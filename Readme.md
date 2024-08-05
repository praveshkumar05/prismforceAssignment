# Abhimanyu and Chakravyuh

This repository contains a solution to the problem "Abhimanyu and Chakravyuh," where Abhimanyu must cross 11 circles guarded by enemies to reach the Pandavas' army. The problem involves determining whether Abhimanyu can successfully cross all circles based on his initial power, the ability to skip some enemies, and the ability to recharge his power a certain number of times.

## Problem Statement

Abhimanyu starts from the innermost circle with a certain amount of power and must cross all 11 circles. Each circle is guarded by an enemy with a specific power. Abhimanyu can skip fighting some enemies and recharge his power a certain number of times. If Abhimanyu enters a circle with less power than the enemy in that circle, he will lose the battle. Additionally, the enemies in the 3rd and 7th circles can regenerate with half of their initial power and attack Abhimanyu from behind if he is battling in the next circle.

## Input Format

- The first line contains the number of test cases.
- For each test case:
  - The first line contains four integers: maxPower, numOfSkip, numOfRecharge, and totalCircle.
  - The second line contains totalCircle integers representing the power of each enemy in the circles.

## Output Format

- For each test case, print "Abhimanyu Broke The Charkavyuh" if Abhimanyu successfully crosses all circles.
- Print "Abhimanyu Lost War at Xth circle" if Abhimanyu loses at the Xth circle.


## Example

### Input
```
2
10 2 5 11
1 2 5 4 8 7 4 5 6 4 3
10 1 3 11
1 12 12 6 8 7 4 5 6 4 3
```

### Output
```
Abhimanyu Broke The Charkavyuh
Abhimanyu Lost War at 3th circle
```
```

## Solution Explanation

The solution involves simulating the traversal of Abhimanyu through the circles. For each test case, we check if Abhimanyu has enough power to defeat the enemy in the current circle. If not, we either recharge his power or skip the circle if possible. If neither is possible, Abhimanyu loses at that circle.

### Key Points

#### Initialization:
- Read the input values for each test case.
- Initialize Abhimanyu's current power and read the power of enemies in each circle.

#### Processing Each Circle:
- For each circle, check if Abhimanyu's current power is sufficient to defeat the enemy.
- If the circle is the 3rd or 7th, add half of the previous enemy's power to the current enemy's power.
- If Abhimanyu's power is insufficient, try to recharge or skip the circle.
- If neither is possible, Abhimanyu loses.

#### Output:
- Print the result for each test case based on whether Abhimanyu successfully crosses all circles or loses at a specific circle.

### Implementation:


#include <bits/stdc++.h>
using namespace std;

// Macros
#define int long long
#define deb(x) cout << #x << " = " << x << endl
#define w(x) while (x--)
#define fo(i, n) for (int i = 0; i < n; i++)
#define pb push_back

// Function to solve each test case
void AbhimanyubreakingTheCharkaVyuh()
{
    int maxPower, numOfSkip, numOfRecharge, totalCircle; // variable declaration

    cin >> maxPower >> numOfSkip >> numOfRecharge >> totalCircle;

    vector<int> monster(totalCircle);

    for (int i = 0; i < totalCircle; i++)
    {
        cin >> monster[i];
    }

    int currAbhiPower = maxPower;
    for (int circle = 0; circle < totalCircle; circle++)
    {
        int currMonsterpower = monster[circle];

        if (circle == 3 || circle == 7)
            currMonsterpower += monster[circle - 1] / 2;

        if (currAbhiPower >= currMonsterpower)
            currAbhiPower -= currMonsterpower;
        else if (currAbhiPower < currMonsterpower)
        {
            if ((numOfRecharge > 0) && (maxPower >= currMonsterpower) && (currAbhiPower != maxPower))
            {
                numOfRecharge--;
                currAbhiPower = maxPower - currMonsterpower;
            }
            else if (numOfSkip > 0)
            {
                numOfSkip--;
            }
            else
            {
                cout << "Abhimanyu Lost War at " << circle + 1 << "th circle" << endl;
                return;
            }
        }
    }

    cout << "Abhimanyu Broke The Charkavyuh" << endl;
}

// Main function
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        AbhimanyubreakingTheCharkaVyuh();
    }

    return 0;
}
## Example Input and Output:
# Input:
2
10 2 5 11
1 2 5 4 8 7 4 5 6 4 3 
10 1 3 11
1 12 12 6 8 7 4 5 6 4 3 

#Output
Abhimanyu Broke The Charkavyuh
Abhimanyu Lost War at 3th circle

