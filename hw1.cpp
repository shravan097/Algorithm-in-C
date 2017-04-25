
// NAME: SHRAVAN DHAKAL
#include <iostream>

int randomIndex(int k) { srand(time(NULL)); return rand() % k;}

int partition( int *data, int start, int end)
{
    //RANDOM PIVOT
    int index= randomIndex(end+1);
    int pivot= data[index];
    std::swap(data[index],data[end]);
    int i = start;

    for(int index=start; index<end; index++)
    {
        if(data[index]<=pivot)
        {
            std::swap(data[i], data[index]);
            i++;
        }
    }
    std::swap(data[i],data[end]);
    return i;
}


int quickselect(int *data, int size, int k)
{
    int pivot=0; //pivot
    int end=size-1;
    int start=0;
    
    //Base case if the array has only one element
    if (size==1) return data[0];
    
    pivot= partition(data,start,end);
    
    //If the kth element is the pivot then return the pivot
    if(k==pivot+1) return data[pivot];
    
    //If the kth element is less than the pivot
    //Then only search on left sub-array
    //Otherwise search only on right sub-array;
    if(k< (pivot+1)) return  quickselect(data, pivot,k); //Left
    else return quickselect((data+pivot+1), end-pivot,k-(pivot+1)); //Right
    
}
