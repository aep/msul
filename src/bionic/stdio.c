#include "stdio_impl.h"

static unsigned char buf_in[BUFSIZ+UNGET];
static unsigned char buf_out[BUFSIZ+UNGET];
static unsigned char buf_err[UNGET];

FILE __sF[3] = {
//stdin
{
	.buf = buf_in + UNGET,
	.buf_size = sizeof buf_in-UNGET,
	.fd = 0,
	.flags = F_PERM | F_NOWR,
	.read = __stdio_read,
	.seek = __stdio_seek,
	.close = __stdio_close,
	.lock = -1,
},
//stdout
{
	.buf = buf_out + UNGET,
	.buf_size = sizeof buf_out-UNGET,
	.fd = 1,
	.flags = F_PERM | F_NORD,
	.lbf = '\n',
	.write = __stdout_write,
	.seek = __stdio_seek,
	.close = __stdio_close,
	.lock = -1,
},
//stdin
{
	.buf = buf_err + UNGET,
	.buf_size = 0,
	.fd = 2,
	.flags = F_PERM | F_NORD,
	.lbf = -1,
	.write = __stdio_write,
	.seek = __stdio_seek,
	.close = __stdio_close,
	.lock = -1,
},
};
