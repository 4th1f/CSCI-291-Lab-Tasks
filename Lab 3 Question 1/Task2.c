#include<stdio.h> 
#include <stdbool.h> 
#define SIZE 24
#define nRows 8
#define nCols 3
// PROTOTYPES
void print_array(int array[], int length);
void print_matrix(int mat[][nCols], int rows);
void set_array(int array[], int length);
void rem_align(int arr[],int length, int position);
void insert_align(int arr[],int length, int pos, int value);
void reshape(int arr[],int length,int arr2d[nRows][nCols]);
void print_trans_matrix(int arrd[nRows][nCols]);
bool found_duplicate(int arr[SIZE]);
void flip_array(int arr[SIZE]);
bool temp_bool=0;

int main()
{
int arr[SIZE];
int arr2d[nRows][nCols];
//Call to different functions
set_array(arr,SIZE);
print_array(arr,SIZE);
flip_array(arr);
print_array(arr,SIZE);
return 0;
}
void print_array(int array[], int length){
   for(int i=0;i<length; i++)
      printf("%d ",array[i]); //Prints only elements without positions for simplicity
   puts("");
}

void print_matrix(int mat[][nCols], int rows){
   for(int i=0;i<rows; i++){
    for(int j=0;j<nCols; j++)
         printf("%d ", mat[i][j]); //Prints only elements without positions for simplicity
    printf("\n");
   }
   puts("");
}

//FUNCTION DEFINITIONS

void set_array(int array[], int length){//Function to set array elements to their index values
   for(int i=0;i<length; i++) // Setting elements to their index values
      array[i]=i; 
}

void rem_align(int arr[],int length, int position){// Function to remove element at given position and shift elements to left
    if (position<0 || position>=length){
        printf("Error : Invalid index Value\n"); // Error Handling
        return;
    }
    for(int i=position; i<length-1; i++) // Shift elements to left
      arr[i]=arr[i+1];
}

void insert_align(int arr[],int length, int pos, int value){// Function to insert value at given position and shift elements to right
    if (pos<0 || pos>=length){ // Error Handling
        printf("Error : Invalid index Value\n");
        return;
    }
    int temp[SIZE]; // Temporary array to hold original values
    for(int i=0; i<length; i++)
      temp[i]=arr[i];
    arr[pos]=value; // Insert new value at given position
    for(int i=pos+1; i<length; i++) // Shift elements to right
      arr[i]=temp[i-1];
}

void reshape(int arr[],int length,int arr2d[nRows][nCols]){ //Function to reshape 1D array to 2D array
    if (length != nRows * nCols){ // Error Handling
        printf("Error : Not Enough elements to pass through 2D Array\n");
        return;
    }
    int i=0; //loop unnecesssary due to pre defined limitations of nRows and nCols and size of arr(i=24, nRows*nCols=8*3=24)
    for(int j=0; j<nRows; j++){ // Filling 2D array row-wise
        for(int k=0; k<nCols; k++){
            arr2d[j][k]=arr[i];
            i++;
        }
    }
}

void print_trans_matrix(int arrd[nRows][nCols]){ //Function to print transpose of 2D array
    for(int i=0;i<nCols; i++){ //Iterate through columns
        for(int j=0;j<nRows; j++) //Iterate through rows
             printf("%d ", arrd[j][i]); //Prints column-wise elements
        printf("\n"); // New line after each column
       }
       puts("");
}

bool found_duplicate(int arr[SIZE]){ //Function to check for duplicates in array
    for(int i=0; i<SIZE; i++){ // Check for each element 
        for(int j=i+1; j<SIZE; j++){ // Check with every other element
            if(arr[i]==arr[j]){
                return true;
            }
        }
    }
    return false;  // No duplicates found
}

void flip_array(int arr[SIZE]){ //Function to flip array elements
    int temp[SIZE]; // Temporary array to hold original values
    int length=SIZE-1; //changfed length to SIZE-1 to avoid out of bound error
    for(int i=0; i<SIZE;i++){ // Copy original array to temporary array
        temp[i]=arr[i];
    }
    for (int i=0;i<=length;i++){ // Flip elements
        arr[i]=temp[length-i];
    }
}


