/* A. QAQ
time limit per test1 second
memory limit per test256 megabytes
"QAQ" is a word to denote an expression of crying. Imagine "Q" as eyes with
tears and "A" as a mouth.

Now Diamond has given Bort a string consisting of only uppercase English letters
of length n. There is a great number of "QAQ" in the string (Diamond is so
cute!).

illustration by 猫屋 https://twitter.com/nekoyaliu
Bort wants to know how many subsequences "QAQ" are in the string Diamond has
given. Note that the letters "QAQ" don't have to be consecutive, but the order
of letters should be exact.

Input
The only line contains a string of length n (1 ≤ n ≤ 100). It's guaranteed that
the string only contains uppercase English letters.

Output
Print a single integer — the number of subsequences "QAQ" in the string.

Examples
InputCopy
QAQAQYSYIOIWIN
OutputCopy
4
InputCopy
QAQQQZZYNOIWIN
OutputCopy
3
Note
In the first example there are 4 subsequences "QAQ": "QAQAQYSYIOIWIN",
"QAQAQYSYIOIWIN", "QAQAQYSYIOIWIN", "QAQAQYSYIOIWIN".


*/

// i think QAQ can be made how many times like that?
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int count = 0;
  int n = s.length();

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'Q') {
      for (int j = i + 1; j < n; ++j) {
        if (s[j] == 'A') {
          for (int k = j + 1; k < n; ++k) {
            if (s[k] == 'Q') {
              count++;
            }
          }
        }
      }
    }
  }

  cout << count << endl;
  return 0;
}
// sub: https://codeforces.com/problemset/submission/894/319808618
