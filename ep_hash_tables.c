#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

typedef struct LinkedList {
    ListNode* first;
    ListNode* last;
} LinkedList;

void hash_push(LinkedList*, const int);
unsigned x;

int main() {
    unsigned n;
    ListNode* j;
    int y, i, tmp;

    scanf("%u", &n);

    while (n--) {
        scanf("%u %d", &x, &y);

        LinkedList hash[x];
        for (i = 0; i < x; ++i)
            hash[i].first = NULL, hash[i].last = NULL;

        for (i = 0; i < y; ++i) {
            scanf("%d", &tmp);
            hash_push(hash, tmp);
        }

        for (i = 0; i < x; ++i) {
            printf("%d -> ", i);
            for (j = hash[i].first; j; j = j->next)
                printf("%d -> ", j->data);

            printf("\\");
            printf("\n");
        }

        if (n)
            printf("\n");
    }

    return 0;
}

void hash_push(LinkedList* __hash, const int key) {
    ListNode* aux;
    aux = (ListNode*)malloc(sizeof(ListNode));

    if (!aux)
        exit(1);

    int idx = key % x;
    if (__hash[idx].first)
        __hash[idx].last->next = aux;
    else
        __hash[idx].first = aux;

    __hash[idx].last = aux;
    aux->next = NULL;
    aux->data = key;
}
