/*A. Zhan's Blender
time limit per test1 second
memory limit per test256 megabytes
Today, a club fair was held at "NSPhM". In order to advertise his pastry club,
Zhan decided to demonstrate the power of his blender.

To demonstrate the power of his blender, Zhan has 𝑛
 fruits.

The blender can mix up to 𝑥
 fruits per second.

In each second, Zhan can put up to 𝑦
 fruits into the blender. After that, the blender will blend min(𝑥,𝑐)
 fruits, where 𝑐
 is the number of fruits inside the blender. After blending, blended fruits are
removed from the blender.

Help Zhan determine the minimum amount of time required for Zhan to blend all
fruits.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤1000
). The description of the test cases follows.

The first line of each test case contains one integer 𝑛
 (0≤𝑛≤109
) — the number of fruits Zhan has.

The second line of each test case contains two integers 𝑥
 and 𝑦
 (1≤𝑥,𝑦≤109
) — the number of fruits the blender can blend per second and the number of
fruits Zhan can put into the blender per second.

Output
For each testcase, output a single integer — the minimum number of seconds to
blend all fruits.

Example
InputCopy
5
5
3 4
3
1 2
6
4 3
100
4 3
9
3 3
OutputCopy
2
3
2
34
3
Note
In the first example, you can first put 2
 fruits in the blender. After that, the blender will mix these 2
 fruits, and in the end, there will be 0
 fruits left in the blender. Then you can put 3
 fruits into the blender, after which the blender will mix these 3
 fruits.

In the second example, you can put 1
 fruit into the blender 3
 times.

In the third example, you can first put 3
 fruits into the blender, then add another 3
 fruits.

*/

#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;

    // x is rate of blender
    // y is rate of putting fruit
    // blender bends min(x,c) fruits, c is no of fruit in blender
    long long rate = min(x, y);
    long long ansSec = (n + rate - 1) / rate;

    // min amount of time to blend all fruits
    /*If y >= x: feeder is never a bottleneck.
→ Blender speed dominates.
→ Time = ceil(n / x).

If y < x: feeder is bottleneck (cannot provide enough to match blender).
→ Time = ceil(n / y).
        */

    cout << ansSec << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2013/337695793
