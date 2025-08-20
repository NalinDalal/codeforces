/*N. Fixing the Expression
time limit per test2 seconds
memory limit per test512 megabytes
An expression is a string consisting of three characters, where the first and
the last characters are digits (from 0 to 9
), and the middle character is a comparison symbol (<, = or >).

An expression is true if the comparison symbol matches the digits (for example,
if the first digit is strictly less than the last digit, the comparison symbol
should be <).

For example, the expressions 1<3, 4>2, 0=0 are true, while 5>5, 7<3 are not.

You are given a string 𝑠
, which is an expression. Change as few characters as possible so that 𝑠
 becomes a true expression. Note that if 𝑠
 is already true, you should leave it as it is.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤300
) — the number of test cases.

Each test case consists of one line containing the string 𝑠
 (|𝑠|=3
, the first and the last characters of 𝑠
 are digits, the second character is a comparison symbol).

Output
For each test case, print a string consisting of 3
 characters — a true expression which can be obtained by changing as few
characters as possible in 𝑠 . If there are multiple answers, print any of them.

Example
InputCopy
5
3<7
3>7
8=9
0=0
5<3
OutputCopy
3<7
8>7
8<9
0=0
0<3
*/

#include <iostream>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    if (s[0] < s[2]) {
      s[1] = '<';
    } else if (s[0] > s[2]) {
      s[1] = '>';
    } else if (s[0] == s[2]) {
      s[1] = '=';
    }
    std::cout << s << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2038/334610346
