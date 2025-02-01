/* https://codeforces.com/problemset/problem/1875/A

A. Jellyfish and Undertale
time limit per test1 second
memory limit per test256 megabytes
Flowey has planted a bomb in Snowdin!

The bomb has a timer that is initially set to 𝑏
. Every second, the timer will decrease by 1
. When the timer reaches 0
, the bomb will explode! To give the residents of Snowdin enough time to
evacuate, you will need to delay the bomb from exploding for as long as
possible.

You have 𝑛
 tools. Each tool can only be used at most once. If you use the 𝑖
-th tool, the timer will increase by 𝑥𝑖
. However, if the timer is changed to an integer larger than 𝑎
, the timer will be set to 𝑎
 due to a bug.

More specifically, the following events will happen every second in the
following order:

You will choose some (possibly none) of your tools that have not been used
before. If you choose the 𝑖 -th tool, and the bomb's timer is currently set to 𝑐
, the timer will be changed to min(𝑐+𝑥𝑖,𝑎)
.
The timer decreases by 1
.
If the timer reaches 0
, the bomb explodes.
Jellyfish now wants to know the maximum time in seconds until the bomb explodes
if the tools are used optimally.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤2000
). The description of the test cases follows.

The first line of each test case contains three integers 𝑎
, 𝑏
 and 𝑛
 (1≤𝑏≤𝑎≤109
, 1≤𝑛≤100
) — the maximum value of the bomb's timer, the initial value of the timer of the
bomb and the number of tools.

The second line of each test contains 𝑛
 integers 𝑥1,𝑥2,…,𝑥𝑛
 (1≤𝑥𝑖≤109
) — the number the timer can increase by using the 𝑖
-th tool.

Note that the sum of 𝑛
 over all test cases is not bounded.

Output
For each test case, output a single integer — the maximum time in seconds until
the bomb explodes.

Example
InputCopy
2
5 3 3
1 1 7
7 1 5
1 2 5 6 8
OutputCopy
9
21
Note
Let 𝑐
 denote the value of the bomb's timer. In the first test case:

Second 1
: choose tool 1
 and 2
 at this second, then 𝑐=5
; the timer decreases by 1
, then 𝑐=4
.
Second 2
: the timer decreases by 1
, then 𝑐=3
.
Second 3
: the timer decreases by 1
, then 𝑐=2
.
Second 4
: the timer decreases by 1
, then 𝑐=1
.
Second 5
: choose tool 3
, then 𝑐=5
; the timer decreases by 1
, then 𝑐=4
.
Second 6
: the timer decreases by 1
, then 𝑐=3
.
Second 7
: the timer decreases by 1
, then 𝑐=2
.
Second 8
: the timer decreases by 1
, then 𝑐=1
.
Second 9
: the timer decreases by 1
, then 𝑐=0
. The bomb explodes.
It can be proved that there is no way to use the tools such that the bomb
explodes after more than 9 seconds.



*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, n;
    cin >> a >> b >> n;

    // a is maximum value of timer
    // b is intial value of timer
    // n is number of tools
    long long v(b);
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v += (x < (a - 1)) ? x : (a - 1);
    }
    // c is current time
    // choose ith item
    // update timer from c to min(c+v[i],a)
    // decrease timer by 1
    // if timer==0 then bomb explodes

    // return maxtimer

    cout << v << endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1875/303946154
