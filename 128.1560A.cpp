/*  https://codeforces.com/problemset/problem/1560/A

A. Dislike of Threes
time limit per test1 second
memory limit per test256 megabytes
Polycarp doesn't like integers that are divisible by 3 or end with the digit 3
in their decimal representation. Integers that meet both conditions are disliked
by Polycarp, too.

Polycarp starts to write out the positive (greater than 0) integers which he
likes: 1,2,4,5,7,8,10,11,14,16,…. Output the 𝑘-th element of this sequence (the
elements are numbered from 1).

Input
The first line contains one integer 𝑡 (1≤𝑡≤100) — the number of test cases. Then
𝑡 test cases follow.

Each test case consists of one line containing one integer 𝑘 (1≤𝑘≤1000).

Output
For each test case, output in a separate line one integer 𝑥 — the 𝑘-th element
of the sequence that was written out by Polycarp.

Example
InputCopy
10
1
2
3
4
5
6
7
8
9
1000
OutputCopy
1
2
4
5
7
8
10
11
14
1666

*/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int k;
    cin >> k;
    // cout the kth element of the sequence
    // sequence logic: skip number divisible by 3 or ending with 3
    int count = 0, num = 1;
    while (count < k) {
      if (num % 3 != 0 && num % 10 != 3) {
        count++;
      }
      num++;
    }

    cout << num - 1 << endl; // Output the k-th valid number
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1560/305950366
