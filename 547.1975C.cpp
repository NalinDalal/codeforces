/*C. Chamo and Mocha's Array
time limit per test2 seconds
memory limit per test256 megabytes
Mocha likes arrays, so before her departure, Chamo gave her an array 𝑎
 consisting of 𝑛
 positive integers as a gift.

Mocha doesn't like arrays containing different numbers, so Mocha decides to use
magic to change the array. Mocha can perform the following three-step operation
some (possibly, zero) times:

Choose indices 𝑙
 and 𝑟
 (1≤𝑙<𝑟≤𝑛
)
Let 𝑥
 be the median†
 of the subarray [𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟]
Set all values 𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟
 to 𝑥
Suppose 𝑎=[1,2,3,4,5]
 initially:

If Mocha chooses (𝑙,𝑟)=(3,4)
 in the first operation, then 𝑥=3
, the array will be changed into 𝑎=[1,2,3,3,5]
.
If Mocha chooses (𝑙,𝑟)=(1,3)
 in the first operation, then 𝑥=2
, the array will be changed into 𝑎=[2,2,2,4,5]
.
Mocha will perform the operation until the array contains only the same number.
Mocha wants to know what is the maximum possible value of this number.

†
 The median in an array 𝑏
 of length 𝑚
 is an element that occupies position number ⌊𝑚+12⌋
 after we sort the elements in non-decreasing order. For example, the median of
[3,1,4,1,5] is 3 and the median of [5,25,20,24] is 20
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤105
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the elements of the array 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output the maximum value of the number.

Example
InputCopy
2
2
1 2
5
1 2 3 4 5
OutputCopy
1
4
Note
In the first test case, 𝑎=[1,2]
. Mocha can only choose the interval (𝑙,𝑟)=(1,2)
. The array will be changed to 𝑎=[1,1]
. Therefore, the answer is 1
.

In the second test case, Mocha can perform the following operations:

Choose the interval (𝑙,𝑟)=(4,5)
, then 𝑎=[1,2,3,4,4]
.
Choose the interval (𝑙,𝑟)=(3,5)
, then 𝑎=[1,2,4,4,4]
.
Choose the interval (𝑙,𝑟)=(1,5)
, then 𝑎=[4,4,4,4,4]
.
The array contains only the same number, which is 4
. It can be proven that the maximum value of the final number cannot be greater
than 4
.



*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::vector<long> v(n);
    for (long p = 0; p < n; p++) {
      std::cin >> v[p];
    }
    if (n == 2) {
      std::cout << (v[0] < v[1] ? v[0] : v[1]) << std::endl;
      continue;
    }

    std::multiset<long> s;
    s.insert(v[0]);
    s.insert(v[1]);
    s.insert(v[2]);
    long res = *std::next(s.begin(), 1);
    for (long p = 3; p < n; p++) {
      s.erase(s.find(v[p - 3]));
      s.insert(v[p]);
      long cand = *std::next(s.begin(), 1);
      res = (res > cand ? res : cand);
    }

    std::cout << res << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1975/331427606
