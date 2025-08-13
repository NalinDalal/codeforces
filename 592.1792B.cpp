/* B. Stand-up Comedian
time limit per test2 seconds
memory limit per test256 megabytes
Eve is a beginner stand-up comedian. Her first show gathered a grand total of
two spectators: Alice and Bob.

Eve prepared 𝑎1+𝑎2+𝑎3+𝑎4
 jokes to tell, grouped by their type:

type 1: both Alice and Bob like them;
type 2: Alice likes them, but Bob doesn't;
type 3: Bob likes them, but Alice doesn't;
type 4: neither Alice nor Bob likes them.
Initially, both spectators have their mood equal to 0
. When a spectator hears a joke he/she likes, his/her mood increases by 1
. When a spectator hears a joke he/she doesn't like, his/her mood decreases by 1
. If the mood of a spectator becomes negative (strictly below zero), he/she
leaves.

When someone leaves, Eve gets sad and ends the show. If no one leaves, and Eve
is out of jokes, she also ends the show.

Thus, Eve wants to arrange her jokes in such a way that the show lasts as long
as possible. Help her to calculate the maximum number of jokes she can tell
before the show ends.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of testcases.

The only line of each testcase contains four integers 𝑎1,𝑎2,𝑎3,𝑎4
 (0≤𝑎1,𝑎2,𝑎3,𝑎4≤108
; 𝑎1+𝑎2+𝑎3+𝑎4≥1
) — the number of jokes of each type Eve prepared.

Output
For each testcase, print a single integer — the maximum number of jokes Eve can
tell before at least one of the spectators leaves or before she runs out of
jokes.

Example
InputCopy
4
5 0 0 0
0 0 0 5
2 5 10 6
3 0 0 7
OutputCopy
5
1
15
7
Note
In the first testcase, Eve only has jokes of the first type. Thus, there's no
order to choose. She tells all her jokes, both Alice and Bob like them. Their
mood becomes 5 . The show ends after Eve runs out of jokes.

In the second testcase, Eve only has jokes of the fourth type. Thus, once again
no order to choose. She tells a joke, and neither Alice, nor Bob likes it. Their
mood decrease by one, becoming −1 . They both have negative mood, thus, both
leave, and the show ends.

In the third testcase, first, Eve tells both jokes of the first type. Both Alice
and Bob has mood 2 . Then she can tell 2 jokes of the third type. Alice's mood
becomes 0 . Bob's mood becomes 4 . Then 4 jokes of the second type. Alice's mood
becomes 4 . Bob's mood becomes 0 . Then another 4 jokes of the third type.
Alice's mood becomes 0 . Bob's mood becomes 4 . Then the remaining joke of the
second type. Alice's mood becomes 1 . Bob's mood becomes 3 . Then one more joke
of the third type, and a joke of the fourth type, for example. Alice's mood
becomes −1 , she leaves, and the show ends.

In the fourth testcase, Eve should first tell the jokes both spectators like,
then the jokes they don't. She can tell 4 jokes of the fourth type until the
spectators leave.
*/

#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long a, b, c, d;
    cin >> a >> b >> c >> d;

    long cnt = a;
    long m = (b < c) ? b : c;

    if (a) {
      cnt += 2 * m;
      b -= m;
      c -= m;
    }

    if (b) {
      long more = (a < b) ? a : b;
      b -= more;
      a -= more;
      cnt += more;
    } else {
      long more = (a < c) ? a : c;
      c -= more;
      a -= more;
      cnt += more;
    }

    if (a > 0) {
      long more = (a < d) ? a : d;
      d -= more;
      a -= more;
      cnt += more;
    }

    if (b > 0 || c > 0 || d > 0) {
      ++cnt;
    }

    cout << cnt << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1792/333741672
