/*A. Problemsolving Log
time limit per test2 seconds
memory limit per test256 megabytes
Monocarp is participating in a programming contest, which features 26
 problems, named from 'A' to 'Z'. The problems are sorted by difficulty.
Moreover, it's known that Monocarp can solve problem 'A' in 1 minute, problem
'B' in 2 minutes, ..., problem 'Z' in 26 minutes.

After the contest, you discovered his contest log — a string, consisting of
uppercase Latin letters, such that the 𝑖 -th letter tells which problem Monocarp
was solving during the 𝑖 -th minute of the contest. If Monocarp had spent enough
time in total on a problem to solve it, he solved it. Note that Monocarp could
have been thinking about a problem after solving it.

Given Monocarp's contest log, calculate the number of problems he solved during
the contest.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of testcases.

The first line of each testcase contains a single integer 𝑛
 (1≤𝑛≤500
) — the duration of the contest, in minutes.

The second line contains a string of length exactly 𝑛
, consisting only of uppercase Latin letters, — Monocarp's contest log.

Output
For each testcase, print a single integer — the number of problems Monocarp
solved during the contest.

Example
InputCopy
3
6
ACBCBC
7
AAAAFPC
22
FEADBBDFFEDFFFDHHHADCC
OutputCopy
3
1
4


*/

/*problem A in 1 minute
 B in 2 minute
 .
 .
 .
 Z in 26 minute

 problems are sorted by difficulty

 given a string -> s[i] is problem solved during ith minute

 given the log find total problems solved

 if he spent enough time in total on a problem to solve it, he solved it

1. make a map<char,int> to store time on each problem
2. iterate over s and inc time for s[i]
3. After counting, check for each problem `A..Z`:
    - required time = `(problem - 'A' + 1)`
    - if `spent_time >= required_time` → increment `ans`.
4. print `ans`

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> time(26, 0);
    for (char c : s) {
      time[c - 'A']++;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
      int need = i + 1;
      if (time[i] >= need)
        ans++;
    }
    cout << ans << endl;
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1914/335235041
