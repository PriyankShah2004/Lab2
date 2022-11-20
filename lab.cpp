
#include <iostream>
using namespace std;
 
int main()
{ 
 
    int processes, resources, i, j, z;
    processes = 5;
    resources = 3; 

    int allocation[5][3] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
 
    int maximum[5][3] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}}; 
 
    int available[3] ={3,3,2};
 
    int ans[processes], index = 0;

    bool finish[processes] = {0};
    
    /* finish gives status of the process that is indexed.*/

    int need[5][3];
    for (i = 0; i < processes; i++) {
        for (j = 0; j < resources; j++){
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
    /* for loop that goes through each row and column to make a 2d array that is made of Max-allocation */

    int y = 0;
    for (z = 0; z < processes; z++) {
        for (i = 0; i < processes; i++) {
            if (finish[i] == 0) {
                int err = 0;
                for (j = 0; j < resources; j++) {
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
        for(i = 0; i < processes - 1; i++)
            cout << " P" << ans[i];
            cout << " P" << ans[processes - 1] <<endl;
  }
    return (0);
}

