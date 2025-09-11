/*E. Find the Car
time limit per test3 seconds
memory limit per test256 megabytes
Timur is in a car traveling on the number line from point 0
 to point 𝑛
. The car starts moving from point 0
 at minute 0
.

There are 𝑘+1
 signs on the line at points 0,𝑎1,𝑎2,…,𝑎𝑘
, and Timur knows that the car will arrive there at minutes 0,𝑏1,𝑏2,…,𝑏𝑘
, respectively. The sequences 𝑎
 and 𝑏
 are strictly increasing with 𝑎𝑘=𝑛
.


Between any two adjacent signs, the car travels with a constant speed. Timur has
𝑞 queries: each query will be an integer 𝑑 , and Timur wants you to output how
many minutes it takes the car to reach point 𝑑 , rounded down to the nearest
integer.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains three integers 𝑛
, 𝑘
, and 𝑞
, (𝑘≤𝑛≤109
; 1≤𝑘,𝑞≤105
) — the final destination, the number of points Timur knows the time for, and
the number of queries respectively.

The second line of each test case contains 𝑘
 integers 𝑎𝑖
 (1≤𝑎𝑖≤𝑛
; 𝑎𝑖<𝑎𝑖+1
 for every 1≤𝑖≤𝑘−1
; 𝑎𝑘=𝑛
).

The third line of each test case contains 𝑘
 integers 𝑏𝑖
 (1≤𝑏𝑖≤109
; 𝑏𝑖<𝑏𝑖+1
 for every 1≤𝑖≤𝑘−1
).

Each of the following 𝑞
 lines contains a single integer 𝑑
 (0≤𝑑≤𝑛
) — the distance that Timur asks the minutes passed for.

The sum of 𝑘
 over all test cases doesn't exceed 105
, and the sum of 𝑞
 over all test cases doesn't exceed 105
.

Output
For each query, output a single integer — the number of minutes passed until the
car reaches the point 𝑑 , rounded down.

Example
InputCopy
4
10 1 3
10
10
0
6
7
10 2 4
4 10
4 7
6
4
2
7
1000000000 1 1
1000000000
1000000000
99999999
6 1 3
6
5
2
6
5
OutputCopy
0 6 7
5 4 2 5
99999999
1 5 4
Note
For the first test case, the car goes from point 0
 to point 10
 in 10
 minutes, so the speed is 1
 unit per minute and:

At point 0
, the time will be 0
 minutes.
At point 6
, the time will be 6
 minutes.
At point 7
, the time will be 7
 minutes.
For the second test case, between points 0
 and 4
, the car travels at a speed of 1
 unit per minute and between 4
 and 10
 with a speed of 2
 units per minute and:

At point 6
, the time will be 5
 minutes.
At point 4
, the time will be 4
 minutes.
At point 2
, the time will be [48;56;204;1792;2856t2
 minutes.
At point 7
, the time will be 5.5
 minutes, so the answer is 5
.
For the fourth test case, the car travels with 1.2
 units per minute, so the answers to the queries are:

At point 2
, the time will be 1.66…
 minutes, so the answer is 1
.
At point 6
, the time will be 5
 minutes.
At point 5
, the time will be 4.16…
 minutes, so the answer is 4
.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    ll n, k, q;
    cin >> n >> k >> q;

    vector<ll> a(k + 1, 0), b(k + 1, 0);
    for (ll i = 1; i <= k; i++)
      cin >> a[i];
    for (ll i = 1; i <= k; i++)
      cin >> b[i];

    for (ll i = 0; i < q; i++) {
      ll d;
      cin >> d;

      if (d == n) {
        cout << b.back() << " ";
        continue;
      }

      ll idx = upper_bound(a.begin(), a.end(), d) - a.begin();
      ll res = b[idx - 1] +
               (b[idx] - b[idx - 1]) * (d - a[idx - 1]) / (a[idx] - a[idx - 1]);
      cout << res << " ";
    }
    cout << "\n";
  }

  return 0;
}

// sub: https://codeforces.com/contest/1971/submission/338028849
