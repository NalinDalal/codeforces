/*D. Replace with Occurrences
time limit per test2 seconds
memory limit per test256 megabytes
Given an array 𝑎
, let 𝑓(𝑥)
 be the number of occurrences of 𝑥
 in the array 𝑎
. For example, when 𝑎=[1,2,3,1,4]
, then 𝑓(1)=2
 and 𝑓(3)=1
.

You have an array 𝑏
 of size 𝑛
. Please determine if there is an array 𝑎
 of size 𝑛
 such that 𝑓(𝑎𝑖)=𝑏𝑖
 for all 1≤𝑖≤𝑛
. If there is one, construct it.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤2⋅105
).

The second line contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤𝑛
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output −1
 if there is no valid array 𝑎
.

Otherwise, print the array 𝑎
 of 𝑛
 integers on a new line. The elements should satisfy 1≤𝑎𝑖≤𝑛
.

Example
InputCopy
3
4
1 2 3 4
6
1 2 2 3 3 3
6
6 6 6 6 6 6
OutputCopy
-1
4 5 5 6 6 6
2 2 2 2 2 2
Note
In the first test case, it can be shown that no array matches the requirement.

In the second test case, 4
, 5
, 6
 appear 1,2,3
 times respectively. Thus, the output array is correct as
𝑓(4),𝑓(5),𝑓(5),𝑓(6),𝑓(6),𝑓(6) are 1,2,2,3,3,3 respectively.
*/

#include <iostream>
#include <map>
#include <vector>

int main() {
  long t;
  std::cin >> t;

  while (t--) {
    long n;
    std::cin >> n;

    std::map<long, std::vector<long>> m;
    for (long i = 0; i < n; ++i) {
      long x;
      std::cin >> x;
      m[x].push_back(i);
    }

    bool possible = true;
    for (const auto &f : m) {
      long key = f.first;
      long len = f.second.size();
      if (len % key != 0) {
        possible = false;
        break;
      }
    }

    if (!possible) {
      std::cout << "-1\n";
      continue;
    }

    long num = 0;
    std::vector<long> v(n);
    for (const auto &f : m) {
      long key = f.first;
      const std::vector<long> &w = f.second;
      for (long p = 0; p < w.size(); ++p) {
        if (p % key == 0)
          ++num;
        v[w[p]] = num;
      }
    }

    for (long i = 0; i < v.size(); ++i) {
      std::cout << v[i] << " ";
    }
    std::cout << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2137/344460380
