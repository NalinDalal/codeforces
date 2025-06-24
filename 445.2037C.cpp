/*C. Superultra's Favorite Permutation
time limit per test2 seconds
memory limit per test256 megabytes
Superultra, a little red panda, desperately wants primogems. In his dreams, a
voice tells him that he must solve the following task to obtain a lifetime
supply of primogems. Help Superultra!

Construct a permutation∗
 𝑝
 of length 𝑛
 such that 𝑝𝑖+𝑝𝑖+1
 is composite†
 over all 1≤𝑖≤𝑛−1
. If it's not possible, output −1
.

∗
A permutation of length 𝑛
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

†
An integer 𝑥
 is composite if it has at least one other divisor besides 1
 and 𝑥
. For example, 4
 is composite because 2
 is a divisor.

Input
The first line contains 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case contains an integer 𝑛
 (2≤𝑛≤2⋅105
) — the length of the permutation.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, if it's not possible to construct 𝑝
, output −1
 on a new line. Otherwise, output 𝑛
 integers 𝑝1,𝑝2,…,𝑝𝑛
 on a new line.

Example
InputCopy
2
3
8
OutputCopy
-1
1 8 7 3 6 2 4 5
Note
In the first example, it can be shown that all permutation of size 3
 contain two adjacent elements whose sum is prime. For example, in the
permutation [2,3,1] the sum 2+3=5 is prime.

In the second example, we can verify that the sample output is correct because
1+8 , 8+7 , 7+3 , 3+6 , 6+2 , 2+4 , and 4+5 are all composite. There may be
other constructions that are correct.



*/

#include <cstdio>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n;
    scanf("%ld", &n);
    if (n < 5) {
      puts("-1");
      continue;
    }
    for (long p = 1; p <= n; p += 2) {
      if (p == 5) {
        continue;
      }
      printf("%ld ", p);
    }

    printf("5 4 ");

    for (long p = 2; p <= n; p += 2) {
      if (p == 4) {
        continue;
      }
      printf("%ld ", p);
    }

    puts("");
  }
}
// sub: https://codeforces.com/problemset/submission/2037/325899008
