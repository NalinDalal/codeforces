/*B. Binary Colouring
time limit per test1 second
memory limit per test256 megabytes
You are given a positive integer 𝑥
. Find any array of integers 𝑎0,𝑎1,…,𝑎𝑛−1
 for which the following holds:

1≤𝑛≤32
,
𝑎𝑖
 is 1
, 0
, or −1
 for all 0≤𝑖≤𝑛−1
,
𝑥=∑𝑖=0𝑛−1𝑎𝑖⋅2𝑖
,
There does not exist an index 0≤𝑖≤𝑛−2
 such that both 𝑎𝑖≠0
 and 𝑎𝑖+1≠0
.
It can be proven that under the constraints of the problem, a valid array always
exists.

Input
Each test contains multiple test cases. The first line of input contains a
single integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the
test cases follows.

The only line of each test case contains a single positive integer 𝑥
 (1≤𝑥<230
).

Output
For each test case, output two lines.

On the first line, output an integer 𝑛
 (1≤𝑛≤32
) — the length of the array 𝑎0,𝑎1,…,𝑎𝑛−1
.

On the second line, output the array 𝑎0,𝑎1,…,𝑎𝑛−1
.

If there are multiple valid arrays, you can output any of them.

Example
InputCopy
7
1
14
24
15
27
11
19
OutputCopy
1
1
5
0 -1 0 0 1
6
0 0 0 -1 0 1
5
-1 0 0 0 1
6
-1 0 -1 0 0 1
5
-1 0 -1 0 1
5
-1 0 1 0 1
Note
In the first test case, one valid array is [1]
, since (1)⋅20=1
.

In the second test case, one possible valid array is [0,−1,0,0,1]
, since (0)⋅20+(−1)⋅21+(0)⋅22+(0)⋅23+(1)⋅24=−2+16=14
.
*/

// a[i] is -1 or 0 or 1
// no 2 consecutive will be 0 at same time
// x = sum(i=0..n-1)(a[i] * pow(2,i))
// given value of x, find n and array a
// output them
//
// Steps:
// 1. Convert x to normal binary array (0 or 1) lsb first
// 2. Traverse array to fix consecutive 1s and carry propagation:
//      - if two consecutive 1s -> lower bit = -1, upper = 0, carry = true
//      - propagate carry forward to ensure no consecutive 0s
// 3. If carry remains after loop -> append new 1
// 4. Print n (size of array) and the array a

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    long x;
    cin >> x;
    vector<long> a;

    // Step 1: Convert x to binary (lsb first)
    long val = x;
    while (val) {
      a.push_back(val % 2); // 0 or 1
      val /= 2;
    }

    bool carry = false;
    // Step 2: Adjust array so that a[i] is -1, 0, or 1
    //         and no two consecutive zeros appear after adjustment
    for (long i = 1; i < a.size(); i++) {
      if (a[i - 1] && a[i]) {
        // if two consecutive 1s, make lower bit -1, upper 0
        a[i - 1] = -1;
        a[i] = 0;
        carry = true;
      } else if (a[i] && carry) {
        // propagate carry
        a[i] = 0;
      } else if (a[i]) {
        // 1 with no carry: fine
        continue;
      } else if (carry) {
        // 0 with carry: fix by making it 1
        a[i] = 1;
        carry = false;
      }
    }

    // Step 3: if carry remains, add a new 1
    if (carry)
      a.push_back(1);

    // Step 4: output length and array
    cout << a.size() << "\n";
    for (long i = 0; i < a.size(); i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1977/339652816
