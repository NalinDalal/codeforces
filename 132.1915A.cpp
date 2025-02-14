/* A. Odd One Out
time limit per test1 second
memory limit per test256 megabytes
You are given three digits 𝑎, 𝑏, 𝑐. Two of them are equal, but the third one is
different from the other two.

Find the value that occurs exactly once.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤270) — the number of test cases.

The only line of each test case contains three digits 𝑎, 𝑏, 𝑐 (0≤𝑎, 𝑏, 𝑐≤9). Two
of the digits are equal, but the third one is different from the other two.

Output
For each test case, output the value that occurs exactly once.

Example
InputCopy
10
1 2 2
4 3 4
5 5 6
7 8 8
9 0 9
3 6 3
2 8 2
5 7 7
7 7 5
5 7 5
OutputCopy
1
3
6
7
0
6
8
5
5
7
*/

#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a != b && b == c) {
      cout << a << endl;
    } else if (a == b && b != c) {
      cout << c << endl;
    } else {
      cout << b << endl;
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1915/306067710
