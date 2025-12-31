#include <inttypes.h>
#include <stdio.h>

int main(){
    int array[10][2] = {{1,2},{2,1},{3,4},{4,3}};
    
    for(int i = sizeof(array)/(sizeof(array[0])) - 1; i > 0; i--){
        array[i][0] = array[i-1][0];
        array[i][1] = array[i-1][1];
    } 
        
    array[0][0] = -1;
    array[0][1] = -1;
    
    for(int i = 0; i < 10; i++){
        printf("{%d %d} ", array[i][0], array[i][1]);
    }
    
        
        
}