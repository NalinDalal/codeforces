/*B. Different Divisors
time limit per test1 second
memory limit per test256 megabytes
Positive integer 𝑥
 is called divisor of positive integer 𝑦
, if 𝑦
 is divisible by 𝑥
 without remainder. For example, 1
 is a divisor of 7
 and 3
 is not divisor of 8
.

We gave you an integer 𝑑
 and asked you to find the smallest positive integer 𝑎
, such that

𝑎
 has at least 4
 divisors;
difference between any two divisors of 𝑎
 is at least 𝑑
.
Input
The first line contains a single integer 𝑡
 (1≤𝑡≤3000
) — the number of test cases.

The first line of each test case contains a single integer 𝑑
 (1≤𝑑≤10000
).

Output
For each test case print one integer 𝑎
 — the answer for this test case.

Example
InputCopy
2
1
2
OutputCopy
6
15
Note
In the first test case, integer 6
 have following divisors: [1,2,3,6]
. There are 4
 of them and the difference between any two of them is at least 1
. There is no smaller integer with at least 4
 divisors.

In the second test case, integer 15
 have following divisors: [1,3,5,15]
. There are 4
 of them and the difference between any two of them is at least 2
.

The answer 12
 is INVALID because divisors are [1,2,3,4,6,12]
. And the difference between, for example, divisors 2
 and 3
 is less than 𝑑=2
.



*/

// given d, find a such that
// a -> has 4 divisor atleast
// diff b/w 2 divisor is atleast d
// if a = p*q then 4 divsor are 1,p,q,a
// diff>=d =>
// Pick the smallest prime ≥ (d+1) as p.
// Pick the next prime ≥ (p+d) as q.

/*Find the first prime ≥ d+1 (p).

Find the next prime ≥ p+d (q).

Print a = p * q
*/

#include <iostream>
using namespace std;

bool isPrime(int n) {
  if (n < 2)
    return false;
  if (n % 2 == 0)
    return n == 2;
  for (int i = 3; 1LL * i * i <= n; i += 2) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int nextPrime(int start) {
  while (!isPrime(start))
    start++;
  return start;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int d;
    cin >> d;

    int p = nextPrime(d + 1);  // first prime ≥ d+1
    int q = nextPrime(p + d);  // next prime ≥ p+d
    long long a = 1LL * p * q; // product ensures 4 divisors

    cout << a << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1474/336830097
