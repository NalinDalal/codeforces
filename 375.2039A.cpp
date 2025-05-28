/*A. Shohag Loves Mod
time limit per test1 second
memory limit per test256 megabytes
Shohag has an integer 𝑛
. Please help him find an increasing integer sequence 1≤𝑎1<𝑎2<…<𝑎𝑛≤100
 such that 𝑎𝑖mod𝑖≠𝑎𝑗mod𝑗
 ∗
 is satisfied over all pairs 1≤𝑖<𝑗≤𝑛
.

It can be shown that such a sequence always exists under the given constraints.

∗
𝑎mod𝑏
 denotes the remainder of 𝑎
 after division by 𝑏
. For example, 7mod3=1,8mod4=0
 and 69mod10=9
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤50
) — the number of test cases.

The first and only line of each test case contains an integer 𝑛
 (2≤𝑛≤50
).

Output
For each test case, print 𝑛
 integers — the integer sequence that satisfies the conditions mentioned in the
statement. If there are multiple such sequences, output any.

Example
InputCopy
2
3
6
OutputCopy
2 7 8
2 3 32 35 69 95
Note
In the first test case, the sequence is increasing, values are from 1
 to 100
 and each pair of indices satisfies the condition mentioned in the statement:

For pair (1,2)
, 𝑎1mod1=2mod1=0
, and 𝑎2mod2=7mod2=1
. So they are different.
For pair (1,3)
, 𝑎1mod1=2mod1=0
, and 𝑎3mod3=8mod3=2
. So they are different.
For pair (2,3)
, 𝑎2mod2=7mod2=1
, and 𝑎3mod3=8mod3=2
. So they are different.
Note that you do not necessarily have to print the exact same sequence, you can
print any other sequence as long as it satisfies the necessary conditions.



*/
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
      cout << 2 * i - 1 << " ";
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2039/321831470
