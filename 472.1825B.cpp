/*B. LuoTianyi and the Table
time limit per test1 second
memory limit per test256 megabytes
LuoTianyi gave an array 𝑏
 of 𝑛⋅𝑚
 integers. She asks you to construct a table 𝑎
 of size 𝑛×𝑚
, filled with these 𝑛⋅𝑚
 numbers, and each element of the array must be used exactly once. Also she
asked you to maximize the following value:

∑𝑖=1𝑛∑𝑗=1𝑚(max1≤𝑥≤𝑖,1≤𝑦≤𝑗𝑎𝑥,𝑦−min1≤𝑥≤𝑖,1≤𝑦≤𝑗𝑎𝑥,𝑦)
This means that we consider 𝑛⋅𝑚
 subtables with the upper left corner in (1,1)
 and the bottom right corner in (𝑖,𝑗)
 (1≤𝑖≤𝑛
, 1≤𝑗≤𝑚
), for each such subtable calculate the difference of the maximum and minimum
elements in it, then sum up all these differences. You should maximize the
resulting sum.

Help her find the maximal possible value, you don't need to reconstruct the
table itself.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤200 ) — the number of test cases. The description of test cases
follows.

The first line of each test case contains two integers 𝑛
 and 𝑚
 (2≤𝑛,𝑚≤100
) — the number of rows and columns of the table.

The second line of each test case contains 𝑛⋅𝑚
 integers 𝑏1,𝑏2,…,𝑏𝑛⋅𝑚
 (−105≤𝑏𝑖≤105
) — the numbers you can put in the table.

Note, that integers in the array 𝑏
 can be negative.

It is guaranteed that the sum of 𝑛⋅𝑚
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case, output a single integer — the maximal value, that can be
obtained.

Example
InputCopy
5
2 2
1 3 1 4
2 2
-1 -1 -1 -1
2 3
7 8 9 -3 10 8
3 2
4 8 -3 0 -7 1
4 3
-32030 59554 16854 -85927 68060 -64460 -79547 90932 85063 82703 -12001 38762
OutputCopy
9
0
64
71
1933711
Note
In the first test case, the table is follows:

4	1
1	3
In the subtable with the bottom right corner in (1,1)
, the difference of the maximal and minimal elements is 4−4=0
.

In the subtable with the bottom right corner in (1,2)
, the difference of the maximal and minimal elements is 4−1=3
.

In the subtable with the bottom right corner in (2,1)
, the difference of the maximal and minimal elements is 4−1=3
.

In the subtable with the bottom right corner in (2,2)
, the difference of the maximal and minimal elements is 4−1=3
.

Then the maximum possible value is 0+3+3+3=9
.

In the second test case, all elements are equal, so all differences are 0
, and the answer is 0
.
*/

#include <iostream>
typedef long long ll;

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    ll n, m;
    std::cin >> n >> m;
    ll mxf(-1e5 - 7), mxs(-1e5 - 7), mnf(1e5 + 7), mns(1e5 + 7);
    for (ll p = 0; p < m * n; p++) {
      ll a;
      std::cin >> a;
      if (a >= mxf) {
        mxs = mxf;
        mxf = a;
      } else if (a > mxs) {
        mxs = a;
      }
      if (a <= mnf) {
        mns = mnf;
        mnf = a;
      } else if (a < mns) {
        mns = a;
      }
    }

    ll df(mxf - mnf), ds(mxf - mns);
    if (mxs - mnf > ds) {
      ds = mxs - mnf;
    }

    ll res = (m * n - 1) * df - (((m < n) ? m : n) - 1) * (df - ds);
    std::cout << res << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/1825/327380565
