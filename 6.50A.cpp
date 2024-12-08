/*
link: https://codeforces.com/problemset/problem/50/A
800 - rating

A. Domino piling
time limit per test2 seconds
memory limit per test256 megabytes

You are given a rectangular board of M × N squares. Also you are given an
unlimited number of standard domino pieces of 2 × 1 squares. You are allowed to
rotate the pieces. You are asked to place as many dominoes as possible on the
board so as to meet the following conditions:

1. Each domino completely covers two squares.
2. No two dominoes overlap.
3. Each domino lies entirely inside the board. It is allowed to touch the edges
of the board.

Find the maximum number of dominoes, which can be placed under these
restrictions.

Input: In a single line you are given two integers M and N — board sizes in
squares (1 ≤ M ≤ N ≤ 16). Output: Output one number — the maximal number of
dominoes, which can be placed.

Examples:-
InputCopy: 2 4
OutputCopy: 4
InputCopy: 3 3
OutputCopy: 4
*/

// size of domino=2*1
// well what if we divide the area of board by area of domino
// then we can find the max number of domino
// if it goes like 17.5,17.6 something, just return 17(nah just use int for data
// type)
//

#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int m, n; // m=row,n=col
  cin >> m >> n;
  int a[m][n];
  int i, j;

  // size of domino=2x1
  // well what if we divide the area of board by area of domino
  // then we can find the max number of domino
  int area = m * n;
  int domino = 2;
  int max = area / domino;
  cout << max << endl;
  return 0;
}
