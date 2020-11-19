/*
    Name : Adam Sheeres-Paulicpulle
    ID: 1036569
    email: asheeres@uoguelph.ca
    CIS 3490
*/

#include "helper.h"

void anagramBrute(Node *head) {
    int count = 0;
    Node *iter = head;
    struct timeval start,end;
    char toFind[256];

    printf("Enter anagram to find: ");
    scanf("%s", toFind);

    gettimeofday(&start, NULL);

    while(iter) {
        if (iter->data) {
            
            if (anagram(toFind, iter->data)) {
                count++;
            }
        }
        iter = iter->next;
    }
    gettimeofday(&end, NULL);

    printf("Brute force found %d and took %ld ms\n\n", count, (end.tv_usec - start.tv_usec));
    return;
}

bool anagram(char *a, char *b) {
    bool flag = false;
    int i, j;
    char *temp = malloc(strlen(b) + 1);
    strcpy(temp, b);

    if (strlen(a) != strlen(temp)) {
        return false;
    }

    //loop over i
    for (i = 0 ; i < strlen(a) ; i++) {
        //loop over j
        for (j = 0 ; j < strlen(temp) ; j++) { //this array needs to decrease when it finds a similar elemnet
            if (a[i] == temp[j]) {
                removeFromIndex(temp, j);
                flag = true;
                break;
            }
        }
        //if no flag, no anagram
        if (flag == false) {
            return false;
        } else {
            flag = false;
        }
    }
    return true;
}

void removeFromIndex(char *toRemove, int index) { //write this
    //removes an element in an array at that index
    int i;
    for (i = index ; i < strlen(toRemove) ; i++) {
        toRemove[i] = toRemove[i+1];
    }
}