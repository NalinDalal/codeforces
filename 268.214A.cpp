/*
 A. System of Equations
time limit per test2 seconds
memory limit per test256 megabytes
Furik loves math lessons very much, so he doesn't attend them, unlike Rubik. But
now Furik wants to get a good mark for math. For that Ms. Ivanova, his math
teacher, gave him a new task. Furik solved the task immediately. Can you?

You are given a system of equations:


You should count, how many there are pairs of integers (a, b) (0 ≤ a, b) which
satisfy the system.

Input
A single line contains two integers n, m (1 ≤ n, m ≤ 1000) — the parameters of
the system. The numbers on the line are separated by a space.

Output
On a single line print the answer to the problem.

Examples
InputCopy
9 3
OutputCopy
1
InputCopy
14 28
OutputCopy
1
InputCopy
4 20
OutputCopy
0
Note
In the first sample the suitable pair is integers (3, 0). In the second sample
the suitable pair is integers (3, 5). In the third sample there is no suitable
pair.
 */
#include <iostream>
int main() {
  int n, m;
  std::cin >> n >> m;
  // find a,b such that a^2+b=n,b^2+a=m
  int a, b;
  // m+n=a^2+b^2+a+b
  // return how many pair of a,b can satisfy this
  int ans = 0;
  for (int a = 0; a * a <= n; a++) {
    b = n - a * a;
    if (a + b * b == m) {
      ans++;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
// ans:https://codeforces.com/problemset/submission/214/312677854
