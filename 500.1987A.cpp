/*A. Upload More RAM
time limit per test1 second
memory limit per test256 megabytes
Oh no, the ForceCodes servers are running out of memory! Luckily, you can help
them out by uploading some of your RAM!

You want to upload 𝑛
 GBs of RAM. Every second, you will upload either 0
 or 1
 GB of RAM. However, there is a restriction on your network speed: in any 𝑘
 consecutive seconds, you can upload only at most 1
 GB of RAM in total.

Find the minimum number of seconds needed to upload 𝑛
 GBs of RAM!

Input
Each test contains multiple test cases. The first line of input contains a
single integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the
test cases follows.

The first and only line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛,𝑘≤100
) — the number of GBs that you want to upload and the length of the time window
respectively.

Output
For each test case, output a single integer — the minimum number of seconds
needed to upload 𝑛 GBs of RAM.

Example
InputCopy
6
5 1
2 2
2 3
1 7
11 5
100 100
OutputCopy
5
3
4
1
51
9901
Note
In the first test case, you can upload 1
 GB of RAM per second, so to upload 5
 GBs, you need 5
 seconds.

In the second test case, you can upload 1
 GB in the first second, 0
 GBs in the second second, and 1
 GB in the third second, which in total adds up to exactly 2
 GBs of uploaded RAM.

In the third test case, you can upload 1
 GB in the first second, 0
 GBs in the second second, 0
 GBs in the third second, and 1
 GB in the fourth second, which in total adds up to exactly 2
 GBs of uploaded RAM.



*/

#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, k;
    std::cin >> n >> k;
    std::cout << (n - 1) * k + 1 << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1987/328938939
