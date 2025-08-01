/*B. Conveyor Belts
time limit per test3 seconds
memory limit per test256 megabytes
Conveyor matrix 𝑚𝑛
 is matrix of size 𝑛×𝑛
, where 𝑛
 is an even number. The matrix consists of concentric ribbons moving clockwise.

In other words, the conveyor matrix for 𝑛=2
 is simply a matrix 2×2
, whose cells form a cycle of length 4
 clockwise. For any natural 𝑘≥2
, the matrix 𝑚2𝑘
 is obtained by adding to the matrix 𝑚2𝑘−2
 an outer layer forming a clockwise cycle.

The conveyor matrix 8×8
.
You are standing in a cell with coordinates 𝑥1,𝑦1
 and you want to get into a cell with coordinates 𝑥2,𝑦2
. A cell has coordinates 𝑥,𝑦
 if it is located at the intersection of the 𝑥
th row and the 𝑦
th column.

Standing on some cell, every second you will move to the cell next in the
direction of movement of the tape on which you are. You can also move to a
neighboring cell by spending one unit of energy. Movements happen instantly and
you can make an unlimited number of them at any time.

Your task is to find the minimum amount of energy that will have to be spent to
get from the cell with coordinates 𝑥1,𝑦1 to the cell with coordinates 𝑥2,𝑦2
.

For example, 𝑛=8
 initially you are in a cell with coordinates 1,3
 and you want to get into a cell with coordinates 6,4
. You can immediately make 2
 movements, once you are in a cell with coordinates 3,3
, and then after 8
 seconds you will be in the right cell.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤2⋅105
) — the number of test cases.

The descriptions of the test cases follow.

The description of each test case consists of one string containing five
integers 𝑛 , 𝑥1 , 𝑦1 , 𝑥2 and 𝑦2 (1≤𝑥1,𝑦1,𝑥2,𝑦2≤𝑛≤109 ) — matrix size and the
coordinates of the start and end cells. It is guaranteed that the number 𝑛 is
even.

Output
For each test case, print one integer in a separate line — the minimum amount of
energy that will have to be spent to get from the cell with coordinates 𝑥1,𝑦1 to
the cell with coordinates 𝑥2,𝑦2
.

Example
InputCopy
5
2 1 1 2 2
4 1 4 3 3
8 1 3 4 6
100 10 20 50 100
1000000000 123456789 987654321 998244353 500000004

OutputCopy
0
1
2
9
10590032
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// 1.find layer
int get_layer(int x, int y, int n) { return min({x, y, n - x + 1, n - y + 1}); }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    int x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    // n is size of matrix

    // x1,y1 are start coordinate
    // x2,y2 are end coordinates
    // concentric ribbon moving clockwise
    // return minimum energy to get from x1, y1 to x2, y2
    /*At any point in time, you:

1. Can move instantly to an adjacent cell (up/down/left/right) by spending 1
energy per move, unlimited use.

2. Or stand still and move with the belt, which auto-moves you 1 cell forward on
your ribbon every 1 second, costing 0 energy.

- If start and end are on the same layer, you can just wait until the rotation
brings you there → 0 energy.

- If they are on different layers, you must spend energy to move in/out of
layers to reach the correct one.

    */
    // 1. find layer
    int layer1 = get_layer(x1, y1, n);
    int layer2 = get_layer(x2, y2, n);

    cout << abs(layer1 - layer2) << '\n';
    // 2. If both cells are on the same layer, then energy = 0.
    // else energy = abs(layer1 - layer2)
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1811/331913549
