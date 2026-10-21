/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/ise/Desktop/RISC_V/data_memory.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {65536U, 0U};
static unsigned int ng3[] = {0U, 0U};
static unsigned int ng4[] = {1U, 0U};
static int ng5[] = {7, 0};
static int ng6[] = {15, 0};
static int ng7[] = {8, 0};
static int ng8[] = {23, 0};
static int ng9[] = {16, 0};
static int ng10[] = {31, 0};
static int ng11[] = {24, 0};



static void Always_35_0(char *t0)
{
    char t13[8];
    char t20[8];
    char t48[8];
    char t50[8];
    char t51[8];
    char t56[8];
    char t66[8];
    char t67[8];
    char t68[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    char *t43;
    int t44;
    char *t45;
    char *t46;
    char *t47;
    unsigned int t49;
    char *t52;
    char *t53;
    char *t54;
    char *t55;
    char *t57;
    char *t58;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t69;
    char *t70;
    char *t71;
    char *t72;
    char *t73;
    char *t74;
    unsigned int t75;
    char *t76;
    unsigned int t77;
    int t78;
    int t79;
    char *t80;
    unsigned int t81;
    int t82;
    int t83;
    char *t84;
    unsigned int t85;
    int t86;
    int t87;
    char *t88;
    unsigned int t89;
    int t90;
    int t91;
    unsigned int t92;
    int t93;
    unsigned int t94;
    unsigned int t95;
    int t96;
    unsigned int t97;
    unsigned int t98;
    int t99;
    int t100;

LAB0:    t1 = (t0 + 3800U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(35, ng0);
    t2 = (t0 + 4120);
    *((int *)t2) = 1;
    t3 = (t0 + 3832);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(35, ng0);

LAB5:    xsi_set_current_line(36, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(41, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(78, ng0);

LAB70:    xsi_set_current_line(79, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(80, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 32, 0LL);
    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);

LAB12:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(36, ng0);

LAB9:    xsi_set_current_line(37, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 0LL);
    xsi_set_current_line(38, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(39, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);
    goto LAB8;

LAB10:    xsi_set_current_line(41, ng0);

LAB13:    xsi_set_current_line(42, ng0);
    t4 = (t0 + 1688U);
    t5 = *((char **)t4);
    memset(t13, 0, 8);
    t4 = (t13 + 4);
    t11 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = (t14 >> 12);
    *((unsigned int *)t13) = t15;
    t16 = *((unsigned int *)t11);
    t17 = (t16 >> 12);
    *((unsigned int *)t4) = t17;
    t18 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t18 & 1048575U);
    t19 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t19 & 1048575U);
    t12 = ((char*)((ng2)));
    memset(t20, 0, 8);
    t21 = (t13 + 4);
    t22 = (t12 + 4);
    t23 = *((unsigned int *)t13);
    t24 = *((unsigned int *)t12);
    t25 = (t23 ^ t24);
    t26 = *((unsigned int *)t21);
    t27 = *((unsigned int *)t22);
    t28 = (t26 ^ t27);
    t29 = (t25 | t28);
    t30 = *((unsigned int *)t21);
    t31 = *((unsigned int *)t22);
    t32 = (t30 | t31);
    t33 = (~(t32));
    t34 = (t29 & t33);
    if (t34 != 0)
        goto LAB17;

LAB14:    if (t32 != 0)
        goto LAB16;

LAB15:    *((unsigned int *)t20) = 1;

LAB17:    t36 = (t20 + 4);
    t37 = *((unsigned int *)t36);
    t38 = (~(t37));
    t39 = *((unsigned int *)t20);
    t40 = (t39 & t38);
    t41 = (t40 != 0);
    if (t41 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(73, ng0);

LAB69:    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng4)));
    t4 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng4)));
    t4 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);

LAB20:    goto LAB12;

LAB16:    t35 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t35) = 1;
    goto LAB17;

LAB18:    xsi_set_current_line(42, ng0);

LAB21:    xsi_set_current_line(43, ng0);
    t42 = ((char*)((ng3)));
    t43 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t43, t42, 0, 0, 1, 0LL);
    xsi_set_current_line(44, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);

