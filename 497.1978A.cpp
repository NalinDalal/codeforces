/*A. Alice and Books
time limit per test1 second
memory limit per test256 megabytes
Alice has 𝑛
 books. The 1
-st book contains 𝑎1
 pages, the 2
-nd book contains 𝑎2
 pages, …
, the 𝑛
-th book contains 𝑎𝑛
 pages. Alice does the following:

She divides all the books into two non-empty piles. Thus, each book ends up in
exactly one of the two piles. Alice reads one book with the highest number in
each pile. Alice loves reading very much. Help her find the maximum total number
of pages she can read by dividing the books into two piles.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤500 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤100
) — the number of books Alice has.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the number of pages in each book.

Output
For each test case, output a single integer — the maximum number of pages Alice
can read.

Example
InputCopy
5
2
1 1
4
2 3 3 1
5
2 2 3 2 2
2
10 3
3
1 2 3
OutputCopy
2
4
5
13
5
Note
In the first test case, Alice can put book number 1
 in the first pile, and book number 2
 in the second pile. Then she will read 𝑎1+𝑎2=1+1=2
 pages.

In the second test case, Alice can put books with numbers 2
 and 3
 in the first pile, and books with numbers 1
 and 4
 in the second pile. Then she will read the book with the highest number 3
 from the first pile, and the book with the highest number 4
 from the second pile. Then she will read 𝑎3+𝑎4=3+1=4
 pages.

*/

#include <iostream>
using namespace std;

int main() {
  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    long x = 0, mx = 0;
    for (long p = 1; p < n; p++) {
      cin >> x;
      mx = (mx > x ? mx : x);
    }
    cin >> x;
    cout << (mx + x) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1978/328807997
