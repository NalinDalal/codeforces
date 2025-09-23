/*D. Binary Cut
time limit per test2 seconds
memory limit per test256 megabytes
You are given a binary string†
. Please find the minimum number of pieces you need to cut it into, so that the
resulting pieces can be rearranged into a sorted binary string.

11010

11 | 01 | 0
0| 01 | 11
00111

Note that:

each character must lie in exactly one of the pieces;
the pieces must be contiguous substrings of the original string;
you must use all the pieces in the rearrangement.
†
 A binary string is a string consisting of characters 𝟶
 and 𝟷
. A sorted binary string is a binary string such that all characters 𝟶
 come before all characters 𝟷
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤500
) — the number of test cases.

The only line of each test case contains a single string 𝑠
 (1≤|𝑠|≤500
) consisting of characters 𝟶
 and 𝟷
, where |𝑠|
 denotes the length of the string 𝑠
.

Output
For each test case, output a single integer — the minimum number of pieces
needed to be able to rearrange the string into a sorted binary string.

Example
InputCopy
6
11010
00000000
1
10
0001111
0110
OutputCopy
3
1
1
2
1
2
Note
The first test case is pictured in the statement. It can be proven that you
can't use fewer than 3 pieces.

In the second and third test cases, the binary string is already sorted, so only
1 piece is needed.

In the fourth test case, you need to make a single cut between the two
characters and rearrange them to make the string 𝟶𝟷
.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    // basically how many cuts needed to make string sorted by rearranging
    // that parts of string
    // like see traverse the string, if continue 1 then keep it in a window
    // then if continue 0 keep it another window,
    // when you get the parity changed, window increased
    // return window
    int r = 0, d = 0;
    for (int i = 0; i < s.size(); i++) {
      r += (s[i - 1] == '0' && s[i] == '1');
      d += (s[i - 1] == '1' && s[i] == '0');
    }
    cout << (r - (r > 0) + d + 1) << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1971/339969634
