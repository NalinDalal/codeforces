/*A. Cake Assignment
time limit per test2 seconds
memory limit per test256 megabytes
Chocola and Vanilla love cakes. Today, the manager of a cake shop gave them a
total of 2𝑘+1 cakes. The cakes were distributed evenly, so each of them
initially received 2𝑘 cakes.

However, Chocola and Vanilla now want to redistribute the cakes such that
Chocola ends up with exactly 𝑥 cakes and Vanilla gets the remaining 2𝑘+1−𝑥
 cakes.

In one step, they can perform exactly one of the following two operations:

Chocola gives half of her cakes to Vanilla. This operation is only allowed if
Chocola currently has an even number of cakes. Vanilla gives half of her cakes
to Chocola. This operation is only allowed if Vanilla currently has an even
number of cakes. Your task is to determine the minimum number of steps required
to reach the target distribution and to output any valid sequence of operations
achieving that minimum.

It can be proven that, under the given constraints, a valid solution always
exists, and the minimum number of steps required is at most 120
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤1000
). The description of the test cases follows.

The first line of each test case contains two integers 𝑘
 and 𝑥
 (1≤𝑘≤60
, 1≤𝑥≤2𝑘+1−1
) — each person initially received 2𝑘
 cakes, and 𝑥
 is the number of cakes Chocola should have after redistribution.

Output
For each test case, output a single integer 𝑛
 (0≤𝑛≤120
) representing the minimum number of steps required for them to redistribute the
cakes accordingly.

On the next line, output 𝑛
 integers 𝑜1,𝑜2,…,𝑜𝑛
 (𝑜𝑖=𝟷
 or 𝑜𝑖=𝟸
), where 𝑜𝑖=𝟷
 means that in the 𝑖
-th step, Chocola gave half of her cakes to Vanilla (operation 1), and 𝑜𝑖=𝟸
 means that Vanilla gave half of her cakes to Chocola (operation 2).

Example
InputCopy
4
2 3
2 4
3 7
2 5
OutputCopy
2
2 1
0

3
2 2 1
2
1 2
Note
In the first test case, they can use the following steps so that Chocola has
exactly 𝑥=3 cakes and Vanilla has exactly 2𝑘+1−𝑥=5 cakes. We use {𝑎,𝑏} to denote
that Chocola currently has 𝑎 cakes and Vanilla currently has 𝑏 cakes.

{4,4}−→−−𝑜1=𝟸{6,2}−→−−𝑜2=𝟷{3,5}

In the second test case, Chocola already has exactly 𝑥=4
 cakes and Vanilla already has exactly 2𝑘+1−𝑥=4
 cakes, so no operations are required.

In the third test case, they can use the following steps so that Chocola has
exactly 𝑥=7 cakes and Vanilla has exactly 2𝑘+1−𝑥=9 cakes.

{8,8}−→−−𝑜1=𝟸{12,4}−→−−𝑜2=𝟸{14,2}−→−−𝑜3=𝟷{7,9}
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long k, x;
  cin >> k >> x;

  // Find index of the highest set bit in x
  int i = 0;
  while (!(x & (1LL << i)))
    i++;

  // If x == 2^k → already correct, no moves
  if (x == (1LL << k)) {
    cout << 0 << "\n\n";
    return;
  }

  vector<int> ans;
  for (int j = i + 1; j <= k; j++) {
    if (x & (1LL << j)) {
      ans.push_back(2); // bit = 1 → operation 2
    } else {
      ans.push_back(1); // bit = 0 → operation 1
    }
  }

  cout << ans.size() << "\n";
  for (int op : ans)
    cout << op << " ";
  if (!ans.empty())
    cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2138/339825263
