/*D. A-B-C Sort
time limit per test2 seconds
memory limit per test256 megabytes
You are given three arrays 𝑎
, 𝑏
 and 𝑐
. Initially, array 𝑎
 consists of 𝑛
 elements, arrays 𝑏
 and 𝑐
 are empty.

You are performing the following algorithm that consists of two steps:

Step 1
: while 𝑎
 is not empty, you take the last element from 𝑎
 and move it in the middle of array 𝑏
. If 𝑏
 currently has odd length, you can choose: place the element from 𝑎
 to the left or to the right of the middle element of 𝑏
. As a result, 𝑎
 becomes empty and 𝑏
 consists of 𝑛
 elements.
Step 2
: while 𝑏
 is not empty, you take the middle element from 𝑏
 and move it to the end of array 𝑐
. If 𝑏
 currently has even length, you can choose which of two middle elements to take.
As a result, 𝑏 becomes empty and 𝑐 now consists of 𝑛 elements. Refer to the Note
section for examples. Can you make array 𝑐 sorted in non-decreasing order?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤2⋅104
) — the number of test cases. Next 𝑡
 cases follow.

The first line of each test case contains the single integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤106
) — the array 𝑎
 itself.

It's guaranteed that the sum of 𝑛
 doesn't exceed 2⋅105
.

Output
For each test, print YES (case-insensitive), if you can make array 𝑐
 sorted in non-decreasing order. Otherwise, print NO (case-insensitive).

Example
InputCopy
3
4
3 1 5 3
3
3 2 1
1
7331
OutputCopy
YES
NO
YES
Note
In the first test case, we can do the following for 𝑎=[3,1,5,3]
:

Step 1
:

𝑎
[3,1,5,3]
⇒
[3,1,5]
⇒
[3,1]
⇒
[3]
⇒
[]
𝑏
[]
[3⎯⎯]
[3,5⎯⎯]
[3,1⎯⎯,5]
[3,3⎯⎯,1,5]
Step 2
:

𝑏
[3,3,1⎯⎯,5]
⇒
[3,3⎯⎯,5]
⇒
[3⎯⎯,5]
⇒
[5⎯⎯]
⇒
[]
𝑐
[]
[1]
[1,3]
[1,3,3]
[1,3,3,5]
As a result, array 𝑐=[1,3,3,5]
 and it's sorted.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    vector<long> a(n);
    for (long p = 0; p < n; p++) {
      cin >> a[p];
    }

    for (long p = n - 2; p >= 0; p -= 2) {
      if (a[p + 1] < a[p]) {
        swap(a[p], a[p + 1]);
      }
    }

    bool sorted = true;
    for (long p = 1; p < n && sorted; p++) {
      if (a[p - 1] > a[p]) {
        sorted = false;
      }
    }

    cout << (sorted ? "YES" : "NO") << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1674/345139667
