/*A. Maximize the Last Element
time limit per test1 second
memory limit per test256 megabytes
You are given an array 𝑎
 of 𝑛
 integers, where 𝑛
 is odd.

In one operation, you will remove two adjacent elements from the array 𝑎
, and then concatenate the remaining parts of the array. For example, given the
array [4,7,4,2,9] , we can obtain the arrays [4,2,9] and [4,7,9] by the
operations [4,7⎯⎯⎯⎯⎯⎯,4,2,9]→[4,2,9] and [4,7,4,2⎯⎯⎯⎯⎯⎯,9]→[4,7,9] respectively.
However, we cannot obtain the array [7,2,9] as it requires deleting non-adjacent
elements [4⎯⎯,7,4⎯⎯,2,9]
.

You will repeatedly perform this operation until exactly one element remains in
𝑎
.

Find the maximum possible value of the remaining element in 𝑎
.

Input
Each test contains multiple test cases. The first line contains a single integer
𝑡 (1≤𝑡≤1000 ) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤99
; 𝑛
 is odd) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤100
) — the elements of the array 𝑎
.

Note that there is no bound on the sum of 𝑛
 over all test cases.

Output
For each test case, output a single integer — the maximum possible value of the
remaining element in 𝑎
.

Example
InputCopy
4
1
6
3
1 3 2
5
4 7 4 2 9
7
3 1 4 1 5 9 2
OutputCopy
6
2
9
5
Note
In the first test case, the array 𝑎
 is [6]
. Since there is only one element, no operations are needed. The maximum
possible value of the remaining element is 6
.

In the second test case, the array 𝑎
 is [1,3,2]
. We can remove the first two elements [1,3⎯⎯⎯⎯⎯⎯,2]→[2]
, or remove the last two elements [1,3,2⎯⎯⎯⎯⎯⎯]→[1]
. Therefore, the maximum possible value of the remaining element is 2
.

In the third test case, the array 𝑎
 is [4,7,4,2,9]
. One way to maximize the remaining element is
[4,7,4⎯⎯⎯⎯⎯⎯,2,9]→[4,2⎯⎯⎯⎯⎯⎯,9]→[9] . Therefore, the maximum possible value of
the remaining element is 9
.

In the fourth test case, the array 𝑎
 is [3,1,4,1,5,9,2]
. It can be shown that the maximum possible value of the remaining element is 5
.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

void solve() {
  ll n;
  cin >> n;
  ll maxi = 0;
  vector<ll> v(n);
  for (auto &it : v)
    cin >> it;
  if (n == 1) {
    cout << v[0] << endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      maxi = max(maxi, v[i]);
    }
  }
  cout << maxi << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1991/329954151
