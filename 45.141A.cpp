/*
 https://codeforces.com/problemset/problem/141/A
submit:




A. Amusing Joke
time limit per test2 seconds
memory limit per test256 megabytes
So, the New Year holidays are over. Santa Claus and his colleagues can take a
rest and have guests at last. When two "New Year and Christmas Men" meet, thear
assistants cut out of cardboard the letters from the guest's name and the host's
name in honor of this event. Then the hung the letters above the main entrance.
One night, when everyone went to bed, someone took all the letters of our
characters' names. Then he may have shuffled the letters and put them in one
pile in front of the door.

The next morning it was impossible to find the culprit who had made the
disorder. But everybody wondered whether it is possible to restore the names of
the host and his guests from the letters lying at the door? That is, we need to
verify that there are no extra letters, and that nobody will need to cut more
letters.

Help the "New Year and Christmas Men" and their friends to cope with this
problem. You are given both inscriptions that hung over the front door the
previous night, and a pile of letters that were found at the front door next
morning.

Input
The input file consists of three lines: the first line contains the guest's
name, the second line contains the name of the residence host and the third line
contains letters in a pile that were found at the door in the morning. All lines
are not empty and contain only uppercase Latin letters. The length of each line
does not exceed 100.

Output
Print "YES" without the quotes, if the letters in the pile could be permuted to
make the names of the "New Year and Christmas Men". Otherwise, print "NO"
without the quotes.

Examples:
Input
SANTACLAUS
DEDMOROZ
SANTAMOROZDEDCLAUS
Output
YES

Input
PAPAINOEL
JOULUPUKKI
JOULNAPAOILELUPUKKI
Output
NO

Input
BABBONATALE
FATHERCHRISTMAS
BABCHRISTMASBONATALLEFATHER
Output
NO

Note
In the first sample the letters written in the last line can be used to write
the names and there won't be any extra letters left. In the second sample letter
"P" is missing from the pile and there's an extra letter "L". In the third
sample there's an extra letter "L".
*/

#include <iostream>

using namespace std;

/*int main() {
  // input
  string host, guest, pile;
  cin >> host >> guest >> pile;

  // output
  bool flag = true;

  for (int i = 0; i < pile.size(); i++) {
    if (pile[i] != host[i] && pile[i] != guest[i])
      flag = false;
    else
      continue;
  }
  if (flag) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}

/* issues
Character Count Mismatch: The current implementation does not verify if the
counts of characters in the host, guest, and pile strings match. Order
Irrelevance: The code incorrectly assumes that characters in the pile must align
with host and guest in order, but order does not matter. Excess Characters: It
does not account for characters in pile that do not belong to either host or
guest. Length Check: The sum of the lengths of host and guest must equal the
length of pile.*/

/* correct
The total length of host and guest matches the length of pile.
All characters in the concatenation of host and guest can be rearranged to form
pile.
*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  // Input
  string host, guest, pile;
  cin >> host >> guest >> pile;

  // Combine host and guest names
  string combined = host + guest;

  // Sort both the combined string and the pile
  sort(combined.begin(), combined.end());
  sort(pile.begin(), pile.end());

  // Compare sorted versions
  if (combined == pile) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}

// what was problem in previous code: we were checking host and guest
// individually, in new code we are checking combined string a/f sorting both
// submission: https://codeforces.com/problemset/submission/141/298758111
