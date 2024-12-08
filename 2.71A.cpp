/*
link: https://codeforces.com/problemset/problem/71/A
800 - Rating



* A. Way Too Long Words
time limit per test1 second
memory limit per test256 megabytes
Sometimes some words like "localization" or "internationalization" are so long
that writing them many times in one text is quite tiresome.

Let's consider a word too long, if its length is strictly more than 10
characters. All too long words should be replaced with a special abbreviation.

This abbreviation is made like this: we write down the first and the last letter
of a word and between them we write the number of letters between the first and
the last letters. That number is in decimal system and doesn't contain any
leading zeroes.

Thus, "localization" will be spelt as "l10n", and "internationalization» will be
spelt as "i18n".

You are suggested to automatize the process of changing the words with
abbreviations. At that all too long words should be replaced by the abbreviation
and the words that are not too long should not undergo any changes.

Input
The first line contains an integer n (1 ≤ n ≤ 100). Each of the following n
lines contains one word. All the words consist of lowercase Latin letters and
possess the lengths of from 1 to 100 characters.

Output
Print n lines. The i-th line should contain the result of replacing of the i-th
word from the input data. */

// what to do:
// 1. read the input
// 2. check how many words are there, if greater than 10 then do following
// 3. split the words into 3 part, first char, last char and count the number of
// letter b/w them-> count-2
// 4. print like first+count-2+last

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; i++) {
    cin >> words[i];
  }
  for (int i = 0; i < n; i++) {
    if (words[i].length() > 10) {
      string first = words[i].substr(0, 1);
      string last = words[i].substr(words[i].length() - 1, 1);
      int count = words[i].length() - 2;
      cout << first << count << last << endl;
    } else {
      cout << words[i] << endl;
    }
  }
}
