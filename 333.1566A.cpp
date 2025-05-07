/* A. Median Maximization
time limit per test1 second
memory limit per test256 megabytes
You are given two positive integers 𝑛
 and 𝑠
. Find the maximum possible median of an array of 𝑛
 non-negative integers (not necessarily distinct), such that the sum of its
elements is equal to 𝑠
.

A median of an array of integers of length 𝑚
 is the number standing on the ⌈𝑚2⌉
-th (rounding up) position in the non-decreasing ordering of its elements.
Positions are numbered starting from 1 . For example, a median of the array
[20,40,20,50,50,30] is the ⌈𝑚2⌉ -th element of [20,20,30,40,50,50] , so it is 30
. There exist other definitions of the median, but in this problem we use the
described definition.

Input
The input consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. Description of the test cases
follows.

Each test case contains a single line with two integers 𝑛
 and 𝑠
 (1≤𝑛,𝑠≤109
) — the length of the array and the required sum of the elements.

Output
For each test case print a single integer — the maximum possible median.

Example
InputCopy
8
1 5
2 5
3 5
2 1
7 17
4 14
1 1000000000
1000000000 1
OutputCopy
5
2
2
0
4
4
1000000000
0
Note
Possible arrays for the first three test cases (in each array the median is
underlined):

In the first test case [5⎯⎯]
In the second test case [2⎯⎯,3]
In the third test case [1,2⎯⎯,2]

*/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;

    cout << s / (n - (n - 1) / 2) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1566/318687521
