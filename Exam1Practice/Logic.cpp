#include <iostream>
#include <array>

int[] intersection(int[] a, int[] b)
{
    int[] *tmp = nullptr;
    for (int i = 0; i < a.length; i++)
    {
        for (int j = 0; j < b.length; b++)
        {
            if (a[i] == b[j])
            {
                tmp = new int[tmp.length + 1];
                tmp[tmp.length - 1] = a[i];
            }
        }
    }
}

int[] union()
{
}

int main()
{
    return 0;
}