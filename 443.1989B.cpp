/*B. Substring and Subsequence
time limit per test2 seconds
memory limit per test256 megabytes
You are given two strings 𝑎
 and 𝑏
, both consisting of lowercase Latin letters.

A subsequence of a string is a string which can be obtained by removing several
(possibly zero) characters from the original string. A substring of a string is
a contiguous subsequence of that string.

For example, consider the string abac:

a, b, c, ab, aa, ac, ba, bc, aba, abc, aac, bac and abac are its subsequences;
a, b, c, ab, ba, ac, aba, bac and abac are its substrings.
Your task is to calculate the minimum possible length of the string that
contains 𝑎 as a substring and 𝑏 as a subsequence.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤103
) — the number of test cases.

The first line of each test case contains a string 𝑎
 (1≤|𝑎|≤100
), consisting of lowercase Latin letters.

The second line of each test case contains a string 𝑏
 (1≤|𝑏|≤100
), consisting of lowercase Latin letters.

Output
For each test case, print a single integer — the minimum possible length of the
string that contains 𝑎 as a substring and 𝑏 as a subsequence.

Example
InputCopy
5
aba
cb
er
cf
mmm
mmm
contest
test
cde
abcefg
OutputCopy
4
4
3
7
7
Note
In the examples below, the characters that correspond to the subsequence equal
to 𝑏 are bolded.

In the first example, one of the possible answers is caba.

In the second example, one of the possible answers is ercf.

In the third example, one of the possible answers is mmm.

In the fourth example, one of the possible answers is contest.

In the fifth example, one of the possible answers is abcdefg.
*/

#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);

  long t;
  std::cin >> t;
  while (t--) {
    std::string a;
    std::cin >> a;
    std::string b;
    std::cin >> b;
    long cnt(a.size() + b.size());

    for (long start = 0; start < b.size(); start++) {
      long idx = start;
      for (int p = 0; p < a.size(); p++) {
        if (idx < b.size() && a[p] == b[idx]) {
          ++idx;
        }
      }
      long total = a.size() + start + (b.size() - idx);
      cnt = (cnt < total ? cnt : total);
    }
    std::cout << cnt << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1989/325831860
