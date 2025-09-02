/*C. OKEA
time limit per test1 second
memory limit per test256 megabytes
People worry that computers will get too smart and take over the world, but the
real problem is that they're too stupid and they've already taken over the
world. — Pedro Domingos You work for a well-known department store that uses
leading technologies and employs mechanistic work — that is, robots!

The department you work in sells 𝑛⋅𝑘
 items. The first item costs 1
 dollar, the second item costs 2
 dollars, and so on: 𝑖
-th item costs 𝑖
 dollars. The items are situated on shelves. The items form a rectangular grid:
there are 𝑛 shelves in total, and each shelf contains exactly 𝑘 items. We will
denote by 𝑎𝑖,𝑗 the price of 𝑗 -th item (counting from the left) on the 𝑖 -th
shelf, 1≤𝑖≤𝑛,1≤𝑗≤𝑘
.

Occasionally robots get curious and ponder on the following question: what is
the mean price (arithmetic average) of items 𝑎𝑖,𝑙,𝑎𝑖,𝑙+1,…,𝑎𝑖,𝑟 for some shelf 𝑖
 and indices 𝑙≤𝑟
? Unfortunately, the old robots can only work with whole numbers. If the mean
price turns out not to be an integer, they break down.

You care about robots' welfare. You want to arrange the items in such a way that
the robots cannot theoretically break. Formally, you want to choose such a
two-dimensional array 𝑎 that:

Every number from 1
 to 𝑛⋅𝑘
 (inclusively) occurs exactly once.
For each 𝑖,𝑙,𝑟
, the mean price of items from 𝑙
 to 𝑟
 on 𝑖
-th shelf is an integer.
Find out if such an arrangement is possible, and if it is, give any example of
such arrangement.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤500
) — the number of test cases.

The first and only line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛,𝑘≤500
) — the number of shelves and length of each shelf, respectively.

It is guaranteed that the sum 𝑛
 over all test cases does not exceed 500
 and the sum 𝑘
 over all test cases does not exceed 500
.

Output
Print the answer for each test case.

If such an arrangement exists, print "YES" on a single line. After that, print
any example on 𝑛 lines of 𝑘 numbers each, one line per shelf. Each number from 1
 to 𝑛⋅𝑘
 must occur exactly once in the output.

If no good arrangement exists, print a single word "NO" on its own line.

Example
InputCopy
4
1 1
2 2
3 3
3 1
OutputCopy
YES
1
YES
1 3
2 4
NO
YES
1
2
3


*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n, k;
    cin >> n >> k;

    if ((n % 2 == 1) && (k > 1)) {
      cout << "NO\n";
      continue;
    }

    cout << "YES\n";
    for (long u = 1; u <= n; u++) {
      for (long p = 0; p < k; p++) {
        cout << (u + n * p) << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1634/336639119
