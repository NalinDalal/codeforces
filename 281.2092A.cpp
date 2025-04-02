/*A. Kamilka and the Sheep
time limit per test1 second
memory limit per test256 megabytes
Kamilka has a flock of 𝑛
 sheep, the 𝑖
-th of which has a beauty level of 𝑎𝑖
. All 𝑎𝑖
 are distinct. Morning has come, which means they need to be fed. Kamilka can
choose a non-negative integer 𝑑 and give each sheep 𝑑 bunches of grass. After
that, the beauty level of each sheep increases by 𝑑
.

In the evening, Kamilka must choose exactly two sheep and take them to the
mountains. If the beauty levels of these two sheep are 𝑥 and 𝑦 (after they have
been fed), then Kamilka's pleasure from the walk is equal to gcd(𝑥,𝑦) , where
gcd(𝑥,𝑦) denotes the greatest common divisor (GCD) of integers 𝑥 and 𝑦
.

The task is to find the maximum possible pleasure that Kamilka can get from the
walk.

Input
Each test consists of several test cases. The first line contains one integer 𝑡
 (1≤𝑡≤500
), the number of test cases. The description of the test cases follows.

The first line of each test case contains one integer 𝑛
 (2≤𝑛≤100
), the number of sheep Kamilka has.

The second line of each test case contains 𝑛
 distinct integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109)
 — the beauty levels of the sheep.

It is guaranteed that all 𝑎𝑖
 are distinct.

Output
For each test case, output a single integer: the maximum possible pleasure that
Kamilka can get from the walk.

Example
InputCopy
4
2
1 3
5
5 4 3 2 1
3
5 6 7
3
1 11 10
OutputCopy
2
4
2
10
Note
In the first test case, 𝑑=1
 works. In this case, the pleasure is gcd(1+1, 1+3)=gcd(2, 4)=2
. It can be shown that a greater answer cannot be obtained.

In the second test case, let's take 𝑑=3
. In this case, the pleasure is gcd(1+3, 5+3)=gcd(4, 8)=4
. Thus, for this test case, the answer is 4.*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int mx = 0;
    sort(begin(a), end(a));
    for (int i = 0; i < n; ++i) {
      for (int k = i + 1; k < n; ++k)
        mx = max(mx, a[k] - a[i]);
    }
    cout << mx << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2092/313640881
