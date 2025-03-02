/*B. Not Quite Latin Square
time limit per test1 second
memory limit per test256 megabytes
A Latin square is a 3×3
 grid made up of the letters 𝙰
, 𝙱
, and 𝙲
 such that:

in each row, the letters 𝙰
, 𝙱
, and 𝙲
 each appear once, and
in each column, the letters 𝙰
, 𝙱
, and 𝙲
 each appear once.
For example, one possible Latin square is shown below.
⎡⎣⎢⎢𝙰𝙲𝙱𝙱𝙰𝙲𝙲𝙱𝙰⎤⎦⎥⎥
You are given a Latin square, but one of the letters was replaced with a
question mark ? . Find the letter that was replaced.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤108
) — the number of testcases.

Each test case contains three lines, each consisting of three characters,
representing the Latin square. Each character is one of 𝙰 , 𝙱 , 𝙲 , or ?
.

Each test case is a Latin square with exactly one of the letters replaced with a
question mark ?
.

Output
For each test case, output the letter that was replaced.

Example
InputCopy
3
ABC
C?B
BCA
BCA
CA?
ABC
?AB
BCA
ABC
OutputCopy
A
B
C
Note
The correct Latin squares for the three test cases are shown below:

⎡⎣⎢⎢𝙰𝙲𝙱𝙱𝙰𝙲𝙲𝙱𝙰⎤⎦⎥⎥⎡⎣⎢⎢𝙱𝙲𝙰𝙲𝙰𝙱𝙰𝙱𝙲⎤⎦⎥⎥⎡⎣⎢⎢𝙲𝙱𝙰𝙰𝙲𝙱𝙱𝙰𝙲⎤⎦⎥⎥


*/
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    char missing = 'A'; // Default missing letter
    for (int row = 0; row < 3; row++) {
      string s;
      cin >> s;
      bool hasA = false, hasB = false, hasC = false;

      for (char c : s) {
        if (c == 'A')
          hasA = true;
        else if (c == 'B')
          hasB = true;
        else if (c == 'C')
          hasC = true;
      }

      if (!hasA)
        missing = 'A';
      else if (!hasB)
        missing = 'B';
      else if (!hasC)
        missing = 'C';
    }

    cout << missing << endl;
  }
  return 0;
}

// find the question mark, check it's corresponding row, cout the
// remaining letter
// sub: https://codeforces.com/problemset/submission/1915/308692990
