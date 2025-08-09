/*B. Minimise Sum
time limit per test1.5 seconds
memory limit per test256 megabytes
This problem differs from problem G. In this problem, you must output the
minimum sum of prefix minimums after at most one operation.

You are given an array 𝑎
 of length 𝑛
, with elements satisfying 0≤𝒂𝒊≤𝒏
. You can perform the following operation at most once:

Choose two indices 𝑖
 and 𝑗
 such that 𝑖<𝑗
. Set 𝑎𝑖:=𝑎𝑖+𝑎𝑗
. Then, set 𝑎𝑗=0
.
Output the minimum possible value of min(𝑎1)+min(𝑎1,𝑎2)+…+min(𝑎1,𝑎2,…,𝑎𝑛)
 that you can get.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (2≤𝑛≤2⋅105
) — the length of 𝑎
.

The following line contains 𝑛
 space-separated integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤𝑛
) — denoting the array 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output an integer on a new line, the minimum possible value
of min(𝑎1)+min(𝑎1,𝑎2)+…+min(𝑎1,𝑎2,…,𝑎𝑛)
.

Example
InputCopy
3
2
1 2
3
1 2 3
4
3 0 2 3
OutputCopy
2
2
3
Note
In the second test case, it is optimal to perform the operation with 𝑖=2
 and 𝑗=3
.

In the third test case, it is optimal to not perform any operations. The answer
is 3
.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    long x = -1, y = -1;
    cin >> x >> y;
    for (long p = 2; p < n; p++) {
      long z;
      cin >> z;
    }
    cout << x + min(x, y) << "\n";
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/2124/333086804
