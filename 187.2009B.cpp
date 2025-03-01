/*B. osu!mania
time limit per test1 second
memory limit per test256 megabytes
You are playing your favorite rhythm game, osu!mania. The layout of your beatmap
consists of 𝑛 rows and 4 columns. Because notes at the bottom are closer, you
will process the bottommost row first and the topmost row last. Each row will
contain exactly one note, represented as a '#'.

For each note 1,2,…,𝑛
, in the order of processing, output the column in which the note appears.

Input
The first line contains 𝑡
 (1≤𝑡≤100
) — the number of test cases.

For each test case, the first line contains 𝑛
 (1≤𝑛≤500
) — the number of rows of the beatmap.

The following 𝑛
 lines contain 4
 characters. The 𝑖
-th line represents the 𝑖
-th row of the beatmap from the top. It is guaranteed that the characters are
either '.' or '#', and exactly one of the characters is '#'.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 500
.

Output
For each test case, output 𝑛
 integers on a new line, the column that the 𝑖
-th note appears in for all 𝑖
 from 1
 to 𝑛
.

Example
InputCopy
3
4
#...
.#..
..#.
...#
2
.#..
.#..
1
...#
OutputCopy
4 3 2 1
2 2
4

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
    vector<int> v(n); // Store the positions of '#'
    for (long p = 0; p < n; p++) {
      std::string s;
      std::cin >> s;
      for (long u = 0; u < 4; u++) {
        if (s[u] == '#') {
          v[p] = u + 1;
          break;
        }
      }
    }

    for (long p = n - 1; p >= 0; p--) {
      std::cout << v[p] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/2009/308483872
