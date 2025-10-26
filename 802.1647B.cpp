/*B. Madoka and the Elegant Gift
time limit per test1 second
memory limit per test256 megabytes
Madoka's father just reached 1
 million subscribers on Mathub! So the website decided to send him a
personalized award — The Mathhub's Bit Button!

The Bit Button is a rectangular table with 𝑛
 rows and 𝑚
 columns with 0
 or 1
 in each cell. After exploring the table Madoka found out that:

A subrectangle 𝐴
 is contained in a subrectangle 𝐵
 if there's no cell contained in 𝐴
 but not contained in 𝐵
.
Two subrectangles intersect if there is a cell contained in both of them.
A subrectangle is called black if there's no cell with value 0
 inside it.
A subrectangle is called nice if it's black and it's not contained in another
black subrectangle. The table is called elegant if there are no two nice
intersecting subrectangles. For example, in the first illustration the red
subrectangle is nice, but in the second one it's not, because it's contained in
the purple subrectangle.


Help Madoka to determine whether the table is elegant.

Input
Each test contains multiple test cases. The first line contains a single integer
𝑡 (1≤𝑡≤200 ) — the number of test cases. Description of the test cases follows.

The first line of each test case contains two positive integers 𝑛,𝑚
 (1≤𝑛,𝑚≤100
).

The next 𝑛
 lines contain strings of length 𝑚
 consisting of zeros and ones — the description of the table.

It is guaranteed that the sum of the values of 𝑛
 and the sum of the values of 𝑚
 for all test cases do not exceed 777
.

Output
For each test case print "YES" if its table is elegant or print "NO" otherwise.

You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs"
will all be recognized as positive answer).

Example
InputCopy
5
3 3
100
011
011
3 3
110
111
110
1 5
01111
4 5
11111
01010
01000
01000
3 2
11
00
11
OutputCopy
YES
NO
YES
NO
YES
Note
In the second test case the table is not elegant, because the red and the purple
subrectangles are nice and intersect.


In the fourth test case the table is not elegant, because the red and the purple
subrectangles are nice and intersect.
*/

/*(t--){
 n,m;
 for(i,j while (i < n-1 & j < m-1)){
        if(grid[i][j], grid[i][j+1],
grid[i+1][j], grid[i+1][j+1] has 1)count++;
 If count of ones == 3 → print "NO" (not elegant)
 }
 if(no block)cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
  }
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++)
      cin >> g[i];

    bool ok = true;

    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m - 1; j++) {
        int ones = (g[i][j] - '0') + (g[i][j + 1] - '0') + (g[i + 1][j] - '0') +
                   (g[i + 1][j + 1] - '0');
        if (ones == 3)
          ok = false;
      }
    }

    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1647/345916879
