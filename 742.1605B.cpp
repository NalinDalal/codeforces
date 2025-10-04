/*B. Reverse Sort
time limit per test2 seconds
memory limit per test256 megabytes
Ashish has a binary string 𝑠
 of length 𝑛
 that he wants to sort in non-decreasing order.

He can perform the following operation:

Choose a subsequence of any length such that its elements are in non-increasing
order. Formally, choose any 𝑘 such that 1≤𝑘≤𝑛 and any sequence of 𝑘 indices
1≤𝑖1<𝑖2<…<𝑖𝑘≤𝑛 such that 𝑠𝑖1≥𝑠𝑖2≥…≥𝑠𝑖𝑘
.
Reverse this subsequence in-place. Formally, swap 𝑠𝑖1
 with 𝑠𝑖𝑘
, swap 𝑠𝑖2
 with 𝑠𝑖𝑘−1
, …
 and swap 𝑠𝑖⌊𝑘/2⌋
 with 𝑠𝑖⌈𝑘/2⌉+1
 (Here ⌊𝑥⌋
 denotes the largest integer not exceeding 𝑥
, and ⌈𝑥⌉
 denotes the smallest integer not less than 𝑥
)
Find the minimum number of operations required to sort the string in
non-decreasing order. It can be proven that it is always possible to sort the
given binary string in at most 𝑛 operations.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000)
  — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤1000)
  — the length of the binary string 𝑠
.

The second line of each test case contains a binary string 𝑠
 of length 𝑛
 containing only 0
s and 1
s.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 1000
.

Output
For each test case output the following:

The minimum number of operations 𝑚
 in the first line (0≤𝑚≤𝑛
).
Each of the following 𝑚
 lines should be of the form: 𝑘
 𝑖1
 𝑖2
 ... 𝑖𝑘
, where 𝑘
 is the length and 𝑖1<𝑖2<...<𝑖𝑘
 are the indices of the chosen subsequence. For them the conditions from the
statement must hold. Example InputCopy
3
7
0011111
5
10100
6
001000
OutputCopy
0
1
4 1 3 4 5
1
3 3 5 6
Note
In the first test case, the binary string is already sorted in non-decreasing
order.

In the second test case, we can perform the following operation:

𝑘=4:
 choose the indices {1,3,4,5}
1⎯⎯
 0
 1⎯⎯
 0⎯⎯
 0⎯⎯
 →
 0⎯⎯
 0
 0⎯⎯
 1⎯⎯
 1⎯⎯

In the third test case, we can perform the following operation:

𝑘=3:
 choose the indices {3,5,6}
0
 0
 1⎯⎯
 0
 0⎯⎯
 0⎯⎯
 →
 0
 0
 0⎯⎯
 0
 0⎯⎯
 1⎯⎯
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    long left(0);
    while (left < s.size() && s[left] == '0') {
      ++left;
    }
    long right(s.size() - 1);
    while (right >= 0 && s[right] == '1') {
      --right;
    }

    std::vector<long> v;
    while (left < right) {
      v.push_back(left);
      ++left;
      v.push_back(right);
      --right;
      while (left < s.size() && s[left] == '0') {
        ++left;
      }
      while (right >= 0 && s[right] == '1') {
        --right;
      }
    }

    if (v.size() > 0) {
      sort(v.begin(), v.end());
      std::cout << "1\n" << v.size();
      for (long p = 0; p < v.size(); p++) {
        std::cout << " " << (1 + v[p]);
      }
      std::cout << std::endl;
    } else {
      std::cout << "0" << std::endl;
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1605/341850310
