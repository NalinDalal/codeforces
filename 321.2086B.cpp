/* B. Large Array and Segments
time limit per test2 seconds
memory limit per test512 megabytes
There is an array 𝑎
 consisting of 𝑛
 positive integers, and a positive integer 𝑘
. An array 𝑏
 is created from array 𝑎
 according to the following rules:

𝑏
 contains 𝑛⋅𝑘
 numbers;
the first 𝑛
 numbers of array 𝑏
 are the same as the numbers of array 𝑎
, that is, 𝑏𝑖=𝑎𝑖
 for 𝑖≤𝑛
;
for any 𝑖>𝑛
, it holds that 𝑏𝑖=𝑏𝑖−𝑛
.
For example, if 𝑎=[2,3,1,4]
 and 𝑘=3
, then 𝑏=[2,3,1,4,2,3,1,4,2,3,1,4]
.

Given a number 𝑥
, it is required to count the number of such positions 𝑙
 (1≤𝑙≤𝑛⋅𝑘
), for which there exists a position 𝑟≥𝑙
, such that the sum of the elements of array 𝑏
 on the segment [𝑙,𝑟]
 is at least 𝑥
 (in other words, 𝑏𝑙+𝑏𝑙+1+⋯+𝑏𝑟≥𝑥
).

Input
Each test consists of several test cases. The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains three integers 𝑛
, 𝑘
, 𝑥
 (1≤𝑛,𝑘≤105
; 1≤𝑥≤1018
).

The second line of each test case contains 𝑛
 integers 𝑎𝑖
 (1≤𝑎𝑖≤108
).

Additional constraints on the input:

the sum of 𝑛
 across all test cases does not exceed 2⋅105
;
the sum of 𝑘
 across all test cases does not exceed 2⋅105
.
Output
For each test case, output one integer — the number of suitable positions 𝑙
 in the array 𝑏
.

Example
InputCopy
7
5 3 10
3 4 2 1 5
15 97623 1300111
105 95 108 111 118 101 95 118 97 108 111 114 97 110 116
1 100000 1234567891011
1
1 1 1
1
1 1 1
2
2 1 2
1 1
2 1 5
2 1
OutputCopy
12
1452188
0
1
1
1
0
Note
In the first test case, the array 𝑏
 looks like this:

[3,4,2,1,5,3,4,2,1,5,3,4,2,1,5]

There are 12
 positions 𝑙
 for which there exists a suitable position 𝑟
. Here are some (not all) of them:

𝑙=1
, for which there is a position 𝑟=6
, the sum over the segment [1,6]
 equals 18
;
𝑙=2
, for which there is a position 𝑟=5
, the sum over the segment [2,5]
 equals 12
;
𝑙=6
, for which there is a position 𝑟=9
, the sum over the segment [6,9]
 equals 10
.

*/

/*#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s += a[i];
    }

    vector<int> b(n * k);
    for (int i = 0; i <= n; i++) {
      b[i] = a[i];
    }
    // it feels from example that copy over array n into array b k times
    int i = n + 1;
    while (i > n && i <= n * k - 1) {
      b[i] = b[i - n];
      i++;
    }

    // now find [l,r] such that b[l]+b[l+1]+b[l+2]+...+b[r]>=x
    // output no of suitable positions l
    int l = 0, r = n * k - 1;
    while (l < r) {
      int mid = (l + r) / 2;

      l++;
      r--;
    }
  }
  return 0;
}*/
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    ll s = 0;
    for (ll p = 0; p < n; p++) {
      cin >> a[p];
      s += a[p];
    }

    ll cnt = n * k;
    cnt -= (x / s) * n;
    x %= s;
    cnt += (!x);
    for (ll p = n - 1; x > 0 && cnt > 0 && p >= 0; p--) {
      x -= a[p];
      if (x <= 0)
        break;
      --cnt;
    }

    cnt = max(cnt, 0LL);
    cout << cnt << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2086/318068401
