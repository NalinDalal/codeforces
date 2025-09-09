/*C. Add Zeros
time limit per test3 seconds
memory limit per test256 megabytes
You're given an array 𝑎
 initially containing 𝑛
 integers. In one operation, you must do the following:

Choose a position 𝑖
 such that 1<𝑖≤|𝑎|
 and 𝑎𝑖=|𝑎|+1−𝑖
, where |𝑎|
 is the current size of the array.
Append 𝑖−1
 zeros onto the end of 𝑎
.
After performing this operation as many times as you want, what is the maximum
possible length of the array 𝑎
?

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤1000
). The description of the test cases follows.

The first line of each test case contains 𝑛
 (1≤𝑛≤3⋅105
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤1012
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 3⋅105
.

Output
For each test case, output a single integer — the maximum possible length of 𝑎
 after performing some sequence of operations.

Example
InputCopy
4
5
2 4 6 2 5
5
5 4 4 5 1
4
6 8 2 3
1
1
OutputCopy
10
11
10
1
Note
In the first test case, we can first choose 𝑖=4
, since 𝑎4=5+1−4=2
. After this, the array becomes [2,4,6,2,5,0,0,0]
. We can then choose 𝑖=3
 since 𝑎3=8+1−3=6
. After this, the array becomes [2,4,6,2,5,0,0,0,0,0]
, which has a length of 10
. It can be shown that no sequence of operations will make the final array
longer.

In the second test case, we can choose 𝑖=2
, then 𝑖=3
, then 𝑖=4
. The final array will be [5,4,4,5,1,0,0,0,0,0,0]
, with a length of 11
.
*/

/*Choose i such that 1 < i ≤ |a| and a[i] == |a| + 1 − i.

Append (i−1) zeros to the end of array

At length m = |a|, the condition is:

a[i] == m + 1 − i

new_length = m + (i−1)

think like jump from m to m+(i-1)

check all i, if match, new length

Start with maxLen = n.

Traverse from right to left:

If a[i] == maxLen + 1 − i, then update:

maxLen += (i−1)
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
ll expo(ll a, ll b, ll mod) {
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
ll mod_mul(ll a, ll b, ll m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m
#define fr(i, n) for (ll i = 0; i < n; i++)
#define pb push_back
#define sz(x) x.size()
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag,
             tree_order_statistics_node_update>
    pbds; // find_by_order, order_of_key
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#ifndef ONLINE_JUDGE
#define debug(x)                                                               \
  cerr << #x << " ";                                                           \
  _print(x);                                                                   \
  cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

/*
**************************************************************************************************
**************************************************************************************************


                    ***        **************
                    ***        **************
                    ***  ***   ***   ***
                    ***  ***   ***   ***
                    ***        ***
                    *************************
                    *************************
                               ***        ***
                         ***   ***   ***  ***
                         ***   ***   ***  ***
                    **************        ***
                    **************        ***

**************************************************************************************************
**************************************************************************************************
*/
template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
  cerr << "}";
}
template <class T> void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V> void _print(unordered_map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
#pragma GCC optimize("unroll-loops,O3,Ofast") // even 10^8+ also works with this
#pragma GCC target("avx2,avx,fma,bmi,bmi2,lzcnt,popcnt")

int knightx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int knighty[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int f(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp) {
  if (ind == nums.size()) {
    return 0;
  }
  if (dp[ind][prev + 1] != -1)
    return dp[ind][prev + 1];
  int len = 0 + f(ind + 1, prev, nums, dp); // not take
  if (prev == -1 || nums[ind] >= nums[prev]) {
    len = max(len, 1 + f(ind + 1, ind, nums, dp));
  }
  return dp[ind][prev + 1] = len;
}
int lengthOfLIS(vector<int> &nums) {

  int n = nums.size();
  vector<vector<int>> dp(n, vector<int>(n + 1, -1));
  return f(0, -1, nums, dp);
}
void solve() {
  int n;
  cin >> n;
  vector<ll> v(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> v[i];
  // set<ll>st;
  // st.insert(n);
  // debug(v)
  // for(int i=2;i<=n;i++){
  //     if(st.find(v[i]+i-1)!=st.end()){
  //         st.insert(v[i]+i-1+i-1);
  //     }
  //     debug(st)
  // }

  vector<pair<ll, ll>> arr;
  for (int i = 2; i <= n; i++) {
    arr.pb({v[i] + i - 1, i - 1});
  }
  sort(all(arr));
  // debug(st)
  set<ll> st;
  st.insert(n);
  for (int i = 0; i < n - 1; i++) {
    if (st.find(arr[i].ff) != st.end()) {
      st.insert(arr[i].ff + arr[i].ss);
    }
    debug(st)
  }

  cout << *st.rbegin() << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
  fastio();

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

// sub: https://codeforces.com/problemset/submission/2027/337697753
