/* A. Coins
time limit per test2 seconds
memory limit per test256 megabytes
In Berland, there are two types of coins, having denominations of 2
 and 𝑘
 burles.

Your task is to determine whether it is possible to represent 𝑛
 burles in coins, i. e. whether there exist non-negative integers 𝑥
 and 𝑦
 such that 2⋅𝑥+𝑘⋅𝑦=𝑛
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The only line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑘≤𝑛≤1018
; 𝑘≠2
).

Output
For each test case, print YES if it is possible to represent 𝑛
 burles in coins; otherwise, print NO. You may print each letter in any case
(YES, yes, Yes will all be recognized as positive answer, NO, no and nO will all
be recognized as negative answer).

Example
InputCopy
4
5 3
6 1
7 4
8 8
OutputCopy
YES
YES
NO
YES
Note
In the first test case, you can take one coin with denomination 2
 and one coin with denomination 𝑘=3
.

In the second test case, you can take three coins with denomination 2
. Alternatively, you can take six coins with denomination 𝑘=1
.

In the third test case, there is no way to represent 7
 burles.

In the fourth test case, you can take one coin with denomination 𝑘=8
.


*/

#include <cstdio>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    bool res = (n % 2 == 0) || ((n - k) % 2 == 0);
    puts(res ? "YES" : "NO");
  }
}

// sub: https://codeforces.com/problemset/submission/1814/301020923
