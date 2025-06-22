/*A. Greedy Monocarp
time limit per test2 seconds
memory limit per test512 megabytes
There are 𝑛
 chests; the 𝑖
-th chest initially contains 𝑎𝑖
 coins. For each chest, you can choose any non-negative (0
 or greater) number of coins to add to that chest, with one constraint: the
total number of coins in all chests must become at least 𝑘
.

After you've finished adding coins to the chests, greedy Monocarp comes, who
wants the coins. He will take the chests one by one, and since he is greedy, he
will always choose the chest with the maximum number of coins. Monocarp will
stop as soon as the total number of coins in chests he takes is at least 𝑘
.

You want Monocarp to take as few coins as possible, so you have to add coins to
the chests in such a way that, when Monocarp stops taking chests, he will have
exactly 𝑘 coins. Calculate the minimum number of coins you have to add.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

Each test case consists of two lines:

the first line contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤50
; 1≤𝑘≤107
);
the second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑘
).
Output
For each test case, print one integer — the minimum number of coins you have to
add so that, when Monocarp stops taking the chests, he has exactly 𝑘 coins. It
can be shown that under the constraints of the problem, it is always possible.

Example
InputCopy
4
5 4
4 1 2 3 2
5 10
4 1 2 3 2
2 10
1 1
3 8
3 3 3
OutputCopy
0
1
8
2
Note
In the first test case of the example, you don't have to add any coins. When
Monocarp arrives, he will take the chest with 4 coins, so he will have exactly 4
 coins.

In the second test case of the example, you can add 1
 coin to the 4
-th chest, so, when Monocarp arrives, he will take a chest with 4
 coins, then another chest with 4
 coins, and a chest with 2
 coins.

In the third test case of the example, you can add 3
 coins to the 1
-st chest and 5
 coins to the 2
-nd chest.

In the fourth test case of the example, you can add 1
 coin to the 1
-st chest and 1
 coin to the 3
-rd chest.


*/

#include <algorithm>
#include <cstdio>
#include <vector>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n, k;
    scanf("%ld %ld", &n, &k);
    std::vector<long> v(n);
    long sum(0), mx(0);
    for (long p = 0; p < n; p++) {
      scanf("%ld", &v[p]);
      mx = (mx > v[p] ? mx : v[p]);
      sum += v[p];
    }
    if (mx >= k) {
      puts("0");
      continue;
    } else if (sum <= k) {
      printf("%ld\n", k - sum);
      continue;
    }
    sort(v.rbegin(), v.rend());
    long cs(0), res(0);
    for (long p = 0; p < v.size(); p++) {
      cs += v[p];
      if (cs > k) {
        break;
      }
      res = k - cs;
    }

    printf("%ld\n", res);
  }
}
// sub: https://codeforces.com/problemset/submission/2042/325516009
