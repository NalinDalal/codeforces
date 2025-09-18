/*B. Cat, Fox and the Lonely Array
time limit per test2 seconds
memory limit per test256 megabytes
Today, Cat and Fox found an array 𝑎
 consisting of 𝑛
 non-negative integers.

Define the loneliness of 𝑎
 as the smallest positive integer 𝑘
 (1≤𝑘≤𝑛
) such that for any two positive integers 𝑖
 and 𝑗
 (1≤𝑖,𝑗≤𝑛−𝑘+1
), the following holds:
𝑎𝑖|𝑎𝑖+1|…|𝑎𝑖+𝑘−1=𝑎𝑗|𝑎𝑗+1|…|𝑎𝑗+𝑘−1,
where 𝑥|𝑦
 denotes the bitwise OR of 𝑥
 and 𝑦
. In other words, for every 𝑘
 consecutive elements, their bitwise OR should be the same. Note that the
loneliness of 𝑎 is well-defined, because for 𝑘=𝑛 the condition is satisfied.

Cat and Fox want to know how lonely the array 𝑎
 is. Help them calculate the loneliness of the found array.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains one integer 𝑛
 (1≤𝑛≤105
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖<220
) — the elements of the array.

It is guaranteed that the sum of 𝑛
 over all test cases doesn't exceed 105
.

Output
For each test case, print one integer  — the loneliness of the given array.

Example
InputCopy
7
1
0
3
2 2 2
3
1 0 2
5
3 0 1 4 2
5
2 0 4 0 2
7
0 0 0 0 1 2 4
8
0 1 3 2 2 1 0 3
OutputCopy
1
1
3
4
4
7
3
Note
In the first example, the loneliness of an array with a single element is always
1 , so the answer is 1
.

In the second example, the OR of each subarray of length 𝑘=1
 is 2
, so the loneliness of the whole array is 1
.

In the seventh example, it's true that
(0|1|3)=(1|3|2)=(3|2|2)=(2|2|1)=(2|1|0)=(1|0|3)=3 , so the condition is
satisfied for 𝑘=3 . We can verify that the condition is not true for any smaller
𝑘 , so the answer is indeed 3
.
*/

/*given an array
 find a sequence of length k that bitwise OR should be equal to each other

 apply binary search

 bitwise OR of all subarray of lenght k should be equal

 find the smallest value of k such that all subarray with length will have
 bitwise OR = bitwise OR of all elements of array

 binary search on ans
*/

/*(t--){
 n,vector<int> a(n)
 ans=0
 for(0 to 29){
    Collect all indices where this bit is set.

Compute the largest gap between consecutive occurrences (including start to
first and last to end).

 ans = max(ans, gap).
 }
 cout<<ans<<endl
  }
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    int ans = 1;
    for (int b = 0; b < 30; b++) { // check each bit
      vector<int> occ;
      for (int i = 0; i < n; i++) {
        if (a[i] >> b & 1)
          occ.push_back(i);
      }
      if (occ.empty())
        continue; // bit never appears

      int last = -1, mx = 0;
      for (int idx : occ) {
        mx = max(mx, idx - last);
        last = idx;
      }
      mx = max(mx, n - last); // tail segment
      ans = max(ans, mx);
    }

    cout << ans << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1973/339195230
