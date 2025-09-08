/*C. Hungry Games
time limit per test2 seconds
memory limit per test256 megabytes
Yaroslav is playing a computer game, and at one of the levels, he encountered 𝑛
 mushrooms arranged in a row. Each mushroom has its own level of toxicity; the 𝑖
-th mushroom from the beginning has a toxicity level of 𝑎𝑖
. Yaroslav can choose two integers 1≤𝑙≤𝑟≤𝑛
, and then his character will take turns from left to right to eat mushrooms
from this subsegment one by one, i.e., the mushrooms with numbers 𝑙,𝑙+1,𝑙+2,…,𝑟
.

The character has a toxicity level 𝑔
, initially equal to 0
. The computer game is defined by the number 𝑥
 — the maximum toxicity level at any given time. When eating a mushroom with
toxicity level 𝑘 , the following happens:

The toxicity level of the character is increased by 𝑘
.
If 𝑔≤𝑥
, the process continues; otherwise, 𝑔
 becomes zero and the process continues.
Yaroslav became interested in how many ways there are to choose the values of 𝑙
 and 𝑟
 such that the final value of 𝑔
 is not zero. Help Yaroslav find this number!

Input
Each test consists of multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains two integers 𝑛
, 𝑥
 (1≤𝑛≤2⋅105,1≤𝑥≤109
) — the number of mushrooms and the maximum toxicity level.

The second line of each test case contains 𝑛
 numbers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single number — the number of subsegments such that
the final value of 𝑔 will not be zero.

Example
InputCopy
5
4 2
1 1 1 1
3 2
1 2 3
1 6
10
6 3
1 2 1 4 3 8
5 999999999
999999999 999999998 1000000000 1000000000 500000000
OutputCopy
8
2
0
10
7
Note
In the first test case, the subsegments (1,1)
, (1,2)
, (1,4)
, (2,2)
, (2,3)
, (3,3)
, (3,4)
 and (4,4)
 are suitable.

In the second test case, non-zero 𝑔
 will remain only on the subsegments (1,1)
 and (2,2)
.

In the third test case, on the only possible subsegment, 𝑔
 will be zero.
*/

/*### Approach

We want to count the number of subarrays whose sum is at most `x`.

---

#### Step 1: Brute force idea
- Fix a starting index `l`.
- Extend the subarray to the right: accumulate the sum `g = a[l] + a[l+1] +
...`.
- As soon as `g > x`, we can stop for this `l` because every further extension
only increases the sum.
- Count how many valid subarrays we got for each `l`.

This works but is `O(n^2)` in the worst case.

---

#### Step 2: Key observation
- All `a[i] ≥ 1`.
- Therefore, prefix sums are **strictly increasing**.
- That means once the sum exceeds `x`, extending further is useless.
- This allows us to apply a **two-pointer / sliding window** technique.

---

#### Step 3: Two-pointer method
- Maintain a window `[l, r)` and a running sum `g = a[l] + ... + a[r-1]`.
- For each `l`:
  - Extend `r` forward while `g + a[r] ≤ x`.
  - After this, all subarrays starting at `l` and ending before `r` are valid.
    - Count = `r - l`.
  - Add this to the answer.
  - Then move `l` forward: subtract `a[l]` from `g`.

---

#### Step 4: Complexity
- Each index moves forward at most once with `l` and once with `r`.
- Total time complexity: **O(n)** per test case.
- Space complexity: **O(1)** (besides input array).

---

*/

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr i64 MOD = 1'000'000'007;

static inline i64 sum_vector(const vector<i64> &v) {
  return accumulate(v.begin(), v.end(), 0LL);
}

/**
 * Returns a 1-based index `ind` such that:
 * - if i != 0, search threshold is x + pref[i-1]
 * - binary searches in (i+1 .. n-1) for first position where pref[mid] >
 * threshold
 * - returns (low + 1) (1-based). If i == n-1, returns n+1.
 */
static i64 findIndex(i64 i, i64 n, const vector<i64> &pref, i64 x) {
  if (i != 0)
    x += pref[i - 1];
  if (i == n - 1)
    return n + 1;

  i64 low = i + 1;
  i64 high = n - 1;

  while (low <= high) {
    i64 mid = low + (high - low) / 2;
    if (pref[mid] <= x)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low + 1; // 1-based
}

static void solve() {
  i64 n, x;
  cin >> n >> x;

  vector<i64> arr(n);
  for (i64 &v : arr)
    cin >> v;

  // prefix sums
  vector<i64> pref(n);
  i64 curr = 0;
  for (i64 i = 0; i < n; ++i) {
    curr += arr[i];
    pref[i] = curr;
  }

  // value[i] and dependency list where j depends on i (1-based indices in dep
  // slots)
  vector<i64> value(n, 0);
  vector<vector<i64>> dep(
      n); // dep[k] holds indices j such that j depends on position k (0-based),
          // but k is taken as 1-based when pushing.

  for (i64 i = 0; i < n; ++i) {
    if (arr[i] > x) {
      if (i != n - 1)
        dep[i + 1].push_back(i); // i+1 acts like 1-based slot
      continue;
    }

    i64 ind = findIndex(i, n, pref, x); // 1-based
    if (ind < n)
      dep[ind].push_back(
          i); // only queue if inside 0..n-1 (since dep is 0..n-1)
    value[i] = ind - i - 1;
  }

  // propagate dependencies from right to left
  for (i64 i = n - 1; i >= 0; --i) {
    for (i64 j : dep[i])
      value[j] += value[i];
  }

  cout << sum_vector(value) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef ONLINE_JUDGE
  // no file redirection
#else
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1994/337486518
