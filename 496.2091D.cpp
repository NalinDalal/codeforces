/*D. Place of the Olympiad
time limit per test1 second
memory limit per test256 megabytes
For the final of the first Olympiad by IT Campus "NEIMARK", a rectangular venue
was prepared. You may assume that the venue is divided into 𝑛 rows, each
containing 𝑚 spots for participants' desks. A total of 𝑘 participants have
registered for the final, and each participant will sit at an individual desk.
Now, the organizing committee must choose the locations for the desks in the
venue.

Each desk occupies one of the 𝑚
 spots in a row. Moreover, if several desks occupy consecutive spots in the same
row, we call such a group of desks a bench, and the number of desks in the group
is the bench's length. For example, seating 7 participants on a 3×4 venue (with
𝑛=3,𝑚=4 ) can be arranged as follows:


In the figure above, the first row has one bench of length 3
, the second row has one bench of length 2
, and the third row has two benches of length 1
.

The organizing committee wants to choose the locations so that the length of the
longest bench is as small as possible. In particular, the same 7 desks can be
arranged in a more optimal way, so that the lengths of all benches do not exceed
2
:


Given the integers 𝑛
, 𝑚
, and 𝑘
, determine the minimum possible length of the longest bench.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

A single line of each test case contains three positive integers — 𝑛
, 𝑚
, 𝑘
 (1≤𝑛,𝑚,𝑘≤109
, 𝑘≤𝑛⋅𝑚
).

Output
For each test case, output a single number — the minimum possible length of the
longest bench.

Example
InputCopy
5
3 4 7
5 5 5
1 13 2
2 4 7
1 5 4
OutputCopy
2
1
1
4
2

*/

#include <cstdio>
typedef long long ll;

int main() {

  ll t;
  scanf("%lld", &t);
  while (t--) {
    ll n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);
    ll left(0), right(m), res(-1);
    while (left <= right) {
      ll mid = (left + right) / 2;
      ll tmp = n * ((m / (mid + 1)) * mid + m % (mid + 1));
      if (tmp >= k) {
        res = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    printf("%lld\n", res);
  }
}
// sub: https://codeforces.com/problemset/submission/2091/328695477
