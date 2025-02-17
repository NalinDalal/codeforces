/* A. Love Story
time limit per test1 second
memory limit per test256 megabytes
Timur loves codeforces. That's why he has a string 𝑠 having length 10 made
containing only lowercase Latin letters. Timur wants to know how many indices
string 𝑠 differs from the string "codeforces".

For example string 𝑠= "coolforsez" differs from "codeforces" in 4 indices, shown
in bold.

Help Timur by finding the number of indices where string 𝑠 differs from
"codeforces".

Note that you can't reorder the characters in the string 𝑠.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤1000) — the number of test
cases.

Each test case is one line and contains the string 𝑠, consisting of exactly 10
lowercase Latin characters.

Output
For each test case, output a single integer — the number of indices where string
𝑠 differs.

Example
InputCopy
5
coolforsez
cadafurcie
codeforces
paiuforces
forcescode
OutputCopy
4
5
0
4
9

*/

#include <iostream>
#include <string>
using namespace std;
// length of string=10
// to dono ko index by index check kro, agar nhi h to count++
// check with string "codeforces"
// return count
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int count = 0;
    string check = "codeforces";
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != check[i])
        count++;
    }
    cout << count << endl;
  }
  return 0;
}
// sol: https://codeforces.com/problemset/submission/1829/306485465
