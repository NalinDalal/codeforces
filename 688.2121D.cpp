/*D. 1709
time limit per test2 seconds
memory limit per test256 megabytes
You are given two arrays of integers 𝑎1,𝑎2,…,𝑎𝑛
 and 𝑏1,𝑏2,…,𝑏𝑛
. It is guaranteed that each integer from 1
 to 2⋅𝑛
 appears in exactly one of the arrays.

You need to perform a certain number of operations (possibly zero) so that both
of the following conditions are satisfied:

For each 1≤𝑖<𝑛
, it holds that 𝑎𝑖<𝑎𝑖+1
 and 𝑏𝑖<𝑏𝑖+1
.
For each 1≤𝑖≤𝑛
, it holds that 𝑎𝑖<𝑏𝑖
.
During each operation, you can perform exactly one of the following three
actions:

Choose an index 1≤𝑖<𝑛
 and swap the values 𝑎𝑖
 and 𝑎𝑖+1
.
Choose an index 1≤𝑖<𝑛
 and swap the values 𝑏𝑖
 and 𝑏𝑖+1
.
Choose an index 1≤𝑖≤𝑛
 and swap the values 𝑎𝑖
 and 𝑏𝑖
.
You do not need to minimize the number of operations, but the total number must
not exceed 1709 . Find any sequence of operations that satisfies both
conditions.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤100 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤40
) — the length of the arrays 𝑎
 and 𝑏
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤2⋅𝑛
).

The third line of each test case contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤2⋅𝑛
).

It is guaranteed that each integer from 1
 to 2⋅𝑛
 appears either in array 𝑎
 or in array 𝑏
.

Output
For each test case, output the sequence of operations.

In the first line for each test case, output the number of operations 𝑘
. Note that 0≤𝑘≤1709
.

In the following 𝑘
 lines for each test case, output the operations themselves:

If you want to swap the values 𝑎𝑖
 and 𝑎𝑖+1
, output two integers 1
 and 𝑖
. Note that 1≤𝑖<𝑛
.
If you want to swap the values 𝑏𝑖
 and 𝑏𝑖+1
, output two integers 2
 and 𝑖
. Note that 1≤𝑖<𝑛
.
If you want to swap the values 𝑎𝑖
 and 𝑏𝑖
, output two integers 3
 and 𝑖
. Note that 1≤𝑖≤𝑛
.
It can be shown that under the given constraints, a solution always exists.

Example
InputCopy
6
1
1
2
1
2
1
2
1 3
4 2
2
1 4
3 2
3
6 5 4
3 2 1
3
5 3 4
2 6 1
OutputCopy
0
1
3 1
1
2 1
1
3 2
9
3 1
3 2
3 3
1 1
2 1
2 2
1 2
1 1
2 1
6
2 2
1 1
1 2
2 1
3 1
3 2
Note
In the first test case, 𝑎1<𝑏1
, so no operations need to be applied.

In the second test case, 𝑎1>𝑏1
. After applying the operation, these values will be swapped.

In the third test case, after applying the operation, 𝑎=[1,3]
 and 𝑏=[2,4]
.

In the fourth test case, after applying the operation, 𝑎=[1,2]
 and 𝑏=[3,4]
*/

/*given array a,b of sie n
 elements appear from 1 to 2n

 2 condition: a[i]<a[i+1], b[i]<b[i+1], a[i]<b[i]

 3 actions available: swap(a[i],a[i+1]), swap(b[i],b[i+1]), swap(a[i],b[i])
 opr++

 cout opr,
 if swap(a[i],a[i+1]) cout<<1<<i
 else if swap(b[i],b[i+1]) cout<<2<<i
 else if(swap(a[i],b[i])) cout<<3<<i

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
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];

    vector<pair<int, int>> ops; // {type, index}

    // Sort a with adjacent swaps
    for (long p = 0; p < n; p++) {
      for (long q = 0; q < n - 1; q++) {
        if (a[q] <= a[q + 1])
          continue;
        swap(a[q], a[q + 1]);
        ops.push_back({1, q + 1});
      }
    }

    // Sort b with adjacent swaps
    for (long p = 0; p < n; p++) {
      for (long q = 0; q < n - 1; q++) {
        if (b[q] <= b[q + 1])
          continue;
        swap(b[q], b[q + 1]);
        ops.push_back({2, q + 1});
      }
    }

    // Fix cross-condition a[i] < b[i]
    for (long p = 0; p < n; p++) {
      if (a[p] <= b[p])
        continue;
      swap(a[p], b[p]);
      ops.push_back({3, p + 1});
    }

    cout << ops.size() << "\n";
    for (auto [type, idx] : ops) {
      cout << type << " " << idx << "\n";
    }
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/2121/338661140
