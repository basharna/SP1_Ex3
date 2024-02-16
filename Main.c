#include "StrList.h"
#include <stdio.h>

int main(){
    char a;
    char data[100];
    StrList* list = StrList_alloc();
    while(1){
        scanf("%c",&a);
    switch (a)
    {
    case 'A':{
        int count;
        scanf("%d",&count);
        for (size_t i = 0; i < count; i++)
        {
            scanf("%s",data);
            StrList_insertLast(list,data);
        }
        break;
    }

    case 'B':{
        int index;
        scanf("%d",&index);
        scanf("%s",data);
        StrList_insertAt(list,data,index);
        break;
    }

    case 'C':
        StrList_print(list);
        break;

    case 'D':{
        int size = StrList_size(list);
        printf("%d\n",size);
        break;
    }
    
    case 'E':{
        int index;
        scanf("%d",&index);
        StrList_printAt(list,index);
        break;
    }

    case 'F':{
        int size = StrList_printLen(list);
        printf("%d\n",size);
        break;
    }
    case 'G':{
        scanf("%s",data);
        int count = StrList_count(list,data);
        printf("%d\n",count);
        break;
    }

    case 'H':{
        scanf("%s",data);
        StrList_remove(list,data);
        break;
    }

    case 'I':{
        int index;
        scanf("%d",&index);
        StrList_removeAt(list,index);
        break;
    }

    case 'J':
        StrList_reverse(list);
        break;
    
    case 'K':
        StrList_free(list);
        break;

    case 'L':
        StrList_sort(list);
        break;

    case 'M':{
        int sorted = StrList_isSorted(list);
        printf("%d\n",sorted);
        break;
    }

    case 'N':
        return 0;
        
    default:
        break;
    }
    }
    
}