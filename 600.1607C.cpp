/*C. Minimum Extraction
time limit per test1 second
memory limit per test256 megabytes
Yelisey has an array 𝑎
 of 𝑛
 integers.

If 𝑎
 has length strictly greater than 1
, then Yelisei can apply an operation called minimum extraction to it:

First, Yelisei finds the minimal number 𝑚
 in the array. If there are several identical minima, Yelisey can choose any of
them. Then the selected minimal element is removed from the array. After that, 𝑚
 is subtracted from each remaining element.
Thus, after each operation, the length of the array is reduced by 1
.

For example, if 𝑎=[1,6,−4,−2,−4]
, then the minimum element in it is 𝑎3=−4
, which means that after this operation the array will be equal to
𝑎=[1−(−4),6−(−4),−2−(−4),−4−(−4)]=[5,10,2,0]
.

Since Yelisey likes big numbers, he wants the numbers in the array 𝑎
 to be as big as possible.

Formally speaking, he wants to make the minimum of the numbers in array 𝑎
 to be maximal possible (i.e. he want to maximize a minimum). To do this,
Yelisey can apply the minimum extraction operation to the array as many times as
he wants (possibly, zero). Note that the operation cannot be applied to an array
of length 1
.

Help him find what maximal value can the minimal element of the array have after
applying several (possibly, zero) minimum extraction operations to the array.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The next 2𝑡
 lines contain descriptions of the test cases.

In the description of each test case, the first line contains an integer 𝑛
 (1≤𝑛≤2⋅105
) — the original length of the array 𝑎
. The second line of the description lists 𝑛
 space-separated integers 𝑎𝑖
 (−109≤𝑎𝑖≤109
) — elements of the array 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
Print 𝑡
 lines, each of them containing the answer to the corresponding test case. The
answer to the test case is a single integer — the maximal possible minimum in 𝑎
, which can be obtained by several applications of the described operation to
it.

Example
InputCopy
8
1
10
2
0 0
3
-1 2 0
4
2 10 1 7
2
2 3
5
3 2 -4 -2 0
2
-1 1
1
-2
OutputCopy
10
0
2
5
2
2
2
-2
Note
In the first example test case, the original length of the array 𝑛=1
. Therefore minimum extraction cannot be applied to it. Thus, the array remains
unchanged and the answer is 𝑎1=10
.

In the second set of input data, the array will always consist only of zeros.

In the third set, the array will be changing as follows: [−1,2,0]→[3,1]→[2]
. The minimum elements are highlighted with blue
. The maximal one is 2
.

In the fourth set, the array will be modified as [2,10,1,7]→[1,9,6]→[8,5]→[3]
. Similarly, the maximum of the minimum elements is 5
.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::vector<long> a(n);
    for (long p = 0; p < n; p++) {
      std::cin >> a[p];
    }
    std::sort(a.begin(), a.end());
    long res(a[0]);
    for (long p = 1; p < a.size(); p++) {
      long diff = a[p] - a[p - 1];
      res = (res > diff) ? res : diff;
    }

    std::cout << res << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1607/334147637
