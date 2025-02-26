/*B. Colourblindness
time limit per test1 second
memory limit per test256 megabytes
Vasya has a grid with 2
 rows and 𝑛
 columns. He colours each cell red, green, or blue.

Vasya is colourblind and can't distinguish green from blue. Determine if Vasya
will consider the two rows of the grid to be coloured the same.

Input
The input consists of multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤100
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤100
) — the number of columns of the grid.

The following two lines each contain a string consisting of 𝑛
 characters, each of which is either R, G, or B, representing a red, green, or
blue cell, respectively — the description of the grid.

Output
For each test case, output "YES" if Vasya considers the grid's two rows to be
identical, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes",
"Yes" and "YES" will be recognized as a positive answer).

Example
InputCopy
6
2
RG
RB
4
GRBG
GBGB
5
GGGGG
BBBBB
7
BBBBBBB
RRRRRRR
8
RGBRRGBR
RGGRRBGR
1
G
G
OutputCopy
YES
NO
YES
NO
YES
YES
Note
In the first test case, Vasya sees the second cell of each row as the same
because the second cell of the first row is green and the second cell of the
second row is blue, so he can't distinguish these two cells. The rest of the
rows are equal in colour. Therefore, Vasya will say that the two rows are
coloured the same, even though they aren't.

In the second test case, Vasya can see that the two rows are different.

In the third test case, every cell is green or blue, so Vasya will think they
are the same.
*/

#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    // 2 rows, n columns
    std::cin >> n;
    std::string s1, s2;
    std::cin >> s1;
    std::cin >> s2;
    // 2 string, compare both string char by char,
    // green=blue i.e. if s1[i] is green, s2[i] is blue then yes, same for
    // viceversa
    // cout yes if s1 is same as s2
    // else cout no
    bool same = true;
    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i]) {
        if ((s1[i] == 'G' && s2[i] == 'B') || (s1[i] == 'B' && s2[i] == 'G')) {
          // Valid swap condition
          continue;
        } else {
          // Characters are different and cannot be made the same
          same = false;
          break;
        }
      }
    }
    if (same)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1722/307966153
