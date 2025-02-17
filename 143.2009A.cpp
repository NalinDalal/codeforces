/* A. Minimize!
time limit per test1 second
memory limit per test256 megabytes
You are given two integers 𝑎 and 𝑏 (𝑎≤𝑏). Over all possible integer values of 𝑐
(𝑎≤𝑐≤𝑏), find the minimum value of (𝑐−𝑎)+(𝑏−𝑐).

Input
The first line contains 𝑡 (1≤𝑡≤55) — the number of test cases.

Each test case contains two integers 𝑎 and 𝑏 (1≤𝑎≤𝑏≤10).

Output
For each test case, output the minimum possible value of (𝑐−𝑎)+(𝑏−𝑐) on a new
line.

Example
InputCopy
3
1 2
3 10
5 5
OutputCopy
1
7
0
Note
In the first test case, you can choose 𝑐=1 and obtain an answer of
(1−1)+(2−1)=1. It can be shown this is the minimum value possible.

In the second test case, you can choose 𝑐=6 and obtain an answer of
(6−3)+(10−6)=7. It can be shown this is the minimum value possible.

*/

#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int a, b;
    std::cin >> a >> b;
    int c;
    c = b - a;
    std::cout << c << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2009/306483774
