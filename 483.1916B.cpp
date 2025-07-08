/* B. Two Divisors
time limit per test1 second
memory limit per test256 megabytes
A certain number 1≤𝑥≤109
 is chosen. You are given two integers 𝑎
 and 𝑏
, which are the two largest divisors of the number 𝑥
. At the same time, the condition 1≤𝑎<𝑏<𝑥
 is satisfied.

For the given numbers 𝑎
, 𝑏
, you need to find the value of 𝑥
.

†
 The number 𝑦
 is a divisor of the number 𝑥
 if there is an integer 𝑘
 such that 𝑥=𝑦⋅𝑘
.

Input
Each test consists of several test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. Then follows the description of
the test cases.

The only line of each test cases contains two integers 𝑎
, 𝑏
 (1≤𝑎<𝑏≤109
).

It is guaranteed that 𝑎
, 𝑏
 are the two largest divisors for some number 1≤𝑥≤109
.

Output
For each test case, output the number 𝑥
, such that 𝑎
 and 𝑏
 are the two largest divisors of the number 𝑥
.

If there are several answers, print any of them.

Example
InputCopy
8
2 3
1 2
3 11
1 5
5 10
4 6
3 9
250000000 500000000
OutputCopy
6
4
33
25
20
12
27
1000000000
Note
For the first test case, all divisors less than 6
 are equal to [1,2,3]
, among them the two largest will be 2
 and 3
.

For the third test case, all divisors less than 33
 are equal to [1,3,11]
, among them the two largest will be 3
 and 11
.

For the fifth test case, all divisors less than 20
 are equal to [1,2,4,5,10]
, among them the two largest will be 5
 and 10
.

For the sixth test case, all divisors less than 12
 are equal to [1,2,3,4,6]
, among them the two largest will be 4
 and 6
.


*/
#include <iostream>

long gcd(long a, long b) { return (b == 0) ? a : gcd(b, a % b); }

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long a, b;
    std::cin >> a >> b;
    long g = gcd(a, b);
    std::cout << (((b % a ? a : b) / g) * b) << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1916/328049958
