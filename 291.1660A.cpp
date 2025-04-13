/* A. Vasya and Coins
time limit per test1 second
memory limit per test256 megabytes
Vasya decided to go to the grocery store. He found in his wallet 𝑎
 coins of 1
 burle and 𝑏
 coins of 2
 burles. He does not yet know the total cost of all goods, so help him find out
𝑠 (𝑠>0
): the minimum positive integer amount of money he cannot pay without change or
pay at all using only his coins.

For example, if 𝑎=1
 and 𝑏=1
 (he has one 1
-burle coin and one 2
-burle coin), then:

he can pay 1
 burle without change, paying with one 1
-burle coin,
he can pay 2
 burle without change, paying with one 2
-burle coin,
he can pay 3
 burle without change by paying with one 1
-burle coin and one 2
-burle coin,
he cannot pay 4
 burle without change (moreover, he cannot pay this amount at all).
So for 𝑎=1
 and 𝑏=1
 the answer is 𝑠=4
.

Input
The first line of the input contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases in the test.

The description of each test case consists of one line containing two integers
𝑎𝑖 and 𝑏𝑖 (0≤𝑎𝑖,𝑏𝑖≤108 ) — the number of 1 -burle coins and 2 -burles coins
Vasya has respectively.

Output
For each test case, on a separate line print one integer 𝑠
 (𝑠>0
): the minimum positive integer amount of money that Vasya cannot pay without
change or pay at all.

Example
InputCopy
5
1 1
4 0
0 2
0 0
2314 2374
OutputCopy
4
5
1
1
7063
Note
The first test case of the example is clarified into the main part of the
statement. In the second test case, Vasya has only 1 burle coins, and he can
collect either any amount from 1 to 4 , but 5 can't. In the second test case,
Vasya has only 2 burle coins, and he cannot pay 1 burle without change. In the
fourth test case you don't have any coins, and he can't even pay 1 burle.

*/

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    // the minimum positive integer amount of money that Vasya cannot pay
    // without change or pay at all.
    // so if say a=0 || b=0, then return 1
    // else return a+2*b+1
    cout << ((a ? (a + 2 * b) : 0) + 1) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1660/315296647
