#include "StrList.h"
#include <stdio.h>

int main(){
    int a;
    char data[100];
    StrList* list = StrList_alloc();
    while(1){
        scanf("%d",&a);
    switch (a)
    {
    case 1:{
        int count;
        scanf("%d",&count);
        for (size_t i = 0; i < count; i++)
        {
            scanf("%s",data);
            StrList_insertLast(list,data);
        }
        break;
    }

    case 2:{
        int index;
        scanf("%d",&index);
        scanf("%s",data);
        StrList_insertAt(list,data,index);
        break;
    }

    case 3:
        StrList_print(list);
        break;

    case 4:{
        int size = StrList_size(list);
        printf("%d\n",size);
        break;
    }
    
    case 5:{
        int index;
        scanf("%d",&index);
        StrList_printAt(list,index);
        break;
    }

    case 6:{
        int size = StrList_printLen(list);
        printf("%d\n",size);
        break;
    }
    case 7:{
        scanf("%s",data);
        int count = StrList_count(list,data);
        printf("%d\n",count);
        break;
    }

    case 8:{
        scanf("%s",data);
        StrList_remove(list,data);
        break;
    }

    case 9:{
        int index;
        scanf("%d",&index);
        StrList_removeAt(list,index);
        break;
    }

    case 10:
        StrList_reverse(list);
        break;
    
    case 11:
        StrList_free(list);
        break;

    case 12:
        StrList_sort(list);
        break;

    case 13:{
        int sorted = StrList_isSorted(list);
        if (sorted == 1)
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }
        break;
    }

    case 0:
        return 0;
        
    default:
        break;
    }
    }
    
}