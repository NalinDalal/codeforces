/* D. Manhattan Circle
time limit per test2 seconds
memory limit per test256 megabytes
Given a 𝑛
 by 𝑚
 grid consisting of '.' and '#' characters, there exists a whole manhattan
circle on the grid. The top left corner of the grid has coordinates (1,1) , and
the bottom right corner has coordinates (𝑛,𝑚)
.

Point (𝑎,𝑏
) belongs to the manhattan circle centered at (ℎ,𝑘
) if |ℎ−𝑎|+|𝑘−𝑏|<𝑟
, where 𝑟
 is a positive constant.

On the grid, the set of points that are part of the manhattan circle is marked
as '#'. Find the coordinates of the center of the circle.

Input
The first line contains 𝑡
 (1≤𝑡≤1000
)  — the number of test cases.

The first line of each test case contains 𝑛
 and 𝑚
 (1≤𝑛⋅𝑚≤2⋅105
) — the height and width of the grid, respectively.

The next 𝑛
 lines contains 𝑚
 characters '.' or '#'. If the character is '#', then the point is part of the
manhattan circle.

It is guaranteed the sum of 𝑛⋅𝑚
 over all test cases does not exceed 2⋅105
, and there is a whole manhattan circle on the grid.

Output
For each test case, output the two integers, the coordinates of the center of
the circle.

Example
InputCopy
6
5 5
.....
.....
..#..
.....
.....
5 5
..#..
.###.
#####
.###.
..#..
5 6
......
......
.#....
###...
.#....
1 1
#
5 6
...#..
..###.
.#####
..###.
...#..
2 10
..........
...#......
OutputCopy
3 3
3 3
4 2
1 1
3 4
2 4

*/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int sr = 0, sc = 0, cnt = 0;
    for (int row = 0; row < n; row++) {
      std::string s;
      std::cin >> s;
      for (int col = 0; col < s.size(); col++) {
        if (s[col] == '.') {
          continue;
        }
        sr += 1 + row;
        sc += 1 + col;
        ++cnt;
      }
    }

    std::cout << (sr / cnt) << " " << (sc / cnt) << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1985/318594995
