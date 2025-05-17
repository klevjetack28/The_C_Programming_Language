#include <stdlib.h>

#undef NULL

#define NULL        0
#define EOF         (-1)
#define BUFSIZE     1024
#define OPEN_MAX    20 /* max number of files to be opened */

typedef struct _iobuf
{
    int cnt;                        /* characters left */
    char *ptr;                      /* next character in position */
    char *base;                     /* location of buffer */
    struct
    {
        unsigned int _READ  : 1;     /* file open for reading */
        unsigned int _WRITE : 1;     /* file open for writing */
        unsigned int _UNBUF : 1;     /* file is unbuffered */
        unsigned int _EOF   : 1;     /* EOF has occurred on this file */
        unsigned int _ERR   : 1;     /* error occurred on this file */  
    } flags;                        /* mode of file access */
    int fd;                         /* file descriptor */
} FILE;
extern FILE _iob[OPEN_MAX];

#define stdin   (&_iob[0])
#define stdout  (&_iob[1])
#define stderr  (&_iob[2])

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p)     (*(p->flags)._EOF)
#define ferror(p)   (*(p->flags)._ERR) != 0)
#define fileno(p)   ((p)->fd)

#define getc(p)     (--(p)->cnt >= 0 \
                ?   (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x, p)  (--(p)->cnt >= 0 \
                ?  *(p)->ptr++ = (x) : _flushbuf((x), p))

#define getchar()   getc(stdin)
#define putchar(x)  putc((x), stdout)

#include <fcntl.h>
#include <unistd.h>
#define PERMS 0666 /* RW for owner, group, others */

FILE *fopen(char *name, char *mode)
{
    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
    {
        return NULL;
    }
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
    {
        if ((fp->flags._READ == 0) | (fp->flags._EOF == 0))
        {
            break;
        }
    }
    if (fp >= _iob + OPEN_MAX)
    {
        return NULL;
    }

    if (*mode == 'w')
    {
        fd = creat(name, PERMS);
    }
    else if (*mode == 'a')
    {
        if ((fd = open(name, O_WRONLY, 0)) == -1)
        {
            fd = creat(name, PERMS);
        }
        lseek(fd, 0L, 2);
    }
    else
    {
        fd = open(name, O_RDONLY, 0);
    }
    if (fd == -1)
    {
        return NULL;
    }
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flags._READ = (*mode == 'r') ? 1 : 0;
    fp->flags._WRITE = (*mode == 'w' || *mode == 'a') ? 1 : 0;
    return fp;
}

int _fillbuf(FILE *fp)
{
    int bufsize;

    if (fp->flags._READ != 1 || fp->flags._EOF == 1 || fp->flags._ERR == 1)
    {
        return EOF;
    }
    bufsize = (fp->flags._UNBUF == 1) ? 1 : BUFSIZE;
    if (fp->base == NULL)
    {
        if ((fp->base = malloc(bufsize)) == NULL)
        {
            return EOF;
        }
    }
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0)
    {
        if (fp->cnt == -1)
        {
            fp->flags._EOF = 1;
        }
        else
        {
            fp->flags._ERR = 1;
        }
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}
/*
int _flushbuf(int fd, FILE *fp)
{

    if ((fp->flags._WRITE != 0 || fp->flags._EOF == 1 || fp->flags._EOF == 1)
    {
        return EOF;
    }
    int n;
    int bufsize = (fp->flags._UNBUF == 1) ? 1 : BUFSIZE;
    char buf[bufsize];
    if ((n = read(fd, buf, bufsize)) == 0)
    {
        return EOF;
    }
    write(fp->fd, buf, n);
    free(buf);
}
*/
FILE _iob[OPEN_MAX] = {
    { 0, (char *) 0, (char *) 0, { ._READ = 1 }, 0 },
    { 0, (char *) 0, (char *) 0, { ._WRITE = 1 }, 1 },
    { 0, (char *) 0, (char *) 0, { ._WRITE = 1 }, 2 }
};

/*
Exercise 8-2. Rewrite fopen and _fillbuf with fields instead of explicit bit operations.
    Compare code size and execution speed.

Exercise 8-3. Design and write _flushbuf, fflush, and fclose.
    int _flushbuf(int, FILE *);

Exercise 8-4. The standard library function
    int fseek(FILE *fp, long offset, int origin)

is identical to lseek except that fp is a file pointer instead of a file descriptor and return value
is an int status, not a position. Write fseek. Make sure that your fseek coordinates properly
with the buffering done for the other functions of the library
*/

int main()
{/*
    int c;
    FILE *cprog = fopen("copy.c", "r");
    while ((c = getc(cprog)) != EOF)
    {
        putchar(c);
    }*/
    //fclose(cprog);
    return 0;
}
