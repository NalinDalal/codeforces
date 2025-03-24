/*B. Kevin and Permutation
time limit per test1 second
memory limit per test256 megabytes

Kevin is a master of permutation-related problems. You are taking a walk with
Kevin in Darkwoods, and during your leisure time, he wants to ask you the
following question.

Given two positive integers 𝑛
 and 𝑘
, construct a permutation∗
 𝑝
 of length 𝑛
 to minimize the sum of the minimum values of all subarrays†
 of length 𝑘
. Formally, you need to minimize

∑𝑖=1𝑛−𝑘+1(min𝑗=𝑖𝑖+𝑘−1𝑝𝑗).

∗
A permutation of length 𝑛
 is an array consisting of 𝑛
 distinct integers from 1
 to 𝑛
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (𝑛=3
 but there is 4
 in the array).

†
An array 𝑎
 is a subarray of an array 𝑏
 if 𝑎
 can be obtained from 𝑏
 by the deletion of several (possibly, zero or all) elements from the beginning
and several (possibly, zero or all) elements from the end. Two subarrays are
considered different if the sets of positions of the deleted elements are
different.

Input
Each test consists of multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤103
).

The only line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑘≤𝑛≤105
).

It is guaranteed that the sum of 𝑛
 over all test cases doesn't exceed 105
.

Output
For each test case, output 𝑛
 integers on a single line — the permutation 𝑝
 you constructed.

If there are multiple answers, you can print any of them.

Example
InputCopy
3
4 2
6 1
8 3
OutputCopy
3 1 2 4
5 2 1 6 4 3
4 6 2 8 3 1 5 7
Note
In the first test case, with 𝑘=2
, consider all subarrays of length 2
: the minimum value of 𝑝1,𝑝2
 is 1
, the minimum value of 𝑝2,𝑝3
 is 1
, and the minimum value of 𝑝3,𝑝4
 is 2
. The sum 1+1+2=4
 is the smallest among all possible permutations.

In the second test case, all subarrays of length 1
 have minimum values of 5,2,1,6,4,3
, and the sum 5+2+1+6+4+3=21
 is proven to be the smallest.



*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    int cur = 1;
    for (int p = 1; k * p <= n; p++) {
      v[p * k] = cur++;
    }
    for (int p = 1; p <= n; p++) {
      if (!v[p]) {
        v[p] = cur++;
      }
      cout << v[p] << " ";
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2048/312133426
