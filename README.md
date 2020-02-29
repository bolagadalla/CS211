# **Queens College CS211 C++ Projects**

* **Perfect Square**

  This code tries to find first perfect square (i * i) whose last two digits are both odd. Although there is no answer to this, it was a good practice in programming an algorithm to try and find it.

* **Adding Large Integers**

  In this algorithm, it would take a very large number that the computer cannot handle as a string. Then it would add both strings together as if it were integers by adding one number at a time and taking care of any carry number. For every integer added, it would add it to the string which would be the answered returned.

* **8 Queens On Board 2D**

  With this program it tries to find all possible positions for 8 queens to be on a chest board such that, the next turn they would not be able to kill each other. There are 92 possible solutions to this problem and this program finds them all using a 2D array. However, it uses gotos which are not a great idea but its meant to intoduce us to program a more complex algorithm.

* **8 Queens On Board 1D using goto**

  This is similar to the previous 8 Queens On Board 2D but it uses 1D array to store the solutions.

* **8 Queens On Board 1D using Struct**

  Instead of using gotos to loop around the program, we use struct in this case to build up our program to find all possible solutions to the 8 Queen.

* **8 Cell Cross**

  In this agorithm we were asked to build a program that would place an integer from 1-8 in a cross formation with the restriction that no two adjacent cells contain consecutive integers, and the integer can only be written once. This problem has 4 possible solutions, and this program finds all those solutions and prints them out to the console.
  
  **_This is how the cross would look like_**
  
          3 5  
        7 1 8 2  
          4 6  
