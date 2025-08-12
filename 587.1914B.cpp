/*B. Preparing for the Contest
time limit per test1 second
memory limit per test256 megabytes
Monocarp is practicing for a big contest. He plans to solve 𝑛
 problems to make sure he's prepared. Each of these problems has a difficulty
level: the first problem has a difficulty level of 1 , the second problem has a
difficulty level of 2 , and so on, until the last (𝑛 -th) problem, which has a
difficulty level of 𝑛
.

Monocarp will choose some order in which he is going to solve all 𝑛
 problems. Whenever he solves a problem which is more difficult than the last
problem he solved, he gets excited because he feels like he's progressing. He
doesn't get excited when he solves the first problem in his chosen order.

For example, if Monocarp solves the problems in the order [3,5⎯⎯,4,1,6⎯⎯,2]
, he gets excited twice (the corresponding problems are underlined).

Monocarp wants to get excited exactly 𝑘
 times during his practicing session. Help him to choose the order in which he
has to solve the problems!

Input
The first line contains one integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

Each test case consists of one line containing two integers 𝑛
 and 𝑘
 (2≤𝑛≤50
; 0≤𝑘≤𝑛−1
).

Output
For each test case, print 𝑛
 distinct integers from 1
 to 𝑛
, denoting the order in which Monocarp should solve the problems. If there are
multiple answers, print any of them.

It can be shown that under the constraints of the problem, the answer always
exists.

Example
InputCopy
3
6 2
5 4
5 0
OutputCopy
3 5 4 1 6 2
1 2 3 4 5
5 4 3 2 1


*/

// n problems
// ith problem has ith difficulty
// to solve all n problems
// if ith >ith-1 then happy
// say [3,5,4,1,6,2]-> 2 times (5,4) and (6,2)
// find order to get happy k times
/*To get k descents, build a permutation that looks like this:

    - First part: ascending [1, 2, ..., n-k-1]

    - Then, for the last k+1 elements, arrange in descending order:

`[n, n-1, ..., n-k]`

This creates exactly k descents:

Because in descending block of length k+1, there are k descents.


*/
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n, k;
    cin >> n >> k;
    for (long p = 1; p <= k; p++) {
      cout << p << " ";
    }
    for (long p = n; p > k; p--) {
      cout << p << " ";
    }
    cout << "\n";
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1914/333583115
