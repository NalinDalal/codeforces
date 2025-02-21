/* A. Vlad and the Best of Five
time limit per test1 second
memory limit per test256 megabytes
Vladislav has a string of length 5, whose characters are each either 𝙰 or 𝙱.

Which letter appears most frequently: 𝙰 or 𝙱?

Input
The first line of the input contains an integer 𝑡 (1≤𝑡≤32) — the number of test
cases.

The only line of each test case contains a string of length 5 consisting of
letters 𝙰 and 𝙱.

All 𝑡 strings in a test are different (distinct).

Output
For each test case, output one letter (𝙰 or 𝙱) denoting the character that
appears most frequently in the string.

Example
InputCopy
8
ABABB
ABABA
BBBAB
AAAAA
BBBBB
BABAA
AAAAB
BAAAA
OutputCopy
B
A
B
A
B
A
A
A

*/

#include <iostream>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'A')
        count++;
      else if (s[i] == 'B')
        count--;
    }
    if (count > 0)
      cout << "A" << endl;
    else
      cout << "B" << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1926/307175229
