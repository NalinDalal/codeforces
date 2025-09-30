/*C1. Adjust The Presentation (Easy Version)
time limit per test2 seconds
memory limit per test256 megabytes
This is the easy version of the problem. In the two versions, the constraints on
𝑞 and the time limit are different. In this version, 𝑞=0 . You can make hacks
only if all the versions of the problem are solved.

A team consisting of 𝑛
 members, numbered from 1
 to 𝑛
, is set to present a slide show at a large meeting. The slide show contains 𝑚
 slides.

There is an array 𝑎
 of length 𝑛
. Initially, the members are standing in a line in the order of 𝑎1,𝑎2,…,𝑎𝑛
 from front to back. The slide show will be presented in order from slide 1
 to slide 𝑚
. Each section will be presented by the member at the front of the line. After
each slide is presented, you can move the member at the front of the line to any
position in the lineup (without changing the order of the rest of the members).
For example, suppose the line of members is [3,1,2,4] . After member 3 presents
the current slide, you can change the line of members into either [3,1,2,4] ,
[1,3,2,4] , [1,2,3,4] or [1,2,4,3]
.

There is also an array 𝑏
 of length 𝑚
. The slide show is considered good if it is possible to make member 𝑏𝑖
 present slide 𝑖
 for all 𝑖
 from 1
 to 𝑚
 under these constraints.

However, your annoying boss wants to make 𝑞
 updates to the array 𝑏
. In the 𝑖
-th update, he will choose a slide 𝑠𝑖
 and a member 𝑡𝑖
 and set 𝑏𝑠𝑖:=𝑡𝑖
. Note that these updates are persistent, that is changes made to the array 𝑏
 will apply when processing future updates.

For each of the 𝑞+1
 states of array 𝑏
, the initial state and after each of the 𝑞
 updates, determine if the slideshow is good.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains three integers 𝑛
, 𝑚
 and 𝑞
 (1≤𝑛,𝑚≤2⋅105
; 𝑞=0
) — the number of members, the number of sections and the number of updates.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
) — the initial order of the members from front to back. It is guaranteed that
each integer from 1 to 𝑛 appears exactly once in 𝑎
.

The third line of each test case contains 𝑚
 integers 𝑏1,𝑏2,…,𝑏𝑚
 (1≤𝑏𝑖≤𝑛
) — the members who should present each section.

It is guaranteed that the sum of 𝑛
 and the sum of 𝑚
 over all test cases do not exceed 2⋅105
 respectively.

Output
For each test case, output 𝑞+1
 lines corresponding to the 𝑞+1
 states of the array 𝑏
. Output "YA" if the slide show is good, and "TIDAK" otherwise.

You can output the answer in any case (upper or lower). For example, the strings
"yA", "Ya", "ya", and "YA" will be recognized as positive responses.

Example
InputCopy
3
4 2 0
1 2 3 4
1 1
3 6 0
1 2 3
1 1 2 3 3 2
4 6 0
3 1 4 2
3 1 1 2 3 4
OutputCopy
YA
YA
TIDAK
Note
For the first test case, you do not need to move the members as both slides are
presented by member 1 , who is already at the front of the line.

For the second test case, the following is a possible way to move members so
that the presentation is good:

[1,2,3]
, do not move member 1
.
[1,2,3]
, move member 1
 after member 3
.
[2,3,1]
, move member 2
 after member 3
.
[3,2,1]
, do not move member 3
.
[3,2,1]
, move member 3
 after member 1
.
[2,1,3]
, do not move member 2
.



*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<int> a(n);
  for (auto &it : a)
    cin >> it;

  vector<int> b(m);
  for (auto &it : b)
    cin >> it;

  // store index of each element in a
  vector<int> pos(n + 1);
  for (int i = 0; i < n; i++) {
    pos[a[i]] = i;
  }

  int cnt = 0;
  unordered_set<int> seen;

  for (int i = 0; i < m; i++) {
    int req = pos[b[i]];
    if (seen.count(b[i]))
      continue;

    if (cnt == req) {
      cnt++;
      seen.insert(b[i]);
    } else {
      cout << "TIDAK\n";
      return;
    }
  }

  cout << "YA\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
// sub: https://codeforces.com/problemset/submission/2021/341157871
