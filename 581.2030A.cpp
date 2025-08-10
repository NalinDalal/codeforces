/*A. A Gift From Orangutan
time limit per test1 second
memory limit per test256 megabytes
While exploring the jungle, you have bumped into a rare orangutan with a bow
tie! You shake hands with the orangutan and offer him some food and water. In
return...

The orangutan has gifted you an array 𝑎
 of length 𝑛
. Using 𝑎
, you will construct two arrays 𝑏
 and 𝑐
, both containing 𝑛
 elements, in the following manner:

𝑏𝑖=min(𝑎1,𝑎2,…,𝑎𝑖)
 for each 1≤𝑖≤𝑛
.
𝑐𝑖=max(𝑎1,𝑎2,…,𝑎𝑖)
 for each 1≤𝑖≤𝑛
.
Define the score of 𝑎
 as ∑𝑛𝑖=1𝑐𝑖−𝑏𝑖
 (i.e. the sum of 𝑐𝑖−𝑏𝑖
 over all 1≤𝑖≤𝑛
). Before you calculate the score, you can shuffle the elements of 𝑎
 however you want.

Find the maximum score that you can get if you shuffle the elements of 𝑎
 optimally.

Input
The first line contains 𝑡
 (1≤𝑡≤100
) — the number of test cases.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤1000
) — the number of elements in 𝑎
.

The following line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤1000
) — the elements of the array 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 1000
.

Output
For each test case, output the maximum score that you can get.

Example
InputCopy
3
1
69
3
7 6 5
5
1 1 1 2 2
OutputCopy
0
4
4
Note
In the first test case, there is no other way to rearrange 𝑎
. So, 𝑏=[69]
 and 𝑐=[69]
. The only possible score is 69−69=0
.

In the second test case, you can rearrange 𝑎
 as [7,5,6]
. Here, 𝑏=[7,5,5]
 and 𝑐=[7,7,7]
. The score in this case is (7−7)+(7−5)+(7−5)=4
. It can be shown this is the maximum possible score.
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());
    cout << (n - 1) * (mx - mn) << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2030/333219966
