/* A. Diagonals
time limit per test1 second
memory limit per test256 megabytes
Vitaly503 is given a checkered board with a side of 𝑛
 and 𝑘
 chips. He realized that all these 𝑘
 chips need to be placed on the cells of the board (no more than one chip can be
placed on a single cell).

Let's denote the cell in the 𝑖
-th row and 𝑗
-th column as (𝑖,𝑗)
. A diagonal is the set of cells for which the value 𝑖+𝑗
 is the same. For example, cells (3,1)
, (2,2)
, and (1,3)
 lie on the same diagonal, but (1,2)
 and (2,3)
 do not. A diagonal is called occupied if it contains at least one chip.

Determine what is the minimum possible number of occupied diagonals among all
placements of 𝑘 chips.

Input
Each test consists of several sets of input data. The first line contains a
single integer 𝑡 (1≤𝑡≤500 ) — the number of sets of input data. Then follow the
descriptions of the sets of input data.

The only line of each set of input data contains two integers 𝑛
, 𝑘
 (1≤𝑛≤100,0≤𝑘≤𝑛2
) — the side of the checkered board and the number of available chips,
respectively.

Output
For each set of input data, output a single integer — the minimum number of
occupied diagonals with at least one chip that he can get after placing all 𝑘
 chips.

Example
InputCopy
7
1 0
2 2
2 3
2 4
10 50
100 239
3 9
OutputCopy
0
1
2
3
6
3
5
Note
In the first test case, there are no chips, so 0 diagonals will be occupied. In
the second test case, both chips can be placed on diagonal (2,1),(1,2) , so the
answer is 1. In the third test case, 3 chips can't be placed on one diagonal,
but placing them on (1,2),(2,1),(1,1) makes 2 diagonals occupied. In the 7th
test case, chips will occupy all 5 diagonals in any valid placing.


*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    if (k == 0) {
      cout << 0 << '\n';
      continue;
    }

    // Compute sizes of all 2n - 1 diagonals
    vector<int> diag_sizes;
    for (int s = 2; s <= 2 * n; ++s) {
      int size = min(s - 1, 2 * n - s + 1);
      diag_sizes.push_back(size);
    }

    // Sort diagonals in descending size to pack as many chips as possible
    sort(diag_sizes.rbegin(), diag_sizes.rend());

    int occupied = 0;
    for (int sz : diag_sizes) {
      if (k <= 0)
        break;
      int use = min(sz, k);
      k -= use;
      occupied++;
    }

    cout << occupied << '\n';
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1995/322610941
