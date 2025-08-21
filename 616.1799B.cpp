/*B. Equalize by Divide
time limit per test1 second
memory limit per test256 megabytes
You are given an array 𝑎1,𝑎2,…,𝑎𝑛
 of positive integers.

You can make this operation multiple (possibly zero) times:

Choose two indices 𝑖
, 𝑗
 (1≤𝑖,𝑗≤𝑛
, 𝑖≠𝑗
).
Assign 𝑎𝑖:=⌈𝑎𝑖𝑎𝑗⌉
. Here ⌈𝑥⌉
 denotes 𝑥
 rounded up to the smallest integer ≥𝑥
.
Is it possible to make all array elements equal by some sequence of operations
(possibly empty)? If yes, print any way to do it in at most 30𝑛 operations.

It can be proven, that under the problem constraints, if some way exists to make
all elements equal, there exists a way with at most 30𝑛 operations.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases. Descriptions of test cases follow.

The first line of each test case description contains a single integer 𝑛
 (1≤𝑛≤100
).

The second line of each test case description contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
).

It is guaranteed, that the sum of 𝑛
 for all test cases does not exceed 1000
.

Output
For each test case print a single integer 𝑞
 (−1≤𝑞≤30𝑛
). If 𝑞=−1
, there is no solution, otherwise 𝑞
 is equal to the number of operations.

If 𝑞≥0
, on the next 𝑞
 lines print two integers 𝑖
, 𝑗
 (1≤𝑖,𝑗≤𝑛
, 𝑖≠𝑗
) — descriptions of operations.

If there are multiple solutions, you can print any.

Example
InputCopy
10
1
100
3
1 1 1
2
2 1
2
5 5
3
4 3 2
4
3 3 4 4
2
2 100
5
5 3 6 7 8
6
3 3 80 3 8 3
4
19 40 19 55
OutputCopy
0
0
-1
0
2
1 3
2 1
4
3 1
4 2
1 3
2 4
6
2 1
2 1
2 1
2 1
2 1
2 1
8
5 2
4 2
3 2
1 3
1 3
2 1
4 1
5 1
4
5 1
3 1
3 1
3 1
9
4 2
2 1
1 2
1 2
3 2
3 2
1 4
2 4
3 4
Note
In the first and second, fourth test cases all numbers are equal, so it is
possible to do nothing.

In the third test case, it is impossible to make all numbers equal.

In the fifth test case: [4,3,2]→[2,3,2]→[2,2,2]
.

In the sixth test case: [3,3,4,4]→[3,3,2,4]→[3,3,2,2]→[2,3,2,2]→[2,2,2,2]
.

Here the red numbers are 𝑖
 indices (that will be assigned), blue numbers are 𝑗
 indices.



*/

#include <iostream>
#include <set>
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
    set<pair<long, long>> s;
    for (long p = 1; p <= n; p++) {
      long x;
      cin >> x;
      s.insert({x, p});
    }

    if (s.begin()->first <= 1 && s.rbegin()->first > 1) {
      cout << -1 << "\n";
      continue;
    }

    vector<pair<long, long>> v;
    for (long p = 0; p < 30 * n; p++) {
      long num = s.rbegin()->first;
      long idxl = s.rbegin()->second;

      long den = s.begin()->first;
      long idxs = s.begin()->second;

      if (num == den)
        break;
      v.push_back({idxl, idxs});
      s.erase(*s.rbegin());
      s.insert({(num + den - 1) / den, idxl});
    }

    cout << v.size() << "\n";
    for (auto &pr : v) {
      cout << pr.first << " " << pr.second << "\n";
    }
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1799/334732696
