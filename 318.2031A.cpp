/* A. Penchick and Modern Monument
time limit per test1 second
memory limit per test256 megabytes
Amidst skyscrapers in the bustling metropolis of Metro Manila, the newest Noiph
mall in the Philippines has just been completed! The construction manager,
Penchick, ordered a state-of-the-art monument to be built with 𝑛 pillars.

The heights of the monument's pillars can be represented as an array ℎ
 of 𝑛
 positive integers, where ℎ𝑖
 represents the height of the 𝑖
-th pillar for all 𝑖
 between 1
 and 𝑛
.

Penchick wants the heights of the pillars to be in non-decreasing order, i.e.
ℎ𝑖≤ℎ𝑖+1 for all 𝑖 between 1 and 𝑛−1 . However, due to confusion, the monument
was built such that the heights of the pillars are in non-increasing order
instead, i.e. ℎ𝑖≥ℎ𝑖+1 for all 𝑖 between 1 and 𝑛−1
.

Luckily, Penchick can modify the monument and do the following operation on the
pillars as many times as necessary:

Modify the height of a pillar to any positive integer. Formally, choose an index
1≤𝑖≤𝑛 and a positive integer 𝑥 . Then, assign ℎ𝑖:=𝑥
.
Help Penchick determine the minimum number of operations needed to make the
heights of the monument's pillars non-decreasing.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤1000
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤50
) — the number of pillars.

The second line of each test case contains 𝑛
 integers ℎ1,ℎ2,…,ℎ𝑛
 (1≤ℎ𝑖≤𝑛
 and ℎ𝑖≥ℎ𝑖+1
) — the height of the pillars.

Please take note that the given array ℎ
 is non-increasing.

Note that there are no constraints on the sum of 𝑛
 over all test cases.

Output
For each test case, output a single integer representing the minimum number of
operations needed to make the heights of the pillars non-decreasing.

Example
InputCopy
3
5
5 4 3 2 1
3
2 2 1
1
1
OutputCopy
4
1
0
Note
In the first test case, the initial heights of pillars are ℎ=[5,4,3,2,1]
.

In the first operation, Penchick changes the height of pillar 1
 to ℎ1:=2
.
In the second operation, he changes the height of pillar 2
 to ℎ2:=2
.
In the third operation, he changes the height of pillar 4
 to ℎ4:=4
.
In the fourth operation, he changes the height of pillar 5
 to ℎ5:=4
.
After the operation, the heights of the pillars are ℎ=[2,2,3,4,4]
, which is non-decreasing. It can be proven that it is not possible for Penchick
to make the heights of the pillars non-decreasing in fewer than 4 operations.

In the second test case, Penchick can make the heights of the pillars
non-decreasing by modifying the height of pillar 3 to ℎ3:=2
.

In the third test case, the heights of pillars are already non-decreasing, so no
operations are required.


*/
#include <iostream>
#include <map>
using namespace std;

int main() {
  long t;
  cin >> t;

  while (t--) {
    long n;
    cin >> n;

    map<long, long> m;
    long mxcnt = 0;

    for (long p = 0; p < n; ++p) {
      long h;
      cin >> h;
      ++m[h];
      mxcnt = (mxcnt > m[h] ? mxcnt : m[h]);
    }

    cout << (n - mxcnt) << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2031/317810956
