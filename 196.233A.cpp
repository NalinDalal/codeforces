/* A. Perfect Permutation
time limit per test2 seconds
memory limit per test256 megabytes
A permutation is a sequence of integers p1, p2, ..., pn, consisting of n
distinct positive integers, each of them doesn't exceed n. Let's denote the i-th
element of permutation p as pi. We'll call number n the size of permutation
p1, p2, ..., pn.

Nickolas adores permutations. He likes some permutations more than the others.
He calls such permutations perfect. A perfect permutation is such permutation p
that for any i (1 ≤ i ≤ n) (n is the permutation size) the following equations
hold ppi = i and pi ≠ i. Nickolas asks you to print any perfect permutation of
size n for the given n.

Input
A single line contains a single integer n (1 ≤ n ≤ 100) — the permutation size.

Output
If a perfect permutation of size n doesn't exist, print a single integer -1.
Otherwise print n distinct integers from 1 to n, p1, p2, ..., pn — permutation
p, that is perfect. Separate printed numbers by whitespaces.

Examples
InputCopy
1
OutputCopy
-1
InputCopy
2
OutputCopy
2 1
InputCopy
4
OutputCopy
2 1 4 3
*/

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    for (int k = 1; k <= n; k++) {
      cout << (k % 2 ? (k + 1) : (k - 1)) << " ";
    }
    cout << endl;
  } else {
    cout << "-1" << endl;
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/233/308756674
