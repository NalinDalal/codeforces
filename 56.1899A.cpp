/* https://codeforces.com/problemset/problem/1899/A

A. Game with Integers
time limit per test1 second
memory limit per test256 megabytes
Vanya and Vova are playing a game. Players are given an integer 𝑛
. On their turn, the player can add 1
 to the current integer or subtract 1
. The players take turns; Vanya starts. If after Vanya's move the integer is
divisible by 3 , then he wins. If 10 moves have passed and Vanya has not won,
then Vova wins.

Write a program that, based on the integer 𝑛
, determines who will win if both players play optimally.

Input
The first line contains the integer 𝑡 (1≤𝑡≤100) — the number of test cases.
The single line of each test case contains the integer 𝑛 (1≤𝑛≤1000).

Output
For each test case, print "First" without quotes if Vanya wins, and "Second"
without quotes if Vova wins.

Example
InputCopy
6
1
3
5
100
999
1000
OutputCopy
First
Second
First
First
Second
First

*/
#include <iostream>
using namespace std;

// either add or subtract 1
// vanya starts, if n%3==0 then "First" else "Second"
// after 10 moves cout<<"Second"
// Track the number of moves

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t; // Number of test cases

  while (t--) {
    int n;
    cin >> n; // Starting integer

    int moves = 0;          // Number of moves
    bool vanya_turn = true; // Vanya starts

    while (moves < 10) {
      moves++;

      // Vanya's move
      if (vanya_turn) {
        if ((n + 1) % 3 == 0)
          n += 1;
        else
          n -= 1;

        if (n % 3 == 0) { // Check win condition
          cout << "First" << endl;
          break;
        }
      }
      // Vova's move
      else {
        if ((n + 1) % 3 == 0)
          n += 1;
        else
          n -= 1;

        if (n % 3 == 0) { // Check win condition
          cout << "Second" << endl;
          break;
        }
      }

      vanya_turn = !vanya_turn; // Switch turns
    }

    if (moves == 10) {
      cout << "Second" << endl; // Vova wins after 10 moves
    }
  }

  return 0;
}

// soln: https://codeforces.com/problemset/submission/1899/299507970
