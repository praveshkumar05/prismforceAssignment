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

    int maxPower, numOfSkip, numOfRecharge, totalCircle; // variable declartion

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
                // return canAbhiBreakTheChakrawyuh(maxPower, maxPower - currMonsterpower, numOfSkip, numOfRecharge - 1, monster, circle + 1);
                numOfRecharge--;
                currAbhiPower = maxPower - currMonsterpower;
            }
            else if (numOfSkip > 0)
            {
                // return canAbhiBreakTheChakrawyuh(maxPower, maxPower - currMonsterpower, numOfSkip, numOfRecharge - 1, monster, circle + 1);

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


/*
    INPUT 
2
10 2 5 11
1 2 5 4 8 7 4 5 6 4 3 
10 1 3 11
1 12 12 6 8 7 4 5 6 4 3 


output
Abhimanyu Broke The Charkavyuh
Abhimanyu Lost War at 3th circle

*/