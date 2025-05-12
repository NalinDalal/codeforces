/* D. I Love 1543
time limit per test2 seconds
memory limit per test256 megabytes
One morning, Polycarp woke up and realized that 1543
 is the most favorite number in his life.

The first thing that Polycarp saw that day as soon as he opened his eyes was a
large wall carpet of size 𝑛 by 𝑚 cells; 𝑛 and 𝑚 are even integers. Each cell
contains one of the digits from 0 to 9
.

Polycarp became curious about how many times the number 1543
 would appear in all layers∗
 of the carpet when traversed clockwise.

∗
The first layer of a carpet of size 𝑛×𝑚
 is defined as a closed strip of length 2⋅(𝑛+𝑚−2)
 and thickness of 1
 element, surrounding its outer part. Each subsequent layer is defined as the
first layer of the carpet obtained by removing all previous layers from the
original carpet.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of test cases. The following lines describe the test cases.

The first line of each test case contains a pair of numbers 𝑛
 and 𝑚
 (2≤𝑛,𝑚≤103
, 𝑛,𝑚
 — even integers).

This is followed by 𝑛
 lines of length 𝑚
, consisting of digits from 0
 to 9
 — the description of the carpet.

It is guaranteed that the sum of 𝑛⋅𝑚
 across all test cases does not exceed 106
.

Output
For each test case, output a single number — the total number of times 1543
 appears in all layers of the carpet in the order of traversal clockwise.

Example
InputCopy
8
2 4
1543
7777
2 4
7154
8903
2 4
3451
8888
2 2
54
13
2 2
51
43
2 6
432015
512034
4 4
5431
1435
5518
7634
6 4
5432
1152
4542
2432
2302
5942
OutputCopy
1
1
0
1
0
2
2
2
Note
Occurrences of 1543 in the seventh example. Different layers are colored in
different colors.

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int count = 0;
    for (int i = 0; (i + 1) * 2 <= n && (i + 1) * 2 <= m; ++i) {
      string layer;

      // Top row
      for (int j = i; j < m - i; ++j)
        layer += a[i][j];
      // Right column
      for (int j = i + 1; j < n - i - 1; ++j)
        layer += a[j][m - i - 1];
      // Bottom row
      for (int j = m - i - 1; j >= i; --j)
        layer += a[n - i - 1][j];
      // Left column
      for (int j = n - i - 2; j >= i + 1; --j)
        layer += a[j][i];

      int pos = layer.size();
      for (int j = 0; j < pos; ++j) {
        if (layer[j] == '1' && layer[(j + 1) % pos] == '5' &&
            layer[(j + 2) % pos] == '4' && layer[(j + 3) % pos] == '3') {
          count++;
        }
      }
    }

    cout << count << '\n';
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2036/319427180
