/*
    Name : Adam Sheeres-Paulicpulle
    ID: 1036569
    email: asheeres@uoguelph.ca
    CIS 3490
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/time.h>

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

//P11
    void anagramBrute(Node *); //preforms the brute force anagram algorithm
    bool anagram(char *, char *); //checks if there is an anagram.
    void removeFromIndex(char *, int ); //removes an element in the array 
    void refine(char *); //takes out unnecessary characters

//P12
    void anagramSorted(Node *); //preforms the presort and finds anagrams
    void sortString(char *); //sorts the string using bubble sort
    void sortList(Node *); //sorts the linked list

//P21
    void stringBrute(Node *); //preforms brute force search to find a string

//P22
    bool stringInString(char *, char *);