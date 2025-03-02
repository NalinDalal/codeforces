/* A. Easy Problem
time limit per test1 second
memory limit per test256 megabytes
Cube is given an integer 𝑛. She wants to know how many ordered pairs of positive
integers (𝑎,𝑏) there are such that 𝑎=𝑛−𝑏. Since Cube is not very good at math,
please help her!

Input
The first line contains an integer 𝑡 (1≤𝑡≤99) — the number of test cases.

The only line of each test case contains an integer 𝑛 (2≤𝑛≤100).

Output
For each test case, output the number of ordered pairs (𝑎,𝑏) on a new line.

Example
InputCopy
3
2
4
6
OutputCopy
1
3
5
Note
In the first test case, the only ordered pair that works is (𝑎,𝑏)=(1,1).

In the second test case, the three ordered pairs of (𝑎,𝑏) that work are
(3,1),(2,2),(1,3).*/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << n - 1 << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2044/308692382
