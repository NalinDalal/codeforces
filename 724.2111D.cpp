/*D. Creating a Schedule
time limit per test2.5 seconds
memory limit per test512 megabytes
A new semester is about to begin, and it is necessary to create a schedule for
the first day. There are a total of 𝑛 groups and 𝑚 classrooms in the faculty. It
is also known that each group has exactly 6 classes on the first day, and the 𝑘
-th class of each group takes place at the same time. Each class must be held in
a classroom, and at the same time, there cannot be classes for more than one
group in the same classroom.

Each classroom has its own index (at least three digits), and all digits of this
index, except for the last two, indicate the floor on which the classroom is
located. For example, classroom 479 is located on the 4 -th floor, while
classroom 31415 is on the 314 -th floor. Between floors, one can move by stairs;
for any floor 𝑥>1 , one can either go down to floor 𝑥−1 or go up to floor 𝑥+1 ;
from the first floor, one can only go up to the second; from the floor 107
 (which is the last one), it is possible to go only to the floor 9999999
.

The faculty's dean's office has decided to create the schedule in such a way
that students move as much as possible between floors, meaning that the total
number of movements between floors across all groups should be maximized. When
the students move from one floor to another floor, they take the shortest path.

For example, if there are 𝑛=2
 groups and 𝑚=4
 classrooms [479,290,478,293]
, the schedule can be arranged as follows:

Class No.	Group 1	Group 2
1
290
293
2
478
479
3
293
290
4
479
478
5
293
290
6
479
478
In such a schedule, the groups will move between the 2
nd and 4
th floors each time, resulting in a total of 20
 movements between floors.

Help the dean's office create any suitable schedule!

Input
Each test consists of several test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤103 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑚
 (1≤𝑛≤𝑚≤105
) — the number of groups and the number of available classrooms.

The second line of each test case contains 𝑚
 integers 𝑎𝑖
 (100≤𝑎𝑖<109
) — the indices of the available classrooms.

Additional constraints on the input:

the numbers of all classrooms are pairwise distinct;
the sum of 𝑚
 across all test cases does not exceed 105
.
Output
For each test case, output 𝑛
 lines, where the 𝑖
-th line should contain 6
 integers — the indices of the classrooms where the classes for the 𝑖
-th group will be held.

Each classroom must be occupied by at most one group during the 𝑘
-th class.

Example
InputCopy
3
2 4
479 290 478 293
1 1
31415
6 10
479 385 290 293 384 383 297 478 291 382
OutputCopy
290 478 293 479 293 479
293 479 290 478 290 478
31415 31415 31415 31415 31415 31415
479 290 479 290 479 290
290 479 290 479 290 479
293 478 293 478 293 478
297 385 297 385 297 385
478 293 478 293 478 293
291 384 291 384 291 384
Note
In the third test case, the maximum number of moves between classrooms is 50
.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<ll> a(m);
  for (auto &x : a)
    cin >> x;
  sort(a.begin(), a.end());

  for (ll i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) {
      if ((i + j) & 1) {
        cout << a[i / 2] << ' ';
      } else {
        cout << a[m - 1 - i / 2] << ' ';
      }
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2111/340687772
