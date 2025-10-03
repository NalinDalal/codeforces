/*B. Valerii Against Everyone
time limit per test1 second
memory limit per test256 megabytes
You're given an array 𝑏
 of length 𝑛
. Let's define another array 𝑎
, also of length 𝑛
, for which 𝑎𝑖=2𝑏𝑖
 (1≤𝑖≤𝑛
).

Valerii says that every two non-intersecting subarrays of 𝑎
 have different sums of elements. You want to determine if he is wrong. More
formally, you need to determine if there exist four integers 𝑙1,𝑟1,𝑙2,𝑟2 that
satisfy the following conditions:

1≤𝑙1≤𝑟1<𝑙2≤𝑟2≤𝑛
;
𝑎𝑙1+𝑎𝑙1+1+…+𝑎𝑟1−1+𝑎𝑟1=𝑎𝑙2+𝑎𝑙2+1+…+𝑎𝑟2−1+𝑎𝑟2
.
If such four integers exist, you will prove Valerii wrong. Do they exist?

An array 𝑐
 is a subarray of an array 𝑑
 if 𝑐
 can be obtained from 𝑑
 by deletion of several (possibly, zero or all) elements from the beginning and
several (possibly, zero or all) elements from the end.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤100
). Description of the test cases follows.

The first line of every test case contains a single integer 𝑛
 (2≤𝑛≤1000
).

The second line of every test case contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (0≤𝑏𝑖≤109
).

Output
For every test case, if there exist two non-intersecting subarrays in 𝑎
 that have the same sum, output YES on a separate line. Otherwise, output NO on
a separate line.

Also, note that each letter can be in any case.

Example
InputCopy
2
6
4 3 0 1 2 0
2
2 5
OutputCopy
YES
NO
Note
In the first case, 𝑎=[16,8,1,2,4,1]
. Choosing 𝑙1=1
, 𝑟1=1
, 𝑙2=2
 and 𝑟2=6
 works because 16=(8+1+2+4+1)
.

In the second case, you can verify that there is no way to select to such
subarrays.



*/

#include <iostream>
#include <set>

int main() {
  std::ios::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::set<long> s;
    bool ans = false;
    for (long p = 0; p < n; p++) {
      long b;
      std::cin >> b;
      if (s.count(b)) {
        ans = true;
      }
      s.insert(b);
    }

    std::cout << (ans ? "YES" : "NO") << std::endl;
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1438/341621469
