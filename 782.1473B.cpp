/*B. String LCM
time limit per test2 seconds
memory limit per test256 megabytes
Let's define a multiplication operation between a string 𝑎
 and a positive integer 𝑥
: 𝑎⋅𝑥
 is the string that is a result of writing 𝑥
 copies of 𝑎
 one after another. For example, "abc" ⋅ 2 =
 "abcabc", "a" ⋅ 5 =
 "aaaaa".

A string 𝑎
 is divisible by another string 𝑏
 if there exists an integer 𝑥
 such that 𝑏⋅𝑥=𝑎
. For example, "abababab" is divisible by "ab", but is not divisible by "ababab"
or "aa".

LCM of two strings 𝑠
 and 𝑡
 (defined as 𝐿𝐶𝑀(𝑠,𝑡)
) is the shortest non-empty string that is divisible by both 𝑠
 and 𝑡
.

You are given two strings 𝑠
 and 𝑡
. Find 𝐿𝐶𝑀(𝑠,𝑡)
 or report that it does not exist. It can be shown that if 𝐿𝐶𝑀(𝑠,𝑡)
 exists, it is unique.

Input
The first line contains one integer 𝑞
 (1≤𝑞≤2000
) — the number of test cases.

Each test case consists of two lines, containing strings 𝑠
 and 𝑡
 (1≤|𝑠|,|𝑡|≤20
). Each character in each of these strings is either 'a' or 'b'.

Output
For each test case, print 𝐿𝐶𝑀(𝑠,𝑡)
 if it exists; otherwise, print -1. It can be shown that if 𝐿𝐶𝑀(𝑠,𝑡)
 exists, it is unique.

Example
InputCopy
3
baba
ba
aa
aaa
aba
ab
OutputCopy
baba
aaaaaa
-1
Note
In the first test case, "baba" = "baba" ⋅ 1 =
 "ba" ⋅ 2
.

In the second test case, "aaaaaa" = "aa" ⋅ 3 =
 "aaa" ⋅ 2
.
*/
#include <bits/stdc++.h>
using namespace std;

string lcmString(const string &a, const string &b) {
  int n = a.size(), m = b.size();
  int l = lcm(n, m);

  string sa = "", sb = "";
  for (int i = 0; i < l / n; i++)
    sa += a;
  for (int i = 0; i < l / m; i++)
    sb += b;

  return (sa == sb) ? sa : "-1";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;
  while (q--) {
    string s, t;
    cin >> s >> t;
    cout << lcmString(s, t) << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1473/344622730