LAB22:    t2 = ((char*)((ng3)));
    t44 = xsi_vlog_unsigned_case_compare(t3, 1, t2, 1);
    if (t44 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng4)));
    t44 = xsi_vlog_unsigned_case_compare(t3, 1, t2, 1);
    if (t44 == 1)
        goto LAB25;

LAB26:
LAB28:
LAB27:    xsi_set_current_line(66, ng0);

LAB68:    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 32, 0LL);
    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);

LAB29:    goto LAB20;

LAB23:    xsi_set_current_line(45, ng0);

LAB30:    xsi_set_current_line(46, ng0);
    t4 = (t0 + 2888);
    t5 = (t4 + 56U);
    t11 = *((char **)t5);
    t12 = (t0 + 2888);
    t21 = (t12 + 72U);
    t22 = *((char **)t21);
    t35 = (t0 + 2888);
    t36 = (t35 + 64U);
    t42 = *((char **)t36);
    t43 = (t0 + 1688U);
    t45 = *((char **)t43);
    memset(t20, 0, 8);
    t43 = (t20 + 4);
    t46 = (t45 + 4);
    t6 = *((unsigned int *)t45);
    t7 = (t6 >> 2);
    *((unsigned int *)t20) = t7;
    t8 = *((unsigned int *)t46);
    t9 = (t8 >> 2);
    *((unsigned int *)t43) = t9;
    t10 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t10 & 1023U);
    t14 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t14 & 1023U);
    xsi_vlog_generic_get_array_select_value(t13, 32, t11, t22, t42, 2, 1, t20, 10, 2);
    t47 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t47, t13, 0, 0, 32, 0LL);
    xsi_set_current_line(47, ng0);
    t2 = ((char*)((ng4)));
    t4 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    goto LAB29;

LAB25:    xsi_set_current_line(49, ng0);

LAB31:    xsi_set_current_line(50, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(57, ng0);
    t2 = (t0 + 2008U);
    t4 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t13 + 4);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 0);
    t8 = (t7 & 1);
    *((unsigned int *)t13) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    t14 = (t10 & 1);
    *((unsigned int *)t2) = t14;
    t11 = ((char*)((ng4)));
    memset(t20, 0, 8);
    t12 = (t13 + 4);
    t21 = (t11 + 4);
    t15 = *((unsigned int *)t13);
    t16 = *((unsigned int *)t11);
    t17 = (t15 ^ t16);
    t18 = *((unsigned int *)t12);
    t19 = *((unsigned int *)t21);
    t23 = (t18 ^ t19);
    t24 = (t17 | t23);
    t25 = *((unsigned int *)t12);
    t26 = *((unsigned int *)t21);
    t27 = (t25 | t26);
    t28 = (~(t27));
    t29 = (t24 & t28);
    if (t29 != 0)
        goto LAB35;

LAB32:    if (t27 != 0)
        goto LAB34;

LAB33:    *((unsigned int *)t20) = 1;

LAB35:    t35 = (t20 + 4);
    t30 = *((unsigned int *)t35);
    t31 = (~(t30));
    t32 = *((unsigned int *)t20);
    t33 = (t32 & t31);
    t34 = (t33 != 0);
    if (t34 > 0)
        goto LAB36;

LAB37:
LAB38:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 2008U);
    t4 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t13 + 4);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 1);
    t8 = (t7 & 1);
    *((unsigned int *)t13) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 1);
    t14 = (t10 & 1);
    *((unsigned int *)t2) = t14;
    t11 = ((char*)((ng4)));
    memset(t20, 0, 8);
    t12 = (t13 + 4);
    t21 = (t11 + 4);
    t15 = *((unsigned int *)t13);
    t16 = *((unsigned int *)t11);
    t17 = (t15 ^ t16);
    t18 = *((unsigned int *)t12);
    t19 = *((unsigned int *)t21);
    t23 = (t18 ^ t19);
    t24 = (t17 | t23);
    t25 = *((unsigned int *)t12);
    t26 = *((unsigned int *)t21);
    t27 = (t25 | t26);
    t28 = (~(t27));
    t29 = (t24 & t28);
    if (t29 != 0)
        goto LAB44;

