/* https://codeforces.com/problemset/problem/1829/B
*
* B. Blank Space
time limit per test1 second
memory limit per test256 megabytes
You are given a binary array 𝑎 of 𝑛 elements, a binary array is an array
consisting only of 0s and 1s.

A blank space is a segment of consecutive elements consisting of only 0s.

Your task is to find the length of the longest blank space.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤1000) — the number of test
cases.

The first line of each test case contains a single integer 𝑛 (1≤𝑛≤100) — the
length of the array.

The second line of each test case contains 𝑛 space-separated integers 𝑎𝑖
(0≤𝑎𝑖≤1) — the elements of the array.

Output
For each test case, output a single integer — the length of the longest blank
space.

Example
InputCopy
5
5
1 0 0 1 0
4
0 1 1 1
1
0
3
1 1 1
9
1 0 0 0 1 0 0 0 1
OutputCopy
2
1
1
0
3

*/

#include <cstdio>
int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n;
    scanf("%ld", &n);
    long cur(0), mx(0);
    for (long p = 0; p < n; p++) {
      int x;
      scanf("%d", &x);
      if (x) {
        cur = 0;
        continue;
      }
      ++cur;
      mx = (mx > cur) ? mx : cur;
    }

    printf("%ld\n", mx);
  }
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cur = 0, mx = 0; // Initialize as integers
    for (int p = 0; p < n; p++) {
      int x;
      cin >> x;
      if (x != 0) { // If non-zero, reset `cur`
        cur = 0;
      } else { // If zero, increment `cur`
        cur++;
        mx = max(mx, cur); // Update `mx` if `cur` is greater
      }
    }
    cout << mx << endl; // Print the maximum length of consecutive zeros
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1829/301020775
