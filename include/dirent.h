#ifndef	_DIRENT_H
#define	_DIRENT_H

#ifdef __cplusplus
extern "C" {
#endif

#define __NEED_ino_t
#define __NEED_off_t

#include <bits/alltypes.h>

typedef struct __DIR_s DIR;

struct dirent
{
	ino_t d_ino;
	off_t d_off;
	unsigned short d_reclen;
	unsigned char d_type;
	char d_name[256];
};

#define d_fileno d_ino

int            closedir(DIR *);
DIR           *fdopendir(int);
DIR           *opendir(const char *);
struct dirent *readdir(DIR *);
int            readdir_r(DIR *, struct dirent *, struct dirent **);
void           rewinddir(DIR *);
void           seekdir(DIR *, long);
long           telldir(DIR *);
int            dirfd(DIR *);

int alphasort(const struct dirent **, const struct dirent **);
int scandir(const char *, struct dirent ***, int (*)(const struct dirent *), int (*)(const struct dirent **, const struct dirent **));

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define DT_UNKNOWN 0
#define DT_FIFO 1
#define DT_CHR 2
#define DT_DIR 4
#define DT_BLK 6
#define DT_REG 8
#define DT_LNK 10
#define DT_SOCK 12
#define DT_WHT 14
#define IFTODT(x) ((x)>>12 & 017)
#define DTTOIF(x) ((x)<<12)
#endif

#ifdef _GNU_SOURCE
int versionsort(const struct dirent **, const struct dirent **);
#endif

#if defined(_LARGEFILE64_SOURCE) || defined(_GNU_SOURCE)
#define dirent64 dirent
#define readdir64 readdir
#define readdir64_r readdir_r
#define scandir64 scandir
#define alphasort64 alphasort
#define versionsort64 versionsort
#define off64_t off_t
#define ino64_t ino_t
#endif

#ifdef __cplusplus
}
#endif

#endif
