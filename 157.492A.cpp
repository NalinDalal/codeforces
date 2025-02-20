/* A. Vanya and Cubes
time limit per test1 second
memory limit per test256 megabytes
Vanya got n cubes. He decided to build a pyramid from them. Vanya wants to build
the pyramid as follows: the top level of the pyramid must consist of 1 cube, the
second level must consist of 1 + 2 = 3 cubes, the third level must have
1 + 2 + 3 = 6 cubes, and so on. Thus, the i-th level of the pyramid must have
1 + 2 + ... + (i - 1) + i cubes.

Vanya wants to know what is the maximum height of the pyramid that he can make
using the given cubes.

Input
The first line contains integer n (1 ≤ n ≤ 104) — the number of cubes given to
Vanya.

Output
Print the maximum possible height of the pyramid in the single line.

Examples
InputCopy
1
OutputCopy
1
InputCopy
25
OutputCopy
4
Note
Illustration to the second sample:

*/
// ith level has sigma i cubes
// n cubes given
// find max possible height
// to agar ham like n=25 diya h
// so go till sigma 6 which is 21 less than 25
// return 6

#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int sum = 0;    // Holds the total number of cubes used
  int height = 0; // Holds the height of the pyramid

  for (int i = 1; sum + (i * (i + 1)) / 2 <= n; i++) {
    sum += (i * (i + 1)) / 2; // Add cubes needed for level i
    height++;                 // Increase height
  }

  std::cout << height << std::endl;
  return 0;
}
// sub: https://codeforces.com/problemset/submission/492/307034118
