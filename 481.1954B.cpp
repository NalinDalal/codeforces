/*B. Make It Ugly
time limit per test2 seconds
memory limit per test256 megabytes
Let's call an array 𝑎
 beautiful if you can make all its elements the same by using the following
operation an arbitrary number of times (possibly, zero):

choose an index 𝑖
 (2≤𝑖≤|𝑎|−1
) such that 𝑎𝑖−1=𝑎𝑖+1
, and replace 𝑎𝑖
 with 𝑎𝑖−1
.
You are given a beautiful array 𝑎1,𝑎2,…,𝑎𝑛
. What is the minimum number of elements you have to remove from it in order for
it to stop being beautiful? Swapping elements is prohibited. If it is impossible
to do so, then output -1.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤3⋅105
).

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
).

Additional constraints on the input:

in every test case, the given array 𝑎
 is beautiful;
the sum of 𝑛
 over all test cases does not exceed 3⋅105
.
Output
For each test case, output a single integer — the minimum number of elements you
have to remove from the array 𝑎 in order for it to stop being beautiful. If it
is impossible, then output -1.

Example
InputCopy
4
3
2 2 2
5
1 2 1 2 1
1
1
7
3 3 3 5 3 3 3
OutputCopy
-1
1
-1
3
Note
In the first testcase, it is impossible to modify the array in such a way that
it stops being beautiful. An array consisting of identical numbers will remain
beautiful no matter how many numbers we remove from it.

In the second testcase, you can remove the number at the index 5
, for example.

The resulting array will be [1,2,1,2]
. Let's check if it is beautiful. Two operations are available:

Choose 𝑖=2
: the array becomes [1,1,1,2]
. No more operations can be applied to it, and the numbers are not all the same.
Choose 𝑖=3
 instead: the array becomes [1,2,2,2]
. No more operations can be applied to it either, and the numbers are still not
all the same. Thus, the array [1,2,1,2] is not beautiful.

In the fourth testcase, you can remove the first three elements, for example.
The resulting array [5,3,3,3] is not beautiful.

*/

#include <algorithm>
#include <iostream>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    long ans = n + 7;
    long x;
    std::cin >> x;
    long pos = -1;

    for (long p = 1; p < n; p++) {
      long a;
      std::cin >> a;
      if (a != x) {
        ans = std::min(ans, p - 1 - pos);
        pos = p;
      }
    }
    ans = std::min(ans, n - 1 - pos);
    if (ans >= n) {
      std::cout << -1 << std::endl;
    } else {
      std::cout << ans << std::endl;
    }
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1954/327966591
