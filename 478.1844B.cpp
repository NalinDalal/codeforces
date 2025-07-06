/*B. Permutations & Primes
time limit per test1 second
memory limit per test256 megabytes
You are given a positive integer 𝑛
.

In this problem, the MEX
 of a collection of integers 𝑐1,𝑐2,…,𝑐𝑘
 is defined as the smallest positive integer 𝑥
 which does not occur in the collection 𝑐
.

The primality of an array 𝑎1,…,𝑎𝑛
 is defined as the number of pairs (𝑙,𝑟)
 such that 1≤𝑙≤𝑟≤𝑛
 and MEX(𝑎𝑙,…,𝑎𝑟)
 is a prime number.

Find any permutation of 1,2,…,𝑛
 with the maximum possible primality among all permutations of 1,2,…,𝑛
.

Note:

A prime number is a number greater than or equal to 2
 that is not divisible by any positive integer except 1
 and itself. For example, 2,5,13
 are prime numbers, but 1
 and 6
 are not prime numbers.
A permutation of 1,2,…,𝑛
 is an array consisting of 𝑛
 distinct integers from 1
 to 𝑛
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (𝑛=3
 but there is 4
 in the array).
Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The only line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output 𝑛
 integers: a permutation of 1,2,…,𝑛
 that achieves the maximum possible primality.

If there are multiple solutions, print any of them.

Example
InputCopy
3
2
1
5
OutputCopy
2 1
1
5 2 1 4 3
Note
In the first test case, there are 3
 pairs (𝑙,𝑟)
 with 1≤𝑙≤𝑟≤2
, out of which 2
 have a prime MEX(𝑎𝑙,…,𝑎𝑟)
:

(𝑙,𝑟)=(1,1)
: MEX(2)=1
, which is not prime.
(𝑙,𝑟)=(1,2)
: MEX(2,1)=3
, which is prime.
(𝑙,𝑟)=(2,2)
: MEX(1)=2
, which is prime.
Therefore, the primality is 2
.
In the second test case, MEX(1)=2
 is prime, so the primality is 1
.

In the third test case, the maximum possible primality is 8
.



*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    if (n == 1) {
      cout << "1\n";
      continue;
    } else if (n == 2) {
      cout << "2 1\n";
      continue;
    }

    vector<long> a(n, 0);
    a[0] = 2;
    a[n / 2] = 1;
    a[n - 1] = 3;
    long cur(4);
    for (long p = 1; p + 1 < n; p++) {
      if (a[p]) {
        continue;
      }
      a[p] = cur;
      cur++;
    }
    for (long p = 0; p < n; p++) {
      cout << a[p] << " ";
    }
    cout << endl;
  }
}
// sub: https://codeforces.com/problemset/submission/1844/327793600
