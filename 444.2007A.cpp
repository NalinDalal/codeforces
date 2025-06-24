/* A. Dora's Set
time limit per test1 second
memory limit per test256 megabytes
Dora has a set 𝑠
 containing integers. In the beginning, she will put all integers in [𝑙,𝑟]
 into the set 𝑠
. That is, an integer 𝑥
 is initially contained in the set if and only if 𝑙≤𝑥≤𝑟
. Then she allows you to perform the following operations:

Select three distinct integers 𝑎
, 𝑏
, and 𝑐
 from the set 𝑠
, such that gcd(𝑎,𝑏)=gcd(𝑏,𝑐)=gcd(𝑎,𝑐)=1†
.
Then, remove these three integers from the set 𝑠
.
What is the maximum number of operations you can perform?

†
Recall that gcd(𝑥,𝑦)
 means the greatest common divisor of integers 𝑥
 and 𝑦
.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤500 ) — the number of test cases. The description of the test
cases follows.

The only line of each test case contains two integers 𝑙
 and 𝑟
 (1≤𝑙≤𝑟≤1000
) — the range of integers in the initial set.

Output
For each test case, output a single integer — the maximum number of operations
you can perform.

Example
InputCopy
8
1 3
3 7
10 21
2 8
51 60
2 15
10 26
1 1000
OutputCopy
1
1
3
1
2
3
4
250
Note
In the first test case, you can choose 𝑎=1
, 𝑏=2
, 𝑐=3
 in the only operation, since gcd(1,2)=gcd(2,3)=gcd(1,3)=1
, and then there are no more integers in the set, so no more operations can be
performed.

In the second test case, you can choose 𝑎=3
, 𝑏=5
, 𝑐=7
 in the only operation.

In the third test case, you can choose 𝑎=11
, 𝑏=19
, 𝑐=20
 in the first operation, 𝑎=13
, 𝑏=14
, 𝑐=15
 in the second operation, and 𝑎=10
, 𝑏=17
, 𝑐=21
 in the third operation. After the three operations, the set 𝑠
 contains the following integers: 12
, 16
, 18
. It can be proven that it's impossible to perform more than 3
 operations.



*/
#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int a, b;
    std::cin >> a >> b;
    std::cout << ((b + 1) / 2 - (a / 2)) / 2 << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2007/325898820
