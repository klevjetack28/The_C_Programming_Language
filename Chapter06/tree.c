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

int getword(char* word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char* w = word;

    while (isspace(c = getch()));

    if (c != EOF)
    {
        *w++ = c;
    }
    if (!isalpha(c) && c != '"' && c != '/' && c != '#')
    {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
    {
        if (!isalnum(*w = getch()) && *w != '_' && *w != '"' && *w != '/' && *w != '*')
        {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else 
    {
        buf[bufp++] = c;
    }
}

struct tnode* talloc(void);
char* my_strdup(char *);

struct tnode* addtree(struct tnode* node, char* w);
{
    int cond;

    if (node == NULL)
    {
        node = talloc();
        node->word = my_strdup(key);
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
    return (struct tnode*)malloc(sizeof(struct tnode));
}

char* my_strdup(char* s)
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
        treeprint(node->left);
        printf("%4d %s\n", node->count, node->word);
        treeprint(node->right);
    }
}
