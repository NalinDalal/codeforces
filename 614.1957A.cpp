/*A. Stickogon
time limit per test1 second
memory limit per test256 megabytes
You are given 𝑛
 sticks of lengths 𝑎1,𝑎2,…,𝑎𝑛
. Find the maximum number of regular (equal-sided) polygons you can construct
simultaneously, such that:

Each side of a polygon is formed by exactly one stick.
No stick is used in more than 1
 polygon.
Note: Sticks cannot be broken.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤100
) — the number of sticks available.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤100
) — the stick lengths.

Output
For each test case, output a single integer on a new line — the maximum number
of regular (equal-sided) polygons you can make simultaneously from the sticks
available.

Example
InputCopy
4
1
1
2
1 1
6
2 2 3 3 3 3
9
4 2 2 2 2 4 2 4 4
OutputCopy
0
0
1
2
Note
In the first test case, we only have one stick, hence we can't form any polygon.

In the second test case, the two sticks aren't enough to form a polygon either.

In the third test case, we can use the 4
 sticks of length 3
 to create a square.

In the fourth test case, we can make a pentagon with side length 2
, and a square of side length 4
.
*/

// vector has length of sticks
// find max no of regular sided polygon you can make
// first of all we will sort the vector

// use a map

// now initialise a counter
// which increase if sticks are of same length stleast 3 times, when break
// the polarity, ince the counter cause let's say if there is 2 three times,
// then it is a triangle now after that if it is 3 five times then it's a
// pentagon so total 2 shapes
// How many triangles can I form (disjointly) using sticks of equal length?

#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    vector<int> v(101, 0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      ++v[a];
    }

    long long cnt = 0;
    for (int p = 0; p <= 100; p++) {
      cnt += v[p] / 3;
    }

    cout << cnt << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1957/334732407
