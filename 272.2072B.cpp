/*B. Having Been a Treasurer in the Past, I Help Goblins Deceive
time limit per test2 seconds
memory limit per test256 megabytes
After completing the first quest, Akito left the starting cave. After a while,
he stumbled upon a goblin village.

Since Akito had nowhere to live, he wanted to find out the price of housing. It
is well known that goblins write numbers as a string of characters '-' and '_',
and the value represented by the string 𝑠 is the number of distinct
subsequences∗ of the string 𝑠 that are equal to the string "-_-" (this is very
similar to goblin faces).

For example, the string 𝑠=
"-_--_-" represents the number 6
, as it has 6
 subsequences "-_-":

𝑠1+𝑠2+𝑠3
𝑠1+𝑠2+𝑠4
𝑠1+𝑠2+𝑠6
𝑠1+𝑠5+𝑠6
𝑠3+𝑠5+𝑠6
𝑠4+𝑠5+𝑠6
Initially, the goblins wrote a random string-number 𝑠
 in response to Akito's question, but then they realized that they wanted to
take as much gold as possible from the traveler. To do this, they ask you to
rearrange the characters in the string 𝑠 so that the value of the number
represented by the string 𝑠 is maximized.

∗
A subsequence of a string 𝑎
 is a string 𝑏
 that can be obtained by deleting several (possibly 0
) characters from 𝑎
. Subsequences are considered different if they are obtained by deleting
different sets of indices.

Input
The first line contains the number 𝑡
 (1≤𝑡≤104
) — the number of test cases.

In the first line of each test case, there is one number 𝑛
 (1≤𝑛≤2⋅105
) — the length of the string written by the goblins.

In the second line of each test case, there is a string 𝑠
 of length 𝑛
, consisting only of characters '-' and '_' — the string written by the goblins.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
For each test case, you need to output one number — the maximum number of
subsequences equal to the string "-_-", if the characters in the string 𝑠 are
optimally rearranged.

Example
InputCopy
8
3
--_
5
__-__
9
--__-_---
4
_--_
10
_-_-_-_-_-
7
_------
1
-
2
_-
OutputCopy
1
0
27
2
30
9
0
0
Note
In the first test case, it is beneficial to rearrange the characters to form the
string "-_-". This is the only string of three characters that has at least one
subsequence "-_-".

In the second test case, there is only one character "-", and at least two are
needed for the subsequence "-_-". This means that for any rearrangement of
characters, the answer will be 0
.

In the seventh and eighth test cases, the length of the string 𝑛<3
, which means that subsequences of length 3
 do not exist.



*/
#include <iostream>
using namespace std;

void solve() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int dash_count = 0, underscore_count = 0;

    // Count occurrences of '-' and '_'
    for (char c : s) {
      if (c == '-')
        dash_count++;
      else
        underscore_count++;
    }

    // If there are not enough '-' or no '_', it's impossible
    if (dash_count < 2 || underscore_count == 0) {
      cout << 0 << endl;
    } else {
      // Split dashes into two groups for max subsequences
      int left_dash = dash_count / 2;
      int right_dash = dash_count - left_dash;
      long long max_sequences = 1LL * left_dash * right_dash * underscore_count;
      cout << max_sequences << endl;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
// sub:https://codeforces.com/problemset/submission/2072/312765040
