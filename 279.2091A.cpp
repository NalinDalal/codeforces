/*A. Olympiad Date
time limit per test1 second
memory limit per test256 megabytes
The final of the first Olympiad by IT Campus "NEIMARK" is scheduled for March 1,
2025. A nameless intern was tasked with forming the date of the Olympiad using
digits — 01.03.2025.

To accomplish this, the intern took a large bag of digits and began drawing them
one by one. In total, he drew 𝑛 digits — the digit 𝑎𝑖 was drawn in the 𝑖 -th
turn.

You suspect that the intern did extra work. Determine at which step the intern
could have first assembled the digits to form the date of the Olympiad (the
separating dots can be ignored), or report that it is impossible to form this
date from the drawn digits. Note that leading zeros must be displayed.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤20
).

The second line of each test case contains 𝑛
 integers 𝑎𝑖
 (0≤𝑎𝑖≤9
) — the numbers that the intern pulled out in chronological order.

Output
For each test case, output the minimum number of digits that the intern could
pull out. If all the digits cannot be used to make a date, output the number 0
.

Example
InputCopy
4
10
2 0 1 2 3 2 5 0 0 1
8
2 0 1 2 3 2 5 0
8
2 0 1 0 3 2 5 0
16
2 3 1 2 3 0 1 9 2 1 0 3 5 4 0 3
OutputCopy
9
0
8
15


*/

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int zero = 3, one = 1, two = 2, three = 1, five = 1;
    int idx = 0;
    for (int p = 0; p < n; p++) {
      int d;
      cin >> d;
      if (d == 0 && zero) {
        --zero;
      } else if (d == 1 && one) {
        --one;
      } else if (d == 2 && two) {
        --two;
      } else if (d == 3 && three) {
        --three;
      } else if (d == 5 && five) {
        --five;
      }
      if (!idx && !zero && !one && !two && !three && !five) {
        idx = p + 1;
      }
    }
    cout << idx << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2091/313337175
