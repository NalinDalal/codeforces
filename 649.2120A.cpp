/*A. Square of Rectangles
time limit per test1 second
memory limit per test256 megabytes
Aryan is an ardent lover of squares but a hater of rectangles (Yes, he knows all
squares are rectangles). But Harshith likes to mess with Aryan. Harshith gives
Aryan three rectangles of sizes 𝑙1×𝑏1 , 𝑙2×𝑏2 , and 𝑙3×𝑏3 such that 𝑙3≤𝑙2≤𝑙1 and
𝑏3≤𝑏2≤𝑏1 . Aryan, in order to defeat Harshith, decides to arrange these three
rectangles to form a square such that no two rectangles overlap and the
rectangles are aligned along edges. Rotating rectangles is not allowed. Help
Aryan determine if he can defeat Harshith.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤100
). The description of the test cases follows.

Each test case contains a single line with 6
 space-separated integers 𝑙1,𝑏1,𝑙2,𝑏2,𝑙3
, and 𝑏3
 (1≤𝑙3≤𝑙2≤𝑙1≤100
, 1≤𝑏3≤𝑏2≤𝑏1≤100
) — the dimensions of the three rectangles.

Output
For each testcase, print "YES" if the rectangles can be arranged to form a
square; otherwise, "NO".

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
5
100 100 10 10 1 1
5 3 5 1 5 1
2 3 1 2 1 1
8 5 3 5 3 3
3 3 3 3 2 1
OutputCopy
NO
YES
YES
NO
NO
Note
In the second test case, the three rectangles 5×3
, 5×1
, and 5×1
 can be arranged as follows to form a square.


In the fourth test case, it can be proven that the rectangles can't be arranged
to form a square with the given constraints.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

    bool ans = false;

    if (l1 + l2 + l3 == b1 && b1 == b2 && b2 == b3) {
      ans = true;
    } else if (l2 + l3 == l1 && b2 == b3 && b1 + b2 == l1) {
      ans = true;
    } else if (b1 + b2 + b3 == l1 && l1 == l2 && l2 == l3) {
      ans = true;
    } else if (b2 + b3 == b1 && l2 == l3 && l1 + l2 == b1) {
      ans = true;
    }

    cout << (ans ? "YES\n" : "NO\n");
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2120/336638747
