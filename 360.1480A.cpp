/* A. Yet Another String Game
time limit per test2 seconds
memory limit per test512 megabytes
Homer has two friends Alice and Bob. Both of them are string fans.

One day, Alice and Bob decide to play a game on a string 𝑠=𝑠1𝑠2…𝑠𝑛
 of length 𝑛
 consisting of lowercase English letters. They move in turns alternatively and
Alice makes the first move.

In a move, a player must choose an index 𝑖
 (1≤𝑖≤𝑛
) that has not been chosen before, and change 𝑠𝑖
 to any other lowercase English letter 𝑐
 that 𝑐≠𝑠𝑖
.

When all indices have been chosen, the game ends.

The goal of Alice is to make the final string lexicographically as small as
possible, while the goal of Bob is to make the final string lexicographically as
large as possible. Both of them are game experts, so they always play games
optimally. Homer is not a game expert, so he wonders what the final string will
be.

A string 𝑎
 is lexicographically smaller than a string 𝑏
 if and only if one of the following holds:

𝑎
 is a prefix of 𝑏
, but 𝑎≠𝑏
;
in the first position where 𝑎
 and 𝑏
 differ, the string 𝑎
 has a letter that appears earlier in the alphabet than the corresponding letter
in 𝑏
.
Input
Each test contains multiple test cases. The first line contains 𝑡
 (1≤𝑡≤1000
)  — the number of test cases. Description of the test cases follows.

The only line of each test case contains a single string 𝑠
 (1≤|𝑠|≤50
) consisting of lowercase English letters.

Output
For each test case, print the final string in a single line.

Example
InputCopy
3
a
bbbb
az
OutputCopy
b
azaz
by
Note
In the first test case: Alice makes the first move and must change the only
letter to a different one, so she changes it to 'b'.

In the second test case: Alice changes the first letter to 'a', then Bob changes
the second letter to 'z', Alice changes the third letter to 'a' and then Bob
changes the fourth letter to 'z'.

In the third test case: Alice changes the first letter to 'b', and then Bob
changes the second letter to 'y'.


*/
#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    for (int p = 0; p < s.size(); p++) {
      if (p % 2) {
        s[p] = (s[p] != 'z' ? 'z' : 'y');
      } else {
        s[p] = (s[p] != 'a' ? 'a' : 'b');
      }
    }
    cout << s << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1480/320501686
