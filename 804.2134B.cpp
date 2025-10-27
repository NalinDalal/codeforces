/*B. Add 0 or K
time limit per test1.5 seconds
memory limit per test256 megabytes

You are given an array of 𝑛
 positive integers 𝑎1,𝑎2,…,𝑎𝑛
 and a positive integer 𝑘
.

In one operation, you may add either 0
 or 𝑘
 to each 𝑎𝑖
, i.e., choose another array of 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 where each 𝑏𝑖
 is either 0
 or 𝑘
, and update 𝑎𝑖
 to 𝑎𝑖+𝑏𝑖
 for 1≤𝑖≤𝑛
. Note that you can choose different values for each element of the array 𝑏
.

Your task is to perform at most 𝑘
 such operations to make gcd(𝑎1,𝑎2,…,𝑎𝑛)>1
 ∗
. It can be proved that this is always possible.

Output the final array after the operations. You do not have to output the
operations themselves.

∗
gcd(𝑎1,𝑎2,…,𝑎𝑛)
 denotes the greatest common divisor (GCD) of 𝑎1,𝑎2,…,𝑎𝑛
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤1000
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤105
, 1≤𝑘≤109
) — the length of the array 𝑎
 and the given constant.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the elements of the array 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output an array of 𝑛
 integers in a new line — the final array after the operations. The integers in
the output should be within the range from 1 to 109+𝑘2
.

If there are multiple valid outputs, you can output any of them.

Note that you do not have to minimize the number of operations.

Example
InputCopy
8
3 3
2 7 1
4 5
2 9 16 14
4 1
1 2 3 4
5 2
5 6 7 8 9
2 10
7 9
1 1000000000
1
1 371
1000000000
3 6
1 3 5
OutputCopy
8 10 10
7 14 21 14
2 2 4 4
9 6 9 12 9
77 99
1000000000000000001
1000000000
25 15 5
Note
In the first test case, the output [8,10,10]
 is valid because gcd(8,10,10)=2>1
, and the array [2,7,1]
 can be transformed into [8,10,10]
 using at most 3
 operations. One possible sequence of operations is shown below:

Operation	𝑏
Resulting 𝑎
1
[3,0,3]
[5,7,4]
2
[0,0,3]
[5,7,7]
3
[3,3,3]
[8,10,10]
Other outputs like [2,10,4]
, [8,16,4]
, and [5,10,10]
 are also considered valid.

In the second test case, the output [7,14,21,14]
 is valid because:

gcd(7,14,21,14)=7>1
.
Starting from [2,9,16,14]
, applying the operation with 𝑏=[5,5,5,0]
 yields [7,14,21,14]
, requiring no more than 5
 operations.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (ll p = 0; p < n; p++) {
      cin >> a[p];
    }

    for (ll p = 0; p < n; p++) {
      a[p] += (a[p] % (k + 1)) * k;
    }

    for (ll p = 0; p < n; p++) {
      cout << a[p] << " ";
    }
    cout << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2134/346061752
