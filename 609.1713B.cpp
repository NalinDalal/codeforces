/*B. Optimal Reduction
time limit per test1 second
memory limit per test256 megabytes
Consider an array 𝑎
 of 𝑛
 positive integers.

You may perform the following operation:

select two indices 𝑙
 and 𝑟
 (1≤𝑙≤𝑟≤𝑛
), then
decrease all elements 𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟
 by 1
.
Let's call 𝑓(𝑎)
 the minimum number of operations needed to change array 𝑎
 into an array of 𝑛
 zeros.

Determine if for all permutations†
 𝑏
 of 𝑎
, 𝑓(𝑎)≤𝑓(𝑏)
 is true.

†
 An array 𝑏
 is a permutation of an array 𝑎
 if 𝑏
 consists of the elements of 𝑎
 in arbitrary order. For example, [4,2,3,4]
 is a permutation of [3,2,4,4]
 while [1,2,2]
 is not a permutation of [1,2,3]
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤105
) — the length of the array 𝑎
.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — description of the array 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, print "YES" (without quotes) if for all permutations 𝑏
 of 𝑎
, 𝑓(𝑎)≤𝑓(𝑏)
 is true, and "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and
"Yes" will be recognized as a positive response).

Example
InputCopy
3
4
2 3 5 4
3
1 2 3
4
3 1 3 2
OutputCopy
YES
YES
NO
Note
In the first test case, we can change all elements to 0
 in 5
 operations. It can be shown that no permutation of [2,3,5,4]
 requires less than 5
 operations to change all elements to 0
.

In the third test case, we need 5
 operations to change all elements to 0
, while [2,3,3,1]
 only needs 3
 operations.



*/

#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;

  while (t--) {
    long n;
    std::cin >> n;

    std::vector<long> a(n);
    for (long p = 0; p < n; p++) {
      std::cin >> a[p];
    }

    long cnt = 0;

    for (long p = 1; p < n; p++) {
      if (a[p - 1] <= a[p]) {
        ++cnt;
      } else {
        break;
      }
    }

    for (long p = n - 1; p > 0; p--) {
      if (a[p - 1] >= a[p]) {
        ++cnt;
      } else {
        break;
      }
    }

    std::cout << (cnt >= n - 1 ? "YES\n" : "NO\n");
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/1713/334457565
