/* https://codeforces.com/problemset/problem/1665/B
B. Array Cloning Technique
time limit per test1 second
memory limit per test256 megabytes
You are given an array 𝑎
 of 𝑛
 integers. Initially there is only one copy of the given array.

You can do operations of two types:

Choose any array and clone it. After that there is one more copy of the chosen
array. Swap two elements from any two copies (maybe in the same copy) on any
positions. You need to find the minimal number of operations needed to obtain a
copy where all elements are equal.

Input
The input consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. Description of the test cases
follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤105
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (−109≤𝑎𝑖≤109
) — the elements of the array 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case output a single integer — the minimal number of operations
needed to create at least one copy where all elements are equal.

Example
InputCopy
6
1
1789
6
0 1 3 3 7 0
2
-1000000000 1000000000
4
4 3 2 1
5
2 5 7 6 3
7
1 1 1 1 1 1 1
OutputCopy
0
6
2
5
7
0
Note
In the first test case all elements in the array are already equal, that's why
the answer is 0
.

In the second test case it is possible to create a copy of the given array.
After that there will be two identical arrays:

[ 0 1 3 3 7 0 ]
 and [ 0 1 3 3 7 0 ]

After that we can swap elements in a way so all zeroes are in one array:

[ 0 0⎯⎯ 0⎯⎯ 3 7 0 ]
 and [ 1⎯⎯ 1 3 3 7 3⎯⎯ ]

Now let's create a copy of the first array:

[ 0 0 0 3 7 0 ]
, [ 0 0 0 3 7 0 ]
 and [ 1 1 3 3 7 3 ]

Let's swap elements in the first two copies:

[ 0 0 0 0⎯⎯ 0⎯⎯ 0 ]
, [ 3⎯⎯ 7⎯⎯ 0 3 7 0 ]
 and [ 1 1 3 3 7 3 ]
.

Finally, we made a copy where all elements are equal and made 6
 operations.

It can be proven that no fewer operations are enough.



*/

#include <iostream>
#include <map>
#include <vector>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> m;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      ++m[a[i]];
      cnt = std::max(cnt, m[a[i]]);
    }

    int res = 0;
    while (cnt < n) {
      int diff = std::min(cnt, n - cnt);
      res += 1 + diff;
      cnt *= 2;
    }
    std::cout << res << std::endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1665/303947704
