/* https://codeforces.com/problemset/problem/1858/A
### Problem: Buttons

#### Time Limit:
1 second per test.

#### Memory Limit:
256 megabytes.

Anna and Katie are in a secret laboratory with a set of buttons. There are 𝑎 + 𝑏
+ 𝑐 buttons in total. Out of these:

- 𝑎 buttons can only be pressed by Anna,
- 𝑏 buttons can only be pressed by Katie,
- 𝑐 buttons can be pressed by either of them.

The game proceeds as follows:

- Anna and Katie take turns pressing the buttons, with Anna making the first
move.
- Each button can be pressed at most once. So, at some point, one of the girls
may no longer have a button to press.
- The player who cannot make a move loses the game.

The task is to determine who will win if both girls play optimally.

#### Input:
- The first line contains a single integer 𝑡 (1 ≤ 𝑡 ≤ 10⁴) — the number of test
cases.
- Each test case consists of three integers 𝑎, 𝑏, and 𝑐 (1 ≤ 𝑎, 𝑏, 𝑐 ≤ 10⁹) —
the number of buttons that only Anna can press, the number of buttons that only
Katie can press, and the number of buttons that can be pressed by either of
them.

#### Output:
For each test case, print "First" if Anna wins, or "Second" if Katie wins.

#### Example Input:
```
5
1 1 1
9 3 3
1 2 3
6 6 9
2 2 8
```

#### Example Output:
```
First
First
Second
First
Second
```*/
/* #include <cstdio>

int main(){

    long t; scanf("%ld", &t);
    while(t--){
        long a, b, c; scanf("%ld %ld %ld\n", &a, &b, &c);
        puts((a + (c % 2) > b) ? "First" : "Second");
    }

}*/

#include <iostream>
using namespace std;
int main() {
  long t;
  cin >> t;
  while (t--) {
    long a, b, c;
    cin >> a >> b >> c;
    if (a + (c % 2) > b) {
      cout << "First" << endl;
    } else {
      cout << "Second" << endl;
    }
  }
  return 0;
}
