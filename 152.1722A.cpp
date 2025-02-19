/* A. Spell Check
time limit per test1 second
memory limit per test256 megabytes
Timur likes his name. As a spelling of his name, he allows any permutation of
the letters of the name. For example, the following strings are valid spellings
of his name: Timur, miurT, Trumi, mriTu. Note that the correct spelling must
have uppercased T and lowercased other letters.

Today he wrote string 𝑠 of length 𝑛 consisting only of uppercase or lowercase
Latin letters. He asks you to check if 𝑠 is the correct spelling of his name.

Input
The first line of the input contains an integer 𝑡 (1≤𝑡≤103) — the number of test
cases.

The first line of each test case contains an integer 𝑛 (1≤𝑛≤10) — the length of
string 𝑠.

The second line of each test case contains a string 𝑠 consisting of only
uppercase or lowercase Latin characters.

Output
For each test case, output "YES" (without quotes) if 𝑠 satisfies the condition,
and "NO" (without quotes) otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes",
"Yes" and "YES" will be recognized as a positive answer).

Example
InputCopy
10
5
Timur
5
miurT
5
Trumi
5
mriTu
5
timur
4
Timr
6
Timuur
10
codeforces
10
TimurTimur
5
TIMUR
OutputCopy
YES
YES
YES
YES
NO
NO
NO
NO
NO
NO

*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool Spell_Check(string s, string check) {
  sort(check.begin(), check.end());
  sort(s.begin(), s.end());
  return s == check; // Directly compare sorted strings
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string check = "Timur";
    if (n != 5) {
      cout << "NO" << endl;
      continue;
    }
    if (Spell_Check(s, check))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1722/306901073
