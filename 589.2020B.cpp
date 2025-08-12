/*B. Brightness Begins
time limit per test1 second
memory limit per test256 megabytes
Imagine you have 𝑛
 light bulbs numbered 1,2,…,𝑛
. Initially, all bulbs are on. To flip the state of a bulb means to turn it off
if it used to be on, and to turn it on otherwise.

Next, you do the following:

for each 𝑖=1,2,…,𝑛
, flip the state of all bulbs 𝑗
 such that 𝑗
 is divisible by 𝑖†
.
After performing all operations, there will be several bulbs that are still on.
Your goal is to make this number exactly 𝑘
.

Find the smallest suitable 𝑛
 such that after performing the operations there will be exactly 𝑘
 bulbs on. We can show that an answer always exists.

†
 An integer 𝑥
 is divisible by 𝑦
 if there exists an integer 𝑧
 such that 𝑥=𝑦⋅𝑧
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The only line of each test case contains a single integer 𝑘
 (1≤𝑘≤1018
).

Output
For each test case, output 𝑛
 — the minimum number of bulbs.

Example
InputCopy
3
1
3
8
OutputCopy
2
5
11
Note
In the first test case, the minimum number of bulbs is 2
. Let's denote the state of all bulbs with an array, where 1
 corresponds to a turned on bulb, and 0
 corresponds to a turned off bulb. Initially, the array is [1,1]
.

After performing the operation with 𝑖=1
, the array becomes [0⎯⎯,0⎯⎯]
.
After performing the operation with 𝑖=2
, the array becomes [0,1⎯⎯]
.
In the end, there are 𝑘=1
 bulbs on. We can also show that the answer cannot be less than 2
.

In the second test case, the minimum number of bulbs is 5
. Initially, the array is [1,1,1,1,1]
.

After performing the operation with 𝑖=1
, the array becomes [0⎯⎯,0⎯⎯,0⎯⎯,0⎯⎯,0⎯⎯]
.
After performing the operation with 𝑖=2
, the array becomes [0,1⎯⎯,0,1⎯⎯,0]
.
After performing the operation with 𝑖=3
, the array becomes [0,1,1⎯⎯,1,0]
.
After performing the operation with 𝑖=4
, the array becomes [0,1,1,0⎯⎯,0]
.
After performing the operation with 𝑖=5
, the array becomes [0,1,1,0,1⎯⎯]
.
In the end, there are 𝑘=3
 bulbs on. We can also show that the answer cannot be smaller than 5
.
*/

#include <cmath>
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    ll k;
    cin >> k;
    cout << k + (ll)(sqrtl(k) + 0.5) << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2020/333583385
