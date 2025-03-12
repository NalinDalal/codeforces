/*B. Normal Problem
time limit per test1 second
memory limit per test256 megabytes
A string consisting of only characters 'p', 'q', and 'w' is painted on a glass
window of a store. Ship walks past the store, standing directly in front of the
glass window, and observes string 𝑎 . Ship then heads inside the store, looks
directly at the same glass window, and observes string 𝑏
.

Ship gives you string 𝑎
. Your job is to find and output 𝑏
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤100
) — the number of test cases.

The only line of each test case contains a string 𝑎
 (1≤|𝑎|≤100
) — the string Ship observes from outside the store. It is guaranteed that 𝑎
 only contains characters 'p', 'q', and 'w'.

Output
For each test case, output string 𝑏
, the string Ship observes from inside the store, on a new line.

Example
InputCopy
5
qwq
ppppp
pppwwwqqq
wqpqwpqwwqp
pqpqpqpq
OutputCopy
pwp
qqqqq
pppwwwqqq
qpwwpqwpqpw
pqpqpqpq

*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    // reverse the string
    // then replace p with q and q with p
    std::reverse(s.begin(), s.end());

    string ans = "";

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'p')
        ans += 'q';
      else if (s[i] == 'q')
        ans += 'p';
      else
        ans += s[i];
    }
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2044/310226520
