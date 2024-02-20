#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StrList.h"

typedef struct _node {
    char *str;
    struct _node *next;
} Node;

struct _StrList {
    Node* head;
    size_t size;
};

Node* Node_alloc(const char *str, Node* next) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    
    newNode->str = (char*)malloc(strlen(str) + 1);
    if (newNode->str == NULL) {
        free(newNode);
        return NULL;
    }
    strcpy(newNode->str, str);
    
    newNode->next = next;
    
    return newNode;
}

void Node_free(Node* node) {
    free(node->str);
    free(node);
}

StrList* StrList_alloc() {
    StrList* newList = (StrList*)malloc(sizeof(StrList));
    if (newList == NULL) {
        return NULL;
    }
    
    newList->head = NULL;
    newList->size = 0;
    
    return newList;
}

void StrList_free(StrList* list) {
    if (list == NULL) {
        return;
    }
    
    Node* p1 = list->head;
    Node* p2;
    while (p1) {
        p2 = p1;
        p1 = p1->next;
        Node_free(p2);
    }
    free(list);
}

size_t StrList_size(const StrList* list) {
    return list->size;
}

void StrList_insertLast(StrList* StrList, const char* data){
    Node* newNode = Node_alloc(data, NULL);
    if (newNode == NULL) {
        return;
    }
    
    if (StrList->head == NULL) {
        StrList->head = newNode;
    } else {
        Node* p = StrList->head;
        while (p->next) {
            p = p->next;
        }
        p->next = newNode;
    }
    StrList->size++;
}

void StrList_insertAt(StrList* StrList, const char* data,int index){
    if (index < 0 || index > StrList->size) {
        return;
    }
    
    if (index == 0) {
        Node* newNode = Node_alloc(data, StrList->head);
        if (newNode == NULL) {
            return;
        }
        StrList->head = newNode;
    } else {
        Node* p = StrList->head;
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        Node* newNode = Node_alloc(data, p->next);
        if (newNode == NULL) {
            return;
        }
        p->next = newNode;
    }
    StrList->size++;
}

char* StrList_firstData(const StrList* StrList){
    return StrList->head->str;
}

void StrList_print(const StrList* StrList){
    Node* p = StrList->head;
    int i = 0;
    while (p) {
        printf("%s", p->str);
        if (StrList->size - 1 != i)
        {
            printf(" ");
        }
            
        
        p = p->next;
        i++;
    }
    printf("\n");
}

void StrList_printAt(const StrList* Strlist,int index){
    if (index < 0 || index >= Strlist->size || Strlist == NULL) {
        return;
    }
    if(index == 0){
        printf("%s",Strlist->head->str);
    }
    else{
        Node* p = Strlist->head;
        for (int i = 1; i <= index; i++) {
            p = p->next;
        }
        printf("%s\n",p->str);
    }
}

int StrList_printLen(const StrList* Strlist){
    int count = 0;
    Node* p = Strlist->head;
    while (p) {
        int chars = strlen(p->str);
        count += chars;
        p = p->next;
    }
    return count;
}

int StrList_count(StrList* StrList, const char* data){
    int count = 0;
    Node* p = StrList->head;
    while (p) {
        if (strcmp(p->str, data) == 0) {
            count++;
        }
        p = p->next;
    }
    return count;
}

void StrList_remove(StrList* StrList, const char* data){
    Node* p = StrList->head;
    Node* prev = NULL;
    while (p) {
        if (strcmp(p->str, data) == 0) {
            if (prev == NULL) {
                StrList->head = p->next;
                Node_free(p);
                p = StrList->head;
            } else {
                prev->next = p->next;
                Node_free(p);
                p = prev->next;
            }
            StrList->size--;
        } else {
            prev = p;
            p = p->next;
        }
    }
}

void StrList_removeAt(StrList* StrList, int index){
    if (index < 0 || index >= StrList->size) {
        return;
    }
    
    if (index == 0) {
        Node* p = StrList->head;
        StrList->head = p->next;
        Node_free(p);
    } else {
        Node* p = StrList->head;
        for (int i = 1; i < index; i++) {
            p = p->next;
        }
        Node* temp = p->next;
        p->next = temp->next;
        Node_free(temp);
    }
    StrList->size--;
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    if (StrList1->size != StrList2->size) {
        return 0;
    }
    
    Node* p1 = StrList1->head;
    Node* p2 = StrList2->head;
    while (p1) {
        if (strcmp(p1->str, p2->str) != 0) {
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return 1;
}

StrList* StrList_clone(const StrList* strList){
    StrList* newList = StrList_alloc();
    if (newList == NULL) {
        return NULL;
    }
    
    Node* p = strList->head;
    while (p) {
        StrList_insertLast(newList, p->str);
        p = p->next;
    }
    return newList;
}

void StrList_reverse( StrList* StrList){
    Node* prev = NULL;
    Node* current = StrList->head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    StrList->head = prev;
}

void StrList_sort( StrList* StrList){
    Node* p = StrList->head;
    Node* q = NULL;
    while (p) {
        q = p->next;
        while (q) {
            if (strcmp(p->str, q->str) > 0) {
                char* temp = p->str;
                p->str = q->str;
                q->str = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}

int StrList_isSorted(StrList* StrList){
    Node* p = StrList->head;
    Node* q = p->next;
    while (q) {
        if (strcmp(p->str, q->str) > 0) {
            return 0;
        }
        p = q;
        q = q->next;
    }
    return 1;
}