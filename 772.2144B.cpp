/*B. Maximum Cost Permutation
time limit per test2 seconds
memory limit per test256 megabytes
Recall that a permutation of length 𝑛
 is a sequence of length 𝑛
 such that each integer from 1
 to 𝑛
 appears in it exactly once.

Let's define the cost of a permutation as the minimum length of its contiguous
subsegment (possibly empty) that needs to be sorted so that the entire
permutation becomes sorted in ascending order.

You are given an integer array 𝑝
 consisting of integers from 0
 to 𝑛
, where no positive (strictly greater than zero) integer appears more than once.
You should replace zeros with integers so that the array 𝑝 becomes a
permutation.

Your task is to calculate the maximum possible cost of the resulting
permutation.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
).

The second line contains 𝑛
 integers 𝑝1,𝑝2,…,𝑝𝑛
 (0≤𝑝𝑖≤𝑛
). No positive integer appears more than once in this sequence.

Additional constraint on the input: the sum of 𝑛
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case, print a single integer — the maximum possible cost of the
resulting permutation.

Example
InputCopy
4
5
1 0 4 0 5
3
0 0 0
4
1 2 3 0
3
0 3 2
OutputCopy
3
3
0
2
Note
In the first example, you can make a permutation [1,3,4,2,5]
 with the cost 3
, because you have to sort segment [2,4]
.

In the second example, you can make a permutation [2,3,1]
 with the cost 3
, because you have to sort segment [1,3]
.

In the third example, there is only one possible permutation — [1,2,3,4]
, with the cost 0
, because the permutation is already sorted.

In the fourth example, there is only one possible permutation — [1,3,2]
, with the cost 2
, because you have to sort segment [2,3]
.
*/

#include <iostream>
#include <set>
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
    std::set<long> s;
    for (long p = 0; p < n; ++p) {
      std::cin >> v[p];
      s.insert(p + 1);
    }

    for (long p = 0; p < n; ++p) {
      if (v[p])
        s.erase(v[p]);
    }

    for (long p = n - 1; p >= 0; --p) {
      if (!v[p]) {
        v[p] = *s.begin();
        s.erase(s.begin());
      }
    }

    long left = n, right = -1;
    for (long p = 0; p < n; ++p) {
      if (v[p] != p + 1) {
        left = p;
        break;
      }
    }

    for (long p = n - 1; p >= 0; --p) {
      if (v[p] != p + 1) {
        right = p;
        break;
      }
    }

    std::cout << ((left < right) ? (right - left + 1) : 0) << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2144/343891225
