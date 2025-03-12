/*A. Special Permutation
time limit per test1 second
memory limit per test256 megabytes
You are given one integer 𝑛
 (𝑛>1
).

Recall that a permutation of length 𝑛
 is an array consisting of 𝑛
 distinct integers from 1
 to 𝑛
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation of length 5
, but [1,2,2]
 is not a permutation (2
 appears twice in the array) and [1,3,4]
 is also not a permutation (𝑛=3
 but there is 4
 in the array).

Your task is to find a permutation 𝑝
 of length 𝑛
 that there is no index 𝑖
 (1≤𝑖≤𝑛
) such that 𝑝𝑖=𝑖
 (so, for all 𝑖
 from 1
 to 𝑛
 the condition 𝑝𝑖≠𝑖
 should be satisfied).

You have to answer 𝑡
 independent test cases.

If there are several answers, you can print any. It can be proven that the
answer exists for each 𝑛>1
.

Input
The first line of the input contains one integer 𝑡
 (1≤𝑡≤100
) — the number of test cases. Then 𝑡
 test cases follow.

The only line of the test case contains one integer 𝑛
 (2≤𝑛≤100
) — the length of the permutation you have to find.

Output
For each test case, print 𝑛
 distinct integers 𝑝1,𝑝2,…,𝑝𝑛
 — a permutation that there is no index 𝑖
 (1≤𝑖≤𝑛
) such that 𝑝𝑖=𝑖
 (so, for all 𝑖
 from 1
 to 𝑛
 the condition 𝑝𝑖≠𝑖
 should be satisfied).

If there are several answers, you can print any. It can be proven that the
answer exists for each 𝑛>1
.

Example
InputCopy
2
2
5
OutputCopy
2 1
2 1 5 3 4

*/
#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
      std::cout << 1 + (i + 1) % n << " ";
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1454/310224557
