/*
A. Dubstep
time limit per test2 seconds
memory limit per test256 megabytes
Vasya works as a DJ in the best Berland nightclub, and he often uses dubstep
music in his performance. Recently, he has decided to take a couple of old songs
and make dubstep remixes from them.

Let's assume that a song consists of some number of words. To make the dubstep
remix of this song, Vasya inserts a certain number of words "WUB" before the
first word of the song (the number may be zero), after the last word (the number
may be zero), and between words (at least one between any pair of neighbouring
words), and then the boy glues together all the words, including "WUB", in one
string and plays the song at the club.

For example, a song with words "I AM X" can transform into a dubstep remix as
"WUBWUBIWUBAMWUBWUBX" and cannot transform into "WUBWUBIAMWUBX".

Recently, Petya has heard Vasya's new dubstep track, but since he isn't into
modern music, he decided to find out what was the initial song that Vasya
remixed. Help Petya restore the original song.

Input
The input consists of a single non-empty string, consisting only of uppercase
English letters, the string's length doesn't exceed 200 characters. It is
guaranteed that before Vasya remixed the song, no word contained substring "WUB"
in it; Vasya didn't change the word order. It is also guaranteed that initially
the song had at least one word.

Output
Print the words of the initial song that Vasya used to make a dubsteb remix.
Separate the words with a space.

Examples
InputCopy
WUBWUBABCWUB
OutputCopy
ABC
InputCopy
WUBWEWUBAREWUBWUBTHEWUBCHAMPIONSWUBMYWUBFRIENDWUB
OutputCopy
WE ARE THE CHAMPIONS MY FRIEND
Note
In the first sample: "WUBWUBABCWUB" = "WUB" + "WUB" + "ABC" + "WUB". That means
that the song originally consisted of a single word "ABC", and all words "WUB"
were added by Vasya.

In the second sample Vasya added a single word "WUB" between all neighbouring
words, in the beginning and in the end, except for words "ARE" and "THE" —
between them Vasya added two "WUB".


*/

#include <iostream>
#include <string>

using namespace std;
int main() {
  string s;
  cin >> s;
  string result;
  size_t i = 0;
  bool first_word = true;
  // just do like  for each space in original string we put 'WUB'
  // so to get ans remove every instance of 'WUB' in original string
  while (i < s.length()) {
    // If "WUB" is found, skip it
    if (i + 2 < s.length() && s.substr(i, 3) == "WUB") {
      i += 3; // Move past "WUB"
    } else {
      // Add space before new words (but not before the first word)
      if (!first_word)
        result += ' ';
      first_word = false;

      // Collect the next word
      while (i < s.length() &&
             (i + 2 >= s.length() || s.substr(i, 3) != "WUB")) {
        result += s[i];
        i++;
      }
    }
  }
  cout << result << endl;
  return 0;
}
// sub: https://codeforces.com/problemset/submission/208/311216135
