/*B. Informatics in MAC
time limit per test1 second
memory limit per test256 megabytes
In the Master's Assistance Center, Nyam-Nyam was given a homework assignment in
informatics.

There is an array 𝑎
 of length 𝑛
, and you want to divide it into 𝑘>1
 subsegments†
 in such a way that the MEX‡
 on each subsegment is equal to the same integer.

Help Nyam-Nyam find any suitable division, or determine that it does not exist.

†
A division of an array into 𝑘
 subsegments is defined as 𝑘
 pairs of integers (𝑙1,𝑟1),(𝑙2,𝑟2),…,(𝑙𝑘,𝑟𝑘)
 such that 𝑙𝑖≤𝑟𝑖
 and for each 1≤𝑗≤𝑘−1
, 𝑙𝑗+1=𝑟𝑗+1
, and also 𝑙1=1
 and 𝑟𝑘=𝑛
. These pairs represent the subsegments themselves.

‡MEX
 of an array is the smallest non-negative integer that does not belong to the
array.

For example:

MEX
 of the array [2,2,1]
 is 0
, because 0
 does not belong to the array.
MEX
 of the array [3,1,0,1]
 is 2
, because 0
 and 1
 belong to the array, but 2
 does not.
MEX
 of the array [0,3,1,2]
 is 4
, because 0
, 1
, 2
, and 3
 belong to the array, but 4
 does not.
Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤105
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖<𝑛
) — the elements of the array 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output a single integer −1
 if a suitable division does not exist.

Otherwise, on the first line, output an integer 𝑘
 (2≤𝑘≤𝑛
) — the number of subsegments in the division.

Then output 𝑘
 lines — the division into subsegments. The 𝑖
-th line should contain two integers 𝑙𝑖
 and 𝑟𝑖
 (1≤𝑙𝑖≤𝑟𝑖≤𝑛
) — the boundaries of the 𝑖
-th subsegment.

The following conditions must be satisfied:

For all 1≤𝑗≤𝑘−1
, 𝑙𝑗+1=𝑟𝑗+1
;
𝑙1=1
, 𝑟𝑘=𝑛
.
If there are multiple possible solutions, output any of them.

Example
InputCopy
5
2
0 0
5
0 1 2 3 4
8
0 1 7 1 0 1 0 3
3
2 2 2
4
0 1 2 0
OutputCopy
2
1 1
2 2
-1
3
1 3
4 5
6 8
3
1 1
2 2
3 3
-1
Note
In the first test case, the array 𝑎
 can be divided into 2
 subsegments with boundaries [1,1]
 and [2,2]
:

MEX
 of the first subsegment [0]
 is 1
, as 0
 belongs to the subsegment, but 1
 does not.
MEX
 of the second subsegment [0]
 is 1
, as 0
 belongs to the subsegment, but 1
 does not.
In the second test case, it can be proven that the required division does not
exist.

In the third test case, the array 𝑎
 can be divided into 3
 subsegments with boundaries [1,3]
, [4,5]
, [6,8]
:

MEX
 of the first subsegment [0,1,7]
 is 2
, as 0
 and 1
 belong to the subsegment, but 2
 does not.
MEX
 of the second subsegment [1,0]
 is 2
, as 0
 and 1
 belong to the subsegment, but 2
 does not.
MEX
 of the third subsegment [1,0,3]
 is 2
, as 0
 and 1
 belong to the subsegment, but 2
 does not.
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
    map<long, long> first, last;
    for (long p = 1; p <= n; p++) {
      long x;
      cin >> x;
      if (!first.count(x))
        first[x] = p;
      last[x] = p;
    }

    bool possible = true;
    long left = 1, right = n;
    for (int p = 0; p < n; p++) {
      if (!first.count(p))
        break;
      else if (first[p] == last[p]) {
        possible = false;
        break;
      }
      left = (left > first[p]) ? left : first[p];
      right = (right < last[p]) ? right : last[p];
      if (left > right)
        possible = false;
    }

    if (possible) {
      cout << "2\n" << "1 " << left << "\n" << left + 1 << " " << n << endl;
    } else {
      cout << "-1" << endl;
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1935/330072735
