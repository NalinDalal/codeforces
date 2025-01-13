/* https://codeforces.com/problemset/problem/1831/A
* A. Twin Permutations
time limit per test1 second
memory limit per test256 megabytes
You are given a permutation† 𝑎 of length 𝑛.

Find any permutation of length 𝑛 such that 𝑎1+𝑏1≤𝑎2+𝑏2≤𝑎3+𝑏3≤…≤𝑎𝑛+𝑏𝑛.
It can be proven that a permutation 𝑏 that satisfies the condition above always
exists.

† A permutation of length 𝑛 is an array consisting of 𝑛 distinct integers from 1
to 𝑛 in arbitrary order. For example, [2,3,1,5,4] is a permutation, but
[1,2,2]is not a permutation (2 appears twice in the array), and [1,3,4] is also
not a permutation (𝑛=3 but there is 4 in the array).

Input
Each test contains multiple test cases. The first line of input contains a
single integer 𝑡 (1≤𝑡≤2000) — the number of test cases. The description of test
cases follows.

The first line of each test case contains a single integer 𝑛 (1≤𝑛≤100) — the
length of permutations 𝑎 and 𝑏.

The second line of each test case contains 𝑛 distinct integers 𝑎1,𝑎2,…,𝑎𝑛
(1≤𝑎𝑖≤𝑛) — the elements of permutation 𝑎. All elements of 𝑎 are distinct.

Note that there is no bound on the sum of 𝑛 over all test cases.

Output
For each test case, output any permutation 𝑏 which satisfies the constraints
mentioned in the statement. It can be proven that a permutation 𝑏 that satisfies
the condition above always exists.

Example
InputCopy
5
5
1 2 4 5 3
2
1 2
1
1
3
3 2 1
4
1 4 3 2
OutputCopy
1 2 4 3 5
2 1
1
1 2 3
1 2 3 4
Note
In the first test case 𝑎=[1,2,4,5,3]. Then the permutation 𝑏=[1,2,4,3,5]
satisfies the condition because 1+1≤2+2≤4+4≤5+3≤3+5.


*/

#include <iostream>

int main() {

  long t;

  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    for (long p = 0; p < n; p++) {
      long x;
      std::cin >> x;
      std::cout << n + 1 - x << " ";
    }
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1831/300855732
