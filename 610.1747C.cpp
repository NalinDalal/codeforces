/*C. Swap Game
time limit per test1 second
memory limit per test256 megabytes
Alice and Bob are playing a game on an array 𝑎
 of 𝑛
 positive integers. Alice and Bob make alternating moves with Alice going first.

In his/her turn, the player makes the following move:

If 𝑎1=0
, the player loses the game, otherwise:
Player chooses some 𝑖
 with 2≤𝑖≤𝑛
. Then player decreases the value of 𝑎1
 by 1
 and swaps 𝑎1
 with 𝑎𝑖
.
Determine the winner of the game if both players play optimally.

Input
The input consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤2⋅104) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤105)
  — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2…𝑎𝑛
 (1≤𝑎𝑖≤109)
  — the elements of the array 𝑎
.

It is guaranteed that sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, if Alice will win the game, output "Alice". Otherwise,
output "Bob".

You can output each letter in any case. For example, "alIcE", "Alice", "alice"
will all be considered identical.

Example
InputCopy
3
2
1 1
2
2 1
3
5 4 4
OutputCopy
Bob
Alice
Alice
Note
In the first testcase, in her turn, Alice can only choose 𝑖=2
, making the array equal [1,0]
. Then Bob, in his turn, will also choose 𝑖=2
 and make the array equal [0,0]
. As 𝑎1=0
, Alice loses.

In the second testcase, once again, players can only choose 𝑖=2
. Then the array will change as follows: [2,1]→[1,1]→[1,0]→[0,0]
, and Bob loses.

In the third testcase, we can show that Alice has a winning strategy.



*/

#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;

  while (t--) {
    long n;
    std::cin >> n;

    long a;
    std::cin >> a;

    bool res = false;
    for (long p = 1; p < n; p++) {
      long x;
      std::cin >> x;
      if (x < a) {
        res = true;
      }
    }

    std::cout << (res ? "Alice\n" : "Bob\n");
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1747/334457753
