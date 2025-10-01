/*D. Come a Little Closer
time limit per test2 seconds
memory limit per test256 megabytes
The game field is a matrix of size 109×109
, with a cell at the intersection of the 𝑎
-th row and the 𝑏
-th column denoted as (𝑎,𝑏
).

There are 𝑛
 monsters on the game field, with the 𝑖
-th monster located in the cell (𝑥𝑖,𝑦𝑖
), while the other cells are empty. No more than one monster can occupy a single
cell.

You can move one monster to any cell on the field that is not occupied by
another monster at most once .

After that, you must select one rectangle on the field; all monsters within the
selected rectangle will be destroyed. You must pay 1 coin for each cell in the
selected rectangle.

Your task is to find the minimum number of coins required to destroy all the
monsters.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of monsters on the field.

The following 𝑛
 lines contain two integers 𝑥𝑖
 and 𝑦𝑖
 (1≤𝑥𝑖,𝑦𝑖≤109
) — the coordinates of the cell with the 𝑖
-th monster. All pairs (𝑥𝑖,𝑦𝑖
) are distinct.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the minimum cost to destroy all 𝑛
 monsters.

Example
InputCopy
7
3
1 1
1 2
2 1
5
1 1
2 6
6 4
3 3
8 2
4
1 1
1 1000000000
1000000000 1
1000000000 1000000000
1
1 1
5
1 2
4 2
4 3
3 1
3 2
3
1 1
2 5
2 2
4
4 3
3 1
4 4
1 2
OutputCopy
3
32
1000000000000000000
1
6
4
8
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;

    vector<pair<ll, ll>> v(n);
    map<ll, ll> mr, mc;

    for (ll p = 0; p < n; p++) {
      cin >> v[p].first >> v[p].second;
      ++mr[v[p].first];
      ++mc[v[p].second];
    }

    if (n == 1) {
      cout << 1 << "\n";
      continue;
    }

    ll ans = 1e18 + 7;
    for (ll p = 0; p < n; p++) {
      ll row = v[p].first;
      ll col = v[p].second;

      // temporarily remove this point
      if (--mr[row] == 0)
        mr.erase(row);
      if (--mc[col] == 0)
        mc.erase(col);

      ll length = mr.rbegin()->first - mr.begin()->first + 1;
      ll width = mc.rbegin()->first - mc.begin()->first + 1;

      ll tst = length * width;
      if (tst == n - 1) {
        tst += min(length, width);
      }
      ans = min(ans, tst);

      // restore
      ++mr[row];
      ++mc[col];
    }

    cout << ans << "\n";
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/2114/341295975
