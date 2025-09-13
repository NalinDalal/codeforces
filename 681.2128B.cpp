/*B. Deque Process
time limit per test1.5 seconds
memory limit per test256 megabytes

We say that an array 𝑎
 of size 𝑛
 is bad if and only if there exists 1≤𝑖≤𝑛−4
 such that one of the following conditions holds:

𝑎𝑖<𝑎𝑖+1<𝑎𝑖+2<𝑎𝑖+3<𝑎𝑖+4
𝑎𝑖>𝑎𝑖+1>𝑎𝑖+2>𝑎𝑖+3>𝑎𝑖+4
An array is good if and only if it's not bad. For example:

𝑎=[3,1,2,4,5,6]
 is bad because 𝑎2<𝑎3<𝑎4<𝑎5<𝑎6
.
𝑎=[7,6,5,4,1,2,3]
 is bad because 𝑎1>𝑎2>𝑎3>𝑎4>𝑎5
.
𝑎=[7,6,5,1,2,3,4]
 is good.
You're given a permutation∗
 𝑝1,𝑝2,…,𝑝𝑛
.

You must perform 𝑛
 turns. At each turn, you must remove either the leftmost or the rightmost
remaining element in 𝑝 . Let 𝑞𝑖 be the element removed at the 𝑖 -th turn.

Choose which element to remove at each turn so that the resulting array 𝑞
 is good. We can show that under the given constraints, it's always possible.

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
test cases 𝑡 (1≤𝑡≤10000
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (5≤𝑛≤100000
) — the length of the array.

The second line of each test case contains 𝑛
 integers 𝑝1,𝑝2,…,𝑝𝑛
 (1≤𝑝𝑖≤𝑛
, 𝑝𝑖
 are pairwise distinct) — elements of the permutation.

It is guaranteed that the sum of 𝑛
 over all test cases doesn't exceed 200000
.

Output
For each test case, you must output a string 𝑠
 of length 𝑛
. For every 1≤𝑖≤𝑛
, at the 𝑖
-th turn:

𝑠𝑖=𝙻
 means that you removed the leftmost element of 𝑝
𝑠𝑖=𝚁
 means that you removed the rightmost element of 𝑝
We can show that an answer always exists. If there are multiple solutions, print
any of them.

Example
InputCopy
6
7
1 2 3 4 5 6 7
9
1 3 6 8 9 7 5 4 2
12
1 2 11 3 6 4 7 8 12 5 10 9
6
4 1 2 5 6 3
5
1 2 3 5 4
9
5 1 8 6 2 7 9 4 3
OutputCopy
RRRLLLL
LLRRLLRRL
LLLLLLLLLLLL
LLLLLL
LLLLL
LLLLLLLLL
Note
In the first test case, the sequence 𝚁𝚁𝚁𝙻𝙻𝙻𝙻
 results in 𝑞=[7,6,5,1,2,3,4]
.

In the second test case, the sequence 𝙻𝙻𝚁𝚁𝙻𝙻𝚁𝚁𝙻
 results in 𝑞=[1,3,2,4,6,8,5,7,9]
.
*/

/*condition for bad:
 1<=i<=n-4
 a[i]<a[i+1]<a[i+2]<a[i+3]<a[i+4]
 or
 a[i]>a[i+1]>a[i+2]>a[i+3]>a[i+4]

 array is good only if it is not bad

 given a array p, n turns
 at each turn remove either 0th or last element,
 push to new array q, q must be good

 (t--){
 n;cin>>n;
 cin>>permutation(n);

 string ans="";
 Check if p is good.

if ( (i % 2 == 0) == (v[i] < v[n - 1 - i]) )
    cout << "LR";
else
    cout << "RL";


By problem statement, at least one is guaranteed to be good.

 }
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    for (int i = 0; i < n / 2; i++) {
      if ((i % 2 == 0) == (v[i] < v[n - 1 - i])) {
        cout << "LR";
      } else {
        cout << "RL";
      }
    }

    if (n % 2)
      cout << "L";
    cout << "\n";
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/2128/338286303
