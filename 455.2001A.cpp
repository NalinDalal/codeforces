/*A. Make All Equal
time limit per test1 second
memory limit per test256 megabytes
You are given a cyclic array 𝑎1,𝑎2,…,𝑎𝑛
.

You can perform the following operation on 𝑎
 at most 𝑛−1
 times:

Let 𝑚
 be the current size of 𝑎
, you can choose any two adjacent elements where the previous one is no greater than the latter one (In particular, 𝑎𝑚
 and 𝑎1
 are adjacent and 𝑎𝑚
 is the previous one), and delete exactly one of them. In other words, choose an integer 𝑖
 (1≤𝑖≤𝑚
) where 𝑎𝑖≤𝑎(𝑖mod𝑚)+1
 holds, and delete exactly one of 𝑎𝑖
 or 𝑎(𝑖mod𝑚)+1
 from 𝑎
.
Your goal is to find the minimum number of operations needed to make all elements in 𝑎
 equal.

Input
Each test contains multiple test cases. The first line contains the number of test cases 𝑡
 (1≤𝑡≤500
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤100
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
) — the elements of array 𝑎
.

Output
For each test case, output a single line containing an integer: the minimum number of operations needed to make all elements in 𝑎
 equal.

Example
InputCopy
7
1
1
3
1 2 3
3
1 2 2
5
5 4 3 2 1
6
1 1 2 2 3 3
8
8 7 6 3 8 7 6 3
6
1 1 4 5 1 4
OutputCopy
0
2
1
4
4
6
3
Note
In the first test case, there is only one element in 𝑎
, so we can't do any operation.

In the second test case, we can perform the following operations to make all elements in 𝑎
 equal:

choose 𝑖=2
, delete 𝑎3
, then 𝑎
 would become [1,2]
.
choose 𝑖=1
, delete 𝑎1
, then 𝑎
 would become [2]
.
It can be proven that we can't make all elements in 𝑎
 equal using fewer than 2
 operations, so the answer is 2
.



*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long t;
    std::cin >> t;
    while (t--) {
        long n;
        std::cin >> n;
        std::vector<long> f(n + 1, 0);
        for (long p = 0; p < n; ++p) {
            long x;
            std::cin >> x;
            ++f[x];
        }
        long mxf = *std::max_element(f.begin(), f.end());
        std::cout << (n - mxf) << '\n';
    }
}
//sub:https://codeforces.com/problemset/submission/2001/326439253
