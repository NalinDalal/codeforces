/*C. Earning on Bets
time limit per test2 seconds
memory limit per test256 megabytes
You have been offered to play a game. In this game, there are 𝑛
 possible outcomes, and for each of them, you must bet a certain integer amount
of coins. In the event that the 𝑖 -th outcome turns out to be winning, you will
receive back the amount of coins equal to your bet on that outcome, multiplied
by 𝑘𝑖 . Note that exactly one of the 𝑛 outcomes will be winning.

Your task is to determine how to distribute the coins in such a way that you
will come out ahead in the event of any winning outcome. More formally, the
total amount of coins you bet on all outcomes must be strictly less than the
number of coins received back for each possible winning outcome.

Input
Ea[48;52;178;1768;2848tch test consists of multiple test cases. The first line
contains a single integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The
description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤50
) — the number of outcomes.

The second line of each test case contains 𝑛
 integers 𝑘1,𝑘2,…,𝑘𝑛
 (2≤𝑘𝑖≤20
) — the multiplier for the amount of coins if the 𝑖
-th outcome turns out to be winning.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output −1
 if there is no way to distribute the coins as required. Otherwise, output 𝑛
 integers 𝑥1,𝑥2,…,𝑥𝑛
 (1≤𝑥𝑖≤109
) — your bets on the outcomes.

It can be shown that if a solution exists, there is always a solution that
satisfies these constraints.

If there are multiple suitable solutions, output any of them.

Example
InputCopy
6
3
3 2 7
2
3 3
5
5 5 5 5 5
6
7 9 3 17 9 13
3
6 3 2
5
9 4 6 8 3
OutputCopy
27 41 12
1 1
-1
1989 1547 4641 819 1547 1071
-1
8 18 12 9 24
Note
In the first test case, the coins can be distributed as follows: 27
 coins on the first outcome, 41
 coins on the second outcome, 12
 coins on the third outcome. Then the total amount of coins bet on all outcomes
is 27+41+12=80 coins. If the first outcome turns out to be winning, you will
receive back 3⋅27=81 coins, if the second outcome turns out to be winning, you
will receive back 2⋅41=82 coins, if the third outcome turns out to be winning,
you will receive back 7⋅12=84 coins. All these values are strictly greater than
80
.

In the second test case, one way is to bet one coin on each of the outcomes.

*/

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int main() {

  ll t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;

    std::vector<ll> v(n);
    ll s = 1;
    for (ll p = 0; p < n; p++) {
      cin >> v[p];

      s = lcm(s, v[p]);
    }

    ll total = 0;
    for (long p = 0; p < n; p++) {
      v[p] = s / v[p];
      total += v[p];
    }
    if (total >= s) {
      cout << "-1" << endl;

      continue;
    }
    for (long p = 0; p < n; p++) {
      cout << v[p] << " ";
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1979/326098103
