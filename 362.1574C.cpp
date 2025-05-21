/* C. Slay the Dragon
time limit per test2 seconds
memory limit per test256 megabytes
Recently, Petya learned about a new game "Slay the Dragon". As the name
suggests, the player will have to fight with dragons. To defeat a dragon, you
have to kill it and defend your castle. To do this, the player has a squad of 𝑛
 heroes, the strength of the 𝑖
-th hero is equal to 𝑎𝑖
.

According to the rules of the game, exactly one hero should go kill the dragon,
all the others will defend the castle. If the dragon's defense is equal to 𝑥 ,
then you have to send a hero with a strength of at least 𝑥 to kill it. If the
dragon's attack power is 𝑦 , then the total strength of the heroes defending the
castle should be at least 𝑦
.

The player can increase the strength of any hero by 1
 for one gold coin. This operation can be done any number of times.

There are 𝑚
 dragons in the game, the 𝑖
-th of them has defense equal to 𝑥𝑖
 and attack power equal to 𝑦𝑖
. Petya was wondering what is the minimum number of coins he needs to spend to
defeat the 𝑖 -th dragon.

Note that the task is solved independently for each dragon (improvements are not
saved).

Input
The first line contains a single integer 𝑛
 (2≤𝑛≤2⋅105
) — number of heroes.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤1012
), where 𝑎𝑖
 is the strength of the 𝑖
-th hero.

The third line contains a single integer 𝑚
 (1≤𝑚≤2⋅105
) — the number of dragons.

The next 𝑚
 lines contain two integers each, 𝑥𝑖
 and 𝑦𝑖
 (1≤𝑥𝑖≤1012;1≤𝑦𝑖≤1018
) — defense and attack power of the 𝑖
-th dragon.

Output
Print 𝑚
 lines, 𝑖
-th of which contains a single integer — the minimum number of coins that should
be spent to defeat the 𝑖 -th dragon.

Example
InputCopy
4
3 6 2 3
5
3 12
7 9
4 14
1 10
8 7
OutputCopy
1
2
4
0
2
Note
To defeat the first dragon, you can increase the strength of the third hero by 1
, then the strength of the heroes will be equal to [3,6,3,3]
. To kill the dragon, you can choose the first hero.

To defeat the second dragon, you can increase the forces of the second and third
heroes by 1 , then the strength of the heroes will be equal to [3,7,3,3] . To
kill the dragon, you can choose a second hero.

To defeat the third dragon, you can increase the strength of all the heroes by 1
, then the strength of the heroes will be equal to [4,7,3,4]
. To kill the dragon, you can choose a fourth hero.

To defeat the fourth dragon, you don't need to improve the heroes and choose a
third hero to kill the dragon.

To defeat the fifth dragon, you can increase the strength of the second hero by
2 , then the strength of the heroes will be equal to [3,8,2,3] . To kill the
dragon, you can choose a second hero.


*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int64_t take(int64_t attack, int64_t defend) {
  return max(int64_t(0), defend - attack);
}

void solve() {
  int64_t n;
  cin >> n;
  vector<int64_t> a(n);
  for (auto &x : a)
    cin >> x;
  sort(a.begin(), a.end());
  int64_t sum = accumulate(a.begin(), a.end(), int64_t(0));

  int64_t q;
  cin >> q;
  while (q--) {
    int64_t x, y;
    cin >> x >> y;
    auto idx = lower_bound(a.begin(), a.end(), x) - a.begin();
    int64_t ans = INT64_MAX;
    if (idx < n) {
      ans = min(ans, take(a[idx], x) + take(sum - a[idx], y));
    }
    if (idx > 0) {
      ans = min(ans, take(a[idx - 1], x) + take(sum - a[idx - 1], y));
    }
    cout << ans << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
// sub: https://codeforces.com/problemset/submission/1574/320680597
