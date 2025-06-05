/* A. Find K Distinct Points with Fixed Center
time limit per test1 second
memory limit per test256 megabytes
I couldn't think of a good title for this problem, so I decided to learn from
LeetCode. — Sun Tzu, The Art of War You are given three integers 𝑥𝑐 , 𝑦𝑐 , and 𝑘
 (−100≤𝑥𝑐,𝑦𝑐≤100
, 1≤𝑘≤1000
).

You need to find 𝑘
 distinct points (𝑥1,𝑦1
), (𝑥2,𝑦2
), …
, (𝑥𝑘,𝑦𝑘
), having integer coordinates, on the 2D coordinate plane such that:

their center∗
 is (𝑥𝑐,𝑦𝑐
)
−109≤𝑥𝑖,𝑦𝑖≤109
 for all 𝑖
 from 1
 to 𝑘
It can be proven that at least one set of 𝑘
 distinct points always exists that satisfies these conditions.

∗
The center of 𝑘
 points (𝑥1,𝑦1
), (𝑥2,𝑦2
), …
, (𝑥𝑘,𝑦𝑘
) is (𝑥1+𝑥2+…+𝑥𝑘𝑘,𝑦1+𝑦2+…+𝑦𝑘𝑘)
.

Input
The first line contains 𝑡
 (1≤𝑡≤100
) — the number of test cases.

Each test case contains three integers 𝑥𝑐
, 𝑦𝑐
, and 𝑘
 (−100≤𝑥𝑐,𝑦𝑐≤100
, 1≤𝑘≤1000
) — the coordinates of the center and the number of distinct points you must
output.

It is guaranteed that the sum of 𝑘
 over all test cases does not exceed 1000
.

Output
For each test case, output 𝑘
 lines, the 𝑖
-th line containing two space separated integers, 𝑥𝑖
 and 𝑦𝑖
, (−109≤𝑥𝑖,𝑦𝑖≤109
) — denoting the position of the 𝑖
-th point.

If there are multiple answers, print any of them. It can be shown that a
solution always exists under the given constraints.

Example
InputCopy
4
10 10 1
0 0 3
-5 -8 8
4 -5 3
OutputCopy
10 10
-1 -1
5 -1
-4 2
-6 -7
-5 -7
-4 -7
-4 -8
-4 -9
-5 -9
-6 -9
-6 -8
1000 -1000
-996 995
8 -10
Note
For the first test case, (101,101)=(10,10)
.

For the second test case, (−1+5−43,−1−1+23)=(0,0)
.



*/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int xc, yc, k;
    cin >> xc >> yc >> k;
    if (k % 2) {
      --k;
      cout << xc << " " << yc << endl;
    }
    for (int p = 1; p <= k / 2; p++)
      cout << xc - p << " " << yc << " " << xc + p << " " << yc << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1998/322997144
