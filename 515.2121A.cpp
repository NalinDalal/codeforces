/*A. Letter Home
time limit per test1 second
memory limit per test256 megabytes
You are given an array of distinct integers 𝑥1,𝑥2,…,𝑥𝑛
 and an integer 𝑠
.

Initially, you are at position 𝑝𝑜𝑠=𝑠
 on the 𝑋
 axis. In one step, you can perform exactly one of the following two actions:

Move from position 𝑝𝑜𝑠
 to position 𝑝𝑜𝑠+1
.
Move from position 𝑝𝑜𝑠
 to position 𝑝𝑜𝑠−1
.
A sequence of steps will be considered successful if, during the entire journey,
you visit each position 𝑥𝑖 on the 𝑋 axis at least once. Note that the initial
position 𝑝𝑜𝑠=𝑠 is also considered visited.

Your task is to determine the minimum number of steps in any successful sequence
of steps.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤1000 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑠
 (1≤𝑛≤10
, 1≤𝑠≤100
) — the number of positions to visit and the starting position.

The second line of each test case contains 𝑛
 integers 𝑥1,𝑥2,…,𝑥𝑛
 (1≤𝑥𝑖≤100
). It is guaranteed that for all 1≤𝑖<𝑛
, it holds that 𝑥𝑖<𝑥𝑖+1
.

Output
For each test case, output the minimum number of steps in any successful
sequence of steps.

Example
InputCopy
12
1 1
1
1 2
1
1 1
2
2 1
2 3
2 2
1 3
2 3
1 2
3 1
1 2 3
3 2
1 3 4
3 3
1 2 3
4 3
1 2 3 10
5 5
1 2 3 6 7
6 6
1 2 3 9 10 11
OutputCopy
0
1
1
2
3
2
2
4
2
11
8
15
Note
In the first test case, no steps need to be taken, so the only visited position
will be 1
.

In the second test case, the following path can be taken: 2→1
. The number of steps is 1
.

In the third test case, the following path can be taken: 1→2
. The number of steps is 1
.

In the fifth test case, the following path can be taken: 2→1→2→3
. The number of steps is 3.
*/

#include <iostream>
using namespace std;

int main() {
  long t;
  cin >> t;
  while (t--) {
    long n, s;
    cin >> n >> s;
    long left = 0, right = 0;
    for (long p = 0; p < n; p++) {
      long x;
      cin >> x;
      if (x < s) {
        long u = s - x;
        left = (left > u ? left : u);
      } else {
        long u = x - s;
        right = (right > u ? right : u);
      }
    }
    long total = left + right + (left < right ? left : right);
    cout << total << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2121/329712946
