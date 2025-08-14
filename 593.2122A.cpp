/*A. Greedy Grid
time limit per test1 second
memory limit per test256 megabytes
A path in a grid is called greedy if it starts at the top-left cell and moves
only to the right or downward, always moving to its neighbor with the greater
value (or either if the values are equal).

The value of a path is the sum of the values of the cells it visits, including
the start and end.

Does there exist an 𝑛×𝑚
 grid of nonnegative integers such that no greedy path achieves the maximum
value among all down/right paths?

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤5000
). The description of the test cases follows.

The only line of each test case contains two integers 𝑛
, 𝑚
 (1≤𝑛,𝑚≤100
) — the number of rows and columns in the grid, respectively.

Output
For each test case, on a separate line output "YES" if the required grid exists,
and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
2
3 3
1 2
OutputCopy
YES
NO
Note
In the first test case, an example of a grid in which no greedy path achieves
the maximum value out of all down/right paths is: ⎡⎣⎢⎢325514123⎤⎦⎥⎥ Let 𝑎𝑖,𝑗
 denote the value of the cell in the 𝑖
-th row and 𝑗
-th column. The maximum value of a down/right path is
𝑎1,1+𝑎2,1+𝑎3,1+𝑎3,2+𝑎3,3=17 . This path isn't greedy because 𝑎1,2 is greater
than 𝑎2,1 ; thus, a greedy path must move right in the first step. The maximum
value of a greedy path is 𝑎1,1+𝑎1,2+𝑎2,2+𝑎3,2+𝑎3,3=16
.

In the second test case, it can be proven that no grid satisfies the conditions.
*/

#include <cstdio>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n, m;
    scanf("%ld %ld", &n, &m);
    puts((n == 1 || m == 1 || (n == 2 && m == 2)) ? "NO" : "YES");
  }
}
// sub: https://codeforces.com/problemset/submission/2122/333870122
/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int t;cin>>t
        ;while(t--){
        int n,m;cin>>n>>m;

    }
    return 0;
}*/
