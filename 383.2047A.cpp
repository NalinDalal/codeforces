/* A. Alyona and a Square Jigsaw Puzzle
time limit per test1 second
memory limit per test256 megabytes
Alyona assembles an unusual square Jigsaw Puzzle. She does so in 𝑛
 days in the following manner:

On the first day, she starts by placing the central piece in the center of the
table. On each day after the first one, she places a certain number of pieces
around the central piece in clockwise order, always finishing each square layer
completely before starting a new one. For example, she places the first 14
 pieces in the following order:

The colors denote the layers. The third layer is still unfinished.
Alyona is happy if at the end of the day the assembled part of the puzzle does
not have any started but unfinished layers. Given the number of pieces she
assembles on each day, find the number of days Alyona is happy on.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

The first line contains a single integer 𝑛
 (1≤𝑛≤100
), the number of days.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤100
, 𝑎1=1
), where 𝑎𝑖
 is the number of pieces Alyona assembles on the 𝑖
-th day.

It is guaranteed in each test case that at the end of the 𝑛
 days, there are no unfinished layers.

Output
For each test case, print a single integer: the number of days when Alyona is
happy.

Example
InputCopy
5
1
1
2
1 8
5
1 3 2 1 2
7
1 2 1 10 2 7 2
14
1 10 10 100 1 1 10 1 10 2 10 2 10 1
OutputCopy
1
2
2
2
3
Note
In the first test case, in the only day Alyona finishes the only layer.

In the second test case, on the first day, Alyona finishes the first layer, and
on the second day, she finishes the second layer.

In the third test case, she finishes the second layer in a few days.

In the fourth test case, she finishes the second layer and immediately starts
the next one on the same day, therefore, she is not happy on that day. She is
only happy on the first and last days.

In the fifth test case, Alyona is happy on the first, fourth, and last days.


*/

#include <iostream>
#include <set>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::set<long> s;
  for (long p = 1; p <= 107; p += 2) {
    s.insert(p * p);
  }

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    long cnt = 0, cs = 0;
    for (long p = 0; p < n; ++p) {
      long x;
      std::cin >> x;
      cs += x;
      cnt += s.count(cs);
    }
    std::cout << cnt << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2047/322398649
