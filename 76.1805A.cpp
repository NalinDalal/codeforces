/* https://codeforces.com/problemset/problem/1805/A
A. We Need the Zero

There is an array 𝑎 consisting of non-negative integers. You can choose an
integer 𝑥 and denote 𝑏𝑖=𝑎𝑖⊕𝑥 for all 1≤𝑖≤𝑛, where ⊕ denotes the bitwise XOR
operation. Is it possible to choose such a number 𝑥 that the value of the
expression 𝑏1⊕𝑏2⊕…⊕𝑏𝑛 equals 0?

It can be shown that if a valid number 𝑥 exists, then there also exists 𝑥 such
that (0≤𝑥<28).

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤1000). The description of the test cases follows.

The first line of the test case contains one integer 𝑛 (1≤𝑛≤103) — the length of
the array 𝑎.

The second line of the test case contains 𝑛 integers — array 𝑎 (0≤𝑎𝑖<28).

It is guaranteed that the sum of 𝑛 over all test cases does not exceed 103.

Output
For each set test case, print the integer 𝑥 (0≤𝑥<28) if it exists, or −1
otherwise.

Example
InputCopy
5
3
1 2 5
3
1 2 3
4
0 1 2 3
4
1 2 2 3
1
1
OutputCopy
6
0
3
-1
1

Note
In the first test case, after applying the operation with the number 6 the array
𝑏 becomes [7,4,3], 7⊕4⊕3=0. There are other answers in the third test case, such
as the number 0.
*/
#include <cstdio>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n;
    scanf("%ld", &n);
    long cs(0);
    for (long p = 0; p < n; p++) {
      long x;
      scanf("%ld", &x);
      cs = cs ^ x;
    }

    if (n % 2) {
      printf("%ld\n", cs);
    } else {
      printf("%d\n", cs ? -1 : 0);
    }
  }
}

// sub: https://codeforces.com/problemset/submission/1805/301103255
