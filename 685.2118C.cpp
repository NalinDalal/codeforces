/*C. Make It Beautiful
time limit per test2 seconds
memory limit per test512 megabytes
You are given an array 𝑎
 of 𝑛
 integers. We define the beauty
 of a number 𝑥
 to be the number of 1
 bits in its binary representation. We define the beauty of an array to be the
sum of beauties of the numbers it contains.

In one operation, you can select an index 𝑖
 (1≤𝑖≤𝑛)
 and increase 𝑎𝑖
 by 1
.

Find the maximum beauty of the array after doing at most 𝑘
 operations.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤5000
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤5000
, 0≤𝑘≤1018
) — the length of the array and the maximal number of operations.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…𝑎𝑛
 (0≤𝑎𝑖≤109
) —denoting the array 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 5000
.

Output
For each test case, output a single integer, the maximum beauty after at most 𝑘
 operations.

Example
InputCopy
5
5 2
0 1 7 2 4
5 3
0 1 7 2 4
1 1
3
3 0
2 0 3
1 100000000000
0
OutputCopy
8
9
2
3
36
Note
In the first test case, 𝑎=[0,1,7,2,4]
.

apply the first operation at 𝑖=1
, the new array is 𝑎=[1,1,7,2,4]
apply the second operation at 𝑖=4
, the new array is 𝑎=[1,1,7,3,4]
The beauty of this array is 1+1+3+2+1=8
. One of the other valid solutions with the same beauty is [0,1,7,3,5]
.
In the third test case, 𝑎=[3]
. Since you are not required to use exactly 𝑘
 operations, it is optimal to do none.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const ll B = 63;

  ll t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    ll zv[B] = {0};

    ll beauty = 0;
    for (ll i = 0; i < n; i++) {
      ll x;
      cin >> x;
      for (ll p = 0; p < B; p++) {
        if (x % 2) {
          ++beauty;
        } else {
          ++zv[p];
        }
        x /= 2;
      }
    }

    for (ll p = 0; p < B; p++) {
      ll add = (1LL << p); // CAUTION: must use 1LL to avoid overflow
      ll need = k / add;
      need = (need < zv[p] ? need : zv[p]);
      beauty += need;
      k -= need * add;
      // cerr << "p:" << p << " zvp:" << zv[p] << " add:" << add
      //      << " need:" << need << " beauty:" << beauty << " k:" << k << "\n";
    }

    cout << beauty << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2118/338553399
