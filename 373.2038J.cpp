/* J. Waiting for...
time limit per test2 seconds
memory limit per test512 megabytes
Monocarp is waiting for a bus at the bus stop. Unfortunately, there are many
people who want to ride a bus too.

You are given a list of events of two types:

B 𝑏𝑖
 — a bus with 𝑏𝑖
 free seats arrives at the stop;
P 𝑝𝑖
 — 𝑝𝑖
 people arrive at the stop.
These events are listed in a chronological order.

When a bus arrives, the following happens. All people at the bus stop (except
for Monocarp) try to enter the bus. If there are enough free seats for all of
them, then they all enter the bus. Otherwise, some people remain at the bus stop
(the number of people who enter the bus is equal to the number of free seats).

If there is still at least one free seat after all people (except for Monocarp)
enter the bus, then Monocarp can decide to enter this bus as well (but he might
choose to wait for another bus). For each bus, you have to determine if it is
possible for Monocarp to take that bus.

Input
The first line contains one integer 𝑛
 (1≤𝑛≤103)
 — the number of events.

Then, 𝑛
 lines follow. The 𝑖
-th of them contains the description of the 𝑖
-th event in one of the two following formats:

B 𝑏𝑖
 (1≤𝑏𝑖≤106
) — a bus with 𝑏𝑖
 free seats arrives at the stop;
P 𝑝𝑖
 (1≤𝑝𝑖≤106
) — 𝑝𝑖
 people arrive at the stop.
Additional constraint on the input: there is at least one event of type B.

Output
For each event of type B, print YES if it is possible for Monocarp to take the
corresponding bus, or NO otherwise (case-insensitive).

Example
InputCopy
10
P 2
P 5
B 8
P 14
B 5
B 9
B 3
P 2
B 1
B 2
OutputCopy
YES
NO
NO
YES
NO
YES

*/
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int waiting_people = 0;

  while (n--) {
    char type;
    int count;
    cin >> type >> count;
    // now For each event of type B, print YES if it is possible for Monocarp to
    // take the corresponding bus, or NO otherwise (case-insensitive).

    if (type == 'P') {
      waiting_people += count;
    } else if (type == 'B') {
      // Let all people (except Monocarp) try to enter
      if (waiting_people >= count) {
        waiting_people -= count;
        cout << "NO" << endl; // No seats left for Monocarp
      } else {
        int remaining_seats = count - waiting_people;
        waiting_people = 0;
        // If at least one seat remains, Monocarp can get in
        cout << (remaining_seats >= 1 ? "YES" : "NO") << endl;
      }
    }
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/2038/321657314
