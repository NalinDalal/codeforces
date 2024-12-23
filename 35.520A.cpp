/* https://codeforces.com/problemset/problem/520/A

A. Pangram
time limit per test2 seconds
memory limit per test256 megabytes
A word or a sentence in some language is called a pangram if all the characters
of the alphabet of this language appear in it at least once. Pangrams are often
used to demonstrate fonts in printing or test the output devices.

You are given a string consisting of lowercase and uppercase Latin letters.
Check whether this string is a pangram. We say that the string contains a letter
of the Latin alphabet if this letter occurs in the string in uppercase or
lowercase.

Input
The first line contains a single integer n (1 ≤ n ≤ 100) — the number of
characters in the string.

The second line contains the string. The string consists only of uppercase and
lowercase Latin letters.

Output
Output "YES", if the string is a pangram and "NO" otherwise.

Examples
InputCopy
12
toosmallword
OutputCopy
NO
InputCopy
35
TheQuickBrownFoxJumpsOverTheLazyDog
OutputCopy
YES
*/

/* #include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  // bool flag = false;
  if (n < 26)
    cout << "NO";
  unordered_map<char, int> charCount;

  // Convert all characters to lowercase and populate the hashmap
  for (char c : s) {
    char lowerChar = tolower(c); // Convert to lowercase
    charCount[lowerChar]++;
  }

  // Check if all 26 letters of the alphabet are present
  for (char c = 'a'; c <= 'z'; c++) {
    if (charCount.find(c) == charCount.end()) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl; // All 26 letters are present
  return 0;
}*/

#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  if (n < 26) {
    cout << "NO" << endl; // Not enough characters to contain all letters
    return 0;
  }

  unordered_map<char, int> charCount;

  // Convert all characters to lowercase and populate the hashmap
  for (char c : s) {
    char lowerChar = tolower(c); // Convert to lowercase
    charCount[lowerChar]++;
  }

  // Check if all 26 letters of the alphabet are present
  for (char c = 'a'; c <= 'z'; c++) {
    if (charCount.find(c) == charCount.end()) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl; // All 26 letters are present
  return 0;
}
