/*A. Cards for Friends
time limit per test1 second
memory limit per test256 megabytes
For the New Year, Polycarp decided to send postcards to all his 𝑛
 friends. He wants to make postcards with his own hands. For this purpose, he
has a sheet of paper of size 𝑤×ℎ , which can be cut into pieces.

Polycarp can cut any sheet of paper 𝑤×ℎ
 that he has in only two cases:

If 𝑤
 is even, then he can cut the sheet in half and get two sheets of size 𝑤2×ℎ
;
If ℎ
 is even, then he can cut the sheet in half and get two sheets of size 𝑤×ℎ2
;
If 𝑤
 and ℎ
 are even at the same time, then Polycarp can cut the sheet according to any of
the rules above.

After cutting a sheet of paper, the total number of sheets of paper is increased
by 1
.

Help Polycarp to find out if he can cut his sheet of size 𝑤×ℎ
 at into 𝑛
 or more pieces, using only the rules described above.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. Then 𝑡
 test cases follow.

Each test case consists of one line containing three integers 𝑤
, ℎ
, 𝑛
 (1≤𝑤,ℎ≤104,1≤𝑛≤109
) — the width and height of the sheet Polycarp has and the number of friends he
needs to send a postcard to.

Output
For each test case, output on a separate line:

"YES", if it is possible to cut a sheet of size 𝑤×ℎ
 into at least 𝑛
 pieces;
"NO" otherwise.
You can output "YES" and "NO" in any case (for example, the strings yEs, yes,
Yes and YES will be recognized as positive).

Example
InputCopy
5
2 2 3
3 3 2
5 10 2
11 13 1
1 4 4
OutputCopy
YES
NO
YES
YES
YES
Note
In the first test case, you can first cut the 2×2
 sheet into two 2×1
 sheets, and then cut each of them into two more sheets. As a result, we get
four sheets 1×1 . We can choose any three of them and send them to our friends.

In the second test case, a 3×3
 sheet cannot be cut, so it is impossible to get two sheets.

In the third test case, you can cut a 5×10
 sheet into two 5×5
 sheets.

In the fourth test case, there is no need to cut the sheet, since we only need
one sheet.

In the fifth test case, you can first cut the 1×4
 sheet into two 1×2
 sheets, and then cut each of them into two more sheets. As a result, we get
four sheets 1×1
.*/
#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int w, h, n;
    cin >> w >> h >> n;
    int s = w * h;
    int cnt = 1;
    while (s % 2 == 0) {
      cnt *= 2;
      s /= 2;
    }
    cout << (cnt >= n ? "YES" : "NO") << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1472/309637202
