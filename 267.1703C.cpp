/*C. Cypher
time limit per test1 second
memory limit per test256 megabytes
Luca has a cypher made up of a sequence of 𝑛
wheels, each with a digit 𝑎𝑖
written on it. On the 𝑖
-th wheel, he made 𝑏𝑖
moves. Each move is one of two types:

up move (denoted by 𝚄
): it increases the 𝑖
-th digit by 1
. After applying the up move on 9
, it becomes 0
.
down move (denoted by 𝙳
): it decreases the 𝑖
-th digit by 1
. After applying the down move on 0
, it becomes 9
.
Example for 𝑛=4
. The current sequence is 0 0 0 0.
Luca knows the final sequence of wheels and the moves for each wheel. Help him
find the original sequence and crack the cypher.

Input
The first line contains a single integer 𝑡
(1≤𝑡≤100
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
(1≤𝑛≤100
) — the number of wheels.

The second line contains 𝑛
integers 𝑎𝑖
(0≤𝑎𝑖≤9
) — the digit shown on the 𝑖
-th wheel after all moves have been performed.

Then 𝑛
lines follow, the 𝑖
-th of which contains the integer 𝑏𝑖
(1≤𝑏𝑖≤10
) and 𝑏𝑖
characters that are either 𝚄
or 𝙳
— the number of moves performed on the 𝑖
-th wheel, and the moves performed. 𝚄
and 𝙳
represent an up move and a down move respectively.

Output
For each test case, output 𝑛
space-separated digits  — the initial sequence of the cypher.

Example
InputCopy
3
3
9 3 1
3 DDD
4 UDUU
2 DU
2
0 9
9 DDDDDDDDD
9 UUUUUUUUU
5
0 5 9 8 3
10 UUUUUUUUUU
3 UUD
8 UUDUUDDD
10 UUDUUDUDDU
4 UUUU
OutputCopy
2 1 1
9 0
0 4 9 6 9
Note
In the first test case, we can prove that initial sequence was [2,1,1]
. In that case, the following moves were performed:

On the first wheel: 2−→𝙳1−→𝙳0−→𝙳9
.
On the second wheel: 1−→𝚄2−→𝙳1−→𝚄2−→𝚄3
.
On the third wheel: 1−→𝙳0−→𝚄1
.
The final sequence was [9,3,1]
, which matches the input.

*
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i]; // like a[i] ke corresponding ko input krna h(n--){

    // now given with some final sequence,
    // return original sequence
    // so just do like->
    //  9 3 1
    //  3 DDD
    // 4 UDUU
    // 2 DU
    // D->+1
    // U->>-1
    // 9+3(1)=12
    // 3+3(-1)+1(1)=1
    // 1+1(1)+1(-1)=1
    // ans is 12 1 1-> 2 1 1{if any no exceeds 10, remove 10 from it}
    // ans if goes down 0 then add 10 to it to get the final value
    for (int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      std::string s;
      std::cin >> s;
      int cnt = 0;
      for (int q = 0; q < s.size(); q++) {
        if (s[q] == 'D') {
          ++cnt;
        } else if (s[q] == 'U') {
          --cnt;
        }
      }

      cnt = ((cnt % 10) + 10) % 10;
      a[i] += cnt;
      a[i] = (a[i] + 10) % 10;
    }

    for (long p = 0; p < n; p++) {
      std::cout << a[p] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1703/312676441
