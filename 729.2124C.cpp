/*C. Subset Multiplication
time limit per test3 seconds
memory limit per test256 megabytes
Alice has an array 𝑎
, consisting of 𝑛
 positive integers. The array satisfies the beautiful property that 𝑎𝑖
 divides 𝑎𝑖+1
 for each 1≤𝑖≤𝑛−1
.

Bob sees Alice's beautiful array and is jealous. To sabotage her, Bob first
creates an array 𝑏 of size 𝑛 such that 𝑏𝑖=𝑎𝑖 for each 1≤𝑖≤𝑛 . Then, he chooses a
positive integer 𝑥 and multiplies some (possibly none, possibly all) elements in
𝑏 by 𝑥
.

Formally, he chooses a (possibly-empty) subset 𝑆⊆{1,2,…,𝑛}
, and for each 𝑖∈𝑆
, he sets 𝑏𝑖:=𝑏𝑖⋅𝑥
.

You are given an array 𝑏
, but you don't know array 𝑎
 and the chosen number 𝑥
. Please output any integer 𝑥
 that Bob could choose, so that multiplying some subset of elements of the
correct array 𝑎 by 𝑥 would result in array 𝑏 . It is guaranteed that the answer
exists. If there are multiple possible integers, you can output any of them.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤2⋅105
). The description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (2≤𝑛≤6⋅105
) — the length of the array 𝑏
.

The second line of each test case contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤109
) — denoting the array 𝑏
.

It is guaranteed the array 𝑏
 can be obtained from some beautiful array 𝑎
 and some positive integer 𝑥
 as described in the statements.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 6⋅105
.

Output
For each test case, output any possible value of 𝑥
 (1≤𝑥≤109
) on a new line. It is guaranteed at least one value of 𝑥
 exists.

Example
InputCopy
4
2
2 4
3
1 1000000000 500000000
4
4 8 4 8
7
42 42 14 84 28 73080 255780
OutputCopy
343
2
4
6
Note
In the first test case, it is possible Bob selected 𝑥=343
 and 𝑆={}
 (meaning he did not change the array 𝑎
 at all).

In the third test case, it is possible Bob selected 𝑥=4
 and 𝑆={1,2}
, meaning he multiplied both 𝑏1
 and 𝑏2
 by 4
. The original array was {1,2,4,8}
, which satisfies the required property.
*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b; // safer against overflow
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll p = 0; p < n; p++) {
      cin >> a[p];
    }

    ll fgcd = 0, flcm = 1;
    for (ll p = n - 1; p >= 0; p--) {
      fgcd = gcd(fgcd, a[p]);
      flcm = lcm(flcm, a[p] / fgcd);
    }

    cout << flcm << "\n";
  }
}
// sub: https://codeforces.com/problemset/submission/2124/341018357
