/*B. Equalize
time limit per test1 second
memory limit per test256 megabytes
Vasya has two hobbies — adding permutations†
 to arrays and finding the most frequently occurring element. Recently, he found
an array 𝑎 and decided to find out the maximum number of elements equal to the
same number in the array 𝑎 that he can obtain after adding some permutation to
the array 𝑎
.

More formally, Vasya must choose exactly one permutation 𝑝1,𝑝2,𝑝3,…,𝑝𝑛
 of length 𝑛
, and then change the elements of the array 𝑎
 according to the rule 𝑎𝑖:=𝑎𝑖+𝑝𝑖
. After that, Vasya counts how many times each number occurs in the array 𝑎
 and takes the maximum of these values. You need to determine the maximum value
he can obtain.

†
A permutation of length 𝑛
 is an array consisting of 𝑛
 distinct integers from 1
 to 𝑛
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (𝑛=3
 but there is 4
 in the array).

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤2⋅104 ) — the number of test cases. Then follows the description
of the test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the elements of the array 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single number — the maximum number of elements
equal to the same number after the operation of adding a permutation.

Example
InputCopy
7
2
1 2
4
7 1 4 1
3
103 102 104
5
1 101 1 100 1
5
1 10 100 1000 1
2
3 1
3
1000000000 999999997 999999999
OutputCopy
2
2
3
2
1
1
2
Note
In the first test case, it is optimal to choose 𝑝=[2,1]
. Then after applying the operation, the array 𝑎
 will be [3,3]
, in which the number 3
 occurs twice, so the answer is 2
.

In the second test case, one of the optimal options is 𝑝=[2,3,1,4]
. After applying the operation, the array 𝑎
 will be [9,4,5,5]
. Since the number 5
 occurs twice, the answer is 2
.
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::vector<long> v;
    std::set<long> s;
    for (long p = 0; p < n; p++) {
      long x;
      std::cin >> x;
      if (s.count(x)) {
        continue;
      }
      v.push_back(x);
      s.insert(x);
    }

    sort(v.begin(), v.end());

    long idx(0);
    long ans(0);
    for (long p = 0; p < v.size(); p++) {
      while (idx + 1 < v.size() && v[idx + 1] < v[p] + n) {
        ++idx;
      }
      long len = idx - p + 1;
      ans = (ans > len) ? ans : len;
      if (idx + 1 == v.size()) {
        break;
      }
    }

    std::cout << ans << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1928/329017364
