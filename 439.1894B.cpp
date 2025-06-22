/*B. Two Out of Three
time limit per test3 seconds
memory limit per test512 megabytes
You are given an array 𝑎1,𝑎2,…,𝑎𝑛
. You need to find an array 𝑏1,𝑏2,…,𝑏𝑛
 consisting of numbers 1
, 2
, 3
 such that exactly two out of the following three conditions are satisfied:

There exist indices 1≤𝑖,𝑗≤𝑛
 such that 𝑎𝑖=𝑎𝑗
, 𝑏𝑖=1
, 𝑏𝑗=2
.
There exist indices 1≤𝑖,𝑗≤𝑛
 such that 𝑎𝑖=𝑎𝑗
, 𝑏𝑖=1
, 𝑏𝑗=3
.
There exist indices 1≤𝑖,𝑗≤𝑛
 such that 𝑎𝑖=𝑎𝑗
, 𝑏𝑖=2
, 𝑏𝑗=3
.
If such an array does not exist, you should report it.

Input
Each test contains multiple test cases. The first line contains a single integer
𝑡 (1≤𝑡≤500) — the number of test cases. Each test case is described as follows.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤100)
 — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤100)
 — the elements of the array 𝑎
.

Output
For each test case, print -1 if there is no solution. Otherwise, print
𝑏1,𝑏2,…,𝑏𝑛 — an array consisting of numbers 1 , 2 , 3 that satisfies exactly two
out of three conditions. If there are multiple possible answers, you can print
any of them.

Example
InputCopy
9
6
1 2 3 2 2 3
7
7 7 7 7 7 7 7
4
1 1 2 2
7
1 2 3 4 5 6 7
5
2 3 3 3 2
3
1 2 1
9
1 1 1 7 7 7 9 9 9
1
1
18
93 84 50 21 88 52 16 50 63 1 30 85 29 67 63 58 37 69
OutputCopy
1 2 3 1 1 1
-1
3 2 2 1
-1
2 1 2 1 3
-1
1 1 2 2 1 2 2 3 3
-1
3 2 1 3 3 3 3 2 2 1 1 2 3 1 3 1 1 2
Note
In the first test case, 𝑏=[1,2,3,1,1,1]
 satisfies condition 1
 because for 𝑖=4
, 𝑗=2
: 𝑎𝑖=𝑎𝑗
, 𝑏𝑖=1
, and 𝑏𝑗=2
. It also satisfies condition 2
 because for 𝑖=6
, 𝑗=3
: 𝑎𝑖=𝑎𝑗
, 𝑏𝑖=1
, and 𝑏𝑗=3
. However, it does not satisfy condition 3
. In total, exactly two out of three conditions are satisfied.



*/

#include <cstdio>
#include <vector>

int main() {

  const int B = 107;

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n;
    scanf("%ld", &n);
    std::vector<std::vector<int>> m(B, std::vector<int>());
    std::vector<long> a(n), b(n, 1);

    long dupes(0);
    for (long p = 0; p < n; p++) {
      scanf("%ld", &a[p]);
      m[a[p]].push_back(p);
      if (m[a[p]].size() == 2) {
        ++dupes;
      }
    }

    if (dupes < 2) {
      puts("-1");
      continue;
    }
    int cur(0);
    for (long p = 0; p < B; p++) {
      if (m[p].size() < 2) {
        continue;
      }
      b[m[p][0]] = 2 + cur;
      cur = 1 - cur;
    }

    for (long p = 0; p < n; p++) {
      printf("%ld ", b[p]);
    }
    puts("");
  }
}
// sub: https://codeforces.com/problemset/submission/1894/325516140
