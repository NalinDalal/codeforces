/* https://codeforces.com/problemset/problem/1828/B
B. Permutation Swap
time limit per test1 second
memory limit per test256 megabytes
You are given an unsorted permutation 𝑝1,𝑝2,…,𝑝𝑛. To sort the permutation, you
choose a constant 𝑘 (𝑘≥1) and do some operations on the permutation. In one
operation, you can choose two integers 𝑖, 𝑗 (1≤𝑗<𝑖≤𝑛) such that 𝑖−𝑗=𝑘, then swap
𝑝𝑖 and 𝑝𝑗.

What is the maximum value of 𝑘 that you can choose to sort the given
permutation?

A permutation is an array consisting of 𝑛 distinct integers from 1 to 𝑛 in
arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a
permutation (2 appears twice in the array) and [1,3,4] is also not a permutation
(𝑛=3 but there is 4 in the array).

An unsorted permutation 𝑝 is a permutation such that there is at least one
position 𝑖 that satisfies 𝑝𝑖≠𝑖.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛 (2≤𝑛≤105) — the
length of the permutation 𝑝.

The second line of each test case contains 𝑛 distinct integers 𝑝1,𝑝2,…,𝑝𝑛
(1≤𝑝𝑖≤𝑛) — the permutation 𝑝. It is guaranteed that the given numbers form a
permutation of length 𝑛 and the given permutation is unsorted.

It is guaranteed that the sum of 𝑛 over all test cases does not exceed 2⋅105.

Output
For each test case, output the maximum value of 𝑘 that you can choose to sort
the given permutation.

We can show that an answer always exists.

Example
InputCopy
7
3
3 1 2
4
3 4 1 2
7
4 2 6 7 5 3 1
9
1 6 7 4 9 2 3 8 5
6
1 5 3 4 2 6
10
3 10 5 2 9 6 7 8 1 4
11
1 11 6 4 8 3 7 5 9 10 2
OutputCopy
1
2
3
4
3
2
3
Note
In the first test case, the maximum value of 𝑘 you can choose is 1. The
operations used to sort the permutation are:

Swap 𝑝2 and 𝑝1 (2−1=1) → 𝑝=[1,3,2]
Swap 𝑝2 and 𝑝3 (3−2=1) → 𝑝=[1,2,3]
In the second test case, the maximum value of 𝑘 you can choose is 2. The
operations used to sort the permutation are:

Swap 𝑝3 and 𝑝1 (3−1=2) → 𝑝=[1,4,3,2]
Swap 𝑝4 and 𝑝2 (4−2=2) → 𝑝=[1,2,3,4]
*/

/* #include <cmath>
#include <iostream>
using namespace std;
long gcd(long a, long b) { return (b == 0) ? a : gcd(b, a % b); }

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long g = 0;
    for (int i = 0; i < n; i++) {
      long x;
      cin >> x;
      long diff = abs(i - x);

      g = gcd(g, diff);
    }
    cout << g << endl;
  }
  return 0;
}*/

#include <cstdio>

long gcd(long a, long b) { return (b == 0) ? a : gcd(b, a % b); }

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n;
    scanf("%ld", &n);
    long g(0);
    for (long p = 1; p <= n; p++) {
      long x;
      scanf("%ld", &x);
      long diff = p - x;
      diff = (diff > 0) ? diff : -diff;
      g = gcd(g, diff);
    }

    printf("%ld\n", g);
  }
}

// sub: https://codeforces.com/problemset/submission/1828/302885035
