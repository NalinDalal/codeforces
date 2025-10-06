/*B. Discounts
time limit per test1 second
memory limit per test256 megabytes
You want to buy 𝑛
 products with prices 𝑎1,𝑎2,…,𝑎𝑛
. You can either:

buy product 𝑖
 individually, paying 𝑎𝑖
 coins, or
use a discount voucher to buy it as part of a group purchase.
You have 𝑘
 discount vouchers with values 𝑏1,𝑏2,…,𝑏𝑘
. A voucher of value 𝑥
 allows you to select exactly 𝑥
 products and pay only for the 𝑥−1
 most expensive ones, as such, you can consider that the cheapest product in the
group is free. Each product can be included in at most one discount group, even
if it is not the free one. Also, any single voucher can be used at most one
single time.

What is the minimum total cost required to purchase all 𝑛
 products?

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line contains two integers 𝑛
 and 𝑘
 (1≤𝑛,𝑘≤2⋅105
) —the number of products and the number of available discount vouchers.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the prices of the products.

The third line contains 𝑘
 integers 𝑏1,𝑏2,…,𝑏𝑘
 (1≤𝑏𝑖≤𝑛
) — the values of the discount vouchers.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
, and the sum of 𝑘
 across all test cases does not exceed 2⋅105
.

Output
Print 𝑡
 lines. The 𝑖
-th line should contain the answer for the 𝑖
-th test case — the minimum total cost required to purchase all products in that
test case.

Example
InputCopy
5
5 3
18 3 7 2 9
3 1 1
6 1
1 2 6 3 3 4
5
2 3
1 1
2 2 2
1 1
10
1
5 3
99 99 999 999 123
2 1 4
OutputCopy
10
17
1
0
1197
Note
In the first test case, you can apply the first discount to products 2, 3,
and 4. You will pay for the two most expensive ones (3 and 7 coins) and get the
cheapest one for free, resulting in a cost of 3+7=10 coins. Then, apply the
second and third discounts to products 1 and 5, getting both for free. The total
cost is 10 coins.

In the second test case, you can use the single discount on products 2, 3, 4, 5,
and 6. Among them, the cheapest is product 2 (costing 2 coins), which you get
for free. You pay for the remaining products: 1+6+3+3+4=17 coins in total.

In the third test case, only one discount is available. You can use it on both
products, getting the cheaper one for free and paying 1 coin for the other.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;

  while (t--) {
    long n, k;
    cin >> n >> k;

    vector<long> a(n);
    for (auto &x : a)
      cin >> x;

    vector<long> b(k);
    for (auto &x : b)
      cin >> x;

    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());

    long idx = -1;
    for (long p = 0; p < k; p++) {
      if (idx + b[p] >= n)
        break;
      idx += b[p];
      a[idx] = 0;
    }

    long long cost = 0;
    for (long x : a)
      cost += x;

    cout << cost << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2143/342207235
