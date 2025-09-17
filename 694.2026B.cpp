/*B. Black Cells
time limit per test2 seconds
memory limit per test256 megabytes
You are given a strip divided into cells, numbered from left to right from 0
 to 1018
. Initially, all cells are white.

You can perform the following operation: choose two white cells 𝑖
 and 𝑗
, such that 𝑖≠𝑗
 and |𝑖−𝑗|≤𝑘
, and paint them black.

A list 𝑎
 is given. All cells from this list must be painted black. Additionally, at most
one cell that is not in this list can also be painted black. Your task is to
determine the minimum value of 𝑘 for which this is possible.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤500
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2000
).

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0<𝑎𝑖<1018
; 𝑎𝑖<𝑎𝑖+1
).

Additional constraint on the input: the sum of 𝑛
 across all test cases does not exceed 2000
.

Output
For each test case, print a single integer — the minimum value of 𝑘
 for which it is possible to paint all the given cells black.

Example
InputCopy
4
2
1 2
1
7
3
2 4 9
5
1 5 8 10 13
OutputCopy
1
1
2
3
Note
In the first example, with 𝑘=1
, it is possible to paint the cells (1,2)
.

In the second example, with 𝑘=1
, it is possible to paint the cells (7,8)
.

In the third example, with 𝑘=2
, it is possible to paint the cells (2,4)
 and (8,9)
.

In the fourth example, with 𝑘=3
, it is possible to paint the cells (0,1)
, (5,8)
 and (10,13)
.
*/

/*Initially all were white
 select any 2 paint them black
 if n was odd, so 1 gets remained so 1 extra neeeded
 hence no of black cell are even

 if n was even, paint pair of cells
 0 extra

 sort the array
 take adjacent elemnts

 odd case last gets remained
 so take dist b/w a[0] and a[1]
 then a[2] and a[3]

 max among these is 4
 k=4, min k to satisfy both condition is 4 hence

n->odd
    i is removed
        k=max diff of consecutive elemtns

    so exclude 1st then some ans you get
    exclude 2nd then something

    among them take the minimum, that is ans

n->even
    can't exclude
    ans=max among all pairs


consider:
1 2 5 8 9

1 removed then 3 is ans
9 removed then ans=4
5 removed ans=1

finalAns=1
*/
/*if (n == 1) {
    cout << "1\n";
    return;
}


Case 2: n % 2 == 0 (even number of required cells)
int ans = a[1] - a[0];
for (int i = 2; i < n; i += 2) {
    ans = max(ans, a[i + 1] - a[i]);
}
cout << ans << '\n';


Case 3: n % 2 == 1 (odd number of required cells)
int ans = INF;
for (int i = 0; i < n; i++) {
    vector<int> v;
    for (int j = 0; j < n; j++) {
        if (j == i) continue;
        v.push_back(a[j]);
    }
    int mx = v[1] - v[0];
    for (int j = 2; j < n - 1; j += 2) {
        mx = max(mx, v[j + 1] - v[j]);
    }
    ans = min(ans, mx);
}
cout << ans << '\n';
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a.begin(), a.end());

  if (n == 1) {
    cout << 1 << "\n";
    return;
  }

  // Case 1: n is even
  if (n % 2 == 0) {
    long long ans = 0;
    for (int i = 0; i < n; i += 2) {
      ans = max(ans, a[i + 1] - a[i]);
    }
    cout << ans << "\n";
  }
  // Case 2: n is odd
  else {
    long long ans = LLONG_MAX;

    // Try skipping one element (we can skip exactly one because of the extra
    // cell allowed)
    for (int skip = 0; skip < n; skip++) {
      long long mx = 0;
      vector<long long> v;
      for (int j = 0; j < n; j++) {
        if (j == skip)
          continue;
        v.push_back(a[j]);
      }
      for (int j = 0; j < (int)v.size(); j += 2) {
        mx = max(mx, v[j + 1] - v[j]);
      }
      ans = min(ans, mx);
    }
    cout << ans << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2026/339014902
