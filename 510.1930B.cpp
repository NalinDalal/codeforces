/*B. Permutation Printing
time limit per test1 second
memory limit per test256 megabytes
You are given a positive integer 𝑛
.

Find a permutation†
 𝑝
 of length 𝑛
 such that there do not exist two distinct indices 𝑖
 and 𝑗
 (1≤𝑖,𝑗<𝑛
; 𝑖≠𝑗
) such that 𝑝𝑖
 divides 𝑝𝑗
 and 𝑝𝑖+1
 divides 𝑝𝑗+1
.

Refer to the Notes section for some examples.

Under the constraints of this problem, it can be proven that at least one 𝑝
 exists.

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
Each test contains multiple test cases. The first line contains a single integer
𝑡 (1≤𝑡≤103 ) — the number of test cases. The description of the test cases
follows.

The first line of each test case contains a single integer 𝑛
 (3≤𝑛≤105
) — the length of the permutation 𝑝
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output 𝑝1,𝑝2,…,𝑝𝑛
.

If there are multiple solutions, you may output any one of them.

Example
InputCopy
2
4
3
OutputCopy
4 1 2 3
1 2 3
Note
In the first test case, 𝑝=[4,1,2,3]
 is a valid permutation. However, the permutation 𝑝=[1,2,3,4]
 is not a valid permutation as we can choose 𝑖=1
 and 𝑗=3
. Then 𝑝1=1
 divides 𝑝3=3
 and 𝑝2=2
 divides 𝑝4=4
. Note that the permutation 𝑝=[3,4,2,1]
 is also not a valid permutation as we can choose 𝑖=3
 and 𝑗=2
. Then 𝑝3=2
 divides 𝑝2=4
 and 𝑝4=1
 divides 𝑝3=2
.

In the second test case, 𝑝=[1,2,3]
 is a valid permutation. In fact, all 6
 permutations of length 3
 are valid.
*/

#include <iostream>
using namespace std;

int main() {
  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    long left = 1, right = n;
    for (long p = 0; p < n; p++) {
      cout << ((p % 2) ? (right--) : (left++)) << " ";
    }
    cout << endl;
  }
}
// sub: https://codeforces.com/problemset/submission/1930/329288142
