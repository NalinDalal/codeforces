/*C. Double Sort
time limit per test2 seconds
memory limit per test256 megabytes
You are given two arrays 𝑎
 and 𝑏
, both consisting of 𝑛
 integers.

In one move, you can choose two indices 𝑖
 and 𝑗
 (1≤𝑖,𝑗≤𝑛
; 𝑖≠𝑗
) and swap 𝑎𝑖
 with 𝑎𝑗
 and 𝑏𝑖
 with 𝑏𝑗
. You have to perform the swap in both arrays.

You are allowed to perform at most 104
 moves (possibly, zero). Can you make both arrays sorted in a non-decreasing
order at the end? If you can, print any sequence of moves that makes both arrays
sorted.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of testcases.

The first line of each testcase contains a single integer 𝑛
 (2≤𝑛≤100
) — the number of elements in both arrays.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
) — the first array.

The third line contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤𝑛
) — the second array.

Output
For each testcase, print the answer. If it's impossible to make both arrays
sorted in a non-decreasing order in at most 104 moves, print -1. Otherwise,
first, print the number of moves 𝑘 (0≤𝑘≤104) . Then print 𝑖 and 𝑗 for each move
(1≤𝑖,𝑗≤𝑛 ; 𝑖≠𝑗)
.

If there are multiple answers, then print any of them. You don't have to
minimize the number of moves.

Example
InputCopy
3
2
1 2
1 2
2
2 1
1 2
4
2 3 1 2
2 3 2 3
OutputCopy
0
-1
3
3 1
3 2
4 3
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
    long n;
    cin >> n;
    vector<long> a(n), b(n);
    vector<pair<long, long>> v;

    for (long p = 0; p < n; ++p)
      cin >> a[p];
    for (long p = 0; p < n; ++p)
      cin >> b[p];

    for (long p = 0; p < n; ++p) {
      for (long q = 0; q < n - 1; ++q) {
        if (a[q] > a[q + 1] || b[q] > b[q + 1]) {
          swap(a[q], a[q + 1]);
          swap(b[q], b[q + 1]);
          v.emplace_back(q, q + 1);
        }
      }
    }

    if (is_sorted(a.begin(), a.end()) && is_sorted(b.begin(), b.end())) {
      cout << v.size() << "\n";
      for (auto &p : v)
        cout << (p.first + 1) << " " << (p.second + 1) << "\n";
    } else {
      cout << -1 << "\n";
    }
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1681/344852223
