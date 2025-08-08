/*B. No Casino in the Mountains
time limit per test1 second
memory limit per test256 megabytes
You are given an array 𝑎
 of 𝑛
 numbers and a number 𝑘
. The value 𝑎𝑖
 describes the weather on the 𝑖
-th day: if it rains on the 𝑖
-th day, then 𝑎𝑖=1
; otherwise, if the weather is good on the 𝑖
-th day, then 𝑎𝑖=0
.

Jean wants to visit as many peaks as possible. One hike to a peak takes exactly
𝑘 days, and during each of these days, the weather must be good (𝑎𝑖=0
). That is, formally, he can start a hike on day 𝑖
 only if all 𝑎𝑗=0
 for all 𝑗
 (𝑖≤𝑗≤𝑖+𝑘−1)
.

After each hike, before starting the next one, Jean must take a break of at
least one day, meaning that on the day following a hike, he cannot go on another
hike.

Find the maximum number of peaks that Jean can visit.

Input
Each test consists of several test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤105
, 1≤𝑘≤𝑛
).

The second line contains 𝑛
 numbers 𝑎𝑖
 (𝑎𝑖∈{0,1}
), where 𝑎𝑖
 denotes the weather on the 𝑖
-th day.

It is guaranteed that the total value of 𝑛
 across all test cases does not exceed 105
.

Output
For each test case, output a single integer: the maximum number of hikes that
Jean can make.

Example
InputCopy
5
5 1
0 1 0 0 0
7 3
0 0 0 0 0 0 0
3 1
1 1 1
4 2
0 1 0 1
6 2
0 0 1 0 0 0
OutputCopy
3
2
0
0
2
Note
In the first sample:

Day 1
 — good weather, Jean goes on a hike. (𝑎1=0
)
Day 2
 — mandatory break.
Day 3
 — again good weather, Jean goes on the second hike. (𝑎3=0
)
Day 4
 — break.
Day 5
 — good weather, third hike. (𝑎5=0
)
Thus, Jean can make 3 hikes, alternating each with a mandatory day of rest.
In the second sample:

From day 1
 to day 3
 — three days of good weather, Jean goes on a hike. (𝑎1=𝑎2=𝑎3=0
)
Day 4
 — mandatory break.
From day 5
 to day 7
 — again three days of good weather, Jean goes on the second hike. (𝑎5=𝑎6=𝑎7=0
)
In total, Jean makes 2 hikes.
In the third sample:

There are no days with good weather (𝑎𝑖=1
 for all 𝑖
)
Jean cannot make any hikes. Answer: 0


*/

#include <bits/stdc++.h>
using namespace std;

int sol(vector<int> a, int k) {
  int n = a.size();
  int ans = 0;
  int i = 0;
  // a[i]=0 means dry
  // a[i]=1 means rain
  // k days hike, so for all j {i<=j<=i+k-1}
  // one day break
  // max no of hikes
  // for continuous k days there must be no rain
  // sliding window of size k where continuous 0 are there
  // count total times condition met

  while (i <= n - k) {
    bool canHike = true;

    // Check if the next k days are all dry
    for (int j = i; j < i + k; ++j) {
      if (a[j] == 1) { // rain
        canHike = false;
        break;
      }
    }

    if (canHike) {
      ans++;
      i += k + 1; // skip k days + 1 break day
    } else {
      i++; // try next starting point
    }
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    cout << sol(a, k) << endl;
  }
  return 0;
}
