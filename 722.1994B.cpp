/*B. Fun Game
time limit per test1 second
memory limit per test256 megabytes
Vova really loves the XOR operation (denoted as ⊕
). Recently, when he was going to sleep, he came up with a fun game.

At the beginning of the game, Vova chooses two binary sequences 𝑠
 and 𝑡
 of length 𝑛
 and gives them to Vanya. A binary sequence is a sequence consisting only of the numbers 0
 and 1
. Vanya can choose integers 𝑙,𝑟
 such that 1≤𝑙≤𝑟≤𝑛
, and for all 𝑙≤𝑖≤𝑟
 simultaneously replace 𝑠𝑖
 with 𝑠𝑖⊕𝑠𝑖−𝑙+1
, where 𝑠𝑖
 is the 𝑖
-th element of the sequence 𝑠
.

In order for the game to be interesting, there must be a possibility to win. Vanya wins if, with an unlimited number of actions, he can obtain the sequence 𝑡
 from the sequence 𝑠
. Determine if the game will be interesting for the sequences 𝑠
 and 𝑡
.

Input
Each test consists of multiple test cases. The first line contains an integer 𝑞
 (1≤𝑞≤104
) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of the sequences 𝑠
 and 𝑡
.

The second line of each test case contains a binary sequence 𝑠
 of length 𝑛
.

The third line of each test case contains a binary sequence 𝑡
 of length 𝑛
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output "Yes" if the game will be interesting, otherwise output "No".

You can output each letter in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as a positive answer).

Example
InputCopy
6
1
0
1
7
0110100
0110100
9
100101010
101111110
4
0011
1011
4
0100
0001
8
10110111
01100000
OutputCopy
NO
YES
YES
NO
YES
YES
Note
In the first test case, Vanya will not be able to change the sequence 𝑠
 with the only possible action of choosing 𝑙=𝑟=1
.

In the second test case, the sequences 𝑠
 and 𝑡
 are already equal.

In the third test case, Vanya can act as follows:

Choose 𝑙=3
 and 𝑟=5
, then 𝑠
 will become 𝟷𝟶𝟷𝟷𝟶𝟷𝟶𝟷𝟶
.
Choose 𝑙=5
 and 𝑟=6
, then 𝑠
 will become 𝟷𝟶𝟷𝟷𝟷𝟷𝟶𝟷𝟶
.
Choose 𝑙=7
 and 𝑟=7
, then 𝑠
 will become 𝟷𝟶𝟷𝟷𝟷𝟷𝟷𝟷𝟶
.
*/

#include <iostream>

int main(){

    long q; std::cin >> q;
    while(q--){
        long n; std::cin >> n;
        std::string s, t; std::cin >> s >> t;
        bool possible(true);
        for(long p = 0; possible && p < s.size(); p++){
            if(s[p] == '1'){break;}
            else if(t[p] == '1'){possible = false;}
        }

        std::cout << (possible ? "YES" : "NO") << std::endl;
    }
return 0;
}
//sub: https://codeforces.com/problemset/submission/1994/340687483
