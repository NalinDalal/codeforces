/* A. Submission Bait
time limit per test1 second
memory limit per test256 megabytes
Alice and Bob are playing a game in an array 𝑎
 of size 𝑛
.

They take turns to do operations, with Alice starting first. The player who can
not operate will lose. At first, a variable 𝑚𝑥 is set to 0
.

In one operation, a player can do:

Choose an index 𝑖
 (1≤𝑖≤𝑛
) such that 𝑎𝑖≥𝑚𝑥
 and set 𝑚𝑥
 to 𝑎𝑖
. Then, set 𝑎𝑖
 to 0
.
Determine whether Alice has a winning strategy.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤103
) — the number of test cases.

For each test case:

The first line contains an integer 𝑛
 (2≤𝑛≤50
) — the size of the array.
The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
) — the elements of the array.
Output
For each test case, if Alice has a winning strategy, output "YES". Otherwise,
output "NO".

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
5
2
2 1
2
1 1
3
3 3 3
4
3 3 4 4
4
1 2 2 2
OutputCopy
YES
NO
YES
NO
YES
Note
In the first test case, Alice can choose 𝑖=1
 since 𝑎1=2≥𝑚𝑥=0
.

After Alice's operation, 𝑎=[0,1]
 and 𝑚𝑥=2
. Bob can not do any operation. Alice wins.

In the second test case, Alice doesn't have a winning strategy.

For example, if Alice chooses 𝑖=1
, after Alice's operation: 𝑎=[0,1]
 and 𝑚𝑥=1
. Then, Bob can choose 𝑖=2
 since 𝑎2=1≥𝑚𝑥=1
. After Bob's operation: 𝑎=[0,0]
 and 𝑚𝑥=1
. Alice can not do any operation. Bob wins.


*/

// player who can't operate losses
// choose i such that v[i]>=mx
// mx=v[i]; v[i]=0
// alice start then bob, then alice and goes on;
// alice wins bool = true
#include <algorithm>
#include <cstdio>
#include <vector>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n;
    scanf("%ld", &n);
    std::vector<long> v(n);
    for (long p = 0; p < n; p++) {
      scanf("%ld", &v[p]);
    }
    if (n % 2) {
      puts("YES");
      continue;
    }
    sort(v.rbegin(), v.rend());
    bool res(false);
    for (long p = 1; !res && p < n; p += 2) {
      if (v[p - 1] == v[p]) {
        continue;
      }
      res = true;
    }

    puts(res ? "YES" : "NO");
  }
}
// sub: https://codeforces.com/problemset/submission/1990/323710419
