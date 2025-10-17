/*B. Stalin Sort
time limit per test1 second
memory limit per test256 megabytes
Stalin Sort is a humorous sorting algorithm designed to eliminate elements which
are out of place instead of bothering to sort them properly, lending itself to
an (𝑛) time complexity.

It goes as follows: starting from the second element in the array, if it is
strictly smaller than the previous element (ignoring those which have already
been deleted), then delete it. Continue iterating through the array until it is
sorted in non-decreasing order. For example, the array [1,4,2,3,6,5,5,7,7]
 becomes [1,4,6,7,7]
 after a Stalin Sort.

We define an array as vulnerable if you can sort it in non-increasing order by
repeatedly applying a Stalin Sort to any of its subarrays∗ , as many times as is
needed.

Given an array 𝑎
 of 𝑛
 integers, determine the minimum number of integers which must be removed from
the array to make it vulnerable.

∗
An array 𝑎
 is a subarray of an array 𝑏
 if 𝑎
 can be obtained from 𝑏
 by the deletion of several (possibly, zero or all) elements from the beginning
and several (possibly, zero or all) elements from the end.

Input
Each test consists of several test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤500 ) — the number of test cases. This is followed by
descriptions of the test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2000
) — the size of the array.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2000
.

Output
For each test case, output a single integer — the minimum number of integers
which must be removed from the array to make it vulnerable.

Example
InputCopy
6
7
3 6 4 9 2 5 2
5
5 4 4 2 2
8
2 2 4 4 6 6 10 10
1
1000
9
6 8 9 10 12 9 7 5 4
7
300000000 600000000 400000000 900000000 200000000 400000000 200000000
OutputCopy
2
0
6
0
4
2
Note
In the first test case, the optimal answer is to remove the numbers 3
 and 9
. Then we are left with 𝑎=[6,4,2,5,2]
. To show this array is vulnerable, we can first apply a Stalin Sort on the
subarray [4,2,5] to get 𝑎=[6,4,5,2] and then apply a Stalin Sort on the subarray
[6,4,5] to get 𝑎=[6,2] , which is non-increasing.

In the second test case, the array is already non-increasing, so we don't have
to remove any integers.



*/

// stalin sort
// if i is smaller than i-1, delete i
// move ahead
// given array a of n integers, find min no of int to delete to make it
// vulnerable
//
#include <bits/stdc++.h>
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

    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (a[j] >= a[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    int lnis = *max_element(dp.begin(), dp.end());
    cout << n - lnis << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2027/344182946
