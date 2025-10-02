/*B. Robot Program
time limit per test2 seconds
memory limit per test512 megabytes
There is a robot on the coordinate line. Initially, the robot is located at the
point 𝑥 (𝑥≠0
). The robot has a sequence of commands of length 𝑛
 consisting of characters, where L represents a move to the left by one unit
(from point 𝑝 to point (𝑝−1) ) and R represents a move to the right by one unit
(from point 𝑝 to point (𝑝+1)
).

The robot starts executing this sequence of commands (one command per second, in
the order they are presented). However, whenever the robot reaches the point 0
, the counter of executed commands is reset (i. e. it starts executing the
entire sequence of commands from the very beginning). If the robot has completed
all commands and is not at 0 , it stops.

Your task is to calculate how many times the robot will enter the point 0
 during the next 𝑘
 seconds.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of a test case contains three integers 𝑛
, 𝑥
 and 𝑘
 (1≤𝑛≤2⋅105
; −𝑛≤𝑥≤𝑛
; 𝑛≤𝑘≤1018
).

The second line of a test case contains a string 𝑠
 consisting of 𝑛
 characters L and/or R.

Additional constraint on the input: the sum of 𝑛
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case, print a single integer — the number of times the robot will
enter the point 0 during the next 𝑘 seconds.

Example
InputCopy
6
3 2 6
LLR
2 -1 8
RL
4 -2 5
LRRR
5 3 7
LRRLL
1 1 1
L
3 -1 4846549234412827
RLR
OutputCopy
1
4
1
0
1
2423274617206414
Note
In the first example, the robot moves as follows: 2→1→0⎯⎯→−1→−2→−1
. The robot has completed all instructions from the sequence and is not at 0
. So it stops after 5
 seconds and the point 0
 is entered once.

In the second example, the robot moves as follows: −1→0⎯⎯→1→0⎯⎯→1→0⎯⎯→1→0⎯⎯→1
. The robot worked 8
 seconds and the point 0
 is entered 4
 times.

In the third example, the robot moves as follows: −2→−3→−2→−1→0⎯⎯→−1
. The robot worked 5
 seconds and the point 0
 is entered once.

In the fourth example, the robot moves as follows: 3→2→3→4→3→2
. The robot has completed all instructions from the sequence and is not at 0
. So it stops after 5
 seconds, without reaching the point 0
.
*/

#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  while (t--) {
    int n, x, k;
    std::cin >> n >> x >> k;
    std::string s;
    std::cin >> s;

    for (int p = 0; x && p < s.size(); p++) {
      x += (s[p] == 'R') - (s[p] == 'L');
      --k;
    }

    if (x) {
      std::cout << "0" << std::endl;
      continue;
    }

    int res(1);
    for (int p = 0; p < n; p++) {
      x += (s[p] == 'R') - (s[p] == 'L');
      if (!x) {
        res += k / (p + 1);
        break;
      }
    }

    std::cout << res << std::endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/2070/341489202
