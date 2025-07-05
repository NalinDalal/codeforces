/*A. Circuit
time limit per test1 second
memory limit per test256 megabytes
Alice has just crafted a circuit with 𝑛
 lights and 2𝑛
 switches. Each component (a light or a switch) has two states: on or off. The
lights and switches are arranged in a way that:

Each light is connected to exactly two switches.
Each switch is connected to exactly one light. It's unknown which light each
switch is connected to. When all switches are off, all lights are also off. If a
switch is toggled (from on to off, or vice versa), the state of the light
connected to it will also toggle. Alice brings the circuit, which shows only the
states of the 2𝑛 switches, to her sister Iris and gives her a riddle: what is
the minimum and maximum number of lights that can be turned on?

Knowing her little sister's antics too well, Iris takes no more than a second to
give Alice a correct answer. Can you do the same?

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤500 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤50
) — the number of lights in the circuit.

The second line of each test case contains 2𝑛
 integers 𝑎1,𝑎2,…,𝑎2𝑛
 (0≤𝑎𝑖≤1
) — the states of the switches in the circuit. 𝑎𝑖=0
 means the 𝑖
-th switch is off, and 𝑎𝑖=1
 means the 𝑖
-th switch is on.

Output
For each test case, output two integers — the minimum and maximum number of
lights, respectively, that can be turned on.

Example
InputCopy
5
1
0 0
1
0 1
1
1 1
3
0 0 1 0 1 0
3
0 1 1 1 0 0
OutputCopy
0 0
1 1
0 0
0 2
1 3
Note
In the first test case, there is only one light in the circuit, and no switch is
on, so the light is certainly off.

In the second test case, there is only one light in the circuit, but one switch
connected to it is on, so the light is on.

In the third test case, there is only one light in the circuit, and both
switches are on, so the light is off as it was toggled twice.

In the fourth test case, to have no lights on, the switches can be arranged in
this way:

Switch 1
 and switch 4
 are connected to light 1
. Since both switches are off, light 1
 is also off.
Switch 2
 and switch 6
 are connected to light 2
. Since both switches are off, light 2
 is also off.
Switch 3
 and switch 5
 are connected to light 3
. Both switches are on, so light 3
 is toggled twice from its initial off state, and thus also stays off.
And to have 2
 lights on, the switches can be arranged in this way:

Switch 1
 and switch 2
 are connected to light 1
. Since both switches are off, light 1
 is also off.
Switch 3
 and switch 4
 are connected to light 2
. Since switch 3
 is on and switch 4
 is off, light 2
 is toggled once from its initial off state, so it is on.
Switch 5
 and switch 6
 are connected to light 3
. Since switch 5
 is on and switch 6
 is off, light 3
 is toggled once from its initial off state, so it is on.
*/

#include <iostream>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    long a = 0, z = 0;
    for (long p = 0; p < 2 * n; p++) {
      int x;
      std::cin >> x;
      a += x;
      z += (!x);
    }
    std::cout << (a % 2) << " " << (a < z ? a : z) << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/2032/327530842
