/*D. Kevin and Competition Memories
time limit per test2 seconds
memory limit per test256 megabytes
Kevin used to get into Rio's Memories, and in Rio's Memories, a series of
contests was once held. Kevin remembers all the participants and all the contest
problems from that time, but he has forgotten the specific rounds, the
distribution of problems, and the exact rankings.

There are 𝑚
 problems in total, with the 𝑖
-th problem having a difficulty of 𝑏𝑖
. Let each contest consist of 𝑘
 problems, resulting in a total of ⌊𝑚𝑘⌋
 contests. This means that you select exactly ⌊𝑚𝑘⌋⋅𝑘
 problems for the contests in any combination you want, with each problem being
selected at most once, and the remaining 𝑚mod𝑘 problems are left unused. For
example, if 𝑚=17 and 𝑘=3 , you should create exactly 5 contests consisting of 3
 problems each, and exactly 2
 problems will be left unused.

There are 𝑛
 participants in the contests, with Kevin being the 1
-st participant. The 𝑖
-th participant has a rating of 𝑎𝑖
. During the contests, each participant solves all problems with a difficulty
not exceeding their rating, meaning the 𝑖 -th participant solves the 𝑗 -th
problem if and only if 𝑎𝑖≥𝑏𝑗 . In each contest, Kevin's rank is one plus the
number of participants who solve more problems than he does.

For each 𝑘=1,2,…,𝑚
, Kevin wants to know the minimum sum of his ranks across all ⌊𝑚𝑘⌋
 contests. In other words, for some value of 𝑘
, after selecting the problems for each contest, you calculate the rank of Kevin
in each contest and sum up these ranks over all ⌊𝑚𝑘⌋ contests. Your goal is to
minimize this value.

Note that contests for different values of 𝑘
 are independent. It means that for different values of 𝑘
, you can select the distribution of problems into the contests independently.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤5⋅104
).

The first line of each test case contains two integers 𝑛
 and 𝑚
 (1≤𝑛,𝑚≤3⋅105
) — the number of participants and the number of problems.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤109
) — the rating of each participant.

The third line of each test case contains 𝑚
 integers 𝑏1,𝑏2,…,𝑏𝑚
 (0≤𝑏𝑖≤109
) — the difficulty of each problem.

It is guaranteed that both the sum of 𝑛
 and the sum of 𝑚
 over all test cases do not exceed 3⋅105
.

Output
For each test case, output 𝑚
 integers — the minimum sum of Kevin's ranks for each 𝑘=1,2,…,𝑚
.

Example
InputCopy
4
4 4
4 3 7 5
2 5 4 6
5 5
5 0 4 8 6
1 3 9 2 7
6 7
1 1 4 5 1 4
1 9 1 9 8 1 0
7 6
1 9 1 9 8 1 0
1 1 4 5 1 4
OutputCopy
7 4 2 3
6 2 1 1 2
7 3 2 1 1 1 1
15 9 5 4 4 4
Note
For the first test case:

When 𝑘=1
, since each contest only contains one problem, the distribution is in fact
unique. For example, in the contest which only includes the third problem (which
has a difficulty of 4
), all participants except the 2
-nd can solve it. Since no one solves strictly more problems than Kevin, his
ranking in this contest is 1 . Similarly, in all 4 contests, Kevin's rankings
are 1,3,1,2 , and the sum is 7
.

When 𝑘=2
, one optimal way is to choose the 1
-st and the 3
-rd problem to form a contest, while the 2
-nd and 4
-th for another. In the former contest, 4
 participants respectively solve 2,1,2,2
 problems, so Kevin's ranking is 1
; in the latter one, they respectively solve 0,0,2,1
, since there are 2
 participants (3
-rd and 4
-th) solve more problems than Kevin, his ranking is 1+2=3
. Thus the answer is 1+3=4
. It can be proven that there's no way to achieve a lower sum.

When 𝑘=3
, we can simply choose the 1
-st, the 3
-rd, and the 4
-th problem to make a contest, and Kevin has a ranking of 2
, which is optimal.

When 𝑘=4
, since there's only one contest, the distribution is also unique, and Kevin's
ranking is 3
*/

/*given m,k
 floor(m/k), floor(m/k)-k

 m mod k

 b[j]<=a[i]
 then they can be solved

 put all a[i]>a[0] in v, sort v.

 store unsolved in v1[i]

 sort v1

 for(k=1 to m){
    contest of size k
    grp v1 into block of size k after sorting
For each block, pick the “last” element (v1[i] with i = k-1, 2k-1, …), add v1[i]
+ 1 to total.
{
+1 is Kevin’s base rank.

v1[i] is how many stronger participants beat him on that contest.}
    cout<<sum
 }
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<ll> a(n), b(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int j = 0; j < m; j++)
    cin >> b[j];

  sort(b.begin(), b.end());

  // Collect stronger participants
  vector<ll> stronger;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[0])
      stronger.push_back(a[i]);
  }
  sort(stronger.begin(), stronger.end());

  // Compute disadvantage per problem
  vector<ll> v1(m);
  for (int i = 0; i < m; i++) {
    if (b[i] > a[0]) {
      ll pos = lower_bound(stronger.begin(), stronger.end(), b[i]) -
               stronger.begin();
      v1[i] =
          stronger.size() - pos; // # stronger who solve this but Kevin cannot
    } else {
      v1[i] = 0; // Kevin solves it
    }
  }

  // Sort disadvantages
  sort(v1.begin(), v1.end());

  // Compute answer for each k
  for (int k = 1; k <= m; k++) {
    ll sum = 0;
    for (int i = k - 1; i < m; i += k) {
      sum += v1[i] + 1;
    }
    cout << sum << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
// sub: https://codeforces.com/problemset/submission/2048/338287249
