/*C. Limited Repainting
time limit per test2 seconds
memory limit per test512 megabytes
You are given a strip, consisting of 𝑛
 cells, all cells are initially colored red.

In one operation, you can choose a segment of consecutive cells and paint them
blue. Before painting, the chosen cells can be either red or blue. Note that it
is not possible to paint them red. You are allowed to perform at most 𝑘
 operations (possibly zero).

For each cell, the desired color after all operations is specified: red or blue.

It is clear that it is not always possible to satisfy all requirements within 𝑘
 operations. Therefore, for each cell, a penalty is also specified, which is
applied if the cell ends up the wrong color after all operations. For the 𝑖 -th
cell, the penalty is equal to 𝑎𝑖
.

The penalty of the final painting is calculated as the maximum penalty among all
cells that are painted the wrong color. If there are no such cells, the painting
penalty is equal to 0
.

What is the minimum penalty of the final painting that can be achieved?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤3⋅105
; 0≤𝑘≤𝑛
) — the length of the strip and the maximum number of operations.

The second line contains a string 𝑠
, consisting of 𝑛
 characters 'R' and/or 'B'. 'R' means that the cell should be painted red. 'B'
means that the cell should be painted blue.

The third line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the penalty for each cell.

The sum of 𝑛
 over all test cases does not exceed 3⋅105
.

Output
For each test case, print a single integer — the minimum penalty of the final
painting.

Example
InputCopy
5
4 1
BRBR
9 3 5 4
4 1
BRBR
9 5 3 4
4 2
BRBR
9 3 5 4
10 2
BRBRBBRRBR
5 1 2 4 5 3 6 1 5 4
5 5
RRRRR
5 3 1 2 4
OutputCopy
3
3
0
4
0
Note
In the first test case, you can paint the cells from 1
 to 3
. The painting will be BBBR. So, only cell 2
 is painted the wrong color. Therefore, the penalty for it is the final penalty
and equals 3
.

In the second test case, the painting BBBR will now result in a penalty of 5
. However, if you paint the cells from 1
 to 1
, resulting in BRRR, then only cell 3
 is painted the wrong color. The final penalty is 3
.

In the third test case, you can paint the cells from 1
 to 1
 and from 3
 to 3
. Then all cells will be the correct color, the penalty equals 0
.
*/

/*(t--){
 n,k;
 vector<int>v(n)

 binary search on penalty
 ignore all cells with penalty < P

For cells with s[i] == 'B' that matter (ai ≥ P): If we are not already painting,
start a new operation → count++.

For cells with s[i] == 'R' that matter: If we are painting, end the segment.
  }
*/

#include <iostream>
#include <vector>

bool check(const std::vector<long> &w, const std::string &s, long k,
           long penalty) {

  bool paint(false);
  long cnt(0);
  for (long p = 0; p < w.size(); p++) {
    if (w[p] < penalty) {
      continue;
    }
    if (s[p] == 'B' && !paint) {
      paint = true;
      ++cnt;
    }
    if (s[p] == 'R' && paint) {
      paint = false;
    }
    if (cnt > k) {
      return false;
    }
  }

  return true;
}

int main() {

  std::ios_base::sync_with_stdio(false);

  long t;
  std::cin >> t;
  while (t--) {
    long n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    std::vector<long> v(n);
    for (long p = 0; p < n; p++) {
      std::cin >> v[p];
    }

    long left(0), right(1e9 + 7), res(0);
    while (left <= right) {
      long mid = (left + right) / 2;
      if (check(v, s, k, mid)) {
        right = mid - 1;
      } else {
        res = mid;
        left = mid + 1;
      }
    }

    std::cout << res << std::endl;
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2070/339324065
