/*C. Equal Values
time limit per test2 seconds
memory limit per test512 megabytes
You are given an array 𝑎1,𝑎2,…,𝑎𝑛
, consisting of 𝑛
 integers.

In one operation, you are allowed to perform one of the following actions:

Choose a position 𝑖
 (1<𝑖≤𝑛
) and make all elements to the left of 𝑖
 equal to 𝑎𝑖
. That is, assign the value 𝑎𝑖
 to all 𝑎𝑗
 (1≤𝑗<𝑖
). The cost of such an operation is (𝑖−1)⋅𝑎𝑖
.
Choose a position 𝑖
 (1≤𝑖<𝑛
) and make all elements to the right of 𝑖
 equal to 𝑎𝑖
. That is, assign the value 𝑎𝑖
 to all 𝑎𝑗
 (𝑖<𝑗≤𝑛
). The cost of such an operation is (𝑛−𝑖)⋅𝑎𝑖
.
Note that the elements affected by an operation may already be equal to 𝑎𝑖
, but that doesn't change the cost.

You are allowed to perform any number of operations (including zero). What is
the minimum total cost to make all elements of the array equal?

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤5⋅105
).

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
).

The sum of 𝑛
 over all test cases does not exceed 5⋅105
.

Output
For each test case, print a single integer — the minimum total cost of
operations to make all elements of the array equal.

Example
InputCopy
3
4
2 4 1 3
3
1 1 1
10
7 5 5 5 10 9 9 4 6 10
OutputCopy
3
0
35
Note
In the first test case, you can perform the operation twice:

choose 𝑖=3
 and make all elements to the left of it equal to it, the cost will be 2⋅1=2
;
choose 𝑖=3
 and make all elements to the right of it equal to it, the cost will be 1⋅1=1
.
The total cost is 2+1=3
.

In the second test case, all elements are already equal, so no operations need
to be performed.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;

    ll prev, left = 0;
    cin >> prev;

    ll cost = prev * (n - 1);

    for (ll p = 1; p < n; p++) {
      ll x;
      cin >> x;

      ll test = x * ((prev == x) ? (left + n - p - 1) : (n - 1));
      left = (prev == x ? left : p);
      cost = min(cost, test);

      prev = x;
    }

    cout << cost << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2111/341295193
