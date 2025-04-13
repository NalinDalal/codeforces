/* B. CopyCopyCopyCopyCopy
time limit per test1 second
memory limit per test256 megabytes
Ehab has an array 𝑎
 of length 𝑛
. He has just enough free time to make a new array consisting of 𝑛
 copies of the old array, written back-to-back. What will be the length of the
new array's longest increasing subsequence?

A sequence 𝑎
 is a subsequence of an array 𝑏
 if 𝑎
 can be obtained from 𝑏
 by deletion of several (possibly, zero or all) elements. The longest increasing
subsequence of an array is the longest subsequence such that its elements are
ordered in strictly increasing order.

Input
The first line contains an integer 𝑡
 — the number of test cases you need to solve. The description of the test cases
follows.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤105
) — the number of elements in the array 𝑎
.

The second line contains 𝑛
 space-separated integers 𝑎1
, 𝑎2
, …
, 𝑎𝑛
 (1≤𝑎𝑖≤109
) — the elements of the array 𝑎
.

The sum of 𝑛
 across the test cases doesn't exceed 105
.

Output
For each testcase, output the length of the longest increasing subsequence of 𝑎
 if you concatenate it to itself 𝑛
 times.

Example
InputCopy
2
3
3 2 1
6
3 1 4 1 5 9
OutputCopy
3
5
Note
In the first sample, the new array is [3,2,1,3,2,1,3,2,1]
. The longest increasing subsequence is marked in bold.

In the second sample, the longest increasing subsequence will be [1,3,4,5,9]
.


*/
#include <iostream>
#include <set>
using std::cin, std::cout, std::endl;
int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    std::set<long> s;
    for (long p = 0; p < n; p++) {
      long x;
      cin >> x;

      s.insert(x);
    }
    cout << s.size() << endl;
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1325/315297502
