/* A. A+B?
time limit per test2 seconds
memory limit per test512 megabytes
You are given an expression of the form 𝑎+𝑏, where 𝑎 and 𝑏 are integers from 0
to 9. You have to evaluate it and print the result.

Input
The first line contains one integer 𝑡 (1≤𝑡≤100) — the number of test cases.

Each test case consists of one line containing an expression of the form 𝑎+𝑏
(0≤𝑎,𝑏≤9, both 𝑎 and 𝑏 are integers). The integers are not separated from the +
sign.

Output
For each test case, print one integer — the result of the expression.

Example
InputCopy
4
4+2
0+0
3+7
8+9
OutputCopy
6
0
10
17

*/

#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    std::cout << (s[0] - '0' + s[2] - '0') << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1772/307431878
