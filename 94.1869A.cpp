/*
* https://codeforces.com/problemset/problem/1869/A

A. Make It Zero
time limit per test1 second
memory limit per test256 megabytes
During Zhongkao examination, Reycloer met an interesting problem, but he cannot
come up with a solution immediately. Time is running out! Please help him.

Initially, you are given an array 𝑎
 consisting of 𝑛≥2
 integers, and you want to change all elements in it to 0
.

In one operation, you select two indices 𝑙
 and 𝑟
 (1≤𝑙≤𝑟≤𝑛
) and do the following:

Let 𝑠=𝑎𝑙⊕𝑎𝑙+1⊕…⊕𝑎𝑟
, where ⊕
 denotes the bitwise XOR operation;
Then, for all 𝑙≤𝑖≤𝑟
, replace 𝑎𝑖
 with 𝑠
.
You can use the operation above in any order at most 8
 times in total.

Find a sequence of operations, such that after performing the operations in
order, all elements in 𝑎 are equal to 0 . It can be proven that the solution
always exists.

Input
The first line of input contains a single integer 𝑡
 (1≤𝑡≤500
) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤100
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤100
) — the elements of the array 𝑎
.

Output
For each test case, in the first line output a single integer 𝑘
 (0≤𝑘≤8
) — the number of operations you use.

Then print 𝑘
 lines, in the 𝑖
-th line output two integers 𝑙𝑖
 and 𝑟𝑖
 (1≤𝑙𝑖≤𝑟𝑖≤𝑛
) representing that you select 𝑙𝑖
 and 𝑟𝑖
 in the 𝑖
-th operation.

Note that you do not have to minimize 𝑘
. If there are multiple solutions, you may output any of them.

Example
InputCopy
6
4
1 2 3 0
8
3 1 4 1 5 9 2 6
6
1 5 4 1 4 7
5
0 0 0 0 0
7
1 1 9 9 0 1 8
3
100 100 0
OutputCopy
1
1 4
2
4 7
1 8
6
1 2
3 4
5 6
1 3
4 6
1 6
0
4
1 2
6 7
3 4
6 7
1
1 2
Note
In the first test case, since 1⊕2⊕3⊕0=0
, after performing the operation on segment [1,4]
, all the elements in the array are equal to 0
.

In the second test case, after the first operation, the array becomes equal to
[3,1,4,15,15,15,15,6] , after the second operation, the array becomes equal to
[0,0,0,0,0,0,0,0]
.

In the third test case:

Operation	𝑎
 before		𝑎
 after
1
[1,5⎯⎯⎯⎯⎯⎯,4,1,4,7]
→
[4,4,4,1,4,7]
2
[4,4,4,1⎯⎯⎯⎯⎯⎯,4,7]
→
[4,4,5,5,4,7]
3
[4,4,5,5,4,7⎯⎯⎯⎯⎯⎯]
→
[4,4,5,5,3,3]
4
[4,4,5⎯⎯⎯⎯⎯⎯⎯⎯⎯,5,3,3]
→
[5,5,5,5,3,3]
5
[5,5,5,5,3,3⎯⎯⎯⎯⎯⎯⎯⎯⎯]
→
[5,5,5,5,5,5]
6
[5,5,5,5,5,5⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯]
→
[0,0,0,0,0,0]
In the fourth test case, the initial array contains only 0
, so we do not need to perform any operations with it.


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    if (n % 2) {
      std::cout << "4\n";
      std::cout << "2 " << n << "\n";
      std::cout << "2 " << n << "\n";
      std::cout << "1 2\n";
      std::cout << "1 2\n";
    } else {
      std::cout << "2\n";
      std::cout << "1 " << n << "\n";
      std::cout << "1 " << n << "\n";
    }
  }
  return 0;
}
