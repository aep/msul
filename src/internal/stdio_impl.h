#ifndef _STDIO_IMPL_H
#define _STDIO_IMPL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <inttypes.h>
#include <wchar.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <ctype.h>
#include <sys/wait.h>
#include <math.h>
#include <float.h>
#include <sys/uio.h>
#include "syscall.h"
#include "libc.h"

#define UNGET 8

#define FLOCK(f) int __need_unlock = ((f)->lock>=0 ? __lockfile((f)) : 0)
#define FUNLOCK(f) if (__need_unlock) __unlockfile((f)); else

#define F_PERM 1
#define F_NORD 4
#define F_NOWR 8
#define F_EOF 16
#define F_ERR 32
#define F_SVB 64

struct __FILE_s {
	unsigned flags;
	unsigned char *rpos, *rend;
	int (*close)(FILE *);
	unsigned char *wend, *wpos;
	unsigned char *mustbezero_1;
	unsigned char *wbase;
	size_t (*read)(FILE *, unsigned char *, size_t);
	size_t (*write)(FILE *, const unsigned char *, size_t);
	off_t (*seek)(FILE *, off_t, int);
	unsigned char *buf;
	size_t buf_size;
	FILE *prev, *next;
	int fd;
	int pipe_pid;
	long lockcount;
	short dummy3;
	signed char mode;
	signed char lbf;
	int lock;
	int waiters;
	void *cookie;
	off_t off;
	void *dummy4;
	void *mustbezero_2;
	unsigned char *shend;
	off_t shlim, shcnt;
};

size_t __stdio_read(FILE *, unsigned char *, size_t);
size_t __stdio_write(FILE *, const unsigned char *, size_t);
size_t __stdout_write(FILE *, const unsigned char *, size_t);
off_t __stdio_seek(FILE *, off_t, int);
int __stdio_close(FILE *);

size_t __string_read(FILE *, unsigned char *, size_t);

int __toread(FILE *);
int __towrite(FILE *);

int __overflow(FILE *, int);
int __oflow(FILE *);
int __uflow(FILE *);
int __underflow(FILE *);

int __fseeko(FILE *, off_t, int);
int __fseeko_unlocked(FILE *, off_t, int);
off_t __ftello(FILE *);
off_t __ftello_unlocked(FILE *);
size_t __fwritex(const unsigned char *, size_t, FILE *);
int __putc_unlocked(int, FILE *);

FILE *__fdopen(int, const char *);

#define OFLLOCK() LOCK(libc.ofl_lock)
#define OFLUNLOCK() UNLOCK(libc.ofl_lock)

#define feof(f) ((f)->flags & F_EOF)
#define ferror(f) ((f)->flags & F_ERR)

#define getc_unlocked(f) \
	( ((f)->rpos < (f)->rend) ? *(f)->rpos++ : __uflow((f)) )

#define putc_unlocked(c, f) ( ((c)!=(f)->lbf && (f)->wpos<(f)->wend) \
	? *(f)->wpos++ = (c) : __overflow((f),(c)) )

/* Caller-allocated FILE * operations */
FILE *__fopen_rb_ca(const char *, FILE *, unsigned char *, size_t);
int __fclose_ca(FILE *);

#endif