LAB41:    if (t27 != 0)
        goto LAB43;

LAB42:    *((unsigned int *)t20) = 1;

LAB44:    t35 = (t20 + 4);
    t30 = *((unsigned int *)t35);
    t31 = (~(t30));
    t32 = *((unsigned int *)t20);
    t33 = (t32 & t31);
    t34 = (t33 != 0);
    if (t34 > 0)
        goto LAB45;

LAB46:
LAB47:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 2008U);
    t4 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t13 + 4);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 2);
    t8 = (t7 & 1);
    *((unsigned int *)t13) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 2);
    t14 = (t10 & 1);
    *((unsigned int *)t2) = t14;
    t11 = ((char*)((ng4)));
    memset(t20, 0, 8);
    t12 = (t13 + 4);
    t21 = (t11 + 4);
    t15 = *((unsigned int *)t13);
    t16 = *((unsigned int *)t11);
    t17 = (t15 ^ t16);
    t18 = *((unsigned int *)t12);
    t19 = *((unsigned int *)t21);
    t23 = (t18 ^ t19);
    t24 = (t17 | t23);
    t25 = *((unsigned int *)t12);
    t26 = *((unsigned int *)t21);
    t27 = (t25 | t26);
    t28 = (~(t27));
    t29 = (t24 & t28);
    if (t29 != 0)
        goto LAB53;

LAB50:    if (t27 != 0)
        goto LAB52;

LAB51:    *((unsigned int *)t20) = 1;

LAB53:    t35 = (t20 + 4);
    t30 = *((unsigned int *)t35);
    t31 = (~(t30));
    t32 = *((unsigned int *)t20);
    t33 = (t32 & t31);
    t34 = (t33 != 0);
    if (t34 > 0)
        goto LAB54;

LAB55:
LAB56:    xsi_set_current_line(63, ng0);
    t2 = (t0 + 2008U);
    t4 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t13 + 4);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 3);
    t8 = (t7 & 1);
    *((unsigned int *)t13) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 3);
    t14 = (t10 & 1);
    *((unsigned int *)t2) = t14;
    t11 = ((char*)((ng4)));
    memset(t20, 0, 8);
    t12 = (t13 + 4);
    t21 = (t11 + 4);
    t15 = *((unsigned int *)t13);
    t16 = *((unsigned int *)t11);
    t17 = (t15 ^ t16);
    t18 = *((unsigned int *)t12);
    t19 = *((unsigned int *)t21);
    t23 = (t18 ^ t19);
    t24 = (t17 | t23);
    t25 = *((unsigned int *)t12);
    t26 = *((unsigned int *)t21);
    t27 = (t25 | t26);
    t28 = (~(t27));
    t29 = (t24 & t28);
    if (t29 != 0)
        goto LAB62;

LAB59:    if (t27 != 0)
        goto LAB61;

LAB60:    *((unsigned int *)t20) = 1;

LAB62:    t35 = (t20 + 4);
    t30 = *((unsigned int *)t35);
    t31 = (~(t30));
    t32 = *((unsigned int *)t20);
    t33 = (t32 & t31);
    t34 = (t33 != 0);
    if (t34 > 0)
        goto LAB63;

LAB64:
LAB65:    goto LAB29;

LAB34:    t22 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB35;

