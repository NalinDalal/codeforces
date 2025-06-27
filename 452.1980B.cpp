/*B. Choosing Cubes
time limit per test1 second
memory limit per test256 megabytes
Dmitry has 𝑛
 cubes, numbered from left to right from 1
 to 𝑛
. The cube with index 𝑓
 is his favorite.

Dmitry threw all the cubes on the table, and the 𝑖
-th cube showed the value 𝑎𝑖
 (1≤𝑎𝑖≤100
). After that, he arranged the cubes in non-increasing order of their values,
from largest to smallest. If two cubes show the same value, they can go in any
order.

After sorting, Dmitry removed the first 𝑘
 cubes. Then he became interested in whether he removed his favorite cube (note
that its position could have changed after sorting).

For example, if 𝑛=5
, 𝑓=2
, 𝑎=[4,3,3,2,3]
 (the favorite cube is highlighted in green), and 𝑘=2
, the following could have happened:

After sorting 𝑎=[4,3,3,3,2]
, since the favorite cube ended up in the second position, it will be removed.
After sorting 𝑎=[4,3,3,3,2]
, since the favorite cube ended up in the third position, it will not be
removed. Input The first line contains an integer 𝑡 (1≤𝑡≤1000 ) — the number of
test cases. Then follow the descriptions of the test cases.

The first line of each test case description contains three integers 𝑛
, 𝑓
, and 𝑘
 (1≤𝑓,𝑘≤𝑛≤100
) — the number of cubes, the index of Dmitry's favorite cube, and the number of
removed cubes, respectively.

The second line of each test case description contains 𝑛
 integers 𝑎𝑖
 (1≤𝑎𝑖≤100
) — the values shown on the cubes.

Output
For each test case, output one line — "YES" if the cube will be removed in all
cases, "NO" if it will not be removed in any case, "MAYBE" if it may be either
removed or left.

You can output the answer in any case. For example, the strings "YES", "nO",
"mAyBe" will be accepted as answers.

Example
InputCopy
12
5 2 2
4 3 3 2 3
5 5 3
4 2 1 3 5
5 5 2
5 2 4 1 3
5 5 5
1 2 5 4 3
5 5 4
3 1 2 4 5
5 5 5
4 3 2 1 5
6 5 3
1 2 3 1 2 3
10 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1
42
5 2 3
2 2 1 1 2
2 1 1
2 1
5 3 1
3 3 2 3 2
OutputCopy
MAYBE
YES
NO
YES
YES
YES
MAYBE
MAYBE
YES
YES
YES
NO


*/

#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> v(n);
    --f;
    for (int i = 0; i < n; i++)
      cin >> v[i];
    int scnt = 0, bcnt = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] > v[f])
        bcnt++;
      else if (v[i] == v[f])
        cnt++;
      else
        scnt++;
    }

    if (k <= bcnt)
      cout << "NO" << endl;
    else if (k >= bcnt + cnt)
      cout << "YES" << endl;
    else
      cout << "MAYBE" << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1980/326243431
