/*A. Binary Imbalance
time limit per test2 seconds
memory limit per test256 megabytes
You are given a string 𝑠
, consisting only of characters '0' and/or '1'.

In one operation, you choose a position 𝑖
 from 1
 to |𝑠|−1
, where |𝑠|
 is the current length of string 𝑠
. Then you insert a character between the 𝑖
-th and the (𝑖+1)
-st characters of 𝑠
. If 𝑠𝑖=𝑠𝑖+1
, you insert '1'. If 𝑠𝑖≠𝑠𝑖+1
, you insert '0'.

Is it possible to make the number of zeroes in the string strictly greater than
the number of ones, using any number of operations (possibly, none)?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of testcases.

The first line of each testcase contains an integer 𝑛
 (1≤𝑛≤100
).

The second line contains a string 𝑠
 of length exactly 𝑛
, consisting only of characters '0' and/or '1'.

Output
For each testcase, print "YES" if it's possible to make the number of zeroes in
𝑠 strictly greater than the number of ones, using any number of operations
(possibly, none). Otherwise, print "NO".

Example
InputCopy
3
2
00
2
11
2
10
OutputCopy
YES
NO
YES
Note
In the first testcase, the number of zeroes is already greater than the number
of ones.

In the second testcase, it's impossible to insert any zeroes in the string.

In the third testcase, you can choose 𝑖=1
 to insert a zero between the 1
-st and the 2
-nd characters. Since 𝑠1≠𝑠2
, you insert a '0'. The resulting string is "100". It has two zeroes and only a
single one, so the answer is "YES".
*/

/*choose a position i
If s[i] == s[i+1], you insert '1'.
If s[i] != s[i+1], you insert '0'.

We want the number of 0s > number of 1s after some operations.

1. if 0'count> 1'count, yes
2. at least one pair of different adjacent characters -> yes
3. all equal chars
    - 0's -> yes
    - 1's -> no

If ( string contains only 1s ){ NO.}
else{ YES.}
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (all_of(s.begin(), s.end(), [](char c) { return c == '1'; })) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1902/334975444
