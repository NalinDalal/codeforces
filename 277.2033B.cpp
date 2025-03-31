/*B. Sakurako and Water
time limit per test2 seconds
memory limit per test256 megabytes
During her journey with Kosuke, Sakurako and Kosuke found a valley that can be
represented as a matrix of size 𝑛×𝑛 , where at the intersection of the 𝑖 -th row
and the 𝑗 -th column is a mountain with a height of 𝑎𝑖,𝑗 . If 𝑎𝑖,𝑗<0 , then
there is a lake there.

Kosuke is very afraid of water, so Sakurako needs to help him:

With her magic, she can select a square area of mountains and increase the
height of each mountain on the main diagonal of that area by exactly one. More
formally, she can choose a submatrix with the upper left corner located at (𝑖,𝑗)
 and the lower right corner at (𝑝,𝑞)
, such that 𝑝−𝑖=𝑞−𝑗
. She can then add one to each element at the intersection of the (𝑖+𝑘)
-th row and the (𝑗+𝑘)
-th column, for all 𝑘
 such that 0≤𝑘≤𝑝−𝑖
.

Determine the minimum number of times Sakurako must use her magic so that there
are no lakes.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤200
) — the number of test cases.

Each test case is described as follows:

The first line of each test case consists of a single number 𝑛
 (1≤𝑛≤500
).
Each of the following 𝑛
 lines consists of 𝑛
 integers separated by spaces, which correspond to the heights of the mountains
in the valley 𝑎 (−105≤𝑎𝑖,𝑗≤105
).
It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 1000
.

Output
For each test case, output the minimum number of times Sakurako will have to use
her magic so that all lakes disappear.

Example
InputCopy
4
1
1
2
-1 2
3 0
3
1 2 3
-2 1 -1
0 0 -1
5
1 1 -1 -1 3
-3 1 4 4 -4
-1 -1 3 0 -5
4 5 3 -3 -1
3 1 -3 -1 5
OutputCopy
0
1
4
19


*/

#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(2 * n - 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int x;
        std::cin >> x;
        int idx = (n - 1) + i - j;
        v[idx] = (v[idx] > -x ? v[idx] : -x);
      }
    }
    int total = 0;
    for (int i = 0; i < v.size(); i++)
      total += v[i];
    cout << total << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2033/313211618
