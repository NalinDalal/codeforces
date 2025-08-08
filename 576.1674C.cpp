/*C. Infinite Replacement
time limit per test2 seconds
memory limit per test256 megabytes
You are given a string 𝑠
, consisting only of Latin letters 'a', and a string 𝑡
, consisting of lowercase Latin letters.

In one move, you can replace any letter 'a' in the string 𝑠
 with a string 𝑡
. Note that after the replacement string 𝑠
 might contain letters other than 'a'.

You can perform an arbitrary number of moves (including zero). How many
different strings can you obtain? Print the number, or report that it is
infinitely large.

Two strings are considered different if they have different length, or they
differ at some index.

Input
The first line contains a single integer 𝑞
 (1≤𝑞≤104
) — the number of testcases.

The first line of each testcase contains a non-empty string 𝑠
, consisting only of Latin letters 'a'. The length of 𝑠
 doesn't exceed 50
.

The second line contains a non-empty string 𝑡
, consisting of lowercase Latin letters. The length of 𝑡
 doesn't exceed 50
.

Output
For each testcase, print the number of different strings 𝑠
 that can be obtained after an arbitrary amount of moves (including zero). If
the number is infinitely large, print -1. Otherwise, print the number.

Example
InputCopy
3
aaaa
a
aa
abc
a
b
OutputCopy
1
-1
2
Note
In the first example, you can replace any letter 'a' with the string "a", but
that won't change the string. So no matter how many moves you make, you can't
obtain a string other than the initial one.

In the second example, you can replace the second let[48;56;204;1792;2856tter
'a' with "abc". String 𝑠 becomes equal to "aabc". Then the second letter 'a'
again. String 𝑠 becomes equal to "aabcbc". And so on, generating infinitely many
different strings.

In the third example, you can either leave string 𝑠
 as is, performing zero moves, or replace the only 'a' with "b". String 𝑠
 becomes equal to "b", so you can't perform more moves on it.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s;
    cin >> t;
    if (t == "a") {
      cout << 1 << '\n';
    } else if (t.find('a') != string::npos) {
      cout << -1 << '\n'; // 'a' exists in t and t != "a"
    } else {
      int n = s.size();
      cout << (1LL << n) << '\n'; // 2^n distinct combinations
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1674/332954618
