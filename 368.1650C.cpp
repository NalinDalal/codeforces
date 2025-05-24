/* C. Weight of the System of Nested Segments
time limit per test2 seconds
memory limit per test256 megabytes
On the number line there are 𝑚
 points, 𝑖
-th of which has integer coordinate 𝑥𝑖
 and integer weight 𝑤𝑖
. The coordinates of all points are different, and the points are numbered from
1 to 𝑚
.

A sequence of 𝑛
 segments [𝑙1,𝑟1],[𝑙2,𝑟2],…,[𝑙𝑛,𝑟𝑛]
 is called system of nested segments if for each pair 𝑖,𝑗
 (1≤𝑖<𝑗≤𝑛
) the condition 𝑙𝑖<𝑙𝑗<𝑟𝑗<𝑟𝑖
 is satisfied. In other words, the second segment is strictly inside the first
one, the third segment is strictly inside the second one, and so on.

For a given number 𝑛
, find a system of nested segments such that:

both ends of each segment are one of 𝑚
 given points;
the sum of the weights 2⋅𝑛
 of the points used as ends of the segments is minimal.
For example, let 𝑚=8
. The given points are marked in the picture, their weights are marked in red,
their coordinates are marked in blue. Make a system of three nested segments:

weight of the first segment: 1+1=2
weight of the second segment: 10+(−1)=9
weight of the third segment: 3+(−2)=1
sum of the weights of all the segments in the system: 2+9+1=12
System of three nested segments
Input
The first line of input data contains an integer 𝑡
 (1≤𝑡≤104
) —the number of input test cases.

An empty line is written before each test case.

The first line of each test case contains two positive integers 𝑛
 (1≤𝑛≤105
) and 𝑚
 (2⋅𝑛≤𝑚≤2⋅105
).

The next 𝑚
 lines contain pairs of integers 𝑥𝑖
 (−109≤𝑥𝑖≤109
) and 𝑤𝑖
 (−104≤𝑤𝑖≤104
) — coordinate and weight of point number 𝑖
 (1≤𝑖≤𝑚
) respectively. All 𝑥𝑖
 are different.

It is guaranteed that the sum of 𝑚
 values over all test cases does not exceed 2⋅105
.

Output
For each test case, output 𝑛+1
 lines: in the first of them, output the weight of the composed system, and in
the next 𝑛 lines output exactly two numbers  — the indices of the points which
are the endpoints of the 𝑖 -th segment (1≤𝑖≤𝑛
). The order in which you output the endpoints of a segment is not important —
you can output the index of the left endpoint first and then the number of the
right endpoint, or the other way around.

If there are several ways to make a system of nested segments with minimal
weight, output any of them.

Example
InputCopy
3

3 8
0 10
-2 1
4 10
11 20
7 -1
9 1
2 3
5 -2

3 6
-1 2
1 3
3 -1
2 4
4 0
8 2

2 5
5 -1
3 -2
1 0
-2 0
-5 -3
OutputCopy
12
2 6
5 1
7 8

10
1 6
5 2
3 4

-6
5 1
4 2
Note
The first test case coincides with the example from the condition. It can be
shown that the weight of the composed system is minimal.

The second test case has only 6
 points, so you need to use each of them to compose 3
 segments.


*/

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    std::vector<std::pair<int, std::pair<int, int>>> v(m);
    for (long p = 0; p < m; p++) {
      scanf("%ld %ld", &v[p].second.first, &v[p].first);
      v[p].second.second = p + 1;
    }
    sort(v.begin(), v.end());
    std::vector<std::pair<int, int>> z(2 * n);
    long long wsum = 0;
    for (long p = 0; p < 2 * n; p++) {
      wsum += v[p].first;
      z[p] = v[p].second;
    }
    cout << wsum << endl;
    sort(z.begin(), z.end());
    for (long p = 0; p < n; p++) {
      printf("%ld %ld\n", z[p].second, z[2 * n - 1 - p].second);
    }
    puts("");
  }
}
// sub: https://codeforces.com/problemset/submission/1650/321007604
