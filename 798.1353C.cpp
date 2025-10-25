/*C. Board Moves
time limit per test1 second
memory limit per test256 megabytes
You are given a board of size 𝑛×𝑛
, where 𝑛
 is odd (not divisible by 2
). Initially, each cell of the board contains one figure.

In one move, you can select exactly one figure presented in some cell and move
it to one of the cells sharing a side or a corner with the current cell, i.e.
from the cell (𝑖,𝑗) you can move the figure to cells:

(𝑖−1,𝑗−1)
;
(𝑖−1,𝑗)
;
(𝑖−1,𝑗+1)
;
(𝑖,𝑗−1)
;
(𝑖,𝑗+1)
;
(𝑖+1,𝑗−1)
;
(𝑖+1,𝑗)
;
(𝑖+1,𝑗+1)
;
Of course, you can not move figures to cells out of the board. It is allowed
that after a move there will be several figures in one cell.

Your task is to find the minimum number of moves needed to get all the figures
into one cell (i.e. 𝑛2−1 cells should contain 0 figures and one cell should
contain 𝑛2 figures).

You have to answer 𝑡
 independent test cases.

Input
The first line of the input contains one integer 𝑡
 (1≤𝑡≤200
) — the number of test cases. Then 𝑡
 test cases follow.

The only line of the test case contains one integer 𝑛
 (1≤𝑛<5⋅105
) — the size of the board. It is guaranteed that 𝑛
 is odd (not divisible by 2
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 5⋅105
 (∑𝑛≤5⋅105
).

Output
For each test case print the answer — the minimum number of moves needed to get
all the figures into one cell.

Example
InputCopy
3
1
5
499993
OutputCopy
0
40
41664916690999888
*/

#include <bits/stdc++.h>
using namespace std;

long long min_moves(int n) {
  long long k = n / 2;
  return 4 * k * (k + 1) * (2 * k + 1) / 3;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << min_moves(n) << "\n";
  }
}

// sub: https://codeforces.com/problemset/submission/1353/345800916
