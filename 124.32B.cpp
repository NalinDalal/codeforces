/* B. Borze
time limit per test2 seconds
memory limit per test256 megabytes
Ternary numeric notation is quite popular in Berland. To telegraph the ternary
number the Borze alphabet is used. Digit 0 is transmitted as «.», 1 as «-.» and
2 as «--». You are to decode the Borze code, i.e. to find out the ternary number
given its representation in Borze alphabet.

Input
The first line contains a number in Borze code. The length of the string is
between 1 and 200 characters. It's guaranteed that the given string is a valid
Borze code of some ternary number (this number can have leading zeroes).

Output
Output the decoded ternary number. It can have leading zeroes.

Examples
InputCopy
.-.--
OutputCopy
012
InputCopy
--.
OutputCopy
20
InputCopy
-..-.--
OutputCopy
1012
*/

#include <iostream>
#include <string>

using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  string ans;
  for (int i = 0; i < n; i++) {
    // 0 as .
    // 1 as -
    // 2 as --
    if (s[i] == '.')
      ans += '0';
    // well if creates problem, i got a feeling
    /*
else if (s[i] == '-.')
ans += '1';
else if (s[i] == '--')
ans += '2';
cout << ans << endl;
*/ else if (i + 1 < n && s[i] == '-' && s[i + 1] == '.') {
      ans += '1';
      i++; // Skip the next character as it's part of "-."
    } else if (i + 1 < n && s[i] == '-' && s[i + 1] == '-') {
      ans += '2';
      i++; // Skip the next character as it's part of "--"
    }
  }
  cout << ans << endl;
  return 0;
}
// sub: https://codeforces.com/problemset/submission/32/305718796
