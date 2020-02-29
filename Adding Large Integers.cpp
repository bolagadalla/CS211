#include <iostream>
using namespace std;

int convert (char c)
{
  return c - '0';
}

string add(string a, string b)
{
  int aidx, bidx, arridx;
  // This variable aidx gets the length of the variable "a" - 1 because strings are considered arrays of characters and arrays starts from 0 counting. so if we have "1234" those are 4 characters BUT since the string is an array when you try to get number 4, you would do a[3], notice how its one less
  aidx = a.length() - 1;

  // Same thing
  bidx = b.length() - 1;

  // this length variable gets the maximum length of the two strings, which ever the maximum is it gives that number, so lets say string "a" is the longer string with 5 characters (numbers in this case) then thats what it will assign to length, then + 1. because thats how long we want the array to be, this array will be the array to store our answer.
  int length = max(a.length(), b.length()) + 1;
  // Creating an array which will store our answer in as integers

  //int * arr = new int[length];
  int arr[length];
  // This assigns the length variable that we created above and minus 1 to give us the indexs number. like i explained above
  arridx = length - 1;


  int first, second, carry = 0, sum;
  // This will loop and adds the calculated number into the array and until it reaches the index 0, so we check everything above 0 and including 0. Thats why we do a while loop to loop while this arridx is >= 0. And at the end of the loop we reduce the arridx by 1 until its 0.
  while(arridx >= 0)
  {
    // This makes sure we dont go beyond the index 0 which is -1. Thats why we check to see if its greater then -1, which will always be until we finish the calculation.
    if(aidx > -1)
    {
      // This will convert character of that index of the array, for example 3 in 1234, into an integer. Then assign it to the "first" variable/
      first = convert(a[aidx]);
    }
    else
    {
      // If we do go less then 0, -1, then we change that first variable to 0. This is to make sure that it would finish the calculation of the other integer because we could have 1234 + 123 = ... 
      /*
          1234
        +
          0123
          ____
      */
      first = 0;
    }
    // Same thing for the second integer string
    if(bidx > -1)
    {
      second = convert(b[bidx]);
    }
    else
    {
      second = 0;
    }
    // Then we add all together. The carry at the first two numbers to add would be 0. But if those two numbers added are greater then 10 then we add one to the carry which will be added on when the next two numbers are added together.
    sum = first + second + carry;

    // This is where we check if the sum is greater then 10
    if(sum >= 10)
    {
      // Then subtract 10 from the sum, so if it was 12 then its 2 and the one is added to the carry
      sum -= 10;
      // if so then we add the one carried to the carry variable
      carry = 1;
    }
    else
    {
      // else we reset it to 0
      carry = 0;
    }

    // this adds that sum to the array of answer we created
    arr[arridx] = sum;

    // Subtract 1 from all the indexs to move 1 over. from right to left
    aidx -= 1;
    bidx -= 1;
    arridx -= 1;
  }

  // Creating a variable which we add all the numbers in the array to it as a string
  string ans = "";

  // The for loop will go through the array and converts every number in the index "i" to a string and add it to the "ans" variable
  for(int i = 0; i < length; i++)
  {
    // This gets rid of the 0 on the left side since it would be usless, ex. 016253 -> 16253
    if(i == 0 && arr[i] == 0)
    {
      // the "continue" key word here would just jump this atteration to the next one
      continue;
    }
    // converts the index of integer to a string and then adds it to the string variable
    ans += to_string(arr[i]);
  }

  // Since this is a string function then we must return a string which is ans, our answer.
  return ans;
}
int main() 
{
 cout << (add("2345566777844567", "9999988777765768009998") == "9999991123332545854565") << endl; // 9999991123332545854565
    cout << (add("9999988777765768009998", "9999988777765768009998") == "19999977555531536019996") << endl; // 19999977555531536019996
    cout << (add("2345566777844567", "745566777844567") == "3091133555689134") << endl; // 3091133555689134
    
    cout << "End of Program." << endl;
    return 0;
}