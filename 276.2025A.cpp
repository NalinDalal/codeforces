/*A. Two Screens
time limit per test2 seconds
memory limit per test512 megabytes
There are two screens which can display sequences of uppercase Latin letters.
Initially, both screens display nothing.

In one second, you can do one of the following two actions:

choose a screen and an uppercase Latin letter, and append that letter to the end
of the sequence displayed on that screen; choose a screen and copy the sequence
from it to the other screen, overwriting the sequence that was displayed on the
other screen. You have to calculate the minimum number of seconds you have to
spend so that the first screen displays the sequence 𝑠 , and the second screen
displays the sequence 𝑡
.

Input
The first line contains one integer 𝑞
 (1≤𝑞≤500
) — the number of test cases.

Each test case consists of two lines. The first line contains the string 𝑠
, and the second line contains the string 𝑡
 (1≤|𝑠|,|𝑡|≤100
). Both strings consist of uppercase Latin letters.

Output
For each test case, print one integer — the minimum possible number of seconds
you have to spend so that the first screen displays the sequence 𝑠 , and the
second screen displays the sequence 𝑡
.

Example
InputCopy
3
GARAGE
GARAGEFORSALE
ABCDE
AABCD
TRAINING
DRAINING
OutputCopy
14
10
16
Note
In the first test case, the following sequence of actions is possible:

spend 6
 seconds to write the sequence GARAGE on the first screen;
copy the sequence from the first screen to the second screen;
spend 7
 seconds to complete the sequence on the second screen by writing FORSALE.
In the second test case, the following sequence of actions is possible:

spend 1
 second to write the sequence A on the second screen;
copy the sequence from the second screen to the first screen;
spend 4
 seconds to complete the sequence on the first screen by writing BCDE;
spend 4
 seconds to complete the sequence on the second screen by writing ABCD.
In the third test case, the fastest way to display the sequences is to type both
of them character by character without copying, and this requires 16 seconds.



*/

#include <iostream>
#include <string>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    int ans = s1.size() + s2.size() + (s1[0] == s2[0]);
    for (long p = 0; p < s1.size() && p < s2.size() && s1[p] == s2[p]; p++) {
      --ans;
    }
    std::cout << ans << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/2025/313099362
