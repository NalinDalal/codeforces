/*B. Beautiful Array
time limit per test1 second
memory limit per test256 megabytes
Stanley defines the beauty of an array 𝑎
 of length 𝑛
, which contains non-negative integers, as follows:
∑𝑖=1𝑛⌊𝑎𝑖𝑘⌋,
which means that we divide each element by 𝑘
, round it down, and sum up the resulting values.

Stanley told Sam the integer 𝑘
 and asked him to find an array 𝑎
 of 𝑛
 non-negative integers, such that the beauty is equal to 𝑏
 and the sum of elements is equal to 𝑠
. Help Sam — find any of the arrays satisfying the conditions above.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤1000
). Description of the test cases follows.

The first line of each test case contains integers 𝑛
, 𝑘
, 𝑏
, 𝑠
 (1≤𝑛≤105
, 1≤𝑘≤109
, 0≤𝑏≤109
, 0≤𝑠≤1018
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case print −1
 if such array 𝑎
 does not exist. Otherwise print 𝑛
 non-negative integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤1018
) — the answer.

Example
InputCopy
8
1 6 3 100
3 6 3 12
3 6 3 19
5 4 7 38
5 4 7 80
99978 1000000000 100000000 1000000000000000000
1 1 0 0
4 1000000000 1000000000 1000000000000000000
OutputCopy
-1
-1
0 0 19
0 3 3 3 29
-1
-1
0
0 0 0 1000000000000000000
Note
In the first, the second, the fifth and the sixth test cases of the example it
is possible to show that such array does not exist.

In the third testcase of the example 𝑎=[0,0,19]
. The sum of elements in it is equal to 19, the beauty of it is equal to
(⌊06⌋+⌊06⌋+⌊196⌋)=(0+0+3)=3
.

In the fourth testcase of the example 𝑎=[0,3,3,3,29]
. The sum of elements in it is equal to 38
, the beauty of it is equal to (0+0+0+0+7)=7
*/

#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    ll n, k, b, s;
    cin >> n >> k >> b >> s;

    long mn = (s - (n - 1) * (k - 1)) / k;
    long mx = s / k;
    if (b < mn || mx < b) {
      cout << -1 << "\n";
      continue;
    }

    ll cur = b * k + k - 1;
    if (s < cur)
      cur = s;
    cout << cur << " ";

    ll rem = s - cur;
    for (long p = 1; p < n; p++) {
      cur = (rem < (k - 1)) ? rem : (k - 1);
      rem -= cur;
      cout << cur << " ";
    }
    cout << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1715/333483139
