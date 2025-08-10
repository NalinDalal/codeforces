/*B. Vika and the Bridge
time limit per test1 second
memory limit per test256 megabytes
In the summer, Vika likes to visit her country house. There is everything for
relaxation: comfortable swings, bicycles, and a river.

There is a wooden bridge over the river, consisting of 𝑛
 planks. It is quite old and unattractive, so Vika decided to paint it. And in
the shed, they just found cans of paint of 𝑘 colors.

After painting each plank in one of 𝑘
 colors, Vika was about to go swinging to take a break from work. However, she
realized that the house was on the other side of the river, and the paint had
not yet completely dried, so she could not walk on the bridge yet.

In order not to spoil the appearance of the bridge, Vika decided that she would
still walk on it, but only stepping on planks of the same color. Otherwise, a
small layer of paint on her sole will spoil the plank of another color. Vika
also has a little paint left, but it will only be enough to repaint one plank of
the bridge.

Now Vika is standing on the ground in front of the first plank. To walk across
the bridge, she will choose some planks of the same color (after repainting),
which have numbers 1≤𝑖1<𝑖2<…<𝑖𝑚≤𝑛 (planks are numbered from 1 from left to
right). Then Vika will have to cross 𝑖1−1,𝑖2−𝑖1−1,𝑖3−𝑖2−1,…,𝑖𝑚−𝑖𝑚−1−1,𝑛−𝑖𝑚
 planks as a result of each of 𝑚+1
 steps.

Since Vika is afraid of falling, she does not want to take too long steps. Help
her and tell her the minimum possible maximum number of planks she will have to
cross in one step, if she can repaint one (or zero) plank a different color
while crossing the bridge.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑘≤𝑛≤2⋅105
) — the number of planks in the bridge and the number of different colors of
paint.

The second line of each test case contains 𝑛
 integers 𝑐1,𝑐2,𝑐3,…,𝑐𝑛
 (1≤𝑐𝑖≤𝑘
) — the colors in which Vika painted the planks of the bridge.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the minimum possible maximum
number of planks that Vika will have to step over in one step.

Example
InputCopy
5
5 2
1 1 2 1 1
7 3
1 2 3 3 3 2 1
6 6
1 2 3 4 5 6
8 4
1 2 3 4 2 3 1 4
3 1
1 1 1
OutputCopy
0
1
2
2
0
Note
In the first test case, Vika can repaint the plank in the middle in color 1
 and walk across the bridge without stepping over any planks.

In the second test case, Vika can repaint the plank in the middle in color 2
 and walk across the bridge, stepping over only one plank each time.

In the third test case, Vika can repaint the penultimate plank in color 2
 and walk across the bridge, stepping only on planks with numbers 2
 and 5
. Then Vika will have to step over 1
, 2
 and 1
 plank each time she steps, so the answer is 2
.

In the fourth test case, Vika can simply walk across the bridge without
repainting it, stepping over two planks each time, walking on planks of color 3
.

In the fifth test case, Vika can simply walk across the bridge without
repainting it, without stepping over any planks.



*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n, k;
    cin >> n >> k;

    vector<long> last(k + 1, 0);
    vector<long> first(k + 1, 0);
    vector<long> second(k + 1, 0);

    for (long p = 1; p <= n; p++) {
      long x;
      cin >> x;
      long dist = p - last[x] - 1;
      last[x] = p;
      if (dist >= first[x]) {
        second[x] = first[x];
        first[x] = dist;
      } else if (dist >= second[x]) {
        second[x] = dist;
      }
    }

    for (long p = 1; p <= k; p++) {
      long dist = n - last[p];
      if (dist >= first[p]) {
        second[p] = first[p];
        first[p] = dist;
      } else if (dist >= second[p]) {
        second[p] = dist;
      }
    }

    long ans = n;
    for (long p = 1; p <= k; p++) {
      long cur = second[p];
      if (cur <= first[p] / 2) {
        cur = first[p] / 2;
      }
      ans = min(ans, cur);
    }

    cout << ans << "\n";
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1848/333220470
