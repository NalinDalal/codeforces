/* https://codeforces.com/problemset/problem/1692/A

A. Marathon
time limit per test1 second
memory limit per test256 megabytes
You are given four distinct integers 𝑎, 𝑏, 𝑐, 𝑑.

Timur and three other people are running a marathon. The value 𝑎 is the distance
that Timur has run and 𝑏, 𝑐, 𝑑 correspond to the distances the other three
participants ran.

Output the number of participants in front of Timur.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤104) — the number of test cases.

The description of each test case consists of four distinct integers 𝑎, 𝑏, 𝑐, 𝑑
(0≤𝑎,𝑏,𝑐,𝑑≤104).

Output
For each test case, output a single integer — the number of participants in
front of Timur.

Example
InputCopy
4
2 3 4 1
10000 0 1 2
500 600 400 300
0 9999 10000 9998
OutputCopy
2
0
1
3
Note
For the first test case, there are 2 people in front of Timur, specifically the
participants who ran distances of 3 and 4 . The other participant is not in
front of Timur because he ran a shorter distance than Timur.

For the second test case, no one is in front of Timur, since he ran a distance
of 10000 while all others ran a distance of 0, 1, and 2 respectively.

For the third test case, only the second person is in front of Timur, who ran a
total distance of 600 while Timur ran a distance of 500.
*/

#include <iostream>

int solve(int a, int b, int c, int d) {
  int result = 0;
  // number of participants in front of Timur
  // ohh well, just check if a is small than how many
  if (a < b)
    result++;
  if (a < c)
    result++;
  if (a < d)
    result++;

  return result;
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << solve(a, b, c, d) << std::endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1692/304591899
