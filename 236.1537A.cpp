/* A. Arithmetic Array
time limit per test1 second
memory limit per test256 megabytes
An array 𝑏
 of length 𝑘
 is called good if its arithmetic mean is equal to 1
. More formally, if
𝑏1+⋯+𝑏𝑘𝑘=1.

Note that the value 𝑏1+⋯+𝑏𝑘𝑘
 is not rounded up or down. For example, the array [1,1,1,2]
 has an arithmetic mean of 1.25
, which is not equal to 1
.

You are given an integer array 𝑎
 of length 𝑛
. In an operation, you can append a non-negative integer to the end of the
array. What's the minimum number of operations required to make the array good?

We have a proof that it is always possible with finitely many operations.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases. Then 𝑡
 test cases follow.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤50
) — the length of the initial array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,…,𝑎𝑛
 (−104≤𝑎𝑖≤104
), the elements of the array.

Output
For each test case, output a single integer — the minimum number of non-negative
integers you have to append to the array so that the arithmetic mean of the
array will be exactly 1
.

Example
InputCopy
4
3
1 1 1
2
1 2
4
8 4 6 2
1
-2
OutputCopy
0
1
16
1
Note
In the first test case, we don't need to add any element because the arithmetic
mean of the array is already 1 , so the answer is 0
.

In the second test case, the arithmetic mean is not 1
 initially so we need to add at least one more number. If we add 0
 then the arithmetic mean of the whole array becomes 1
, so the answer is 1
.

In the third test case, the minimum number of elements that need to be added is
16 since only non-negative integers can be added.

In the fourth test case, we can add a single integer 4
. The arithmetic mean becomes −2+42
 which is equal to 1
.


*/

#include <iostream>
int main() {

  int t;
  std::cin >> t;

  while (t--) {
    int n;
    std::cin >> n;
    int s = 0;
    for (long p = 0; p < n; p++) {
      int x;
      std::cin >> x;
      s += x;
    }
    std::cout << ((s >= n) ? (s - n) : 1) << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1537/311155526
