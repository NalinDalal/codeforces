/* A. Minutes Before the New Year
time limit per test1 second
memory limit per test256 megabytes
New Year is coming and you are excited to know how many minutes remain before
the New Year. You know that currently the clock shows ℎ hours and 𝑚 minutes,
where 0≤ℎℎ<24 and 0≤𝑚𝑚<60. We use 24-hour time format!

Your task is to find the number of minutes before the New Year. You know that
New Year comes when the clock shows 0 hours and 0 minutes.

You have to answer 𝑡 independent test cases.

Input
The first line of the input contains one integer 𝑡 (1≤𝑡≤1439) — the number of
test cases.

The following 𝑡 lines describe test cases. The 𝑖-th line contains the time as
two integers ℎ and 𝑚 (0≤ℎ<24, 0≤𝑚<60). It is guaranteed that this time is not a
midnight, i.e. the following two conditions can't be met at the same time: ℎ=0
and 𝑚=0. It is guaranteed that both ℎ and 𝑚 are given without leading zeros.

Output
For each test case, print the answer on it — the number of minutes before the
New Year.

Example
InputCopy
5
23 55
23 0
0 1
4 20
23 59
OutputCopy
5
60
1439
1180
1

*/

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int h, m;
    cin >> h >> m;
    // h-hours
    // m-minutes
    // return time b/f new year i.e. 12AM
    // given in 24hr format
    int time = h * 60 + m;
    int ans = 24 * 60 - time;
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1283/307031375
