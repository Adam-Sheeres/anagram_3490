/*
    Name : Adam Sheeres-Paulicpulle
    ID: 1036569
    email: asheeres@uoguelph.ca
    CIS 3490
*/

#include "helper.h"

void stringBrute(Node *head) {
    Node *iter = head;
    char toFind[256];
    struct timeval start,end;
    int count = 0;

    printf("Enter a string to find : ");
    scanf("%s", toFind);

    gettimeofday(&start, NULL);

    while(iter) {
        if (strstr(iter->data, toFind)) {
            count++;
        }
        iter = iter->next;
    }
    gettimeofday(&end, NULL);
    printf("Brute force found %d and took %ld ms\n", count, (end.tv_usec - start.tv_usec));
}

