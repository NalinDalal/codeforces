/* A. Rectangle Cutting
time limit per test1 second
memory limit per test256 megabytes
Bob has a rectangle of size 𝑎×𝑏
. He tries to cut this rectangle into two rectangles with integer sides by
making a cut parallel to one of the sides of the original rectangle. Then Bob
tries to form some other rectangle from the two resulting rectangles, and he can
rotate and move these two rectangles as he wishes.

Note that if two rectangles differ only by a 90∘
 rotation, they are considered the same. For example, the rectangles 6×4
 and 4×6
 are considered the same.

Thus, from the 2×6
 rectangle, another rectangle can be formed, because it can be cut into two 2×3
 rectangles, and then these two rectangles can be used to form the 4×3
 rectangle, which is different from the 2×6
 rectangle.


However, from the 2×1
 rectangle, another rectangle cannot be formed, because it can only be cut into
two rectangles of 1×1 , and from these, only the 1×2 and 2×1 rectangles can be
formed, which are considered the same.


Help Bob determine if he can obtain some other rectangle, or if he is just
wasting his time.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. This is followed by the
description of the test cases.

The single line of each test case contains two integers 𝑎
 and 𝑏
 (1≤𝑎,𝑏≤109
) — the size of Bob's rectangle.

Output
For each test case, output "Yes" if Bob can obtain another rectangle from the
𝑎×𝑏 rectangle. Otherwise, output "No".

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive answers.

Example
InputCopy
7
1 1
2 1
2 6
3 2
2 2
2 4
6 3
OutputCopy
No
No
Yes
Yes
Yes
Yes
No
Note
In the first test case, the 1×1
 rectangle cannot be cut into two rectangles, so another rectangle cannot be
obtained from it.

In the fourth test case, the 3×2
 rectangle can be cut into two 3×1
 rectangles, and from these, the 1×6
 rectangle can be formed.

In the fifth test case, the 2×2
 rectangle can be cut into two 1×2
 rectangles, and from these, the 1×4
 rectangle can be formed.
*/

#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int a, b;
    std::cin >> a >> b;
    bool possible = (a % 2 == 0 && a / 2 != b) || (b % 2 == 0 && b / 2 != a);
    std::cout << (possible ? "Yes" : "No") << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1928/320218135
