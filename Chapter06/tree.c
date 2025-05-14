#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct tnode
{
    char* word;
    int count;
    struct tnode* left;
    struct tnode* right;
};

#define MAXWORD
struct tnode* addtree(struct tnode*, char*);
void treeprint(struct tnode*);
int getword(char *, int);

int main()
{
    struct tnode* root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            root=addtree(root, word);
        }
    }
    treeprint(root);
    return 0;
}

struct tnode* talloc(void);
char* strdup(char *);

struct tnode* addree(struct tnode* node, char* w);
{
    int cond;

    if (node == NULL)
    {
        node = talloc();
        node->word = strdup(key);
        node->count = 1;
        node->left = node->right = NULL;
    }
    else if ((cond = strcmp(w, node->word)) = 0)
    {
        node->count++;
    }
    else if (cond < 0)
    {
        node->left = addtree(node->left, w);
    }
    else
    {
        node->right = addtree(node->right, w);
    }
    return node;
}

struct tnode* talloc(void)
{
    return (struct tnode*)malloc(sizeof(struct tnode))
}

char* strdup(char* s)
{
    char* p;

    p = (char*)malloc(strlen(s) + 1);
    if (p != NULL)
    {
        strcpy(p, s);
    }
    return p;
}

void treeprint(struct tnode* node)
{
    if (node != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}
