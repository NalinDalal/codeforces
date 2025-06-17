/* B. Turtle and an Infinite Sequence
time limit per test1 second
memory limit per test256 megabytes
There is a sequence 𝑎0,𝑎1,𝑎2,…
 of infinite length. Initially 𝑎𝑖=𝑖
 for every non-negative integer 𝑖
.

After every second, each element of the sequence will simultaneously change. 𝑎𝑖
 will change to 𝑎𝑖−1∣𝑎𝑖∣𝑎𝑖+1
 for every positive integer 𝑖
. 𝑎0
 will change to 𝑎0∣𝑎1
. Here, |
 denotes bitwise OR.

Turtle is asked to find the value of 𝑎𝑛
 after 𝑚
 seconds. In particular, if 𝑚=0
, then he needs to find the initial value of 𝑎𝑛
. He is tired of calculating so many values, so please help him!

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛,𝑚
 (0≤𝑛,𝑚≤109
).

Output
For each test case, output a single integer — the value of 𝑎𝑛
 after 𝑚
 seconds.

Example
InputCopy
9
0 0
0 1
0 2
1 0
5 2
10 1
20 3
1145 14
19198 10
OutputCopy
0
1
3
1
7
11
23
1279
19455
Note
After 1
 second, [𝑎0,𝑎1,𝑎2,𝑎3,𝑎4,𝑎5]
 will become [1,3,3,7,7,7]
.

After 2
 seconds, [𝑎0,𝑎1,𝑎2,𝑎3,𝑎4,𝑎5]
 will become [3,3,7,7,7,7]
.


*/
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define mod (100001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    ll l = (0ll > n - m ? 0ll : n - m);
    ll r = m + n;
    if (l == r)
      cout << l << endl;
    for (int i = 30; i >= 0; i--) {
      if ((r >> i & 1) && !(l >> i & 1)) {
        cout << (l | (ll)pow(2ll, i + 1) - 1) << endl;
        break;
      }
    }
  }

  // find value of a[n] after m seconds
  // after each second a[i] change to a[i-1]|a[i]|a[i+1]
  // a[0] changes to a[0]|a[1]
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1981/324719016
