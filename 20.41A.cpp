/* A. Translation
time limit per test1 second
memory limit per test256 megabytes
The translation from the Berland language into the Birland language is not an
easy task. Those languages are very similar: a Berlandish word differs from a
Birlandish word with the same meaning a little: it is spelled (and pronounced)
reversely. For example, a Berlandish word code corresponds to a Birlandish word
edoc. However, making a mistake during the "translation" is easy. Vasya
translated the word s from Berlandish into Birlandish as t. Help him: find out
if he translated the word correctly.

Input
The first line contains word s, the second line contains word t. The words
consist of lowercase Latin letters. The input data do not contain unnecessary
spaces. The words are not empty and their lengths do not exceed 100 symbols.

Output
If the word t is a word s, written reversely, print YES, otherwise print NO.

Examples
Input
code
edoc
Output
YES

Input
abb
aba
Output
NO

Input
code
code
Output
NO
*/

// input the word s and t
// now reverse word t
// check it linearly with word s
// if it is equal, print YES
// else NO

#include <iostream>
#include <string>

using namespace std;

int main() {
  string s, t;
  cin >> s;
  cin >> t;

  int n = s.length();
  int m = t.length();

  // If the lengths are different, immediately print NO
  if (n != m) {
    cout << "NO";
    return 0;
  }

  // Check if the reversed string t matches s
  for (int i = 0; i < n; i++) {
    if (s[i] != t[n - i - 1]) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
  return 0;
}
