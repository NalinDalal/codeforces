/*B. Replace Character
time limit per test1 second
memory limit per test256 megabytes
You're given a string 𝑠
 of length 𝑛
, consisting of only lowercase English letters.

You must do the following operation exactly once:

Choose any two indices 𝑖
 and 𝑗
 (1≤𝑖,𝑗≤𝑛
). You can choose 𝑖=𝑗
.
Set 𝑠𝑖:=𝑠𝑗
.
You need to minimize the number of distinct permutations†
 of 𝑠
. Output any string with the smallest number of distinct permutations after
performing exactly one operation.

†
 A permutation of the string is an arrangement of its characters into any order.
For example, "bac" is a permutation of "abc" but "bcc" is not.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

The first line of each test case contains 𝑛
 (1≤𝑛≤10
) — the length of string 𝑠
.

The second line of each test case contains 𝑠
 of length 𝑛
. The string contains only lowercase English letters.

Output
For each test case, output the required 𝑠
 after applying exactly one operation. If there are multiple solutions, print
any of them.

Example
InputCopy
6
3
abc
4
xyyx
8
alphabet
1
k
10
aabbccddee
6
ttbddq
OutputCopy
cbc
yyyx
alphaaet
k
eabbccddee
tttddq
Note
In the first test case, we can obtain the following strings in one operation:
"abc", "bbc", "cbc", "aac", "acc", "aba", and "abb".

The string "abc" has 6
 distinct permutations: "abc", "acb", "bac", "bca", "cab", and "cba".

The string "cbc" has 3
 distinct permutations: "bcc", "cbc", and "ccb", which is the lowest of all the
obtainable strings. In fact, all obtainable strings except "abc" have 3
 permutations, so any of them would be accepted.




*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int B = 26;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int v[B] = {0};
    for (int p = 0; p < s.size(); p++) {
      ++v[s[p] - 'a'];
    }
    int mn(s.size()), mx(0);
    char mnc(' '), mxc(' ');
    for (int p = 0; p < B; p++) {
      if (!v[p]) {
        continue;
      }
      if (v[p] < mn) {
        mn = v[p];
        mnc = ('a' + p);
      }
      if (v[p] >= mx) {
        mx = v[p];
        mxc = ('a' + p);
      }
    }

    for (int p = 0; p < s.size(); p++) {
      if (s[p] == mnc) {
        s[p] = mxc;
        break;
      }
    }
    std::cout << s << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2047/312133724
