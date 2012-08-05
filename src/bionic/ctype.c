#define _U 0x01
#define _L 0x02
#define _N 0x04
#define _S 0x08
#define _P 0x10
#define _C 0x20
#define _X 0x40
#define _B 0x80

#define CTYPE_NUM_CHARS       256
const char _C_ctype_[1 + CTYPE_NUM_CHARS] = {
    0,
    _C,_C,_C,_C,_C,_C,_C,_C,
    _C,_C|_S,_C|_S,_C|_S,_C|_S,_C|_S,_C,_C,
    _C,_C,_C,_C,_C,_C,_C,_C,
    _C,_C,_C,_C,_C,_C,_C,_C,
    _S|(char)_B,_P,_P,_P,_P,_P,_P,_P,
    _P,_P,_P,_P,_P,_P,_P,_P,
    _N,_N,_N,_N,_N,_N,_N,_N,
    _N,_N,_P,_P,_P,_P,_P,_P,
    _P,_U|_X,_U|_X,_U|_X,_U|_X,_U|_X,_U|_X,_U,
    _U,_U,_U,_U,_U,_U,_U,_U,
    _U,_U,_U,_U,_U,_U,_U,_U,
    _U,_U,_U,_P,_P,_P,_P,_P,
    _P,_L|_X,_L|_X,_L|_X,_L|_X,_L|_X,_L|_X,_L,
    _L,_L,_L,_L,_L,_L,_L,_L,
    _L,_L,_L,_L,_L,_L,_L,_L,
    /* determine printability based on the IS0 8859 8-bit standard */
    _L,_L,_L,_P,_P,_P,_P,_C,

    _C,_C,_C,_C,_C,_C,_C,_C, /* 80 */
    _C,_C,_C,_C,_C,_C,_C,_C, /* 88 */
    _C,_C,_C,_C,_C,_C,_C,_C, /* 90 */
    _C,_C,_C,_C,_C,_C,_C,_C, /* 98 */
    _P,_P,_P,_P,_P,_P,_P,_P, /* A0 */
    _P,_P,_P,_P,_P,_P,_P,_P, /* A8 */
    _P,_P,_P,_P,_P,_P,_P,_P, /* B0 */
    _P,_P,_P,_P,_P,_P,_P,_P, /* B8 */
    _P,_P,_P,_P,_P,_P,_P,_P, /* C0 */
    _P,_P,_P,_P,_P,_P,_P,_P, /* C8 */
    _P,_P,_P,_P,_P,_P,_P,_P, /* D0 */
    _P,_P,_P,_P,_P,_P,_P,_P, /* D8 */
    _P,_P,_P,_P,_P,_P,_P,_P, /* E0 */
    _P,_P,_P,_P,_P,_P,_P,_P, /* E8 */
    _P,_P,_P,_P,_P,_P,_P,_P, /* F0 */
    _P,_P,_P,_P,_P,_P,_P,_P  /* F8 */
};

const char *_ctype_ = _C_ctype_;


