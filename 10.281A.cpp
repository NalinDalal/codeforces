// link: https://codeforces.com/problemset/problem/281/A
// rating: 800
/* 281 A. Word Capitalization
time limit per test2 seconds
memory limit per test256 megabytes

Capitalization is writing a word with its first letter as a capital letter. Your
task is to capitalize the given word.

Note, that during capitalization all the letters except the first one
remainsunchanged.

Input A single line contains a non-empty word. This word consists of lowercase
and uppercase English letters. The length of the word will not exceed 10^3.

Output Output the given word after capitalization.

Examples:
Input: ApPLe
Output: ApPLe
Input: konjac
Output: Konjac
*/

// what to do:
// input a string s
// now we just need to capitalise the first letter of s
// so find first leter of s
// then check if it is lowercase or uppercase
// if lowercase, then subtract 32 to it
// if uppercase, return it

#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  cin >> s;

  if (s[0] >= 'a' && s[0] <= 'z') {
    s[0] = s[0] - 32;
  }
  cout << s;
  return 0;
}
