// link: https://codeforces.com/problemset/problem/263/A
// rating: 800

/* A. Beautiful Matrix
time limit per test2 seconds
memory limit per test256 megabytes
You've got a 5 × 5 matrix, consisting of 24 zeroes and a single number one.
Let's index the matrix rows by numbers from 1 to 5 from top to bottom, let's
index the matrix columns by numbers from 1 to 5 from left to right. In one move,
you are allowed to apply one of the two following transformations to the matrix:

Swap two neighboring matrix rows, that is, rows with indexes i and i + 1 for
some integer i (1 ≤ i < 5). Swap two neighboring matrix columns, that is,
columns with indexes j and j + 1 for some integer j (1 ≤ j < 5). You think that
a matrix looks beautiful, if the single number one of the matrix is located in
its middle (in the cell that is on the intersection of the third row and the
third column). Count the minimum number of moves needed to make the matrix
beautiful.

Input
The input consists of five lines, each line contains five integers: the j-th
integer in the i-th line of the input represents the element of the matrix that
is located on the intersection of the i-th row and the j-th column. It is
guaranteed that the matrix consists of 24 zeroes and a single number one.

Output
Print a single integer — the minimum number of moves needed to make the matrix
beautiful.

Examples:
1.
Input
0 0 0 0 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

Output
3

2.
Input
0 0 0 0 0
0 0 0 0 0
0 1 0 0 0
0 0 0 0 0
0 0 0 0 0

Output
1
*/

// what to do:
// 1. read the matrix
// 2. find the 1 present in the matrix
// 3. move it to middle of matrix
// 4. for each move, add 1 to numMoves
// 5. return numMoves

#include <iostream>
#include <vector>

using namespace std;

// 1st approach:
/* 1. nah, input the whole 5x5 matrix and then try to find the 1 in the middle
  matrix[2][2],
  2. if present, return 0
  3. else, move the 1 to middle and return n such that n is min no of moves
  4. taken to shift the 1 to middle
  */

/*
int main() {
  int matrix[5][5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> matrix[i][j];
    }
  }

  int numMoves = 0;
  int row = 2, col = 2;
  while (matrix[row][col] != 1) {
    if (matrix[row][col] == 0) {
      row--;
      col--;
    } else {
      row++;
      col++;
    }
    numMoves++;
  }

  cout << numMoves << endl;
  return 0;
}*/

// Optimisation:
/* 1. Reduce unnecessary checks: We don't need to check for matrix[row][col] ==
1 at each iteration if we're moving towards the target. The logic can be
simplified based on the rules.
2. Eliminate redundant cin input processing: If you have control over how the
input is given (e.g., it's predefined or comes from a file), you can streamline
input processing.
3. Use a clearer approach: For this particular problem, assuming the goal is to
find the number of moves to reach 1, we can make the condition clearer and
optimize how we determine the direction of movement.*/

/* Identify the position of 1 in the matrix: Instead of iterating step-by-step
to find 1, find its position first. This reduces the need to make repeated
matrix checks. Calculate the number of moves directly: Once we know the target's
position, we can calculate the number of moves required to reach it from the
center (which is (2, 2)) using the Manhattan distance.*/

/*Remove redundant checks: Currently, the movement is determined by the values
in the matrix. We can optimize this by directly moving towards the target 1
without needing extra checks for the values at each step. Avoid unnecessary
matrix access: If the matrix values follow a fixed pattern or are predictable,
we could directly compute the number of moves. However, if the pattern is not
predictable, this might not be possible, but minimizing redundant matrix
accesses still helps.*/

int main() {
  int matrix[5][5];
  int targetRow = -1, targetCol = -1;

  // Read input for the matrix and find the position of 1.
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> matrix[i][j];
      if (matrix[i][j] == 1) {
        targetRow = i;
        targetCol = j;
      }
    }
  }

  // Calculate the number of moves using Manhattan distance
  int numMoves = abs(2 - targetRow) + abs(2 - targetCol);

  cout << numMoves << endl;
  return 0;
}
