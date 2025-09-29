/*A. Sports Betting
time limit per test2 seconds
memory limit per test256 megabytes
The boarding process for various flights can occur in different ways: either by
bus or through a telescopic jet bridge. Every day, exactly one flight is made
from St. Petersburg to Minsk, and Vadim decided to demonstrate to the students
that he always knows in advance how the boarding will take place.

Vadim made a bet with 𝑛
 students, and with the 𝑖
-th student, he made a bet on day 𝑎𝑖
. Vadim wins the bet if he correctly predicts the boarding process on both day
𝑎𝑖+1 and day 𝑎𝑖+2
.

Although Vadim does not know in advance how the boarding will occur, he really
wants to win the bet at least with one student and convince him of his
predictive abilities. Check if there exists a strategy for Vadim that allows him
to guarantee success.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤105
) — the number of students Vadim made bets with.

The second line of each test case contains 𝑛
 integers 𝑎1,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the days on which Vadim made bets with the students.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output "Yes" (without quotes) if Vadim can guarantee
convincing at least one student, and "No" otherwise.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
5
4
1 1 1 1
3
2 2 2
5
2 4 3 2 4
8
6 3 1 1 5 1 2 6
1
1000000000
OutputCopy
Yes
No
Yes
No
No
Note
In the first test case, Vadim needs to make at least one correct prediction
about the boarding process on the second and third days. There are a total of 4
 possible boarding scenarios for these days, so Vadim can give all 4
 students different predictions and guarantee that at least one of them will be
correct.

In the second test case, Vadim only made bets with three students and cannot
guarantee that he will provide at least one of them with a correct prediction.
*/

// and in that light, I find deliverance
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// defines
#define int long long
#define debug(x) cerr << "(" << #x << "=" << x << "," << __LINE__ << ")\n";
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);

// constants
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
const char dir[4]{'D', 'R', 'U', 'L'};
const int MOD = 1e9 + 7;
const int maxn = 2e5 + 5;
const double eps = 1e-9;

// typedefs
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

// Template
template <class T>
using oset =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Mods
int add(int a, int b) {
  if ((a += b) >= MOD) {
    a -= MOD;
  }
  return a;
}
int sub(int a, int b) {
  if ((a -= b) < 0) {
    a += MOD;
  }
  return a;
}
int mul(int a, int b) {
  int ret = (a % MOD * b % MOD) % MOD;
  if (ret < 0) {
    ret += MOD;
  }
  return ret;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(all(a));
  for (auto [key, val] : mp) {
    if (mp[key] >= 4) {
      cout << "Yes\n";
      return;
    }
  }
  map<int, int> vis;
  int flag = 0;
  for (int i = 0; i < n; i++) {
    if (mp[a[i]] >= 2) {
      if (flag and not vis[a[i]] and a[i] - a[i - 1] == 1) {
        cout << "Yes\n";
        return;
      }
      vis[a[i]] = 1;
      flag = 1;
      continue;
    }
    if (flag) {
      if (a[i] - a[i - 1] > 1) {
        flag = 0;
      }
    }
  }
  cout << "No\n";
}
signed main() {
  fastio();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2097/341019021
