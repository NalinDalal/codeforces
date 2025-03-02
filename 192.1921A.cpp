/*A. Square
time limit per test1 second
memory limit per test256 megabytes
A square of positive (strictly greater than 0
) area is located on the coordinate plane, with sides parallel to the coordinate
axes. You are given the coordinates of its corners, in random order. Your task
is to find the area of the square.

Input
Each test consists of several testcases. The first line contains one integer 𝑡
 (1≤𝑡≤100
) — the number of testcases. The following is a description of the testcases.

Each testcase contains four lines, each line contains two integers 𝑥𝑖,𝑦𝑖
 (−1000≤𝑥𝑖,𝑦𝑖≤1000
), coordinates of the corners of the square.

It is guaranteed that there is a square with sides parallel to the coordinate
axes, with positive (strictly greater than 0 ) area, with corners in given
points.

Output
For each test case, print a single integer, the area of the square.

Example
InputCopy
3
1 2
4 5
1 5
4 2
-1 1
1 -1
1 1
-1 -1
45 11
45 39
17 11
17 39
OutputCopy
9
4
784

*/
#include <iostream>
#include <set> // To store unique distances
using namespace std;

// The three distances (d1, d2, d3) do not guarantee that they represent the
// side of a square.
int squaredDistance(int x1, int y1, int x2, int y2) {
  return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;
    // cout area of suqare
    // area=dist^2;
    //  Calculate distances between points (we assume given points form a
    //  square)
    // Store all squared distances
    set<int> distances = {
        squaredDistance(x1, y1, x2, y2), squaredDistance(x1, y1, x3, y3),
        squaredDistance(x1, y1, x4, y4), squaredDistance(x2, y2, x3, y3),
        squaredDistance(x2, y2, x4, y4), squaredDistance(x3, y3, x4, y4),
    };
    // Find the side length (smallest non-zero distance)

    /*
            // Area of square = side²
            cout << side * side << endl;
        int xDist = pow((x2 - x1), 2);
        int yDist = pow((y2 - y1), 2);
        int dist = pow((xDist + yDist), 0.5);
        cout << dist * dist << endl;*/
    // Area of square = side²
    // A square has exactly **two** unique distances: one for the side, one for
    // the diagonal
    if (distances.size() == 2) {
      int sideSquared =
          *distances.begin();      // The smaller distance is the side squared
      cout << sideSquared << endl; // Area of square = side²
    } else {
      cout << "-1" << endl; // Not a square
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1921/308691844
