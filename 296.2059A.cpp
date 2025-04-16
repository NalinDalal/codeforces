/* A. Milya and Two Arrays
time limit per test1 second
memory limit per test256 megabytes
An array is called good if for any element 𝑥
 that appears in this array, it holds that 𝑥
 appears at least twice in this array. For example, the arrays [1,2,1,1,2]
, [3,3]
, and [1,2,4,1,2,4]
 are good, while the arrays [1]
, [1,2,1]
, and [2,3,4,4]
 are not good.

Milya has two good arrays 𝑎
 and 𝑏
 of length 𝑛
. She can rearrange the elements in array 𝑎
 in any way. After that, she obtains an array 𝑐
 of length 𝑛
, where 𝑐𝑖=𝑎𝑖+𝑏𝑖
 (1≤𝑖≤𝑛
).

Determine whether Milya can rearrange the elements in array 𝑎
 such that there are at least 3
 distinct elements in array 𝑐
.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤1000 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains a single integer 𝑛
 (3≤𝑛≤50
) — the length of the arrays 𝑎
 and 𝑏
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the elements of the array 𝑎
.

The third line of each test case contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤109
) — the elements of the array 𝑏
.

Output
For each test case, output «
YES»
 (without quotes) if it is possible to obtain at least 3
 distinct elements in array 𝑐
, and «
NO»
 otherwise.

You can output each letter in any case (for example, «
YES»
, «
Yes»
, «
yes»
, «
yEs»
 will be recognized as a positive answer).

Example
InputCopy
5
4
1 2 1 2
1 2 1 2
6
1 2 3 3 2 1
1 1 1 1 1 1
3
1 1 1
1 1 1
6
1 52 52 3 1 3
59 4 3 59 3 4
4
100 1 100 1
2 2 2 2
OutputCopy
YES
YES
NO
YES
NO
Note
In the first test case, you can swap the second and third elements. Then the
array 𝑎=[1,1,2,2] , 𝑏=[1,2,1,2] , and then 𝑐=[2,3,3,4]
.

In the second test case, you can leave the elements unchanged. Then
𝑐=[2,3,4,4,3,2]
.

In the third test case, the array 𝑎
 will not change from rearranging the elements in it. Then 𝑐=[2,2,2]
, so the answer is «
NO»
.

*/

#include <iostream>
#include <set>
using namespace std;
// since all elements are appearing twice, hence the length is always even
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    std::set<int> a, b;
    for (int p = 0; p < n; p++) {
      long x;
      cin >> x;

      a.insert(x);
    }
    for (int p = 0; p < n; p++) {
      long x;
      cin >> x;
      b.insert(x);
    }
    cout << (a.size() * b.size() >= 3 ? "YES" : "NO") << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2059/315788697
