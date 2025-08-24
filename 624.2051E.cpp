/*E. Best Price
time limit per test2 seconds
memory limit per test256 megabytes
A batch of Christmas trees has arrived at the largest store in Berland. 𝑛
 customers have already come to the store, wanting to buy them.

Before the sales begin, the store needs to determine the price for one tree (the
price is the same for all customers). To do this, the store has some information
about each customer.

For the 𝑖
-th customer, two integers 𝑎𝑖
 and 𝑏𝑖
 are known, which define their behavior:

if the price of the product is at most 𝑎𝑖
, the customer will buy a tree and leave a positive review;
otherwise, if the price of the product is at most 𝑏𝑖
, the customer will buy a tree but leave a negative review;
otherwise, the customer will not buy a tree at all.
Your task is to calculate the maximum possible earnings for the store, given
that it can receive no more than 𝑘 negative reviews.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤2⋅105
; 0≤𝑘≤𝑛
).

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤2⋅109
).

The third line contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤2⋅109
; 𝑎𝑖<𝑏𝑖
).

Additional constraint on the input: the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single integer — the maximum possible earnings for
the store, given that it can receive no more than 𝑘 negative reviews.

Example
InputCopy
5
2 0
2 1
3 4
1 1
2
5
3 3
1 5 2
3 6 4
4 3
2 3 2 8
3 7 3 9
3 1
2 9 5
12 14 9
OutputCopy
2
5
9
14
15
Note
Consider the example from the statement:

In the first test case, the price should be set to 1
. Then both customers will buy one tree each and leave no negative reviews;
In the second test case, the price should be set to 5
. Then the only customer will buy a tree and leave a negative review;
In the third test case, the price should be set to 3
. Then all customers will buy one tree each, and the store will receive two
negative reviews. In the fourth test case, the price should be set to 7 . Then
two customers will buy one tree each, and the store will receive one negative
review.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll n, k, x, res = 0;
  cin >> n >> k;
  vector<pair<ll, int>> a(2 * n);

  for (int i = 0; i < n; i++) {
    cin >> x;
    a[i] = {x, 1};
  }
  for (int i = n; i < 2 * n; i++) {
    cin >> x;
    a[i] = {x, 2};
  }

  sort(a.begin(), a.end());

  ll noBuyers = n, negative = 0;
  int i = 0;
  while (i < 2 * n) {
    if (negative <= k)
      res = max(res, a[i].first * noBuyers);

    x = a[i].first;
    while (i < 2 * n && a[i].first == x) {
      if (a[i].second == 1) {
        negative++;
      } else {
        noBuyers--;
        negative--;
      }
      i++;
    }
  }

  cout << res << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int TC;
  cin >> TC;
  while (TC--) {
    solve();
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2051/335235843
