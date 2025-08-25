/*C. Kevin and Puzzle
time limit per test2 seconds
memory limit per test256 megabytes

Kevin enjoys logic puzzles.

He played a game with 𝑛
 classmates who stand in a line. The 𝑖
-th person from the left says that there are 𝑎𝑖
 liars to their left (not including themselves).

Each classmate is either honest or a liar, with the restriction that no two
liars can stand next to each other. Honest classmates always say the truth.
Liars can say either the truth or lies, meaning their statements are considered
unreliable.

Kevin wants to determine the number of distinct possible game configurations
modulo 998244353 . Two configurations are considered different if at least one
classmate is honest in one configuration and a liar in the other.

Input
Each test[48;54;204;1728;2856t contains multiple test cases. The first line
contains the number of test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of classmates.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤𝑛
) — the number of liars to the left of the 𝑖
-th person they claimed.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output one integer — the number of distinct game
configurations modulo 998244353
.

Example
InputCopy
8
3
0 1 2
5
0 0 0 0 0
5
0 0 1 1 2
5
0 1 2 3 4
5
0 0 1 1 1
5
5 1 5 2 5
1
0
4
2 3 1 1
OutputCopy
1
2
3
0
4
1
2
0
Note
We will use red
 to mark liars and blue
 to mark honest people.

In the first test case, the only possible way is (0,1,2)
.

In the second test case, two possible ways are (0,0,0,0,0)
 and (0,0,0,0,0)
.

In the third test case, three possible ways are (0,0,1,1,2)
, (0,0,1,1,2)
, (0,0,1,1,2)
.
*/

#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  const long MOD = 998244353;
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::vector<long> a(n + 1), f(n + 1, 0);
    for (long p = 1; p <= n; p++) {
      std::cin >> a[p];
    }

    // f[k] is the number of configurations GIVEN THAT k IS A TRUTH TELLER
    f[0] = 1;
    for (long p = 1; p <= n; p++) {
      f[p] = ((a[p - 1] == a[p]) ? f[p - 1] : 0) +
             ((p > 1 && a[p - 2] + 1 == a[p]) ? f[p - 2] : 0);
      f[p] %= MOD;
    }

    // Last one is a truth teller or the one before is a truth teller (can't
    // have both liars)
    long ans = (f[n - 1] + f[n]) % MOD;
    std::cout << ans << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2061/335442215
