/* A. Soldier and Bananas
time limit per test1 second
memory limit per test256 megabytes
A soldier wants to buy w bananas in the shop. He has to pay k dollars for the
first banana, 2k dollars for the second one and so on (in other words, he has to
pay i·k dollars for the i-th banana).

He has n dollars. How many dollars does he have to borrow from his friend
soldier to buy w bananas?

Input
The first line contains three positive integers k, n, w (1  ≤  k, w  ≤  1000,
0 ≤ n ≤ 109), the cost of the first banana, initial number of dollars the
soldier has and number of bananas he wants.

Output
Output one integer — the amount of dollars that the soldier must borrow from his
friend. If he doesn't have to borrow money, output 0.

Examples
Input
3 17 4
Output
13
*/

#include <iostream>

using namespace std;

// have n dollars, want to buy w banana, cost is like k for 1st, 2k for 2nd, 3k
// for 3rd etc
// borrow amount needed is what?
// borrow amount = w*k(needs to be iteratively multiplied)-n
// cost=cost+k*i(till ith banana)
// cost=k*[{w*(w+1)}/2]
// borrow=max(0,cost-n)
int main() {
  int n; // initial dollars
  int k; // cost of first banana
  int w; // number of bananas
  cin >> k >> n >> w;
  // Calculate total cost
  int totalCost = k * (w * (w + 1)) / 2;

  // Calculate amount to borrow
  int borrow = max(0, totalCost - n);

  cout << borrow << endl;
  return 0;
}
