/* B. Pushing Balls
time limit per test1 second
memory limit per test512 megabytes
Ecrade has an 𝑛×𝑚
 grid, originally empty, and he has pushed several (possibly, zero) balls in it.

Each time, he can push one ball into the grid either from the leftmost edge of a
particular row or the topmost edge of a particular column of the grid.

When a ball moves towards a position:

If there is no ball originally at that position, the incoming ball will stop and
occupy the position. If there is already a ball at that position, the incoming
ball will stop and occupy the position, while the original ball will continue
moving to the next position in the same direction. Note that if a row or column
is full (i.e., all positions in that row or column have balls), he cannot push a
ball into that row or column.

Given the final state of whether there is a ball at each position of the grid,
you need to determine whether it is possible for Ecrade to push the balls to
reach the final state.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤10000
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑚
 (1≤𝑛,𝑚≤50
).

This is followed by 𝑛
 lines, each containing exactly 𝑚
 characters and consisting only of 0
 and 1
, describing the final state of the grid. There is a ball at one position of the
grid if and only if the corresponding position of the given input is 1
.

It is guaranteed that the sum of 𝑛⋅𝑚
 over all test cases does not exceed 10000
.

Output
For each test case, output "Yes" (without quotes) if it is possible for Ecrade
to push the balls to reach the final state, and "No" (without quotes) otherwise.

You can output "Yes" and "No" in any case (for example, strings "YES", "yEs" and
"yes" will be recognized as a positive response).

Example
InputCopy
5
3 3
001
001
110
3 3
010
111
010
3 3
111
111
111
3 3
000
000
000
3 3
000
000
001
OutputCopy
YES
YES
YES
YES
NO
Note
For simplicity, if Ecrade pushes a ball from the leftmost edge of the 𝑖
-th row, we call the operation ROW 𝑖
; if he pushes a ball from the topmost edge of the 𝑖
-th column, we call the operation COL 𝑖
.

For intuitive understanding, a non-zero number 𝑥
 in the matrix given below represents the 𝑥
-th ball that is pushed in.

In the first test case, a possible series of operations:

⎛⎝⎜⎜000000000⎞⎠⎟⎟−→−−−ROW 3−→−−−ROW 3⎛⎝⎜⎜002001000⎞⎠⎟⎟−→−−−COL 3−→−−−COL
3⎛⎝⎜⎜002001430⎞⎠⎟⎟

In the second test case, a possible series of operations:

⎛⎝⎜⎜000000000⎞⎠⎟⎟−→−−−ROW 2−→−−−ROW 2−→−−−ROW 2⎛⎝⎜⎜030020010⎞⎠⎟⎟−→−−−COL
2−→−−−COL 2⎛⎝⎜⎜030542010⎞⎠⎟⎟

In the third test case, a possible series of operations:

⎛⎝⎜⎜000000000⎞⎠⎟⎟−→−−−ROW 1−→−−−ROW 2−→−−−ROW 3⎛⎝⎜⎜123000000⎞⎠⎟⎟−→−−−COL
3−→−−−COL 3−→−−−COL 3⎛⎝⎜⎜123000654⎞⎠⎟⎟−→−−−ROW 1−→−−−ROW 2−→−−−ROW
3⎛⎝⎜⎜789123654⎞⎠⎟⎟


*/

#include <iostream>
#include <vector>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n, m;
    std::cin >> n >> m;
    std::vector<std::string> b(n);
    for (long row = 0; row < n; row++) {
      std::cin >> b[row];
    }

    std::vector<std::vector<bool>> d(n, std::vector<bool>(m, 0));
    for (long row = 0; row < n; row++) {
      for (long col = 0; col < m; col++) {
        if (b[row][col] == '0') {
          break;
        }
        d[row][col] = 1;
      }
    }

    for (long col = 0; col < m; col++) {
      for (long row = 0; row < n; row++) {
        if (b[row][col] == '0') {
          break;
        }
        d[row][col] = 1;
      }
    }

    bool res(true);
    for (long row = 0; res && row < n; row++) {
      for (long col = 0; res && col < m; col++) {
        if (b[row][col] == '1' && !d[row][col]) {
          res = false;
        }
      }
    }

    std::cout << (res ? "YES" : "NO") << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/2090/314201488
