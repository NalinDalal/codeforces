/*A. Recycling Center
time limit per test1 second
memory limit per test256 megabytes
In the recycling center, there are 𝑛
 trash bags, the 𝑖
-th bag has a weight of 𝑎𝑖
. At each second, two actions will happen successively:

First, you must choose a trash bag and destroy it. It will cost 1
 coin if the weight of the trash bag is strictly greater than 𝑐
, and it will cost 0
 coins otherwise.
Then, the weight of each remaining trash bag will get multiplied by two.
What is the minimum number of coins you have to spend to get rid of all trash
bags? Input Each test contains multiple test cases. The first line contains the
number of test cases 𝑡 (1≤𝑡≤1000
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑐
 (1≤𝑛≤30
, 1≤𝑐≤109)
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the weight of each trash bag.

Output
For each test case, you must output a single integer — the minimum number of
coins you have to spend to destroy all trash bags.

Example
InputCopy
4
5 10
10 4 15 1 8
3 42
1000000000 1000000000 1000000000
10 30
29 25 2 12 15 42 14 6 16 9
10 1000000
1 1 1 1 1 1 1 1 1 864026633
OutputCopy
2
3
6
1
Note
In the following explanation:

Numbers in blue represent trash bags that have been destroyed for free,
Numbers in red represent trash bags that have been destroyed for 1
 coin,
Numbers in black represent trash bags that have not been destroyed yet.
In the first test case, one solution is:

[10,4,15,1,8]
[10,8,30,2,16]
, 10
 is destroyed for free because 10≤10
.
[10,8,60,4,32]
, 8
 is destroyed for free because 8≤10
.
[10,8,120,8,32]
, 32
 is destroyed for 1
 coin because 32>10
.
[10,8,240,8,32]
, 8
 is destroyed for free because 8≤10
.
[10,8,240,8,32]
, 240
 is destroyed for 1
 coin because 240>10
.
In total, you paid 2
 coins, and we can prove it is optimal.

In the second test case, one solution is:

[1000000000,1000000000,1000000000]
[1000000000,2000000000,2000000000]
, 1000000000
 is destroyed for 1
 coin because 1000000000>42
.
[1000000000,2000000000,4000000000]
, 2000000000
 is destroyed for 1
 coin because 2000000000>42
.
[1000000000,2000000000,4000000000]
, 4000000000
 is destroyed for 1
 coin because 4000000000>42
.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, c;
    cin >> n >> c;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    int ans = 0;
    // choose a bg, if it's wt >c then cost+=1
    // else cost+=0
    // then multiply whole vector by 2
    sort(v.rbegin(), v.rend());
    int mult = 1;
    for (int i = 0; i < n; i++) {
      if (mult * v[i] > c) {
        ++ans;
      } else {
        mult *= 2;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2128/337091051
