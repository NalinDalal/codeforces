/*L. LOL Lovers
time limit per test3 seconds
memory limit per test1024 megabytes
There are 𝑛
 food items lying in a row on a long table. Each of these items is either a loaf
of bread (denoted as a capital Latin letter 'L' with ASCII code 76) or an onion
(denoted as a capital Latin letter 'O' with ASCII code 79). There is at least
one loaf of bread and at least one onion on the table.

You and your friend want to divide the food on the table: you will take a prefix
of this row (several leftmost items), and the friend will take the rest.
However, there are several restrictions:

Each person should have at least one item.
The number of your loaves should differ from the number of your friend's loaves.
The number of your onions should differ from the number of your friend's onions.
Find any correct division and print the number of items you take or report that
there is no answer. Input The first line contains one integer 𝑛 (2≤𝑛≤200 ) — the
number of food items on the table. The second line contains a string of length 𝑛
 consisting of letters 'L' and 'O'. 𝑖
-th symbol represents the type of the 𝑖
-th food item on the table: 'L' stands for a loaf of bread, and 'O' stands for
an onion. It is guaranteed that this string contains at least one letter 'L' and
at least one letter 'O'.

Output
Print one integer — a number 𝑘
 such that, if you take 𝑘
 leftmost items and your friend takes the remaining 𝑛−𝑘
 items, each of you and your friend get at least one item, your number of loaves
is different from your friend's, and your number of onions is different from
your friend's. If there are several possible answers, print any of them. If
there are no possible answers, print the number −1
.

Examples
InputCopy
3
LOL
OutputCopy
-1
InputCopy
2
LO
OutputCopy
1
InputCopy
4
LLLO
OutputCopy
1
InputCopy
4
OLOL
OutputCopy
-1
InputCopy
10
LLOOOOLLLO
OutputCopy
5
Note
In the first example, in any division the left and the right part contain one
loaf of bread.

In the second example, the division is 'L' and 'O', and in these two strings the
number of loaves is different (1 and 0) and the number of onions is different (0
and 1).

In the third example, any number 1, 2 or 3 is a correct answer.
*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

/*You get prefix s[0..k-1], friend gets s[k..n-1].

Conditions:
    - Both parts non-empty.
    - #Loaves differ.
    - #Onions differ.

Output a valid k (1 ≤ k ≤ n-1), or -1 if impossible.
*/
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;
  // L represnet bread
  // O onion

  /* If s[0] != s[n-1], answer = 1.

Else answer = n-1.
  - Because you take everything except the last item, friend gets 1 item of the
same type as the first.
  - Then friend’s counts differ from yours.

If that still fails (rare corner case), then print -1.
      */
  long na(0), nb(0);
  for (long p = 0; p < s.size(); p++) {
    if (s[p] == 'L') {
      ++na;
    } else if (s[p] == 'O') {
      ++nb;
    }
  }

  long ans(-1), x(0), y(0);
  for (long p = 0; ans < 0 && p + 1 < s.size(); p++) {
    if (s[p] == 'L') {
      ++x;
    } else if (s[p] == 'O') {
      ++y;
    }
    if ((x != na - x) && (y != nb - y)) {
      ans = p + 1;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1912/335142261!
//
