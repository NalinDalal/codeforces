/* A. Closest Point
time limit per test2 seconds
memory limit per test512 megabytes
Consider a set of points on a line. The distance between two points 𝑖
 and 𝑗
 is |𝑖−𝑗|
.

The point 𝑖
 from the set is the closest to the point 𝑗
 from the set, if there is no other point 𝑘
 in the set such that the distance from 𝑗
 to 𝑘
 is strictly less than the distance from 𝑗
 to 𝑖
. In other words, all other points from the set have distance to 𝑗
 greater or equal to |𝑖−𝑗|
.

For example, consider a set of points {1,3,5,8}
:

for the point 1
, the closest point is 3
 (other points have distance greater than |1−3|=2
);
for the point 3
, there are two closest points: 1
 and 5
;
for the point 5
, the closest point is 3
 (but not 8
, since its distance is greater than |3−5|
);
for the point 8
, the closest point is 5
.
You are given a set of points. You have to add an integer point into this set in
such a way that it is different from every existing point in the set, and it
becomes the closest point to every point in the set. Is it possible?

Input
The first line contains one integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

Each test case consists of two lines:

the first line contains one integer 𝑛
 (2≤𝑛≤40
) — the number of points in the set;
the second line contains 𝑛
 integers 𝑥1,𝑥2,…,𝑥𝑛
 (1≤𝑥1<𝑥2<⋯<𝑥𝑛≤100
) — the points from the set.
Output
For each test case, print YES if it is possible to add a new point according to
the conditions from the statement. Otherwise, print NO.

Example
InputCopy
3
2
3 8
2
5 6
6
1 2 3 4 5 10
OutputCopy
YES
NO
NO
Note
In the first example, the point 7
 will be the closest to both 3
 and 8
.

In the second example, it is impossible to add an integer point so that it
becomes the closest to both 5 and 6 , and is different from both of them.


*/
#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
      b = a;
      std::cin >> a;
    }
    std::cout << ((n == 2 && (b - a > 1 || b - a < -1)) ? "YES" : "NO")
              << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2004/322787070
