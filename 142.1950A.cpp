/* A. Stair, Peak, or Neither?
time limit per test1 second
memory limit per test256 megabytes
You are given three digits 𝑎
, 𝑏
, and 𝑐
. Determine whether they form a stair, a peak, or neither.

A stair satisfies the condition 𝑎<𝑏<𝑐
.
A peak satisfies the condition 𝑎<𝑏>𝑐
.
Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The only line of each test case contains three digits 𝑎
, 𝑏
, 𝑐
 (0≤𝑎
, 𝑏
, 𝑐≤9
).

Output
For each test case, output "STAIR" if the digits form a stair, "PEAK" if the
digits form a peak, and "NONE" otherwise (output the strings without quotes).

Example
InputCopy
7
1 2 3
3 2 1
1 5 3
3 4 1
0 0 0
4 1 7
4 5 7
OutputCopy
STAIR
NONE
PEAK
PEAK
NONE
NONE
STAIR

*/

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a < b && b < c)
      cout << "STAIR" << endl;
    else if (a < b && b > c)
      cout << "PEAK" << endl;
    else
      cout << "NONE" << endl;
  }
  return 0;
}
