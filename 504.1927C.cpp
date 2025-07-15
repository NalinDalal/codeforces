/*
C. Choose the Different Ones!
time limit per test2 seconds
memory limit per test256 megabytes
Given an array 𝑎
 of 𝑛
 integers, an array 𝑏
 of 𝑚
 integers, and an even number 𝑘
.

Your task is to determine whether it is possible to choose exactly 𝑘2
 elements from both arrays in such a way that among the chosen elements, every
integer from 1 to 𝑘 is included.

For example:

If 𝑎=[2,3,8,5,6,5]
, 𝑏=[1,3,4,10,5]
, 𝑘=6
, then it is possible to choose elements with values 2,3,6
 from array 𝑎
 and elements with values 1,4,5
 from array 𝑏
. In this case, all numbers from 1
 to 𝑘=6
 will be included among the chosen elements.
If 𝑎=[2,3,4,5,6,5]
, 𝑏=[1,3,8,10,3]
, 𝑘=6
, then it is not possible to choose elements in the required way.
Note that you are not required to find a way to choose the elements — your
program should only check whether it is possible to choose the elements in the
required way.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The descriptions of the test cases follow.

The first line of each test case contains three integers 𝑛
, 𝑚
, and 𝑘
 (1≤𝑛,𝑚≤2⋅105
, 2≤𝑘≤2⋅min(𝑛,𝑚)
, 𝑘
 is even) — the length of array 𝑎
, the length of array 𝑏
, and the number of elements to be chosen, respectively.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤106
) — the elements of array 𝑎
.

The third line of each test case contains 𝑚
 integers 𝑏1,𝑏2,…,𝑏𝑚
 (1≤𝑏𝑗≤106
) — the elements of array 𝑏
.

It is guaranteed that the sum of values 𝑛
 and 𝑚
 over all test cases in a test does not exceed 4⋅105
.

Output
Output 𝑡
 lines, each of which is the answer to the corresponding test case. As the
answer, output "YES" if it is possible to choose 𝑘2 numbers from each array in
such a way that among the chosen elements, every integer from 1 to 𝑘 is
included. Otherwise, output "NO".

You can output each letter in any case (lowercase or uppercase). For example,
the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive
answer.

Example
InputCopy
6
6 5 6
2 3 8 5 6 5
1 3 4 10 5
6 5 6
2 3 4 5 6 5
1 3 8 10 3
3 3 4
1 3 5
2 4 6
2 5 4
1 4
7 3 4 4 2
1 4 2
2
6 4 4 2
1 5 2
3
2 2 1 4 3
OutputCopy
YES
NO
YES
YES
NO
NO
Note
In the first test case of the example, it is possible to choose elements equal
to 2 , 3 , and 6 from array 𝑎 and elements equal to 1 , 4 , and 5 from array 𝑏
. Thus, all numbers from 1
 to 𝑘=6
 are included among the chosen elements.

In the second test case of the example, it can be shown that it is not possible
to choose exactly three elements from each array in the required way.

In the third test case of the example, it is possible to choose elements equal
to 1 and 3 from array 𝑎 and elements equal to 2 and 4 from array 𝑏 . Thus, all
numbers from 1 to 𝑘=4 are included among the chosen elements.
*/
#include <iostream>
#include <vector>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    long n, m, k;
    std::cin >> n >> m >> k;
    std::vector<bool> a(k + 1, 0), b(k + 1, 0);
    for (long p = 0; p < n; p++) {
      long x;
      std::cin >> x;
      if (x <= k) {
        a[x] = 1;
      }
    }
    for (long p = 0; p < m; p++) {
      long x;
      std::cin >> x;
      if (x <= k) {
        b[x] = 1;
      }
    }

    bool possible(true);
    long u(0), v(0), w(0);
    for (long p = 1; possible && p <= k; p++) {
      if (a[p] && b[p]) {
        ++w;
      } else if (a[p]) {
        ++u;
      } else if (b[p]) {
        ++v;
      } else {
        possible = false;
      }
    }

    possible = possible && (u + w >= k / 2) && (v + w >= k / 2);
    std::cout << (possible ? "YES" : "NO") << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/1927/329016831
