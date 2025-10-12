/*A. Add and Divide
time limit per test1 second
memory limit per test256 megabytes
You have two positive integers 𝑎
 and 𝑏
.

You can perform two kinds of operations:

𝑎=⌊𝑎𝑏⌋
 (replace 𝑎
 with the integer part of the division between 𝑎
 and 𝑏
)
𝑏=𝑏+1
 (increase 𝑏
 by 1
)
Find the minimum number of operations required to make 𝑎=0
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of test cases.

The only line of the description of each test case contains two integers 𝑎
, 𝑏
 (1≤𝑎,𝑏≤109
).

Output
For each test case, print a single integer: the minimum number of operations
required to make 𝑎=0
.

Example
InputCopy
6
9 2
1337 1
1 1
50000000 4
991026972 997
1234 5678
OutputCopy
4
9
2
12
3
1
Note
In the first test case, one of the optimal solutions is:

Divide 𝑎
 by 𝑏
. After this operation 𝑎=4
 and 𝑏=2
.
Divide 𝑎
 by 𝑏
. After this operation 𝑎=2
 and 𝑏=2
.
Increase 𝑏
. After this operation 𝑎=2
 and 𝑏=3
.
Divide 𝑎
 by 𝑏
. After this operation 𝑎=0
 and 𝑏=3
.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long a, b;
    cin >> a >> b;

    long res = 1 + a / b;
    for (long p = b; p <= b + 100; ++p) {
      if (p == 1)
        continue; // skip invalid base
      long div = 0, cur = a;
      while (cur) {
        cur /= p;
        ++div;
      }
      long cnt = (p - b) + div;
      res = min(res, cnt);
    }

    cout << res << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1485/343244722
