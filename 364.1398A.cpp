/* A. Bad Triangle
time limit per test1 second
memory limit per test256 megabytes
You are given an array 𝑎1,𝑎2,…,𝑎𝑛
, which is sorted in non-decreasing order (𝑎𝑖≤𝑎𝑖+1)
.

Find three indices 𝑖
, 𝑗
, 𝑘
 such that 1≤𝑖<𝑗<𝑘≤𝑛
 and it is impossible to construct a non-degenerate triangle (a triangle with
nonzero area) having sides equal to 𝑎𝑖 , 𝑎𝑗 and 𝑎𝑘 (for example it is possible
to construct a non-degenerate triangle with sides 3 , 4 and 5 but impossible
with sides 3 , 4 and 7
). If it is impossible to find such triple, report it.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The first line of each test case contains one integer 𝑛
 (3≤𝑛≤5⋅104
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
; 𝑎𝑖−1≤𝑎𝑖
) — the array 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case print the answer to it in one line.

If there is a triple of indices 𝑖
, 𝑗
, 𝑘
 (𝑖<𝑗<𝑘
) such that it is impossible to construct a non-degenerate triangle having sides
equal to 𝑎𝑖 , 𝑎𝑗 and 𝑎𝑘 , print that three indices in ascending order. If there
are multiple answers, print any of them.

Otherwise, print -1.

Example
InputCopy
3
7
4 6 11 11 15 18 20
4
10 10 10 11
3
1 1 1000000000
OutputCopy
2 3 6
-1
1 2 3
Note
In the first test case it is impossible with sides 6
, 11
 and 18
. Note, that this is not the only correct answer.

In the second test case you always can construct a non-degenerate triangle.


*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    int idx = -1;
    for (int p = 1; p < n - 1; p++) {
      if (v[n - 1] >= v[0] + v[p]) {
        idx = p + 1;
        break;
      }
    }
    if (idx > 0)
      cout << "1 " << idx << " " << n << endl;
    else
      cout << "-1" << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1398/320753340
