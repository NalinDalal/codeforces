/* https://codeforces.com/problemset/problem/581/A
A. Vasya the Hipster
time limit per test1 second
memory limit per test256 megabytes
One day Vasya the Hipster decided to count how many socks he had. It turned out
that he had a red socks and b blue socks.

According to the latest fashion, hipsters should wear the socks of different
colors: a red one on the left foot, a blue one on the right foot.

Every day Vasya puts on new socks in the morning and throws them away before
going to bed as he doesn't want to wash them.

Vasya wonders, what is the maximum number of days when he can dress fashionable
and wear different socks, and after that, for how many days he can then wear the
same socks until he either runs out of socks or cannot make a single pair from
the socks he's got.

Can you help him?

Input
The single line of the input contains two positive integers a and b
(1 ≤ a, b ≤ 100) — the number of red and blue socks that Vasya's got.

Output
Print two space-separated integers — the maximum number of days when Vasya can
wear different socks and the number of days when he can wear the same socks
until he either runs out of socks or cannot make a single pair from the socks
he's got.

Keep in mind that at the end of the day Vasya throws away the socks that he's
been wearing on that day.

Examples
InputCopy
3 1
OutputCopy
1 1
InputCopy
2 3
OutputCopy
2 0
InputCopy
7 3
OutputCopy
3 2
Note
In the first sample Vasya can first put on one pair of different socks, after
that he has two red socks left to wear on the second day.
*/

// a red socks - on left foot
// b blue socks - on right foot
// red paired with blue - dDiff
// same sock - dSame
// return dDiff, dSame
// input=a,b
// output=dDiff,dSame

#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int diff = (a < b) ? a : b;
  int after = (a + b - 2 * diff) / 2;
  cout << diff << " " << after;
  return 0;
}

// sub: https://codeforces.com/problemset/submission/581/303823654
