/*B. Arranging Cats
time limit per test2 seconds
memory limit per test512 megabytes
In order to test the hypothesis about the cats, the scientists must arrange the
cats in the boxes in a specific way. Of course, they would like to test the
hypothesis and publish a sensational article as quickly as possible, because
they are too engrossed in the next hypothesis about the phone's battery charge.

Scientists have 𝑛
 boxes in which cats may or may not sit. Let the current state of the boxes be
denoted by the sequence 𝑏1,…,𝑏𝑛 : 𝑏𝑖=1 if there is a cat in box number 𝑖 , and
𝑏𝑖=0 otherwise.

Fortunately, the unlimited production of cats has already been established, so
in one day, the scientists can perform one of the following operations:

Take a new cat and place it in a box (for some 𝑖
 such that 𝑏𝑖=0
, assign 𝑏𝑖=1
).
Remove a cat from a box and send it into retirement (for some 𝑖
 such that 𝑏𝑖=1
, assign 𝑏𝑖=0
).
Move a cat from one box to another (for some 𝑖,𝑗
 such that 𝑏𝑖=1,𝑏𝑗=0
, assign 𝑏𝑖=0,𝑏𝑗=1
).
It has also been found that some boxes were immediately filled with cats.
Therefore, the scientists know the initial position of the cats in the boxes
𝑠1,…,𝑠𝑛 and the desired position 𝑓1,…,𝑓𝑛
.

Due to the large amount of paperwork, the scientists do not have time to solve
this problem. Help them for the sake of science and indicate the minimum number
of days required to test the hypothesis.

Input
Each test consists of several test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. This is followed by
descriptions of the test cases.

Each test case consists of three lines.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤105
) — the number of boxes.

The second line of each test case contains a string 𝑠
 of 𝑛
 characters, where the 𝑖
-th character is '1' if there is a cat in the 𝑖
-th box and '0' otherwise.

The third line of each test case contains a string 𝑓
 of 𝑛
 characters, where the 𝑖
-th character is '1' if there should be a cat in the 𝑖
-th box and '0' otherwise.

It is guaranteed that in a test the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output a single integer on a separate line — the minimum
number of operations required to obtain the desired position from the initial
position. It can be shown that a solution always exists.

Example
InputCopy
6
5
10010
00001
1
1
1
3
000
111
4
0101
1010
3
100
101
8
10011001
11111110
OutputCopy
2
0
3
2
1
4
Note
In the first test case, you can first move the cat from the first box to the
fifth, and then remove the cat from the fourth box.

In the second test case, there is nothing to do — the only cat is already
sitting in the correct box.

In the third test case of input data, it takes three days to place a cat in each
box.

*/

/*traverse the string s and final string f
 mismatch 1->0 extra cat
 mismatch 0->1 issing cat
 If both types of mismatches exist, we can pair them up into moves instead of
 separate add/remove steps.

 hence Minimum days = max(extra_cats, missing_cats)

 if(s[i] == '1' and f[i] == '0') extra_cats++;
 if(s[i] == '0' and f[i] == '1') missing_cats++;

 Answer = max(extra_cats, missing_cats).


*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, f;
    cin >> s >> f;

    int extra = 0, missing = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1' && f[i] == '0')
        extra++;
      if (s[i] == '0' && f[i] == '1')
        missing++;
    }
    cout << max(extra, missing) << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1921/333086440
