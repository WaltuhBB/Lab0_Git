//Постановка задачи: Программа считает количество первых вхождений каждого элемента
//путем замены последующих вхождений на несуществующий элемент(больше максимального)
//Программа отмечает первое вхождение элемента переменной типа bool

#include <stdio.h>
#include <stdbool.h>

//#define szz 3
//#define szz 11
#define szz 10

int main()
{
    //int array[szz] = {1, 1, 1};
    //countEl = 1

    //int array[szz] = {1, 2, 3};
    //countEl = 3

    //int array[szz] = {5,5,5,7,3,3,2,2,1,1,10};
    //countEl = 6

    int array[szz] = {5,5,7,3,3,2,2,1,1,10};
    //countEl = 6

    int max = array[0];
    for(int i=1;i < szz;i++)
        if(array[i] > max) max = array[i];
    bool unique = true;
    int notExist = max+1;
    int countEl=0;
    for(int i=0;i < szz;i++)
    {
        int jx = i+1;
        if(array[i]!= notExist)
        {
            unique = true;
            while(jx < szz)
            {
                if(array[jx]!= notExist)
                {
                    if(array[i] == array[jx])
                    {
                        array[jx] = notExist;

                    }
                }
                jx++;
            }
        }
        else
            unique = false;
        if(unique)
            countEl++;
        else
            array[i] = notExist;
    }

    printf("countEl = %d", countEl);
}
