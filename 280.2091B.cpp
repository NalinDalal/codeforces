/* B. Team Training
time limit per test2 seconds
memory limit per test256 megabytes
At the IT Campus "NEIMARK", there are training sessions in competitive
programming — both individual and team-based!

For the next team training session, 𝑛
 students will attend, and the skill of the 𝑖
-th student is given by a positive integer 𝑎𝑖
.

The coach considers a team strong if its strength is at least 𝑥
. The strength of a team is calculated as the number of team members multiplied
by the minimum skill among the team members.

For example, if a team consists of 4
 members with skills [5,3,6,8]
, then the team's strength is 4⋅𝑚𝑖𝑛([5,3,6,8])=12
.

Output the maximum possible number of strong teams, given that each team must
have at least one participant and every participant must belong to exactly one
team.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑥
 (1≤𝑛≤2⋅105
, 1≤𝑥≤109
) — the number of students in training and the minimum strength of a team to be
considered strong.

The second line of each test case contains 𝑛
 integers 𝑎𝑖
 (1≤𝑎𝑖≤109
) — the skill of each student.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the maximum possible number of teams with strength at
least 𝑥
.

Example
InputCopy
5
6 4
4 5 3 3 2 6
4 10
4 2 1 3
5 3
5 3 2 3 2
3 6
9 1 7
6 10
6 1 3 6 3 2
OutputCopy
4
0
4
2
1
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, x;
    cin >> n >> x;
    std::vector<long> a(n);
    for (int p = 0; p < n; p++) {
      cin >> a[p];
    }
    sort(a.rbegin(), a.rend());
    int num = 0, cnt = 0;
    for (int p = 0; p < n; p++) {
      ++num;
      if (num * a[p] >= x) {
        ++cnt;
        num = 0;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2091/313337602
