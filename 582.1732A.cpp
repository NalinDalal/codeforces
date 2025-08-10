/*A. Bestie
time limit per test1 second
memory limit per test256 megabytes
You are given an array 𝑎
 consisting of 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
. Friends asked you to make the greatest common divisor (GCD) of all numbers in
the array equal to 1 . In one operation, you can do the following:

Select an arbitrary index in the array 1≤𝑖≤𝑛
;
Make 𝑎𝑖=gcd(𝑎𝑖,𝑖)
, where gcd(𝑥,𝑦)
 denotes the GCD of integers 𝑥
 and 𝑦
. The cost of such an operation is 𝑛−𝑖+1
.
You need to find the minimum total cost of operations we need to perform so that
the GCD of the all array numbers becomes equal to 1
.

Input
Each test consists of multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤5000
) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤20
) — the length of the array.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the elements of the array.

Output
For each test case, output a single integer — the minimum total cost of
operations that will need to be performed so that the GCD of all numbers in the
array becomes equal to 1
.

We can show that it's always possible to do so.

Example
InputCopy
9
1
1
1
2
2
2 4
3
3 6 9
4
5 10 15 20
5
120 60 80 40 80
6
150 90 180 120 60 30
6
2 4 6 9 12 18
6
30 60 90 120 125 125
OutputCopy
0
1
2
2
1
3
3
0
1
Note
In the first test case, the GCD of the entire array is already equal to 1
, so there is no need to perform operations.

In the second test case, select 𝑖=1
. After this operation, 𝑎1=gcd(2,1)=1
. The cost of this operation is 1
.

In the third test case, you can select 𝑖=1
, after that the array 𝑎
 will be equal to [1,4]
. The GCD of this array is 1
, and the total cost is 2
.

In the fourth test case, you can select 𝑖=2
, after that the array 𝑎
 will be equal to [3,2,9]
. The GCD of this array is 1
, and the total cost is 2
.

In the sixth test case, you can select 𝑖=4
 and 𝑖=5
, after that the array 𝑎
 will be equal to [120,60,80,4,5]
. The GCD of this array is 1
, and the total cost is 3
.
*/

#include <bits/stdc++.h>
using namespace std;

long long gcd_all(const vector<long long> &arr) {
  long long g = 0;
  for (auto x : arr)
    g = gcd(g, x);
  return g;
}

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

    if (gcd_all(a) == 1) {
      cout << 0 << "\n";
      continue;
    }

    int ans = INT_MAX;

    // Try 1 change
    for (int i = 0; i < n; i++) {
      auto b = a;
      b[i] = gcd(b[i], i + 1);
      if (gcd_all(b) == 1)
        ans = min(ans, n - i);
    }

    // Try 2 changes
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        auto b = a;
        b[i] = gcd(b[i], i + 1);
        b[j] = gcd(b[j], j + 1);
        if (gcd_all(b) == 1)
          ans = min(ans, (n - i) + (n - j));
      }
    }

    // Worst case
    if (ans == INT_MAX)
      ans = 3;

    cout << ans << "\n";
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1732/333220146
