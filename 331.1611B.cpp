/* B. Team Composition: Programmers and Mathematicians
time limit per test1 second
memory limit per test256 megabytes
The All-Berland Team Programming Contest will take place very soon. This year,
teams of four are allowed to participate.

There are 𝑎
 programmers and 𝑏
 mathematicians at Berland State University. How many maximum teams can be made
if:

each team must consist of exactly 4
 students,
teams of 4
 mathematicians or 4
 programmers are unlikely to perform well, so the decision was made not to
compose such teams. Thus, each team must have at least one programmer and at
least one mathematician.

Print the required maximum number of teams. Each person can be a member of no
more than one team.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) —the number of test cases.

This is followed by descriptions of 𝑡
 sets, one per line. Each set is given by two integers 𝑎
 and 𝑏
 (0≤𝑎,𝑏≤109
).

Output
Print 𝑡
 lines. Each line must contain the answer to the corresponding set of input data
— the required maximum number of teams.

Example
InputCopy
6
5 5
10 1
2 3
0 0
17 2
1000000000 1000000000
OutputCopy
2
1
1
0
2
500000000
Note
In the first test case of the example, two teams can be composed. One way to
compose two teams is to compose two teams of 2 programmers and 2 mathematicians.

In the second test case of the example, only one team can be composed: 3
 programmers and 1
 mathematician in the team.

*/

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    // a are no of programmer
    // b are mathematician
    // team consist of 4 person, need atleast 1 programmer and 1 mathematician
    // cout no of teams possible
    // max no of team limited by:
    // total people/4
    // min(a,b)
    // valid team=min({a, b, (a + b) / 4})
    int ans = min({a, b, (a + b) / 4});
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1611/318681413
