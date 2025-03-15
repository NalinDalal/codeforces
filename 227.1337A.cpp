/* A. Ichihime and Triangle
time limit per test1 second
memory limit per test256 megabytes
Ichihime is the current priestess of the Mahjong Soul Temple. She claims to be
human, despite her cat ears.

These days the temple is holding a math contest. Usually, Ichihime lacks
interest in these things, but this time the prize for the winner is her favorite
— cookies. Ichihime decides to attend the contest. Now she is solving the
following problem.



You are given four positive integers 𝑎
, 𝑏
, 𝑐
, 𝑑
, such that 𝑎≤𝑏≤𝑐≤𝑑
.

Your task is to find three integers 𝑥
, 𝑦
, 𝑧
, satisfying the following conditions:

𝑎≤𝑥≤𝑏
.
𝑏≤𝑦≤𝑐
.
𝑐≤𝑧≤𝑑
.
There exists a triangle with a positive non-zero area and the lengths of its
three sides are 𝑥 , 𝑦 , and 𝑧
.
Ichihime desires to get the cookie, but the problem seems too hard for her. Can
you help her?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
)  — the number of test cases.

The next 𝑡
 lines describe test cases. Each test case is given as four space-separated
integers 𝑎 , 𝑏 , 𝑐 , 𝑑 (1≤𝑎≤𝑏≤𝑐≤𝑑≤109
).

Output
For each test case, print three integers 𝑥
, 𝑦
, 𝑧
  — the integers you found satisfying the conditions given in the statement.

It is guaranteed that the answer always exists. If there are multiple answers,
print any.

Example
InputCopy
4
1 3 5 7
1 5 5 7
100000 200000 300000 400000
1 1 977539810 977539810
OutputCopy
3 4 5
5 5 5
182690 214748 300999
1 977539810 977539810
Note
One of the possible solutions to the first test case:
3 5 4


One of the possible solutions to the second test case:
5 5 5
*/
#include <cstdio>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long a, b, c, d;
    scanf("%ld %ld %ld %ld", &a, &b, &c, &d);
    printf("%ld %ld %ld\n", b, c, c);
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/1337/310721065
