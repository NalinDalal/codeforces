/*B. Three Sevens
time limit per test2 seconds
memory limit per test256 megabytes
Lottery "Three Sevens" was held for 𝑚
 days. On day 𝑖
, 𝑛𝑖
 people with the numbers 𝑎𝑖,1,…,𝑎𝑖,𝑛𝑖
 participated in the lottery.

It is known that in each of the 𝑚
 days, only one winner was selected from the lottery participants. The lottery
winner on day 𝑖 was not allowed to participate in the lottery in the days from
𝑖+1 to 𝑚
.

Unfortunately, the information about the lottery winners has been lost. You need
to find any possible list of lottery winners on days from 1 to 𝑚 or determine
that no solution exists.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤50000
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑚
 (1≤𝑚≤50000
) — the number of days in which the lottery was held.

Next, for each 𝑖
 from 1
 to 𝑚
, follows a two-line block of data.

The first line of each block contains a single integer 𝑛𝑖
 (1≤𝑛𝑖≤50000
) — the number of lottery participants on day 𝑖
.

The second line of the block contains integers 𝑎𝑖,1,…,𝑎𝑖,𝑛𝑖
 (1≤𝑎𝑖,𝑗≤50000
) — lottery participants on day 𝑖
. It is guaranteed that all the numbers 𝑎𝑖,1,…,𝑎𝑖,𝑛𝑖
 are pairwise distinct.

It is guaranteed that the sum of 𝑛𝑖
 over all blocks of all test cases does not exceed 50000
.

Output
For each test case, if there is no solution, print a single integer −1
.

Otherwise, print 𝑚
 integers 𝑝1,𝑝2,…,𝑝𝑚
 (1≤𝑝𝑖≤50000
) — lottery winners on days from 1
 to 𝑚
. If there are multiple solutions, print any of them.

Example
InputCopy
3
3
4
1 2 4 8
3
2 9 1
2
1 4
2
2
1 2
2
2 1
4
4
1 2 3 4
1
1
1
4
1
3
OutputCopy
8 2 1
-1
2 1 4 3
Note
In the first test case, one of the answers is [8,2,1]
 since the participant with the number 8
 participated on day 1
, but did not participate on days 2
 and 3
; the participant with the number 2
 participated on day 2
, but did not participate on day 3
; and the participant with the number 1
 participated on day 3
. Note that this is not the only possible answer, for example, [8,9,4]
 is also a correct answer.

In the second test case, both lottery participants participated on both days, so
any possible lottery winner on the day 1 must have participated on the day 2 ,
which is not allowed. Thus, there is no correct answer.

In the third test case, only one participant participated on days 2
, 3
, 4
, and on day 1
 there is only one participant who did not participate in the lottery on days
2,3,4 — participant 2 , which means [2,1,4,3] is the only correct answer to this
test case.
*/

#include <iostream>
#include <vector>

int main() {

  const long N = 50007;

  long t;
  std::cin >> t;
  while (t--) {
    long m;
    std::cin >> m;
    std::vector<std::vector<long>> v(m);
    for (long p = 0; p < m; p++) {
      long n;
      std::cin >> n;
      for (long u = 0; u < n; u++) {
        long x;
        std::cin >> x;
        v[p].push_back(x);
      }
    }

    std::vector<bool> f(N, 0);
    std::vector<long> w(m, -1);
    for (long p = m - 1; p >= 0; p--) {
      for (long u = 0; u < v[p].size(); u++) {
        long x = v[p][u];
        if (!f[x] && w[p] < 0) {
          w[p] = x;
        }
        f[x] = 1;
      }
      if (w[p] < 0) {
        break;
      }
    }

    if (w[0] < 0) {
      std::cout << "-1" << std::endl;
    } else {
      for (long p = 0; p < m; p++) {
        std::cout << w[p] << " ";
      }
      std::cout << std::endl;
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1798/328808215
