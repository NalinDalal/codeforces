/*A. Serval and String Theory
time limit per test1 second
memory limit per test256 megabytes

A string 𝑟
 consisting only of lowercase Latin letters is called universal if and only if 𝑟
 is lexicographically smaller∗
 than the reversal†
 of 𝑟
.

You are given a string 𝑠
 consisting of 𝑛
 lowercase Latin letters. You are required to make 𝑠
 universal. To achieve this, you can perform the following operation on 𝑠
 at most 𝑘
 times:

Choose two indices 𝑖
 and 𝑗
 (1≤𝑖,𝑗≤𝑛
), then swap 𝑠𝑖
 and 𝑠𝑗
. Note that if 𝑖=𝑗
, you do nothing.
Determine whether you can make 𝑠
 universal by performing the above operation at most 𝑘
 times.

∗
A string 𝑎
 is lexicographically smaller than a string 𝑏
 of the same length, if and only if the following holds:

in the first position where 𝑎
 and 𝑏
 differ, the string 𝑎
 has a letter that appears earlier in the alphabet than the corresponding letter
in 𝑏
.
†
The reversal of a string 𝑟
 is the string obtained by writing 𝑟
 from right to left. For example, the reversal of the string 𝚊𝚋𝚌𝚊𝚍
 is 𝚍𝚊𝚌𝚋𝚊
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤100
, 0≤𝑘≤104
) — the length of the string 𝑠
, and the maximum number of operations you can perform.

The second line contains a string 𝑠
 consisting of 𝑛
 lowercase Latin letters.

Output
For each test case, print "YES" if it is possible to make 𝑠
 universal by performing the operation at most 𝑘
 times. Otherwise, print "NO".

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
8
1 10000
a
3 3
rev
6 0
string
6 0
theory
9 2
universal
19 0
codeforcesecrofedoc
19 1
codeforcesecrofedoc
3 1
zzz
OutputCopy
NO
YES
NO
YES
YES
NO
YES
NO
Note
In the first test case, 𝑠
 will keep the same after any operations. However, the reversal of 𝚊
 is still 𝚊
, so it is impossible to make 𝑠
 universal.

In the second test case, the string 𝚛𝚎𝚟
 is lexicographically smaller than 𝚟𝚎𝚛
. Thus, 𝑠
 is already universal.

In the fifth test case, you can perform the operations as follows:

Swap 𝑠4
 and 𝑠7
. After this operation, 𝑠
 becomes 𝚞𝚗𝚒𝚜𝚎𝚛𝚟𝚊𝚕
;
Swap 𝑠1
 and 𝑠3
. After this operation, 𝑠
 becomes 𝚒𝚗𝚞𝚜𝚎𝚛𝚟𝚊𝚕
.
And the string 𝚒𝚗𝚞𝚜𝚎𝚛𝚟𝚊𝚕
 is universal.


*/

#include <algorithm>
#include <iostream>
#include <string>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;
    std::string t(s);
    std::reverse(t.begin(), t.end());

    bool res = (s < t);
    bool diff = false;
    for (int p = 1; !res && k && !diff && p < s.size(); p++) {
      if (s[p - 1] != s[p]) {
        diff = true;
      }
    }
    if (k && diff) {
      res = true;
    }

    std::cout << (res ? "YES" : "NO") << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2085/312760360
