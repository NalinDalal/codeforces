/* B. Almost Ternary Matrix
time limit per test1 second
memory limit per test256 megabytes
You are given two even integers 𝑛
 and 𝑚
. Your task is to find any binary matrix 𝑎
 with 𝑛
 rows and 𝑚
 columns where every cell (𝑖,𝑗)
 has exactly two neighbours with a different value than 𝑎𝑖,𝑗
.

Two cells in the matrix are considered neighbours if and only if they share a
side. More formally, the neighbours of cell (𝑥,𝑦) are: (𝑥−1,𝑦) , (𝑥,𝑦+1) ,
(𝑥+1,𝑦) and (𝑥,𝑦−1)
.

It can be proven that under the given constraints, an answer always exists.

Input
Each test contains multiple test cases. The first line of input contains a
single integer 𝑡 (1≤𝑡≤100 ) — the number of test cases. The following lines
contain the descriptions of the test cases.

The only line of each test case contains two even integers 𝑛
 and 𝑚
 (2≤𝑛,𝑚≤50
) — the height and width of the binary matrix, respectively.

Output
For each test case, print 𝑛
 lines, each of which contains 𝑚
 numbers, equal to 0
 or 1
 — any binary matrix which satisfies the constraints described in the statement.

It can be proven that under the given constraints, an answer always exists.

Example
InputCopy
3
2 4
2 2
4 4
OutputCopy
1 0 0 1
0 1 1 0
1 0
0 1
1 0 1 0
0 0 1 1
1 1 0 0
0 1 0 1
Note
White means 0
, black means 1
.


The binary matrix from the first test case	The binary matrix from the
second test case	The binary matrix from the third test case

*/
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    // vector<vector<int>> a(n, vector<int>(m, 0));
    //  neighbours of cell (x,y) are (x-1,y),(x,y+1),(x+1,y),(x,y-1)
    //  two neighbours with a different value than a[i,j]
    //  0- black, 1- white

    // stary a[0][0] with value of 1
    // output the matrix

    // int a[0][0] = 1;

    for (long row = 1; row <= n; row++) {
      for (long col = 1; col <= m; col++) {
        cout << (((row % 4 <= 1) != (col % 4 <= 1)) ? 1 : 0) << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}
