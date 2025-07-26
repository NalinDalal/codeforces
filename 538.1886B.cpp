/*B. Fear of the Dark
time limit per test2 seconds
memory limit per test256 megabytes
Monocarp tries to get home from work. He is currently at the point 𝑂=(0,0)
 of a two-dimensional plane; his house is at the point 𝑃=(𝑃𝑥,𝑃𝑦)
.

Unfortunately, it is late in the evening, so it is very dark. Monocarp is afraid
of the darkness. He would like to go home along a path illuminated by something.

Thankfully, there are two lanterns, located in the points 𝐴=(𝐴𝑥,𝐴𝑦)
 and 𝐵=(𝐵𝑥,𝐵𝑦)
. You can choose any non-negative number 𝑤
 and set the power of both lanterns to 𝑤
. If a lantern's power is set to 𝑤
, it illuminates a circle of radius 𝑤
 centered at the lantern location (including the borders of the circle).

You have to choose the minimum non-negative value 𝑤
 for the power of the lanterns in such a way that there is a path from the point
𝑂 to the point 𝑃 which is completely illuminated. You may assume that the
lanterns don't interfere with Monocarp's movement.

The picture for the first two test cases
Input
The first line of the input contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case consists of three lines:

the first line contains two integers 𝑃𝑥
 and 𝑃𝑦
 (−103≤𝑃𝑥,𝑃𝑦≤103
) — the location of Monocarp's house;
the second line contains two integers 𝐴𝑥
 and 𝐴𝑦
 (−103≤𝐴𝑥,𝐴𝑦≤103
) — the location of the first lantern;
the third line contains two integers 𝐵𝑥
 and 𝐵𝑦
 (−103≤𝐵𝑥,𝐵𝑦≤103
) — the location of the second lantern.
Additional constraint on the input:

in each test case, the points 𝑂
, 𝑃
, 𝐴
 and 𝐵
 are different from each other.
Output
For each test case, print the answer on a separate line — one real number equal
to the minimum value of 𝑤 such that there is a completely illuminated path from
the point 𝑂 to the point 𝑃
.

Your answer will be considered correct if its absolute or relative error does
not exceed 10−6 — formally, if your answer is 𝑎 , and the jury's answer is 𝑏 ,
your answer will be accepted if |𝑎−𝑏|max(1,𝑏)≤10−6
.

Example
InputCopy
2
3 3
1 0
-1 6
3 3
-1 -1
4 3
OutputCopy
3.6055512755
3.2015621187
*/

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

double dist(pair<double, double> u, pair<double, double> v) {
  return sqrt((u.first - v.first) * (u.first - v.first) +
              (u.second - v.second) * (u.second - v.second));
}

int main() {
  long t;
  cin >> t;
  while (t--) {
    pair<double, double> h, a, b;
    cin >> h.first >> h.second;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;

    double za = dist(pair<double, double>(0.0, 0.0), a);
    double zb = dist(pair<double, double>(0.0, 0.0), b);
    double ha = dist(h, a);
    double hb = dist(h, b);
    double ab = dist(a, b);
    ab /= 2.0;

    double res = (za > ha) ? za : ha; // only A, 0->A->H
    double cand = (zb > hb) ? zb : hb;
    res = (res < cand) ? res : cand; // Only B, 0->B->H
    cand = (za > ab) ? za : ab;
    cand = (cand > hb) ? cand : hb;
    res = (cand < res) ? cand : res; // 0->A->B->H
    cand = (zb > ab) ? zb : ab;
    cand = (cand > ha) ? cand : ha;
    res = (cand < res) ? cand : res; // 0->B->A->H
    cout.precision(8);
    cout << fixed << res << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1886/330933150
