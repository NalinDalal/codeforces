/*A. Kevin and Arithmetic
time limit per test1 second
memory limit per test256 megabytes
To train young Kevin's arithmetic skills, his mother devised the following
problem.

Given 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 and a sum 𝑠
 initialized to 0
, Kevin performs the following operation for 𝑖=1,2,…,𝑛
 in order:

Add 𝑎𝑖
 to 𝑠
. If the resulting 𝑠
 is even, Kevin earns a point and repeatedly divides 𝑠
 by 2
 until it becomes odd.
Note that Kevin can earn at most one point per operation, regardless of how many
divisions he does.

Since these divisions are considered more beneficial for Kevin's development,
his mother wants to rearrange 𝑎 so that the number of Kevin's total points is
maximized. Determine the maximum number of points.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤100
) — the number of integers.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
).

Output
For each test case, output one integer — the maximum number of points.

Example
InputCopy
5
1
1
2
1 2
3
2 4 6
4
1000000000 999999999 999999998 999999997
10
3 1 4 1 5 9 2 6 5 3
OutputCopy
0
2
1
3
8
Note
In the first test case, the only arrangement of 𝑎
 is [1]
. 𝑠
 becomes 1
. Kevin earns no points.

In the second test case, the only possible arrangement of 𝑎
 is [2,1]
. 𝑠
 becomes 1
 and 1
 successively. Kevin earns points in both operations.

In the third test case, one possible arrangement of 𝑎
 is [2,4,6]
. 𝑠
 becomes 1
, 5
, and 11
 successively. Kevin earns a point in the first operation.
*/
/*#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n);
    int point = 0;

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      // Add a[i] to sum. If the resulting sum is even, Kevin earns a point
      // and repeatedly divides sum by 2 until it becomes odd.

      sum += a[i];
      if (sum % 2 == 0) {
        point++;
        // repeatedly divide sum by 2 until it becomes odd
        while (sum % 2 == 0)
          sum /= 2;
      }
    }
    // cout max points
    cout << point << endl;
  }
  return 0;
}*/
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int odds = 0, evens = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      x %= 2;
      odds += x;
      evens += (1 - x);
    }

    cout << odds + (evens ? 1 : -1) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2061/315786341
