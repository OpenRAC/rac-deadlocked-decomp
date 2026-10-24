#include "common.h"

typedef struct {
    u8 pad0[0x30];
    void (*func30)(void *, s32);
} Ops;

typedef struct {
    u8 pad0[0x1A];
    s16 unk1A;
    s16 unk1C;
    u8 pad1E[0x3E - 0x1E];
    u8 unk3E;
    u8 pad3F;
    s32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
} Cfg;

typedef struct {
    u8 pad0[0xC];
    u8 *unkC;
    u8 pad10[0x2C - 0x10];
    u8 *unk2C;
    u8 pad30[0x7C - 0x30];
    s16 unk7C;
} Sub;

extern u8 *func_00476F70(void *);
extern void *func_0047C510(void *);
extern u8 *func_0053E038(void *);
extern void func_L01_005A7B30(void *, s32, s32, s32, s32);

// Set up the object at vars+0x1D8: fill its parameters, pick its two indices (0x1C4/0x1C8) and copy values into its info block.
void func_L01_00502598(u8 *arg0) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);
    u8 *info;
    u8 *other_info;
    Cfg *cfg;
    s32 n;
    u8 *extra;
    u8 *obj;

    info = func_00476F70(*(void **)(vars + 0x1D8));
    obj = *(u8 **)(vars + 0x1D8);
    if (*(s16 *)(obj + 0xBC) == 0x2722) {
        Sub *p = *(Sub **)(obj + 0xAC);
        p->unkC = (u8 *)p + 0xE0;
        p->unk2C = (u8 *)p + 0x170;
        p->unk7C = 8;
    }
    other_info = func_0047C510(*(void **)(vars + 0x1D8));
    (*(Ops **)(vars + 0x204))->func30(*(void **)(vars + 0x1D8), 0);
    cfg = func_0047C510(*(void **)(vars + 0x1D8));
    cfg->unk40 = 1;
    cfg->unk1C = 3;
    cfg->unk48 = 30.0f;
    cfg->unk1A = 7;
    cfg->unk3E = 20;
    cfg->unk44 = 1.0f;
    cfg->unk4C = 15.0f;
    if (*(s32 *)(vars + 0x1C4) == -1 && *(s32 *)(vars + 0x1C8) == -1 &&
        *(s32 *)(other_info + 0x30) != -1) {
        *(s32 *)(vars + 0x1C4) = *(s32 *)(other_info + 0x30);
        *(s32 *)(vars + 0x1C8) = *(s32 *)(other_info + 0x30);
    } else if (*(s32 *)(vars + 0x1C4) == -1) {
        if (*(s32 *)(vars + 0x1C8) != *(s32 *)(vars + 0x1C4)) {
            *(s32 *)(vars + 0x1C4) = *(s32 *)(vars + 0x1C8);
        }
    } else if (*(s32 *)(vars + 0x1C8) == -1) {
        *(s32 *)(vars + 0x1C8) = *(s32 *)(vars + 0x1C4);
    }
    func_L01_005A7B30(*(void **)(vars + 0x1D8), 4, 1, 1, 0);
    extra = func_0053E038(*(void **)(vars + 0x1D8));
    if (*(s32 *)(vars + 0x54) < 2) {
        *(s32 *)(vars + 0x54) = 100;
    }
    n = *(s32 *)(vars + 0x54);
    *(s32 *)(info + 4) = n;
    *(f32 *)(info + 0) = n;
    if (extra != NULL) {
        *(f32 *)(extra + 0x2E8) = *(f32 *)(info + 0);
        *(f32 *)(extra + 0x2EC) = *(s32 *)(info + 4);
    }
    info[8] = vars[0x58];
    info[9] = vars[0x59];
    info[10] = vars[0x5A];
    *(s32 *)(vars + 0x1EC) = *(s16 *)(vars + 0x1FA) * 50.0f;
}
