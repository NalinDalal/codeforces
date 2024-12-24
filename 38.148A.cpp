/*  https://codeforces.com/problemset/problem/148/A

A. Insomnia cure
time limit per test2 seconds
memory limit per test256 megabytes
«One dragon. Two dragon. Three dragon», — the princess was counting. She had
trouble falling asleep, and she got bored of counting lambs when she was nine.

However, just counting dragons was boring as well, so she entertained herself at
best she could. Tonight she imagined that all dragons were here to steal her,
and she was fighting them off. Every k-th dragon got punched in the face with a
frying pan. Every l-th dragon got his tail shut into the balcony door. Every
m-th dragon got his paws trampled with sharp heels. Finally, she threatened
every n-th dragon to call her mom, and he withdrew in panic.

How many imaginary dragons suffered moral or physical damage tonight, if the
princess counted a total of d dragons?

Input
Input data contains integer numbers k, l, m, n and d, each number in a separate
line (1 ≤ k, l, m, n ≤ 10, 1 ≤ d ≤ 105).

Output
Output the number of damaged dragons.

Examples
InputCopy
1
2
3
4
12
OutputCopy
12
InputCopy
2
3
4
5
24
OutputCopy
17
Note
In the first case every first dragon got punched with a frying pan. Some of the
dragons suffered from other reasons as well, but the pan alone would be enough.

In the second case dragons 1, 7, 11, 13, 17, 19 and 23 escaped unharmed.

*/
#include <iostream>
#include <set>

using namespace std;

int main() {
  int k, l, m, n, d;
  cin >> k >> l >> m >> n >> d;

  // kth dragon - frying pan
  // lth dragon - balcony door
  // mth dragon - sharp heels
  // nth dragon - mom
  // d=total dragon;d=k+l+m+n
  // make a set of k,l,m,n
  set<int> damagedDragons;
  // kth dragon
  for (int i = k; i <= d; i += k) {
    damagedDragons.insert(i);
  }
  // Mark every l-th dragon
  for (int i = l; i <= d; i += l) {
    damagedDragons.insert(i);
  }

  // Mark every m-th dragon
  for (int i = m; i <= d; i += m) {
    damagedDragons.insert(i);
  }

  // Mark every n-th dragon
  for (int i = n; i <= d; i += n) {
    damagedDragons.insert(i);
  }

  // The size of the set gives the number of unique damaged dragons
  cout << damagedDragons.size() << endl;

  return 0;
}
