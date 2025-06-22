/*C. Black Circles
time limit per test2 seconds
memory limit per test256 megabytes
There are 𝑛
 circles on a two-dimensional plane. The 𝑖
-th circle is centered at (𝑥𝑖,𝑦𝑖)
. Initially, all circles have a radius of 0
.

The circles' radii increase at a rate of 1
 unit per second.

You are currently at (𝑥𝑠,𝑦𝑠)
; your goal is to reach (𝑥𝑡,𝑦𝑡)
 without touching the circumference of any circle (including the moment you
reach (𝑥𝑡,𝑦𝑡)
). You can move in any direction you want. However, your speed is limited to 1
 unit per second.

Please determine whether this is possible.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤105
) — the number of circles.

The next 𝑛
 lines each contain two integers 𝑥𝑖
, 𝑦𝑖
 (1≤𝑥𝑖,𝑦𝑖≤109
) — the center of each circle.

The final line contains four integers 𝑥𝑠
, 𝑦𝑠
, 𝑥𝑡
, 𝑦𝑡
 (1≤𝑥𝑠,𝑦𝑠,𝑥𝑡,𝑦𝑡≤109
) — the coordinates of the starting point and the goal, respectively.

It is guaranteed that these 𝑛+2
 points are distinct.

It is guaranteed that the sum of 𝑛
 over all testcases does not exceed 105
.

Output
For each test case, output 𝚈𝙴𝚂
 if it is possible to reach the goal without touching the circle boundaries, and
output 𝙽𝙾 otherwise.

You can output 𝚈𝚎𝚜
 and 𝙽𝚘
 in any case (for example, strings 𝚢𝙴𝚜
, 𝚢𝚎𝚜
, 𝚈𝚎𝚜
, and 𝚈𝙴𝚂
 will be recognized as a positive response).

Example
InputCopy
7
3
2 5
2 14
10 13
4 9 9 7
3
10 11
6 9
12 12
14 13 4 8
1
5 7
12 6 11 13
2
1000000000 2
2 1000000000
1 1 2 2
1
999999998 1000000000
999999999 999999999 1 1
1
1000000000 1
1 1000000000 1 1
10
989237121 2397081
206669655 527238537
522705783 380636165
532545346 320061691
207818728 199485303
884520552 315781807
992311437 802563521
205138355 324818663
223575704 395073023
281560523 236279118
216941610 572010615 323956540 794523071
OutputCopy
YES
NO
YES
YES
YES
NO
YES
Note
In the first test case, a feasible way of movement is as follows.




*/

#include <cstdio>
#include <vector>
typedef long long ll;

int main() {

  ll t;
  scanf("%lld", &t);
  while (t--) {
    ll n;
    scanf("%lld", &n);
    std::vector<ll> x(n), y(n);
    for (ll p = 0; p < n; p++) {
      scanf("%lld %lld", &x[p], &y[p]);
    }
    ll xs, ys, xt, yt;
    scanf("%lld %lld %lld %lld", &xs, &ys, &xt, &yt);
    ll dst = (xs - xt) * (xs - xt) + (ys - yt) * (ys - yt);
    bool possible(true);
    for (long p = 0; possible && p < n; p++) {
      ll cdt = (x[p] - xt) * (x[p] - xt) + (y[p] - yt) * (y[p] - yt);
      if (cdt <= dst) {
        possible = false;
      }
    }

    puts(possible ? "YES" : "NO");
  }
}
// sub: https://codeforces.com/problemset/submission/2002/325516640
