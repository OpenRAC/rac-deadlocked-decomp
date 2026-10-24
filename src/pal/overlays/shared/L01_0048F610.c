#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern f32 *func_00476F70(void *);
extern s32 func_00476F40(void *);
extern s32 func_L01_005B2560(void *);
extern void func_L01_005A6848(void *, s32);
extern void func_004850F0(void *, s32, s32);
extern void func_00474368(void *, s32, s32);
extern void func_L00_005F3FC8(void *);
extern void func_L00_00621818(void *, s32, s32);
extern s32 func_L01_005A72B8(void *, void *);
extern void func_L01_005A5EB0(void *);
extern void func_00477AD0(void *, s32);

// Watch the object at arg1+0x170: react when its value at offset 0 drops or reaches zero, then copy a saved position.
s32 func_L01_0048F610(u8 *arg0, u8 *arg1) {
    f32 *value;
    f32 old;
    u8 *obj;

    if (*(u8 **)(arg1 + 0x170) == NULL) {
        return arg0[0x20] != 1;
    }
    value = func_00476F70(*(u8 **)(arg1 + 0x170));
    if (value == NULL) {
        return 1;
    }
    if (func_00476F40(*(u8 **)(arg1 + 0x170)) == 0) {
        return 1;
    }
    old = *value;
    if (func_L01_005B2560(*(u8 **)(arg1 + 0x170)) != 0 || *value < old) {
        func_L01_005A6848(arg0, 200);
    }
    if (*value <= 0.0f) {
        func_004850F0(*(u8 **)(arg1 + 0x170), -1, 0);
        func_00474368(arg0, 5, 4);
    }
    obj = *(u8 **)(arg1 + 0x170);
    if (((*(u64 *)(obj + 0x30) & ((u64)0x8208 << 29)) != ((u64)0x8200 << 23) || *(s32 *)(obj + 0x98) != 0) &&
        *value > 0.0f) {
        func_L00_005F3FC8(obj);
        func_L00_00621818(arg0, 5, -1);
    }
    if (*(s32 *)(arg1 + 0x60) != 0 && func_L01_005A72B8(arg0, arg1 + 0x50) != 0) {
        arg1[0x1D6] = 1;
        *(u128 *)(arg1 + 0xD60) = *(u128 *)(arg1 + 0x50);
    }
    func_L01_005A5EB0(arg0);
    func_00477AD0(*(u8 **)(arg1 + 0x170), 0);
    return 0;
}
