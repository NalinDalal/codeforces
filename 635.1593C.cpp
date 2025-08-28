/*C. Save More Mice
time limit per test4 seconds
memory limit per test256 megabytes
There are one cat, 𝑘
 mice, and one hole on a coordinate line. The cat is located at the point 0
, the hole is located at the point 𝑛
. All mice are located between the cat and the hole: the 𝑖
-th mouse is located at the point 𝑥𝑖
 (0<𝑥𝑖<𝑛
). At each point, many mice can be located.

In one second, the following happens. First, exactly one mouse moves to the
right by 1 . If the mouse reaches the hole, it hides (i.e. the mouse will not
any more move to any point and will not be eaten by the cat). Then (after that
the mouse has finished its move) the cat moves to the right by 1 . If at the new
cat's position, some mice are located, the cat eats them (they will not be able
to move after that). The actions are performed until any mouse hasn't been
hidden or isn't eaten.

In other words, the first move is made by a mouse. If the mouse has reached the
hole, it's saved. Then the cat makes a move. The cat eats the mice located at
the pointed the cat has reached (if the cat has reached the hole, it eats
nobody).

Each second, you can select a mouse that will make a move. What is the maximum
number of mice that can reach the hole without being eaten?

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. Then 𝑡
 test cases follow.

Each test case consists of two lines. The first line contains two integers 𝑛
 and 𝑘
 (2≤𝑛≤109
, 1≤𝑘≤4⋅105
). The second line contains 𝑘
 integers 𝑥1,𝑥2,…𝑥𝑘
 (1≤𝑥𝑖<𝑛
) — the initial coordinates of the mice.

It is guaranteed that the sum of all 𝑘
 given in the input doesn't exceed 4⋅105
.

Output
For each test case output on a separate line an integer 𝑚
 (𝑚≥0
) — the maximum number of mice that can reach the hole without being eaten.

Example
InputCopy
3
10 6
8 7 5 4 9 4
2 8
1 1 1 1 1 1 1 1
12 11
1 2 3 4 5 6 7 8 9 10 11
OutputCopy
3
1
4


*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// One of the best problems
// we need rem strictly greater than zero to account for the cat being in that
// position, even if we have enough time to save the mouse Look at the second
// test case in the example
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n, k;
    cin >> n >> k;
    vector<long> dist(k);
    for (long p = 0; p < k; p++) {
      long x;
      cin >> x;
      dist[p] = n - x;
    }

    sort(dist.begin(), dist.end());

    long cnt = 0, rem = n;
    for (long p = 0; rem > 0 && p < (long)dist.size(); p++) {
      rem -= dist[p];
      if (rem > 0)
        cnt++;
    }

    cout << cnt << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1593/335918104
