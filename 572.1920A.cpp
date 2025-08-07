/*A. Satisfying Constraints
time limit per test1 second
memory limit per test256 megabytes
Alex is solving a problem. He has 𝑛
 constraints on what the integer 𝑘
 can be. There are three types of constraints:

𝑘
 must be greater than or equal to some integer 𝑥
;
𝑘
 must be less than or equal to some integer 𝑥
;
𝑘
 must be not equal to some integer 𝑥
.
Help Alex find the number of integers 𝑘
 that satisfy all 𝑛
 constraints. It is guaranteed that the answer is finite (there exists at least
one constraint of type 1 and at least one constraint of type 2
). Also, it is guaranteed that no two constraints are the exact same.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤500 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤100
) — the number of constraints.

The following 𝑛
 lines describe the constraints. Each line contains two integers 𝑎
 and 𝑥
 (𝑎∈{1,2,3},1≤𝑥≤109
). 𝑎
 denotes the type of constraint. If 𝑎=1
, 𝑘
 must be greater than or equal to 𝑥
. If 𝑎=2
, 𝑘
 must be less than or equal to 𝑥
. If 𝑎=3
, 𝑘
 must be not equal to 𝑥
.

It is guaranteed that there is a finite amount of integers satisfying all 𝑛
 constraints (there exists at least one constraint of type 1
 and at least one constraint of type 2
). It is also guaranteed that no two constraints are the exact same (in other
words, all pairs (𝑎,𝑥) are distinct).

Output
For each test case, output a single integer — the number of integers 𝑘
 that satisfy all 𝑛
 constraints.

Example
InputCopy
6
4
1 3
2 10
3 1
3 5
2
1 5
2 4
10
3 6
3 7
1 2
1 7
3 100
3 44
2 100
2 98
1 3
3 99
6
1 5
2 10
1 9
2 2
3 2
3 9
5
1 1
2 2
3 1
3 2
3 3
6
1 10000
2 900000000
3 500000000
1 100000000
3 10000
3 900000001
OutputCopy
7
0
90
0
0
800000000
Note
In the first test case, 𝑘≥3
 and 𝑘≤10
. Furthermore, 𝑘≠1
 and 𝑘≠5
. The possible integers 𝑘
 that satisfy the constraints are 3,4,6,7,8,9,10
. So the answer is 7
.

In the second test case, 𝑘≥5
 and 𝑘≤4
, which is impossible. So the answer is 0
.
*/
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;

  while (t--) {
    long n;
    std::cin >> n;

    long mn = 0;
    long mx = 1e9 + 7;
    std::vector<long> v;

    for (long p = 0; p < n; ++p) {
      int a;
      long x;
      std::cin >> a >> x;

      if (a == 1) {
        mn = std::max(mn, x);
      } else if (a == 2) {
        mx = std::min(mx, x);
      } else {
        v.push_back(x);
      }
    }

    long cnt = mx - mn + 1;
    for (long x : v) {
      if (mn <= x && x <= mx) {
        --cnt;
      }
    }

    std::cout << std::max(cnt, 0L) << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1920/332740027
