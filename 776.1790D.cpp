/*D. Matryoshkas
time limit per test2 seconds
memory limit per test256 megabytes
Matryoshka is a wooden toy in the form of a painted doll, inside which you can
put a similar doll of a smaller size.

A set of nesting dolls contains one or more nesting dolls, their sizes are
consecutive positive integers. Thus, a set of nesting dolls is described by two
numbers: 𝑠 — the size of a smallest nesting doll in a set and 𝑚 — the number of
dolls in a set. In other words, the set contains sizes of 𝑠,𝑠+1,…,𝑠+𝑚−1 for some
integer 𝑠 and 𝑚 (𝑠,𝑚>0
).

You had one or more sets of nesting dolls. Recently, you found that someone
mixed all your sets in one and recorded a sequence of doll sizes — integers
𝑎1,𝑎2,…,𝑎𝑛
.

You do not remember how many sets you had, so you want to find the minimum
number of sets that you could initially have.

For example, if a given sequence is 𝑎=[2,2,3,4,3,1]
. Initially, there could be 2
 sets:

the first set consisting of 4
 nesting dolls with sizes [1,2,3,4]
;
a second set consisting of 2
 nesting dolls with sizes [2,3]
.
According to a given sequence of sizes of nesting dolls 𝑎1,𝑎2,…,𝑎𝑛
, determine the minimum number of nesting dolls that can make this sequence.

Each set is completely used, so all its nesting dolls are used. Each element of
a given sequence must correspond to exactly one doll from some set.

Input
The first line of input data contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The description of the test cases follows.

The first line of each test case contains one integer 𝑛
 (1≤𝑛≤2⋅105
) — the total number of matryoshkas that were in all sets.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
)  — the sizes of the matryoshkas.

It is guaranteed that the sum of values of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print one integer 𝑘
 — the minimum possible number of matryoshkas sets.

Example
InputCopy
10
6
2 2 3 4 3 1
5
11 8 7 10 9
6
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
8
1 1 4 4 2 3 2 3
6
1 2 3 2 3 4
7
10 11 11 12 12 13 13
7
8 8 9 9 10 10 11
8
4 14 5 15 6 16 7 17
8
5 15 6 14 8 12 9 11
5
4 2 2 3 4
OutputCopy
2
1
6
2
2
2
2
2
4
3
Note
The first test case is described in the problem statement.

In the second test case, all matryoshkas could be part of the same set with
minimum size 𝑠=7
.

In the third test case, each matryoshka represents a separate set.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    vector<long> v(n);
    for (auto &x : v)
      cin >> x;

    sort(v.begin(), v.end());
    v.push_back(1e9 + 3); // sentinel

    long prev = v[0];
    long cur = 1;
    long cnt = 0;
    long run = 0;

    for (long p = 1; p <= n; ++p) {
      if (v[p] == prev) {
        ++cur;
      } else {
        if (cur < run) {
          cnt += (run - cur);
          run = cur;
        } else {
          run = cur;
        }

        if (v[p] > prev + 1) {
          cnt += run;
          run = 0;
        }

        cur = 1;
      }
      prev = v[p];
    }

    cout << cnt << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1790/343974361
