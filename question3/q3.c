#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 101
typedef struct Node{
    int val;
    struct Node* next;
}Node;
Node* table[SIZE] = {NULL};
int hash(int x){
    return x % SIZE;
}
void insert(int x){
    int i = hash(x);
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = x;
    n->next = table[i];
    table[i] = n;
}
int found(int x){
    int i = hash(x);
    Node* curr = table[i];
    while (curr){
        if(curr->val == x){
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}
void intersection(int out[], int a1[], int n1, int a2[], int n2){
    int count=0;
    for(int i = 0; i< n1; i++){
        insert(a1[i]);
    }
    for(int i = 0; i < n2; i++){
        if(found(a2[i])){
            out[count++] = a2[i];
        }
    }
    for(int i = 0; i < count ; i++){
        printf("%d ", out[i]);
    }
}
int main(){
    int n1, n2;
    scanf("%d", &n1);
    int a1[n1];
    for(int i = 0; i < n1 ; i++){
        scanf("%d", &a1[i]);
    }

    scanf("%d", &n2);
    int a2[n2];
    for(int i = 0; i < n2 ; i++){
        scanf("%d", &a2[i]);
    }
    int out[n1];
    intersection(out, a1, n1, a2, n2);
    return 0;
}
