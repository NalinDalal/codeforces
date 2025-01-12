/* https://codeforces.com/problemset/problem/1845/A
A. Forbidden Integer
time limit per test2 seconds
memory limit per test256 megabytes
You are given an integer 𝑛
, which you want to obtain. You have an unlimited supply of every integer from 1
 to 𝑘
, except integer 𝑥
 (there are no integer 𝑥
 at all).

You are allowed to take an arbitrary amount of each of these integers (possibly,
zero). Can you make the sum of taken integers equal to 𝑛
?

If there are multiple answers, print any of them.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of testcases.

The only line of each testcase contains three integers 𝑛,𝑘
 and 𝑥
 (1≤𝑥≤𝑘≤𝑛≤100
).

Output
For each test case, in the first line, print "YES" or "NO" — whether you can
take an arbitrary amount of each integer from 1 to 𝑘 , except integer 𝑥 , so
that their sum is equal to 𝑛
.

If you can, the second line should contain a single integer 𝑚
 — the total amount of taken integers. The third line should contain 𝑚
 integers — each of them from 1
 to 𝑘
, not equal to 𝑥
, and their sum is 𝑛
.

If there are multiple answers, print any of them.

Example
InputCopy
5
10 3 2
5 2 1
4 2 1
7 7 3
6 1 1
OutputCopy
YES
6
3 1 1 1 1 3
NO
YES
2
2 2
YES
1
7
NO
Note
Another possible answer for the first testcase is [3,3,3,1]
. Note that you don't have to minimize the amount of taken integers. There also
exist other answers.

In the second testcase, you only have an unlimited supply of integer 2
. There is no way to get sum 5
 using only them.

In the fifth testcase, there are no integers available at all, so you can't get
any positive sum.
*/

#include <cstdio>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n, k, x;
    scanf("%ld %ld %ld", &n, &k, &x);
    if (x != 1) {
      printf("YES\n%ld\n", n);
      for (long p = 0; p < n; p++) {
        printf("1 ");
      }
      puts("");
    } else if (k >= 2 && n % 2 == 0) {
      printf("YES\n%ld\n", n / 2);
      for (long p = 0; p < n / 2; p++) {
        printf("2 ");
      }
      puts("");
    } else if (k >= 3) {
      printf("YES\n%ld\n3 ", (n / 2));
      for (long p = 1; p < n / 2; p++) {
        printf("2 ");
      }
      puts("");
    } else {
      puts("NO");
      continue;
    }
  }
}

// sub: https://codeforces.com/problemset/submission/1845/300756944
