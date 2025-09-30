/*C. Card Game
time limit per test2 seconds
memory limit per test512 megabytes
Alice and Bob are playing a game. They have 𝑛
 cards numbered from 1
 to 𝑛
. At the beginning of the game, some of these cards are given to Alice, and the
rest are given to Bob.

Card with number 𝑖
 beats card with number 𝑗
 if and only if 𝑖>𝑗
, with one exception: card 1
 beats card 𝑛
.

The game continues as long as each player has at least one card. During each
turn, the following occurs:

Alice chooses one of her cards and places it face up on the table;
Bob, seeing Alice's card, chooses one of his cards and places it face up on the
table; if Alice's card beats Bob's card, both cards are taken by Alice.
Otherwise, both cards are taken by Bob. A player can use a card that they have
taken during one of the previous turns.

The player who has no cards at the beginning of a turn loses. Determine who will
win if both players play optimally.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤5000
) — the number of test cases.

Each test case consists of two lines:

the first line contains a single integer 𝑛
 (2≤𝑛≤50
) — the number of cards;
the second line contains 𝑛
 characters, each either A or B. If the 𝑖
-th character is A, then card number 𝑖
 is initially given to Alice; otherwise, it is given to Bob.
Additional constraint on the input: in each test case, at least one card is
initially given to Alice, and at least one card is initially given to Bob.

Output
For each test case, output Alice if Alice wins with optimal play, or Bob if Bob
wins. It can be shown that if both players play optimally, the game will
definitely end in a finite number of turns with one of the players winning.

Example
InputCopy
8
2
AB
2
BA
4
ABAB
4
BABA
3
BAA
5
AAAAB
5
BAAAB
6
BBBAAA
OutputCopy
Alice
Bob
Bob
Bob
Alice
Alice
Bob
Alice
Note
In the first test case, Alice has only one card, and Bob has only one card.
Since Alice's card beats Bob's card, she wins after the first turn.

In the second test case, Alice has only one card, and Bob has only one card.
Since Bob's card beats Alice's card, he wins after the first turn.

In the third test case, there are two possible game scenarios:

if Alice plays the card 1
 on the first turn, Bob can respond with the card 2
 and take both cards. Then, Alice has to play the card 3
 on the second turn, and Bob will respond by playing the card 4
. Then, he wins;
if Alice plays the card 3
 on the first turn, Bob can respond with the card 4
 and take both cards. Then, Alice has to play the card 1
, and Bob can respond either with the card 2
 or the card 3
. Then, he wins.
In the fourth test case, there are two possible game scenarios:

if Alice plays the card 2
 on the first turn, Bob can respond with the card 3
 and take both cards. Then, Alice has to play the card 4
 on the second turn, and Bob will respond by playing the card 1
. Then, he wins;
if Alice plays the card 4
 on the first turn, Bob can respond with the card 1
 and take both cards. Then, Alice has to play the card 2
, and Bob can respond either with the card 3
 or the card 4
. Then, he wins.


*/

#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    if (s[0] == s.back()) {
      std::cout << (s[0] == 'A' ? "Alice" : "Bob") << std::endl;
    } else if (s[0] == 'A') {
      bool alice(true);
      for (int p = n - 2; alice && p >= 0; p--) {
        if (s[p] == 'B') {
          alice = false;
        }
      }
      std::cout << (alice ? "Alice" : "Bob") << std::endl;
    } else {
      std::cout << (s[n - 2] == 'A' ? "Alice" : "Bob") << std::endl;
    }
  }
}
// sub: https://codeforces.com/problemset/submission/2104/341157134
