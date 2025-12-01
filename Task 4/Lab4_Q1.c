#include <stdio.h>

void rearrange_iterative(int arr[], int size) {
    int temp[size];  // Temporary array to build result
    int oIndex = 0;
    int eIndex = size - 1;
    
    // Scan array once and place odds at front, evens at back
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            temp[oIndex++] = arr[i];
        } else {
            temp[eIndex--] = arr[i];
        }
    }
    for (int i=0;i<size;i++) {
        printf( "%d ", temp[i] );
    }
}

void rearrange_recursive(int arr[],int new_array[], int size, int oindex, int eindex, int gindex) {
    if (gindex<=-1){
        gindex ++;
        oindex = 0;
        eindex = size - 1;
        rearrange_recursive(arr,new_array,size,oindex,eindex,gindex);
    }
    else if(gindex>=size){
        for (int i=0;i<size;i++) {
            printf( "%d ", new_array[i]);
        }
    }
    else if (gindex<size){
        if (arr[gindex] % 2 == 0) {
            new_array[eindex] = arr[gindex];
            eindex--;
            gindex++;
            rearrange_recursive(arr,new_array,size,oindex,eindex,gindex);
        }
        else {
            new_array[oindex] = arr[gindex];
            oindex++;
            gindex++;
            rearrange_recursive(arr,new_array,size,oindex,eindex,gindex);
        }
    }
}

int main(){
    int arr[] = {12, 3, 5, 8, 7, 10, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int new_array[size];
    int gindex = -1;
    int oindex,eindex;
    rearrange_recursive(arr, new_array, size, oindex, eindex, gindex);
    return 0;
}