/* A. Matching
time limit per test2 seconds
memory limit per test512 megabytes
An integer template is a string consisting of digits and/or question marks.

A positive (strictly greater than 0
) integer matches the integer template if it is possible to replace every
question mark in the template with a digit in such a way that we get the decimal
representation of that integer without any leading zeroes.

For example:

42
 matches 4?;
1337
 matches ????;
1337
 matches 1?3?;
1337
 matches 1337;
3
 does not match ??;
8
 does not match ???8;
1337
 does not match 1?7.
You are given an integer template consisting of at most 5
 characters. Calculate the number of positive (strictly greater than 0
) integers that match it.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤2⋅104
) — the number of test cases.

Each test case consists of one line containing the string 𝑠
 (1≤|𝑠|≤5
) consisting of digits and/or question marks — the integer template for the
corresponding test case.

Output
For each test case, print one integer — the number of positive (strictly greater
than 0 ) integers that match the template.

Example
InputCopy
8
??
?
0
9
03
1??7
?5?
9??99
OutputCopy
90
9
0
1
0
100
90
100

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

    // jitne question mark like 2 h to 10*10
    // cause 10 for each, then combination can be made
    // but if ? at start then only 9
    int res = 1;
    if (s[0] == '?') {
      res = 9;
    }
    // if no ? then only 1
    else if (s[0] == '0') {
      res = 0;
    }

    for (int p = 1; p < s.size(); p++) {
      res *= (s[p] == '?') ? 10 : 1;
    }
    std::cout << res << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1821/318816717
