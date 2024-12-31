/* https://codeforces.com/problemset/problem/151/A

A. Soft Drinking
time limit per test2 seconds
memory limit per test256 megabytes
This winter is so cold in Nvodsk! A group of n friends decided to buy k bottles
of a soft drink called "Take-It-Light" to warm up a bit. Each bottle has l
milliliters of the drink. Also they bought c limes and cut each of them into d
slices. After that they found p grams of salt.

To make a toast, each friend needs nl milliliters of the drink, a slice of lime
and np grams of salt. The friends want to make as many toasts as they can,
provided they all drink the same amount. How many toasts can each friend make?

Input
The first and only line contains positive integers n, k, l, c, d, p, nl, np, not
exceeding 1000 and no less than 1. The numbers are separated by exactly one
space.

Output
Print a single integer — the number of toasts each friend can make.

Examples
InputCopy
3 4 5 10 8 100 3 1
OutputCopy
2
InputCopy
5 100 10 1 19 90 4 3
OutputCopy
3
InputCopy
10 1000 1000 25 23 1 50 1
OutputCopy
0
Note
A comment to the first sample:

Overall the friends have 4 * 5 = 20 milliliters of the drink, it is enough to
make 20 / 3 = 6 toasts. The limes are enough for 10 * 8 = 80 toasts and the salt
is enough for 100 / 1 = 100 toasts. However, there are 3 friends in the group,
so the answer is min(6, 80, 100) / 3 = 2.

*/

#include <iostream>

using namespace std;

int main() {
  int n, k, l, c, d, p, nl, np;
  // n, k, l, c, d, p, nl, np,
  // n: Number of friends.

  /*k: Number of bottles.
  l: Milliliters of drink per bottle.
  c: Number of limes.
  d: Slices per lime.
  p: Grams of salt.
  nl: Milliliters of drink needed per toast.
  np: Grams of salt needed per toast.*/

  /* total resource:
   * total_drink=k*l
   * total_lime=c*d
   * total_salt=p*/
  /* totast each resource:
   * toast_drink=total_drink/nl
   * totast_lime=total_lime
   * toast_salt=total_salt/np*/
  /* total toast:
   * total_toast=min(toast_drink, toast_slice,toast_salt)
   * totast_per_friend=total_toast/n */

  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int ans = 0;
  int total_drink = k * l;
  int total_slices = c * d;
  int total_salt = p;

  // Calculate maximum toasts each resource can support
  int toasts_drink = total_drink / nl;
  int toasts_slices = total_slices;
  int toasts_salt = total_salt / np;

  // Find the limiting resource
  int total_toasts = min(toasts_drink, min(toasts_slices, toasts_salt));

  // # Calculate toasts per friend
  int toasts_per_friend = total_toasts / n;

  cout << toasts_per_friend << endl;
  return 0;
}
// submission: https://codeforces.com/problemset/submission/151/299194547
