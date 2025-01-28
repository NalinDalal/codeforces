/* https://codeforces.com/problemset/problem/1794/B
B. Not Dividing
time limit per test2 seconds
memory limit per test256 megabytes
You are given an array of 𝑛 positive integers 𝑎1,𝑎2,…,𝑎𝑛. In one operation, you
can choose any number of the array and add 1 to it.

Make at most 2𝑛 operations so that the array satisfies the following property:
𝑎𝑖+1 is not divisible by 𝑎𝑖, for each 𝑖=1,2,…,𝑛−1.

You do not need to minimize the number of operations.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104). The description of the test cases follows.

The first line of each test case contains an integer 𝑛 (1≤𝑛≤104) — the length of
the given array.

The second line of each test case contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109) —
the given array.

It is guaranteed that the sum of 𝑛 over all test cases does not exceed 5⋅104.

Output
For each test case, print the answer on a separate line.

In the only line, print 𝑛 integers — the resulting array 𝑎 after applying at
most 2𝑛 operations.

We can show that an answer always exists under the given constraints. If there
are multiple answers, print any of them.

Example
InputCopy
3
4
2 4 3 6
3
1 2 3
2
4 2
OutputCopy
4 5 6 7
3 2 3
4 2
Note
In the first test case, the array [4,5,6,7] can be achieved by applying 2
operations to the first element, 1 operation to the second element, 3 operations
to the third element, and 1 operation to the last element. The total number of
operations performed is 7, which is less than the allowed 8 operations in this
case.

In the second test case, the array [3,2,3] can be achieved by applying two
operations to the first element. Another possible resulting array could be
[2,3,5] , because the total number of operations does not need to be minimum.

In the third test case, not applying any operations results in an array that
satisfies the statement's property. Observe that it is not mandatory to make
operations.*/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1) {
        a[i] = 2;
      }
      if (i && a[i] % a[i - 1] == 0) {
        ++a[i];
      }
    }

    for (long p = 0; p < n; p++) {
      cout << a[p] << " ";
    }
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1794/303272710
