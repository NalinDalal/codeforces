/*A. Median of an Array
time limit per test1 second
memory limit per test256 megabytes
You are given an array 𝑎
 of 𝑛
 integers.

The median of an array 𝑞1,𝑞2,…,𝑞𝑘
 is the number 𝑝⌈𝑘2⌉
, where 𝑝
 is the array 𝑞
 sorted in non-decreasing order. For example, the median of the array
[9,5,1,2,6] is 5 , as in the sorted array [1,2,5,6,9] , the number at index
⌈52⌉=3 is 5 , and the median of the array [9,2,8,3] is 3 , as in the sorted
array [2,3,8,9] , the number at index ⌈42⌉=2 is 3
.

You are allowed to choose an integer 𝑖
 (1≤𝑖≤𝑛
) and increase 𝑎𝑖
 by 1
 in one operation.

Your task is to find the minimum number of operations required to increase the
median of the array.

Note that the array 𝑎
 may not necessarily contain distinct numbers.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. Then follows the description of
the test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤105
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the array 𝑎
.

It is guaranteed that the sum of the values of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the minimum number of operations
required to increase the median of the array.

Example
InputCopy
8
3
2 2 8
4
7 3 3 1
1
1000000000
5
5 5 5 4 5
6
2 1 2 3 1 4
2
1 2
2
1 1
4
5 5 5 5
OutputCopy
1
2
1
3
2
1
2
3
Note
In the first test case, you can apply one operation to the first number and
obtain the array [3,2,8] , the median of this array is 3 , as it is the number
at index ⌈32⌉=2 in the non-decreasing sorted array [2,3,8] . The median of the
original array [2,2,8] is 2 , as it is the number at index ⌈32⌉=2 in the
non-decreasing sorted array [2,2,8] . Thus, the median increased (3>2 ) in just
one operation.

In the fourth test case, you can apply one operation to each of the numbers at
indices 1,2,3 and obtain the array [6,6,6,4,5] , the median of this array is 6
, as it is the number at index ⌈52⌉=3
 in the non-decreasing sorted array [4,5,6,6,6]
. The median of the original array [5,5,5,4,5]
 is 5
, as it is the number at index ⌈52⌉=2
 in the non-decreasing sorted array [4,5,5,5,5]
. Thus, the median increased (6>5
) in three operations. It can be shown that this is the minimum possible number
of operations.

In the fifth test case, you can apply one operation to each of the numbers at
indices 1,3 and obtain the array [3,1,3,3,1,4] , the median of this array is 3
, as it is the number at index ⌈62⌉=3
 in the non-decreasing sorted array [1,1,3,3,3,4]
. The median of the original array [2,1,2,3,1,4]
 is 2
, as it is the number at index ⌈62⌉=3
 in the non-decreasing sorted array [1,1,2,2,3,4]
. Thus, the median increased (3>2
) in two operations. It can be shown that this is the minimum possible number of
operations.



*/

/*copy array q into array p
 * then sort the array p
 * then find the medium of array p
 * choose int i, a[i]++ in 1 opr
 * minimum number of operations required to increase the median of the array.

Only elements at or right of the median position in sorted order affect the
median.

To increase the median, you must increase p[n/2] (and maybe beyond).

Target value target = med + 1 (or more, if given in the problem).

For all indices i >= n/2, make sure p[i] >= target.

Each increment costs p[i] → target.

operation = for(n/2 .. n-1){max(0,target-p[i])}
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    sort(v.begin(), v.end());
    int idx = (n - 1) / 2;

    int cnt = 0;
    for (int i = idx; i < n && v[i] == v[idx]; i++, cnt++)
      ;

    cout << cnt << "\n";
  }
}
