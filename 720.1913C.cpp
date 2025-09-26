/*C. Game with Multiset
time limit per test1.5 seconds
memory limit per test256 megabytes
In this problem, you are initially given an empty multiset. You have to process
two types of queries:

ADD 𝑥
 — add an element equal to 2𝑥
 to the multiset;
GET 𝑤
 — say whether it is possible to take the sum of some subset of the current
multiset and get a value equal to 𝑤
.
Input
The first line contains one integer 𝑚
 (1≤𝑚≤105
) — the number of queries.

Then 𝑚
 lines follow, each of which contains two integers 𝑡𝑖
, 𝑣𝑖
, denoting the 𝑖
-th query. If 𝑡𝑖=1
, then the 𝑖
-th query is ADD 𝑣𝑖
 (0≤𝑣𝑖≤29
). If 𝑡𝑖=2
, then the 𝑖
-th query is GET 𝑣𝑖
 (0≤𝑣𝑖≤109
).

Output
For each GET query, print YES if it is possible to choose a subset with sum
equal to 𝑤 , or NO if it is impossible.

Examples
InputCopy
5
1 0
1 0
1 0
2 3
2 4
OutputCopy
YES
NO
InputCopy
7
1 0
1 1
1 2
1 10
2 4
2 6
2 7
OutputCopy
YES
YES
YES
*/

/*empty multiset
2 query:
    ADD x → insert 2^x into the multiset.
    GET w → ask if some subset of the current multiset sums exactly to w.

no of form 2^x, so a binary resource pool
To check if w can be formed, we can greedily try to cover w from largest to
smallest power of two:
    - At bit level i, we know how many 2^i we have.
    - We see how many we need to cover the current w.
    - Take min(need, available[i]), subtract from w.
    - Move down to next bit.

Maintain an array cnt[30] = how many of each 2^i we have.

For ADD x: cnt[x]++.

For GET w:

For i from 29 down to 0:

need = w >> i (how many 2^i needed).

take = min(need, cnt[i]).

w -= take * (1 << i).

At end, if w == 0, answer YES, else NO.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> m;
  vector<int> cnt(30, 0); // count of each power of two

  while (m--) {
    int t, v;
    cin >> t >> v;

    if (t == 1) {
      cnt[v]++; // add 2^v
    } else {
      long long w = v;
      for (int i = 29; i >= 0; i--) {
        long long need = w >> i; // how many 2^i needed
        long long take = min<long long>(need, cnt[i]);
        w -= take * (1LL << i);
      }
      cout << (w == 0 ? "YES\n" : "NO\n");
    }
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1913/340563809
