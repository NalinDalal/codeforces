/*B. Minimize Inversions
time limit per test2 seconds
memory limit per test256 megabytes
You are given two permutations 𝑎
 and 𝑏
 of length 𝑛
. A permutation is an array of 𝑛
 elements from 1
 to 𝑛
 where all elements are distinct. For example, an array [2,1,3
] is a permutation, but [0,1
] and [1,3,1
] aren't.

You can (as many times as you want) choose two indices 𝑖
 and 𝑗
, then swap 𝑎𝑖
 with 𝑎𝑗
 and 𝑏𝑖
 with 𝑏𝑗
 simultaneously.

You hate inversions, so you want to minimize the total number of inversions in
both permutations.

An inversion in a permutation 𝑝
 is a pair of indices (𝑖,𝑗)
 such that 𝑖<𝑗
 and 𝑝𝑖>𝑝𝑗
. For example, if 𝑝=[3,1,4,2,5]
 then there are 3
 inversions in it (the pairs of indices are (1,2)
, (1,4)
 and (3,4)
).

Input
The first line contains an integer 𝑡
 (1≤𝑡≤20000
) — the number of test cases.

Each test case consists of three lines. The first line contains an integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of the permutations 𝑎
 and 𝑏
. The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
) — permutation 𝑎
. The third line contains 𝑏
 in a similar format.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output two permutations 𝑎′
 and 𝑏′
 (in the same format as in the input) — the permutations after all operations.
The total number of inversions in 𝑎′ and 𝑏′ should be the minimum possible among
all pairs of permutations that can be obtained using operations from the
statement.

If there are multiple solutions, print any of them.

Example
InputCopy
3
5
1 2 3 4 5
5 4 3 2 1
3
3 1 2
3 1 2
6
2 5 6 1 3 4
1 5 3 6 2 4
OutputCopy
3 2 5 1 4
3 4 1 5 2
1 2 3
1 2 3
2 3 4 6 5 1
1 2 4 3 5 6
Note
In the first test case, the minimum possible number of inversions is 10
.

In the second test case, we can sort both permutations at the same time. For
this, the following operations can be done:

Swap the elements in the positions 1
 and 3
 in both permutations. After the operation, 𝑎=
 [2,1,3
], 𝑏=
 [2,1,3
].
Swap the elements in the positions 1
 and 2
. After the operations, 𝑎
 and 𝑏
 are sorted.
In the third test case, the minimum possible number of inversions is 7
.



*/

#include <algorithm>
#include <cstdio>
#include <vector>

int main() {
  long t;
  scanf("%ld", &t);
  while (t--) {
    long n;
    scanf("%ld", &n);
    std::vector<std::pair<long, long>> v(n);
    for (long p = 0; p < n; p++) {
      scanf("%ld", &v[p].first);
    }
    for (long p = 0; p < n; p++) {
      scanf("%ld", &v[p].second);
    }
    sort(v.begin(), v.end());
    for (long p = 0; p < n; p++) {
      printf("%ld ", v[p].first);
    };
    puts("");
    for (long p = 0; p < n; p++) {
      printf("%ld ", v[p].second);
    };
    puts("");
  }
}
// sub: https://codeforces.com/problemset/submission/1918/324438592
