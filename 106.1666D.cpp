/* https://codeforces.com/problemset/problem/1666/D

D. Deletive Editing

Daisy loves playing games with words. Recently, she has been playing the
following Deletive Editing word game with Daniel.

Daisy picks a word, for example, "DETERMINED". On each game turn, Daniel calls
out a letter, for example, 'E', and Daisy removes the first occurrence of this
letter from the word, getting "DTERMINED". On the next turn, Daniel calls out a
letter again, for example, 'D', and Daisy removes its first occurrence, getting
"TERMINED". They continue with 'I', getting "TERMNED", with 'N', getting
"TERMED", and with 'D', getting "TERME". Now, if Daniel calls out the letter
'E', Daisy gets "TRME", but there is no way she can get the word "TERM" if they
start playing with the word "DETERMINED".

Daisy is curious if she can get the final word of her choice, starting from the
given initial word, by playing this game for zero or more turns. Your task it
help her to figure this out.

Input
The first line of the input contains an integer 𝑛 — the number of test cases
(1≤𝑛≤10000). The following 𝑛 lines contain test cases.

Each test case consists of two words 𝑠 and 𝑡 separated by a space. Each word
consists of at least one and at most 30 uppercase English letters; 𝑠 is the
Daisy's initial word for the game; 𝑡 is the final word that Daisy would like to
get at the end of the game.

Output
Output 𝑛 lines to the output — a single line for each test case.
Output "YES" if it is possible for Daisy to get from the initial word 𝑠 to the
final word 𝑡 by playing the Deletive Editing game. Output "NO" otherwise.

Example
InputCopy
6
DETERMINED TRME
DETERMINED TERM
PSEUDOPSEUDOHYPOPARATHYROIDISM PEPA
DEINSTITUTIONALIZATION DONATION
CONTEST CODE
SOLUTION SOLUTION

OutputCopy
YES
NO
NO
YES
NO
YES
*/

#include <iostream>
#include <vector>

using namespace std;

bool solution(string s, string t) {
  vector<bool> used(26, false); // Track used letters
  int idx = t.size() - 1;       // Pointer for `to` string

  for (int p = s.size() - 1; p >= 0; p--) {
    if (s[p] == t[idx]) {
      if (!used[s[p] - 'A']) {
        idx--; // Match found, move pointer
      } else {
        return false; // If letter is already used incorrectly
      }
    } else {
      used[s[p] - 'A'] = true; // Mark letter as used
    }
  }
  return idx < 0; // If all characters in `to` are matched
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;

    // print yes if it is possible to convert s into t
    if (solution(s, t)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1666/303484343
