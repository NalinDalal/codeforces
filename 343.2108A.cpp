/* A. Permutation Warm-Up
time limit per test1 second
memory limit per test256 megabytes

For a permutation 𝑝
 of length 𝑛
∗
, we define the function:

𝑓(𝑝)=∑𝑖=1𝑛|𝑝𝑖−𝑖|

You are given a number 𝑛
. You need to compute how many distinct values the function 𝑓(𝑝)
 can take when considering all possible permutations of the numbers from 1
 to 𝑛
.

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
test cases 𝑡 (1≤𝑡≤100
). The description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤500
) — the number of numbers in the permutations.

Output
For each test case, output a single integer — the number of distinct values of
the function 𝑓(𝑝) for the given length of permutations.

Example
InputCopy
5
2
3
8
15
43
OutputCopy
2
3
17
57
463
Note
Consider the first two examples of the input.

For 𝑛=2
, there are only 2
 permutations — [1,2]
 and [2,1]
. 𝑓([1,2])=|1−1|+|2−2|=0
, 𝑓([2,1])=|2−1|+|1−2|=1+1=2
. Thus, the function takes 2
 distinct values.

For 𝑛=3
, there are already 6
 permutations: [1,2,3]
, [1,3,2]
, [2,1,3]
, [2,3,1]
, [3,1,2]
, [3,2,1]
, the function values of which will be 0,2,2,4,4
, and 4
 respectively, meaning there are a total of 3
 values.


*/

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (1 + (long long)n * n / 4) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2108/319472231
