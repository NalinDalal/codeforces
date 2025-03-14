/*A. Casimir's String Solitaire
time limit per test2 seconds
memory limit per test256 megabytes
Casimir has a string 𝑠
 which consists of capital Latin letters 'A', 'B', and 'C' only. Each turn he
can choose to do one of the two following actions:

he can either erase exactly one letter 'A' and exactly one letter 'B' from
arbitrary places of the string (these letters don't have to be adjacent); or he
can erase exactly one letter 'B' and exactly one letter 'C' from arbitrary
places in the string (these letters don't have to be adjacent). Therefore, each
turn the length of the string is decreased exactly by 2 . All turns are
independent so for each turn, Casimir can choose any of two possible actions.

For example, with 𝑠
 =
 "ABCABC" he can obtain a string 𝑠
 =
 "ACBC" in one turn (by erasing the first occurrence of 'B' and the second
occurrence of 'A'). There are also many other options for a turn aside from this
particular example.

For a given string 𝑠
 determine whether there is a sequence of actions leading to an empty string. In
other words, Casimir's goal is to erase all letters from the string. Is there a
way to do this?

Input
The first line contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

Each test case is described by one string 𝑠
, for which you need to determine if it can be fully erased by some sequence of
turns. The string 𝑠 consists of capital letters 'A', 'B', 'C' and has a length
from 1 to 50 letters, inclusive.

Output
Print 𝑡
 lines, each line containing the answer to the corresponding test case. The
answer to a test case should be YES if there is a way to fully erase the
corresponding string and NO otherwise.

You may print every letter in any case you want (so, for example, the strings
yEs, yes, Yes, and YES will all be recognized as positive answers).

Example
InputCopy
6
ABACAB
ABBA
AC
ABC
CABCBB
BCBCBCBCBCBCBCBC
OutputCopy
NO
YES
NO
NO
YES
YES

*/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    // no of a's+no of c's==no of b's
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'A')
        a++;
      if (s[i] == 'B')
        b++;
      if (s[i] == 'C')
        c++;
    }
    if (a + c == b)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1579/310612689
