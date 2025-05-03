/* A. ABC String
time limit per test2 seconds
memory limit per test256 megabytes
You are given a string 𝑎
, consisting of 𝑛
 characters, 𝑛
 is even. For each 𝑖
 from 1
 to 𝑛
 𝑎𝑖
 is one of 'A', 'B' or 'C'.

A bracket sequence is a string containing only characters "(" and ")". A regular
bracket sequence is a bracket sequence that can be transformed into a correct
arithmetic expression by inserting characters "1" and "+" between the original
characters of the sequence. For example, bracket sequences "()()" and "(())" are
regular (the resulting expressions are: "(1)+(1)" and "((1+1)+1)"), and ")(",
"(" and ")" are not.

You want to find a string 𝑏
 that consists of 𝑛
 characters such that:

𝑏
 is a regular bracket sequence;
if for some 𝑖
 and 𝑗
 (1≤𝑖,𝑗≤𝑛
) 𝑎𝑖=𝑎𝑗
, then 𝑏𝑖=𝑏𝑗
.
In other words, you want to replace all occurrences of 'A' with the same type of
bracket, then all occurrences of 'B' with the same type of bracket and all
occurrences of 'C' with the same type of bracket.

Your task is to determine if such a string 𝑏
 exists.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of testcases.

Then the descriptions of 𝑡
 testcases follow.

The only line of each testcase contains a string 𝑎
. 𝑎
 consists only of uppercase letters 'A', 'B' and 'C'. Let 𝑛
 be the length of 𝑎
. It is guaranteed that 𝑛
 is even and 2≤𝑛≤50
.

Output
For each testcase print "YES" if there exists such a string 𝑏
 that:

𝑏
 is a regular bracket sequence;
if for some 𝑖
 and 𝑗
 (1≤𝑖,𝑗≤𝑛
) 𝑎𝑖=𝑎𝑗
, then 𝑏𝑖=𝑏𝑗
.
Otherwise, print "NO".

You may print every letter in any case you want (so, for example, the strings
yEs, yes, Yes and YES are all recognized as positive answer).

Example
InputCopy
4
AABBAC
CACA
BBBBAC
ABCA
OutputCopy
YES
YES
NO
NO
Note
In the first testcase one of the possible strings 𝑏
 is "(())()".

In the second testcase one of the possible strings 𝑏
 is "()()".


*/
#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string a;
    cin >> a;
    int n = a.length();
    string res = "NO";

    // Try all 8 possible mappings of A, B, C to '(' or ')'
    for (int mask = 0; mask < 8; ++mask) {
      int f[3];
      for (int i = 0; i < 3; ++i) {
        f[i] = (mask & (1 << i)) ? 1 : -1; // 1 for '(', -1 for ')'
      }

      int cnt = 0;
      bool valid = true;
      for (char c : a) {
        cnt += f[c - 'A'];
        if (cnt < 0) {
          valid = false;
          break;
        }
      }
      if (cnt != 0)
        valid = false;

      if (valid) {
        res = "YES";
        break;
      }
    }

    cout << res << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1494/318176689
