/* https://codeforces.com/problemset/problem/1760/A
A. Medium Number
time limit per test1 second
memory limit per test256 megabytes
Given three distinct integers 𝑎, 𝑏, and 𝑐, find the medium number between all of
them.

The medium number is the number that is neither the minimum nor the maximum of
the given three numbers.

For example, the median of 5,2,6 is 5, since the minimum is 2 and the maximum
is 6.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤6840) — the number of test
cases.

The description of each test case consists of three distinct integers 𝑎, 𝑏, 𝑐
(1≤𝑎,𝑏,𝑐≤20).

Output
For each test case, output a single integer — the medium number of the three
numbers.

Example
InputCopy
9
5 2 6
14 3 4
20 2 1
1 2 3
11 19 12
10 8 20
6 20 3
4 1 3
19 8 4
OutputCopy
5
4
2
2
12
10
6
3
8


*/

#include <algorithm>
#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    // return the number that is neither minimum nor maximum
    std::cout << (a + b + c - std::min({a, b, c}) - std::max({a, b, c}))
              << std::endl;
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/1760/305784538
