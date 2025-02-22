/* A. Fair Playoff
time limit per test2 seconds
memory limit per test256 megabytes
Four players participate in the playoff tournament. The tournament is held
according to the following scheme: the first player will play with the second,
and the third player with the fourth, then the winners of the pairs will play in
the finals of the tournament.

It is known that in a match between two players, the one whose skill is greater
will win. The skill of the 𝑖 -th player is equal to 𝑠𝑖 and all skill levels are
pairwise different (i. e. there are no two identical values in the array 𝑠
).

The tournament is called fair if the two players with the highest skills meet in
the finals.

Determine whether the given tournament is fair.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

A single line of test case contains four integers 𝑠1,𝑠2,𝑠3,𝑠4
 (1≤𝑠𝑖≤100
) — skill of the players. It is guaranteed that all the numbers in the array are
different.

Output
For each testcase, output YES if the tournament is fair, or NO otherwise.

Example
InputCopy
4
3 7 9 5
4 5 6 9
5 3 8 1
6 5 3 2
OutputCopy
YES
NO
YES
NO
Note
Consider the example:

in the first test case, players 2
 and 3
 with skills 7
 and 9
 advance to the finals;
in the second test case, players 2
 and 4
 with skills 5
 and 9
 advance to the finals. The player with skill 6
 does not advance, but the player with skill 5
 advances to the finals, so the tournament is not fair;
in the third test case, players 1
 and 3
 with skills 5
 and 8
 advance to the finals;
in the fourth test case, players 1
 and 3
 with skills 6
 and 3
 advance to the finals. The player with skill 5
 does not advance, but the player with skill 3
 advances to the finals, so the tournament is not fair.

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long t;
  cin >> t;

  while (t--) {
    vector<pair<long, long>> a(4);

    for (long p = 0; p < 4; p++) {
      cin >> a[p].first;
      a[p].second = p;
    }
    // need to check whether the two strongest competitors make it to the
    // finals.
    // compare s1,s2
    // s3,s4
    // now if something happens like,s1<s2<s3<s4 then not fair as s2<s3, but
    // s3 doesn't goes to finals

    sort(a.rbegin(), a.rend());

    long x = a[0].second, y = a[1].second;
    x /= 2;
    y /= 2;

    cout << (x == y ? "NO" : "YES") << endl;
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1535/307322647
