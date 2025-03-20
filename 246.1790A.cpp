/*A. Polycarp and the Day of Pi
time limit per test1 second
memory limit per test256 megabytes
On March 14, the day of the number 𝜋 is celebrated all over the world.
This is a very important mathematical constant equal to the ratio of the
circumference of a circle to its diameter.

Polycarp was told at school that the number 𝜋 is irrational, therefore it has an
infinite number of digits in decimal notation. He wanted to prepare for the Day
of the number 𝜋 by memorizing this number as accurately as possible.

Polycarp wrote out all the digits that he managed to remember. For example, if
Polycarp remembered 𝜋 as 3.1415, he wrote out 31415.

Polycarp was in a hurry and could have made a mistake, so you decided to check
how many first digits of the number 𝜋 Polycarp actually remembers correctly.

Input
The first line of the input data contains the single integer 𝑡 (1≤𝑡≤103) — the
number of test cases in the test.

Each test case is described by a single string of digits 𝑛, which was written
out by Polycarp.

The string 𝑛 contains up to 30 digits.

Output
Output 𝑡 integers, each of which is the answer to the corresponding test case,
that is how many first digits of the number 𝜋 Polycarp remembers correctly.

Example
InputCopy
9
000
3
4141592653
141592653589793238462643383279
31420
31415
314159265358
27182
314159265358979323846264338327
OutputCopy
0
1
0
0
3
5
12
0
30
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    // so we can have a string of 30 digits which is value of pi
    // then compare check with s and increase counter for each digit
    // return counter atlast
    int counter = 0;
    string piValue = "314159265358979323846264338327";
    for (int i = 0; i < n; i++) {
      if (s[i] == piValue[i])
        counter++;
      else
        break;
    }
    cout << counter << endl;
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1790/311480894
