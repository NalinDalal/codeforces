/* https://codeforces.com/problemset/problem/1866/A
A. Ambitious Kid
time limit per test1 second
memory limit per test256 megabytes
Chaneka, Pak Chanek's child, is an ambitious kid, so Pak Chanek gives her the
following problem to test her ambition.

Given an array of integers [𝐴1,𝐴2,𝐴3,…,𝐴𝑁]. In one operation, Chaneka can choose
one element, then increase or decrease the element's value by 1. Chaneka can do
that operation multiple times, even for different elements.

What is the minimum number of operations that must be done to make it such that
𝐴1×𝐴2×𝐴3×…×𝐴𝑁=0?

Input
The first line contains a single integer 𝑁 (1≤𝑁≤105).

The second line contains 𝑁 integers 𝐴1,𝐴2,𝐴3,…,𝐴𝑁 (−105≤𝐴𝑖≤105).

Output
An integer representing the minimum number of operations that must be done to
make it such that 𝐴1×𝐴2×𝐴3×…×𝐴𝑁=0.

Examples
InputCopy
3
2 -6 5
OutputCopy
2
InputCopy
1
-3
OutputCopy
3
InputCopy
5
0 -1 0 1 0
OutputCopy
0
Note
In the first example, initially, 𝐴1×𝐴2×𝐴3=2×(−6)×5=−60. Chaneka can do the
following sequence of operations:

Decrease the value of 𝐴1 by 1. Then, 𝐴1×𝐴2×𝐴3=1×(−6)×5=−30
Decrease the value of 𝐴1 by 1. Then, 𝐴1×𝐴2×𝐴3=0×(−6)×5=0
In the third example, Chaneka does not have to do any operations, because from
the start, it already holds that 𝐴1×𝐴2×𝐴3×𝐴4×𝐴5=0×(−1)×0×1×0=0
*/

// find element nearest to zero
// then return it's mod

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  // we need to find minimum number of operation to make it zero
  // so select nearest to zero element
  // return it's absolute value

  // Initialize variables to store the minimum absolute value
  int min_abs = abs(v[0]); // Start with the absolute value of the first element

  // Iterate through the array to find the closest to zero
  for (int i = 1; i < n; i++) {
    int current_abs = abs(v[i]);
    if (current_abs < min_abs) {
      min_abs = current_abs;
    }
  }

  cout << min_abs << endl; // Output the result
  return 0;
}

// soln: t.ly/9wKTy
