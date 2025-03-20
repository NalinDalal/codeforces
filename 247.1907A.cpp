/*A. Rook
time limit per test1 second
memory limit per test256 megabytes
As you probably know, chess is a game that is played on a board with 64 squares
arranged in an 8×8 grid. Columns of this board are labeled with letters from a
to h, and rows are labeled with digits from 1 to 8. Each square is described by
the row and column it belongs to.


The rook is a piece in the game of chess. During its turn, it may move any
non-zero number of squares horizontally or vertically. Your task is to find all
possible moves for a rook on an empty chessboard.

Input
The first line of input contains single integer 𝑡
 (1≤𝑡≤64
) — the number of test cases. The descriptions of test cases follow.

Each test case contains one string of two characters, description of the square
where rook is positioned. The first character is a letter from a to h, the label
of column, and the second character is a digit from 1 to 8, the label of row.

The same position may occur in more than one test case.

Output
For each test case, output descriptions of all squares where the rook can move,
in the same format as in the input.

You can output squares in any order per test case.

Example
InputCopy
1
d5
OutputCopy
d1
d2
b5
g5
h5
d3
e5
f5
d8
a5
d6
d7
c5
d4
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    // given a position, find all possible moves of a rook
    for (char col = '1'; col <= '8'; col++) {
      if (col != s[1]) {
        std::cout << s[0] << col << std::endl;
      }
    }
    for (char row = 'a'; row <= 'h'; row++) {
      if (row != s[0]) {
        std::cout << row << s[1] << std::endl;
      }
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1907/311481215
