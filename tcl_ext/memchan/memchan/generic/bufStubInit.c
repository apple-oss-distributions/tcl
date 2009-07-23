/* 
 * bufStubInit.c --
 *
 *	This file contains the initializers for the Buf stub vectors.
 *
 */

#include "buf.h"
#include "memchanDecls.h"
#include "bufIntDecls.h"

extern MemchanStubs memchanStubs;

/*
 * WARNING: The contents of this file is automatically generated by the
 * tools/genStubs.tcl script. Any modifications to the function declarations
 * below should be made in the generic/buf.decls script.
 */

/* !BEGIN!: Do not edit below this line. */

BufIntStubs bufIntStubs = {
    TCL_STUB_MAGIC,
    NULL,
};

static BufStubHooks bufStubHooks = {
    &bufIntStubs,
    &memchanStubs
};

BufStubs bufStubs = {
    TCL_STUB_MAGIC,
    &bufStubHooks,
    Buf_IsInitialized, /* 0 */
    Buf_Init, /* 1 */
    NULL, /* 2 */
    NULL, /* 3 */
    NULL, /* 4 */
    NULL, /* 5 */
    NULL, /* 6 */
    NULL, /* 7 */
    NULL, /* 8 */
    NULL, /* 9 */
    Buf_RegisterType, /* 10 */
    NULL, /* 11 */
    NULL, /* 12 */
    NULL, /* 13 */
    NULL, /* 14 */
    NULL, /* 15 */
    NULL, /* 16 */
    NULL, /* 17 */
    NULL, /* 18 */
    NULL, /* 19 */
    Buf_IncrRefcount, /* 20 */
    Buf_DecrRefcount, /* 21 */
    Buf_IsShared, /* 22 */
    Buf_GetType, /* 23 */
    Buf_GetTypeName, /* 24 */
    Buf_Size, /* 25 */
    Buf_GetClientData, /* 26 */
    NULL, /* 27 */
    NULL, /* 28 */
    NULL, /* 29 */
    Buf_Create, /* 30 */
    Buf_Dup, /* 31 */
    Buf_CreateFixedBuffer, /* 32 */
    Buf_CreateExtendableBuffer, /* 33 */
    Buf_CreateRange, /* 34 */
    NULL, /* 35 */
    NULL, /* 36 */
    NULL, /* 37 */
    NULL, /* 38 */
    NULL, /* 39 */
    Buf_Read, /* 40 */
    Buf_Write, /* 41 */
    NULL, /* 42 */
    NULL, /* 43 */
    NULL, /* 44 */
    NULL, /* 45 */
    NULL, /* 46 */
    NULL, /* 47 */
    NULL, /* 48 */
    NULL, /* 49 */
    Buf_PositionPtr, /* 50 */
    Buf_Tell, /* 51 */
    Buf_FreePosition, /* 52 */
    Buf_MovePosition, /* 53 */
    Buf_DupPosition, /* 54 */
    Buf_PositionOffset, /* 55 */
    Buf_PositionFromOffset, /* 56 */
    NULL, /* 57 */
    NULL, /* 58 */
    NULL, /* 59 */
    Buf_NewQueue, /* 60 */
    Buf_FreeQueue, /* 61 */
    Buf_QueueRead, /* 62 */
    Buf_QueueWrite, /* 63 */
    Buf_QueueAppend, /* 64 */
    Buf_QueueSize, /* 65 */
};

/* !END!: Do not edit above this line. */
