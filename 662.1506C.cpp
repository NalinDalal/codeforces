/*C. Double-ended Strings
time limit per test2 seconds
memory limit per test256 megabytes
You are given the strings 𝑎
 and 𝑏
, consisting of lowercase Latin letters. You can do any number of the following
operations in any order:

if |𝑎|>0
 (the length of the string 𝑎
 is greater than zero), delete the first character of the string 𝑎
, that is, replace 𝑎
 with 𝑎2𝑎3…𝑎𝑛
;
if |𝑎|>0
, delete the last character of the string 𝑎
, that is, replace 𝑎
 with 𝑎1𝑎2…𝑎𝑛−1
;
if |𝑏|>0
 (the length of the string 𝑏
 is greater than zero), delete the first character of the string 𝑏
, that is, replace 𝑏
 with 𝑏2𝑏3…𝑏𝑛
;
if |𝑏|>0
, delete the last character of the string 𝑏
, that is, replace 𝑏
 with 𝑏1𝑏2…𝑏𝑛−1
.
Note that after each of the operations, the string 𝑎
 or 𝑏
 may become empty.

For example, if 𝑎=
"hello" and 𝑏=
"icpc", then you can apply the following sequence of operations:

delete the first character of the string 𝑎
 ⇒
 𝑎=
"ello" and 𝑏=
"icpc";
delete the first character of the string 𝑏
 ⇒
 𝑎=
"ello" and 𝑏=
"cpc";
delete the first character of the string 𝑏
 ⇒
 𝑎=
"ello" and 𝑏=
"pc";
delete the last character of the string 𝑎
 ⇒
 𝑎=
"ell" and 𝑏=
"pc";
delete the last character of the string 𝑏
 ⇒
 𝑎=
"ell" and 𝑏=
"p".
For the given strings 𝑎
 and 𝑏
, find the minimum number of operations for which you can make the strings 𝑎
 and 𝑏
 equal. Note that empty strings are also equal.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤100
). Then 𝑡
 test cases follow.

The first line of each test case contains the string 𝑎
 (1≤|𝑎|≤20
), consisting of lowercase Latin letters.

The second line of each test case contains the string 𝑏
 (1≤|𝑏|≤20
), consisting of lowercase Latin letters.

Output
For each test case, output the minimum number of operations that can make the
strings 𝑎 and 𝑏 equal.

Example
InputCopy
5
a
a
abcd
bc
hello
codeforces
hello
helo
dhjakjsnasjhfksafasd
adjsnasjhfksvdafdser
OutputCopy
0
2
13
3
20
*/

#include <algorithm>
#include <iostream>
#include <string>

int main() {
  long t;
  std::cin >> t;

  while (t--) {
    std::string a, b;
    std::cin >> a >> b;

    long max_common = 0;

    for (size_t i = 0; i < a.size(); i++) {
      for (size_t j = 0; j < b.size(); j++) {
        size_t k = 0;
        while (i + k < a.size() && j + k < b.size() && a[i + k] == b[j + k]) {
          max_common = std::max(max_common, static_cast<long>(k + 1));
          k++;
        }
      }
    }

    long ans = a.size() + b.size() - 2 * max_common;
    std::cout << ans << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1506/337091381
