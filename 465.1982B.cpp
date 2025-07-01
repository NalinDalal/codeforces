/*B. Collatz Conjecture
time limit per test1 second
memory limit per test256 megabytes
Recently, the first-year student Maxim learned about the Collatz conjecture, but
he didn't pay much attention during the lecture, so he believes that the
following process is mentioned in the conjecture:

There is a variable 𝑥
 and a constant 𝑦
. The following operation is performed 𝑘
 times:

increase 𝑥
 by 1
, then
while the number 𝑥
 is divisible by 𝑦
, divide it by 𝑦
.
Note that both of these actions are performed sequentially within one operation.
For example, if the number 𝑥=16
, 𝑦=3
, and 𝑘=2
, then after one operation 𝑥
 becomes 17
, and after another operation 𝑥
 becomes 2
, because after adding one, 𝑥=18
 is divisible by 3
 twice.

Given the initial values of 𝑥
, 𝑦
, and 𝑘
, Maxim wants to know what is the final value of 𝑥
.

Input
Each test consists of multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. Then follows the description of the test cases.

The only line of each test case contains three integers 𝑥
, 𝑦
, and 𝑘
 (1≤𝑥,𝑘≤109
, 2≤𝑦≤109
) — the initial variable, constant and the number of operations.

Output
For each test case, output a single integer — the number obtained after applying
𝑘 operations.

Example
InputCopy
13
1 3 1
2 3 1
24 5 5
16 3 2
2 2 1
1337 18 1
1 2 144133
12345678 3 10
998244353 2 998244353
998244353 123456789 998244352
998244354 998241111 998244352
998244355 2 9982443
1000000000 1000000000 1000000000
OutputCopy
2
1
1
2
3
1338
1
16936
1
21180097
6486
1
2
Note
In the first test case, there is only one operation applied to 𝑥=1
, resulting in 𝑥
 becoming 2
.

In the second test case, for 𝑥=2
, within one operation, one is added to 𝑥
 and it's divided by 𝑦=3
, resulting in 𝑥
 becoming 1
.

In the third test case, 𝑥
 changes as follows:

After the first operation, 𝑥=1
, because 24+1=25
 and 25
 is divisible by 𝑦=5
 twice within one operation.
After the second operation, 𝑥=2
.
After the third operation, 𝑥=3
.
After the fourth operation, 𝑥=4
.
After the fifth operation, 𝑥=1
.


*/
#include <iostream>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long x, y, k;
    std::cin >> x >> y >> k;
    long res = 0;
    while (k && x != 1) {
      long long d = (x / y + 1) * y - x;
      if (!d) {
        d = 1;
      }
      if (d > k) {
        d = k;
      }
      x += d;
      while (x % y == 0) {
        x /= y;
      }
      k -= d;
    }
    std::cout << (x + k % (y - 1)) << std::endl;
  }
}
// sub:
