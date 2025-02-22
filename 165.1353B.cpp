/* B. Two Arrays And Swaps
time limit per test1 second
memory limit per test256 megabytes
You are given two arrays 𝑎
 and 𝑏
 both consisting of 𝑛
 positive (greater than zero) integers. You are also given an integer 𝑘
.

In one move, you can choose two indices 𝑖
 and 𝑗
 (1≤𝑖,𝑗≤𝑛
) and swap 𝑎𝑖
 and 𝑏𝑗
 (i.e. 𝑎𝑖
 becomes 𝑏𝑗
 and vice versa). Note that 𝑖
 and 𝑗
 can be equal or different (in particular, swap 𝑎2
 with 𝑏2
 or swap 𝑎3
 and 𝑏9
 both are acceptable moves).

Your task is to find the maximum possible sum you can obtain in the array 𝑎
 if you can do no more than (i.e. at most) 𝑘
 such moves (swaps).

You have to answer 𝑡
 independent test cases.

Input
The first line of the input contains one integer 𝑡
 (1≤𝑡≤200
) — the number of test cases. Then 𝑡
 test cases follow.

The first line of the test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤30;0≤𝑘≤𝑛
) — the number of elements in 𝑎
 and 𝑏
 and the maximum number of moves you can do. The second line of the test case
contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤30
), where 𝑎𝑖
 is the 𝑖
-th element of 𝑎
. The third line of the test case contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤30
), where 𝑏𝑖
 is the 𝑖
-th element of 𝑏
.

Output
For each test case, print the answer — the maximum possible sum you can obtain
in the array 𝑎 if you can do no more than (i.e. at most) 𝑘 swaps.

Example
InputCopy
5
2 1
1 2
3 4
5 5
5 5 6 6 5
1 2 5 4 3
5 3
1 2 3 4 5
10 9 10 10 9
4 0
2 2 4 3
2 4 2 3
4 4
1 2 2 1
4 4 5 4
OutputCopy
6
27
39
11
17
Note
In the first test case of the example, you can swap 𝑎1=1
 and 𝑏2=4
, so 𝑎=[4,2]
 and 𝑏=[3,1]
.

In the second test case of the example, you don't need to swap anything.

In the third test case of the example, you can swap 𝑎1=1
 and 𝑏1=10
, 𝑎3=3
 and 𝑏3=10
 and 𝑎2=2
 and 𝑏4=10
, so 𝑎=[10,10,10,4,5]
 and 𝑏=[1,9,3,2,9]
.

In the fourth test case of the example, you cannot swap anything.

In the fifth test case of the example, you can swap arrays 𝑎
 and 𝑏
, so 𝑎=[4,4,5,4]
 and 𝑏=[1,2,2,1]
.



*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += (i < k && b[i] > a[i]) ? b[i] : a[i];
    }
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1353/307323753
