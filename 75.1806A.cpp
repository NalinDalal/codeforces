/* https://codeforces.com/problemset/problem/1806/A
A. Walking Master
time limit per test1 second
memory limit per test1024 megabytes
YunQian is standing on an infinite plane with the Cartesian coordinate system on
it. In one move, she can move to the diagonally adjacent point on the top right
or the adjacent point on the left.

That is, if she is standing on point (𝑥,𝑦), she can either move to point
(𝑥+1,𝑦+1) or point (𝑥−1,𝑦).

YunQian initially stands at point (𝑎,𝑏) and wants to move to point (𝑐,𝑑). Find
the minimum number of moves she needs to make or declare that it is impossible.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤104) — the number of test cases.
The description of test cases follows. The first line and only line of each test
case contain four integers 𝑎, 𝑏, 𝑐, 𝑑 (−108≤𝑎,𝑏,𝑐,𝑑≤108).

Output
For each test case, if it is possible to move from point (𝑎,𝑏) to point (𝑐,𝑑),
output the minimum number of moves. Otherwise, output −1.

Example
InputCopy
6
-1 0 -1 2
0 0 4 5
-2 -1 1 1
-3 2 -3 2
2 -1 -1 -1
1 1 0 2
OutputCopy
4
6
-1
0
3
3
Note
In the first test case, one possible way using 4 moves is
(−1,0)→(0,1)→(−1,1)→(0,2)→(−1,2). It can be proven that it is impossible to move
from point (−1,0) to point (−1,2) in less than 4 moves.

*/

#include <cmath>
#include <iostream>
using namespace std;

int solution(int a, int b, int c, int d) {
  // for point (x,y) can move to (x+1,y+1) or (x-1,y)
  // start point(a,b), end point(c,d)
  // find min steps
  // d-b must be equal to c-a
  // Check if it is impossible to reach (c, d) from (a, b)

  if ((b > d) || ((d - b) < (c - a))) {
    return -1;
  }
  return 2 * (d - b) + (a - c);
  // find abs(a-c) and abs(b-d)
  // Minimum steps will be the maximum of the differences in x and y coordinates
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << solution(a, b, c, d) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1806/301101691
