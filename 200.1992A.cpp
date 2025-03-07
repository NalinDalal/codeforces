/*A. Only Pluses
time limit per test1 second
memory limit per test256 megabytes
Kmes has written three integers 𝑎
, 𝑏
 and 𝑐
 in order to remember that he has to give Noobish_Monk 𝑎×𝑏×𝑐
 bananas.

Noobish_Monk has found these integers and decided to do the following at most 5
 times:

pick one of these integers;
increase it by 1
.
For example, if 𝑎=2
, 𝑏=3
 and 𝑐=4
, then one can increase 𝑎
 three times by one and increase 𝑏
 two times. After that 𝑎=5
, 𝑏=5
, 𝑐=4
. Then the total number of bananas will be 5×5×4=100
.

What is the maximum value of 𝑎×𝑏×𝑐
 Noobish_Monk can achieve with these operations?

Input
Each test contains multiple test cases. The first line of input contains a
single integer 𝑡 (1≤𝑡≤1000 ) — the number of test cases. The description of the
test cases follows.

The first and only line of each test case contains three integers 𝑎
, 𝑏
 and 𝑐
 (1≤𝑎,𝑏,𝑐≤10
) — Kmes's integers.

Output
For each test case, output a single integer — the maximum amount of bananas
Noobish_Monk can get.

Example
InputCopy
2
2 3 4
10 1 10
OutputCopy
100
600

*/

#include <iostream>

int main() {

  int t;
  std::cin >> t;
  while (t--) {
    long a, b, c;
    std::cin >> a >> b >> c;
    for (long p = 0; p < 5; p++) {
      if (a <= b && a <= c) {
        ++a;
      } else if (b <= a && b <= c) {
        ++b;
      } else if (c <= a && c <= b) {
        ++c;
      }
    }
    std::cout << a * b * c << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1992/309382643
