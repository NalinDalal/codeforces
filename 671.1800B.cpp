/*B. Count the Number of Pairs
time limit per test2 seconds
memory limit per test256 megabytes
Kristina has a string 𝑠
 of length 𝑛
, consisting only of lowercase and uppercase Latin letters. For each pair of
lowercase letter and its matching uppercase letter, Kristina can get 1 burl.
However, pairs of characters cannot overlap, so each character can only be in
one pair.

For example, if she has the string 𝑠
 = "aAaaBACacbE", she can get a burl for the following character pairs:

𝑠1
 = "a" and 𝑠2
 = "A"
𝑠4
 = "a" and 𝑠6
 = "A"
𝑠5
 = "B" and 𝑠10
 = "b"
𝑠7
= "C" and 𝑠9
 = "c"
Kristina wants to get more burles for her string, so she is going to perform no
more than 𝑘 operations on it. In one operation, she can:

either select the lowercase character 𝑠𝑖
 (1≤𝑖≤𝑛
) and make it uppercase.
or select uppercase character 𝑠𝑖
 (1≤𝑖≤𝑛
) and make it lowercase.
For example, when 𝑘
 = 2 and 𝑠
 = "aAaaBACacbE" it can perform one operation: choose 𝑠3
 = "a" and make it uppercase. Then she will get another pair of 𝑠3
 = "A" and 𝑠8
 = "a"

Find maximum number of burles Kristina can get for her string.

Input
The first line of input data contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 (1≤𝑛≤2⋅105
) and 𝑘
 (0≤𝑘≤𝑛
) — the number of characters in the string and the maximum number of operations
that can be performed on it.

The second line of each test case contains a string 𝑠
 of length 𝑛
, consisting only of lowercase and uppercase Latin letters.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print exactly one integer on a separate line: the maximum
number of burles that Kristina can get for her string 𝑠
.

Example
InputCopy
5
11 2
aAaaBACacbE
2 2
ab
4 1
aaBB
6 0
abBAcC
5 3
cbccb
OutputCopy
5
0
1
3
2
Note
The first test case is explained in the problem statement.

In the second test case, it is not possible to get any pair by performing any
number of operations.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    // n is string size, k is max opr allow
    string s;
    cin >> s;

    // 1 burle when 2 pair of lowercase and uppercase
    // perform only k operation
    // operation ->either s[i] to uppercase or s[i] to lowercase
    // count lowercase and uppercase for each char
    // then find the pairs without any operation : `pairs = min(lower[i],
    // upper[i])` extra pairs: `extra = min(k, (lower[i] + upper[i]) / 2)`
    // reduce k accordingly

    vector<int> lower(26, 0), upper(26, 0);

    // count lowercase and uppercase for each char
    for (char c : s) {
      if (islower(c))
        lower[c - 'a']++;
      else
        upper[c - 'A']++;
    }
    int ans = 0;
    // ans is max no of burles from string s
    for (int i = 0; i < 26; i++) {
      // natural pairs - pairs without any operation
      int natural = min(lower[i], upper[i]);
      ans += natural;
      lower[i] -= natural;
      upper[i] -= natural;

      // use operations for leftovers
      int leftover = lower[i] + upper[i];
      int extra = min(k, leftover / 2);
      ans += extra;
      k -= extra;
    }
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1800/337696574
