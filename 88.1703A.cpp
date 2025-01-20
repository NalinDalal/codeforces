/* https://codeforces.com/problemset/problem/1703/A

A. YES or YES?

There is a string 𝑠 of length 3, consisting of uppercase and lowercase English
letters. Check if it is equal to "YES" (without quotes), where each letter can
be in any case. For example, "yES", "Yes", "yes" are all allowable.

Input
The first line of the input contains an integer 𝑡 (1≤𝑡≤103) — the number of
testcases.

The description of each test consists of one line containing one string 𝑠
consisting of three characters. Each character of 𝑠 is either an uppercase or
lowercase English letter.

Output
For each test case, output "YES" (without quotes) if 𝑠 satisfies the condition,
and "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yES", "yes" and
"Yes" will be recognized as a positive response).

Example
InputCopy
10
YES
yES
yes
Yes
YeS
Noo
orZ
yEz
Yas
XES
OutputCopy
YES
YES
YES
YES
YES
NO
NO
NO
NO
NO
Note
The first five test cases contain the strings "YES", "yES", "yes", "Yes", "YeS".
All of these are equal to "YES", where each character is either uppercase or
lowercase.


*/

#include <bits/stdc++.h>

using namespace std;

/*wrong; check word by word
* string solve(string s) {
  if (s.size() != 3) {
    cout << "NO" << endl;
    return "NO";
  }
  if (s == "YES" || s == "yES" || s == "Yes" || s == "yes") {
    cout << "YES" << endl;
    return "YES";
  } else {
    cout << "NO" << endl;
    return "NO";
  }
}*/
string solve(string s) {
  bool res(true);
  if (s[0] != 'Y' && s[0] != 'y') {
    res = false;
  }
  if (s[1] != 'E' && s[1] != 'e') {
    res = false;
  }
  if (s[2] != 'S' && s[2] != 's') {
    res = false;
  }
  std::cout << (res ? "YES" : "NO") << std::endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    solve(s);
  }
  return 0;
}

// sub: https://codeforces.com/contest/1703/submission/302130204
