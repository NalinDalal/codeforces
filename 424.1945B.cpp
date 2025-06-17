/*B. Fireworks
time limit per test1 second
memory limit per test256 megabytes
One of the days of the hike coincided with a holiday, so in the evening at the
camp, it was decided to arrange a festive fireworks display. For this purpose,
the organizers of the hike bought two installations for launching fireworks and
a huge number of shells for launching.

Both installations are turned on simultaneously. The first installation launches
fireworks every 𝑎 minutes (i.e., after 𝑎,2⋅𝑎,3⋅𝑎,… minutes after launch). The
second installation launches fireworks every 𝑏 minutes (i.e., after 𝑏,2⋅𝑏,3⋅𝑏,…
 minutes after launch).

Each firework is visible in the sky for 𝑚+1
 minutes after launch, i.e., if a firework was launched after 𝑥
 minutes after the installations were turned on, it will be visible every minute
from 𝑥 to 𝑥+𝑚 , inclusive. If one firework was launched 𝑚 minutes after another,
both fireworks will be visible for one minute.

What is the maximum number of fireworks that could be seen in the sky at the
same time?

Input
Each test consists of several test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. Then follow the descriptions of
the test cases.

The first and only line of each test case contains integers 𝑎
, 𝑏
, 𝑚
 (1≤𝑎,𝑏,𝑚≤1018
) — the frequency of launching for the first installation, the second
installation, and the time the firework is visible in the sky.

Output
For each set of input data, output a single number — the maximum number of
fireworks that can be seen simultaneously.

Example
InputCopy
6
6 7 4
3 4 10
7 8 56
5 6 78123459896
1 1 1
1 1 1000000000000000000
OutputCopy
2
7
17
28645268630
4
2000000000000000002
Note
In the first set of input data, the fireworks are visible in the sky for 5
 minutes. Since the first installation launches fireworks every 6
 minutes, and the second one every 7
 minutes, two fireworks launched from the same installation will not be visible
in the sky at the same time. At the same time, after 7 minutes from the start of
the holiday, one firework from the first and one from the second camp will be
visible. Thus, it is possible to see no more than 2 fireworks simultaneously.

In the third set of input data, 17
 fireworks will be visible after 112
 minutes:

9
 fireworks launched from the first installation at times
[56,63,70,77,84,91,98,105,112
];
8
 fireworks launched from the second installation at times
[56,64,72,80,88,96,104,112
].


*/
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, m;
    cin >> a >> b >> m;
    cout << ((m + a) / a + (m + b) / b) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1945/324717457
