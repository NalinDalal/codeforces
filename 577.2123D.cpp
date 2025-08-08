/*D. Binary String Battle
time limit per test2 seconds
memory limit per test256 megabytes
Alice and Bob are given a binary string 𝑠
 of length 𝑛
, and an integer 𝑘
 (1≤𝑘<𝑛
).

Alice wins if she is able to transform all characters of 𝑠
 into zeroes. If Alice is unable to win in a finite number of moves, then Bob
wins.

Alice and Bob take turns, with Alice going first.

On Alice's turn, she may choose any subsequence∗
 of length 𝑘
 in 𝑠
, then set all characters in that subsequence to zero.
On Bob's turn, he may choose any substring†
 of length 𝑘
 in 𝑠
, then set all characters in that substring to one.
Note that Alice wins if the string consists of all zeros at any point during the
game, including in between Alice's and Bob's turns.

Determine who wins with optimal play.

∗
A subsequence of a string 𝑠
 is a set of characters in 𝑠
. Note that these characters do not have to be adjacent.

†
A substring of a string 𝑠
 is a contiguous group of characters in 𝑠
. Note that these characters must be adjacent.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
)  — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (2≤𝑛≤2⋅105
, 1≤𝑘<𝑛
).

The second line of each test case contains a binary string 𝑠
 of length 𝑛
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output on a single line "Alice" if Alice wins with optimal
play, and "Bob" if Bob wins with optimal play.

You can output the answer in any case (upper or lower). For example, the strings
"aLiCe", "alice", "ALICE", and "alICE" will be recognized as "Alice".

Example
InputCopy
6
5 2
11011
7 4
1011011
6 1
010000
4 1
1111
8 3
10110110
6 4
111111
OutputCopy
Bob
Alice
Alice
Bob
Bob
Alice
Note
In the third sample, Alice can choose the subsequence consisting of 𝑠2
, turning 𝑠
 into 000000
. Then she wins immediately.

In the fourth sample, it can be shown that there is no way for Alice to
guarantee that she can turn 𝑠 into 0000 within a finite number of moves.
*/
#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    long cnt(0);
    for (long p = 0; p < s.size(); p++) {
      cnt += (s[p] == '1');
    }
    std::cout << (cnt <= k || n < 2 * k ? "Alice" : "Bob") << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2123/332954856
