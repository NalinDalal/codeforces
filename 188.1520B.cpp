/*B. Ordinary Numbers
time limit per test2 seconds
memory limit per test256 megabytes
Let's call a positive integer 𝑛
 ordinary if in the decimal notation all its digits are the same. For example, 1
, 2
 and 99
 are ordinary numbers, but 719
 and 2021
 are not ordinary numbers.

For a given number 𝑛
, find the number of ordinary numbers among the numbers from 1
 to 𝑛
.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
). Then 𝑡
 test cases follow.

Each test case is characterized by one integer 𝑛
 (1≤𝑛≤109
).

Output
For each test case output the number of ordinary numbers among numbers from 1
 to 𝑛
.

Example
InputCopy
6
1
2
3
4
5
100
OutputCopy
1
2
3
4
5
18

*/
// check if n is ordinary
// n is ordinary if in the decimal notation all its digits are the same.like
// ones,tens,hundred must be same
// so digit like 22,33,222,333 are ordinary

// find no of ordinary number from 1 to n
// n is normal if in decimal notation all digit are same

#include <iostream>
using namespace std;

int countOrdinaryNumbers(int n) {
  int count = 0;
  for (int d = 1; d <= 9; d++) { // Start with digits 1 to 9
    long long num = d;
    while (num <= n) {
      count++;
      num = num * 10 + d; // Generate ordinary numbers: 1 → 11 → 111 → 1111
    }
  }
  return count;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << countOrdinaryNumbers(n) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1520/308484982
