int swap(int* a, int* b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;


}


int* selectionsort(int* nums, int N)
{
   
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (nums[i] >= nums[j])
            {
                swap(&nums[i], &nums[j]);
            }
        }
        
    }



    return(nums);


}

int* bubblesort(int* nums, int N)
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (nums[j] >= nums[j + 1])
            {
                swap(&nums[j], &nums[j + 1]);
            }
        }
    }

   




    return(nums);
}

int* insertionsort(int* nums, int N)
{
    int j=0;
    int key = 0;

    for (int i = 1; i < N; i++)
    {
        key = nums[i];
        
        for (j = i - 1; j >= 0 && nums[j] > key; j--)
        {
            nums[j + 1] = nums[j];
        }

        nums[j + 1] = key;
    }

}

int tmp[100001] = { 0 };

void merge(int* nums, int left, int mid, int right)
{
    
    int i = left;
    int j = mid+ 1;
    int z = left;
    
    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j])
            tmp[z++] = nums[i++];
        else
            tmp[z++] = nums[j++];
    }

    if (i > mid)
    {
        for (int l = j; l <= right; l++)
            tmp[z++] = nums[l];
    }

    else
    {
        for (int l = i; l <= mid; l++)
            tmp[z++] = nums[l];

    }


    for (int l = left; l <= right; l++)
    {
        nums[l] = tmp[l];

    }

    

}

void mergesort_personal(int* nums, int left, int right)
{
    if (left < right) {

        int mid = (left + right) / 2;
        mergesort_personal(nums, left, mid);
        mergesort_personal(nums, mid+1, right);
        merge(nums, left, mid, right);


    }


}

int* mergesort(int* nums, int N)
{
    
    int left = 0;
    int right = N-1;

    mergesort_personal(nums, left, right);
    return (nums);

}




void quick_me(int* nums, int l, int r) {

    if (l < r)
    {

        int p = partiton(nums, l, r);

        quick_me(nums, l, p - 1);
        quick_me(nums, p + 1, r);
    }



}

int partiton(int* nums, int l, int r) {

    int pivot = nums[r];
    int i = (l - 1);

    for (int j = l; j <= r - 1; j++)
    {
        if (nums[j] <= pivot)
        {
            i++;
            swap(&nums[i], &nums[j]);


        }

    }
    swap(&nums[i + 1], &nums[r]);
    return (i + 1);


}

int* quicksort(int* nums, int N)
{
    quick_me(nums, 0, N-1);

    return(nums);
}


int* countingsort(int* nums, int N)
{

    int test[100001] = { 0 };

    
    int* final = NULL;
    final = (int*)malloc(sizeof(int) * N);

    if (final == NULL) {
        fprintf(stderr, "메모리가 부족하여 할당할 수 없습니다\n");
        exit(1);

    }

    for (int i = 0; i <= N-1; i++)
    {
        final[i] = 444;
    }
    

   

    for (int j = 0; j < N; j++)
    {
        test[nums[j]]++;
    }

    for (int i = 2; i < 100001; i++)
    {
        test[i] = test[i] + test[i - 1];
    }
    
    for (int j = N-1; j > -1; j--)
    {   
        final[test[nums[j]]-1] = nums[j];
        test[nums[j]]--;
    }
    
    

    return(final);

    free(final);
   
   
}

int* radixsort_personal(int* nums, int N)
{
    int result[100001] = { 0 };
    int max = 0;
    int exp = 1;
   

    for (int i = 0; i < N; i++)
    {
        if (nums[i] > max) max = nums[i];
    }

    while (max / exp > 0)
    {
        int tmp[10] = { 0 };
        for (int i = 0; i < N; i++)
            tmp[nums[i] / exp % 10]++;
        for (int i = 1; i < 10; i++)
            tmp[i] += tmp[i - 1];

        for (int i = N-1; i >= 0; i--)
        {
            result[--tmp[nums[i] / exp % 10]] = nums[i];

        }

        for (int i = 0; i < N; i++)
        {
            nums[i] = result[i];
            
        }

        exp *= 10;
    }




}


int* radixsort(int* nums, int N)
{

    radixsort_personal(nums, N);
    return (nums);
}



void heapify(int* nums, int i, int N)
{
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int parent = i;

    if (left < N && nums[parent] < nums[left])
        parent = left;

    if (right < N && nums[parent] < nums[right])
        parent = right;

    
    if (i != parent)
    {
        swap(&nums[parent], &nums[i]);
        heapify(nums, parent, N);
    }
       



}






int* heapsort(int* nums, int N)
{
    for (int i = (N / 2) - 1; i >= 0; i--)
    {
        heapify(nums, i, N);
    }
 
    for(int i = N-1; i>0 ; i--)
    {
        
        swap(&nums[0], &nums[i]);
        heapify(nums, 0, i);
        
    }

    return(nums);
   
}
