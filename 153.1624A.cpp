/* A. Plus One on the Subset
time limit per test2 seconds
memory limit per test256 megabytes
Polycarp got an array of integers 𝑎[1…𝑛] as a gift. Now he wants to perform a
certain number of operations (possibly zero) so that all elements of the array
become the same (that is, to become 𝑎1=𝑎2=⋯=𝑎𝑛).

In one operation, he can take some indices in the array and increase the
elements of the array at those indices by 1. For example, let 𝑎=[4,2,1,6,2]. He
can perform the following operation: select indices 1, 2, and 4 and increase
elements of the array in those indices by 1. As a result, in one operation, he
can get a new state of the array 𝑎=[5,3,1,7,2].

What is the minimum number of operations it can take so that all elements of the
array become equal to each other (that is, to become 𝑎1=𝑎2=⋯=𝑎𝑛)?

Input
The first line of the input contains a single integer 𝑡 (1≤𝑡≤104)  — the number
of test cases in the test.

The following are descriptions of the input test cases.

The first line of the description of each test case contains one integer 𝑛
(1≤𝑛≤50)  — the array 𝑎.

The second line of the description of each test case contains 𝑛 integers
𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109)  — elements of the array 𝑎.

Output
For each test case, print one integer  — the minimum number of operations to
make all elements of the array 𝑎 equal.

Example
InputCopy
3
6
3 4 2 4 1 2
3
1000 1002 998
2
12 11
OutputCopy
3
4
1
Note
First test case:

𝑎=[3,4,2,4,1,2] take 𝑎3,𝑎5 and perform an operation plus one on them, as a
result we get 𝑎=[3,4,3,4,2,2]. 𝑎=[3,4,3,4,2,2] we take 𝑎1,𝑎5,𝑎6 and perform an
operation on them plus one, as a result we get 𝑎=[4,4,3,4,3,3]. 𝑎=[4,4,3,4,3,3]
we take 𝑎3,𝑎5,𝑎6 and perform an operation on them plus one, as a result we get
𝑎=[4,4,4,4,4,4]. There are other sequences of 3 operations, after the
application of which all elements become equal.

Second test case:

𝑎=[1000,1002,998] 2 times we take 𝑎1,𝑎3 and perform an operation plus one on
them, as a result we get 𝑎=[1002,1002,1000]. 𝑎=[1002,1002,1000] also take 𝑎3 2
times and perform an operation plus one on it, as a result we get
𝑎=[1002,1002,1002]. Third test case:

𝑎=[12,11] take 𝑎2 and perform an operation plus one on it, as a result we get
𝑎=[12,12].

*/

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int minVal = INT_MAX, maxVal = INT_MIN;

    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      maxVal = max(maxVal, x);
      minVal = min(minVal, x);
    }
    // find difference b/w max and min of array
    cout << (maxVal - minVal) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1624/306904389
