/*E. Skibidus and Rizz
time limit per test1.5 seconds
memory limit per test256 megabytes
With the approach of Valentine's Day, Skibidus desperately needs a way to rizz
up his crush! Fortunately, he knows of just the way: creating the perfect Binary
String!

Given a binary string∗
 𝑡
, let 𝑥
 represent the number of 𝟶
 in 𝑡
 and 𝑦
 represent the number of 𝟷
 in 𝑡
. Its balance-value is defined as the value of max(𝑥−𝑦,𝑦−𝑥)
.

Skibidus gives you three integers 𝑛
, 𝑚
, and 𝑘
. He asks for your help to construct a binary string 𝑠
 of length 𝑛+𝑚
 with exactly 𝑛
 𝟶
's and 𝑚
 𝟷
's such that the maximum balance-value among all of its substrings†
 is exactly 𝑘
. If it is not possible, output -1.

∗
A binary string only consists of characters 𝟶
 and 𝟷
.

†
A string 𝑎
 is a substring of a string 𝑏
 if 𝑎
 can be obtained from 𝑏
 by the deletion of several (possibly, zero or all) characters from the
beginning and several (possibly, zero or all) characters from the end.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first and only line of each test case contains three integers 𝑛
, 𝑚
, and 𝑘
 (0≤𝑛,𝑚≤2⋅105
, 1≤𝑘≤𝑛+𝑚
, 𝑛+𝑚≥1
).

It is guaranteed that the sum of 𝑛
 and the sum of 𝑚
 over all test cases does not exceed 2⋅105
.

Output
For each test case, if it is possible to construct 𝑠
, output it on a new line. If there are multiple possible 𝑠
, output any. Otherwise, output -1 on a new line.

Example
InputCopy
6
1 2 1
4 3 2
2 4 3
8 3 2
5 0 4
5 0 5
OutputCopy
101
0100101
011011
-1
-1
00000
Note
In the first test case, we must construct 𝑠
 such that it contains one 𝟶
, two 𝟷
, and a maximum balance of 1
 among all of its substrings. One possible valid 𝑠
 is 𝟷𝟶𝟷
 because:

Consider the substring bounded by indices [1,1]
. Its balance-value is max(0−1,1−0)=1
.
Consider the substring bounded by indices [1,2]
. Its balance-value is max(1−1,1−1)=0
.
Consider the substring bounded by indices [1,3]
. Its balance-value is max(1−2,2−1)=1
.
Consider the substring bounded by indices [2,2]
. Its balance-value is max(1−0,0−1)=1
.
Consider the substring bounded by indices [2,3]
. Its balance-value is max(1−1,1−1)=0
.
Consider the substring bounded by indices [3,3]
. Its balance-value is max(0−1,1−0)=1
.
Among all possible substrings, the maximum balance-value is 1
.

In the second test case, the substring with the maximum balance-value is 0100
, which has a balance of 𝑚𝑎𝑥(3−1,1−3)=2
.
*/

/* 1. Swap n and m if n > m to ensure m ≥ n.
    - c[0] = the character for the smaller count, c[1] = the character for the
larger count.

2. Check if it is possible to create such a string:
    - if (m - n > k || m < k) return -1;
    - Explanation:
        - m - n > k → too many of one character, can't avoid consecutive limit.
        - m < k → can't start properly (not enough ones to place).

3. Construct the string by alternating blocks of k ones and k zeros until both
counts are exhausted.

4. Print the string.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long n, m, k;
  cin >> n >> m >> k;

  char zero = '0', one = '1';
  if (n > m) {
    swap(n, m);
    swap(zero, one);
  }

  if (m - n > k || m < k) {
    cout << -1 << "\n";
    return;
  }

  string res;
  while (n > 0 || m > 0) {
    // Place up to k of the larger count
    long long t = min(k, m);
    res += string(t, one);
    m -= t;

    // Place up to k of the smaller count
    t = min(k, n);
    res += string(t, zero);
    n -= t;
  }

  cout << res << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2065/335538245
