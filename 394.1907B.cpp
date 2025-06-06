/* B. YetnotherrokenKeoard
time limit per test1 second
memory limit per test256 megabytes
Polycarp has a problem — his laptop keyboard is broken.

Now, when he presses the 'b' key, it acts like an unusual backspace: it deletes
the last (rightmost) lowercase letter in the typed string. If there are no
lowercase letters in the typed string, then the press is completely ignored.

Similarly, when he presses the 'B' key, it deletes the last (rightmost)
uppercase letter in the typed string. If there are no uppercase letters in the
typed string, then the press is completely ignored.

In both cases, the letters 'b' and 'B' are not added to the typed string when
these keys are pressed.

Consider an example where the sequence of key presses was "ARaBbbitBaby". In
this case, the typed string will change as follows: "" −→𝙰 "A" −→𝚁 "AR" −→𝚊
 "ARa" −→𝙱
 "Aa" −→𝚋
 "A" −→𝚋
 "A" −→𝚒
 "Ai" −→𝚝
 "Ait" −→𝙱
 "it" −→𝚊
 "ita" −→𝚋
 "it" −→𝚢
 "ity".

Given a sequence of pressed keys, output the typed string after processing all
key presses.

Input
The first line of the input data contains an integer 𝑡
 (1≤𝑡≤1000
), the number of test cases in the test.

The following contains 𝑡
 non-empty lines, which consist of lowercase and uppercase letters of the Latin
alphabet.

It is guaranteed that each line contains at least one letter and the sum of the
lengths of the lines does not exceed 106
.

Output
For each test case, output the result of processing the key presses on a
separate line. If the typed string is empty, then output an empty line.

Example
InputCopy
12
ARaBbbitBaby
YetAnotherBrokenKeyboard
Bubble
Improbable
abbreviable
BbBB
BusyasaBeeinaBedofBloomingBlossoms
CoDEBARbIES
codeforces
bobebobbes
b
TheBBlackbboard
OutputCopy
ity
YetnotherrokenKeoard
le
Imprle
revile

usyasaeeinaedofloominglossoms
CDARIES
codeforces
es

helaoard

*/

#include <iostream>
#include <vector>

int main() {

  std::ios_base::sync_with_stdio(false);

  long t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    std::vector<long> smalls, caps;
    std::vector<bool> show(s.size(), true);

    for (long p = 0; p < s.size(); p++) {
      if (s[p] == 'b') {
        show[p] = false;
        if (smalls.size() == 0) {
          continue;
        }
        show[smalls.back()] = false;
        smalls.pop_back();
      } else if (s[p] == 'B') {
        show[p] = false;
        if (caps.size() == 0) {
          continue;
        }
        show[caps.back()] = false;
        caps.pop_back();
      } else if (s[p] >= 'a' && s[p] <= 'z') {
        smalls.push_back(p);
      } else if (s[p] >= 'A' && s[p] <= 'Z') {
        caps.push_back(p);
      }
    }

    for (long p = 0; p < s.size(); p++) {
      if (show[p]) {
        std::cout << s[p];
      }
    }
    std::cout << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/1907/323081170
