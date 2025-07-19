/*C. Palindromic Subsequences
time limit per test2 seconds
memory limit per test512 megabytes

For an integer sequence 𝑎=[𝑎1,𝑎2,…,𝑎𝑛]
, we define 𝑓(𝑎)
 as the length of the longest subsequence∗
 of 𝑎
 that is a palindrome†
.

Let 𝑔(𝑎)
 represent the number of subsequences of length 𝑓(𝑎)
 that are palindromes. In other words, 𝑔(𝑎)
 counts the number of palindromic subsequences in 𝑎
 that have the maximum length.

Given an integer 𝑛
, your task is to find any sequence 𝑎
 of 𝑛
 integers that satisfies the following conditions:

1≤𝑎𝑖≤𝑛
 for all 1≤𝑖≤𝑛
.
𝑔(𝑎)>𝑛
It can be proven that such a sequence always exists under the given constraints.

∗
A sequence 𝑥
 is a subsequence of a sequence 𝑦
 if 𝑥
 can be obtained from 𝑦
 by the deletion of several (possibly, zero or all) element from arbitrary
positions.

†
A palindrome is a sequence that reads the same from left to right as from right
to left. For example, [1,2,1,3,1,2,1] , [5,5,5,5] , and [4,3,3,4] are
palindromes, while [1,2] and [2,3,3,3,3] are not.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤100
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (6≤𝑛≤100
) — the length of the sequence.

Note that there are no constraints on the sum of 𝑛
 over all test cases.

Output
For each test case, output 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
, representing an array that satisfies the conditions.

If there are multiple solutions, you may output any of them.

Example
InputCopy
3
6
9
15
OutputCopy
1 1 2 3 1 2
7 3 3 7 5 3 7 7 3
15 8 8 8 15 5 8 1 15 5 8 15 15 15 8
Note
In the first example, one possible solution is 𝑎=[1,1,2,3,1,2]
. In this case, 𝑓(𝑎)=3
 as the longest palindromic subsequence has length 3
. There are 7
 ways to choose a subsequence of length 3
 that is a palindrome, as shown below:

[𝑎1,𝑎2,𝑎5]=[1,1,1]
[𝑎1,𝑎3,𝑎5]=[1,2,1]
[𝑎1,𝑎4,𝑎5]=[1,3,1]
[𝑎2,𝑎3,𝑎5]=[1,2,1]
[𝑎2,𝑎4,𝑎5]=[1,3,1]
[𝑎3,𝑎4,𝑎6]=[2,3,2]
[𝑎3,𝑎5,𝑎6]=[2,1,2]
Therefore, 𝑔(𝑎)=7
, which is greater than 𝑛=6
. Hence, 𝑎=[1,1,2,3,1,2]
 is a valid solution.

In the second example, one possible solution is 𝑎=[7,3,3,7,5,3,7,7,3]
. In this case, 𝑓(𝑎)=5
. There are 24
 ways to choose a subsequence of length 5
 that is a palindrome. Some examples are [𝑎2,𝑎4,𝑎5,𝑎8,𝑎9]=[3,7,5,7,3]
 and [𝑎1,𝑎4,𝑎6,𝑎7,𝑎8]=[7,7,3,7,7]
. Therefore, 𝑔(𝑎)=24
, which is greater than 𝑛=9
. Hence, 𝑎=[7,3,3,7,5,3,7,7,3]
 is a valid solution.

In the third example, 𝑓(𝑎)=7
 and 𝑔(𝑎)=190
, which is greater than 𝑛=15
.
*/

/*n is input
f(a)=length of longest palindromic subsequence
subsequence= array obtained by deleting some or 0 elements from original array
order must be preserved
longest palindromic subsequcne is a subsequnce which is palindromic in order

g(a)= no of palindromic subsequence are there of length f(a)

1<=a[i]<=n for all i
g(a)>n

f(a)max=1
g(a)=n

but we wanna get g(a)>n

consider example: 1,2,3 ......n/2,1,2,......n/2
f(a)=3
g(a)=n/2*(n/2-1)
=n(n-2)/4

n(n-2)/4>n
n>6

n>=8=> we're done
n=6 --> provided with example{1,1,2,3,1,2}
n=7 --> 1,2,3,4,1,2,3

so just put it manually
*/
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define ll long long
#define int long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
using namespace std;
using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
const int inf = 9e18;
const int mod = 1e9 + 7;
const int NUM = 1000030;
const int N = 10000000;
#define DEBUG(x) cerr << #x << ": " << x << '\n'
template <typename T, typename Y>
istream &operator>>(istream &is, pair<T, Y> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename Y>
ostream &operator<<(ostream &os, pair<T, Y> p) {
  os << p.first << ' ' << p.second << ' ';
  return os;
}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {
  for (auto &i : v)
    is >> i;
  return is;
}
template <typename T> ostream &operator<<(ostream &os, vector<T> v) {
  for (auto &i : v)
    os << i << ' ';
  return os;
}
vector<int> lp, sieve;
vector<int> pr;
vector<int> power;
vector<int> fact;
void initpow(int x) {
  power.resize(NUM);
  power[0] = 1;
  for (int i = 1; i < NUM; i++) {
    power[i] = (power[i - 1] * (x % mod)) % mod;
  }
}
void initFactorial() {
  fact.resize(NUM);
  fact[0] = 1;
  for (int i = 1; i < NUM; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
}
void calc_sieve() {
  sieve.resize(NUM + 1, 0);
  for (int x = 2; x <= NUM; x++) {
    if (sieve[x])
      continue;
    for (int u = x; u <= NUM; u += x) {
      sieve[u] = x;
    }
  }
}
void primefactor() {
  lp.resize(N + 1, 0);
  for (int i = 2; i <= N; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
      lp[i * pr[j]] = pr[j];
  }
}
int binpow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
int binpow(int a, int b, int mod) {
  int res = 1;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res % mod;
}
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int lcm(int a, int b) { return ((a / gcd(a, b)) * b); }
int inversemod(int a, int mod) { return binpow(a, mod - 2, mod); }
int divmod(int a, int b, int c) { return ((a % c) * inversemod(b, c)) % c; }
int combination(int n, int k) {
  if (k > n)
    return 0;
  int p1 = (fact[n] * inversemod(fact[k], mod)) % mod;
  int p2 = (1 * inversemod(fact[n - k], mod)) % mod;
  return (p1 * p2) % mod;
}
void solve() {
  ll n;
  cin >> n;
  vi v(n);
  if (n == 6) {
    cout << "1 1 2 3 1 2" << endl;
    return;
  } else if (n == 7) {
    cout << "1 1 2 3 1 2 2" << endl;
    return;
  }
  for (ll i = 0; i < n / 2; i++) {
    v[i] = i + 1;
  }
  for (ll i = n / 2; i < n; i++) {
    v[i] = i - n / 2 + 1;
  }
  cout << v << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2056/329716152