LAB36:    xsi_set_current_line(58, ng0);
    t36 = (t0 + 1848U);
    t42 = *((char **)t36);
    memset(t48, 0, 8);
    t36 = (t48 + 4);
    t43 = (t42 + 4);
    t37 = *((unsigned int *)t42);
    t38 = (t37 >> 0);
    *((unsigned int *)t48) = t38;
    t39 = *((unsigned int *)t43);
    t40 = (t39 >> 0);
    *((unsigned int *)t36) = t40;
    t41 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t41 & 255U);
    t49 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t49 & 255U);
    t45 = (t0 + 2888);
    t46 = (t0 + 2888);
    t47 = (t46 + 72U);
    t52 = *((char **)t47);
    t53 = (t0 + 2888);
    t54 = (t53 + 64U);
    t55 = *((char **)t54);
    t57 = (t0 + 1688U);
    t58 = *((char **)t57);
    memset(t56, 0, 8);
    t57 = (t56 + 4);
    t59 = (t58 + 4);
    t60 = *((unsigned int *)t58);
    t61 = (t60 >> 2);
    *((unsigned int *)t56) = t61;
    t62 = *((unsigned int *)t59);
    t63 = (t62 >> 2);
    *((unsigned int *)t57) = t63;
    t64 = *((unsigned int *)t56);
    *((unsigned int *)t56) = (t64 & 1023U);
    t65 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t65 & 1023U);
    xsi_vlog_generic_convert_array_indices(t50, t51, t52, t55, 2, 1, t56, 10, 2);
    t69 = (t0 + 2888);
    t70 = (t69 + 72U);
    t71 = *((char **)t70);
    t72 = ((char*)((ng5)));
    t73 = ((char*)((ng1)));
    xsi_vlog_convert_partindices(t66, t67, t68, ((int*)(t71)), 2, t72, 32, 1, t73, 32, 1);
    t74 = (t50 + 4);
    t75 = *((unsigned int *)t74);
    t44 = (!(t75));
    t76 = (t51 + 4);
    t77 = *((unsigned int *)t76);
    t78 = (!(t77));
    t79 = (t44 && t78);
    t80 = (t66 + 4);
    t81 = *((unsigned int *)t80);
    t82 = (!(t81));
    t83 = (t79 && t82);
    t84 = (t67 + 4);
    t85 = *((unsigned int *)t84);
    t86 = (!(t85));
    t87 = (t83 && t86);
    t88 = (t68 + 4);
    t89 = *((unsigned int *)t88);
    t90 = (!(t89));
    t91 = (t87 && t90);
    if (t91 == 1)
        goto LAB39;

LAB40:    goto LAB38;

LAB39:    t92 = *((unsigned int *)t68);
    t93 = (t92 + 0);
    t94 = *((unsigned int *)t51);
    t95 = *((unsigned int *)t67);
    t96 = (t94 + t95);
    t97 = *((unsigned int *)t66);
    t98 = *((unsigned int *)t67);
    t99 = (t97 - t98);
    t100 = (t99 + 1);
    xsi_vlogvar_wait_assign_value(t45, t48, t93, t96, t100, 0LL);
    goto LAB40;

LAB43:    t22 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB44;

LAB45:    xsi_set_current_line(60, ng0);
    t36 = (t0 + 1848U);
    t42 = *((char **)t36);
    memset(t48, 0, 8);
    t36 = (t48 + 4);
    t43 = (t42 + 4);
    t37 = *((unsigned int *)t42);
    t38 = (t37 >> 8);
    *((unsigned int *)t48) = t38;
    t39 = *((unsigned int *)t43);
    t40 = (t39 >> 8);
    *((unsigned int *)t36) = t40;
    t41 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t41 & 255U);
    t49 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t49 & 255U);
    t45 = (t0 + 2888);
    t46 = (t0 + 2888);
    t47 = (t46 + 72U);
    t52 = *((char **)t47);
    t53 = (t0 + 2888);
    t54 = (t53 + 64U);
    t55 = *((char **)t54);
    t57 = (t0 + 1688U);
    t58 = *((char **)t57);
    memset(t56, 0, 8);
    t57 = (t56 + 4);
    t59 = (t58 + 4);
    t60 = *((unsigned int *)t58);
    t61 = (t60 >> 2);
    *((unsigned int *)t56) = t61;
    t62 = *((unsigned int *)t59);
    t63 = (t62 >> 2);
    *((unsigned int *)t57) = t63;
    t64 = *((unsigned int *)t56);
    *((unsigned int *)t56) = (t64 & 1023U);
    t65 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t65 & 1023U);
    xsi_vlog_generic_convert_array_indices(t50, t51, t52, t55, 2, 1, t56, 10, 2);
    t69 = (t0 + 2888);
    t70 = (t69 + 72U);
    t71 = *((char **)t70);
    t72 = ((char*)((ng6)));
    t73 = ((char*)((ng7)));
    xsi_vlog_convert_partindices(t66, t67, t68, ((int*)(t71)), 2, t72, 32, 1, t73, 32, 1);
    t74 = (t50 + 4);
    t75 = *((unsigned int *)t74);
    t44 = (!(t75));
    t76 = (t51 + 4);
    t77 = *((unsigned int *)t76);
    t78 = (!(t77));
    t79 = (t44 && t78);
    t80 = (t66 + 4);
    t81 = *((unsigned int *)t80);
    t82 = (!(t81));
    t83 = (t79 && t82);
    t84 = (t67 + 4);
    t85 = *((unsigned int *)t84);
    t86 = (!(t85));
    t87 = (t83 && t86);
    t88 = (t68 + 4);
    t89 = *((unsigned int *)t88);
    t90 = (!(t89));
    t91 = (t87 && t90);
    if (t91 == 1)
        goto LAB48;

