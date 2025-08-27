/*E. Decode
time limit per test2 seconds
memory limit per test256 megabytes
In a desperate attempt to obtain your waifu favorite character, you have hacked
into the source code of the game. After days of struggling, you finally find the
binary string that encodes the gacha system of the game. In order to decode it,
you must first solve the following problem.

You are given a binary string 𝑠
 of length 𝑛
. For each pair of integers (𝑙,𝑟)
 (1≤𝑙≤𝑟≤𝑛)
, count the number of pairs (𝑥,𝑦)
 (𝑙≤𝑥≤𝑦≤𝑟)
 such that the amount of 𝟶
 equals the amount of 𝟷
 in the substring 𝑠𝑥𝑠𝑥+1...𝑠𝑦
.

Output the sum of counts over all possible (𝑙,𝑟)
 modulo 109+7
.

Input
The first line contains 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

Each test case contains a binary string 𝑠
 (1≤|𝑠|≤2⋅105
). It is guaranteed 𝑠
 only contains characters 𝟶
 and 𝟷
.

It is guaranteed the sum of |𝑠|
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output an integer, the answer modulo 109+7
.

Example
InputCopy
4
0000
01010101
1100111001
11000000111
OutputCopy
0
130
147
70
*/

/*Certainly. **Answer (problem E – Decode):**

---

### Step 1. Restating the Problem

We need to count, for all ranges `(l, r)` of a binary string `s`, the number of
sub-substrings `(x, y)` within `(l, r)` that are *balanced* (`#0 = #1`). Then
sum over all `(l, r)`. Constraints: `|s| ≤ 2⋅10^5`, sum over test cases ≤
2⋅10^5. So we need `O(n)` or `O(n log n)` per test case.

---

### Step 2. Reformulation

Observation: The total answer equals the **sum over all balanced substrings `(x,
y)`** of how many `(l, r)` intervals contain `(x, y)`.

* If substring `(x, y)` is balanced, then every `(l, r)` with `l ≤ x` and `r ≥
y` includes it.
* Number of such `(l, r)` = `x * (n - y + 1)`.

So:

$$
\text{Answer} = \sum_{\text{balanced }(x,y)} x \cdot (n-y+1).
$$

This reduces the problem to enumerating balanced substrings efficiently.

---

### Step 3. Balanced Substrings via Prefix Balance

Define prefix balance array:

$$
p[0] = 0,\quad p[i] = \#1\text{s in first i chars} - \#0\text{s in first i
chars}.
$$

Then substring `(x, y)` is balanced iff

$$
p[y] = p[x-1].
$$

So we want pairs `(a, b)` with `p[a] = p[b]`, `a < b`. Balanced substring is
`(a+1, b)`. Contribution: `(a+1) * (n - b + 1)`.

Thus:

$$
\text{Answer} = \sum_{p[a] = p[b],\, a<b} (a+1)\cdot(n-b+1).
$$

---

### Step 4. Efficient Summation

We must process all equal prefix balances.

For each value of `p`, maintain list of indices where it occurs.
For each group of indices `[i1, i2, ..., ik]` (in increasing order), we want:

$$
\sum_{u<v} (i_u+1) \cdot (n - i_v + 1).
$$

This can be done efficiently with prefix sums.

Let’s fix `v`, then contribution from all `u < v` is:

$$
(n - i_v + 1) \cdot \sum_{u < v} (i_u+1).
$$

So we can process sequentially:

* Maintain `prefix_sum = sum_{u<current} (i_u+1)`.
* For each `iv`: add `(n - iv + 1) * prefix_sum`.

This is `O(n)` per test case.

---

### Step 5. Modulo Arithmetic

We must output modulo `1e9+7`. All arithmetic done with `long long` then mod.

---

### Step 6. Example Walkthrough

`s = "01010101"`, `n=8`.

Prefix balances: p\[0]=0.
p\[1]=-1, p\[2]=0, p\[3]=-1, p\[4]=0, p\[5]=-1, p\[6]=0, p\[7]=-1, p\[8]=0.

Groups: balance=0: indices \[0,2,4,6,8].
balance=-1: indices \[1,3,5,7].

For group \[0,2,4,6,8]: iterate v=2,4,6,8.
Compute contributions, etc. Then sum groups. Produces 130, matches sample.

---

**Recommendation:** Use prefix-balance grouping and prefix sums for
contributions.
**Next step:** Compile and run with provided samples to verify exact outputs.

*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();

    // prefix balances
    vector<int> p(n + 1, 0);
    for (int i = 0; i < n; i++) {
      p[i + 1] = p[i] + (s[i] == '1' ? 1 : -1);
    }

    // group indices by balance
    unordered_map<int, vector<int>> groups;
    groups.reserve(n * 2);
    groups.max_load_factor(0.7);

    for (int i = 0; i <= n; i++) {
      groups[p[i]].push_back(i);
    }

    ll ans = 0;
    for (auto &kv : groups) {
      auto &vec = kv.second;
      ll prefix_sum = 0;
      for (int idx : vec) {
        // contribute from previous indices
        ll contrib = ((ll)(n - idx + 1) % MOD) * (prefix_sum % MOD) % MOD;
        ans = (ans + contrib) % MOD;

        // update prefix sum
        prefix_sum = (prefix_sum + (ll)(idx + 1)) % MOD;
      }
    }
    cout << ans % MOD << "\n";
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/1996/335753989
