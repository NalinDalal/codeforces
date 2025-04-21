/*A. Maximize?
time limit per test2 seconds
memory limit per test256 megabytes
You are given an integer 𝑥
. Your task is to find any integer 𝑦
 (1≤𝑦<𝑥)
 such that gcd(𝑥,𝑦)+𝑦
 is maximum possible.

Note that if there is more than one 𝑦
 which satisfies the statement, you are allowed to find any.

gcd(𝑎,𝑏)
 is the Greatest Common Divisor of 𝑎
 and 𝑏
. For example, gcd(6,4)=2
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

Each of the following 𝑡
 lines contains a single integer 𝑥
 (2≤𝑥≤1000
).

Output
For each test case, output any 𝑦
 (1≤𝑦<𝑥
), which satisfies the statement.

Example
InputCopy
7
10
7
21
100
2
1000
6
OutputCopy
5
6
18
98
1
750
3

*/
#include <cstdio>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long x;
    scanf("%ld", &x);
    printf("%ld\n", x - 1);
  }
}
// sub: https://codeforces.com/problemset/submission/1968/316456599