LAB49:    goto LAB47;

LAB48:    t92 = *((unsigned int *)t68);
    t93 = (t92 + 0);
    t94 = *((unsigned int *)t51);
    t95 = *((unsigned int *)t67);
    t96 = (t94 + t95);
    t97 = *((unsigned int *)t66);
    t98 = *((unsigned int *)t67);
    t99 = (t97 - t98);
    t100 = (t99 + 1);
    xsi_vlogvar_wait_assign_value(t45, t48, t93, t96, t100, 0LL);
    goto LAB49;

LAB52:    t22 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB53;

LAB54:    xsi_set_current_line(62, ng0);
    t36 = (t0 + 1848U);
    t42 = *((char **)t36);
    memset(t48, 0, 8);
    t36 = (t48 + 4);
    t43 = (t42 + 4);
    t37 = *((unsigned int *)t42);
    t38 = (t37 >> 16);
    *((unsigned int *)t48) = t38;
    t39 = *((unsigned int *)t43);
    t40 = (t39 >> 16);
    *((unsigned int *)t36) = t40;
    t41 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t41 & 255U);
    t49 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t49 & 255U);
    t45 = (t0 + 2888);
    t46 = (t0 + 2888);
    t47 = (t46 + 72U);
    t52 = *((char **)t47);
    t53 = (t0 + 2888);
    t54 = (t53 + 64U);
    t55 = *((char **)t54);
    t57 = (t0 + 1688U);
    t58 = *((char **)t57);
    memset(t56, 0, 8);
    t57 = (t56 + 4);
    t59 = (t58 + 4);
    t60 = *((unsigned int *)t58);
    t61 = (t60 >> 2);
    *((unsigned int *)t56) = t61;
    t62 = *((unsigned int *)t59);
    t63 = (t62 >> 2);
    *((unsigned int *)t57) = t63;
    t64 = *((unsigned int *)t56);
    *((unsigned int *)t56) = (t64 & 1023U);
    t65 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t65 & 1023U);
    xsi_vlog_generic_convert_array_indices(t50, t51, t52, t55, 2, 1, t56, 10, 2);
    t69 = (t0 + 2888);
    t70 = (t69 + 72U);
    t71 = *((char **)t70);
    t72 = ((char*)((ng8)));
    t73 = ((char*)((ng9)));
    xsi_vlog_convert_partindices(t66, t67, t68, ((int*)(t71)), 2, t72, 32, 1, t73, 32, 1);
    t74 = (t50 + 4);
    t75 = *((unsigned int *)t74);
    t44 = (!(t75));
    t76 = (t51 + 4);
    t77 = *((unsigned int *)t76);
    t78 = (!(t77));
    t79 = (t44 && t78);
    t80 = (t66 + 4);
    t81 = *((unsigned int *)t80);
    t82 = (!(t81));
    t83 = (t79 && t82);
    t84 = (t67 + 4);
    t85 = *((unsigned int *)t84);
    t86 = (!(t85));
    t87 = (t83 && t86);
    t88 = (t68 + 4);
    t89 = *((unsigned int *)t88);
    t90 = (!(t89));
    t91 = (t87 && t90);
    if (t91 == 1)
        goto LAB57;

