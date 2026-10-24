#include "common.h"

extern s32 func_L01_00570060(void *, void *);
extern void func_L01_00571210(void *, s32);
extern s32 func_L01_0056E308(void *);
extern s32 func_L01_00570140(void *);
extern s32 func_L01_0056C038(void *, void *);
extern s32 func_00453CE8(void *);
extern void func_L01_0056F450(void *, void *);
extern s32 func_L01_0056E200(void *, s32);
extern u8 *D_00222E14;

// Walk the list at arg0+0x3F0; when no entry is busy and arg0[0] is set, rebuild each entry's mask and reset its timer.
void func_L01_0056FCA0(u8 *arg0) {
    u8 *n;
    s32 idle = 1;

    if (arg0 == NULL) {
        return;
    }
    for (n = *(u8 **)(arg0 + 0x3F0); n != NULL; n = *(u8 **)(n + 0x1AC)) {
        if (n[0x1DA] == 0 && *(s32 *)(n + 0x1C8) != -1 && func_L01_00570060(arg0, n) != 0) {
            func_L01_00571210(D_00222E14 + (*(s32 *)(n + 0x1C8) << 8), -1);
            n[0x1DA] = 1;
        }
        if (func_L01_0056E308(n) != 0) {
            continue;
        }
        idle = 0;
        if (func_L01_00570140(n) == 0) {
            continue;
        }
        if (n[0x17C] == 0 && func_L01_0056C038(n, arg0 + 0xD0) == 0) {
            continue;
        }
        if (func_00453CE8(n + 0x19C) != 0) {
            func_L01_0056F450(arg0, n);
        }
    }
    if (arg0[0] != 0 && idle != 0) {
        for (n = *(u8 **)(arg0 + 0x3F0); n != NULL; n = *(u8 **)(n + 0x1AC)) {
            s32 i;
            u8 *slot;
            *(s32 *)(n + 0x178) = 0;
            for (i = 0, slot = n + 0x53; i < 8; i++, slot += 0x24) {
                if (func_L01_0056E200(n, i) != 0 && *(s32 *)(slot + 1) != -1) {
                    *(s32 *)(n + 0x178) |= 1 << slot[0];
                }
            }
            n[0x17C] = 0;
            *(s16 *)(n + 0x1A2) = 0;
            *(s16 *)(n + 0x17E) = 0;
            n[0x1DB] = 0;
            *(s32 *)(n + 0x19C) = *(f32 *)(n + 0x198) * 50.0f;
        }
    }
}
