/*D. This Is the Last Time
time limit per test2 seconds
memory limit per test256 megabytes
You are given 𝑛
 casinos, numbered from 1
 to 𝑛
. Each casino is described by three integers: 𝑙𝑖
, 𝑟𝑖
, and 𝑟𝑒𝑎𝑙𝑖
 (𝑙𝑖≤𝑟𝑒𝑎𝑙𝑖≤𝑟𝑖
). You initially have 𝑘
 coins.

You can play at casino 𝑖
 only if the current number of coins 𝑥
 satisfies 𝑙𝑖≤𝑥≤𝑟𝑖
. After playing, your number of coins becomes 𝑟𝑒𝑎𝑙𝑖
.

You can visit the casinos in any order and are not required to visit all of
them. Each casino can be visited no more than once.

Your task is to find the maximum final number of coins you can obtain.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤105
, 0≤𝑘≤109
) — the number of casinos and the initial number of coins.

This is followed by 𝑛
 lines. In the 𝑖
-th line, there are three integers 𝑙𝑖
, 𝑟𝑖
, 𝑟𝑒𝑎𝑙𝑖
 (0≤𝑙𝑖≤𝑟𝑒𝑎𝑙𝑖≤𝑟𝑖≤109
) — the parameters of the 𝑖
-th casino.

It is guaranteed that the sum of all 𝑛
 across all test cases does not exceed 105
.

Output
For each test case, output a single integer — the maximum number of coins you
can obtain after optimally choosing the order of visiting the casinos.

Example
InputCopy
5
3 1
2 3 3
1 2 2
3 10 10
1 0
1 2 2
1 2
1 2 2
2 2
1 3 2
2 4 4
2 5
1 10 5
3 6 5
OutputCopy
10
0
2
4
5
Note
In the first test case, you can first play at the 2
-nd casino. After that, you will have 2
 coins. Then you can play at the 1
-st casino, and the number of coins will increase to 3
. Finally, after playing at the 3
-rd casino, you will have 10
 coins — this is the maximum possible amount.

In the second test case, you have no money, so you cannot earn more.

In the fourth test case, it is beneficial to play at the 2
-nd casino right away and earn 4
 coins.
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define all(x) x.begin(), x.end()
#define pb push_back
#define f first
#define s second

const char nl = '\n';

void solve() {
  int n;
  ll k;
  cin >> n >> k;

  vpl items(n);
  for (int i = 0; i < n; ++i) {
    ll x, y, z;
    cin >> x >> y >> z;
    items[i] = {z, x}; // (value, cost)
  }

  sort(all(items));

  for (auto &[val, cost] : items) {
    if (k >= cost) {
      k = max(k, val);
    }
  }

  cout << k << nl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/2126/331275515
