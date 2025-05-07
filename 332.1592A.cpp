/* A. Gamer Hemose
time limit per test1 second
memory limit per test256 megabytes
One day, Ahmed_Hossam went to Hemose and said "Let's solve a gym contest!".
Hemose didn't want to do that, as he was playing Valorant, so he came up with a
problem and told it to Ahmed to distract him. Sadly, Ahmed can't solve it...
Could you help him?

There is an Agent in Valorant, and he has 𝑛
 weapons. The 𝑖
-th weapon has a damage value 𝑎𝑖
, and the Agent will face an enemy whose health value is 𝐻
.

The Agent will perform one or more moves until the enemy dies.

In one move, he will choose a weapon and decrease the enemy's health by its
damage value. The enemy will die when his health will become less than or equal
to 0 . However, not everything is so easy: the Agent can't choose the same
weapon for 2 times in a row.

What is the minimum number of times that the Agent will need to use the weapons
to kill the enemy?

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤105) . Description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝐻
 (2≤𝑛≤103,1≤𝐻≤109)
 — the number of available weapons and the initial health value of the enemy.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109)
 — the damage values of the weapons.

It's guaranteed that the sum of 𝑛
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case, print a single integer — the minimum number of times that
the Agent will have to use the weapons to kill the enemy.

Example
InputCopy
3
2 4
3 7
2 6
4 2
3 11
2 1 7
OutputCopy
1
2
3
Note
In the first test case, the Agent can use the second weapon, making health value
of the enemy equal to 4−7=−3 . −3≤0 , so the enemy is dead, and using weapon 1
 time was enough.

In the second test case, the Agent can use the first weapon first, and then the
second one. After this, the health of enemy will drop to 6−4−2=0 , meaning he
would be killed after using weapons 2 times.

In the third test case, the Agent can use the weapons in order (third, first,
third), decreasing the health value of enemy to 11−7−2−7=−5 after using the
weapons 3 times. Note that we can't kill the enemy by using the third weapon
twice, as even though 11−7−7<0 , it's not allowed to use the same weapon twice
in a row.


*/

/*1. Sort the weapons by damage.

2. Let:
    - a = weapon with maximum damage.
    - b = weapon with second maximum damage.

3. Alternate the weapon uses between a and b in pattern: a, b, a, b...
    - Each two moves does damage = a + b.

4. Compute how many full pairs of moves (a + b) are needed.

5. Handle the remainder (what's left after full pairs) with:
    - One more use of a if needed.
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, h;
    cin >> n >> h;
    // n is no of weapons, h is health of enemy
    vector<int> v(n);

    for (int i = 0; i < n; i++)
      cin >> v[i];

    // can't use same weapon twice
    // pair damage=a+b
    // full_pairs = H / pair_damage
    // remaining = H % pair_damage

    // if(remaining == 0 ) ans = full_pairs * 2
    // else if(remaining <= a ) ans = full_pairs * 2 + 1
    // else ans = full_pairs * 2 + 2

    sort(v.begin(), v.end());
    int a = v[n - 1]; // max damage weapon
    int b = v[n - 2]; // second max damage

    int full_pairs = h / (a + b);
    int rem = h % (a + b);

    int ans;
    if (rem == 0) {
      ans = full_pairs * 2;
    } else if (rem <= a) {
      ans = full_pairs * 2 + 1;
    } else {
      ans = full_pairs * 2 + 2;
    }

    cout << ans << '\n';
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1592/318681898
