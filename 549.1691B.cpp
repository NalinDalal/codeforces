/*B. Shoe Shuffling
time limit per test1 second
memory limit per test256 megabytes
A class of students got bored wearing the same pair of shoes every day, so they
decided to shuffle their shoes among themselves. In this problem, a pair of
shoes is inseparable and is considered as a single object.

There are 𝑛
 students in the class, and you are given an array 𝑠
 in non-decreasing order, where 𝑠𝑖
 is the shoe size of the 𝑖
-th student. A shuffling of shoes is valid only if no student gets their own
shoes and if every student gets shoes of size greater than or equal to their
size.

You have to output a permutation 𝑝
 of {1,2,…,𝑛}
 denoting a valid shuffling of shoes, where the 𝑖
-th student gets the shoes of the 𝑝𝑖
-th student (𝑝𝑖≠𝑖
). And output −1
 if a valid shuffling does not exist.

A permutation is an array consisting of 𝑛
 distinct integers from 1
 to 𝑛
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array) and [1,3,4]
 is also not a permutation (𝑛=3
 but there is 4
 in the array).

Input
Each test contains multiple test cases. The first line contains a single integer
𝑡 (1≤𝑡≤1000 ) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤105
) — the number of students.

The second line of each test case contains 𝑛
 integers 𝑠1,𝑠2,…,𝑠𝑛
 (1≤𝑠𝑖≤109
, and for all 1≤𝑖<𝑛
, 𝑠𝑖≤𝑠𝑖+1
) — the shoe sizes of the students.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, print the answer in a single line using the following
format.

If a valid shuffling does not exist, print the number −1
 as the answer.

If a valid shuffling exists, print 𝑛
 space-separated integers — a permutation 𝑝
 of 1,2,…,𝑛
 denoting a valid shuffling of shoes where the 𝑖
-th student gets the shoes of the 𝑝𝑖
-th student. If there are multiple answers, then print any of them.

Example
InputCopy
2
5
1 1 1 1 1
6
3 6 8 13 15 21
OutputCopy
5 1 2 3 4
-1
Note
In the first test case, any permutation 𝑝
 of 1,…,𝑛
 where 𝑝𝑖≠𝑖
 would represent a valid shuffling since all students have equal shoe sizes, and
thus anyone can wear anyone's shoes.

In the second test case, it can be shown that no valid shuffling is possible.
*/

#include <iostream>
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
    v.push_back(1e9 + 7);
    long sz = 1, start = 0;
    bool possible = true;
    std::vector<long> w;
    for (long p = 1; p <= n; p++) {
      if (v[p] == v[p - 1]) {
        ++sz;
        continue;
      }
      if (sz == 1) {
        possible = false;
        break;
      }
      w.push_back(p);
      for (long u = start; u < p - 1; u++) {
        w.push_back(u + 1);
      }
      start = p;
      sz = 1;
    }

    if (possible) {
      for (long p = 0; p < w.size(); p++) {
        std::cout << w[p] << " ";
      }
      std::cout << std::endl;
    } else {
      std::cout << -1 << std::endl;
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1691/331524093
