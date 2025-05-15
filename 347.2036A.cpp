/* A. Quintomania
time limit per test1 second
memory limit per test256 megabytes
Boris Notkin composes melodies. He represents them as a sequence of notes, where
each note is encoded as an integer from 0 to 127 inclusive. The interval between
two notes 𝑎 and 𝑏 is equal to |𝑎−𝑏| semitones.

Boris considers a melody perfect if the interval between each two adjacent notes
is either 5 semitones or 7 semitones.

After composing his latest melodies, he enthusiastically shows you his
collection of works. Help Boris Notkin understand whether his melodies are
perfect.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of melodies.

Each melody is described by two lines.

The first line contains an integer 𝑛
 (2≤𝑛≤50
) — the number of notes in the melody.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤127
) — the notes of the melody.

Output
For each melody, output "YES", if it is perfect; otherwise, output "NO".

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
8
2
114 109
2
17 10
3
76 83 88
8
38 45 38 80 85 92 99 106
5
63 58 65 58 65
8
117 124 48 53 48 43 54 49
5
95 102 107 114 121
10
72 77 82 75 70 75 68 75 68 75
OutputCopy
YES
YES
YES
NO
YES
NO
YES
YES

*/

#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    // interval b/w 2 adjacent notes is either 5 or 7
    // check if the diff b/w adjacent notes is either 5/7
    // if either of diff is not 7/5 return false
    // else return true;
    bool isPerfect = true;
    for (int i = 0; i < n - 1; i++) {
      if (abs(v[i] - v[i + 1]) != 7 && abs(v[i] - v[i + 1]) != 5)
        isPerfect = false;
    }
    if (isPerfect)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2036/319808247
