/* https://codeforces.com/problemset/problem/1783/A
A. Make it Beautiful
time limit per test3 seconds
memory limit per test512 megabytes
An array 𝑎 is called ugly if it contains at least one element which is equal to
the sum of all elements before it. If the array is not ugly, it is beautiful.

For example:
the array [6,3,9,6] is ugly: the element 9 is equal to 6+3;
the array [5,5,7] is ugly: the element 5 (the second one) is equal to 5;
the array [8,4,10,14] is beautiful: 8≠0, 4≠8, 10≠8+4, 14≠8+4+10, so there is no
element which is equal to the sum of all elements before it.

You are given an array 𝑎 such that 1≤𝑎1≤𝑎2≤⋯≤𝑎𝑛≤100. You have to reorder the
elements of 𝑎 in such a way that the resulting array is beautiful. Note that you
are not allowed to insert new elements or erase existing ones, you can only
change the order of elements of 𝑎. You are allowed to keep the array 𝑎
unchanged, if it is beautiful.

Input
The first line contains one integer 𝑡 (1≤𝑡≤2000) — the number of test cases.

Each test case consists of two lines. The first line contains one integer 𝑛
(2≤𝑛≤50). The second line contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎1≤𝑎2≤⋯≤𝑎𝑛≤100).

Output
For each test case, print the answer as follows:

if it is impossible to reorder the elements of 𝑎 in such a way that it becomes
beautiful, print NO; otherwise, in the first line, print YES. In the second
line, print 𝑛 integers — any beautiful array which can be obtained from 𝑎 by
reordering its elements. If there are multiple such arrays, print any of them.

Example
InputCopy
4
4
3 3 6 6
2
10 10
5
1 2 3 4 5
3
1 4 4
OutputCopy
YES
3 6 3 6
NO
YES
2 4 1 5 3
YES
1 4 4
*/

// ugly logic-> sum(0,i-1)=arr[i]
// reorder to make beautiful

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &a) {
  sort(a.rbegin(), a.rend()); // Sort in descending order
  if (a[0] == a.back()) {
    return 0; // Return 0 to indicate "NO"
  }

  cout << "YES" << endl;
  cout << a.back() << " ";
  for (int i = 0; i < a.size() - 1; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 1; // Return 1 to indicate "YES"
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (solve(a) == 0) {
      cout << "NO" << endl;
    }
  }
  return 0;
}

// sort in descending order
// Check if the largest element equals the smallest; if true, output "NO."
// If they differ, output "YES," print the smallest element first, and the rest
// in descending order. Ensure the smallest element is treated separately to
// maintain the required order.
