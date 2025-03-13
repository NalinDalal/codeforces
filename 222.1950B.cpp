/*B. Upscaling
time limit per test1 second
memory limit per test256 megabytes
You are given an integer 𝑛
. Output a 2𝑛×2𝑛
 checkerboard made of 2×2
 squares alternating '#
' and '.
', with the top-left cell being '#
'.


The picture above shows the answers for 𝑛=1,2,3,4
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤20
) — the number of test cases.

The only line of each test case contains a single integer 𝑛
 (1≤𝑛≤20
) — it means you need to output a checkerboard of side length 2𝑛
.

Output
For each test case, output 2𝑛
 lines, each containing 2𝑛
 characters without spaces — the checkerboard, as described in the statement. Do
not output empty lines between test cases.

Example
InputCopy
4
1
2
3
4
OutputCopy
##
##
##..
##..
..##
..##
##..##
##..##
..##..
..##..
##..##
##..##
##..##..
##..##..
..##..##
..##..##
##..##..
##..##..
..##..##
..##..##

*/

#include <iostream>

int main() {

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::string s, t;
    for (int p = 0; p < n; p++) {
      s += (p % 2 ? ".." : "##");
      t += (p % 2 ? "##" : "..");
    }

    for (int row = 0; row < 2 * n; row++) {
      std::cout << (row % 4 < 2 ? s : t) << std::endl;
    }
  }
}
// sub: https://codeforces.com/problemset/submission/1950/310371371
