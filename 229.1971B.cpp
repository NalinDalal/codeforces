/*B. Different String
time limit per test1 second
memory limit per test256 megabytes
You are given a string 𝑠
 consisting of lowercase English letters.

Rearrange the characters of 𝑠
 to form a new string 𝑟
 that is not equal to 𝑠
, or report that it's impossible.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The only line of each test case contains a string 𝑠
 of length at most 10
 consisting of lowercase English letters.

Output
For each test case, if no such string 𝑟
 exists as described in the statement, output "NO" (without quotes).

Otherwise, output "YES" (without quotes). Then, output one line — the string 𝑟
, consisting of letters of string 𝑠
.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes",
and "Yes" will be recognized as a positive response).

If multiple answers are possible, you can output any of them.

Example
InputCopy
8
codeforces
aaaaa
xxxxy
co
d
nutdealer
mwistht
hhhhhhhhhh
OutputCopy
YES
forcodesec
NO
YES
xxyxx
YES
oc
NO
YES
undertale
YES
thtsiwm
NO
Note
In the first test case, another possible answer is 𝚏𝚘𝚛𝚌𝚎𝚜𝚌𝚘𝚍𝚎
.

In the second test case, all rearrangements of 𝚊𝚊𝚊𝚊𝚊
 are equal to 𝚊𝚊𝚊𝚊𝚊
.


*/

#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    bool diff = false;

    for (int p = 1; !diff && p < s.size(); p++) {
      if (s[p - 1] == s[p]) {
        continue;
      }
      char c = s[p - 1];
      s[p - 1] = s[p];
      s[p] = c;
      diff = true;
    }

    if (diff) {
      std::cout << "YES\n" << s << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
}
// sub: https://codeforces.com/problemset/submission/1971/310722075
