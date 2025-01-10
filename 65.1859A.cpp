/* https://codeforces.com/problemset/problem/1859/A
* A. United We Stand
time limit per test1 second
memory limit per test256 megabytes
Given an array 𝑎 of length 𝑛, containing integers. And there are two initially
empty arrays 𝑏 and 𝑐. You need to add each element of array 𝑎 to exactly one of
the arrays 𝑏 or 𝑐, in order to satisfy the following conditions:

Both arrays 𝑏 and 𝑐 are non-empty. More formally, let 𝑙𝑏 be the length of array
𝑏, and 𝑙𝑐 be the length of array 𝑐. Then 𝑙𝑏,𝑙𝑐≥1.For any two indices 𝑖 and 𝑗
(1≤𝑖≤𝑙𝑏,1≤𝑗≤𝑙𝑐), 𝑐𝑗 is not a divisor of 𝑏𝑖.
Output the arrays 𝑏 and 𝑐 that can be obtained, or output −1 if they do not
exist.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤500) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains a single integer 𝑛 (2≤𝑛≤100) — the
length of array 𝑎.

The second line of each test case contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109) —
the elements of array 𝑎.

Output
For each test case, output a single integer −1 if a solution does not exist.

Otherwise, in the first line, output two integers 𝑙𝑏 and 𝑙𝑐 — the lengths of
arrays 𝑏 and 𝑐 respectively.

In the second line, output 𝑙𝑏 integers 𝑏1,𝑏2,…,𝑏𝑙𝑏 — the elements of array 𝑏.

In the third line, output 𝑙𝑐 integers 𝑐1,𝑐2,…,𝑐𝑙𝑐 — the elements of array 𝑐.

If there are multiple solutions, output any of them. You can output the elements
of the arrays in any order.

Example
InputCopy
5
3
2 2 2
5
1 2 3 4 5
3
1 3 5
7
1 7 7 2 9 1 4
5
4 8 12 12 4
OutputCopy
-1
3 2
1 3 5
2 4
1 2
1
3 5
2 5
1 1
2 4 7 7 9
3 2
4 8 4
12 12
Note
In the first test case, a solution does not exist.

In the second test case, we can obtain 𝑏=[1,3,5] and 𝑐=[2,4]. Then elements 2
and 4 do not divide elements 1,3 and 5.

In the fifth test case, we can obtain 𝑏=[4,8,4] and 𝑐=[12,12].


*/

// take input
// sort array a
// if all elements are identical, oputput -1
// else{
// Place the smallest element in b (this ensures no element in c can divide it
// since 𝑐 will only contain larger elements).Place the remaining elements in 𝑐.
// }
// output b, c
#include <algorithm>
#include <cstdio>
#include <vector>

int main() {
  long t;
  scanf("%ld", &t);

  while (t--) {
    long n;
    scanf("%ld", &n);
    std::vector<long> a(n);
    long mx = 0;

    // Read the array and find the maximum element
    for (long p = 0; p < n; p++) {
      scanf("%ld", &a[p]);
      if (a[p] > mx) {
        mx = a[p];
      }
    }

    std::vector<long> b, c;

    // Split the array into two groups
    for (long p = 0; p < n; p++) {
      if (a[p] == mx) {
        c.push_back(a[p]);
      } else {
        b.push_back(a[p]);
      }
    }

    // Check if both arrays are non-empty
    if (b.empty() || c.empty()) {
      puts("-1");
    } else {
      // Output sizes of b and c
      printf("%ld %ld\n", b.size(), c.size());
      for (long x : b) {
        printf("%ld ", x);
      }
      puts("");
      for (long x : c) {
        printf("%ld ", x);
      }
      puts("");
    }
  }

  return 0;
}
