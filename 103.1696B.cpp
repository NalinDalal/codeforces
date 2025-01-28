/* https://codeforces.com/problemset/problem/1696/B
B. NIT Destroys the Universe
time limit per test2 seconds
memory limit per test512 megabytes
For a collection of integers 𝑆, define mex(𝑆) as the smallest non-negative
integer that does not appear in 𝑆.

NIT, the cleaver, decides to destroy the universe. He is not so powerful as
Thanos, so he can only destroy the universe by snapping his fingers several
times.

The universe can be represented as a 1-indexed array 𝑎 of length 𝑛. When NIT
snaps his fingers, he does the following operation on the array:

He selects positive integers 𝑙 and 𝑟 such that 1≤𝑙≤𝑟≤𝑛. Let
𝑤=mex({𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟}). Then, for all 𝑙≤𝑖≤𝑟, set 𝑎𝑖 to 𝑤. We say the universe is
destroyed if and only if for all 1≤𝑖≤𝑛, 𝑎𝑖=0 holds.

Find the minimum number of times NIT needs to snap his fingers to destroy the
universe. That is, find the minimum number of operations NIT needs to perform to
make all elements in the array equal to 0.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104). Description of the test cases follows.

The first line of each test case contains one integer 𝑛 (1≤𝑛≤105).

The second line of each test case contains 𝑛 integers 𝑎1, 𝑎2, …, 𝑎𝑛 (0≤𝑎𝑖≤109).

It is guaranteed that the sum of 𝑛 over all test cases does not exceed 2⋅105.

Output
For each test case, print one integer — the answer to the problem.

Example
InputCopy
4
4
0 0 0 0
5
0 1 2 3 4
7
0 2 3 0 1 2 0
1
1000000000
OutputCopy
0
1
2
1
Note
In the first test case, we do 0 operations and all elements in the array are
already equal to 0.

In the second test case, one optimal way is doing the operation with 𝑙=2, 𝑟=5.

In the third test case, one optimal way is doing the operation twice,
respectively with 𝑙=4, 𝑟=4 and 𝑙=2, 𝑟=6.

In the fourth test case, one optimal way is doing the operation with 𝑙=1, 𝑟=1.
*/

#include <algorithm> // For std::min
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    // return minimum of number of operations to make all element equal to 0
    // Count the number of segments of non-zero numbers
    int ans = 0;
    bool inSegment = false;
    for (int i = 0; i < n; i++) {
      if (v[i] != 0) {
        if (!inSegment) {
          ans++;
          inSegment = true;
        }
      } else {
        inSegment = false;
      }
    }
    cout << min(ans, 2) << endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1696/303373945
