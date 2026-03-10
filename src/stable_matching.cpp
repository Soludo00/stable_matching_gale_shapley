#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 3;

    // men's preferences
    int men[3][3] = {
        {0,1,2},
        {1,0,2},
        {1,2,0}
    };

    // women's preferences
    int women[3][3] = {
        {1,0,2},
        {2,1,0},
        {0,1,2}
    };

    vector<int> partner(n, -1);
    vector<bool> manFree(n, true);
    vector<int> nextProposal(n, 0);

    int freeCount = n;

    while(freeCount > 0)
    {
        int m;

        for(m = 0; m < n; m++)
        {
            if(manFree[m])
                break;
        }

        int w = men[m][nextProposal[m]];
        nextProposal[m]++;

        if(partner[w] == -1)
        {
            partner[w] = m;
            manFree[m] = false;
            freeCount--;
        }
        else
        {
            int current = partner[w];

            bool prefersNew = false;

            for(int i = 0; i < n; i++)
            {
                if(women[w][i] == m)
                {
                    prefersNew = true;
                    break;
                }

                if(women[w][i] == current)
                    break;
            }

            if(prefersNew)
            {
                partner[w] = m;
                manFree[m] = false;
                manFree[current] = true;
            }
        }
    }

    cout << "Final matches:" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << "Woman " << i << " is matched with Man " << partner[i] << endl;
    }

    return 0;
}
