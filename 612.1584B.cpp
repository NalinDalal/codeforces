/*B. Coloring Rectangles
time limit per test1 second
memory limit per test256 megabytes
David was given a red checkered rectangle of size 𝑛×𝑚
. But he doesn't like it. So David cuts the original or any other rectangle
piece obtained during the cutting into two new pieces along the grid lines. He
can do this operation as many times as he wants.

As a result, he will get a set of rectangles. Rectangles 1×1
 are forbidden.

David also knows how to paint the cells blue. He wants each rectangle from the
resulting set of pieces to be colored such that any pair of adjacent cells by
side (from the same piece) have different colors.

What is the minimum number of cells David will have to paint?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤103
) — the number of test cases. The next lines contain descriptions of test cases.

The only line of each test case contains two integers 𝑛
, 𝑚
 (1≤𝑛,𝑚≤3⋅104
, 𝑛⋅𝑚≥2
).

Output
For each test case print a single integer — the minimum number of cells David
will have to paint blue.

Example
InputCopy
4
1 3
2 2
2 5
3 5
OutputCopy
1
2
4
5
Note
The following pictures show how the initial rectangle can be split and cells
colored blue.

In the first test case:


In the second test case:


In the third test case:


In the fourth test case:

*/

#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, m;
    std::cin >> n >> m;
    std::cout << ((m * n + 2) / 3) << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1584/334610701
