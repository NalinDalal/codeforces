/*B. Journey
time limit per test1 second
memory limit per test256 megabytes
Monocarp decided to embark on a long hiking journey.

He decided that on the first day he would walk 𝑎
 kilometers, on the second day he would walk 𝑏
 kilometers, on the third day he would walk 𝑐
 kilometers, on the fourth day, just like on the first, he would walk 𝑎
 kilometers, on the fifth day, just like on the second, he would walk 𝑏
 kilometers, on the sixth day, just like on the third, he would walk 𝑐
 kilometers, and so on.

Monocarp will complete his journey on the day when he has walked at least 𝑛
 kilometers in total. Your task is to determine the day on which Monocarp will
complete his journey.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case consists of one line containing four integers 𝑛
, 𝑎
, 𝑏
, 𝑐
 (1≤𝑛≤109
; 1≤𝑎,𝑏,𝑐≤106
).

Output
For each test case, output one integer — the day on which Monocarp will have
walked at least 𝑛 kilometers in total and will complete his journey.

Example
InputCopy
4
12 1 5 3
6 6 7 4
16 3 4 1
1000000000 1 1 1
OutputCopy
5
1
6
1000000000
Note
In the first example, over the first four days, Monocarp will cover 1+5+3+1=10
 kilometers. On the fifth day, he will cover another 5
 kilometers, meaning that in total over five days he will have covered 10+5=15
 kilometers. Since 𝑛=12
, Monocarp will complete his journey on the fifth day.

In the second example, Monocarp will cover 6
 kilometers on the first day. Since 𝑛=6
, Monocarp will complete his journey on the very first day.

In the third example, Monocarp will cover 3+4+1+3+4+1=16
 kilometers over the first six days. Since 𝑛=16
, Monocarp will complete his journey on the sixth day.



*/

/*#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, a, b, c;
    std::cin >> n >> a >> b >> c;
    // need to walk n total
    // 1st day - a km
    // 2nd - b km
    // 3rd - c km
    // how many days to complete journey
    int distances[] = {a, b, c}; // Distances for 3-day cycle
    int ans = 0, i = 0;
    while (n > 0) {
      // 1st remove a, then b then c
      // remove till n!<=0
      // return count
      n -= distances[i]; // Walk on the current day's distance
      ans++;             // Increase day count
      i = (i + 1) % 3;   // Cycle through 3 days
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
//tle
*/

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int distances[] = {a, b, c}; // Distances for 3-day cycle
    int cycle_sum = a + b + c;   // Total distance in one full cycle
    int days = 0;

    // Use full cycles to reduce `n` efficiently
    if (n >= cycle_sum) {
      int full_cycles = n / cycle_sum;
      days += full_cycles * 3;
      n -= full_cycles * cycle_sum;
    }

    // Handle the remaining distance
    int i = 0;
    while (n > 0) {
      n -= distances[i]; // Walk the distance for the current day
      days++;            // Increment the day count
      i = (i + 1) % 3;   // Move to the next day in the cycle
    }

    cout << days << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2051/313098529
