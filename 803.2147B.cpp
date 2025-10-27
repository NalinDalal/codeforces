/*B. Multiple Construction
time limit per test1 second
memory limit per test256 megabytes
You are given an integer 𝑛
. Your task is to construct an array of length 2⋅𝑛
 such that:

Each integer from 1
 to 𝑛
 appears exactly twice in the array.
For each integer 𝑥
 (1≤𝑥≤𝑛
), the distance between the two occurrences of 𝑥
 is a multiple of 𝑥
. In other words, if 𝑝𝑥
 and 𝑞𝑥
 are the indices of the two occurrences of 𝑥
, |𝑞𝑥−𝑝𝑥|
 must be divisible by 𝑥
.
It can be shown that a solution always exists.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

Each of the next 𝑡
 lines contains a single integer 𝑛
 (1≤𝑛≤2⋅105
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a line containing 2⋅𝑛
 integers — the array that satisfies the given conditions.

If there are multiple valid answers, print any of them.

Example
InputCopy
3
2
3
1
OutputCopy
1 2 1 2
1 3 1 2 3 2
1 1
Note
[Visualizer
link](https://codeforces.com/assets/contests/2147/B_RlbLXHyL5DuDqDlx4DG1.html)

In the first test case:

The number 1
 appears at positions 1
 and 3
: the distance is 2
, which is divisible by 1
.
The number 2
 appears at positions 2
 and 4
: the distance is 2
, which is divisible by 2
.
In the second test case:

The number 1
 appears at positions 1
 and 3
: the distance is 2
, which is divisible by 1
.
The number 2
 appears at positions 4
 and 6
: the distance is 2
, which is divisible by 2
.
The number 3
 appears at positions 2
 and 5
: the distance is 3
, which is divisible by 3
.
In the third test case, the two occurrences of 1
 are at positions 1
 and 2
, so the distance between them is 1
, which is a multiple of 1
.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;

    // First descending sequence: n, n-1, ..., 1
    for (long p = 0; p < n; p++) {
      cout << (n - p) << " ";
    }

    // Then one more 'n'
    cout << n << " ";

    // Then ascending sequence: 1, 2, ..., n-1
    for (long p = 1; p < n; p++) {
      cout << p << " ";
    }

    cout << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2147/346061413
