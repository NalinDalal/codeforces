/*A. Binary Matrix
time limit per test1 second
memory limit per test512 megabytes
A matrix is called binary if all its elements are either 0
 or 1
.

Ecrade calls a binary matrix 𝐴
 good if the following two properties hold:

The bitwise XOR of all numbers in each row of matrix 𝐴
 is equal to 0
.
The bitwise XOR of all numbers in each column of matrix 𝐴
 is equal to 0
.
Ecrade has a binary matrix of size 𝑛⋅𝑚
. He is interested in the minimum number of elements that need to be changed for
the matrix to become good.

However, it seems a little difficult, so please help him!

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤400
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛,𝑚
 (1≤𝑛,𝑚≤100
).

This is followed by 𝑛
 lines, each containing exactly 𝑚
 characters consisting only of 0
 and 1
, describing the elements of Ecrade's matrix.

It is guaranteed that the sum of 𝑛⋅𝑚
 across all test cases does not exceed 5⋅104
.

Output
For each test case, output a single integer, the minimum number of elements that
need to be changed.

Example
InputCopy
7
3 3
010
101
010
3 3
000
000
000
3 3
100
010
001
3 3
101
010
000
3 3
000
010
000
1 4
0101
4 1
0
1
0
1
OutputCopy
2
0
3
3
1
2
2
Note
In the first test case, he needs to change 2 elements to obtain the following
matrix ⎛⎝⎜⎜110101011⎞⎠⎟⎟
.

In the second test case, he can make no changes to obtain the following matrix
⎛⎝⎜⎜000000000⎞⎠⎟⎟
.

In the third test case, he needs to change 3 elements to obtain the following
matrix ⎛⎝⎜⎜101000101⎞⎠⎟⎟
.


*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int row = 0; row < n; row++) {
      std::cin >> v[row];
    }
    int rowCnt = 0;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int col = 0; col < m; col++) {
        cnt += (v[i][col] - '0');
      }
      rowCnt += (cnt % 2);
    }

    int colCnt = 0;
    for (int i = 0; i < m; i++) {
      int cnt = 0;
      for (int row = 0; row < n; row++) {
        cnt += (v[row][i] - '0');
      }
      colCnt += (cnt % 2);
    }
    cout << (rowCnt > colCnt ? rowCnt : colCnt) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2082/311370004
