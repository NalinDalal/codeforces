/*E. Sakurako, Kosuke, and the Permutation
time limit per test2 seconds
memory limit per test256 megabytes
Sakurako's exams are over, and she did excellently. As a reward, she received a
permutation 𝑝 . Kosuke was not entirely satisfied because he failed one exam and
did not receive a gift. He decided to sneak into her room (thanks to the code
for her lock) and spoil the permutation so that it becomes simple.

A permutation 𝑝
 is considered simple if for every 𝑖
 (1≤𝑖≤𝑛)
 one of the following conditions holds:

𝑝𝑖=𝑖
𝑝𝑝𝑖=𝑖
For example, the permutations [1,2,3,4]
, [5,2,4,3,1]
, and [2,1]
 are simple, while [2,3,1]
 and [5,2,1,4,3]
 are not.

In one operation, Kosuke can choose indices 𝑖,𝑗
 (1≤𝑖,𝑗≤𝑛)
 and swap the elements 𝑝𝑖
 and 𝑝𝑗
.

Sakurako is about to return home. Your task is to calculate the minimum number
of operations that Kosuke needs to perform to make the permutation simple.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case is described by two lines.

The first line contains one integer 𝑛
 (1≤𝑛≤106
) — the length of the permutation 𝑝
.
The second line contains 𝑛
 integers 𝑝𝑖
 (1≤𝑝𝑖≤𝑛
) — the elements of the permutation 𝑝
.
It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 106
.

It is guaranteed that 𝑝
 is a permutation.

Output
For each test case, output the minimum number of operations that Kosuke needs to
perform to make the permutation simple.

Example
InputCopy
6
5
1 2 3 4 5
5
5 4 3 2 1
5
2 3 4 5 1
4
2 3 4 1
3
1 3 2
7
2 3 1 5 6 7 4
OutputCopy
0
0
2
1
0
2
Note
In the first and second examples, the permutations are already simple.

In the fourth example, it is sufficient to swap 𝑝2
 and 𝑝4
. Thus, the permutation will become [2,1,4,3]
 in 1
 operation.
*/
#include <bits/stdc++.h>

using namespace std;

#define fastIO                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);                                                              \
  cout.precision(numeric_limits<double>::max_digits10);

void CoderAbhi27() {
  int n;
  cin >> n;
  vector<int> p(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }

  int ans = 0;
  vector<int> chk(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (chk[i])
      continue;

    int j = p[i];
    int cnt = 1;
    while (j != i) {
      chk[j] = 1;
      j = p[j];
      cnt++;
    }
    chk[i] = 1;

    if (cnt <= 2)
      continue;
    ans += (cnt - 1) / 2;
  } // O(n)

  cout << ans << '\n';
}

// tc -> O(n)
// sc -> O(n)

int32_t main() {
  fastIO;

  int t = 1;
  cin >> t;
  while (t--) {
    CoderAbhi27();
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/2033/341622436
