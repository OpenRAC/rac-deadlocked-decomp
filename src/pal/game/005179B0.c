#include "common.h"

extern void func_0046FB00(void *, s32, s32);
extern void func_00474148(void *, s32, s32, f32);
extern s32 func_00513728(void *, s32);
extern void func_00524030(void *, s32, s32, s32, f32);

// Clear the two handles at arg0+0x7E8 and the flags at 0x2658/0x265A, then call func_00524030 when 0x25CC is 0 and the owner's byte 0x54 matches 0x2DD4.
void func_005179B0(u8 *arg0) {
    s32 i;

    *(s32 *)(arg0 + 0x7F4) = 0;
    if (arg0[0x265A] == 0) {
        arg0[0x265A] = 0;
        arg0[0x2658] = 0;
        for (i = 0; i < 2; i++) {
            s32 *slot = (s32 *)(arg0 + 0x7E8) + i;
            if (*slot != 0) {
                func_0046FB00(*(void **)(arg0 + 0x2EF0), *slot, 0);
                *slot = 0;
            }
        }
        if (*(s32 *)(arg0 + 0x25CC) == 0 &&
            (*(u8 **)(arg0 + 0x2EF0))[0x54] == *(s32 *)(arg0 + 0x2DD4)) {
            if (*(s32 *)(arg0 + 0x2318) == 3) {
                func_00524030(arg0, 0x3E, 0, 0, -2.0f);
                func_00474148(*(void **)(arg0 + 0x22F0), 4, -2, 0.0f);
            } else {
                func_00524030(arg0, func_00513728(arg0, 0), 0, 0, -2.0f);
            }
        }
    } else {
        arg0[0x265A] = 0;
        arg0[0x2658] = 0;
        if (*(s32 *)(arg0 + 0x7E8) != 0) {
            for (i = 0; i < 2; i++) {
                s32 *slot = (s32 *)(arg0 + 0x7E8) + i;
                if (*slot != 0) {
                    func_0046FB00(*(void **)(arg0 + 0x2EF0), *slot, 8);
                    *slot = 0;
                }
            }
            *(s32 *)(arg0 + 0x7F4) = 0;
        }
        if (*(s32 *)(arg0 + 0x25CC) == 0 &&
            (*(u8 **)(arg0 + 0x2EF0))[0x54] == *(s32 *)(arg0 + 0x2DD4)) {
            if (*(s32 *)(arg0 + 0x2318) == 3) {
                func_00524030(arg0, 0x3E, 0, 0, -2.0f);
            } else {
                func_00524030(arg0, func_00513728(arg0, 0), 0, 0, -2.0f);
            }
        }
        arg0[0x265A] = 0;
        arg0[0x2658] = 0;
    }
}
