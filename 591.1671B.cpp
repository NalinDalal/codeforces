/*B. Consecutive Points Segment
time limit per test2 seconds
memory limit per test256 megabytes
You are given 𝑛
 points with integer coordinates on a coordinate axis 𝑂𝑋
. The coordinate of the 𝑖
-th point is 𝑥𝑖
. All points' coordinates are distinct and given in strictly increasing order.

For each point 𝑖
, you can do the following operation no more than once: take this point and move
it by 1 to the left or to the right (i..e., you can change its coordinate 𝑥𝑖 to
𝑥𝑖−1 or to 𝑥𝑖+1
). In other words, for each point, you choose (separately) its new coordinate.
For the 𝑖 -th point, it can be either 𝑥𝑖−1 , 𝑥𝑖 or 𝑥𝑖+1
.

Your task is to determine if you can move some points as described above in such
a way that the new set of points forms a consecutive segment of integers, i. e.
for some integer 𝑙 the coordinates of points should be equal to 𝑙,𝑙+1,…,𝑙+𝑛−1
.

Note that the resulting points should have distinct coordinates.

You have to answer 𝑡
 independent test cases.

Input
The first line of the input contains one integer 𝑡
 (1≤𝑡≤2⋅104
) — the number of test cases. Then 𝑡
 test cases follow.

The first line of the test case contains one integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of points in the set 𝑥
.

The second line of the test case contains 𝑛
 integers 𝑥1<𝑥2<…<𝑥𝑛
 (1≤𝑥𝑖≤106
), where 𝑥𝑖
 is the coordinate of the 𝑖
-th point.

It is guaranteed that the points are given in strictly increasing order (this
also means that all coordinates are distinct). It is also guaranteed that the
sum of 𝑛 does not exceed 2⋅105 (∑𝑛≤2⋅105
).

Output
For each test case, print the answer — if the set of points from the test case
can be moved to form a consecutive segment of integers, print YES, otherwise
print NO.

Example
InputCopy
5
2
1 4
3
1 2 3
4
1 2 3 7
1
1000000
3
2 5 6
OutputCopy
YES
YES
NO
YES
YES
*/

#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;

    long x;
    cin >> x;

    long y = x;
    for (long p = 1; p < n; p++) {
      cin >> y;
    }

    cout << (y <= x + n + 1 ? "YES" : "NO") << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1671/333741522
