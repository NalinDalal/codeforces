/*B. Ten Words of Wisdom
time limit per test1 second
memory limit per test256 megabytes
In the game show "Ten Words of Wisdom", there are 𝑛
 participants numbered from 1
 to 𝑛
, each of whom submits one response. The 𝑖
-th response is 𝑎𝑖
 words long and has quality 𝑏𝑖
. No two responses have the same quality, and at least one response has length
at most 10
.

The winner of the show is the response which has the highest quality out of all
responses that are not longer than 10 words. Which response is the winner?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤50
) — the number of responses.

Then 𝑛
 lines follow, the 𝑖
-th of which contains two integers 𝑎𝑖
 and 𝑏𝑖
 (1≤𝑎𝑖,𝑏𝑖≤50
) — the number of words and the quality of the 𝑖
-th response, respectively.

Additional constraints on the input: in each test case, at least one value of 𝑖
 satisfies 𝑎𝑖≤10
, and all values of 𝑏𝑖
 are distinct.

Output
For each test case, output a single line containing one integer 𝑥
 (1≤𝑥≤𝑛
) — the winner of the show, according to the rules given in the statement.

It can be shown that, according to the constraints in the statement, exactly one
winner exists for each test case.

Example
InputCopy
3
5
7 2
12 5
9 3
9 4
10 1
3
1 2
3 4
5 6
1
1 43
OutputCopy
4
3
1
Note
In the first test case, the responses provided are as follows:

Response 1: 7
 words, quality 2
Response 2: 12
 words, quality 5
Response 3: 9
 words, quality 3
Response 4: 9
 words, quality 4
Response 5: 10
 words, quality 1
We can see that the responses with indices 1
, 3
, 4
, and 5
 have lengths not exceeding 10
 words. Out of these responses, the winner is the one with the highest quality.

Comparing the qualities, we find that:

Response 1 has quality 2
.
Response 3 has quality 3
.
Response 4 has quality 4
.
Response 5 has quality 1
.
Among these responses, Response 4 has the highest quality.


*/
#include <iostream>
using std::cin, std::cout, std::endl;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int win = 0, quality = 0;
    for (int i = 1; i <= n; i++) { // Start from 1 to n
      int a, b;
      cin >> a >> b;
      if (a > 10)
        continue;
      if (b > quality) {
        quality = b;
        win = i;
      }
    }
    cout << win << endl;
  }
  return 0;
}

// cout winner of game
// winner-> highest quality{bi is quality}
// word.length<=10
// sub: https://codeforces.com/problemset/submission/1850/308690110
