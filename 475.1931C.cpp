/*C. Make Equal Again
time limit per test2 seconds
memory limit per test256 megabytes
You have an array 𝑎
 of 𝑛
 integers.

You can no more than once apply the following operation: select three integers 𝑖
, 𝑗
, 𝑥
 (1≤𝑖≤𝑗≤𝑛
) and assign all elements of the array with indexes from 𝑖
 to 𝑗
 the value 𝑥
. The price of this operation depends on the selected indices and is equal to
(𝑗−𝑖+1) burles.

For example, the array is equal to [1,2,3,4,5,1]
. If we choose 𝑖=2,𝑗=4,𝑥=8
, then after applying this operation, the array will be equal to [1,8,8,8,5,1]
.

What is the least amount of burles you need to spend to make all the elements of
the array equal?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of input test case[48;52;178;1768;2848ts. The descriptions of
the test cases follow.

The first line of the description of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the size of the array.

The second line of the description of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
) — array elements.

It is guaranteed that the sum of 𝑛
 for all test cases does not exceed 2⋅105
.

Output
For each test case, output one integer — the minimum number of burles that will
have to be spent to make all the elements of the array equal. It can be shown
that this can always be done.

Example
InputCopy
8
6
1 2 3 4 5 1
7
1 1 1 1 1 1 1
8
8 8 8 1 2 8 8 8
1
1
2
1 2
3
1 2 3
7
4 3 2 7 1 1 3
9
9 9 2 9 2 5 5 5 3
OutputCopy
4
0
2
0
1
2
6
7
*/

#include <iostream>
#include <vector>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::vector<long> a(n);
    for (long p = 0; p < n; p++) {
      std::cin >> a[p];
    }
    long left = 1;
    while (left < n && a[left] == a[0]) {
      ++left;
    }
    long right = 1;
    while (right + 1 <= n && a[n - 1 - right] == a.back()) {
      ++right;
    }

    long s = (left > right ? left : right);
    if (a[0] == a.back()) {
      s = left + right;
    }
    s = (s < n ? s : n);
    std::cout << (n - s) << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/1931/327531028
