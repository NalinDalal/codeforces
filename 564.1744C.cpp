/*C. Traffic Light
time limit per test1 second
memory limit per test256 megabytes
You find yourself on an unusual crossroad with a weird traffic light. That
traffic light has three possible colors: red (r), yellow (y), green (g). It is
known that the traffic light repeats its colors every 𝑛 seconds and at the 𝑖 -th
second the color 𝑠𝑖 is on.

That way, the order of the colors is described by a string. For example, if 𝑠=
"rggry", then the traffic light works as the following:
red-green-green-red-yellow-red-green-green-red-yellow- ... and so on.

More formally, you are given a string 𝑠1,𝑠2,…,𝑠𝑛
 of length 𝑛
. At the first second the color 𝑠1
 is on, at the second — 𝑠2
, ..., at the 𝑛
-th second the color 𝑠𝑛
 is on, at the 𝑛+1
-st second the color 𝑠1
 is on and so on.

You need to cross the road and that can only be done when the green color is on.

You know which color is on the traffic light at the moment, but you don't know
the current moment of time. You need to find the minimum amount of time in which
you are guaranteed to cross the road.

You can assume that you cross the road immediately.

For example, with 𝑠=
"rggry" and the current color r there are two options: either the green color
will be on after 1 second, or after 3 . That way, the answer is equal to 3 —
that is the number of seconds that we are guaranteed to cross the road, if the
current color is r.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Then the description of the test cases follows.

The first line of each test case contains an integer 𝑛
 and a symbol 𝑐
 (1≤𝑛≤2⋅105
, 𝑐
 is one of allowed traffic light colors r, y or g)— the length of the string 𝑠
 and the current color of the traffic light.

The second line of each test case contains a string 𝑠
 of the length 𝑛
, consisting of the letters r, y and g.

It is guaranteed that the symbol g is in the string 𝑠
 and the symbol 𝑐
 is in the string 𝑠
.

It is guaranteed, that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case output the minimal number of second in which you are
guaranteed to cross the road.

Example
InputCopy
6
5 r
rggry
1 g
g
3 r
rrg
5 y
yrrgy
7 r
rgrgyrg
9 y
rrrgyyygy
OutputCopy
3
0
2
4
1
4
Note
The first test case is explained in the statement.

In the second test case the green color is on so you can cross the road
immediately.

In the third test case, if the red color was on at the second second, then we
would wait for the green color for one second, and if the red light was on at
the first second, then we would wait for the green light for two seconds.

In the fourth test case the longest we would wait for the green color is if we
wait for it starting from the fifth second.
*/

/*Since the string repeats infinitely, we simulate it by duplicating s.

For every position i in s where the character equals c (current color), we:

Look forward to find the next g (green).

Record how long it takes.

Among all possible start positions, take the maximum wait time — this ensures
the worst-case wait is covered.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;

    // To simulate the infinite loop, double the string
    s += s;

    // Precompute distances to next 'g' from every position
    vector<int> next_g(2 * n, -1);
    int last_g = -1;

    for (int i = 2 * n - 1; i >= 0; --i) {
      if (s[i] == 'g') {
        last_g = i;
      }
      next_g[i] = last_g;
    }

    int max_wait = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == c) {
        int wait = next_g[i] - i;
        max_wait = max(max_wait, wait);
      }
    }

    cout << max_wait << '\n';
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1744/332291443
