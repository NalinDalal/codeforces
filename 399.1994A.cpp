/*A. Diverse Game
time limit per test1 second
memory limit per test256 megabytes
Petr, watching Sergey's stream, came up with a matrix 𝑎
, consisting of 𝑛
 rows and 𝑚
 columns (the number in the 𝑖
-th row and 𝑗
-th column is denoted as 𝑎𝑖,𝑗
), which contains all integers from 1
 to 𝑛⋅𝑚
. But he didn't like the arrangement of the numbers, and now he wants to come up
with a new matrix 𝑏 , consisting of 𝑛 rows and 𝑚 columns, which will also
contain all integers from 1 to 𝑛⋅𝑚 , such that for any 1≤𝑖≤𝑛,1≤𝑗≤𝑚 it holds that
𝑎𝑖,𝑗≠𝑏𝑖,𝑗
.

You are given the matrix 𝑎
, construct any matrix 𝑏
 that meets Petr's requirements, or determine that it is impossible.

Hurry up! Otherwise, he will donate all his money to the stream in search of an
answer to his question.

Input
Each test consists of multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤103
) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains two integers 𝑛
 and 𝑚
 (1≤𝑛,𝑚≤10
) — the number of rows and columns of matrix 𝑎
.

The next 𝑛
 lines contain 𝑚
 integers each, describing matrix 𝑎
. The 𝑖
-th of these lines contains the elements of matrix 𝑎𝑖,1,𝑎𝑖,2,…,𝑎𝑖,𝑚
.

It is guaranteed that all numbers in matrix 𝑎
 are distinct and 1≤𝑎𝑖,𝑗≤𝑛⋅𝑚
.

It is guaranteed that the sum of 𝑛⋅𝑚
 over all test cases does not exceed 5⋅104
.

Output
For each test case, output 𝑛⋅𝑚
 integers — any suitable matrix 𝑏
, or −1
 if such a matrix does not exist.

Example
InputCopy
5
1 1
1
2 1
2
1
1 5
2 4 5 3 1
2 4
1 2 3 4
5 6 7 8
3 3
4 2 1
9 8 3
6 7 5
OutputCopy
-1
1
2
4 5 3 1 2
6 7 8 5
2 3 4 1
8 3 9
7 5 6
2 1 4
Note
In the first test case, there is only one element in the matrix, so matrix 𝑏
 is the only matrix and it does not fit.

In the second test case 𝑎1,1=2≠1=𝑏1,1
, 𝑎2,1=1≠2=𝑏2,1
.


*/
#include <iostream>
#include <vector>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long n, m;
    std::cin >> n >> m;

    std::vector<std::vector<long>> a(n, std::vector<long>(m, 0));
    for (long row = 0; row < n; row++) {
      for (long col = 0; col < m; col++) {
        std::cin >> a[row][col];
      }
    }

    // Swap adjacent elements in the first row
    for (long col = 0; col + 1 < m; col++) {
      std::swap(a[0][col], a[0][col + 1]);
    }

    // Swap adjacent rows
    for (long row = 0; row + 1 < n; row++) {
      std::swap(a[row], a[row + 1]);
    }

    if (n * m == 1) {
      std::cout << "-1\n";
      continue;
    }

    for (long row = 0; row < n; row++) {
      for (long col = 0; col < m; col++) {
        std::cout << a[row][col] << ' ';
      }
      std::cout << '\n';
    }
  }

  return 0;
}
// https://codeforces.com/problemset/submission/1994/323361972
