/*D. Right Left Wrong
time limit per test2 seconds
memory limit per test256 megabytes
Vlad found a strip of 𝑛
 cells, numbered from left to right from 1
 to 𝑛
. In the 𝑖
-th cell, there is a positive integer 𝑎𝑖
 and a letter 𝑠𝑖
, where all 𝑠𝑖
 are either 'L' or 'R'.

Vlad invites you to try to score the maximum possible points by performing any (possibly zero) number of operations.

In one operation, you can choose two indices 𝑙
 and 𝑟
 (1≤𝑙<𝑟≤𝑛
) such that 𝑠𝑙
 = 'L' and 𝑠𝑟
 = 'R' and do the following:

add 𝑎𝑙+𝑎𝑙+1+⋯+𝑎𝑟−1+𝑎𝑟
 points to the current score;
replace 𝑠𝑖
 with '.' for all 𝑙≤𝑖≤𝑟
, meaning you can no longer choose these indices.
For example, consider the following strip:

3
5
1
4
3
2
L	R	L	L	L	R
You can first choose 𝑙=1
, 𝑟=2
 and add 3+5=8
 to your score.

3
5
1
4
3
2
.	.	L	L	L	R
Then choose 𝑙=3
, 𝑟=6
 and add 1+4+3+2=10
 to your score.

3
5
1
4
3
2
.	.	.	.	.	.
As a result, it is impossible to perform another operation, and the final score is 18
.

What is the maximum score that can be achieved?

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains one integer 𝑛
 (2≤𝑛≤2⋅105
) — the length of the strip.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤105
) — the numbers written on the strip.

The third line of each test case contains a string 𝑠
 of 𝑛
 characters 'L' and 'R'.

It is guaranteed that the sum of the values of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output one integer — the maximum possible number of points that can be scored.

Example
InputCopy
4
6
3 5 1 4 3 2
LRLLLR
2
2 8
LR
2
3 9
RL
5
1 2 3 4 5
LRLRR
OutputCopy
18
10
0
22



*/

#include <iostream>
#include <vector>
typedef long long ll;

int main(){

    std::ios_base::sync_with_stdio(false);
    long t; std::cin >> t;
    while(t--){
        long n; std::cin >> n;
        std::vector<ll> a(n + 2, 0); for(long p = 1; p <= n; p++){std::cin >> a[p]; a[p] += a[p - 1];}
        std::string s; std::cin >> s; s = 'R' + s + 'L';
        long left(0), right(n + 1); ll total(0);
        do{
            ++left;  while(s[left]  != 'L'){++left;}
            --right; while(s[right] != 'R'){--right;}
            if(left < right){total += a[right] - a[left - 1];}
            else{break;}
        }while(left < right);

        std::cout << total << std::endl;
    }

}
//sub: https://codeforces.com/problemset/submission/2000/330608927
