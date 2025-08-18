/*B. Playing with GCD
time limit per test1 second
memory limit per test256 megabytes
You are given an integer array 𝑎
 of length 𝑛
.

Does there exist an array 𝑏
 consisting of 𝑛+1
 positive integers such that 𝑎𝑖=gcd(𝑏𝑖,𝑏𝑖+1)
 for all 𝑖
 (1≤𝑖≤𝑛
)?

Note that gcd(𝑥,𝑦)
 denotes the greatest common divisor (GCD) of integers 𝑥
 and 𝑦
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤105
). Description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤105
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 space-separated integers 𝑎1,𝑎2,…,𝑎𝑛
 representing the array 𝑎
 (1≤𝑎𝑖≤104
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output "YES" if such 𝑏
 exists, otherwise output "NO". You can print each letter in any case (upper or
lower).

Example
InputCopy
4
1
343
2
4 2
3
4 2 4
4
1 1 1 1
OutputCopy
YES
YES
NO
YES
Note
In the first test case, we can take 𝑏=[343,343]
.

In the second test case, one possibility for 𝑏
 is 𝑏=[12,8,6]
.

In the third test case, it can be proved that there does not exist any array 𝑏
 that fulfills all the conditions.
*/

#include <iostream>
#include <vector>
using namespace std;

long gcd(long a, long b) { return b ? gcd(b, a % b) : a; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    vector<long> a(n);
    for (long p = 0; p < n; p++) {
      cin >> a[p];
    }
    bool res = true;
    for (long p = 1; res && p + 1 < n; p++) {
      if (a[p] % gcd(a[p - 1], a[p + 1])) {
        res = false;
      }
    }
    cout << (res ? "YES\n" : "NO\n");
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1736/334332467
