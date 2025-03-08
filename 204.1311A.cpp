/*A. Add Odd or Subtract Even
time limit per test2 seconds
memory limit per test256 megabytes
You are given two positive integers 𝑎
 and 𝑏
.

In one move, you can change 𝑎
 in the following way:

Choose any positive odd integer 𝑥
 (𝑥>0
) and replace 𝑎
 with 𝑎+𝑥
;
choose any positive even integer 𝑦
 (𝑦>0
) and replace 𝑎
 with 𝑎−𝑦
.
You can perform as many such operations as you want. You can choose the same
numbers 𝑥 and 𝑦 in different moves.

Your task is to find the minimum number of moves required to obtain 𝑏
 from 𝑎
. It is guaranteed that you can always obtain 𝑏
 from 𝑎
.

You have to answer 𝑡
 independent test cases.

Input
The first line of the input contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Then 𝑡
 test cases follow. Each test case is given as two space-separated integers 𝑎
 and 𝑏
 (1≤𝑎,𝑏≤109
).

Output
For each test case, print the answer — the minimum number of moves required to
obtain 𝑏 from 𝑎 if you can perform any number of moves described in the problem
statement. It is guaranteed that you can always obtain 𝑏 from 𝑎
.

Example
InputCopy
5
2 3
10 10
2 4
7 4
9 3
OutputCopy
1
0
2
2
1
Note
In the first test case, you can just add 1
.

In the second test case, you don't need to do anything.

In the third test case, you can add 1
 two times.

In the fourth test case, you can subtract 4
 and add 1
.

In the fifth test case, you can just subtract 6
.



*/
#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a == b) {
      cout << "0" << endl;
    } else if ((b > a) && ((b - a) % 2 == 1)) {
      cout << "1" << endl;
    } else if ((b > a) && ((b - a) % 2 == 0)) {
      cout << "2" << endl;
    } else if ((a > b) && ((a - b) % 2 == 0)) {
      cout << "1" << endl;
    } else if ((a > b) && ((a - b) % 2 == 1)) {
      cout << "2" << endl;
    }
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1311/309487038
