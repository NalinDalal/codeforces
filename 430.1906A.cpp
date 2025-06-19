/*A. Easy As ABC
time limit per test1 second
memory limit per test1024 megabytes
You are playing a word puzzle. The puzzle starts with a 3
 by 3
 grid, where each cell contains either the letter A, B, or C.

The goal of this puzzle is to find the lexicographically smallest possible word
of length 3 . The word can be formed by choosing three different cells where the
cell containing the first letter is adjacent to the cell containing the second
letter, and the cell containing the second letter is adjacent to the cell
containing the third letter.

Two cells are adjacent to each other if they share a border or a corner, as
shown in the following illustration. Formally, if (𝑟,𝑐) denotes the cell in the
𝑟 -th row and 𝑐 -th column, then cell (𝑟,𝑐) is adjacent to cell (𝑟,𝑐+1) ,
(𝑟−1,𝑐+1) , (𝑟−1,𝑐) , (𝑟−1,𝑐−1) , (𝑟,𝑐−1) , (𝑟+1,𝑐−1) , (𝑟+1,𝑐) , and (𝑟+1,𝑐+1)
.


Determine the lexicographically smallest possible word of length 3
 that you can find within the grid.

A string 𝑠
 of length 𝑛
 is lexicographically smaller than string 𝑡
 of the same length if there exists an integer 1≤𝑖≤𝑛
 such that 𝑠𝑗=𝑡𝑗
 for all 1≤𝑗<𝑖
, and 𝑠𝑖<𝑡𝑖
 in alphabetical order. The following illustration shows some examples on some
grids and their the lexicographically smallest possible word of length 3 that
you can find within the grids.


Input
Input consists of three lines, each containing three letters, representing the
puzzle grid. Each letter in the grid can only be either A, B, or C.

Output
Output the lexicographically smallest possible word of length 3
 that you can find within the grid.

Examples
InputCopy
BCB
CAC
BCB
OutputCopy
ABC
InputCopy
BCB
CCC
CCA
OutputCopy
ACB
InputCopy
ACA
CBC
ACA
OutputCopy
ABA
InputCopy
ACA
CAC
ACA
OutputCopy
AAA
InputCopy
CCC
CBC
CCC
OutputCopy
BCC


*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {

  std::ios_base::sync_with_stdio(false);
  std::vector<std::string> v(3);
  std::cin >> v[0] >> v[1] >> v[2];
  std::string res("CCC");

  for (int p = 0; p < 9; p++) {
    for (int q = 0; q < 9; q++) {
      for (int r = 0; r < 9; r++) {
        if (p == q || p == r || q == r) {
          continue;
        }
        int rowa(p / 3), cola(p % 3);
        int rowb(q / 3), colb(q % 3);
        int rowc(r / 3), colc(r % 3);

        if (std::abs(rowa - rowb) > 1 || std::abs(cola - colb) > 1) {
          continue;
        }
        if (std::abs(rowb - rowc) > 1 || std::abs(colb - colc) > 1) {
          continue;
        }

        std::string x;
        x += v[rowa][cola];
        x += v[rowb][colb];
        x += v[rowc][colc];

        res = (res < x ? res : x);
      }
    }
  }

  std::cout << res << std::endl;
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1906/325105440
