/* B. Seating in a Bus
time limit per test2 seconds
memory limit per test256 megabytes
In Berland, a bus consists of a row of 𝑛
 seats numbered from 1
 to 𝑛
. Passengers are advised to always board the bus following these rules:

If there are no occupied seats in the bus, a passenger can sit in any free seat;
Otherwise, a passenger should sit in any free seat that has at least one
occupied neighboring seat. In other words, a passenger can sit in a seat with
index 𝑖 (1≤𝑖≤𝑛 ) only if at least one of the seats with indices 𝑖−1 or 𝑖+1 is
occupied. Today, 𝑛 passengers boarded the bus. The array 𝑎 chronologically
records the seat numbers they occupied. That is, 𝑎1 contains the seat number
where the first passenger sat, 𝑎2 — the seat number where the second passenger
sat, and so on.

You know the contents of the array 𝑎
. Determine whether all passengers followed the recommendations.

For example, if 𝑛=5
, and 𝑎
 = [5,4,2,1,3
], then the recommendations were not followed, as the 3
-rd passenger sat in seat number 2
, while the neighboring seats with numbers 1
 and 3
 were free.

Input
The first line of input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The following describes the input test cases.

The first line of each test case contains exactly one integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of seats in the bus and the number of passengers who boarded the
bus.

The second line of each test case contains 𝑛
 distinct integers 𝑎𝑖
 (1≤𝑎𝑖≤𝑛
) — the seats that the passengers occupied in chronological order.

It is guaranteed that the sum of 𝑛
 values across all test cases does not exceed 2⋅105
, and that no passenger sits in an already occupied seat.

Output
For each test case, output on a separate line:

"YES", if all passengers followed the recommendations;
"NO" otherwise.
You may output the answer in any case (for example, the strings "yEs", "yes",
"Yes", and "YES" will be recognized as a positive answer).

Example
InputCopy
4
5
5 4 2 1 3
3
2 3 1
4
2 3 1 4
5
1 2 3 5 4
OutputCopy
NO
YES
YES
NO
Note
The first test case is explained in the problem statement.


*/
#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x;
    cin >> x;
    int left = x - 1, right = x + 1;
    bool rule = true;
    for (int i = 0; i < n; i++) {
      cin >> x;
      if (x == left) {
        --left;
      } else if (x == right) {
        ++right;
      } else {
        rule = false;
      }
    }

    cout << (rule ? "YES" : "NO") << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2000/318309943
