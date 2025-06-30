/*B. XOR Sequences
time limit per test1 second
memory limit per test256 megabytes
You are given two distinct non-negative integers 𝑥
 and 𝑦
. Consider two infinite sequences 𝑎1,𝑎2,𝑎3,…
 and 𝑏1,𝑏2,𝑏3,…
, where

𝑎𝑛=𝑛⊕𝑥
;
𝑏𝑛=𝑛⊕𝑦
.
Here, 𝑥⊕𝑦
 denotes the bitwise XOR operation of integers 𝑥
 and 𝑦
.

For example, with 𝑥=6
, the first 8
 elements of sequence 𝑎
 will look as follows: [7,4,5,2,3,0,1,14,…]
. Note that the indices of elements start with 1
.

Your task is to find the length of the longest common subsegment†
 of sequences 𝑎
 and 𝑏
. In other words, find the maximum integer 𝑚
 such that 𝑎𝑖=𝑏𝑗,𝑎𝑖+1=𝑏𝑗+1,…,𝑎𝑖+𝑚−1=𝑏𝑗+𝑚−1
 for some 𝑖,𝑗≥1
.

†
A subsegment of sequence 𝑝
 is a sequence 𝑝𝑙,𝑝𝑙+1,…,𝑝𝑟
, where 1≤𝑙≤𝑟
.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test
cases follows.

The only line of each test case contains two integers 𝑥
 and 𝑦
 (0≤𝑥,𝑦≤109,𝑥≠𝑦
) — the parameters of the sequences.

Output
For each test case, output a single integer — the length of the longest common
subsegment.

Example
InputCopy
4
0 1
12 4
57 37
316560849 14570961
OutputCopy
1
8
4
33554432
Note
In the first test case, the first 7
 elements of sequences 𝑎
 and 𝑏
 are as follows:

𝑎=[1,2,3,4,5,6,7,…]

𝑏=[0,3,2,5,4,7,6,…]

It can be shown that there isn't a positive integer 𝑘
 such that the sequence [𝑘,𝑘+1]
 occurs in 𝑏
 as a subsegment. So the answer is 1
.

In the third test case, the first 20
 elements of sequences 𝑎
 and 𝑏
 are as follows:

𝑎=[56,59,58,61,60,63,62,49,48,51,50,53,52,55,54,41, 40, 43, 42,45,…]

𝑏=[36,39,38,33,32,35,34,45,44,47,46,41, 40, 43, 42,53,52,55,54,49,…]

It can be shown that one of the longest common subsegments is the subsegment
[41,40,43,42] with a length of 4
.
*/

#include <iostream>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long x, y;
    std::cin >> x >> y;
    long z = x ^ y;
    long res = 1;
    while (z % 2 == 0) {
      res *= 2;
      z /= 2;
    }
    std::cout << res << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1979/326663625
