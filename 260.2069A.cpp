/*A. Was there an Array?
time limit per test2 seconds
memory limit per test512 megabytes
For an array of integers 𝑎1,𝑎2,…,𝑎𝑛
, we define its equality characteristic as the array 𝑏2,𝑏3,…,𝑏𝑛−1
, where 𝑏𝑖=1
 if the 𝑖
-th element of the array 𝑎
 is equal to both of its neighbors, and 𝑏𝑖=0
 if the 𝑖
-th element of the array 𝑎
 is not equal to at least one of its neighbors.

For example, for the array [1,2,2,2,3,3,4,4,4,4]
, the equality characteristic will be [0,1,0,0,0,0,1,1]
.

You are given the array 𝑏2,𝑏3,…,𝑏𝑛−1
. Your task is to determine whether there exists such an array 𝑎
 for which the given array is the equality characteristic.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

Each test case consists of two lines:

the first line contains one integer 𝑛
 (3≤𝑛≤100
);
the second line contains 𝑛−2
 integers 𝑏2,𝑏3,…,𝑏𝑛−1
 (0≤𝑏𝑖≤1
).
Output
For each test case, output YES if the array 𝑎
 exists, or NO if such an array does not exist. Each letter can be printed in
any case.

Example
InputCopy
3
10
0 1 0 0 0 0 1 1
3
1
10
0 1 0 1 1 0 0 1
OutputCopy
YES
YES
NO
Note
In the first example, the array 𝑎=[1,2,2,2,3,3,4,4,4,4]
 is suitable.

In the second example, the array 𝑎=[7,7,7]
 is suitable.



*/

#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    int pprev = 0, prev = 0;
    bool possible = true;
    for (int p = 2; p < n; p++) {
      int x;
      std::cin >> x;
      if (pprev && !prev && x) {
        possible = false;
      }
      pprev = prev;
      prev = x;
    }

    std::cout << (possible ? "YES" : "NO") << std::endl;
  }

  // given b array; array a is also there
  // bi is 1 if ith element of a is equal to i-1, i+1
  // else bi is 0

  // tell if a exist or not

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2069/312069943
