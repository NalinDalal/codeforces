/* D. Same Differences
time limit per test2 seconds
memory limit per test256 megabytes
You are given an array 𝑎
 of 𝑛
 integers. Count the number of pairs of indices (𝑖,𝑗)
 such that 𝑖<𝑗
 and 𝑎𝑗−𝑎𝑖=𝑗−𝑖
.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
). Then 𝑡
 test cases follow.

The first line of each test case contains one integer 𝑛
 (1≤𝑛≤2⋅105
).

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
) — array 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case output the number of pairs of indices (𝑖,𝑗)
 such that 𝑖<𝑗
 and 𝑎𝑗−𝑎𝑖=𝑗−𝑖
.

Example
InputCopy
4
6
3 5 1 4 6 6
3
1 2 3
4
1 3 3 4
6
1 6 3 4 5 6
OutputCopy
1
3
3
10

*/
#include <iostream>
#include <map>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 0;
    map<long long, long long> m;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      x -= i;
      ans += m[x];
      ++m[x];
    }
    cout << ans << endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1520/318411694
