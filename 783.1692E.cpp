/*E. Binary Deque
time limit per test2 seconds
memory limit per test256 megabytes
Slavic has an array of length 𝑛
 consisting only of zeroes and ones. In one operation, he removes either the
first or the last element of the array.

What is the minimum number of operations Slavic has to perform such that the
total sum of the array is equal to 𝑠 after performing all the operations? In
case the sum 𝑠 can't be obtained after any amount of operations, you should
output -1.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑠
 (1≤𝑛,𝑠≤2⋅105
) — the length of the array and the needed sum of elements.

The second line of each test case contains 𝑛
 integers 𝑎𝑖
 (0≤𝑎𝑖≤1
) — the elements of the array.

It is guaranteed that the sum of 𝑛
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case, output a single integer — the minimum amount of operations
required to have the total sum of the array equal to 𝑠 , or -1 if obtaining an
array with sum 𝑠 isn't possible.

Example
InputCopy
7
3 1
1 0 0
3 1
1 1 0
9 3
0 1 0 1 1 1 0 0 1
6 4
1 1 1 1 1 1
5 1
0 0 1 1 0
16 2
1 1 0 0 1 0 0 1 1 0 0 0 0 0 1 1
6 3
1 0 1 0 0 0
OutputCopy
0
1
3
2
2
7
-1
Note
In the first test case, the sum of the whole array is 1
 from the beginning, so we don't have to make any operations.

In the second test case, the sum of the array is 2
 and we want it to be equal to 1
, so we should remove the first element. The array turns into [1,0]
, which has a sum equal to 1
.

In the third test case, the sum of the array is 5
 and we need it to be 3
. We can obtain such a sum by removing the first two elements and the last
element, doing a total of three operations. The array turns into [0,1,1,1,0,0]
, which has a sum equal to 3
.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;

    int total = accumulate(a.begin(), a.end(), 0);
    if (total < s) {
      cout << -1 << "\n";
      continue;
    }
    if (total == s) {
      cout << 0 << "\n";
      continue;
    }

    int l = 0, sum = 0, max_len = 0;
    for (int r = 0; r < n; r++) {
      sum += a[r];
      while (sum > s) {
        sum -= a[l++];
      }
      if (sum == s) {
        max_len = max(max_len, r - l + 1);
      }
    }

    cout << (max_len == 0 ? -1 : n - max_len) << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1692/344622984
