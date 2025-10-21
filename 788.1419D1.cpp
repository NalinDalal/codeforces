/*D1. Sage's Birthday (easy version)
time limit per test1 second
memory limit per test256 megabytes
This is the easy version of the problem. The difference between the versions is
that in the easy version all prices 𝑎𝑖 are different. You can make hacks if and
only if you solved both versions of the problem.

Today is Sage's birthday, and she will go shopping to buy ice spheres. All 𝑛
 ice spheres are placed in a row and they are numbered from 1
 to 𝑛
 from left to right. Each ice sphere has a positive integer price. In this
version all prices are different.

An ice sphere is cheap if it costs strictly less than two neighboring ice
spheres: the nearest to the left and the nearest to the right. The leftmost and
the rightmost ice spheres are not cheap. Sage will choose all cheap ice spheres
and then buy only them.

You can visit the shop before Sage and reorder the ice spheres as you wish. Find
out the maximum number of ice spheres that Sage can buy, and show how the ice
spheres should be reordered.

Input
The first line contains a single integer 𝑛
 (1≤𝑛≤105)
 — the number of ice spheres in the shop.

The second line contains 𝑛
 different integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109)
 — the prices of ice spheres.

Output
In the first line print the maximum number of ice spheres that Sage can buy.

In the second line print the prices of ice spheres in the optimal order. If
there are several correct answers, you can print any of them.

Example
InputCopy
5
1 2 3 4 5
OutputCopy
2
3 1 4 2 5
Note
In the example it's not possible to place ice spheres in any order so that Sage
would buy 3 of them. If the ice spheres are placed like this (3,1,4,2,5) , then
Sage will buy two spheres: one for 1 and one for 2 , because they are cheap.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  long n;
  std::cin >> n;

  std::vector<long> a(n);
  for (long i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::sort(a.rbegin(), a.rend());

  long last = -1;
  if (n % 2 == 0) {
    last = a.back();
    a.pop_back();
  }

  std::vector<long> b(a.size());
  long idx = 0;

  // Fill even indices
  for (long i = 0; i < n; i += 2) {
    b[i] = a[idx++];
  }

  // Fill odd indices
  for (long i = 1; i < n; i += 2) {
    b[i] = a[idx++];
  }

  if (last > 0) {
    b.push_back(last);
  }

  std::cout << (n - 1) / 2 << "\n";
  for (long i = 0; i < b.size(); ++i) {
    std::cout << b[i] << " ";
  }
  std::cout << "\n";

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1419/344996479
