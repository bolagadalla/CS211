/*
1) All numbers should be unique in the cross array
2) Number n in cross[i] cannot be concecative numbers to any cell above it, below it, diagnel to it from upward and downward
3) When on the cell to check, you always start at 1
4) If we fail to find a number in that cross[i] cell then we increment the number inside to check the next number

          3 5
        7 1 8 2
          4 6
*/




#include <iostream>
#include <math.h>
#include <array>
using namespace std;

struct Cross
{
    int cross[8] = {1};
    
    int checkArray[8][5] = {{-1}, {0,-1}, {0,-1}, {0,1,2,-1}, {0,1,3,-1}, {1,4,-1}, {2,3,4,-1}, {3,4,5,6,-1}};
    int solutions = 0;
    
    // Prints the array after its done.
    void PrintCrossAreay()
    {
        solutions++;
        cout << "Solution #: " << solutions << endl;
        cout << "     " << cross[0] << "    " << cross[1] << endl;
        for(int i = 2; i < 6; i++)
        {
            cout << cross[i] << "    ";
        }
        cout << endl;
        cout << "     " << cross[6] << "    " << cross[7] << endl << endl;;
    }
    
    // Makes sure the numbers in each cell is unique and not consecutive diagonally
    bool OK(int c)
    {
      // Loops through the indexs before c to make sure there are no numbers that are the same
      for(int i = 0; i < c; i++)
      {
        // Checks if the cells are equals
        if(cross[i] == cross[c])
          return false;
      }
        
      int i = 0;
      // Checks the index of cross to the indexs of the array checkArray
      while(checkArray[c][i] != -1)
      {
        // If they are 1 less or more to the current number in c
        if(abs(cross[c] - cross[checkArray[c][i]]) == 1)
          return false;
        i++;
      }
      return true;
    }
    
    // Uses other methods to solve the puzzle.
    void Solve()
    {
        int c = 0;
        cross[c] = 1;
        while(c > -1)
        {
          if(OK(c))
          {
            c += 1;
            if(c > 7)
            {
              // Prints the array
              PrintCrossAreay();
              // Backtrack since we reached the maximum array size
              c -= 1;
              cross[c] += 1;
            }
          }
          else
          {
            cross[c] += 1;
            if(cross[c] > 8)
            {
              // Resets the cell
              cross[c] = 1;
              // Backtrack since we reached the maximum number can exist in a cell
              c -= 1;
              cross[c] += 1;
            }
          }

          // Makes sure the number on the index c doesnt pass 8
          if(cross[c] > 8)
          {
            // Resets the cell
            cross[c] = 1;
            // Backtrack since we reached the maximum number can exist in a cell
            c -= 1;
            cross[c] += 1;
          }

        }
    }
};


int main() 
{
    Cross s;
    s.Solve();
    return 0;
}