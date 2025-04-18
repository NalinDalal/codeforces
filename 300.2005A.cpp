/* A. Simple Palindrome
time limit per test1 second
memory limit per test256 megabytes
Narek has to spend 2 hours with some 2-year-old kids at the kindergarten. He
wants to teach them competitive programming, and their first lesson is about
palindromes.

Narek found out that the kids only know the vowels of the English alphabet (the
letters 𝚊 , 𝚎 , 𝚒 , 𝚘 , and 𝚞
), so Narek needs to make a string that consists of vowels only. After making
the string, he'll ask the kids to count the number of subsequences that are
palindromes. Narek wants to keep it simple, so he's looking for a string such
that the amount of palindrome subsequences is minimal.

Help Narek find a string of length 𝑛
, consisting of lowercase English vowels only (letters 𝚊
, 𝚎
, 𝚒
, 𝚘
, and 𝚞
), which minimizes the amount of palindrome†
 subsequences‡
 in it.

†
 A string is called a palindrome if it reads the same from left to right and
from right to left.

‡
 String 𝑡
 is a subsequence of string 𝑠
 if 𝑡
 can be obtained from 𝑠
 by removing several (possibly, zero or all) characters from 𝑠
 and concatenating the remaining ones, without changing their order. For
example, 𝚘𝚍𝚘𝚌𝚜 is a subsequence of 𝚌𝚘𝚍𝚎𝚏𝚘𝚛𝚌𝚎𝚜
.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of test cases. Subsequently, the description of each test case
follows.

The only line of each test case contains a single integer 𝑛
 (1≤𝑛≤100
) — the size of the string.

Output
For each test case, output any string of length 𝑛
 that satisfies the above conditions.

Example
InputCopy
3
2
3
6
OutputCopy
uo
iae
oeiiua
Note
In the first example, 𝚞𝚘
 has only three palindrome subsequences: 𝚞
, 𝚘
, and the empty string. It can be shown that there is no better answer.

In the third example, 𝚘𝚎𝚒𝚒𝚞𝚊
 has only eight palindrome subsequences: 𝚘
, 𝚎
, 𝚒
, 𝚒
, 𝚞
, 𝚊
, 𝚒𝚒
, and the empty string. It can be shown that there is no better answer.



 */

#include <iostream>
#include <vector>

const std::string s = "aeiou";

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> v(5, n / 5);
    for (int p = 0; p < n % 5; p++) {
      v[p]++;
    }
    for (int p = 0; p < 5; p++) {
      for (int q = 0; q < v[p]; q++) {
        std::cout << s[p];
      }
    }
    std::cout << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2005/316051267
