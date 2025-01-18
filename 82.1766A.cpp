/* https://codeforces.com/problemset/problem/1766/A

A. Extremely Round
time limit per test3 seconds
memory limit per test512 megabytes
Let's call a positive integer extremely round if it has only one non-zero digit.
For example, 5000, 4, 1, 10, 200 are extremely round integers; 42,13, 666, 77,
101 are not.

You are given an integer 𝑛. You have to calculate the number of extremely round
integers 𝑥 such that 1≤𝑥≤𝑛.

Input
The first line contains one integer 𝑡 (1≤𝑡≤104) — the number of test cases.

Then, 𝑡 lines follow. The 𝑖-th of them contains one integer 𝑛 (1≤𝑛≤999999) — the
description of the 𝑖-th test case.

Output
For each test case, print one integer — the number of extremely round integers 𝑥
such that 1≤𝑥≤𝑛.

Example
InputCopy
5
9
42
13
100
111
OutputCopy
9
13
10
19
19
*/

#include <iostream>

using namespace std;

void sol() {
  int n;
  cin >> n;
  int res(0);
  while (n > 10) {
    res += 9;
    n /= 10;
  }
  res += n;
  cout << res << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    sol();
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1766/301631387
