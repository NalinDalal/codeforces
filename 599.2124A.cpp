/*A. Deranged Deletions
time limit per test1 second
memory limit per test256 megabytes
Call an array 𝑏
 of length 𝑚
 a derangement if the following property holds:

Let 𝑐
 be an array of length 𝑚
 such that 𝑐𝑖=𝑏𝑖
 over all 1≤𝑖≤𝑚
.
Sort 𝑐
 in non-decreasing order.
If 𝑏𝑖≠𝑐𝑖
 over all 1≤𝑖≤𝑚
, then 𝑏
 is a derangement.
For example,

If 𝑏=[4,8,3,1]
, then 𝑐=[1,3,4,8]
 after getting sorted. Since 𝑏𝑖≠𝑐𝑖
 in all positions, 𝑏
 is a derangement.
If 𝑏=[3,2,1]
, then 𝑐=[1,2,3]
 after getting sorted. Since 𝑏2=𝑐2
, 𝑏
 is not a derangement.
You are given an array 𝑎
 of length 𝑛
. In one operation, you can delete an element from 𝑎
. The order of the remaining elements is preserved after each deletion.

Output whether it is possible to perform some (possibly none) operations such
that the remaining elements form a derangement. If it is possible, output any
possible remaining array. The remaining array must be non-empty.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤100
). The description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤100
) — the length of array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
) — denoting the array 𝑎
.

Output
For each test case, on a new line, if it is possible to perform operations such
that the remaining array is a derangement, output YES. Otherwise, output NO.

You can output in any case (upper or lower). For example, the strings "yEs",
"yes", "Yes", and "YES" will be recognized as positive responses.

If your response was positive, output two more lines in the following format:

The first line should contain an integer 𝑘
 (1≤𝑘≤𝑛
), the number of elements that remain in the array.
The second line should contain 𝑑1,𝑑2…,𝑑𝑘
, the elements that remain in the array. It must be possible to acquire array 𝑑
 after performing some operations on 𝑎
. Array 𝑑
 must be a derangement.
Example
InputCopy
3
3
2 2 3
5
4 5 5 2 4
1
1
OutputCopy
NO
YES
4
4 5 2 4
NO
Note
In the second test case, we can delete one 5
 from the array so that it becomes [4,5,2,4]
. It can be shown this array is a derangement. This is not the only solution –
it can be shown that the original array [4,5,5,2,4] is another valid solution.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::vector<long> a(n);
    for (long p = 0; p < n; p++) {
      std::cin >> a[p];
    }

    long x = -1, y = -1;
    for (long p = 0; x < 0 && p < n; p++) {
      for (long q = p + 1; x < 0 && q < n; q++) {
        if (a[p] > a[q]) {
          x = a[p];
          y = a[q];
        }
      }
    }

    if (x < 0) {
      std::cout << "NO" << std::endl;
    } else {
      std::cout << "YES" << std::endl
                << "2" << std::endl
                << x << " " << y << std::endl;
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2124/334147502
