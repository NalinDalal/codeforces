/* A. Treasure Hunt
time limit per test1 second
memory limit per test256 megabytes
Little B and his friend Little K found a treasure map, and now they just need to
dig up the treasure, which is buried at a depth of 𝑎.5 meters.

They take turns digging. On the first day, Little B digs; on the second day,
Little K. After each day, they switch. Little B digs exactly 𝑥 meters of soil
each day, while Little K digs 𝑦 meters. They became curious about who will dig
up the treasure first, meaning during whose day the total dug depth will exceed
𝑎.5
.

But they are too busy digging, so help them and tell who will dig up the
treasure!

Input
The first line contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases. The description of the test cases follows.

In a single line of each test case, three integers 𝑥,𝑦,𝑎
 are given (1≤𝑥,𝑦,𝑎≤109
).

Output
For each test case, output "NO" if Little B digs it up first; otherwise, output
"YES". You can output the answer in any case.

Example
InputCopy
3
1 2 4
2 1 4
2 2 1
OutputCopy
YES
NO
NO
Note
In the first test case, on the first day they will dig 1
 meter; on the second day 1+2=3
 meters in total; on the third day 1+2+1=4
 meters; and on the fourth day they will dig 6
 meters. Thus, the treasure will be dug up first by Little K.

In the second test case, on the first day they will dig 2
 meters; on the second day 2+1=3
 meters in total; on the third day 2+1+2=5
 meters, meaning it was dug up first by Little B.


*/
#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    long x, y, a;
    std::cin >> x >> y >> a;
    a %= (x + y);
    std::cout << (a < x ? "NO" : "YES");
  }
}
// sub: https://codeforces.com/problemset/submission/2090/314158771
