/*A. Football
time limit per test2 seconds
memory limit per test256 megabytes
Petya loves football very much. One day, as he was watching a football match, he
was writing the players' current positions on a piece of paper. To simplify the
situation he depicted it as a string consisting of zeroes and ones. A zero
corresponds to players of one team; a one corresponds to players of another
team. If there are at least 7 players of some team standing one after another,
then the situation is considered dangerous. For example, the situation
00100110111111101 is dangerous and 11110111011101 is not. You are given the
current situation. Determine whether it is dangerous or not.

Input
The first input line contains a non-empty string consisting of characters "0"
and "1", which represents players. The length of the string does not exceed 100
characters. There's at least one player from each team present on the field.

Output
Print "YES" if the situation is dangerous. Otherwise, print "NO".

Examples
InputCopy
001001
OutputCopy
NO
InputCopy
1000000001
OutputCopy
YES
*/

// 0- team A
// 1- team B
// Dangerous condn-at least 7 players of some team standing one after another
// given a string find whether it is dangrous or not
// if dangerous print YES
// else print NO

#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int state = -1;
  int runningSum = 0;
  string output = "NO";
  for (int k = 0; k < s.size(); k++) {
    if (s[k] != state) {
      state = s[k];
      runningSum = 0;
    }
    ++runningSum;
    if (runningSum >= 7) {
      output = "YES";
      break;
    }
  }
  cout << output << endl;

  return 0;
}
// sub: https://codeforces.com/problemset/submission/96/309911070
