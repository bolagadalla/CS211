#include <iostream>
#include <cmath>

using namespace std;
int main() 
{
  int solutions = 0;
  int q[8], c = 0;
  q[0] = 0;
  // New Columb
  NC:
  c++;
  if(c == 8) goto Print;
  q[c] = -1;
  // New Row
  NR:
  q[c]++;
  if(q[c] == 8) goto BackTrack;

  for(int i = 0; i < c; i++)
  {
    if(q[i] == q[c] || (c - i) == abs(q[c] - q[i])) goto NR;
  }
  goto NC;
  // BackTrack To The Previous Cell
  BackTrack:
  c--;
  if(c == -1) 
  {
    cout << "Number Of Solutions Found: " << solutions << endl;
    return 0;
  }
  goto NR;
  // Prints The Array
  Print:
  solutions++;
  cout << "Solution #: " << solutions << endl;
  for(int c = 0; c < 8; c++)
  {
    for(int r = 0; r < 8; r++)
    {
      if(q[c] == r)
      {
        cout << "1   ";
      }
      else
      {
        cout << "0   ";
      }
    }
    cout << endl << endl;
  }

  cout << endl;
  goto BackTrack;

}