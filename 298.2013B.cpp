/*
B. Battle for Survive
time limit per test1 second
memory limit per test256 megabytes
Eralim, being the mafia boss, manages a group of 𝑛
 fighters. Fighter 𝑖
 has a rating of 𝑎𝑖
.

Eralim arranges a tournament of 𝑛−1
 battles, in each of which two not yet eliminated fighters 𝑖
 and 𝑗
 (1≤𝑖<𝑗≤𝑛
) are chosen, and as a result of the battle, fighter 𝑖
 is eliminated from the tournament, and the rating of fighter 𝑗
 is reduced by the rating of fighter 𝑖
. That is, 𝑎𝑗
 is decreased by 𝑎𝑖
. Note that fighter 𝑗
's rating can become negative. The fighters indexes do not change.

Eralim wants to know what maximum rating the last remaining fighter can preserve
if he chooses the battles optimally.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤2⋅105
) — the number of fighters.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…𝑎𝑛
 (1≤𝑎𝑖≤109
) — the ratings of the fighters.

The sum of 𝑛
 over all testcases does not exceed 2⋅105
.

Output
For each testcase, output a single integer — the maximum rating that the last
remaining fighter can preserve.

Example
InputCopy
5
2
2 1
3
2 2 8
4
1 2 4 3
5
1 2 3 4 5
5
3 2 4 5 4
OutputCopy
-1
8
2
7
8
Note
In the first example, you can arrange a fight between fighters with indices 1
 and 2
, where the fighter with index 2
 will win. The rating of the last fighter, that is, the fighter with index 2
, will be 1−2=−1
.

In the second example, you can first conduct a fight between fighters with
indices 1 and 2 , where the fighter with index 2 will win, and then
conduct a fight between fighters with indices 2 and 3 , where the fighter
with index 3 will win.

The rating of the fighter with index 2
 after the first fight will be 2−2=0
. The rating of the fighter with index 3
 after the second fight will be 8−0=8
.
*/
#include <iostream>
using namespace std;

int main() {
  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    long long s = 0;
    for (long p = 0; p < n; p++) {
      long x;
      cin >> x;
      s += (p == n - 2 ? -x : x);
    }
    cout << s << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2013/315920273
