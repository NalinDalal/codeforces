/*B. Make Almost Equal With Mod
time limit per test1 second
memory limit per test256 megabytes
xi - Solar Storm
⠀
You are given an array 𝑎1,𝑎2,…,𝑎𝑛
 of distinct positive integers. You have to do the following operation exactly
once:

choose a positive integer 𝑘
;
for each 𝑖
 from 1
 to 𝑛
, replace 𝑎𝑖
 with 𝑎𝑖 mod 𝑘†
.
Find a value of 𝑘
 such that 1≤𝑘≤1018
 and the array 𝑎1,𝑎2,…,𝑎𝑛
 contains exactly 2
 distinct values at the end of the operation. It can be shown that, under the
constraints of the problem, at least one such 𝑘 always exists. If there are
multiple solutions, you can print any of them.

†
 𝑎 mod 𝑏
 denotes the remainder after dividing 𝑎
 by 𝑏
. For example:

7 mod 3=1
 since 7=3⋅2+1
15 mod 4=3
 since 15=4⋅3+3
21 mod 1=0
 since 21=21⋅1+0
Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤100
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤1017
) — the initial state of the array. It is guaranteed that all the 𝑎𝑖
 are distinct.

Note that there are no constraints on the sum of 𝑛
 over all test cases.

Output
For each test case, output a single integer: a value of 𝑘
 (1≤𝑘≤1018
) such that the array 𝑎1,𝑎2,…,𝑎𝑛
 contains exactly 2
 distinct values at the end of the operation.

Example
InputCopy
5
4
8 15 22 30
5
60 90 98 120 308
6
328 769 541 986 215 734
5
1000 2000 7000 11000 16000
2
2 1
OutputCopy
7
30
3
5000
1000000000000000000
Note
In the first test case, you can choose 𝑘=7
. The array becomes [8 mod 7,15 mod 7,22 mod 7,30 mod 7]=[1,1,1,2]
, which contains exactly 2
 distinct values ({1,2}
).

In the second test case, you can choose 𝑘=30
. The array becomes [0,0,8,0,8]
, which contains exactly 2
 distinct values ({0,8}
). Note that choosing 𝑘=10
 would also be a valid solution.

In the last test case, you can choose 𝑘=1018
. The array becomes [2,1]
, which contains exactly 2
 distinct values ({1,2}
). Note that choosing 𝑘=1018+1
 would not be valid, because 1≤𝑘≤1018
 must be true.
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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a)
      cin >> x;

    ll mod = 0;
    for (ll t = 2; !mod && t < (ll)3e18; t *= 2) {
      set<ll> s;
      for (ll p = 0; s.size() < 3 && p < n; p++) {
        s.insert(a[p] % t);
      }
      if (s.size() == 2) {
        mod = t;
        break;
      }
    }

    cout << mod << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1909/342538098
