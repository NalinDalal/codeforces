/*B. Kevin and Geometry
time limit per test1 second
memory limit per test256 megabytes

Kevin has 𝑛
 sticks with length 𝑎1,𝑎2,…,𝑎𝑛
.

Kevin wants to select 4
 sticks from these to form an isosceles trapezoid∗
 with a positive area. Note that rectangles and squares are also considered
isosceles trapezoids. Help Kevin find a solution. If no solution exists, output
−1
.

∗
An isosceles trapezoid is a convex quadrilateral with a line of symmetry
bisecting one pair of opposite sides. In any isosceles trapezoid, two opposite
sides (the bases) are parallel, and the two other sides (the legs) are of equal
length.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (4≤𝑛≤2⋅105
).

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤108
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output 4
 integers — the lengths of sticks. If no solution exists, output −1
.

If there are multiple solutions, print any of them.

Example
InputCopy
7
4
5 5 5 10
4
10 5 10 5
4
1 2 3 4
4
1 1 1 3
6
4 2 1 5 7 1
6
10 200 30 300 30 100
4
100000000 100000000 1 2
OutputCopy
5 5 5 10
5 5 10 10
-1
-1
1 1 4 5
-1
100000000 100000000 1 2
Note
In the first test case, you can form an isosceles trapezoid with bases of length
5 and 10 , and two legs of length 5
.

In the second test case, you can form an isosceles trapezoid with two bases of
length 5 and two legs of length 10 . A rectangle is considered an isosceles
trapezoid here.

In the third test case, there are no sticks with the same length. It's
impossible to form an isosceles trapezoid.

In the fourth test case, it's impossible to form an isosceles trapezoid with a
positive area.



*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::vector<long> v(n);
    for (long &x : v)
      std::cin >> x;

    std::sort(v.rbegin(), v.rend()); // Sort descending

    long s = -1, sidx = -1, a = -1, b = -1;

    // Find first pair of equal elements (s)
    for (long p = 1; p < n; ++p) {
      if (v[p - 1] == v[p]) {
        sidx = p;
        s = v[p];
        v[p - 1] = v[p] = -1; // Mark them as used
        break;
      }
    }

    if (v[0] > 0) {
      a = v[0];
      v[0] = -1;
    } else {
      a = v[2];
      v[2] = -1;
    }

    for (long p = 1; p < n; ++p) {
      if (v[p] < 0)
        continue;
      if (a < 2 * s + v[p]) {
        b = v[p];
        break;
      } else {
        a = v[p];
      }
    }

    if (b > 0) {
      std::cout << s << " " << s << " " << a << " " << b << "\n";
    } else {
      std::cout << "-1\n";
    }
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2061/324579179
