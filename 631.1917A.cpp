/*A. Least Product
time limit per test1 second
memory limit per test256 megabytes
You are given an array of integers 𝑎1,𝑎2,…,𝑎𝑛
. You can perform the following operation any number of times (possibly zero):

Choose any element 𝑎𝑖
 from the array and change its value to any integer between 0
 and 𝑎𝑖
 (inclusive). More formally, if 𝑎𝑖<0
, replace 𝑎𝑖
 with any integer in [𝑎𝑖,0]
, otherwise replace 𝑎𝑖
 with any integer in [0,𝑎𝑖]
.
Let 𝑟
 be the minimum possible product of all the 𝑎𝑖
 after performing the operation any number of times.

Find the minimum number of operations required to make the product equal to 𝑟
. Also, print one such shortest sequence of operations. If there are multiple
answers, you can print any of them.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤500 ) - the number of test cases. This is followed by their
description.

The first line of each test case contains the a single integer 𝑛
 (1≤𝑛≤100
) — the length of the array.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (−109≤𝑎𝑖≤109
).

Output
For each test case:

The first line must contain the minimum number of operations 𝑘
 (0≤𝑘≤𝑛
).
The 𝑗
-th of the next 𝑘
 lines must contain two integers 𝑖
 and 𝑥
, which represent the 𝑗
-th operation. That operation consists in replacing 𝑎𝑖
 with 𝑥
.
Example
InputCopy
4
1
155
4
2 8 -1 3
4
-1 0 -2 -5
4
-15 -75 -25 -30
OutputCopy
1
1 0
0
0
1
3 0
Note
In the first test case, we can change the value of the first integer into 0
 and the product will become 0
, which is the minimum possible.

In the second test case, initially, the product of integers is equal to
2⋅8⋅(−1)⋅3=−48 which is the minimum possible, so we should do nothing in this
case.
*/

/*Certainly. **Answer:**

### Step 1. Key Insight

The operation allows reducing any number toward zero (if positive) or toward
zero (if negative). The minimal possible product `r` is:

1. If there is at least one `0` → `r = 0` (since we can always make at least one
element `0`).
2. Otherwise, if there are **no zeros**:

   * If the number of negatives is **odd** → product is already negative, which
is minimal. No operations needed.
   * If the number of negatives is **even** → product is non-negative. To
minimize, we must introduce a zero. That means setting any element to `0` in
**one operation**.

So the minimal number of operations is:

* `0` if already minimal.
* `1` otherwise.

### Step 2. Constructing Operations

* If a zero exists → just output `0`.
* If negatives are odd → product already minimal → output `0`.
* If negatives are even and no zeros → perform one operation: choose any element
(simplest: the one with smallest absolute value) and set it to `0`.

### Step 3. Example

Input:

```
4
1
155
4
2 8 -1 3
4
-1 0 -2 -5
4
-15 -75 -25 -30
```

Output (valid one among many):

```
1
1 0
0
0
1
4 0
```

### Step 4. Why Correct

* Case 1: one element `155` → all positive, so product positive. Best is `0`,
one operation.
* Case 2: `2 8 -1 3` → product negative already. Best possible, zero operations.
* Case 3: contains zero. Product `0`. Already minimal.
* Case 4: four negatives (even count). Product positive. Must set one element to
`0`. One operation.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    bool hasZero = false;
    int negCount = 0;
    int minIdx = 0;
    long long minAbs = LLONG_MAX;

    for (int i = 0; i < n; i++) {
      if (a[i] == 0)
        hasZero = true;
      if (a[i] < 0)
        negCount++;
      if (abs(a[i]) < minAbs) {
        minAbs = abs(a[i]);
        minIdx = i;
      }
    }

    if (hasZero || (negCount % 2 == 1)) {
      cout << 0 << "\n";
    } else {
      cout << 1 << "\n";
      cout << (minIdx + 1) << " 0\n";
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1917/335753470
