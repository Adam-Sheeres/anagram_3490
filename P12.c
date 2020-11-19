#include "helper.h"

void sortString(char *toSort) {
    if (toSort) {
        for (int i = 0 ; i < strlen(toSort) - 1; i++) {
            for (int j = i ; j < strlen(toSort) ; j++) {
                if (toSort[i] > toSort[j]) {
                    char c = toSort[i];
                    toSort[i] = toSort[j];
                    toSort[j] = c;
                }
            }
        }
    }
}

void sortList(Node *head) {
    Node *iter = head;

    while(iter) {
        Node *iter2 = iter->next;
        while(iter2) {
            if ((iter->data) && (iter2->data)) {
                if (atoi(iter->data) > atoi(iter2->data)) {
                    char *temp = iter->data;
                    iter->data = iter2->data;
                    iter2->data = temp;
                }
            }
            iter2 = iter2->next;
        }
        iter = iter->next;
    }

}

void anagramSorted(Node *head) {
    Node *iter = head;
    int anagramCount = 0;
    struct timeval start,end;
    char toFind[256];

    printf("Enter anagram to find: ");
    scanf("%s", toFind);

    //sort everything
    sortList(head);
    sortString(toFind);
    while(iter) {
        sortString(iter->data);
        iter = iter->next;
    }

    gettimeofday(&start, NULL);

    iter = head;
    while(iter) {
        if (anagram(toFind, iter->data)) {
            anagramCount++;
            if (anagram(toFind, iter->next->data) == false) { //if the current one is anagram, but next one is not an anagram
                break;
            }
        } 
        iter = iter->next;
    }
    gettimeofday(&end, NULL);
    printf("Presort found %d and took %ld ms (after sorting)\n\n", anagramCount, (end.tv_usec - start.tv_usec));
}