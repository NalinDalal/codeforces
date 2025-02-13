/* https://codeforces.com/problemset/problem/1999/A
A. A+B Again?
time limit per test1 second
memory limit per test256 megabytes
Given a two-digit positive integer 𝑛, find the sum of its digits.

Input
The first line contains an integer 𝑡 (1≤𝑡≤90) — the number of test cases.

The only line of each test case contains a single two-digit positive integer 𝑛
(10≤𝑛≤99).

Output
For each test case, output a single integer — the sum of the digits of 𝑛.

Example
InputCopy
8
77
21
40
34
19
84
10
99
OutputCopy
14
3
4
7
10
12
1
18


*/
#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    int sum = 0;
    // for n output sum of digits of n
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }
    std::cout << sum << std::endl;
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1999/305951019
