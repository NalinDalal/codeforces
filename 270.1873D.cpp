/*D. 1D Eraser
time limit per test1 second
memory limit per test256 megabytes
You are given a strip of paper 𝑠
 that is 𝑛
 cells long. Each cell is either black or white. In an operation you can take
any 𝑘 consecutive cells and make them all white.

Find the minimum number of operations needed to remove all black cells.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑘≤𝑛≤2⋅105
) — the length of the paper and the integer used in the operation.

The second line of each test case contains a string 𝑠
 of length 𝑛
 consisting of characters 𝙱
 (representing a black cell) or 𝚆
 (representing a white cell).

The sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the minimum number of operations
needed to remove all black cells.

Example
InputCopy
8
6 3
WBWWWB
7 3
WWBWBWW
5 4
BWBWB
5 5
BBBBB
8 2
BWBWBBBB
10 2
WBBWBBWBBW
4 1
BBBB
3 2
WWW
OutputCopy
2
1
2
1
4
3
4
0
Note
In the first test case you can perform the following operations:
𝚆𝙱𝚆𝚆𝚆𝙱→𝚆𝚆𝚆𝚆𝚆𝙱→𝚆𝚆𝚆𝚆𝚆𝚆

In the second test case you can perform the following operations:
𝚆𝚆𝙱𝚆𝙱𝚆𝚆→𝚆𝚆𝚆𝚆𝚆𝚆𝚆

In the third test case you can perform the following operations:
𝙱𝚆𝙱𝚆𝙱→𝙱𝚆𝚆𝚆𝚆→𝚆𝚆𝚆𝚆𝚆



*/

#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    int cnt = 0, idx = 0;
    while (idx < s.size()) {
      if (s[idx] == 'B') {
        ++cnt;
        idx += k;
      } else {
        ++idx;
      }
    }

    std::cout << cnt << std::endl;
  }
}
// sub:https://codeforces.com/problemset/submission/1873/312678885
