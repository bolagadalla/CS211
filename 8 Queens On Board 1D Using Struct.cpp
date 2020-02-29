#include <iostream>
#include <cmath>
using namespace std;

struct Board
{
  // create an array of all zeros
  int board[8] = {}; 
  int solution = 0;

  // Print the board
  void printBoard()
  {
    solution += 1;
    cout << "solution " << solution << endl;
    for(int i = 0; i < 8; i++)
    {
      cout << board[i] << "  ";
    }
    cout << endl <<endl;
  }

  // Checks if there is a queen to the left of the current queen's position
  bool checkLeft(int c)
  {
    for (int i = 0; i < c ; i++)
    {
      // Queens are on the same row
      if(board[c] == board[i])
      {
        return false;
      }
    }
    return true;
  }

  // Check if there is a queen upward diagonally from the current queen's position
  bool checkDiagonalUp(int c)
  {
    int row = board[c];
    for (int i = 1; (row - i > -1) && (c - i  > -1); i++)
    {
      // There is a queen up diagonally
      if(board[c-i] == row - i)
      {
        // Returns false meaning we cannot place a queen in that cell
        return false; 
      }
    }
    // Otherwise we can place a queen on this cell
    return true;
  }

  // Checks if there is a queen downward diagonally from the current queen's position
  bool checkDiagonalDown(int c)
  {
    int row = board[c];
    for(int i = 1; (c - i > -1) && (row + i < 8); i++)
    {
      // there is a queen down diagonally
      if (row + i == board[c - i]  )
      {
        // Returns false, we cannot place a queen here
        return false;
      }
    }
    // If there is no queen then we can return true, meaning we can place a queen here
    return true;
  }

  // We check if there is any queen to the left, up diagonally, down diagonally
  // If there is not a queen there then we are a allowed to place a queen there
  bool ok(int c){
    if (checkLeft(c) && checkDiagonalUp(c) && checkDiagonalDown(c))
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  // Solves the problem using the other function we created
  void solve()
  {
    int c = 0;
    // if we backtrack beyond the first col, we are done
    while(c > -1)
    {

      // if we have moved beyond the last column
      if(c > 7)
      {
        // print the board
        printBoard();
        // backtrack
        c -= 1;
        board[c] += 1;
      }

      // If we have moved beyond the last row 
      if(board[c] > 7)
      {
        // reset queen
        board[c] = 0;
        // backtrack
        c -= 1;
        board[c] += 1;
      }

      // Check if the placed queen is ok.
      else if(ok(c))
      {
        // move to next column if ok
        c += 1;
      } 
      else
      {
        // move to next row if not ok
        board[c] += 1;
      }
    }
  }
};

int main()
{
  // Create an object of type board
  Board b;
  b.solve();
  cout<< "There are " << b.solution << " solutions" << endl;
  return 0;
}
