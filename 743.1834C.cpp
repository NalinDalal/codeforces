/*C. Game with Reversing
time limit per test1 second
memory limit per test256 megabytes
Alice and Bob are playing a game. They have two strings 𝑆
 and 𝑇
 of the same length 𝑛
 consisting of lowercase latin letters. Players take turns alternately, with
Alice going first.

On her turn, Alice chooses an integer 𝑖
 from 1
 to 𝑛
, one of the strings 𝑆
 or 𝑇
, and any lowercase latin letter 𝑐
, and replaces the 𝑖
-th symbol in the chosen string with the character 𝑐
.

On his turn, Bob chooses one of the strings 𝑆
 or 𝑇
, and reverses it. More formally, Bob makes the replacement 𝑆:=rev(𝑆)
 or 𝑇:=rev(𝑇)
, where rev(𝑃)=𝑃𝑛𝑃𝑛−1…𝑃1
.

The game lasts until the strings 𝑆
 and 𝑇
 are equal. As soon as the strings become equal, the game ends instantly.

Define the duration of the game as the total number of moves made by both
players during the game. For example, if Alice made 2 moves in total, and Bob
made 1 move, then the duration of this game is 3
.

Alice's goal is to minimize the duration of the game, and Bob's goal is to
maximize the duration of the game.

What will be the duration of the game, if both players play optimally? It can be
shown that the game will end in a finite number of turns.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤105
) — the length of the strings 𝑆
 and 𝑇
.

The second line of each test case contains a string 𝑆
 of length 𝑛
 consisting of lowercase latin letters.

The third line of each test case contains a string 𝑇
 of length 𝑛
 consisting of lowercase latin letters.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output a single number on a separate line — the duration of
the described game, if both players play optimally.

Example
InputCopy
7
5
abcde
abxde
5
hello
olleo
2
ab
cd
7
aaaaaaa
abbbbba
1
q
q
6
yoyoyo
oyoyoy
8
abcdefgh
hguedfbh
OutputCopy
1
2
3
9
0
2
6
Note
In the first test case, in her turn, Alice can replace the third symbol of the
string 𝑆 with x. After that, both strings will become equal to "abxde" and the
game will end after one move. Since Alice's goal is to finish the game in as few
moves as possible, this move will be one of her optimal first moves, and the
final answer will be 1
.

In the second test case, in her turn, Alice can replace the fifth symbol of the
string 𝑇 with h. After this move, 𝑆= "hello", 𝑇= "olleh". Then Bob makes his
turn. In his turn, he must reverse one of the strings. If Bob chooses the string
𝑆 , then after his turn both strings will be equal to "olleh", and if he chooses
the string 𝑇 , then after his turn both strings will be equal to "hello". Thus,
after the presented first move of Alice, the game will definitely end in 2
 moves. It can be shown that there is no strategy for Alice to finish the game
in less than 2 moves, with both players playing optimally. The final answer is 2
.

In the third test case, in her first move, Alice can replace the second symbol
of the string 𝑆 with c. After this move, 𝑆= "ac", 𝑇= "cd". Then Bob makes his
turn. If Bob reverses the string 𝑆 , then after his turn 𝑆= "ca", 𝑇= "cd". Then
it is easy to see that in this case Alice can definitely finish the game on the
3 -rd move, by replacing the second symbol of the string 𝑇 with a, after which
both strings will become equal to "ca". If Bob reverses the string 𝑇 , then
after his turn 𝑆= "ac", 𝑇= "dc". In this case, Alice can also definitely finish
the game on the 3 rd move, by replacing the first symbol of the string 𝑆 with d,
after which both strings will become equal to "dc". Thus, Alice can definitely
finish the game in 3 moves regardless of Bob's moves. It can be shown that the
game cannot end in less than 3 moves, with both players playing optimally.

In the fifth test case, the strings 𝑆
 and 𝑇
 are equal, so the game will end without starting, in 0
 moves.
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1;
    string s2;
    cin >> s1 >> s2;
    string a = s1;
    string b = s2;
    reverse(a.begin(), a.end());
    int cnt1 = 0;
    int cnt2 = 0;
    int j = n;
    while (j--) {
      if (s1[j] != s2[j]) {
        cnt1++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[i] != s2[i]) {
        cnt2++;
      }
    }
    string str = b;
    int ans = 2 * cnt1 - 1;
    if (cnt1 <= 1) {
      cout << cnt1 << endl;
      continue;
    }
    if (cnt2 == 0) {
      cout << 2 << endl;
      continue;
    } else {

      reverse(b.begin(), b.end());
      if (cnt1 % 2 == 0) {
        if (str == b) {

        } else {
          ans++;
        }
      }
      int cnt = 2 * cnt2 - 1;
      if (cnt2 % 2) {
        if (str == b) {

        } else {
          cnt++;
        }
      }
      ans = min(ans, cnt);
    }
    cout << ans << endl;
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1834/341852108
