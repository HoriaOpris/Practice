//implements sorting algorithm

void Sort(int *a, int size)
{
    int temp;

    for (unsigned i = 0; i < size - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
            i = -1;
        }
    }
}