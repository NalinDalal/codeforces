/*C. Tiles Comeback
time limit per test2 seconds
memory limit per test256 megabytes
Vlad remembered that he had a series of 𝑛
 tiles and a number 𝑘
. The tiles were numbered from left to right, and the 𝑖
-th tile had colour 𝑐𝑖
.

If you stand on the first tile and start jumping any number of tiles right, you
can get a path of length 𝑝 . The length of the path is the number of tiles you
stood on.

Vlad wants to see if it is possible to get a path of length 𝑝
 such that:

it ends at tile with index 𝑛
;
𝑝
 is divisible by 𝑘
the path is divided into blocks of length exactly 𝑘
 each;
tiles in each block have the same colour, the colors in adjacent blocks are not
necessarily different. For example, let 𝑛=14 , 𝑘=3
.

The colours of the tiles are contained in the array 𝑐
 = [1,2,1,1,7,5,3,3,1,3,4,4,2,4
]. Then we can construct a path of length 6
 consisting of 2
 blocks:

𝑐1→𝑐3→𝑐4→𝑐11→𝑐12→𝑐14

All tiles from the 1
-st block will have colour 1
, from the 2
-nd block will have colour 4
.

It is also possible to construct a path of length 9
 in this example, in which all tiles from the 1
-st block will have colour 1
, from the 2
-nd block will have colour 3
, and from the 3
-rd block will have colour 4
.

Input
The first line of input data contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑘≤𝑛≤2⋅105
)—the number of tiles in the series and the length of the block.

The second line of each test case contains 𝑛
 integers 𝑐1,𝑐2,𝑐3,…,𝑐𝑛
 (1≤𝑐𝑖≤𝑛
) — the colours of the tiles.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output on a separate line:

YES if you can get a path that satisfies these conditions;
NO otherwise.
You can output YES and NO in any case (for example, strings yEs, yes, Yes and
YES will be recognized as positive response).

Example
InputCopy
10
4 2
1 1 1 1
14 3
1 2 1 1 7 5 3 3 1 3 4 4 2 4
3 3
3 1 3
10 4
1 2 1 2 1 2 1 2 1 2
6 2
1 3 4 1 6 6
2 2
1 1
4 2
2 1 1 1
2 1
1 2
3 2
2 2 2
4 1
1 1 2 2
OutputCopy
YES
YES
NO
NO
YES
YES
NO
YES
YES
YES
Note
In the first test case, you can jump from the first tile to the last tile;

The second test case is explained in the problem statement.



*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; ++i)
      cin >> c[i];

    if (c[0] == c[n - 1]) {
      int cnt = 0;
      for (int i = 0; i < n; ++i)
        if (c[i] == c[0])
          ++cnt;
      if (cnt >= k)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      int left = -1, right = -1, cnt = 0;
      // Find k-th occurrence of c[0] from the left
      for (int i = 0; i < n; ++i) {
        if (c[i] == c[0])
          ++cnt;
        if (cnt == k) {
          left = i;
          break;
        }
      }
      cnt = 0;
      // Find k-th occurrence of c[n-1] from the right
      for (int i = n - 1; i >= 0; --i) {
        if (c[i] == c[n - 1])
          ++cnt;
        if (cnt == k) {
          right = i;
          break;
        }
      }
      if (left != -1 && right != -1 && left < right)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1851/328694129
