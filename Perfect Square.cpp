#include <iostream>
using namespace std;

int main() 
{
  int n = 1;
  int lastNumber, secondLastNumber;

  while(n < 100)
  {
    cout << n * n << endl;
    lastNumber = (n * n) % 10;
    cout << "lastNumber: " << lastNumber << endl;
    secondLastNumber = ((n * n) / 10) % 10;
    cout << "secondLastNumber: " << secondLastNumber << endl;
    n++;

    if((secondLastNumber % 2 == 1) && (lastNumber % 2 == 1))
    {
      cout << "found: " << endl;
      return 0;
    }
  }
}