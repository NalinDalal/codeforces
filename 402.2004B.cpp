/* B. Game with Doors
time limit per test2 seconds
memory limit per test256 megabytes
There are 100
 rooms arranged in a row and 99
 doors between them; the 𝑖
-th door connects rooms 𝑖
 and 𝑖+1
. Each door can be either locked or unlocked. Initially, all doors are unlocked.

We say that room 𝑥
 is reachable from room 𝑦
 if all doors between them are unlocked.

You know that:

Alice is in some room from the segment [𝑙,𝑟]
;
Bob is in some room from the segment [𝐿,𝑅]
;
Alice and Bob are in different rooms.
However, you don't know the exact rooms they are in.

You don't want Alice and Bob to be able to reach each other, so you are going to
lock some doors to prevent that. What's the smallest number of doors you have to
lock so that Alice and Bob cannot meet, regardless of their starting positions
inside the given segments?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑙
 and 𝑟
 (1≤𝑙<𝑟≤100
) — the bounds of the segment of rooms where Alice is located.

The second line of each test case contains two integers 𝐿
 and 𝑅
 (1≤𝐿<𝑅≤100
) — the bounds of the segment of rooms where Bob is located.

Output
For each test case, print a single integer — the smallest number of doors you
have to lock so that Alice and Bob cannot meet, regardless of their starting
positions inside the given segments.

Example
InputCopy
4
1 2
3 4
2 5
2 5
3 7
6 7
4 5
2 8
OutputCopy
1
3
2
3
Note
In the first test case, it is sufficient to lock the door between rooms 2
 and 3
.

In the second test case, the following doors have to be locked: (2,3)
, (3,4)
, (4,5)
.

In the third test case, the following doors have to be locked: (5,6)
 and (6,7)
.


*/

#include <iostream>
using namespace std;

int main() {

  long t;
  cin >> t;
  while (t--) {
    long l, r;
    cin >> l >> r;
    long L, R;
    cin >> L >> R;
    long mxl = (l > L ? l : L);
    long mnr = (r < R ? r : R);
    long len = (mnr - mxl);
    long res = len + (l != L) + (r != R);
    res = (len >= 0 ? res : 1);
    cout << res << endl;
  }
}
// sub: https://codeforces.com/problemset/submission/2004/323580573
