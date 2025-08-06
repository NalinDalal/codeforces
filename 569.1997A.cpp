/*A. Strong Password
time limit per test2 seconds
memory limit per test512 megabytes
Monocarp's current password on Codeforces is a string 𝑠
, consisting of lowercase Latin letters. Monocarp thinks that his current
password is too weak, so he wants to insert exactly one lowercase Latin letter
into the password to make it stronger. Monocarp can choose any letter and insert
it anywhere, even before the first character or after the last character.

Monocarp thinks that the password's strength is proportional to the time it
takes him to type the password. The time it takes to type the password is
calculated as follows:

the time to type the first character is 2
 seconds;
for each character other than the first, the time it takes to type it is 1
 second if it is the same as the previous character, or 2
 seconds otherwise.
For example, the time it takes to type the password abacaba is 14
; the time it takes to type the password a is 2
; the time it takes to type the password aaabacc is 11
.

You have to help Monocarp — insert a lowercase Latin letter into his password so
that the resulting password takes the maximum possible amount of time to type.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

Each test case consists of one line containing the string 𝑠
 (1≤|𝑠|≤10
), consisting of lowercase Latin letters.

Output
For each test case, print one line containing the new password — a string which
can be obtained from 𝑠 by inserting one lowercase Latin letter. The string you
print should have the maximum possible required time to type it. If there are
multiple answers, print any of them.

Example
InputCopy
4
a
aaa
abb
password
OutputCopy
wa
aada
abcb
pastsword


*/

/*given string s
- Insert exactly one lowercase letter (a–z) anywhere in s.
- Choose the insertion to maximize the total time it takes to type the resulting
string.

1. First character → 2 seconds
2. For each following character:
    +1 sec → if same as previous
    +2 sec → if different from previous

For each test case, find a way to insert a letter so the typing time is
maximized.


*/
#include <iostream>
#include <string>
using namespace std;

// Function to calculate typing time
int typingTime(const string &s) {
  int time = 2; // First character
  for (int i = 1; i < s.size(); ++i) {
    time += (s[i] == s[i - 1]) ? 1 : 2;
  }
  return time;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    int maxTime = -1;
    string best;

    // Try inserting each letter at every position
    for (int pos = 0; pos <= s.size(); ++pos) {
      for (char c = 'a'; c <= 'z'; ++c) {
        string newStr = s.substr(0, pos) + c + s.substr(pos);
        int time = typingTime(newStr);
        if (time > maxTime) {
          maxTime = time;
          best = newStr;
        }
      }
    }

    cout << best << '\n';
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1997/332660114
