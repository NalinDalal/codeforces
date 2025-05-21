/* A. Deadline
time limit per test2 seconds
memory limit per test256 megabytes
Adilbek was assigned to a special project. For Adilbek it means that he has 𝑛
 days to run a special program and provide its results. But there is a problem:
the program needs to run for 𝑑 days to calculate the results.

Fortunately, Adilbek can optimize the program. If he spends 𝑥
 (𝑥
 is a non-negative integer) days optimizing the program, he will make the
program run in ⌈𝑑𝑥+1⌉ days (⌈𝑎⌉ is the ceiling function: ⌈2.4⌉=3 , ⌈2⌉=2
). The program cannot be run and optimized simultaneously, so the total number
of days he will spend is equal to 𝑥+⌈𝑑𝑥+1⌉
.

Will Adilbek be able to provide the generated results in no more than 𝑛
 days?

Input
The first line contains a single integer 𝑇
 (1≤𝑇≤50
) — the number of test cases.

The next 𝑇
 lines contain test cases – one per line. Each line contains two integers 𝑛
 and 𝑑
 (1≤𝑛≤109
, 1≤𝑑≤109
) — the number of days before the deadline and the number of days the program
runs.

Output
Print 𝑇
 answers — one per test case. For each test case print YES (case insensitive) if
Adilbek can fit in 𝑛 days or NO (case insensitive) otherwise.

Example
InputCopy
3
1 1
4 5
5 11
OutputCopy
YES
YES
NO
Note
In the first test case, Adilbek decides not to optimize the program at all,
since 𝑑≤𝑛
.

In the second test case, Adilbek can spend 1
 day optimizing the program and it will run ⌈52⌉=3
 days. In total, he will spend 4
 days and will fit in the limit.

In the third test case, it's impossible to fit in the limit. For example, if
Adilbek will optimize the program 2 days, it'll still work ⌈112+1⌉=4 days.


*/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    // spend x days to optimise
    // run the program in ceil(d/x+1) days
    // print YES if fits in n days
    // else print NO
    bool ans = false;
    for (int i = 0; i * i <= d + 10; i++) {
      int u = i + (d + i) / (i + 1);
      if (u <= n) {
        ans = true;
        break;
      }
    }
    cout << (ans ? "YES" : "NO") << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1288/320675454
