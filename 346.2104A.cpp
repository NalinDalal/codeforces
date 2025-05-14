/* A. Three Decks
time limit per test2 seconds
memory limit per test512 megabytes
Monocarp placed three decks of cards in a row on the table. The first deck
consists of 𝑎 cards, the second deck consists of 𝑏 cards, and the third deck
consists of 𝑐 cards, with the condition 𝑎<𝑏<𝑐
.

Monocarp wants to take some number of cards (at least one, but no more than 𝑐
) from the third deck and distribute them between the first two decks so that
each of the taken cards ends up in either the first or the second deck. It is
possible that all the cards taken from the third deck will go into the same
deck.

Your task is to determine whether Monocarp can make the number of cards in all
three decks equal using the described operation.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The only line of each test case contains three integers 𝑎,𝑏
, and 𝑐
 (1≤𝑎,𝑏,𝑐≤108
) — the number of cards in the first, second, and third decks, respectively.

Additional constraint on the input: 𝑎<𝑏<𝑐
.

Output
For each test case, output "YES" (without quotes) if Monocarp can make the
number of cards in all three decks equal using the described operation.
Otherwise, output "NO" (without quotes).

Example
InputCopy
4
3 5 10
12 20 30
3 5 7
1 5 6
OutputCopy
YES
NO
YES
NO
Note
In the first test case, Monocarp has to take 4
 cards from the third deck, put 3
 cards in the first deck, and 1
 card in the second deck. Thus, there will be 6
 cards in all three decks.

In the second test case, it is impossible to make the number of cards in all
three decks equal.

In the third test case, Monocarp has to take 2
 cards from the third deck and put both in the first deck. Thus, there will be 5
 cards in all three decks.

In the fourth test case, it is also impossible to make the number of cards in
all three decks equal.


*/

#include <iostream>
using namespace std;

bool can(int a, int b, int c) {
  // a<b<c
  // distribute cards such that all become equal
  int s = a + b + c;
  int u = (s % 3) ? -1 : (s / 3);
  if (u >= a && u >= b)
    return true;
  else
    return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (can(a, b, c))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2104/319597911
