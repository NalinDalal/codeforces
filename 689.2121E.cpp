/*E. Sponsor of Your Problems
time limit per test2 seconds
memory limit per test256 megabytes
For two integers 𝑎
 and 𝑏
, we define 𝑓(𝑎,𝑏)
 as the number of positions in the decimal representation of the numbers 𝑎
 and 𝑏
 where their digits are the same. For example, 𝑓(12,21)=0
, 𝑓(31,37)=1
, 𝑓(19891,18981)=2
, 𝑓(54321,24361)=3
.

You are given two integers 𝑙
 and 𝑟
 of the same length in decimal representation. Consider all integers 𝑙≤𝑥≤𝑟
. Your task is to find the minimum value of 𝑓(𝑙,𝑥)+𝑓(𝑥,𝑟)
.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test
cases follows.

Each test case consists of a single line containing two integers 𝑙
 and 𝑟
 (1≤𝑙≤𝑟<109
).

It is guaranteed that the numbers 𝑙
 and 𝑟
 have the same length in decimal representation and do not have leading zeros.

Output
For each test case, output the minimum value of 𝑓(𝑙,𝑥)+𝑓(𝑥,𝑟)
 among all integer values 𝑙≤𝑥≤𝑟
.

Example
InputCopy
14
1 1
2 3
4 6
15 16
17 19
199 201
899 999
1990 2001
6309 6409
12345 12501
19987 20093
746814 747932
900990999 900991010
999999999 999999999
OutputCopy
2
1
0
3
2
2
1
3
3
4
3
5
12
18
Note
In the first test case, you can choose 𝑥=1
. Then 𝑓(1,1)+𝑓(1,1)=1+1=2
.

In the second test case, you can choose 𝑥=2
. Then 𝑓(2,2)+𝑓(2,3)=1+0=1
.

In the third test case, you can choose 𝑥=5
. Then 𝑓(4,5)+𝑓(5,6)=0+0=0
.

In the fourth test case, you can choose 𝑥=15
. Then 𝑓(15,15)+𝑓(15,16)=2+1=3
.

In the fifth test case, you can choose 𝑥=18
. Then 𝑓(17,18)+𝑓(18,19)=1+1=2
.

In the sixth test case, you can choose 𝑥=200
. Then 𝑓(199,200)+𝑓(200,201)=0+2=2
.

In the seventh test case, you can choose 𝑥=900
. Then 𝑓(899,900)+𝑓(900,999)=0+1=1
.

In the eighth test case, you can choose 𝑥=1992
. Then 𝑓(1990,1992)+𝑓(1992,2001)=3+0=3
.
*/

/*f(a,b) gives count of digits in a, b that are have same place an face value
 i.e. f(a,b)->
 int f(a,b){
 a.toString();b.toString();
 int count=0;
 for(int i=0;i<a.length();i++){
 if(a[i]==b[i])count++;
 return count;
 }
 }

 given l,r
 find min value of f(l,x)+f(x,r)
 where x is b/w l,r
*/
#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(0);
  long t;
  std::cin >> t;
  while (t--) {
    std::string l, r;
    std::cin >> l >> r;
    if (l == r) {
      std::cout << (2 * l.size()) << std::endl;
      continue;
    }

    long idx(0);
    while (idx < l.size() && l[idx] == r[idx]) {
      ++idx;
    }
    if (l[idx] + 1 < r[idx]) {
      std::cout << (2 * idx) << std::endl;
      continue;
    }
    long cnt(2 * idx + 1);
    for (long p = idx + 1; p < l.size(); p++) {
      if (l[p] == '9' && r[p] == '0') {
        ++cnt;
      } else
        break;
    }

    std::cout << cnt << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2121/338661212
