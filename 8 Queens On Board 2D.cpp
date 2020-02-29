#include <iostream>
using namespace std;

void GoToNewColum(int arr[][8], int &c)
{
  c++;
  if(c == 8)
  {
    for(int r = 0; r < 8; r++)
    {
      for(int c = 0; c < 8; c++)
      {
        cout << arr[c][r] << "    ";
      }
      cout << endl << endl;
    }
    cout << endl;
  }
}



int main() 
{
  int solutionFound = 0;
  int rows = 8;
  int cols = 8;
  int b[8][8] = {0}, r, c = 0;
  b[0][0] = 1;
  NC: c++;
  if(c == cols) goto Print;
  r = -1;
  NR: r++;
  if(r == rows) goto BackTrack;
  // Row Test
  for(int i = 0; i < c; i++)
    if(b[r][i] == 1) goto NR;
  // Diagnale Test
  for(int i = 1; (r - i) >= 0 && (c - i) >= 0; i++)
    if(b[r - i][c - i] == 1) goto NR;
  //Down Diagnale Test
  for(int i = 1; (r + i) < rows && (c - i) >= 0; i++)
    if(b[r + i][c - i] == 1) goto NR;

  // Placing a queen
  b[r][c] = 1;
  goto NC;
  BackTrack: 
  c--;
  // Break out of the program when we go to the furthest columb
  if(c == -1)
  {
    cout << "Number of solutions: " << solutionFound << endl;
    return 0;
  } 
  r = 0;
  // Finding the queen again
  while(b[r][c] != 1) 
    r++;

  // Placing empty space
  b[r][c] = 0;
  goto NR;
  Print:
  solutionFound++;
  cout << "Solution #" << solutionFound << ":" << endl;
  for(int r = 0; r < rows; r++)
  {
    for(int c = 0; c < cols; c++)
    {
      cout << b[c][r] << "    ";
    }
    cout << endl << endl;
  }
  cout << endl;
  goto BackTrack;
}