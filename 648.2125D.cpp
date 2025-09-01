/*D. Segments Covering
time limit per test2 seconds
memory limit per test256 megabytes
There is a linear strip divided into 𝑚
 cells, numbered from 1
 to 𝑚
 from left to right.

You are given 𝑛
 segments. Each segment is defined by four numbers: 𝑙
, 𝑟
, 𝑝
 and 𝑞
 — the segment covers cells from 𝑙
 to 𝑟
 inclusively and exists with probability 𝑝𝑞
 (independently).

Your task is to calculate the probability that each cell is covered by exactly
one segment.

Input
The first line contains two integers 𝑛
 and 𝑚
 (1≤𝑛,𝑚≤2⋅105
).

Then 𝑛
 lines follow. The 𝑖
-th of them contains four integers 𝑙𝑖
, 𝑟𝑖
, 𝑝𝑖
 and 𝑞𝑖
 (1≤𝑙𝑖≤𝑟𝑖≤𝑚
; 1≤𝑝𝑖<𝑞𝑖<998244353
).

Output
Print a single integer — the probability that each cell is covered by exactly
one segment, taken modulo 998244353
.

Formally, the probability can be expressed as an irreducible fraction 𝑥𝑦
. You have to print the value of 𝑥⋅𝑦−1mod998244353
, where 𝑦−1
 is an integer such that 𝑦⋅𝑦−1mod998244353=1
.

Examples
InputCopy
3 3
1 2 1 3
3 3 1 2
1 3 2 3
OutputCopy
610038216
InputCopy
2 3
1 2 1 2
2 3 1 2
OutputCopy
0
InputCopy
8 5
1 3 1 2
1 5 1 6
1 4 4 5
5 5 1 7
4 5 1 2
4 5 2 5
3 3 2 7
1 2 1 3
OutputCopy
94391813
Note
In the first example, the probability is equal to 518
.
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

#define FAST_IO                                                                \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(nullptr);                                                            \
  cout.tie(nullptr);

const int N = 2e5 + 1;

ll n, m;
vector<vector<ll>> v[N]; // v[i] stores {r, p, q} for intervals starting at i
ll DP[N];                // memoization for dp

// Binary exponentiation modulo `mod`
ll binex(ll a, ll b, ll mod) {
  a %= mod;
  ll result = 1;
  b %= (mod - 1); // Fermat's little theorem optimization
  while (b > 0) {
    if (b % 2)
      result = (result * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return result;
}

// Modular inverse using Fermat's little theorem
ll modinv(ll a, ll mod) { return binex(a, mod - 2, mod); }

// DP function to compute probability/value from position i
ll dp(ll i) {
  if (i > m)
    return 1; // base case
  if (DP[i] != -1)
    return DP[i]; // memoization

  ll ans = 0;
  for (auto next : v[i]) {
    ll r = next[0], p = next[1], q = next[2];

    // Compute probability fraction: (p/q) / ((q-p)/q) = p / (q-p)
    ll val = (modinv(q - p, MOD) * q) % MOD;
    val = (val * p) % MOD;
    val = (val * modinv(q, MOD)) % MOD;

    // Multiply by DP of next interval
    ans = (ans + val * dp(r + 1)) % MOD;
  }

  return DP[i] = ans;
}

int main() {
  FAST_IO
  memset(DP, -1, sizeof(DP));

  cin >> n >> m;
  ll total_val = 1;

  for (ll i = 0; i < n; i++) {
    ll l, r, p, q;
    cin >> l >> r >> p >> q;
    v[l].push_back({r, p, q});

    // Multiply cumulative probability
    total_val = (total_val * (q - p)) % MOD;
    total_val = (total_val * modinv(q, MOD)) % MOD;
  }

  cout << (total_val * dp(1)) % MOD << endl;

  return 0;
}

// sub: https://codeforces.com/problemset/submission/2125/336458943
