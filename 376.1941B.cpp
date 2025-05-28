/*B. Rudolf and 121
time limit per test2 seconds
memory limit per test256 megabytes
Rudolf has an array 𝑎
 of 𝑛
 integers, the elements are numbered from 1
 to 𝑛
.

In one operation, he can choose an index 𝑖
 (2≤𝑖≤𝑛−1
) and assign:

𝑎𝑖−1=𝑎𝑖−1−1
𝑎𝑖=𝑎𝑖−2
𝑎𝑖+1=𝑎𝑖+1−1
Rudolf can apply this operation any number of times. Any index 𝑖
 can be used zero or more times.

Can he make all the elements of the array equal to zero using this operation?

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases in the test.

The first line of each case contains a single integer 𝑛
 (3≤𝑛≤2⋅105
) — the number of elements in the array.

The second line of each case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑗≤109
) — the elements of the array.

It is guaranteed that the sum of the values of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output "YES" if it is possible to make all the elements of
the array zero using the described operations. Otherwise, output "NO".

You can output each letter in any case (lowercase or uppercase). For example,
the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive
answer.

Example
InputCopy
7
5
1 3 5 5 2
5
2 4 4 5 1
5
0 1 3 3 1
6
5 6 0 2 3 0
4
1 2 7 2
3
7 1 0
4
1 1 1 1
OutputCopy
YES
NO
YES
NO
NO
NO
NO
Note
In the first example, the original array is [1,3,5,5,2]
, to make all its elements zero, Rudolf can act as follows:

apply the operation at 𝑖=4
 and get the array [1,3,4,3,1]
;
apply the operation at 𝑖=3
 and get the array [1,2,2,2,1]
;
apply the operation at 𝑖=2
 and get the array [0,0,1,2,1]
;
apply the operation at 𝑖=4
 and get the array [0,0,0,0,0]. */

#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    bool valid = true;
    for (long p = 0; valid && p + 2 < n; p++) {
      if (a[p] < 0) {
        valid = false;
      }
      a[p + 1] -= 2 * a[p];
      a[p + 2] -= a[p];
    }

    valid = valid && !a[n - 2] && !a[n - 1];
    cout << (valid ? "YES" : "NO") << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1941/321831835
