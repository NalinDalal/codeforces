/* https://codeforces.com/problemset/problem/1850/D
D. Balanced Round
time limit per test2 seconds
memory limit per test256 megabytes
You are the author of a Codeforces round and have prepared 𝑛
 problems you are going to set, problem 𝑖
 having difficulty 𝑎𝑖
. You will do the following process:

remove some (possibly zero) problems from the list;
rearrange the remaining problems in any order you wish.
A round is considered balanced if and only if the absolute difference between
the difficulty of any two consecutive problems is at most 𝑘 (less or equal than
𝑘
).

What is the minimum number of problems you have to remove so that an arrangement
of problems is balanced?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The first line of each test case contains two positive integers 𝑛
 (1≤𝑛≤2⋅105
) and 𝑘
 (1≤𝑘≤109
) — the number of problems, and the maximum allowed absolute difference between
consecutive problems.

The second line of each test case contains 𝑛
 space-separated integers 𝑎𝑖
 (1≤𝑎𝑖≤109
) — the difficulty of each problem.

Note that the sum of 𝑛
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case, output a single integer — the minimum number of problems you
have to remove so that an arrangement of problems is balanced.

Example
InputCopy
7
5 1
1 2 4 5 6
1 2
10
8 3
17 3 1 20 12 5 17 12
4 2
2 4 6 8
5 3
2 3 19 10 8
3 4
1 10 5
8 1
8 3 1 4 5 10 7 3
OutputCopy
2
0
5
0
3
1
4
Note
For the first test case, we can remove the first 2
 problems and construct a set using problems with the difficulties [4,5,6]
, with difficulties between adjacent problems equal to |5−4|=1≤1
 and |6−5|=1≤1
.

For the second test case, we can take the single problem and compose a round
using the problem with difficulty 10
.



*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n, k;
    scanf("%ld %ld", &n, &k);
    std::vector<long> a(n);
    for (long p = 0; p < n; p++) {
      scanf("%ld", &a[p]);
    }
    sort(a.begin(), a.end());

    long cur(1), mx(1);
    for (long p = 1; p < n; p++) {
      if (a[p] <= a[p - 1] + k) {
        ++cur;
        mx = (mx > cur ? mx : cur);
      } else {
        cur = 1;
      }
    }

    printf("%ld\n", n - mx);
  }
}

// sub: https://codeforces.com/problemset/submission/1850/302785454
