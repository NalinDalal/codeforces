/* https://codeforces.com/problemset/problem/1857/A

A. Array Coloring

You are given an array consisting of 𝑛 integers. Your task is to determine
whether it is possible to color all its elements in two colors in such a way
that the sums of the elements of both colors have the same parity and each color
has at least one element colored.

For example, if the array is [1,2,4,3,2,3,5,4], we can color it as follows:
[1,2,4,3,2,3,5,4], where the sum of the blue elements is 6 and the sum of the
red elements is 18

Input
The first line contains an integer 𝑡 (1≤𝑡≤1000) — the number of test cases.

Each test case begins with a line containing an integer 𝑛 (2≤𝑛≤50) — the length
of the array 𝑎.

The next line contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤50) — the elements of the
array 𝑎.

Output
For each test case, output "YES" (without quotes) if it is possible to color the
array in two colors in such a way that the sums of the elements of both colors
have the same parity and each color has at least one element colored, and "NO"
otherwise.

You can output "Yes" and "No" in any case (for example, the strings "yES",
"yes", and "Yes" will be recognized as correct answers).

Example
InputCopy
7
8
1 2 4 3 2 3 5 4
2
4 7
3
3 9 8
2
1 7
5
5 4 3 2 1
4
4 3 4 5
2
50 48
OutputCopy
YES
NO
YES
YES
NO
YES
YES
Note
The first sample is described in the statement.

In the second sample, there are only two colorings [4,7] and [4,7] , but in both
cases the parity of sums is different.

In the third sample, you can color [3,9,8] and 12 and 8 are both even.


*/

#include <bits/stdc++.h>

using namespace std;
// Calculate the total sum of the array.
// If the sum is odd, print "NO". Otherwise, print "YES"
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    // same parity of both color sums
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
    }
    // Check parity of the sum
    if (sum % 2 == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1857/300553933
