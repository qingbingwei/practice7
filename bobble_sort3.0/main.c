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
    }//����ʲô���ͣ�һ��һ���ֽڽ���
}

int cmp_int(const void* e1,const void* e2)
{
    return (*(int*)e1 - *(int*)e2);//�ų�����
}

void bobble_sort(void* base,int sz,int width,int(*cmp)(const void* e1,const void* e2))
{
    int i = 0;//����
    for(i = 0;i < sz;i++)
    {
        int j = 0;
        for(j = 0;j < sz-1-i;j++)
        {
           if(cmp((char*)base + j * width,(char*)base + (j + 1) * width) > 0) //e1��e2Ϊ�������Ƚ�Ԫ�ص�ַ
            {
                //����
                Swap((char*)base + j * width,(char*)base + (j + 1) * width,width);//��Ҫ����Ԫ����ʼλ�úͿ��
            }//�����Ҵ�СдΪ(char*)base + j*width,������ڲ�ͬ�������ݵĲ��ң�����Ƶ������ǿ������ת��
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
