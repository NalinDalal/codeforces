/* A. Square String?
time limit per test1 second
memory limit per test256 megabytes
A string is called square if it is some string written twice in a row. For
example, the strings "aa", "abcabc", "abab" and "baabaa" are square. But the
strings "aaa", "abaaab" and "abcdabc" are not square.

For a given string 𝑠 determine if it is square.

Input
The first line of input data contains an integer 𝑡 (1≤𝑡≤100) —the number of test
cases.

This is followed by 𝑡 lines, each containing a description of one test case. The
given strings consist only of lowercase Latin letters and have lengths between 1
and 100 inclusive.

Output
For each test case, output on a separate line:
YES if the string in the corresponding test case is square,
NO otherwise.
You can output YES and NO in any case (for example, strings yEs, yes, Yes and
YES will be recognized as a positive response).

Example
InputCopy
10
a
aa
aaa
aaaa
abab
abcabc
abacaba
xxyy
xyyx
xyxy
OutputCopy
NO
YES
NO
YES
YES
YES
NO
NO
NO
YES*/

#include <iostream>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() % 2) {
      std::cout << "NO" << std::endl;
      continue;
    }
    int h = s.size() / 2;
    bool flag = true;
    for (int i = 0; i < h; i++) {
      if (s[i] != s[h + i]) {
        flag = false;
        break;
      }
    }
    std::cout << (flag ? "YES" : "NO") << std::endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1619/306776686
