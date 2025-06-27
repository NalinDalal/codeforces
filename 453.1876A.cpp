/*A. Helmets in Night Light
time limit per test1 second
memory limit per test256 megabytes
Pak Chanek is the chief of a village named Khuntien. On one night filled with
lights, Pak Chanek has a sudden and important announcement that needs to be
notified to all of the 𝑛 residents in Khuntien.

First, Pak Chanek shares the announcement directly to one or more residents with
a cost of 𝑝 for each person. After that, the residents can share the
announcement to other residents using a magical helmet-shaped device. However,
there is a cost for using the helmet-shaped device. For each 𝑖 , if the 𝑖 -th
resident has got the announcement at least once (either directly from Pak Chanek
or from another resident), he/she can share the announcement to at most 𝑎𝑖 other
residents with a cost of 𝑏𝑖 for each share.

If Pak Chanek can also control how the residents share the announcement to other
residents, what is the minimum cost for Pak Chanek to notify all 𝑛 residents of
Khuntien about the announcement?

Input
Each test contains multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The following lines contain the description of
each test case.

The first line contains two integers 𝑛
 and 𝑝
 (1≤𝑛≤105
; 1≤𝑝≤105
) — the number of residents and the cost for Pak Chanek to share the
announcement directly to one resident.

The second line contains 𝑛
 integers 𝑎1,𝑎2,𝑎3,…,𝑎𝑛
 (1≤𝑎𝑖≤105
) — the maximum number of residents that each resident can share the
announcement to.

The third line contains 𝑛
 integers 𝑏1,𝑏2,𝑏3,…,𝑏𝑛
 (1≤𝑏𝑖≤105
) — the cost for each resident to share the announcement to one other resident.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output a line containing an integer representing the minimum
cost to notify all 𝑛 residents of Khuntien about the announcement.

Example
InputCopy
3
6 3
2 3 2 1 1 3
4 3 2 6 3 6
1 100000
100000
1
4 94
1 4 2 3
103 96 86 57
OutputCopy
16
100000
265
Note
In the first test case, the following is a possible optimal strategy:

Pak Chanek shares the announcement directly to the 3
-rd, 5
-th, and 6
-th resident. This requires a cost of 𝑝+𝑝+𝑝=3+3+3=9
.
The 3
-rd resident shares the announcement to the 1
-st and 2
-nd resident. This requires a cost of 𝑏3+𝑏3=2+2=4
.
The 2
-nd resident shares the announcement to the 4
-th resident. This requires a cost of 𝑏2=3
.
The total cost is 9+4+3=16
. It can be shown that there is no other strategy with a smaller cost.



*/

#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;

int main() {
  ll t;
  std::cin >> t;
  while (t--) {
    ll n, r;
    std::cin >> n >> r;

    std::vector<std::pair<ll, ll>> v(n);
    for (ll p = 0; p < n; ++p)
      std::cin >> v[p].second;
    for (ll p = 0; p < n; ++p)
      std::cin >> v[p].first;

    std::sort(v.begin(), v.end());

    ll rem = n - 1;
    ll total = r;
    for (ll p = 0; p < n; ++p) {
      if (v[p].first >= r)
        break;
      ll cnt = std::min(rem, v[p].second);
      total += cnt * v[p].first;
      rem -= cnt;
    }

    total += r * rem;
    std::cout << total << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1876/326244490
