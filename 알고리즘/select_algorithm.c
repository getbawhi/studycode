int partiton(int* nums, int left, int right)
{
    int pivot = nums[right];
    int i = (left - 1);

    for (int j = left; j < right; j++)
    {
        if (nums[j] <= pivot)
        {
            i++;
            swap(&nums[i], &nums[j]);

        }
    }
    swap(&nums[i + 1], &nums[right]);
    return(i + 1);

}


int select(int* nums, int p, int r, int i)
{
    
    int q = partiton(nums, p, r);
    int k = q - p + 1;
    if (i < k)
    {
        select(nums, p, q - 1, i);

    }
    else if (i == k)
    {
        return nums[q];

    }
    else select(nums, q + 1, r, i - k);

}



int select_algorithm(int* nums, int N, int k)
{
    
    int p = 0;
    int r = N-1;
    int i = k;
    int result = 0;
    if (p == N) return nums[p];
    result = select(nums, p, r, i);
    return(result);

}
