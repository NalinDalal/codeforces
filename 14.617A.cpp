/* A. Elephant
time limit per test1 second
memory limit per test256 megabytes
An elephant decided to visit his friend. It turned out that the elephant's house
is located at point 0 and his friend's house is located at point x(x > 0) of the
coordinate line. In one step the elephant can move 1, 2, 3, 4 or 5 positions
forward. Determine, what is the minimum number of steps he need to make in order
to get to his friend's house.

Input
The first line of the input contains an integer x (1 ≤ x ≤ 1 000 000) — The
coordinate of the friend's house.

Output
Print the minimum number of steps that elephant needs to make to get from point
0 to point x.

Examples

Input:5
Output:1

Input: 12
Output: 3
Note
In the first sample the elephant needs to make one step of length 5 to reach the
point x.

In the second sample the elephant can get to point x if he moves by 3, 5 and 4.
There are other ways to get the optimal answer but the elephant cannot reach x
in less than three moves.
*/

// 1,2,3,4 or 5 steps
// minimum no of steps to get to friend's house

// solve via recursion

// like what if i do like min see 12 remove 5, we get 7, remove 5, we get 2,
// remove 2, total steps 3
//
// remove=5;
// remove=min(remove,steps);
// int cordinate=cordinate-remove
// increase steps

/* int solve(int cordinate) {
if (cordinate == 0) {
return 0;}
int steps = 1;
int remove = 5;
remove=min(remove,steps);
cordinate=cordinate-remove;
steps++;}
while (cordinate >remove) {
remove = remove - 5;
steps++;}
solve(cordinate)
return steps;}*/

#include <algorithm> // for std::min
#include <iostream>

int main() {
  int coordinate;
  std::cin >> coordinate;

  int steps = 0;
  int remove = 5;

  while (coordinate > 0) {
    int to_remove =
        std::min(remove, coordinate); // Remove the minimum between `remove` and
                                      // the remaining coordinate
    coordinate -= to_remove;
    steps++;

    // Optionally adjust `remove` if needed in further steps (here it's fixed at
    // 5).
  }

  std::cout << steps << std::endl;
  return 0;
}
