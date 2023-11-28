#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

#include <stdint.h>

uint64 sys_mprotect(void){
    int addr;
    int len;
    argint(0, &addr);
    argint(1, &len);

    uintptr_t addr_ptr = (uintptr_t)addr;
    return mprotect((void*) addr_ptr, len);
}

uint64 sys_munprotect(void){
    int addr;
    int len;
    argint(0, &addr);
    argint(1, &len);

    uintptr_t addr_ptr = (uintptr_t)addr;
    return munprotect((void*) addr_ptr, len);
}