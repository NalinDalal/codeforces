/* https://codeforces.com/problemset/problem/1837/A

A. Grasshopper on a Line
time limit per test2 seconds
memory limit per test256 megabytes
You are given two integers 𝑥
 and 𝑘
. Grasshopper starts in a point 0
 on an OX axis. In one move, it can jump some integer distance, that is not
divisible by 𝑘 , to the left or to the right.

What's the smallest number of moves it takes the grasshopper to reach point 𝑥
? What are these moves? If there are multiple answers, print any of them.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of testcases.

The only line of each testcase contains two integers 𝑥
 and 𝑘
 (1≤𝑥≤100
; 2≤𝑘≤100
) — the endpoint and the constraint on the jumps, respectively.

Output
For each testcase, in the first line, print a single integer 𝑛
 — the smallest number of moves it takes the grasshopper to reach point 𝑥
.

In the second line, print 𝑛
 integers, each of them not divisible by 𝑘
. A positive integer would mean jumping to the right, a negative integer would
mean jumping to the left. The endpoint after the jumps should be exactly 𝑥
.

Each jump distance should be from −109
 to 109
. In can be shown that, for any solution with the smallest number of jumps,
there exists a solution with the same number of jumps such that each jump is
from −109 to 109
.

It can be shown that the answer always exists under the given constraints. If
there are multiple answers, print any of them.

Example
InputCopy
3
10 2
10 3
3 4
OutputCopy
2
7 3
1
10
1
3

*/
#include <cstdio>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long x, k;
    scanf("%ld %ld", &x, &k);
    if (x % k) {
      printf("1\n%ld\n", x);
    } else {
      printf("2\n1 %ld\n", x - 1);
    }
  }
}

// sub: https://codeforces.com/problemset/submission/1837/300757212
