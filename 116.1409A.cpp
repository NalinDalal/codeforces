/* https://codeforces.com/problemset/problem/1409/A


A. Yet Another Two Integers Problem
time limit per test1 second
memory limit per test256 megabytes
You are given two integers 𝑎 and 𝑏.

In one move, you can choose some integer 𝑘 from 1 to 10 and add it to 𝑎 or
subtract it from 𝑎. In other words, you choose an integer 𝑘∈[1;10] and perform
𝑎:=𝑎+𝑘 or 𝑎:=𝑎−𝑘. You may use different values of 𝑘 in different moves.Your task
is to find the minimum number of moves required to obtain 𝑏 from 𝑎.

You have to answer 𝑡 independent test cases.

Input
The first line of the input contains one integer 𝑡 (1≤𝑡≤2⋅104) — the number of
test cases. Then 𝑡 test cases follow.

The only line of the test case contains two integers 𝑎 and 𝑏 (1≤𝑎,𝑏≤109).

Output
For each test case, print the answer: the minimum number of moves required to
obtain 𝑏 from 𝑎.

Example
InputCopy
6
5 5
13 42
18 4
1337 420
123456789 1000000000
100500 9000
OutputCopy
0
3
2
92
87654322
9150
Note

In the first test case of the example, you don't need to do anything.
In the second test case of the example, the following sequence of moves can be
applied: 13→23→32→42 (add 10, add 9, add 10). In the third test case of the
example, the following sequence of moves can be applied: 18→10→4 (subtract 8,
subtract 6).
*/

#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  const int n = 10;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int diff = a - b;
    if (diff < 0) {
      diff = -diff;
    }
    int ans = (diff + n - 1) / n;
    cout << ans << endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1409/304749834
