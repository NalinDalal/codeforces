/*A. Only One Digit
time limit per test1 second
memory limit per test256 megabytes
You are given an integer 𝑥
. You need to find the smallest non-negative integer 𝑦
 such that the numbers 𝑥
 and 𝑦
 share at least one common digit. In other words, there must exist a decimal
digit 𝑑 that appears in both the representation of the number 𝑥 and the number 𝑦
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The first line of each test case contains one integer 𝑥
 (1≤𝑥≤1000
).

Output
For each test case, output one integer 𝑦
 — the minimum non-negative number that satisfies the condition.

Example
InputCopy
5
6
96
78
122
696
OutputCopy
6
6
7
1
6
Note
In the first test case, the numbers 6
 and 6
 share the common digit '6'. Moreover, there is no natural number smaller than
this that shares a common digit.

In the second test case, the numbers 6
 and 96
 share the common digit '6'.
*/

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    // now given a number n
    // find the smallest digit in it
    // atleast what i understood
    string s = to_string(n);
    sort(s.begin(), s.end());
    int ans = s[0] - '0';
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2126/332289735
