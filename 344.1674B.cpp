/*B. Dictionary
time limit per test2 seconds
memory limit per test512 megabytes
The Berland language consists of words having exactly two letters. Moreover, the
first letter of a word is different from the second letter. Any combination of
two different Berland letters (which, by the way, are the same as the lowercase
letters of Latin alphabet) is a correct word in Berland language.

The Berland dictionary contains all words of this language. The words are listed
in a way they are usually ordered in dictionaries. Formally, word 𝑎 comes
earlier than word 𝑏 in the dictionary if one of the following conditions hold:

the first letter of 𝑎
 is less than the first letter of 𝑏
;
the first letters of 𝑎
 and 𝑏
 are the same, and the second letter of 𝑎
 is less than the second letter of 𝑏
.
So, the dictionary looks like that:

Word 1
: ab
Word 2
: ac
...
Word 25
: az
Word 26
: ba
Word 27
: bc
...
Word 649
: zx
Word 650
: zy
You are given a word 𝑠
 from the Berland language. Your task is to find its index in the dictionary.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤650
) — the number of test cases.

Each test case consists of one line containing 𝑠
 — a string consisting of exactly two different lowercase Latin letters (i. e. a
correct word of the Berland language).

Output
For each test case, print one integer — the index of the word 𝑠
 in the dictionary.

Example
InputCopy
7
ab
ac
az
ba
bc
zx
zy
OutputCopy
1
2
25
26
27
649
650
*/

#include <iostream>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    long res = 1 + 25 * (s[0] - 'a') + (s[1] - 'a') - (s[1] > s[0]);
    std::cout << res << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/1674/319472510
