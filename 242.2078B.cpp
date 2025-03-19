/*B. Vicious Labyrinth
time limit per test1.5 seconds
memory limit per test256 megabytes
Axium Crisis - ak+q
There are 𝑛
 cells in a labyrinth, and cell 𝑖
 (1≤𝑖≤𝑛
) is 𝑛−𝑖
 kilometers away from the exit. In particular, cell 𝑛
 is the exit. Note also that each cell is connected to the exit but is not
accessible from any other cell in any way.

In each cell, there is initially exactly one person stuck in it. You want to
help everyone get as close to the exit as possible by installing a teleporter in
each cell 𝑖 (1≤𝑖≤𝑛
), which translocates the person in that cell to another cell 𝑎𝑖
.

The labyrinth owner caught you in the act. Amused, she let you continue, but
under some conditions:

Everyone must use the teleporter exactly 𝑘
 times.
No teleporter in any cell can lead to the same cell it is in. Formally, 𝑖≠𝑎𝑖
 for all 1≤𝑖≤𝑛
.
You must find a teleporter configuration that minimizes the sum of distances of
all individuals from the exit after using the teleporter exactly 𝑘 times while
still satisfying the restrictions of the labyrinth owner.

If there are many possible configurations, you can output any of them.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first and only line of each test case contains two integers 𝑛
 and 𝑘
 (2≤𝑛≤2⋅105
, 1≤𝑘≤109
) — the number of cells in the labyrinth and the value 𝑘
.

It is guaranteed that the total sum of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output 𝑛
 integers — the destinations of the teleporters 𝑎1,𝑎2,…,𝑎𝑛
 in order, satisfying the given conditions (1≤𝑎𝑖≤𝑛
, 𝑎𝑖≠𝑖
).

Example
InputCopy
2
2 1
3 2
OutputCopy
2 1
2 3 2
Note
In the first test case, the position of each person is as follows.

Before teleporting: [1,2]
.
First teleportation: [2,1]
.
The distance sum is (2−2)+(2−1)=1
, which is the minimum possible.

In the second test case, the position of each person is as follows.

Before teleporting: [1,2,3]
.
First teleportation: [2,3,2]
.
Second teleportation: [3,2,3]
.
The distance sum is (3−3)+(3−2)+(3−3)=1
, which is the minimum possible.*/

#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    k %= 2;
    for (int i = 1; i <= n - 2; i++)
      cout << n - !k << " ";
    cout << n << " " << n - 1 << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2078/311372116
