/* https://codeforces.com/problemset/problem/1853/A

A. Desorting
time limit per test1 second
memory limit per test256 megabytes
Call an array 𝑎 of length 𝑛 sorted if 𝑎1≤𝑎2≤…≤𝑎𝑛−1≤𝑎𝑛.

Ntarsis has an array 𝑎 of length 𝑛.

He is allowed to perform one type of operation on it (zero or more times):

Choose an index 𝑖 (1≤𝑖≤𝑛−1).
Add 1 to 𝑎1,𝑎2,…,𝑎𝑖.
Subtract 1 from 𝑎𝑖+1,𝑎𝑖+2,…,𝑎𝑛.
The values of 𝑎 can be negative after an operation.

Determine the minimum operations needed to make 𝑎 not sorted.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤100). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛 (2≤𝑛≤500) — the
length of the array 𝑎.

The next line contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109) — the values of array 𝑎.

It is guaranteed that the sum of 𝑛 across all test cases does not exceed 500.

Output
Output the minimum number of operations needed to make the array not sorted.

Example
InputCopy
4
2
1 1
4
1 8 10 13
3
1 3 2
3
1 9 14
OutputCopy
1
2
0
3

Note
In the first case, we can perform 1 operation to make the array not sorted:
Pick 𝑖=1. The array 𝑎 then becomes [2,0], which is not sorted.In the second
case, we can perform 2 operations to make the array not sorted: Pick 𝑖=3. The
array 𝑎 then becomes [2,9,11,12]. Pick 𝑖=3. The array 𝑎 then becomes
[3,10,12,11], which is not sorted. It can be proven that 1 and 2 operations are
the minimal numbers of operations in the first and second test cases,
respectively.

In the third case, the array is already not sorted, so we perform 0 operations.


*/// Array is not sorted
           // Update previous value
           // Output the result

#include <cstdio>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n;
    scanf("%ld", &n);
    bool sorted(true);
    long minnum(1e9 + 7);
    long prev;
    scanf("%ld", &prev);
    for (long p = 1; p < n; p++) {
      long x;
      scanf("%ld", &x);
      if (prev <= x) {
        long num = 1 + (x - prev) / 2;
        minnum = (num < minnum) ? num : minnum;
      } else {
        sorted = false;
      }
      prev = x;
    }

    printf("%ld\n", sorted ? minnum : 0);
  }
}
