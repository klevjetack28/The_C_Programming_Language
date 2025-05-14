#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct nlist 
{
    struct nlist* next;
    char* name;
    char* defn;
};

#define HASHSIZE 101

static struct nlist* hashtab[HASHSIZE];

struct nlist* lookup(char*);
char* my_strdup(char *);
unsigned hash(char*);

struct nlist* install(char* name, char* defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL)
    {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
        {
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else
    {
        free((void *) np->defn);
    }
    
    if ((np->defn = strdup(defn)) == NULL)
    {
        return NULL;
    }
    return np;
}

struct nlist* lookup(char* s)
{
    struct nlist* np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    {
        if (strcmp(np->name, s) == 0)
        {
            return np;
        }
    }
    return NULL;
}

unsigned hash(char* s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
    {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
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

int main()
{
    install("lukas", "tackett");
    printf("%s\n", lookup("lukas")->defn);
    return 0;
}
