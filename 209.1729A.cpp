/*A. Two Elevators
time limit per test1 second
memory limit per test256 megabytes
Vlad went into his appartment house entrance, now he is on the 1
-th floor. He was going to call the elevator to go up to his apartment.

There are only two elevators in his house. Vlad knows for sure that:

the first elevator is currently on the floor 𝑎
 (it is currently motionless),
the second elevator is located on floor 𝑏
 and goes to floor 𝑐
 (𝑏≠𝑐
). Please note, if 𝑏=1
, then the elevator is already leaving the floor 1
 and Vlad does not have time to enter it.
If you call the first elevator, it will immediately start to go to the floor 1
. If you call the second one, then first it will reach the floor 𝑐
 and only then it will go to the floor 1
. It takes |𝑥−𝑦|
 seconds for each elevator to move from floor 𝑥
 to floor 𝑦
.

Vlad wants to call an elevator that will come to him faster. Help him choose
such an elevator.

Input
The first line of the input contains the only 𝑡
 (1≤𝑡≤104
) — the number of test cases.

This is followed by 𝑡
 lines, three integers each 𝑎
, 𝑏
 and 𝑐
 (1≤𝑎,𝑏,𝑐≤108
, 𝑏≠𝑐
) — floor numbers described in the statement.

Output
Output 𝑡
 numbers, each of which is the answer to the corresponding test case. As an
answer, output:

1
, if it is better to call the first elevator;
2
, if it is better to call the second one;
3
, if it doesn't matter which elevator to call (both elevators will arrive in the
same time). Example InputCopy
3
1 2 3
3 1 2
3 2 1
OutputCopy
1
3
2
Note
In the first test case of the example, the first elevator is already on the
floor of 1
.

In the second test case of the example, when called, the elevators would move as
follows:

At the time of the call, the first elevator is on the floor of 3
, and the second one is on the floor of 1
, but is already going to another floor;
in 1
 second after the call, the first elevator would be on the floor 2
, the second one would also reach the floor 2
 and now can go to the floor 1
;
in 2
 seconds, any elevator would reach the floor 1
.
In the third test case of the example, the first elevator will arrive in 2
 seconds, and the second in 1
.


*/

#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    // time to move from x to y is abs(x-y)
    int first = a - 1;
    first = (first >= 0) ? first : -first;
    int secondA = (b - c), secondB = (c - 1);
    secondA = (secondA >= 0) ? secondA : -secondA;
    secondB = (secondB >= 0) ? secondB : -secondB;
    int second = secondA + secondB;
    if (first < second)
      std::cout << "1" << std::endl;
    else if (first > second)
      std::cout << "2" << std::endl;
    else
      std::cout << "3" << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1729/309855139
