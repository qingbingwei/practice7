#include <iostream>
//������������ʮ��������
void bobble_sort(int arr[],int sz)
{
    int i = 0;  //����
    for (i = 0;i < sz - 1;i++)
    {
        int flag = 1;
        int j = 0;  //��������
        for(j = 0;j < sz-i-1;j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int tmp = 0;
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 0;
            }
        }
        if(flag == 1)
        {
            break;
        }
    }
}

int main()
{
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    int sz = sizeof(arr)/sizeof(arr[0]);
    bobble_sort(arr,sz);

    int i = 0;
    for (i = 0;i < sz;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}