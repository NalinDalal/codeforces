/*B. Basketball Together
time limit per test1 second
memory limit per test256 megabytes
A basketball competition is held where the number of players in a team does not
have a maximum or minimum limit (not necessarily 5 players in one team for each
match). There are 𝑁 candidate players in the competition that will be trained by
Pak Chanek, the best basketball coach on earth. The 𝑖 -th candidate player has a
power of 𝑃𝑖
.

Pak Chanek will form zero or more teams from the 𝑁
 candidate players on the condition that each candidate player may only join in
at most one team. Each of Pak Chanek's teams will be sent to compete once with
an enemy team that has a power of 𝐷 . In each match, the team sent is said to
defeat the enemy team if the sum of powers from the formed players is strictly
greater than 𝐷
.

One of Pak Chanek's skills is that when a team that has been formed plays in a
match, he can change the power of each player in the team to be equal to the
biggest player power from the team.

Determine the maximum number of wins that can be achieved by Pak Chanek.

Input
The first line contains two integers 𝑁
 and 𝐷
 (1≤𝑁≤105
, 1≤𝐷≤109
) — the number of candidate players and the power of the enemy team.

The second line contains 𝑁
 integers 𝑃1,𝑃2,…,𝑃𝑁
 (1≤𝑃𝑖≤109
) — the powers of all candidate players.

Output
A line containing an integer representing the maximum number of wins that can be
achieved by Pak Chanek.

Example
InputCopy
6 180
90 80 70 60 50 100
OutputCopy
2
Note
The 1
-st team formed is a team containing players 4
 and 6
. The power of each player in the team becomes 100
. So the total power of the team is 100+100=200>180
.

The 2
-nd team formed is a team containing players 1
, 2
, and 5
. The power of each player in the team becomes 90
. So the total power of the team is 90+90+90=270>180
.



*/

/*To maximize the number of winning teams:
- Start from strongest players
- Try to build teams around them using the minimum number of players required to
beat D

1. Sort P in ascending order
2. Iterate through each player P[i] (from strongest to weakest)
3. For each P[i], calculate:
    Minimum number of players k needed:
    k = ceil((D + 1) / P[i]) → because we want k * P[i] > D

4. If you have enough remaining players to make that team of size k, make the
team and increment win count

5. Otherwise, break
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  long long D;
  cin >> n >> D;

  vector<long long> P(n);
  for (int i = 0; i < n; ++i) {
    cin >> P[i];
  }

  sort(P.begin(), P.end()); // ascending

  int wins = 0;
  int left = 0, right = n - 1;

  while (left <= right) {
    long long maxPower = P[right];
    long long need = (D + maxPower) / maxPower; // ceil((D+1)/maxPower)

    if ((right - left + 1) >= need) {
      wins++;
      left += (need - 1); // use weakest (need - 1) players + strongest (right)
      right--;
    } else {
      break;
    }
  }

  cout << wins << endl;
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1725/332660656
