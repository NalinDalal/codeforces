/*B. Binary Path
time limit per test1 second
memory limit per test256 megabytes
You are given a 2×𝑛
 grid filled with zeros and ones. Let the number at the intersection of the 𝑖
-th row and the 𝑗
-th column be 𝑎𝑖𝑗
.

There is a grasshopper at the top-left cell (1,1)
 that can only jump one cell right or downwards. It wants to reach the
bottom-right cell (2,𝑛) . Consider the binary string of length 𝑛+1 consisting of
numbers written in cells of the path without changing their order.

Your goal is to:

Find the lexicographically smallest†
 string you can attain by choosing any available path;
Find the number of paths that yield this lexicographically smallest string.
†
 If two strings 𝑠
 and 𝑡
 have the same length, then 𝑠
 is lexicographically smaller than 𝑡
 if and only if in the first position where 𝑠
 and 𝑡
 differ, the string 𝑠
 has a smaller element than the corresponding element in 𝑡
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤2⋅105
).

The second line of each test case contains a binary string 𝑎11𝑎12…𝑎1𝑛
 (𝑎1𝑖
 is either 0
 or 1
).

The third line of each test case contains a binary string 𝑎21𝑎22…𝑎2𝑛
 (𝑎2𝑖
 is either 0
 or 1
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output two lines:

The lexicographically smallest string you can attain by choosing any available
path; The number of paths that yield this string. Example InputCopy
3
2
00
00
4
1101
1100
8
00100111
11101101
OutputCopy
000
2
11000
1
001001101
4
Note
In the first test case, the lexicographically smallest string is 𝟶𝟶𝟶
. There are two paths that yield this string:


In the second test case, the lexicographically smallest string is 𝟷𝟷𝟶𝟶𝟶
. There is only one path that yields this string:

*/

#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    long idx(0), cnt(1), down(n - 1);
    while (idx < n) {
      if (b[idx] < a[idx + 1]) {
        cnt = 1;
        down = idx;
        break;
      } else if (b[idx] == a[idx + 1]) {
        down = idx;
        while ((idx + 1 < n) && b[idx] == a[idx + 1]) {
          ++idx;
          ++cnt;
        }
        if ((idx == n - 1) || b[idx] < a[idx + 1]) {
          break;
        } else {
          down = n - 1;
          cnt = 1;
        }
      }
      ++idx;
    }

    std::string mn = a.substr(0, down + 1) + b.substr(down);
    std::cout << mn << "\n" << cnt << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1937/340287021
