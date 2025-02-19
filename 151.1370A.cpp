/* A. Maximum GCD
time limit per test1 second
memory limit per test256 megabytes
Let's consider all integers in the range from 1 to 𝑛 (inclusive).

Among all pairs of distinct integers in this range, find the maximum possible
greatest common divisor of integers in pair. Formally, find the maximum value of
gcd(𝑎,𝑏), where 1≤𝑎<𝑏≤𝑛.

The greatest common divisor, gcd(𝑎,𝑏), of two positive integers 𝑎 and 𝑏 is the
biggest integer that is a divisor of both 𝑎 and 𝑏.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤100)  — the number of test
cases. The description of the test cases follows.

The only line of each test case contains a single integer 𝑛 (2≤𝑛≤106).

Output
For each test case, output the maximum value of gcd(𝑎,𝑏) among all 1≤𝑎<𝑏≤𝑛.

Example
InputCopy
2
3
5
OutputCopy
1
2
Note
In the first test case, gcd(1,2)=gcd(2,3)=gcd(1,3)=1.
In the second test case, 2 is the maximum possible value, corresponding to
gcd(2,4).*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
  for (int i = a; i >= 1; i--) {
    if (a % i == 0 && b % i == 0)
      return i;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    // output maximum value of gcd(a,b)
    // 1<=a<b<=n
    int a, b;
    gcd(a, b);
    // alter
    //__gcd(m, n)
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1370/306897564
