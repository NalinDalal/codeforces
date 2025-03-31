/*
B. Penchick and Satay Sticks
time limit per test1.5 seconds
memory limit per test256 megabytes
Penchick and his friend Kohane are touring Indonesia, and their next stop is in
Surabaya!

In the bustling food stalls of Surabaya, Kohane bought 𝑛
 satay sticks and arranged them in a line, with the 𝑖
-th satay stick having length 𝑝𝑖
. It is given that 𝑝
 is a permutation∗
 of length 𝑛
.

Penchick wants to sort the satay sticks in increasing order of length, so that
𝑝𝑖=𝑖 for each 1≤𝑖≤𝑛 . For fun, they created a rule: they can only swap
neighboring satay sticks whose lengths differ by exactly 1 . Formally, they can
perform the following operation any number of times (including zero):

Select an index 𝑖
 (1≤𝑖≤𝑛−1
) such that |𝑝𝑖+1−𝑝𝑖|=1
;
Swap 𝑝𝑖
 and 𝑝𝑖+1
.
Determine whether it is possible to sort the permutation 𝑝
, thus the satay sticks, by performing the above operation.

∗
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
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤2⋅105
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of satay sticks.

The second line of each test case contains 𝑛
 integers 𝑝1,𝑝2,…,𝑝𝑛
 (1≤𝑝𝑖≤𝑛
) — the permutation 𝑝
 representing the length of the satay sticks.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output "YES" if it is possible to sort permutation 𝑝
 by performing the operation. Otherwise, output "NO".

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
2
4
2 1 3 4
4
4 2 3 1
OutputCopy
YES
NO
Note
In the first test case, we can sort permutation 𝑝=[2,1,3,4]
 by performing an operation on index 1
 (|𝑝2−𝑝1|=|1−2|=1
), resulting in 𝑝=[1,2,3,4]
.

In the second test case, it can be proven that it is impossible to sort
permutation 𝑝=[4,2,3,1] by performing the operation. Here is an example of a
sequence of operations that can be performed on the permutation:

Select 𝑖=2
 (|𝑝3−𝑝2|=|3−2|=1
). This results in 𝑝=[4,3,2,1]
.
Select 𝑖=1
 (|𝑝2−𝑝1|=|3−4|=1
). This results in 𝑝=[3,4,2,1]
.
Select 𝑖=3
 (|𝑝4−𝑝3|=|1−2|=1
). This results in 𝑝=[3,4,1,2]
.
Unfortunately, permutation 𝑝
 remains unsorted after performing the operations.

*/

#include <iostream>
#include <vector>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::vector<long> v(n + 1);
    for (long p = 1; p <= n; p++) {
      std::cin >> v[p];
    }
    bool ans = true;
    for (long i = 1; i <= n && ans; i++) {
      if (v[i] == i) {
        continue;
      } else if (v[i] == i + 1 && i < n && v[i + 1] == i) {
        long tmp = v[i];
        v[i] = v[i + 1];
        v[i + 1] = tmp;
      } else {
        ans = false;
      }
    }
    std::cout << (ans ? "YES" : "NO") << std::endl;
  }
  return 0;
}
// sub:https://codeforces.com/problemset/submission/2031/313212036
