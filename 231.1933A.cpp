/*A. Turtle Puzzle: Rearrange and Negate
time limit per test2 seconds
memory limit per test256 megabytes
You are given an array 𝑎
 of 𝑛
 integers. You must perform the following two operations on the array (the
first, then the second):

Arbitrarily rearrange the elements of the array or leave the order of its
elements unchanged. Choose at most one contiguous segment of elements and
replace the signs of all elements in this segment with their opposites.
Formally, you can choose a pair of indices 𝑙,𝑟 such that 1≤𝑙≤𝑟≤𝑛 and assign
𝑎𝑖=−𝑎𝑖 for all 𝑙≤𝑖≤𝑟 (negate elements). Note that you may choose not to select a
pair of indices and leave all the signs of the elements unchanged. What is the
maximum sum of the array elements after performing these two operations (the
first, then the second)?

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases. The descriptions of the test cases follow.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤50
) — the number of elements in array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (−100≤𝑎𝑖≤100
) — elements of the array.

Output
For each test case, output the maximum sum of the array elements after
sequentially performing the two given operations.

Example
InputCopy
8
3
-2 3 -3
1
0
2
0 1
1
-99
4
10 -2 -3 7
5
-1 -2 -3 -4 -5
6
-41 22 -69 73 -15 -50
12
1 2 3 4 5 6 7 8 9 10 11 12
OutputCopy
8
0
1
99
22
15
270
78
Note
In the first test case, you can first rearrange the array to get [3,−2,−3]
 (operation 1), then choose 𝑙=2,𝑟=3
 and get the sum 3+−((−2)+(−3))=8
 (operation 2).

In the second test case, you can do nothing in both operations and get the sum 0
.

In the third test case, you can do nothing in both operations and get the sum
0+1=1
.

In the fourth test case, you can first leave the order unchanged (operation 1),
then choose 𝑙=1,𝑟=1 and get the sum −(−99)=99 (operation 2).

In the fifth test case, you can first leave the order unchanged (operation 1),
then choose 𝑙=2,𝑟=3 and get the sum 10+−((−2)+(−3))+7=22 (operation 2).

In the sixth test case, you can first leave the order unchanged (operation 1),
then choose 𝑙=1,𝑟=5 and get the sum −((−1)+(−2)+(−3)+(−4)+(−5))=15 (operation
2).


*/

#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
      int x;
      cin >> x;
      ans += (x > 0 ? x : -x);
    }
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1933/310856952
