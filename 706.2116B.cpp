/*B. Gellyfish and Baby's Breath
time limit per test1 second
memory limit per test256 megabytes
Flower gives Gellyfish two permutations∗
 of [0,1,…,𝑛−1]
: 𝑝0,𝑝1,…,𝑝𝑛−1
 and 𝑞0,𝑞1,…,𝑞𝑛−1
.

Now Gellyfish wants to calculate an array 𝑟0,𝑟1,…,𝑟𝑛−1
 through the following method:

For all 𝑖
 (0≤𝑖≤𝑛−1
), 𝑟𝑖=max𝑗=0𝑖(2𝑝𝑗+2𝑞𝑖−𝑗)
But since Gellyfish is very lazy, you have to help her figure out the elements
of 𝑟
.

Since the elements of 𝑟
 are very large, you are only required to output the elements of 𝑟
 modulo 998244353
.

∗
An array 𝑏
 is a permutation of an array 𝑎
 if 𝑏
 consists of the elements of 𝑎
 in arbitrary order. For example, [4,2,3,4]
 is a permutation of [3,2,4,4]
 while [1,2,2]
 is not a permutation of [1,2,3]
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤105
).

The second line of each test case contains 𝑛
 integers 𝑝0,𝑝1,…,𝑝𝑛−1
 (0≤𝑝𝑖<𝑛
).

The third line of each test case contains 𝑛
 integers 𝑞0,𝑞1,…,𝑞𝑛−1
 (0≤𝑞𝑖<𝑛
).

It is guaranteed that both 𝑝
 and 𝑞
 are permutations of [0,1,…,𝑛−1]
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output 𝑛
 integers 𝑟0,𝑟1,…,𝑟𝑛−1
 in a single line, modulo 998244353
.

Example
InputCopy
3
3
0 2 1
1 2 0
5
0 1 2 3 4
4 3 2 1 0
10
5 8 9 3 4 0 2 7 1 6
9 5 1 4 0 3 2 8 7 6
OutputCopy
3 6 8
17 18 20 24 32
544 768 1024 544 528 528 516 640 516 768
Note
In the first test case:

𝑟0=2𝑝0+2𝑞0=1+2=3
𝑟1=max(2𝑝0+2𝑞1,2𝑝1+2𝑞0)=max(1+4,4+2)=6
𝑟2=max(2𝑝0+2𝑞2,2𝑝1+2𝑞1,2𝑝2+2𝑞0)=(1+1,4+4,2+2)=8


*/

/*given p,q which are permutation of array r
 calculate r, where r[i]=max(pow(2,p[j])+pow(2,q[i-j])) for j=0 to i
 find elemrents of r mod 998244353

mxa = maximum p[0..i], wa = index where p[wa] = mxa

mxb = maximum q[0..i], wb = index where q[wb] = mxb

r[i] = (2^p[idxa] + 2^q[idxb]) % MOD

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const ll MOD = 998244353;
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;

    // Step 1: Precompute powers of 2 modulo MOD
    vector<ll> v(n, 1);
    for (ll i = 1; i < n; i++)
      v[i] = (2 * v[i - 1]) % MOD;

    // Step 2: Read permutations p and q
    vector<ll> p(n), q(n);
    for (ll i = 0; i < n; i++)
      cin >> p[i];
    for (ll i = 0; i < n; i++)
      cin >> q[i];

    vector<ll> r(n); // result array
    ll mxa = -1, mxb = -1, wa = -1, wb = -1;

    for (ll i = 0; i < n; i++) {
      // update running maximums
      if (p[i] > mxa) {
        mxa = p[i];
        wa = i;
      }
      if (q[i] > mxb) {
        mxb = q[i];
        wb = i;
      }

      ll idxa = -1, idxb = -1;

      // decide optimal split j to maximize 2^p[j] + 2^q[i-j]
      if (mxa > mxb) {
        idxa = wa;
        idxb = i - wa;
      } else if (mxa < mxb) {
        idxa = i - wb;
        idxb = wb;
      } else {
        // tie: pick split giving larger sum
        ll tsta = p[i - wb];
        ll tstb = q[i - wa];
        if (tsta > tstb) {
          idxa = i - wb;
          idxb = wb;
        } else {
          idxa = wa;
          idxb = i - wa;
        }
      }

      r[i] = (v[p[idxa]] + v[q[idxb]]) % MOD;
    }

    for (ll i = 0; i < n; i++)
      cout << r[i] << " ";
    cout << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2116/339653371
