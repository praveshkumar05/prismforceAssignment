# Abhimanyu in Chakravyuha

This repository contains the solution to the "Abhimanyu in Chakravyuha" problem.

## Problem Statement

Imagine Abhimanyu in Chakravyuha. There are 11 circles in the Chakravyuha surrounded by different enemies. Abhimanyu is located in the innermost circle and has to cross all the 11 circles to reach Pandavas army back.

### Given:
- Each circle is guarded by different enemies with powers k1, k2, ..., k11.
- Abhimanyu starts from the innermost circle with p power.
- Abhimanyu has a boon to skip fighting enemies `a` times.
- Abhimanyu can recharge himself with power `b` times.
- Battling in each circle will result in loss of the same power from Abhimanyu as the enemy.
- If Abhimanyu enters the circle with energy less than the respective enemy, he will lose the battle.
- k3 and k7 enemies can regenerate once with half of their initial power and can attack Abhimanyu from behind if he is battling in the next circle.

### Objective:
Write an algorithm to find if Abhimanyu can cross the Chakravyuha and test it with two sets of test cases.

## Solution

### Approach:
The algorithm iterates through each circle, checking Abhimanyu's power against the enemy's power. Abhimanyu can skip a certain number of enemies or recharge his power a certain number of times. The `k3` and `k7` enemies have special regeneration abilities that are considered in the algorithm.

### Implementation:

```cpp
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
