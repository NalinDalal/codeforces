/*D. Find the Different Ones!
time limit per test5 seconds
memory limit per test256 megabytes
You are given an array 𝑎
 of 𝑛
 integers, and 𝑞
 queries.

Each query is represented by two integers 𝑙
 and 𝑟
 (1≤𝑙≤𝑟≤𝑛
). Your task is to find, for each query, two indices 𝑖
 and 𝑗
 (or determine that they do not exist) such that:

𝑙≤𝑖≤𝑟
;
𝑙≤𝑗≤𝑟
;
𝑎𝑖≠𝑎𝑗
.
In other words, for each query, you need to find a pair of different elements
among 𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟 , or report that such a pair does not exist.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The descriptions of the test cases follow.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤2⋅105
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤106
) — the elements of the array 𝑎
.

The third line of each test case contains a single integer 𝑞
 (1≤𝑞≤2⋅105
) — the number of queries.

The next 𝑞
 lines contain two integers each, 𝑙
 and 𝑟
 (1≤𝑙<𝑟≤𝑛
) — the boundaries of the query.

It is guaranteed that the sum of the values of 𝑛
 across all test cases does not exceed 2⋅105
. Similarly, it is guaranteed that the sum of the values of 𝑞
 across all test cases does not exceed 2⋅105
.

Output
For each query, output two integers separated by space: 𝑖
 and 𝑗
 (𝑙≤𝑖,𝑗≤𝑟
), for which 𝑎𝑖≠𝑎𝑗
. If such a pair does not exist, output 𝑖=−1
 and 𝑗=−1
.

You may separate the outputs for the test cases with empty lines. This is not a
mandatory requirement.

Example
InputCopy
5
5
1 1 2 1 1
3
1 5
1 2
1 3
6
30 20 20 10 10 20
5
1 2
2 3
2 4
2 6
3 5
4
5 2 3 4
4
1 2
1 4
2 3
2 4
5
1 4 3 2 4
5
1 5
2 4
3 4
3 5
4 5
5
2 3 1 4 2
7
1 2
1 4
1 5
2 4
2 5
3 5
4 5
OutputCopy
2 3
-1 -1
1 3

2 1
-1 -1
4 2
4 6
5 3

1 2
1 2
2 3
3 2

1 3
2 4
3 4
5 3
5 4

1 2
4 2
1 3
2 3
3 2
5 4
5 4
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
    std::vector<long> v(n + 1, 0);

    long prev = 0;
    for (long p = 1; p <= n; p++) {
      long x;
      std::cin >> x;
      if (x != prev) {
        v[p] = p - 1;
      } else {
        v[p] = v[p - 1];
      }
      prev = x;
    }

    long q;
    std::cin >> q;
    while (q--) {
      long l, r;
      std::cin >> l >> r;
      if (v[r] < l) {
        std::cout << "-1 -1\n";
      } else {
        std::cout << v[r] << " " << r << "\n";
      }
    }
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1927/340687580
