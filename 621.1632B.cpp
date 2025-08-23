/*B. Roof Construction
time limit per test1 second
memory limit per test256 megabytes
It has finally been decided to build a roof over the football field in School
179. Its construction will require placing 𝑛 consecutive vertical pillars.
Furthermore, the headmaster wants the heights of all the pillars to form a
permutation 𝑝 of integers from 0 to 𝑛−1 , where 𝑝𝑖 is the height of the 𝑖 -th
pillar from the left (1≤𝑖≤𝑛)
.

As the chief, you know that the cost of construction of consecutive pillars is
equal to the maximum value of the bitwise XOR of heights of all pairs of
adjacent pillars. In other words, the cost of construction is equal to
max1≤𝑖≤𝑛−1𝑝𝑖⊕𝑝𝑖+1 , where ⊕ denotes the bitwise XOR operation.

Find any sequence of pillar heights 𝑝
 of length 𝑛
 with the smallest construction cost.

In this problem, a permutation is an array consisting of 𝑛
 distinct integers from 0
 to 𝑛−1
 in arbitrary order. For example, [2,3,1,0,4]
 is a permutation, but [1,0,1]
 is not a permutation (1
 appears twice in the array) and [1,0,3]
 is also not a permutation (𝑛=3
, but 3
 is in the array).

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). Description of the test cases follows.

The only line for each test case contains a single integer 𝑛
 (2≤𝑛≤2⋅105
) — the number of pillars for the construction of the roof.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case print 𝑛
 integers 𝑝1
, 𝑝2
, …
, 𝑝𝑛
 — the sequence of pillar heights with the smallest construction cost.

If there are multiple answers, print any of them.

Example
InputCopy
4
2
3
5
10
OutputCopy
0 1
2 0 1
3 2 1 0 4
4 6 3 2 0 8 9 1 7 5
Note
For 𝑛=2
 there are 2
 sequences of pillar heights:

[0,1]
 — cost of construction is 0⊕1=1
.
[1,0]
 — cost of construction is 1⊕0=1
.
For 𝑛=3
 there are 6
 sequences of pillar heights:

[0,1,2]
 — cost of construction is max(0⊕1,1⊕2)=max(1,3)=3
.
[0,2,1]
 — cost of construction is max(0⊕2,2⊕1)=max(2,3)=3
.
[1,0,2]
 — cost of construction is max(1⊕0,0⊕2)=max(1,2)=2
.
[1,2,0]
 — cost of construction is max(1⊕2,2⊕0)=max(3,2)=3
.
[2,0,1]
 — cost of construction is max(2⊕0,0⊕1)=max(2,1)=2
.
[2,1,0]
 — cost of construction is max(2⊕1,1⊕0)=max(3,1)=3
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

    long k = 0;
    while ((1L << (k + 1)) <= n - 1) {
      ++k;
    }

    for (long p = (1L << k) - 1; p >= 0; --p) {
      cout << p << " ";
    }
    for (long p = (1L << k); p < n; ++p) {
      cout << p << " ";
    }
    cout << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1632/335142531
