/* B. New Bakery
time limit per test1 second
memory limit per test256 megabytes
Bob decided to open a bakery. On the opening day, he baked 𝑛
 buns that he can sell. The usual price of a bun is 𝑎
 coins, but to attract customers, Bob organized the following promotion:

Bob chooses some integer 𝑘
 (0≤𝑘≤min(𝑛,𝑏)
).
Bob sells the first 𝑘
 buns at a modified price. In this case, the price of the 𝑖
-th (1≤𝑖≤𝑘
) sold bun is (𝑏−𝑖+1)
 coins.
The remaining (𝑛−𝑘)
 buns are sold at 𝑎
 coins each.
Note that 𝑘
 can be equal to 0
. In this case, Bob will sell all the buns at 𝑎
 coins each.

Help Bob determine the maximum profit he can obtain by selling all 𝑛
 buns.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test
cases follows.

The only line of each test case contains three integers 𝑛
, 𝑎
, and 𝑏
 (1≤𝑛,𝑎,𝑏≤109
) — the number of buns, the usual price of a bun, and the price of the first bun
to be sold at a modified price.

Output
For each test case, output a single integer — the maximum profit that Bob can
obtain.

Example
InputCopy
7
4 4 5
5 5 9
10 10 5
5 5 11
1000000000 1000000000 1000000000
1000000000 1000000000 1
1000 1 1000
OutputCopy
17
35
100
45
1000000000000000000
1000000000000000000
500500
Note
In the first test case, it is optimal for Bob to choose 𝑘=1
. Then he will sell one bun for 5
 coins, and three buns at the usual price for 4
 coins each. Then the profit will be 5+4+4+4=17
 coins.

In the second test case, it is optimal for Bob to choose 𝑘=5
. Then he will sell all the buns at the modified price and obtain a profit of
9+8+7+6+5=35 coins.

In the third test case, it is optimal for Bob to choose 𝑘=0
. Then he will sell all the buns at the usual price and obtain a profit of
10⋅10=100 coins.*/
#include <iostream>

typedef long long ll;
int main() {

  ll t;
  std::cin >> t;

  while (t--) {
    ll n, a, b;
    std::cin >> n >> a >> b;

    ll k = b - a;
    k = (k > 0 ? k : 0);
    k = (k < n ? k : n);
    ll total = b * k - k * (k - 1) / 2 + (n - k) * a;
    std::cout << total << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1978/316179344
