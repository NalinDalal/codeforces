/*A. Three Pairwise Maximums
time limit per test1 second
memory limit per test256 megabytes
You are given three positive (i.e. strictly greater than zero) integers 𝑥
, 𝑦
 and 𝑧
.

Your task is to find positive integers 𝑎
, 𝑏
 and 𝑐
 such that 𝑥=max(𝑎,𝑏)
, 𝑦=max(𝑎,𝑐)
 and 𝑧=max(𝑏,𝑐)
, or determine that it is impossible to find such 𝑎
, 𝑏
 and 𝑐
.

You have to answer 𝑡
 independent test cases. Print required 𝑎
, 𝑏
 and 𝑐
 in any (arbitrary) order.

Input
The first line of the input contains one integer 𝑡
 (1≤𝑡≤2⋅104
) — the number of test cases. Then 𝑡
 test cases follow.

The only line of the test case contains three integers 𝑥
, 𝑦
, and 𝑧
 (1≤𝑥,𝑦,𝑧≤109
).

Output
For each test case, print the answer:

"NO" in the only line of the output if a solution doesn't exist;
or "YES" in the first line and any valid triple of positive integers 𝑎
, 𝑏
 and 𝑐
 (1≤𝑎,𝑏,𝑐≤109
) in the second line. You can print 𝑎
, 𝑏
 and 𝑐
 in any order.
Example
InputCopy
5
3 2 3
100 100 100
50 49 49
10 30 20
1 1000000000 1000000000
OutputCopy
YES
3 2 1
YES
100 100 100
NO
NO
YES
1 1 1000000000

*/

#include <iostream>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long x, y, z;
    std::cin >> x >> y >> z;

    if (x == y && x >= z) {
      std::cout << "YES\n" << x << " " << z << " " << z << std::endl;
    } else if (x == z && z >= y) {
      std::cout << "YES\n" << x << " " << y << " " << y << std::endl;
    } else if (y == z && y >= x) {
      std::cout << "YES\n" << y << " " << x << " " << x << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1385/310370990
