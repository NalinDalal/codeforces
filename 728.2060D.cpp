/*D. Subtract Min Sort
time limit per test2 seconds
memory limit per test256 megabytes
You are given a sequence 𝑎
 consisting of 𝑛
 positive integers.

You can perform the following operation any number of times.

Select an index 𝑖
 (1≤𝑖<𝑛
), and subtract min(𝑎𝑖,𝑎𝑖+1)
 from both 𝑎𝑖
 and 𝑎𝑖+1
.
Determine if it is possible to make the sequence non-decreasing by using the
operation any number of times.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤2⋅105
).

The second line of each test case contains 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
If it is possible to make the sequence non-decreasing, print "YES" on a new
line. Otherwise, print "NO" on a new line.

You can output the answer in any case. For example, the strings "yEs", "yes",
and "Yes" will also be recognized as positive responses.

Example
InputCopy
5
5
1 2 3 4 5
4
4 3 2 1
4
4 5 2 3
8
4 5 4 5 4 5 4 5
9
9 9 8 2 4 4 3 5 3
OutputCopy
YES
NO
YES
YES
NO
Note
In the first test case, the array is already sorted.

In the second test case, we can show that it is impossible.

In the third test case, after performing an operation on 𝑖=1
, the array becomes [0,1,2,3]
, which is now in nondecreasing order.
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
    vector<long> v(n);
    for (long p = 0; p < n; p++) {
      cin >> v[p];
    }

    for (long p = 1; p < n; p++) {
      long x = (v[p - 1] < v[p] ? v[p - 1] : v[p]);
      v[p - 1] -= x;
      v[p] -= x;
    }

    bool res = true;
    for (long p = 1; res && p < n; p++) {
      if (v[p - 1] > v[p]) {
        res = false;
      }
    }

    cout << (res ? "YES\n" : "NO\n");
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2060/341018015
