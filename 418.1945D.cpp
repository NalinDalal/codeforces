/*D. Seraphim the Owl
time limit per test2 seconds
memory limit per test256 megabytes
The guys lined up in a queue of 𝑛
 people, starting with person number 𝑖=1
, to ask Serafim the Owl about the meaning of life. Unfortunately, Kirill was
very busy writing the legend for this problem, so he arrived a little later and
stood at the end of the line after the 𝑛 -th person. Kirill is completely
dissatisfied with this situation, so he decided to bribe some people ahead of
him.

For the 𝑖
-th person in the queue, Kirill knows two values: 𝑎𝑖
 and 𝑏𝑖
. If at the moment Kirill is standing at position 𝑖
, then he can choose any position 𝑗
 such that 𝑗<𝑖
 and exchange places with the person at position 𝑗
. In this case, Kirill will have to pay him 𝑎𝑗
 coins. And for each 𝑘
 such that 𝑗<𝑘<𝑖
, Kirill will have to pay 𝑏𝑘
 coins to the person at position 𝑘
. Kirill can perform this action any number of times.

Kirill is thrifty, so he wants to spend as few coins as possible, but he doesn't
want to wait too long, so Kirill believes he should be among the first 𝑚 people
in line.

Help Kirill determine the minimum number of coins he will have to spend in order
to not wait too long.

Input
Each test consists of several sets of input data. The first line contains a
single integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. Then follows the
description of the test case.

The first line of each test case contains two integers 𝑛
 and 𝑚
 (1≤𝑚≤𝑛≤200000
) — the number of people in the queue besides Kirill and the maximum allowable
final position of Kirill, respectively.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 separated by spaces (1≤𝑎𝑖≤109
).

The third line contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 separated by spaces (1≤𝑏𝑖≤109
).

It is guaranteed that the sum of the values of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the minimum number of coins Kirill
needs to spend.

Example
InputCopy
4
4 2
7 3 6 9
4 3 8 5
6 2
6 9 7 1 8 3
5 8 8 1 4 1
7 7
7 2 9 2 6 5 9
9 1 10 7 1 4 9
2 1
2 3
1 1
OutputCopy
14
22
9
3


*/

#include <cstdio>
#include <vector>
typedef long long ll;

int main() {

  ll t;
  scanf("%lld", &t);
  while (t--) {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    std::vector<ll> a(n);
    for (ll p = 0; p < n; p++) {
      scanf("%lld", &a[p]);
    }
    std::vector<ll> b(n);
    for (ll p = 0; p < n; p++) {
      scanf("%lld", &b[p]);
    }

    ll prev(0), rbs(0);
    std::vector<ll> f(n, 0);
    for (ll p = n - 1; p >= 0; p--) {
      f[p] = a[p] + rbs + prev;
      rbs += b[p];
      if (a[p] <= b[p]) {
        rbs = 0;
        prev = f[p];
      }
    }

    ll ans(f[0]);
    for (ll p = 0; p < m; p++) {
      ans = (ans < f[p] ? ans : f[p]);
    }
    printf("%lld\n", ans);
  }
}
// sub: https://codeforces.com/problemset/submission/1945/324330186
