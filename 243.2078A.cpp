/*A. Final Verdict
time limit per test1 second
memory limit per test256 megabytes
Testify - void (Mournfinale) feat. 星熊南巫
You are given an array 𝑎
 of length 𝑛
, and must perform the following operation until the length of 𝑎
 becomes 1
.

Choose a positive integer 𝑘<|𝑎|
 such that |𝑎|𝑘
 is an integer. Split 𝑎
 into 𝑘
 subsequences∗
 𝑠1,𝑠2,…,𝑠𝑘
 such that:

Each element of 𝑎
 belongs to exactly one subsequence.
The length of every subsequence is equal.
After this, replace 𝑎=[avg(𝑠1),avg(𝑠2),…,avg(𝑠𝑘)]
, where avg(𝑠)=∑|𝑠|𝑖=1𝑠𝑖|𝑠|
 is the average of all the values in the subsequence. For example,
avg([1,2,1,1])=54=1.25
.

Your task is to determine whether there exists a sequence of operations such
that after all operations, 𝑎=[𝑥]
.

∗
A sequence 𝑥
 is a subsequence of a sequence 𝑦
 if 𝑥
 can be obtained from 𝑦
 by the deletion of several (possibly, zero or all) elements.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
, 𝑥
 (1≤𝑛,𝑥≤100
) — the length of the array 𝑎
 and the final desired value.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤100
) — the array 𝑎
.

Output
For each test case, output "YES'" (without quotes) if there exists such a
sequence of operations, and "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yES", "yes" and
"Yes" will be recognized as a positive response).

Example
InputCopy
4
1 3
3
4 9
7 11 2 5
6 9
1 9 14 12 10 8
10 10
10 10 10 10 10 10 10 10 10 10
OutputCopy
YES
NO
YES
YES
Note
In the first test case, 𝑥=3
 and 𝑎=[3]
 already holds.

In the second test case, 𝑥=9
, and there exists no sequence of operations such that after all operations,
𝑎=[9]
.

In the third test case, 𝑥=9
, and here is one possible sequence of operations.

𝑘=2
, 𝑠1=[1,12,8]
 and 𝑠2=[9,14,10]
. Hence, 𝑎=[avg(𝑠1),avg(𝑠2)]=[7,11]
.
𝑘=1
 and 𝑠1=[7,11]
. Hence, 𝑎=[avg(𝑠1)]=[9]
.
In the fourth test case, 𝑥=10
, and here is one possible sequence of operations.

𝑘=1
 and 𝑠1=[10,10,10,10,10,10,10,10,10,10]
. Hence, 𝑎=[avg(𝑠1)]=[10]
.


*/

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {

    int n, x;
    cin >> n >> x;
    int sum = 0;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      sum += x;
    }
    cout << (sum == n * x ? "YES" : "NO") << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2078/311372717
