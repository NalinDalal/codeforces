/*A. Donut Shops
time limit per test2 seconds
memory limit per test256 megabytes
There are two rival donut shops.

The first shop sells donuts at retail: each donut costs 𝑎
 dollars.

The second shop sells donuts only in bulk: box of 𝑏
 donuts costs 𝑐
 dollars. So if you want to buy 𝑥
 donuts from this shop, then you have to buy the smallest number of boxes such
that the total number of donuts in them is greater or equal to 𝑥
.

You want to determine two positive integer values:

how many donuts can you buy so that they are strictly cheaper in the first shop
than in the second shop? how many donuts can you buy so that they are strictly
cheaper in the second shop than in the first shop? If any of these values
doesn't exist then that value should be equal to −1 . If there are multiple
possible answers, then print any of them.

The printed values should be less or equal to 109
. It can be shown that under the given constraints such values always exist if
any values exist at all.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of testcases.

Each of the next 𝑡
 lines contains three integers 𝑎
, 𝑏
 and 𝑐
 (1≤𝑎≤109
, 2≤𝑏≤109
, 1≤𝑐≤109
).

Output
For each testcase print two positive integers. For both shops print such 𝑥
 that buying 𝑥
 donuts in this shop is strictly cheaper than buying 𝑥
 donuts in the other shop. 𝑥
 should be greater than 0
 and less or equal to 109
.

If there is no such 𝑥
, then print −1
. If there are multiple answers, then print any of them.

Example
InputCopy
4
5 10 4
4 5 20
2 2 3
1000000000 1000000000 1000000000
OutputCopy
-1 20
8 -1
1 2
-1 1000000000
Note
In the first testcase buying any number of donuts will be cheaper in the second
shop. For example, for 3 or 5 donuts you'll have to buy a box of 10 donuts for 4
 dollars. 3
 or 5
 donuts in the first shop would cost you 15
 or 25
 dollars, respectively, however. For 20
 donuts you'll have to buy two boxes for 8
 dollars total. Note that 3
 and 5
 are also valid answers for the second shop, along with many other answers.

In the second testcase buying any number of donuts will be either cheaper in the
first shop or the same price. 8 donuts cost 32 dollars in the first shop and 40
 dollars in the second shop (because you have to buy two boxes). 10
 donuts will cost 40
 dollars in both shops, so 10
 is not a valid answer for any of the shops.

In the third testcase 1
 donut costs 2
 and 3
 dollars, respectively. 2
 donuts cost 4
 and 3
 dollars. Thus, 1
 is a valid answer for the first shop and 2
 is a valid answer for the second shop.

In the fourth testcase 109
 donuts cost 1018
 dollars in the first shop and 109
 dollars in the second shop.
*/
#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << (a < c ? 1LL : -1LL) << " " << (c < b * a ? b : -1LL) << "\n";
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/1373/344852814
