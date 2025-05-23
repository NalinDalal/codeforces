/* A. Two Frogs
time limit per test1 second
memory limit per test256 megabytes
Roaming through the alligator-infested Everglades, Florida Man encounters a most
peculiar showdown. There are 𝑛 lilypads arranged in a row, numbered from 1 to 𝑛
 from left to right. Alice and Bob are frogs initially positioned on distinct
lilypads, 𝑎 and 𝑏 , respectively. They take turns jumping, starting with Alice.

During a frog's turn, it can jump either one space to the left or one space to
the right, as long as the destination lilypad exists. For example, on Alice's
first turn, she can jump to either lilypad 𝑎−1 or 𝑎+1 , provided these lilypads
are within bounds. It is important to note that each frog must jump during its
turn and cannot remain on the same lilypad.

However, there are some restrictions:

The two frogs cannot occupy the same lilypad. This means that Alice cannot jump
to a lilypad that Bob is currently occupying, and vice versa. If a frog cannot
make a valid jump on its turn, it loses the game. As a result, the other frog
wins. Determine whether Alice can guarantee a win, assuming that both players
play optimally. It can be proven that the game will end after a finite number of
moves if both players play optimally.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

The first and only line of each test case contains three integers 𝑛
, 𝑎
, and 𝑏
 (2≤𝑛≤100
, 1≤𝑎,𝑏≤𝑛
, 𝑎≠𝑏
) — the number of lilypads, and the starting positions of Alice and Bob,
respectively.

Note that there are no constraints on the sum of 𝑛
 over all test cases.

Output
For each test case, print a single line containing either "YES" or "NO",
representing whether or not Alice has a winning strategy.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
5
2 1 2
3 3 1
4 2 3
5 2 4
7 6 2
OutputCopy
NO
YES
NO
YES
YES
Note
In the first test case, Alice has no legal moves. Therefore, Alice loses on the
first turn.

In the second test case, Alice can only move to lilypad 2
. Then, Bob has no legal moves. Therefore, Alice has a winning strategy in this
case.

In the third test case, Alice can only move to lilypad 1
. Then, Bob can move to lilypad 2
. Alice is no longer able to move and loses, giving Bob the win. It can be shown
that Bob can always win regardless of Alice's moves; hence, Alice does not have
a winning strategy.


*/
#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;

    // n no of lilypads
    // a,b is position of frogs
    // if Alice wining strategey print YES
    // else NO
    cout << ((a - b) % 2 ? "NO" : "YES") << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2055/320468172