LAB58:    goto LAB56;

LAB57:    t92 = *((unsigned int *)t68);
    t93 = (t92 + 0);
    t94 = *((unsigned int *)t51);
    t95 = *((unsigned int *)t67);
    t96 = (t94 + t95);
    t97 = *((unsigned int *)t66);
    t98 = *((unsigned int *)t67);
    t99 = (t97 - t98);
    t100 = (t99 + 1);
    xsi_vlogvar_wait_assign_value(t45, t48, t93, t96, t100, 0LL);
    goto LAB58;

LAB61:    t22 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB62;

LAB63:    xsi_set_current_line(64, ng0);
    t36 = (t0 + 1848U);
    t42 = *((char **)t36);
    memset(t48, 0, 8);
    t36 = (t48 + 4);
    t43 = (t42 + 4);
    t37 = *((unsigned int *)t42);
    t38 = (t37 >> 24);
    *((unsigned int *)t48) = t38;
    t39 = *((unsigned int *)t43);
    t40 = (t39 >> 24);
    *((unsigned int *)t36) = t40;
    t41 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t41 & 255U);
    t49 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t49 & 255U);
    t45 = (t0 + 2888);
    t46 = (t0 + 2888);
    t47 = (t46 + 72U);
    t52 = *((char **)t47);
    t53 = (t0 + 2888);
    t54 = (t53 + 64U);
    t55 = *((char **)t54);
    t57 = (t0 + 1688U);
    t58 = *((char **)t57);
    memset(t56, 0, 8);
    t57 = (t56 + 4);
    t59 = (t58 + 4);
    t60 = *((unsigned int *)t58);
    t61 = (t60 >> 2);
    *((unsigned int *)t56) = t61;
    t62 = *((unsigned int *)t59);
    t63 = (t62 >> 2);
    *((unsigned int *)t57) = t63;
    t64 = *((unsigned int *)t56);
    *((unsigned int *)t56) = (t64 & 1023U);
    t65 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t65 & 1023U);
    xsi_vlog_generic_convert_array_indices(t50, t51, t52, t55, 2, 1, t56, 10, 2);
    t69 = (t0 + 2888);
    t70 = (t69 + 72U);
    t71 = *((char **)t70);
    t72 = ((char*)((ng10)));
    t73 = ((char*)((ng11)));
    xsi_vlog_convert_partindices(t66, t67, t68, ((int*)(t71)), 2, t72, 32, 1, t73, 32, 1);
    t74 = (t50 + 4);
    t75 = *((unsigned int *)t74);
    t44 = (!(t75));
    t76 = (t51 + 4);
    t77 = *((unsigned int *)t76);
    t78 = (!(t77));
    t79 = (t44 && t78);
    t80 = (t66 + 4);
    t81 = *((unsigned int *)t80);
    t82 = (!(t81));
    t83 = (t79 && t82);
    t84 = (t67 + 4);
    t85 = *((unsigned int *)t84);
    t86 = (!(t85));
    t87 = (t83 && t86);
    t88 = (t68 + 4);
    t89 = *((unsigned int *)t88);
    t90 = (!(t89));
    t91 = (t87 && t90);
    if (t91 == 1)
        goto LAB66;

LAB67:    goto LAB65;

LAB66:    t92 = *((unsigned int *)t68);
    t93 = (t92 + 0);
    t94 = *((unsigned int *)t51);
    t95 = *((unsigned int *)t67);
    t96 = (t94 + t95);
    t97 = *((unsigned int *)t66);
    t98 = *((unsigned int *)t67);
    t99 = (t97 - t98);
    t100 = (t99 + 1);
    xsi_vlogvar_wait_assign_value(t45, t48, t93, t96, t100, 0LL);
    goto LAB67;

}


extern void work_m_05547986337533431843_3258266500_init()
{
	static char *pe[] = {(void *)Always_35_0};
	xsi_register_didat("work_m_05547986337533431843_3258266500", "isim/load_store_tb_isim_beh.exe.sim/work/m_05547986337533431843_3258266500.didat");
	xsi_register_executes(pe);
}
