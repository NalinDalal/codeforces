/* C. Combination Lock
time limit per test2 seconds
memory limit per test256 megabytes
At the IT Campus "NEIMARK", there are several top-secret rooms where problems
for major programming competitions are developed. To enter one of these rooms,
you must unlock a circular lock by selecting the correct code. This code is
updated every day.

Today's code is a permutation∗
 of the numbers from 1
 to 𝑛
, with the property that in every cyclic shift†
 of it, there is exactly one fixed point. That is, in every cyclic shift, there
exists exactly one element whose value is equal to its position in the
permutation.

Output any valid permutation that satisfies this condition. Keep in mind that a
valid permutation might not exist, then output −1
.

∗
A permutation is defined as a sequence of length 𝑛
 consisting of integers from 1
 to 𝑛
, where each number appears exactly once. For example, (2 1 3), (1), (4 3 1 2)
are permutations; (1 2 2), (3), (1 3 2 5) are not.

†
A cyclic shift of an array is obtained by moving the last element to the
beginning of the array. A permutation of length 𝑛 has exactly 𝑛 cyclic shifts.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

A single line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the desired permutation. If multiple solutions exist,
output any one of them. If no suitable permutations exist, output −1
.

Example
InputCopy
3
4
5
3
OutputCopy
-1
4 1 3 5 2
1 3 2
Note
In the second example, there is a permutation such that in each cyclic shift
there is a fixed point (highlighted in dark red):


The first line contains the element numbers, and the second line contains all
the shifts of the desired permutation.*/

#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n;
    std::cin >> n;

    if (n % 2 == 0) {
      std::cout << -1 << std::endl;
      continue;
    }
    for (long p = 1; p <= n; p += 2) {
      std::cout << p << std::endl;
    }

    for (long p = 2; p <= n; p += 2) {
      std::cout << p << std::endl;
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2091/314950388
