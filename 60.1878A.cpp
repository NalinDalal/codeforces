/* https://codeforces.com/problemset/problem/1878/A

A. How Much Does Daytona Cost?

We define an integer to be the most common on a subsegment, if its number of
occurrences on that subsegment is larger than the number of occurrences of any
other integer in that subsegment. A subsegment of an array is a consecutive
segment of elements in the array 𝑎.

Given an array 𝑎 of size 𝑛, and an integer 𝑘, determine if there exists a
non-empty subsegment of 𝑎 where 𝑘 is the most common element.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤1000) — the number of test cases. The description of test cases
follows.

The first line of each test case contains two integers 𝑛 and 𝑘 (1≤𝑛≤100,
1≤𝑘≤100) — the number of elements in array and the element which must be the
most common.

The second line of each test case contains 𝑛 integers 𝑎1, 𝑎2, 𝑎3, …, 𝑎𝑛
(1≤𝑎𝑖≤100) — elements of the array.

Output
For each test case output "YES" if there exists a subsegment in which 𝑘 is the
most common element, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes",
"Yes", and "YES" will be recognized as a positive answer).

Example
InputCopy
7
5 4
1 4 3 4 1
4 1
2 3 4 4
5 6
43 5 60 4 2
2 5
1 5
4 1
5 3 3 1
1 3
3
5 3
3 4 1 5 5
OutputCopy
YES
NO
NO
YES
YES
YES
YES
Note
In the first test case we need to check if there is a subsegment where the most
common element is 4.

On the subsegment [2,5] the elements are 4, 3, 4, 1.

4 appears 2 times;
1 appears 1 time;
3 appears 1 time.
This means that 4 is the most common element on the subsegment [2,5], so there
exists a subsegment where 4 is the most common element.
*/

// Implements a bitwise sieve for prime number detection and the Miller-Rabin
// primality test for checking large primes. Functions like binpower and
// MillerRabin are included to perform efficient modular exponentiation and
// prime tests. The solve() function checks whether a given value k exists in
// the input array arr. If k is found in the array, it prints "YES", otherwise
// prints "NO".

#include <bits/stdc++>
using namespace std;

#define YES cout << "YES" << '\n';
#define NO cout << "NO" << '\n';

void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> arr(n);

  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (auto x : arr) {
    if (x == k) {
      YES return;
    }
  }
  NO
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testCases = 1;
  cin >> testCases;
  while (testCases--) {
    solve();
  }

  return 0;
}
