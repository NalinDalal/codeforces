/*C. Coloring Game
time limit per test2.5 seconds
memory limit per test256 megabytes
Alice and Bob are playing a game using an integer array 𝑎
 of size 𝑛
.

Initially, all elements of the array are colorless. First, Alice chooses 3
 elements and colors them red. Then Bob chooses any element and colors it blue
(if it was red — recolor it). Alice wins if the sum of the red elements is
strictly greater than the value of the blue element.

Your task is to calculate the number of ways that Alice can choose 3
 elements in order to win regardless of Bob's actions.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (3≤𝑛≤5000
).

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎1≤𝑎2≤⋯≤𝑎𝑛≤105
).

Additional constraint on the input: the sum of 𝑛
 over all test cases doesn't exceed 5000
.

Output
For each test case, print a single integer — the number of ways that Alice can
choose 3 elements in order to win regardless of Bob's actions.

Example
InputCopy
6
3
1 2 3
4
1 1 2 4
5
7 7 7 7 7
5
1 1 2 2 4
6
2 3 3 4 5 5
5
1 1 1 1 3
OutputCopy
0
0
10
2
16
0
Note
In the first two test cases, no matter which three elements Alice chooses, Bob
will be able to paint one element blue so that Alice does not win.

In the third test case, Alice can choose any three elements. If Bob colors one
of the red elements, the sum of red elements will be 14 , and the sum of blue
elements will be 7 . If Bob chooses an uncolored element, the sum of red
elements will be 21 , and the sum of blue elements will be 7
.

In the fourth test case, Alice can choose either the 1
-st, 3
-rd and 4
-th element, or the 2
-nd, 3
-rd and 4
-th element.
*/

/*Alice picks 3 elements → paints them red.

Bob picks 1 element → paints it blue (if already red, it gets recolored).

Alice wins if:
sum of red elements>blue element value

We want to count how many triplets Alice can pick such that she always wins, no
matter what Bob does.


say a[i] is red,
new sum=a[j]+a[k]
blue=a[i]
=> a[j]+a[k]>a[i]

say a[i] is blue
red sum=a[i]+a[j]+a[k]
blue=a[i]
=> a[i]+a[j]+a[k]>max(a)

alice wins if in (x,y,z) x+y>z || x+y+z>an
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    long long ans = 0;
    long long maxVal = a[n - 1];

    for (int k = 2; k < n; k++) {
      int i = 0, j = k - 1;
      while (i < j) {
        if (a[i] + a[j] > a[k]) {
          // Need a[x] + a[j] + a[k] > maxVal
          long long need = maxVal - (a[j] + a[k]) + 1;
          auto it = lower_bound(a.begin() + i, a.begin() + j, need);
          int idx = it - a.begin();
          if (idx < j) {
            ans += (j - idx);
          }
          j--;
        } else {
          i++;
        }
      }
    }

    cout << ans << "\n";
  }
}
// sub: https://codeforces.com/problemset/submission/2112/338286714
