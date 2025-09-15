/*C. XOR and Triangle
time limit per test2 seconds
memory limit per test256 megabytes
This time, the pink soldiers have given you an integer 𝑥
 (𝑥≥2
).

Please determine if there exists a positive integer 𝑦
 that satisfies the following conditions.

𝑦
 is strictly less than 𝑥
.
There exists a non-degenerate triangle∗
 with side lengths 𝑥
, 𝑦
, 𝑥⊕𝑦
. Here, ⊕
 denotes the bitwise XOR operation.
Additionally, if there exists such an integer 𝑦
, output any.

∗
A triangle with side lengths 𝑎
, 𝑏
, 𝑐
 is non-degenerate when 𝑎+𝑏>𝑐
, 𝑎+𝑐>𝑏
, 𝑏+𝑐>𝑎
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤2000
). The description of the test cases follows.

The only line of each test case contains a single integer 𝑥
 (2≤𝑥≤109
).

Output
For each test case, print one integer on a separate line. The integer you must
output is as follows:

If there exists an integer 𝑦
 satisfying the conditions, output the value of 𝑦
 (1≤𝑦<𝑥
);
Otherwise, output −1
.
If there exist multiple integers that satisfy the conditions, you may output
any.

Example
InputCopy
7
5
2
6
3
69
4
420
OutputCopy
3
-1
5
-1
66
-1
320
Note
In the first test case, there exists a non-degenerate triangle with side lengths
3 , 5 , and 3⊕5=6 . Therefore, 𝑦=3 is a valid answer.

In the second test case, 1
 is the only possible candidate for 𝑦
, but it cannot make a non-degenerate triangle. Therefore, the answer is −1.
*/

// given x find a y such that x>y and x xor y is 3rd side of that
// triangle
// basically, we can use binary search to find y
// a,b,c triangle-> a+b>c,b+c>a,a+c>b
/*  for (int i = 1; i < x; i++) {
  int z = x ^ i; // Compute XOR result
  if (z > 0 && i + z > x && x + z > i && x + i > z) {
      cout << i << "\n";
      return;
  }
}

cout << "-1\n"; // No valid y found
// problem slow for large x
// but checking the conditions we find that, x < y + (x ^ y)
//put y=x-1 and checkfor a fallback if fails
//works except when x is a power of two.

if power of 2
just pick y = x-2 or y = x/2. One of them works.

if power of 2-> x-1
else -> x-2
*/
#include <bits/stdc++.h>

using namespace std;

#define fastIO                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);                                                              \
  cout.precision(numeric_limits<double>::max_digits10);

void CoderAbhi27() {
  int x;
  cin >> x;
  if (__builtin_popcountll(x) == 1) {
    cout << "-1\n";
    return;
  }
  int y = 0;
  int f1 = 0, f0 = 0;
  for (int i = 0; i <= 30; i++) {
    if (x & (1 << i)) {
      if (f1 == 0) {
        y |= 1 << i;
        f1 = 1;
      }
    } else {
      if (f0 == 0) {
        y |= 1 << i;
        f0 = 1;
      }
    }
  } // log(x)
  if (y < x) {
    cout << y << '\n';
  } else
    cout << "-1\n";
}

// tc : O(logx)
// sc : O(1)

int32_t main() {
  fastIO;

  int t = 1;
  cin >> t;
  while (t--) {
    CoderAbhi27();
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2074/338660735
