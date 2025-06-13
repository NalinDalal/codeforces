/*B. Binomial Coefficients, Kind Of
time limit per test2 seconds
memory limit per test512 megabytes
Recently, akshiM met a task that needed binomial coefficients to solve. He
wrote a code he usually does that looked like this:

    for (int n = 0; n < N; n++) { // loop over n from 0 to N-1 (inclusive)
        C[n][0] = 1;
        C[n][n] = 1;
        for (int k = 1; k < n; k++) // loop over k from 1 to n-1 (inclusive)
            C[n][k] = C[n][k - 1] + C[n - 1][k - 1];
    }
Unfortunately, he made an error, since the right formula is the following:

            C[n][k] = C[n - 1][k] + C[n - 1][k - 1]
But his team member keblidA is interested in values that were produced using
the wrong formula. Please help him to calculate these coefficients for 𝑡
 various pairs (𝑛𝑖,𝑘𝑖)
. Note that they should be calculated according to the first (wrong) formula.

Since values 𝐶[𝑛𝑖][𝑘𝑖]
 may be too large, print them modulo 109+7
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤105
) — the number of pairs. Next, 𝑡
 pairs are written in two lines.

The second line contains 𝑡
 integers 𝑛1,𝑛2,…,𝑛𝑡
 (2≤𝑛𝑖≤105
).

The third line contains 𝑡
 integers 𝑘1,𝑘2,…,𝑘𝑡
 (1≤𝑘𝑖<𝑛𝑖
).

Output
Print 𝑡
 integers 𝐶[𝑛𝑖][𝑘𝑖]
 modulo 109+7
.

Example
InputCopy
7
2 5 5 100000 100000 100000 100000
1 2 3 1 33333 66666 99999
OutputCopy
2
4
8
2
326186014
984426998
303861760


*/                                                                             \
#include<cstdio>
#include <vector>

int main() {

  const long MOD = 1e9 + 7;
  std::vector<long> v(1e5 + 7, 1);
  for (long p = 1; p < v.size(); p++) {
    v[p] = (2 * v[p - 1]) % MOD;
  }

  long t;
  scanf("%ld", &t);
  std::vector<long> wn(t), wk(t);
  for (long p = 0; p < t; p++) {
    scanf("%ld", &wn[p]);
  }
  for (long p = 0; p < t; p++) {
    scanf("%ld", &wk[p]);
  }
  for (long p = 0; p < t; p++) {
    printf("%ld\n", (wk[p] < wn[p]) ? v[wk[p]] : 1);
  }
  puts("");
}
// sub: https://codeforces.com/problemset/submission/2025/324245811
