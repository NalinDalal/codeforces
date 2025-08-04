/*B. StORage room
time limit per test2 seconds
memory limit per test256 megabytes
In Cyprus, the weather is pretty hot. Thus, Theofanis saw this as an opportunity
to create an ice cream company.

He keeps the ice cream safe from other ice cream producers by locking it inside
big storage rooms. However, he forgot the password. Luckily, the lock has a
special feature for forgetful people!

It gives you a table 𝑀
 with 𝑛
 rows and 𝑛
 columns of non-negative integers, and to open the lock, you need to find an
array 𝑎 of 𝑛 elements such that:

0≤𝑎𝑖<230
, and
𝑀𝑖,𝑗=𝑎𝑖|𝑎𝑗
 for all 𝑖≠𝑗
, where |
 denotes the bitwise OR operation.
The lock has a bug, and sometimes it gives tables without any solutions. In that
case, the ice cream will remain frozen for the rest of eternity.

Can you find an array to open the lock?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤103
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤103
) — the size of the hidden array.

The next 𝑛
 lines describe the rows of 𝑀
, line 𝑖
 contains the table values 𝑀𝑖,1,𝑀𝑖,2,…,𝑀𝑖,𝑛
 (0≤𝑀𝑖,𝑗<230
).

It is guaranteed that 𝑀𝑖,𝑖=0
 and 𝑀𝑖,𝑗=𝑀𝑗,𝑖
 for all 1≤𝑖,𝑗≤𝑛
.

It is also guaranteed that the sum of 𝑛
 over all test cases does not exceed 103
.

Output
For each test case, if there is a solution print YES and an array that satisfies
the property, otherwise print NO.

If there are multiple solutions, print any of them.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
4
1
0
4
0 3 3 5
3 0 3 7
3 3 0 7
5 7 7 0
5
0 7 7 5 5
7 0 3 2 6
7 3 0 3 7
5 2 3 0 4
5 6 7 4 0
3
0 0 1
0 0 0
1 0 0
OutputCopy
YES
7
YES
1 3 2 5
YES
5 2 3 0 4
NO
*/

/*n x n matrix M, we want to find an array a of size n such that:
    - For all i ≠ j, we have M[i][j] = a[i] | a[j] (bitwise OR).
    - M[i][i] = 0 and M[i][j] = M[j][i] (the matrix is symmetric and diagonal is
zero).

For each i, you want to find a[i] such that:
a[i] | a[j] = M[i][j]    for all j ≠ i

a[i] ≤ M[i][j] because a[i] | a[j] is always at least as large as a[i].

a[i] = M[i][0] & M[i][1] & ... & M[i][n-1] (j ≠ i)

hence do:
a[i] = AND over all M[i][j] where j ≠ i

1. For each test case:
    - Read matrix M.
    - Compute a[i] = AND over M[i][j] for j ≠ i.

2. Verify for all i ≠ j: a[i] | a[j] == M[i][j].

3. If yes, print YES and array a. Otherwise, print NO.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        cin >> M[i][j];

    vector<int> a(n, (1 << 30) - 1); // all bits set
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (i != j)
          a[i] &= M[i][j];

    // verify
    bool ok = true;
    for (int i = 0; i < n && ok; ++i) {
      for (int j = 0; j < n && ok; ++j) {
        if (i == j)
          continue;
        if ((a[i] | a[j]) != M[i][j])
          ok = false;
      }
    }

    if (ok) {
      cout << "YES\n";
      for (int x : a)
        cout << x << ' ';
      cout << '\n';
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1903/332291794
