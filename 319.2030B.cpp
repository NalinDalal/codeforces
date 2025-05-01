/* B. Minimise Oneness
time limit per test1.5 seconds
memory limit per test256 megabytes
For an arbitrary binary string 𝑡
∗
, let 𝑓(𝑡)
 be the number of non-empty subsequences†
 of 𝑡
 that contain only 𝟶
, and let 𝑔(𝑡)
 be the number of non-empty subsequences of 𝑡
 that contain at least one 𝟷
.

Note that for 𝑓(𝑡)
 and for 𝑔(𝑡)
, each subsequence is counted as many times as it appears in 𝑡
. E.g., 𝑓(𝟶𝟶𝟶)=7,𝑔(𝟷𝟶𝟶)=4
.

We define the oneness of the binary string 𝑡
 to be |𝑓(𝑡)−𝑔(𝑡)|
, where for an arbitrary integer 𝑧
, |𝑧|
 represents the absolute value of 𝑧
.

You are given a positive integer 𝑛
. Find a binary string 𝑠
 of length 𝑛
 such that its oneness is as small as possible. If there are multiple strings,
you can print any of them.

∗
A binary string is a string that only consists of characters 𝟶
 and 𝟷
.

†
A sequence 𝑎
 is a subsequence of a sequence 𝑏
 if 𝑎
 can be obtained from 𝑏
 by the deletion of several (possibly, zero or all) elements. For example,
subsequences of 𝟷𝟶𝟷𝟷𝟷𝟶𝟷 are 𝟶 , 𝟷 , 𝟷𝟷𝟷𝟷𝟷 , 𝟶𝟷𝟷𝟷 , but not 𝟶𝟶𝟶 nor 𝟷𝟷𝟷𝟶𝟶
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The only line of each test case contains an integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of 𝑠
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output 𝑠
 on a new line. If multiple answers exist, output any.

Example
InputCopy
3
1
2
3
OutputCopy
0
01
010
Note
In the first test case, for the example output, 𝑓(𝑡)=1
 because there is one subsequence that contains only 𝟶
 (𝟶
), and 𝑔(𝑡)=0
 because there are no subsequences that contain at least one 1
. The oneness is |1−0|=1
. The output 𝟷
 is correct as well because its oneness is |0−1|=1
.

For the example output of the second test case, 𝑓(𝑡)=1
 because there is one non-empty subsequence that contains only 𝟶
, and 𝑔(𝑡)=2
 because there are two non-empty subsequences that contain at least one 𝟷
 (𝟶𝟷
 and 𝟷
). The oneness is thus |1−2|=1
. It can be shown that 1
 is the minimum possible value of its oneness over all possible binary strings
of size 2.*/

#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::cout << "1";
    for (int i = 1; i < n; i++) {
      std::cout << "0";
    }
    std::cout << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2030/317897474
