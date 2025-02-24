/* A. My First Sorting Problem
time limit per test1 second
memory limit per test256 megabytes
You are given two integers 𝑥 and 𝑦.

Output two integers: the minimum of 𝑥 and 𝑦, followed by the maximum of 𝑥 and 𝑦.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤100) — the number of test cases.

The only line of each test case contains two space-separated integers 𝑥 and 𝑦
(0≤𝑥,𝑦≤9).

Output
For each test case, output two integers: the minimum of 𝑥 and 𝑦, followed by the
maximum of 𝑥 and 𝑦.

Example
InputCopy
10
1 9
8 4
1 4
3 4
2 0
2 4
6 9
3 3
0 0
9 9
OutputCopy
1 9
4 8
1 4
3 4
0 2
2 4
6 9
3 3
0 0
9 9

*/

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << min(a, b) << " " << max(a, b) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1971/307560288
