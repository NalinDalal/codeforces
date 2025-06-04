/* B. Progressive Square
time limit per test2 seconds
memory limit per test256 megabytes
A progressive square of size 𝑛
 is an 𝑛×𝑛
 matrix. Maxim chooses three integers 𝑎1,1
, 𝑐
, and 𝑑
 and constructs a progressive square according to the following rules:

𝑎𝑖+1,𝑗=𝑎𝑖,𝑗+𝑐

𝑎𝑖,𝑗+1=𝑎𝑖,𝑗+𝑑

For example, if 𝑛=3
, 𝑎1,1=1
, 𝑐=2
, and 𝑑=3
, then the progressive square looks as follows:

⎛⎝⎜⎜1354687911⎞⎠⎟⎟

Last month Maxim constructed a progressive square and remembered the values of 𝑛
, 𝑐
, and 𝑑
. Recently, he found an array 𝑏
 of 𝑛2
 integers in random order and wants to make sure that these elements are the
elements of that specific square.

It can be shown that for any values of 𝑛
, 𝑎1,1
, 𝑐
, and 𝑑
, there exists exactly one progressive square that satisfies all the rules.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains three integers 𝑛
, 𝑐
, and 𝑑
 (2≤𝑛≤500
, 1≤𝑐,𝑑≤106
) — the size of the square and the values of 𝑐
 and 𝑑
 as described in the statement.

The second line of each test case contains 𝑛⋅𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛⋅𝑛
 (1≤𝑏𝑖≤109
) — the elements found by Maxim.

It is guaranteed that the sum of 𝑛2
 over all test cases does not exceed 25⋅104
.

Output
For each test case, output "YES" in a separate line if a progressive square for
the given 𝑛 , 𝑐 , and 𝑑 can be constructed from the array elements 𝑎 , otherwise
output "NO".

You can output each letter in any case (lowercase or uppercase). For example,
the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive
answer.

Example
InputCopy
5
3 2 3
3 9 6 5 7 1 10 4 8
3 2 3
3 9 6 5 7 1 11 4 8
2 100 100
400 300 400 500
3 2 3
3 9 6 6 5 1 11 4 8
4 4 4
15 27 7 19 23 23 11 15 7 3 19 23 11 15 11 15
OutputCopy
NO
YES
YES
NO
NO

*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool canConstruct(int n, int c, int d, const vector<int> &b) {
  vector<int> sortedB = b;
  sort(sortedB.begin(), sortedB.end());

  vector<int> v;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      v.push_back(row * c + col * d);
    }
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < n * n; i++) {
    if (sortedB[i] != sortedB[0] + v[i]) {
      return false;
    }
  }

  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, c, d;
    cin >> n >> c >> d;
    vector<int> b(n * n);
    for (int i = 0; i < n * n; i++) {
      cin >> b[i];
    }

    cout << (canConstruct(n, c, d, b) ? "YES" : "NO") << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1955/322787339
