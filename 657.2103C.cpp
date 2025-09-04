/*C. Median Splits
time limit per test2 seconds
memory limit per test256 megabytes

The median of an array 𝑏1,𝑏2,…𝑏𝑚
, written as med(𝑏1,𝑏2,…,𝑏𝑚)
, is the ⌈𝑚2⌉
-th∗
 smallest element of array 𝑏
.

You are given an array of integers 𝑎1,𝑎2,…,𝑎𝑛
 and an integer 𝑘
. You need to determine whether there exists a pair of indices 1≤𝑙<𝑟<𝑛
 such that:

med(med(𝑎1,𝑎2,…,𝑎𝑙),med(𝑎𝑙+1,𝑎𝑙+2,…,𝑎𝑟),med(𝑎𝑟+1,𝑎𝑟+2,…,𝑎𝑛))≤𝑘.

In other words, determine whether it is possible to split the array into three
contiguous subarrays† such that the median of the three subarray medians is less
than or equal to 𝑘
.

∗
⌈𝑥⌉
 is the ceiling function which returns the least integer greater than or equal
to 𝑥
.

†
An array 𝑥
 is a subarray of an array 𝑦
 if 𝑥
 can be obtained from 𝑦
 by the deletion of several (possibly, zero or all) elements from the beginning
and several (possibly, zero or all) elements from the end.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (3≤𝑛≤2⋅105
, 1≤𝑘≤109
) — the length of the array 𝑎
 and the constant 𝑘
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the elements of the array 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each testcase, output "YES" if such a split exists, and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
6
3 2
3 2 1
3 1
3 2 1
6 3
8 5 3 1 6 4
8 7
10 7 12 16 3 15 6 11
6 8
7 11 12 4 9 17
3 500000000
1000 1000000000 1000
OutputCopy
YES
NO
NO
YES
YES
YES
Note
In the first and second test case, the only possible partition of the array into
three contiguous subarrays is [3] , [2] , [1] . Their respective medians are 3
, 2
, and 1
. The median of the three subarray medians is med(3,2,1)=2
. Therefore, the answer for the first test case is "YES" since 2≤2
, while the answer for the second test case is "NO" since 2>1
.

In the third test case, it can be proven that no partition satisfies the
constraints.

In the fourth test case, one of the partitions satisfying the constraints is
[10,7] , [12,16,3,15] , [6,11] . The respective medians of subarrays are 7 , 12
, and 6
. The median of the three subarray medians is med(7,12,6)=7≤𝑘
, hence this partition satisfies the constraints.

In the fifth test case, one of the partitions satisfying the constraints is
[7,11] , [12,4] , [9,17] . The respective medians of the subarrays are 7 , 4 ,
and 9 . The median of the three subarray medians is med(7,4,9)=7≤𝑘 , hence this
partition satisfies the constraints.

In the sixth test case, the only possible partition of the array into three
contiguous subarrays is [1000] , [109] , [1000] . The respective medians of the
subarrays are 1000 , 109 , and 1000 . The median of the three subarray medians
is med(1000,109,1000)=1000≤𝑘 , hence this partition satisfies the constraints.
*/

/*We want to partition array a into 3 contiguous subarrays [1..l], [l+1..r],
[r+1..n]. Let their medians be m1, m2, m3. We check whether med(m1, m2, m3) ≤ k.

med(x,y,z) = the middle value among the three numbers.
So condition = at least two of {m1, m2, m3} ≤ k.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    auto find = [&](int start, int diff) {
      int cnt = 0;
      for (int i = start; i >= 0 && i < n; i += diff) {
        cnt += (a[i] <= k);
        cnt -= (a[i] > k);
        if (cnt >= 0)
          return i;
      }
      return diff == 1 ? n : -1;
    };

    auto first2 = [&]() {
      int l = find(0, 1);
      if (l % 2 == 0 && l + 1 < n && a[l + 1] > k)
        l++;
      int r = find(l + 1, 1);
      return r < n - 1;
    };

    auto last2 = [&]() {
      int r = find(n - 1, -1);
      if ((n - r) % 2 && r - 1 >= 0 && a[r - 1] > k)
        r--;
      int l = find(r - 1, -1);
      return l > 0;
    };

    auto outer2 = [&]() {
      int l = find(0, 1);
      int r = find(n - 1, -1);
      return r - l > 1;
    };

    cout << (first2() || last2() || outer2() ? "YES" : "NO") << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2103/336830557
