#include <iostream>
#include "Input.h"
using namespace std;
 
int main()
{ 

    int ans[processes];
    bool finish[processes] = {0};
    int index = 0;
    int need[5][3];
    /* finish gives status of the process that is indexed.*/

    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++){
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
    /* Need[i,j] = k need processes[i] needs k instances of resources[j]*/
    /* for loop that goes through each row and column to make a 2d array that is made of Max-allocation */

    int y = 0;
    for (z = 0; z < processes; z++) {
        for (int i = 0; i < processes; i++) {
            if (finish[i] == 0) {
                int err = 0;
                for (int j = 0; j < resources; j++) {
                    if (need[i][j] > available[j]){
                        err = 1;
                        break;
                    }
                }
                
                if (err == 0) {
                    ans[index++] = i;
                    for (y = 0; y < resources; y++)
                        available[y] += allocation[i][y];
                        finish[i] = 1;
                }
            }
        }
    }

    /* work array is {3,3,2}*/
    /* make sure finish[i] = false and need[i] <= work */

    int err = 1;
    
    for(int i = 0;i<processes;i++){
        if(finish[i]==0){
            err = 0;
            cout << "Not safe";
            }
        }

    if(err==1){
        cout << "Safe Sequence is " << endl;
        for(int i = 0; i < processes - 1; i++)
            cout << " P" << ans[i];
            cout << " P" << ans[4];
  }
    return (0);
}

