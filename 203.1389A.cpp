/*A. LCM Problem
time limit per test2 seconds
memory limit per test256 megabytes
Let 𝐿𝐶𝑀(𝑥,𝑦)
 be the minimum positive integer that is divisible by both 𝑥
 and 𝑦
. For example, 𝐿𝐶𝑀(13,37)=481
, 𝐿𝐶𝑀(9,6)=18
.

You are given two integers 𝑙
 and 𝑟
. Find two integers 𝑥
 and 𝑦
 such that 𝑙≤𝑥<𝑦≤𝑟
 and 𝑙≤𝐿𝐶𝑀(𝑥,𝑦)≤𝑟
.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤10000
) — the number of test cases.

Each test case is represented by one line containing two integers 𝑙
 and 𝑟
 (1≤𝑙<𝑟≤109
).

Output
For each test case, print two integers:

if it is impossible to find integers 𝑥
 and 𝑦
 meeting the constraints in the statement, print two integers equal to −1
;
otherwise, print the values of 𝑥
 and 𝑦
 (if there are multiple valid answers, you may print any of them).
Example
InputCopy
4
1 1337
13 69
2 4
88 89
OutputCopy
6 7
14 21
2 4
-1 -1

*/
#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int l, r;
    std::cin >> l >> r;
    if (2 * l > r)
      std::cout << -1 << " " << -1 << std::endl;
    else
      std::cout << l << " " << 2 * l << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1389/309486596
