/*C. Sakurako's Field Trip
time limit per test2 seconds
memory limit per test256 megabytes
Even in university, students need to relax. That is why Sakurakos teacher
decided to go on a field trip. It is known that all of the students will be
walking in one line. The student with index 𝑖 has some topic of interest which
is described as 𝑎𝑖 . As a teacher, you want to minimise the disturbance of the
line of students.

The disturbance of the line is defined as the number of neighbouring people with
the same topic of interest. In other words, disturbance is the number of indices
𝑗 (1≤𝑗<𝑛 ) such that 𝑎𝑗=𝑎𝑗+1
.

In order to do this, you can choose index 𝑖
 (1≤𝑖≤𝑛
) and swap students at positions 𝑖
 and 𝑛−𝑖+1
. You can perform any number of swaps.

Your task is to determine the minimal amount of disturbance that you can achieve
by doing the operation described above any number of times.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case is described by two lines.

The first line contains one integer 𝑛
 (2≤𝑛≤105
) — the length of the line of students.
The second line contains 𝑛
 integers 𝑎𝑖
 (1≤𝑎𝑖≤𝑛
) — the topics of interest of students in line.
It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output the minimal possible disturbance of the line that you
can achieve.

Example
InputCopy
9
5
1 1 1 2 3
6
2 1 2 2 1 1
4
1 2 1 1
6
2 1 1 2 2 4
4
2 1 2 3
6
1 2 2 1 2 1
5
4 5 5 1 5
7
1 4 3 5 1 1 3
7
3 1 3 2 2 3 3
OutputCopy
1
2
1
0
0
1
1
0
2
Note
In the first example, it is necessary to apply the operation to 𝑖=2
, thus the array will become [1,2,1,1,3]
, with the bold elements indicating those that have swapped places. The
disturbance of this array is equal to 1
.

In the fourth example, it is sufficient to apply the operation to 𝑖=3
, thus the array will become [2,1,2,1,2,4]
. The disturbance of this array is equal to 0
.

In the eighth example, it is sufficient to apply the operation to 𝑖=3
, thus the array will become [1,4,1,5,3,1,3]
. The disturbance of this array is equal to 0
.
*/

#include <bits/stdc++.h>
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
    for (long i = 0; i < n; i++) {
      cin >> v[i];
    }

    for (long p = 1; p < n - 1 - p; p++) {
      if (v[p] == v[p - 1] || v[n - 1 - p] == v[n - p]) {
        long x = v[p];
        v[p] = v[n - 1 - p];
        v[n - 1 - p] = x;
      }
    }

    long cnt = 0;
    for (long p = 1; p < n; p++) {
      cnt += (v[p] == v[p - 1]);
    }

    cout << cnt << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2033/343076084
