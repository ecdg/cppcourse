/*
 * Write the definition of a function named isSorted that receives three arguments:
an array of int,
an int that indicates the number of elements of interest in the array, and
a bool.

If the bool argument is TRUE then the function returns TRUE if and only if the array is sorted in ascending order.

If the bool argument is FALSE then the function returns TRUE if and only if the array is sorted in descending order.

In all other cases the function returns FALSE.

You may assume that the array has at least two elements.

 */

bool isSorted(const int arrayOfInt[], int numberOfElements, bool sorted)
{
    bool flag = true;

    if(sorted == true)
    {
        for(int i = 0; i < (numberOfElements - 1); i++)
        {
            if(arrayOfInt[i] > arrayOfInt[i + 1])
                flag = false;
        }

    }
    else
    {
        for (int i= (numberOfElements - 1); i > 0; i--)
        {
            if (arrayOfInt[i] > arrayOfInt[i - 1])
                flag = false;
        }

    }

    return flag;
}

// OR

bool isSorted(int a[], int n, bool asc) {
    int x;
    for (int i=1; i<n; i++)
        if (asc && a[i-1]>a[i]) return false;
        else if (!asc && a[i-1]<a[i]) return false;
    return true;
}