/* A. X Axis
time limit per test2 seconds
memory limit per test256 megabytes
You are given three points with integer coordinates 𝑥1
, 𝑥2
, and 𝑥3
 on the 𝑋
 axis (1≤𝑥𝑖≤10
). You can choose any point with an integer coordinate 𝑎
 on the 𝑋
 axis. Note that the point 𝑎
 may coincide with 𝑥1
, 𝑥2
, or 𝑥3
. Let 𝑓(𝑎)
 be the total distance from the given points to the point 𝑎
. Find the smallest value of 𝑓(𝑎)
.

The distance between points 𝑎
 and 𝑏
 is equal to |𝑎−𝑏|
. For example, the distance between points 𝑎=5
 and 𝑏=2
 is 3
.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤103 ) — the number of test cases. Then follows their
descriptions.

The single line of each test case contains three integers 𝑥1
, 𝑥2
, and 𝑥3
 (1≤𝑥𝑖≤10
) — the coordinates of the points.

Output
For each test case, output the smallest value of 𝑓(𝑎)
.

Example
InputCopy
8
1 1 1
1 5 9
8 2 8
10 9 3
2 1 1
2 4 1
7 3 5
1 9 4
OutputCopy
0
8
6
7
1
3
4
8
Note
In the first test case, the smallest value of 𝑓(𝑎)
 is achieved when 𝑎=1
: 𝑓(1)=|1−1|+|1−1|+|1−1|=0
.

In the second test case, the smallest value of 𝑓(𝑎)
 is achieved when 𝑎=5
: 𝑓(5)=|1−5|+|5−5|+|9−5|=8
.

In the third test case, the smallest value of 𝑓(𝑎)
 is achieved when 𝑎=8
: 𝑓(8)=|8−8|+|2−8|+|8−8|=6
.

In the fourth test case, the smallest value of 𝑓(𝑎)
 is achieved when 𝑎=9
: 𝑓(10)=|10−9|+|9−9|+|3−9|=7
.


*/

#include <iostream>
int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    int mn = (a < b ? a : b);
    mn = (mn < c ? mn : c);
    int mx = (a > b ? a : b);
    mx = (mx > c ? mx : c);
    std::cout << mx - mn << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/1986/309637554
