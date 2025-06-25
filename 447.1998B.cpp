/*B. Minimize Equal Sum Subarrays
time limit per test1.5 seconds
memory limit per test256 megabytes
It is known that Farmer John likes Permutations, but I like them too!
— Sun Tzu, The Art of Constructing Permutations
You are given a permutation∗
 𝑝
 of length 𝑛
.

Find a permutation 𝑞
 of length 𝑛
 that minimizes the number of pairs (𝑖,𝑗
) (1≤𝑖≤𝑗≤𝑛
) such that 𝑝𝑖+𝑝𝑖+1+…+𝑝𝑗=𝑞𝑖+𝑞𝑖+1+…+𝑞𝑗
.

∗
A permutation of length 𝑛
 is an array consisting of 𝑛
 distinct integers from 1
 to 𝑛
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (𝑛=3
 but there is 4
 in the array).

Input
The first line contains 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains 𝑛
 (1≤𝑛≤2⋅105
).

The following line contains 𝑛
 space-separated integers 𝑝1,𝑝2,…,𝑝𝑛
 (1≤𝑝𝑖≤𝑛
) — denoting the permutation 𝑝
 of length 𝑛
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output one line containing any permutation of length 𝑛
 (the permutation 𝑞
) such that 𝑞
 minimizes the number of pairs.

Example
InputCopy
3
2
1 2
5
1 2 3 4 5
7
4 7 5 1 2 6 3
OutputCopy
2 1
3 5 4 2 1
6 2 1 4 7 3 5
Note
For the first test, there exists only one pair (𝑖,𝑗
) (1≤𝑖≤𝑗≤𝑛
) such that 𝑝𝑖+𝑝𝑖+1+…+𝑝𝑗=𝑞𝑖+𝑞𝑖+1+…+𝑞𝑗
, which is (1,2
). It can be proven that no such 𝑞
 exists for which there are no pairs.


*/
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
    std::vector<long> v(n);
    for (long p = 1; p < n; ++p) {
      std::cin >> v[p];
    }
    std::cin >> v[0];
    for (long p = 0; p < n; ++p) {
      std::cout << v[p] << " ";
    }
    std::cout << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1998/325960351
