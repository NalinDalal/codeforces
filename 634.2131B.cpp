/*B. Alternating Series
time limit per test2 seconds
memory limit per test256 megabytes

You are given an integer 𝑛
. Call an array 𝑎
 of length 𝑛
 good if:

For all 1≤𝑖<𝑛
, 𝑎𝑖⋅𝑎𝑖+1<0
 (i.e., the product of adjacent elements is negative).
For all subarrays∗
 with length at least 2
, the sum of all elements in the subarray is positive†
.
Additionally, we say a good array 𝑎
 of length 𝑛
 is better than another good array 𝑏
 of length 𝑛
 if [|𝑎1|,|𝑎2|,…,|𝑎𝑛|]
 is lexicographically smaller‡
 than [|𝑏1|,|𝑏2|,…,|𝑏𝑛|]
. Note that |𝑧|
 denotes the absolute value of integer 𝑧
.

Output a good array of length 𝑛
 such that it is better than every other good array of length 𝑛
.

∗
An array 𝑐
 is a subarray of an array 𝑑
 if 𝑐
 can be obtained from 𝑑
 by the deletion of several (possibly, zero or all) elements from the beginning
and several (possibly, zero or all) elements from the end.

†
An integer 𝑥
 is positive if 𝑥>0
.

‡
A sequence 𝑎
 is lexicographically smaller than a sequence 𝑏
 if and only if one of the following holds:

𝑎
 is a prefix of 𝑏
, but 𝑎≠𝑏
; or
in the first position where 𝑎
 and 𝑏
 differ, the sequence 𝑎
 has a smaller element than the corresponding element in 𝑏
.
Input
The first line contains an integer 𝑡
 (1≤𝑡≤500
) — the number of test cases.

The single line of each test case contains one integer 𝑛
 (2≤𝑛≤2⋅105
) — the length of your array.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (−109≤𝑎𝑖≤109
), the elements of your array on a new line.

Example
InputCopy
2
2
3
OutputCopy
-1 2
-1 3 -1
Note
In the first test case, because 𝑎1⋅𝑎2=−2<0
 and 𝑎1+𝑎2=1>0
, it satisfies the two constraints. In addition, it can be shown that the
corresponding 𝑏=[1,2] is better than any other good array of length 2
.
*
*/
#include <iostream>
using namespace std;

int main() {
  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    for (long p = 0; p < n; p++) {
      if (p % 2 == 0) {
        cout << -1 << " ";
      } else {
        cout << (p + 1 < n ? 3 : 2) << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/2131/335917903
