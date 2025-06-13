/*C. Inhabitant of the Deep Sea
time limit per test2 seconds
memory limit per test256 megabytes
𝑛
 ships set out to explore the depths of the ocean. The ships are numbered from 1
 to 𝑛
 and follow each other in ascending order; the 𝑖
-th ship has a durability of 𝑎𝑖
.

The Kraken attacked the ships 𝑘
 times in a specific order. First, it attacks the first of the ships, then the
last, then the first again, and so on.

Each attack by the Kraken reduces the durability of the ship by 1
. When the durability of the ship drops to 0
, it sinks and is no longer subjected to attacks (thus the ship ceases to be the
first or last, and the Kraken only attacks the ships that have not yet sunk). If
all the ships have sunk, the Kraken has nothing to attack and it swims away.

For example, if 𝑛=4
, 𝑘=5
, and 𝑎=[1,2,4,3]
, the following will happen:

The Kraken attacks the first ship, its durability becomes zero and now 𝑎=[2,4,3]
;
The Kraken attacks the last ship, now 𝑎=[2,4,2]
;
The Kraken attacks the first ship, now 𝑎=[1,4,2]
;
The Kraken attacks the last ship, now 𝑎=[1,4,1]
;
The Kraken attacks the first ship, its durability becomes zero and now 𝑎=[4,1]
.
How many ships were sunk after the Kraken's attack?

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤2⋅105
, 1≤𝑘≤1015
) — the number of ships and how many times the Kraken will attack the ships.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the durability of the ships.

It is guaranteed that the sum of 𝑛
 for all test cases does not exceed 2⋅105
.

Output
For each test case, output the number of ships sunk by the Kraken on a separate
line.

Example
InputCopy
6
4 5
1 2 4 3
4 6
1 2 4 3
5 20
2 7 1 8 2
2 2
3 2
2 15
1 5
2 7
5 2
OutputCopy
2
3
5
0
2
2


*/

#include <cstdio>
#include <deque>
#include <vector>
typedef long long ll;

int main() {

  ll t;
  scanf("%lld", &t);
  while (t--) {
    ll n, k;
    scanf("%lld %lld", &n, &k);
    std::deque<ll> dq(n);
    for (ll p = 0; p < n; p++) {
      ll x;
      scanf("%lld", &x);
      dq.push_back(x);
    }
    while (k && dq.size() > 1) {
      int mn = (dq.front() < dq.back() ? dq.front() : dq.back());
      int rem = (k < (2 * mn) ? k : (2 * mn));
      dq.front() -= (rem + 1) / 2;
      dq.back() -= (rem / 2);
      if (dq.front() == 0) {
        dq.pop_front();
      }
      if (dq.back() == 0) {
        dq.pop_back();
      }
      k -= rem;
    }

    if (!dq.empty()) {
      dq.front() -= k;
      if (dq.front() <= 0) {
        dq.pop_front();
      }
    }

    printf("%lld\n", n - dq.size());
  }
}
// sub: https://codeforces.com/problemset/submission/1955/324246034
