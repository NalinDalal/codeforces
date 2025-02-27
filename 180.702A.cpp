/* A. Maximum Increase
time limit per test1 second
memory limit per test256 megabytes
You are given array consisting of n integers. Your task is to find the maximum
length of an increasing subarray of the given array.

A subarray is the sequence of consecutive elements of the array. Subarray is
called increasing if each element of this subarray strictly greater than
previous.

Input
The first line contains single positive integer n (1 ≤ n ≤ 105) — the number of
integers.

The second line contains n positive integers a1, a2, ..., an (1 ≤ ai ≤ 109).

Output
Print the maximum length of an increasing subarray of the given array.

Examples
InputCopy
5
1 7 2 11 15
OutputCopy
3
InputCopy
6
100 100 100 100 100 100
OutputCopy
1
InputCopy
3
1 2 3
OutputCopy
3

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  // return maxLength of increasing subarray
  // do it like this:
  // int count=0
  // 1. iterate over the array
  // if arr[i]<arr[i+1] count++
  // else do it like
  int maxLength = 1;     // Minimum length of increasing subarray is 1
  int currentLength = 1; // Length of the current increasing subarray

  for (int i = 0; i < n - 1; i++) {
    if (v[i] < v[i + 1]) {
      currentLength++;
    } else {
      maxLength = max(maxLength, currentLength);
      currentLength = 1; // Reset currentLength for new subarray
    }
  }

  maxLength = max(maxLength, currentLength); // Final check after loop ends

  cout << maxLength << endl;
  return 0;
}
// sub: https://codeforces.com/problemset/submission/702/308162288
