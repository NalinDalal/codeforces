/*
https://codeforces.com/problemset/problem/268/A

A. Games
time limit per test1 second
memory limit per test256 megabytes
Manao works on a sports TV. He's spent much time watching the football games of
some country. After a while he began to notice different patterns. For example,
each team has two sets of uniforms: home uniform and guest uniform. When a team
plays a game at home, the players put on the home uniform. When a team plays as
a guest on somebody else's stadium, the players put on the guest uniform. The
only exception to that rule is: when the home uniform color of the host team
matches the guests' uniform, the host team puts on its guest uniform as well.
For each team the color of the home and guest uniform is different.

There are n teams taking part in the national championship. The championship
consists of n·(n - 1) games: each team invites each other team to its stadium.
At this point Manao wondered: how many times during the championship is a host
team going to put on the guest uniform? Note that the order of the games does
not affect this number.

You know the colors of the home and guest uniform for each team. For simplicity,
the colors are numbered by integers in such a way that no two distinct colors
have the same number. Help Manao find the answer to his question.

Input
The first line contains an integer n (2 ≤ n ≤ 30). Each of the following n lines
contains a pair of distinct space-separated integers hi, ai (1 ≤ hi, ai ≤ 100) —
the colors of the i-th team's home and guest uniforms, respectively.

Output
In a single line print the number of games where the host team is going to play
in the guest uniform.

Examples
InputCopy
3
1 2
2 4
3 4
OutputCopy
1
InputCopy
4
100 42
42 100
5 42
100 5
OutputCopy
5
InputCopy
2
1 2
1 2
OutputCopy
0
Note
In the first test case the championship consists of 6 games. The only game with
the event in question is the game between teams 2 and 1 on the stadium of
team 2.

In the second test sample the host team will have to wear guest uniform in the
games between teams: 1 and 2, 2 and 1, 2 and 3, 3 and 4, 4 and 2 (the host team
is written first).

*/

// total n(n-1) games
// if home == guest{home changes to guest}

/*Array Indexing Error: In the line if (a[i][0] == a[1][j]), you're comparing
the home uniform color of team i with the guest uniform color of team 1 can be
optimised*/

// We need to count how many times a host team will wear its guest uniform
// during the tournament. This happens when: The home uniform color of the host
// team matches the guest uniform color of the guest team.

/* Approach:
Loop over all pairs of teams (i, j) where i is the host team and j is the guest
team (but i != j). For each such pair, check if the host's home uniform color
(hi) matches the guest's guest uniform color (aj). If they match, increment the
count. Finally, print the result.*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n; // number of teams
  cin >> n;

  // Vector to store pairs of (home color, guest color)
  vector<pair<int, int>> uniforms(n);

  // Input the uniforms for each team
  for (int i = 0; i < n; i++) {
    cin >> uniforms[i].first >> uniforms[i].second; // home and guest uniform
  }

  int count = 0;

  // Check all pairs of teams (i, j) where i is host and j is guest
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) { // i is the host, j is the guest
        if (uniforms[i].first == uniforms[j].second) {
          // If the home uniform of host (i) matches the guest uniform of guest
          // (j)
          count++;
        }
      }
    }
  }

  cout << count << endl; // Output the result
  return 0;
}

// Submission: https://codeforces.com/problemset/submission/268/298501769
