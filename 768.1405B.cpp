/*B. Array Cancellation
time limit per test1 second
memory limit per test256 megabytes
You're given an array 𝑎
 of 𝑛
 integers, such that 𝑎1+𝑎2+⋯+𝑎𝑛=0
.

In one operation, you can choose two different indices 𝑖
 and 𝑗
 (1≤𝑖,𝑗≤𝑛
), decrement 𝑎𝑖
 by one and increment 𝑎𝑗
 by one. If 𝑖<𝑗
 this operation is free, otherwise it costs one coin.

How many coins do you have to spend in order to make all elements equal to 0
?

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤5000
). Description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤105
)  — the number of elements.

The next line contains 𝑛
 integers 𝑎1,…,𝑎𝑛
 (−109≤𝑎𝑖≤109
). It is given that ∑𝑛𝑖=1𝑎𝑖=0
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, print the minimum number of coins we have to spend in order
to make all elements equal to 0
.

Example
InputCopy
7
4
-3 5 -3 1
2
1 -1
4
-3 2 -3 4
4
-1 1 1 -1
7
-5 7 -6 -4 17 -13 4
6
-1000000000 -1000000000 -1000000000 1000000000 1000000000 1000000000
1
0
OutputCopy
3
0
4
1
8
3000000000
0
Note
Possible strategy for the first test case:

Do (𝑖=2,𝑗=3)
 three times (free), 𝑎=[−3,2,0,1]
.
Do (𝑖=2,𝑗=1)
 two times (pay two coins), 𝑎=[−1,0,0,1]
.
Do (𝑖=4,𝑗=1)
 one time (pay one coin), 𝑎=[0,0,0,0].
*/

#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll avail = 0, cnt = 0;

    for (ll p = 0; p < n; p++) {
      ll x;
      cin >> x;

      if (x > 0) {
        avail += x;
      } else if (x < 0) {
        if (x + avail > 0) {
          avail += x;
        } else {
          x += avail;
          cnt -= x;
          avail = 0;
        }
      }
    }

    cout << cnt << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1405/343494120
