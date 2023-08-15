#include <stdio.h>


void Swap(char* buf1,char* buf2,int width)
{
    int i = 0;
    for(i = 0;i < width;i++)
    {
        char tmp = *buf1;
        *buf1 = *buf2;
        *buf2 = tmp;
        buf1++;
        buf2++;
    }//不管什么类型，一个一个字节交换
}

int cmp_int(const void* e1,const void* e2)
{
    return (*(int*)e1 - *(int*)e2);//排成升序
}

void bobble_sort(void* base,int sz,int width,int(*cmp)(const void* e1,const void* e2))
{
    int i = 0;//趟数
    for(i = 0;i < sz;i++)
    {
        int j = 0;
        for(j = 0;j < sz-1-i;j++)
        {
           if(cmp((char*)base + j * width,(char*)base + (j + 1) * width) > 0) //e1，e2为两个待比较元素地址
            {
                //交换
                Swap((char*)base + j * width,(char*)base + (j + 1) * width,width);//需要两个元素起始位置和宽度
            }//将查找大小写为(char*)base + j*width,方便对于不同类型数据的查找，不用频繁进行强制类型转换
        }
    }
}

void test1()
{
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    int sz = sizeof(arr)/sizeof(arr[0]);
    //bobble_sort(arr,sz);

    bobble_sort(arr,sz, sizeof(arr[0]),cmp_int);

    int i = 0;
    for (i = 0;i < sz;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{

    test1();
    return 0;
}
