/*E. Permutation of Rows and Columns
time limit per test3 seconds
memory limit per test256 megabytes
You have been given a matrix 𝑎
 of size 𝑛
 by 𝑚
, containing a permutation of integers from 1
 to 𝑛⋅𝑚
.

A permutation of 𝑛
 integers is an array containing all numbers from 1
 to 𝑛
 exactly once. For example, the arrays [1]
, [2,1,3]
, [5,4,3,2,1]
 are permutations, while the arrays [1,1]
, [100]
, [1,2,4,5]
 are not.

A matrix contains a permutation if, when all its elements are written out, the
resulting array is a permutation. Matrices [[1,2],[3,4]] , [[1]] ,
[[1,5,3],[2,6,4]] contain permutations, while matrices [[2]] , [[1,1],[2,2]] ,
[[1,2],[100,200]] do not.

You can perform one of the following two actions in one operation:

choose columns 𝑐
 and 𝑑
 (1≤𝑐,𝑑≤𝑚
, 𝑐≠𝑑
) and swap these columns;
choose rows 𝑐
 and 𝑑
 (1≤𝑐,𝑑≤𝑛
, 𝑐≠𝑑
) and swap these rows.
You can perform any number of operations.

You are given the original matrix 𝑎
 and the matrix 𝑏
. Your task is to determine whether it is possible to transform matrix 𝑎
 into matrix 𝑏
 using the given operations.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The descriptions of the test cases follow.

The first line of each test case description contains 2
 integers 𝑛
 and 𝑚
 (1≤𝑛,𝑚≤𝑛⋅𝑚≤2⋅105
) — the sizes of the matrix.

The next 𝑛
 lines contain 𝑚
 integers 𝑎𝑖𝑗
 each (1≤𝑎𝑖𝑗≤𝑛⋅𝑚
). It is guaranteed that matrix 𝑎
 is a permutation.

The next 𝑛
 lines contain 𝑚
 integers 𝑏𝑖𝑗
 each (1≤𝑏𝑖𝑗≤𝑛⋅𝑚
). It is guaranteed that matrix 𝑏
 is a permutation.

It is guaranteed that the sum of the values 𝑛⋅𝑚
 for all test cases does not exceed 2⋅105
.

Output
For each test case, output "YES" if the second matrix can be obtained from the
first, and "NO" otherwise.

You can output each letter in any case (lowercase or uppercase). For example,
the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive
answer.

Example
InputCopy
7
1 1
1
1
2 2
1 2
3 4
4 3
2 1
2 2
1 2
3 4
4 3
1 2
3 4
1 5 9 6
12 10 4 8
7 11 3 2
1 5 9 6
12 10 4 8
7 11 3 2
3 3
1 5 9
6 4 2
3 8 7
9 5 1
2 4 6
7 8 3
2 3
1 2 6
5 4 3
6 1 2
3 4 5
1 5
5 1 2 3 4
4 2 5 1 3
OutputCopy
YES
YES
NO
YES
YES
NO
YES
Note
In the second example, the original matrix looks like this:

(1324)

By swapping rows 1
 and 2
, it becomes:

(3142)

By swapping columns 1
 and 2
, it becomes equal to matrix 𝑏
:

(4231)

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> a[i][j];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> b[i][j];

    // Row check
    multiset<vector<int>> rowA, rowB;
    for (int i = 0; i < n; i++) {
      auto r = a[i];
      sort(r.begin(), r.end());
      rowA.insert(r);
    }
    for (int i = 0; i < n; i++) {
      auto r = b[i];
      sort(r.begin(), r.end());
      rowB.insert(r);
    }

    // Column check
    multiset<vector<int>> colA, colB;
    for (int j = 0; j < m; j++) {
      vector<int> c;
      for (int i = 0; i < n; i++)
        c.push_back(a[i][j]);
      sort(c.begin(), c.end());
      colA.insert(c);
    }
    for (int j = 0; j < m; j++) {
      vector<int> c;
      for (int i = 0; i < n; i++)
        c.push_back(b[i][j]);
      sort(c.begin(), c.end());
      colB.insert(c);
    }

    if (rowA == rowB && colA == colB)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1980/335918256
