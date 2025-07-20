/*B. Array merging
time limit per test1 second
memory limit per test256 megabytes
You are given two arrays 𝑎
 and 𝑏
 both of length 𝑛
.

You will merge†
 these arrays forming another array 𝑐
 of length 2⋅𝑛
. You have to find the maximum length of a subarray consisting of equal values
across all arrays 𝑐 that could be obtained.

†
 A merge of two arrays results in an array 𝑐
 composed by successively taking the first element of either array (as long as
that array is nonempty) and removing it. After this step, the element is
appended to the back of 𝑐 . We repeat this operation as long as we can (i.e. at
least one array is nonempty).

Input
Each test contains multiple test cases. The first line of input contains a
single integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of test
cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of the array 𝑎
 and 𝑏
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤2⋅𝑛
) — the elements of array 𝑎
.

The third line of each test case contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤2⋅𝑛
) — the elements of array 𝑏
.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output the maximum length of a subarray consisting of equal
values across all merges.

Example
InputCopy
4
1
2
2
3
1 2 3
4 5 6
2
1 2
2 1
5
1 2 2 2 2
2 1 1 1 1
OutputCopy
2
1
2
5
Note
In the first test case, we can only make 𝑐=[2,2]
, thus the answer is 2
.

In the second test case, since all values are distinct, the answer must be 1
.

In the third test case, the arrays 𝑐
 we can make are [1,2,1,2]
, [1,2,2,1]
, [2,1,1,2]
, [2,1,2,1]
. We can see that the answer is 2
 when we choose 𝑐=[1,2,2,1]
.
*/

#include <iostream>
#include <map>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;

  while (t--) {
    long n;
    cin >> n;

    map<long, long> a, b;

    // Process first sequence
    long prev = -1, cur = 0;
    for (long p = 0; p < n; p++) {
      long x;
      cin >> x;
      if (x != prev) {
        if (prev > 0 && (!a.count(prev) || a[prev] < cur)) {
          a[prev] = cur;
        }
        cur = 0;
      }
      ++cur;
      prev = x;
    }
    if (!a.count(prev) || a[prev] < cur) {
      a[prev] = cur;
    }

    // Process second sequence
    prev = -1, cur = 0;
    for (long p = 0; p < n; p++) {
      long x;
      cin >> x;
      if (x != prev) {
        if (prev > 0 && (!b.count(prev) || b[prev] < cur)) {
          b[prev] = cur;
        }
        cur = 0;
      }
      ++cur;
      prev = x;
    }
    if (!b.count(prev) || b[prev] < cur) {
      b[prev] = cur;
    }

    // Calculate max sum of max-run-lengths of shared keys
    long mx = 0;

    for (const auto &[key, val] : a) {
      long total = val;
      if (key > 0 && b.count(key)) {
        total += b[key];
      }
      mx = max(mx, total);
    }

    for (const auto &[key, val] : b) {
      long total = val;
      if (key > 0 && a.count(key)) {
        total += a[key];
      }
      mx = max(mx, total);
    }

    cout << mx << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1831/329954374
