/*A.Perpendicular Segments time limit per test2 seconds memory limit per test256
        megabytes You are given a coordinate plane and three integers 𝑋,
    𝑌,
    and 𝐾.Find two line segments 𝐴𝐵 and 𝐶𝐷 such that

            the coordinates of points 𝐴,
    𝐵, 𝐶, and 𝐷 are integers;
0≤𝐴𝑥, 𝐵𝑥, 𝐶𝑥, 𝐷𝑥≤𝑋 and 0≤𝐴𝑦, 𝐵𝑦, 𝐶𝑦, 𝐷𝑦≤𝑌;
the length of segment 𝐴𝐵 is at least 𝐾;
the length of segment 𝐶𝐷 is at least 𝐾;
segments 𝐴𝐵 and 𝐶𝐷 are perpendicular
    : if you draw lines that contain 𝐴𝐵 and 𝐶𝐷,
      they will cross at a right angle
          .Note that it's not necessary for segments to intersect. Segments are
perpendicular as long as the lines they induce are perpendicular.

      Input The first line contains a single integer
          𝑡(1≤𝑡≤5000) — the number of test cases.Next,
      𝑡 cases follow.

      The first and only line of each test case contains three integers 𝑋,
      𝑌,
      and 𝐾(1≤𝑋, 𝑌≤1000; 1≤𝐾≤1414)
              .

          Additional constraint on the input: the values of 𝑋
, 𝑌
, and 𝐾
 are chosen in such a way that the answer exists.

Output
For each test case, print two lines. The first line should contain 4
 integers 𝐴𝑥
, 𝐴𝑦
, 𝐵𝑥
, and 𝐵𝑦
 — the coordinates of the first segment.

The second line should also contain 4
 integers 𝐶𝑥
, 𝐶𝑦
, 𝐷𝑥
, and 𝐷𝑦
 — the coordinates of the second segment.

If there are multiple answers, print any of them.

Example
InputCopy
4
1 1 1
3 4 1
4 3 3
3 4 4
OutputCopy
0 0 1 0
0 0 0 1
2 4 2 2
0 1 1 1
0 0 1 3
1 2 4 1
0 1 3 4
0 3 3 0
Note
The answer for the first test case is shown below:

The answer for the second test case:

The answer for the third test case:

The answer for the fourth test case:

**/

#include <iostream>
using namespace std;

int main() {
  long t;
  cin >> t;
  while (t--) {
    long x, y, k;
    cin >> x >> y >> k;
    long m = (x < y ? x : y);
    cout << "0 0 " << m << " " << m << "\n";
    cout << "0 " << m << " " << m << " 0\n";
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/2026/315920081
