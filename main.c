/*
    Name : Adam Sheeres-Paulicpulle
    ID: 1036569
    email: asheeres@uoguelph.ca
    CIS 3490
*/

#include "helper.h"

Node *parser(char *filename) {
    FILE *fp;
    char buffer[1024];
    struct Node *head = malloc(sizeof(Node));
    struct Node *iter = head;

    fp = fopen(filename, "r");

    if (!fp) { //if you can't open file
        printf("ERROR OPENING FILE\n");
        return NULL;
    }

    //read in the stuff
    while( fscanf(fp, "%s", buffer) == 1) {
        //get the data
        if (buffer[strlen(buffer)-1] == '.' || buffer[strlen(buffer)-1] == ',' ) {
            removeFromIndex(buffer, strlen(buffer)-1);
        }
        iter->data = malloc(strlen(buffer) + 1);
        strcpy(iter->data, buffer);
        iter->next = malloc(sizeof(Node));
        iter = iter->next;
        iter->next = NULL;
        strcpy(buffer, "\0");
    }

    fclose(fp);

    return head;
}

void fixList(Node *head) {
    Node *iter = head;
    while(iter) {
        if (iter->next->data == NULL) {
            free(iter->next);
            iter->next = NULL;
            return;
        }
        iter = iter->next;
    }
}

void printList(Node *head) {
    Node *iter = head;
    while(iter) {
        printf("%s\n", iter->data);
        iter = iter->next;
    }
}

void freeList(Node *head) {
    Node *iter = head;
    while(iter) {
        free(iter->data);
        Node *next = iter->next;
        free(iter);
        iter = next;
    }
}

int main() {
    struct Node *headAnagram = parser("data_4.txt");
    struct Node *headString = parser("data_5.txt");
    char choice[10];
    char anagram[256];
    fixList(headAnagram);
    fixList(headString);

    while(1) {
        printf("Enter program name (P11, P12, P21, P22, P23, exit) : ");
        scanf("%s", choice);
        if ((strcmp(choice, "exit") == 0)) {
            break;
        }
        if (strcmp(choice, "P11") == 0) { //P11
            anagramBrute(headAnagram);

        } else if (strcmp(choice, "P12") == 0) { //P12
            anagramSorted(headAnagram);
            freeList(headAnagram);
            headAnagram = parser("data_4.txt");
        } else if (strcmp(choice, "P21") == 0) { //P21
            stringBrute(headString);

        } else if (strcmp(choice, "P22") == 0) { //P22
            
        } else if (strcmp(choice, "P23") == 0) { //P23
            
        } else {
            break;
        }
    }

    freeList(headAnagram);
    freeList(headString);
    return 0;
}