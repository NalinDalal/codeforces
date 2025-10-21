/*E. 2-Letter Strings
time limit per test2 seconds
memory limit per test256 megabytes
Given 𝑛
 strings, each of length 2
, consisting of lowercase Latin alphabet letters from 'a' to 'k', output the
number of pairs of indices (𝑖,𝑗) such that 𝑖<𝑗 and the 𝑖 -th string and the 𝑗
-th string differ in exactly one position.

In other words, count the number of pairs (𝑖,𝑗)
 (𝑖<𝑗
) such that the 𝑖
-th string and the 𝑗
-th string have exactly one position 𝑝
 (1≤𝑝≤2
) such that 𝑠𝑖𝑝≠𝑠𝑗𝑝
.

The answer may not fit into 32-bit integer type, so you should use 64-bit
integers like long long in C++ to avoid integer overflow.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤105
) — the number of strings.

Then follows 𝑛
 lines, the 𝑖
-th of which containing a single string 𝑠𝑖
 of length 2
, consisting of lowercase Latin letters from 'a' to 'k'.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, print a single integer — the number of pairs (𝑖,𝑗)
 (𝑖<𝑗
) such that the 𝑖
-th string and the 𝑗
-th string have exactly one position 𝑝
 (1≤𝑝≤2
) such that 𝑠𝑖𝑝≠𝑠𝑗𝑝
.

Please note, that the answer for some test cases won't fit into 32-bit integer
type, so you should use at least 64-bit integer type in your programming
language (like long long for C++).

Example
InputCopy
4
6
ab
cb
db
aa
cc
ef
7
aa
bb
cc
ac
ca
bb
aa
4
kk
kk
ab
ab
5
jf
jf
jk
jk
jk
OutputCopy
5
6
0
6
Note
For the first test case the pairs that differ in exactly one position are:
("ab", "cb"), ("ab", "db"), ("ab", "aa"), ("cb", "db") and ("cb", "cc").

For the second test case the pairs that differ in exactly one position are:
("aa", "ac"), ("aa", "ca"), ("cc", "ac"), ("cc", "ca"), ("ac", "aa") and ("ca",
"aa").

For the third test case, the are no pairs satisfying the conditions.
*/

#include <iostream>
#include <string>
#include <vector>
typedef long long ll;

int main() {
  const int B = 12;
  ll t;
  std::cin >> t;

  while (t--) {
    ll n;
    std::cin >> n;

    // Initialize 12x12 matrix
    std::vector<std::vector<ll>> m(B, std::vector<ll>(B, 0));

    // Read strings and count occurrences
    for (ll i = 0; i < n; ++i) {
      std::string s;
      std::cin >> s;
      ++m[s[0] - 'a'][s[1] - 'a'];
    }

    // Row sums and column sums
    std::vector<ll> rowSum(B, 0), colSum(B, 0);
    for (int r = 0; r < B; ++r) {
      for (int c = 0; c < B; ++c) {
        rowSum[r] += m[r][c];
        colSum[c] += m[r][c];
      }
    }

    // Compute total pairs
    ll total = 0;
    for (int r = 0; r < B; ++r) {
      for (int c = 0; c < B; ++c) {
        total += m[r][c] * (rowSum[r] - m[r][c]);
        total += m[r][c] * (colSum[c] - m[r][c]);
      }
    }

    std::cout << (total / 2) << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1669/344996895
