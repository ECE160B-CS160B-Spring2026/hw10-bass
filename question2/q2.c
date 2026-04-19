#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tnode{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
}TNode;
typedef struct {
    char *word;
    int count;
}Word;
TNode *talloc(void);
TNode *addtree(TNode *p, Word w);
void printTree(TNode *p);
int main(){
    TNode *root = NULL;
    char word[100];
    Word arr[100] = {0};
    int n = 0;
    while(scanf("%s", word) == 1){
        int i;
        int found = 0;
        for(i = 0; i < n; i++){//find quanity
            if(strcmp(word, arr[i].word) == 0 ){
                arr[i].count++;
                found = 1;
                break;
            }
        }
        if(found == 0){// if found unique
            arr[n].word = strdup(word);
            arr[n].count = 1;
            n++;
        }
    }
    for(int i = 0; i < n; i++){
        root = addtree(root, arr[i]);
    }
printTree(root);
return 0;
}
TNode *talloc(void){
    return malloc(sizeof(TNode));
}
TNode *addtree(TNode *p, Word w){
    if(p == NULL){
        p = talloc();
        p->word = w.word;
        p->count = w.count;
        p->left = p->right = NULL;
    } 
    else if(w.count < p->count){
        p->left = addtree(p->left, w);
    }
    else{
        p->right = addtree(p->right, w);
    }
    return p;
}
void printTree(TNode *p){
    if (p != NULL){
        printTree(p->right);
        printf("%d %s\n", p->count, p->word);
        printTree(p->left);
    }
}
