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
static const char *ng0 = "/home/ise/Desktop/RISC_V/alu.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {2U, 0U};
static unsigned int ng4[] = {3U, 0U};
static unsigned int ng5[] = {4U, 0U};
static unsigned int ng6[] = {5U, 0U};
static unsigned int ng7[] = {6U, 0U};
static unsigned int ng8[] = {7U, 0U};
static unsigned int ng9[] = {8U, 0U};
static unsigned int ng10[] = {9U, 0U};



static void Always_40_0(char *t0)
{
    char t10[8];
    char t40[8];
    char t41[8];
    char t42[8];
    char t43[8];
    char t56[8];
    char t57[8];
    char t61[8];
    char t85[8];
    char t86[8];
    char t89[8];
    char t98[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
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
    int t31;
    int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    char *t44;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    char *t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    char *t58;
    char *t59;
    char *t60;
    char *t62;
    char *t63;
    char *t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    char *t70;
    char *t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    char *t87;
    char *t88;
    char *t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    char *t97;
    char *t99;
    char *t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    char *t113;
    char *t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    char *t120;
    char *t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    char *t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    char *t130;
    char *t131;

LAB0:    t1 = (t0 + 4040U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 4360);
    *((int *)t2) = 1;
    t3 = (t0 + 4072);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(40, ng0);

LAB5:    xsi_set_current_line(41, ng0);
    t4 = (t0 + 2728U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t4, 4);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng7)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng8)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng9)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng10)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB25;

LAB26:
LAB28:
LAB27:    xsi_set_current_line(76, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3128);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB29:    goto LAB2;

LAB7:    xsi_set_current_line(42, ng0);

LAB30:    xsi_set_current_line(43, ng0);
    t7 = (t0 + 2408U);
    t8 = *((char **)t7);
    t7 = (t0 + 2568U);
    t9 = *((char **)t7);
    memset(t10, 0, 8);
    xsi_vlog_unsigned_add(t10, 32, t8, 32, t9, 32);
    t7 = (t0 + 3128);
    xsi_vlogvar_assign_value(t7, t10, 0, 0, 32);
    goto LAB29;

LAB9:    xsi_set_current_line(45, ng0);

LAB31:    xsi_set_current_line(46, ng0);
    t3 = (t0 + 2408U);
    t4 = *((char **)t3);
    t3 = (t0 + 2568U);
    t7 = *((char **)t3);
    memset(t10, 0, 8);
    xsi_vlog_unsigned_minus(t10, 32, t4, 32, t7, 32);
    t3 = (t0 + 3128);
    xsi_vlogvar_assign_value(t3, t10, 0, 0, 32);
    goto LAB29;

LAB11:    xsi_set_current_line(48, ng0);

LAB32:    xsi_set_current_line(49, ng0);
    t3 = (t0 + 2408U);
    t4 = *((char **)t3);
    t3 = (t0 + 2568U);
    t7 = *((char **)t3);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t7);
    t13 = (t11 & t12);
    *((unsigned int *)t10) = t13;
    t3 = (t4 + 4);
    t8 = (t7 + 4);
    t9 = (t10 + 4);
    t14 = *((unsigned int *)t3);
    t15 = *((unsigned int *)t8);
    t16 = (t14 | t15);
    *((unsigned int *)t9) = t16;
    t17 = *((unsigned int *)t9);
    t18 = (t17 != 0);
    if (t18 == 1)
        goto LAB33;

LAB34:
LAB35:    t39 = (t0 + 3128);
    xsi_vlogvar_assign_value(t39, t10, 0, 0, 32);
    goto LAB29;

LAB13:    xsi_set_current_line(51, ng0);

LAB36:    xsi_set_current_line(52, ng0);
    t3 = (t0 + 2408U);
    t4 = *((char **)t3);
    t3 = (t0 + 2568U);
    t7 = *((char **)t3);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t7);
    t13 = (t11 | t12);
    *((unsigned int *)t10) = t13;
    t3 = (t4 + 4);
    t8 = (t7 + 4);
    t9 = (t10 + 4);
    t14 = *((unsigned int *)t3);
    t15 = *((unsigned int *)t8);
    t16 = (t14 | t15);
    *((unsigned int *)t9) = t16;
    t17 = *((unsigned int *)t9);
    t18 = (t17 != 0);
    if (t18 == 1)
        goto LAB37;

LAB38:
LAB39:    t39 = (t0 + 3128);
    xsi_vlogvar_assign_value(t39, t10, 0, 0, 32);
    goto LAB29;

LAB15:    xsi_set_current_line(54, ng0);

LAB40:    xsi_set_current_line(55, ng0);
    t3 = (t0 + 2408U);
    t4 = *((char **)t3);
    t3 = (t0 + 2568U);
    t7 = *((char **)t3);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    *((unsigned int *)t10) = t13;
    t3 = (t4 + 4);
    t8 = (t7 + 4);
    t9 = (t10 + 4);
    t14 = *((unsigned int *)t3);
    t15 = *((unsigned int *)t8);
    t16 = (t14 | t15);
    *((unsigned int *)t9) = t16;
    t17 = *((unsigned int *)t9);
    t18 = (t17 != 0);
    if (t18 == 1)
        goto LAB41;

LAB42:
LAB43:    t21 = (t0 + 3128);
    xsi_vlogvar_assign_value(t21, t10, 0, 0, 32);
    goto LAB29;

LAB17:    xsi_set_current_line(57, ng0);

LAB44:    xsi_set_current_line(58, ng0);
    t3 = (t0 + 2408U);
    t4 = *((char **)t3);
    t3 = (t0 + 2568U);
    t7 = *((char **)t3);
    memset(t10, 0, 8);
    t3 = (t10 + 4);
    t8 = (t7 + 4);
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 0);
    *((unsigned int *)t10) = t12;
    t13 = *((unsigned int *)t8);
    t14 = (t13 >> 0);
    *((unsigned int *)t3) = t14;
    t15 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t15 & 31U);
    t16 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t16 & 31U);
    memset(t40, 0, 8);
    xsi_vlog_unsigned_lshift(t40, 32, t4, 32, t10, 5);
    t9 = (t0 + 3128);
    xsi_vlogvar_assign_value(t9, t40, 0, 0, 32);
    goto LAB29;

LAB19:    xsi_set_current_line(60, ng0);

LAB45:    xsi_set_current_line(61, ng0);
    t3 = (t0 + 2408U);
    t4 = *((char **)t3);
    t3 = (t0 + 2568U);
    t7 = *((char **)t3);
    memset(t10, 0, 8);
    t3 = (t10 + 4);
    t8 = (t7 + 4);
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 0);
    *((unsigned int *)t10) = t12;
    t13 = *((unsigned int *)t8);
    t14 = (t13 >> 0);
    *((unsigned int *)t3) = t14;
    t15 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t15 & 31U);
    t16 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t16 & 31U);
    memset(t40, 0, 8);
    xsi_vlog_unsigned_rshift(t40, 32, t4, 32, t10, 5);
    t9 = (t0 + 3128);
    xsi_vlogvar_assign_value(t9, t40, 0, 0, 32);
    goto LAB29;

LAB21:    xsi_set_current_line(63, ng0);

LAB46:    xsi_set_current_line(64, ng0);
    t3 = (t0 + 2408U);
    t4 = *((char **)t3);
    t3 = (t0 + 2568U);
    t7 = *((char **)t3);
    memset(t40, 0, 8);
    t3 = (t40 + 4);
    t8 = (t7 + 4);
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 0);
    *((unsigned int *)t40) = t12;
    t13 = *((unsigned int *)t8);
    t14 = (t13 >> 0);
    *((unsigned int *)t3) = t14;
    t15 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t15 & 31U);
    t16 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t16 & 31U);
    memset(t41, 0, 8);
    xsi_vlog_signed_arith_rshift(t41, 32, t4, 32, t40, 5);
    t9 = (t0 + 3128);
    xsi_vlogvar_assign_value(t9, t41, 0, 0, 32);
    goto LAB29;

LAB23:    xsi_set_current_line(66, ng0);

LAB47:    xsi_set_current_line(68, ng0);
    t3 = (t0 + 2408U);
    t4 = *((char **)t3);
    memset(t41, 0, 8);
    t3 = (t41 + 4);
    t7 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 31);
    t13 = (t12 & 1);
    *((unsigned int *)t41) = t13;
    t14 = *((unsigned int *)t7);
    t15 = (t14 >> 31);
    t16 = (t15 & 1);
    *((unsigned int *)t3) = t16;
    t8 = (t0 + 2568U);
    t9 = *((char **)t8);
    memset(t42, 0, 8);
    t8 = (t42 + 4);
    t21 = (t9 + 4);
    t17 = *((unsigned int *)t9);
    t18 = (t17 >> 31);
    t19 = (t18 & 1);
    *((unsigned int *)t42) = t19;
    t20 = *((unsigned int *)t21);
    t23 = (t20 >> 31);
    t24 = (t23 & 1);
    *((unsigned int *)t8) = t24;
    memset(t43, 0, 8);
    t22 = (t41 + 4);
    t39 = (t42 + 4);
    t25 = *((unsigned int *)t41);
    t26 = *((unsigned int *)t42);
    t27 = (t25 ^ t26);
    t28 = *((unsigned int *)t22);
    t29 = *((unsigned int *)t39);
    t30 = (t28 ^ t29);
    t33 = (t27 | t30);
    t34 = *((unsigned int *)t22);
    t35 = *((unsigned int *)t39);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB51;

LAB48:    if (t36 != 0)
        goto LAB50;

LAB49:    *((unsigned int *)t43) = 1;

LAB51:    memset(t40, 0, 8);
    t45 = (t43 + 4);
    t46 = *((unsigned int *)t45);
    t47 = (~(t46));
    t48 = *((unsigned int *)t43);
    t49 = (t48 & t47);
    t50 = (t49 & 1U);
    if (t50 != 0)
        goto LAB52;

LAB53:    if (*((unsigned int *)t45) != 0)
        goto LAB54;

LAB55:    t52 = (t40 + 4);
    t53 = *((unsigned int *)t40);
    t54 = *((unsigned int *)t52);
    t55 = (t53 || t54);
    if (t55 > 0)
        goto LAB56;

LAB57:    t81 = *((unsigned int *)t40);
    t82 = (~(t81));
    t83 = *((unsigned int *)t52);
    t84 = (t82 || t83);
    if (t84 > 0)
        goto LAB58;

LAB59:    if (*((unsigned int *)t52) > 0)
        goto LAB60;

LAB61:    if (*((unsigned int *)t40) > 0)
        goto LAB62;

LAB63:    memcpy(t10, t85, 8);

LAB64:    t131 = (t0 + 3128);
    xsi_vlogvar_assign_value(t131, t10, 0, 0, 32);
    goto LAB29;

LAB25:    xsi_set_current_line(72, ng0);

LAB100:    xsi_set_current_line(73, ng0);
    t3 = (t0 + 2408U);
    t4 = *((char **)t3);
    t3 = (t0 + 2568U);
    t7 = *((char **)t3);
    memset(t41, 0, 8);
    t3 = (t4 + 4);
    if (*((unsigned int *)t3) != 0)
        goto LAB102;

LAB101:    t8 = (t7 + 4);
    if (*((unsigned int *)t8) != 0)
        goto LAB102;

LAB105:    if (*((unsigned int *)t4) < *((unsigned int *)t7))
        goto LAB103;

LAB104:    memset(t40, 0, 8);
    t21 = (t41 + 4);
    t11 = *((unsigned int *)t21);
    t12 = (~(t11));
    t13 = *((unsigned int *)t41);
    t14 = (t13 & t12);
    t15 = (t14 & 1U);
    if (t15 != 0)
        goto LAB106;

LAB107:    if (*((unsigned int *)t21) != 0)
        goto LAB108;

LAB109:    t39 = (t40 + 4);
    t16 = *((unsigned int *)t40);
    t17 = *((unsigned int *)t39);
    t18 = (t16 || t17);
    if (t18 > 0)
        goto LAB110;

LAB111:    t19 = *((unsigned int *)t40);
    t20 = (~(t19));
    t23 = *((unsigned int *)t39);
    t24 = (t20 || t23);
    if (t24 > 0)
        goto LAB112;

LAB113:    if (*((unsigned int *)t39) > 0)
        goto LAB114;

LAB115:    if (*((unsigned int *)t40) > 0)
        goto LAB116;

LAB117:    memcpy(t10, t45, 8);

LAB118:    t51 = (t0 + 3128);
    xsi_vlogvar_assign_value(t51, t10, 0, 0, 32);
    goto LAB29;

LAB33:    t19 = *((unsigned int *)t10);
    t20 = *((unsigned int *)t9);
    *((unsigned int *)t10) = (t19 | t20);
    t21 = (t4 + 4);
    t22 = (t7 + 4);
    t23 = *((unsigned int *)t4);
    t24 = (~(t23));
    t25 = *((unsigned int *)t21);
    t26 = (~(t25));
    t27 = *((unsigned int *)t7);
    t28 = (~(t27));
    t29 = *((unsigned int *)t22);
    t30 = (~(t29));
    t31 = (t24 & t26);
    t32 = (t28 & t30);
    t33 = (~(t31));
    t34 = (~(t32));
    t35 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t35 & t33);
    t36 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t36 & t34);
    t37 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t37 & t33);
    t38 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t38 & t34);
    goto LAB35;

LAB37:    t19 = *((unsigned int *)t10);
    t20 = *((unsigned int *)t9);
    *((unsigned int *)t10) = (t19 | t20);
    t21 = (t4 + 4);
    t22 = (t7 + 4);
    t23 = *((unsigned int *)t21);
    t24 = (~(t23));
    t25 = *((unsigned int *)t4);
    t31 = (t25 & t24);
    t26 = *((unsigned int *)t22);
    t27 = (~(t26));
    t28 = *((unsigned int *)t7);
    t32 = (t28 & t27);
    t29 = (~(t31));
    t30 = (~(t32));
    t33 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t33 & t29);
    t34 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t34 & t30);
    goto LAB39;

LAB41:    t19 = *((unsigned int *)t10);
    t20 = *((unsigned int *)t9);
    *((unsigned int *)t10) = (t19 | t20);
    goto LAB43;

LAB50:    t44 = (t43 + 4);
    *((unsigned int *)t43) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB51;

LAB52:    *((unsigned int *)t40) = 1;
    goto LAB55;

LAB54:    t51 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t51) = 1;
    goto LAB55;

LAB56:    t58 = (t0 + 2408U);
    t59 = *((char **)t58);
    t58 = (t0 + 2568U);
    t60 = *((char **)t58);
    memset(t61, 0, 8);
    t58 = (t59 + 4);
    if (*((unsigned int *)t58) != 0)
        goto LAB66;

LAB65:    t62 = (t60 + 4);
    if (*((unsigned int *)t62) != 0)
        goto LAB66;

LAB69:    if (*((unsigned int *)t59) < *((unsigned int *)t60))
        goto LAB67;

LAB68:    memset(t57, 0, 8);
    t64 = (t61 + 4);
    t65 = *((unsigned int *)t64);
    t66 = (~(t65));
    t67 = *((unsigned int *)t61);
    t68 = (t67 & t66);
    t69 = (t68 & 1U);
    if (t69 != 0)
        goto LAB70;

LAB71:    if (*((unsigned int *)t64) != 0)
        goto LAB72;

LAB73:    t71 = (t57 + 4);
    t72 = *((unsigned int *)t57);
    t73 = *((unsigned int *)t71);
    t74 = (t72 || t73);
    if (t74 > 0)
        goto LAB74;

LAB75:    t76 = *((unsigned int *)t57);
    t77 = (~(t76));
    t78 = *((unsigned int *)t71);
    t79 = (t77 || t78);
    if (t79 > 0)
        goto LAB76;

LAB77:    if (*((unsigned int *)t71) > 0)
        goto LAB78;

LAB79:    if (*((unsigned int *)t57) > 0)
        goto LAB80;

LAB81:    memcpy(t56, t80, 8);

LAB82:    goto LAB57;

LAB58:    t87 = (t0 + 2408U);
    t88 = *((char **)t87);
    memset(t89, 0, 8);
    t87 = (t89 + 4);
    t90 = (t88 + 4);
    t91 = *((unsigned int *)t88);
    t92 = (t91 >> 31);
    t93 = (t92 & 1);
    *((unsigned int *)t89) = t93;
    t94 = *((unsigned int *)t90);
    t95 = (t94 >> 31);
    t96 = (t95 & 1);
    *((unsigned int *)t87) = t96;
    t97 = ((char*)((ng2)));
    memset(t98, 0, 8);
    t99 = (t89 + 4);
    t100 = (t97 + 4);
    t101 = *((unsigned int *)t89);
    t102 = *((unsigned int *)t97);
    t103 = (t101 ^ t102);
    t104 = *((unsigned int *)t99);
    t105 = *((unsigned int *)t100);
    t106 = (t104 ^ t105);
    t107 = (t103 | t106);
    t108 = *((unsigned int *)t99);
    t109 = *((unsigned int *)t100);
    t110 = (t108 | t109);
    t111 = (~(t110));
    t112 = (t107 & t111);
    if (t112 != 0)
        goto LAB86;

LAB83:    if (t110 != 0)
        goto LAB85;

LAB84:    *((unsigned int *)t98) = 1;

LAB86:    memset(t86, 0, 8);
    t114 = (t98 + 4);
    t115 = *((unsigned int *)t114);
    t116 = (~(t115));
    t117 = *((unsigned int *)t98);
    t118 = (t117 & t116);
    t119 = (t118 & 1U);
    if (t119 != 0)
        goto LAB87;

LAB88:    if (*((unsigned int *)t114) != 0)
        goto LAB89;

LAB90:    t121 = (t86 + 4);
    t122 = *((unsigned int *)t86);
    t123 = *((unsigned int *)t121);
    t124 = (t122 || t123);
    if (t124 > 0)
        goto LAB91;

LAB92:    t126 = *((unsigned int *)t86);
    t127 = (~(t126));
    t128 = *((unsigned int *)t121);
    t129 = (t127 || t128);
    if (t129 > 0)
        goto LAB93;

LAB94:    if (*((unsigned int *)t121) > 0)
        goto LAB95;

LAB96:    if (*((unsigned int *)t86) > 0)
        goto LAB97;

LAB98:    memcpy(t85, t130, 8);

LAB99:    goto LAB59;

LAB60:    xsi_vlog_unsigned_bit_combine(t10, 32, t56, 32, t85, 32);
    goto LAB64;

LAB62:    memcpy(t10, t56, 8);
    goto LAB64;

LAB66:    t63 = (t61 + 4);
    *((unsigned int *)t61) = 1;
    *((unsigned int *)t63) = 1;
    goto LAB68;

LAB67:    *((unsigned int *)t61) = 1;
    goto LAB68;

LAB70:    *((unsigned int *)t57) = 1;
    goto LAB73;

LAB72:    t70 = (t57 + 4);
    *((unsigned int *)t57) = 1;
    *((unsigned int *)t70) = 1;
    goto LAB73;

LAB74:    t75 = ((char*)((ng2)));
    goto LAB75;

LAB76:    t80 = ((char*)((ng1)));
    goto LAB77;

LAB78:    xsi_vlog_unsigned_bit_combine(t56, 32, t75, 32, t80, 32);
    goto LAB82;

LAB80:    memcpy(t56, t75, 8);
    goto LAB82;

LAB85:    t113 = (t98 + 4);
    *((unsigned int *)t98) = 1;
    *((unsigned int *)t113) = 1;
    goto LAB86;

LAB87:    *((unsigned int *)t86) = 1;
    goto LAB90;

LAB89:    t120 = (t86 + 4);
    *((unsigned int *)t86) = 1;
    *((unsigned int *)t120) = 1;
    goto LAB90;

LAB91:    t125 = ((char*)((ng2)));
    goto LAB92;

LAB93:    t130 = ((char*)((ng1)));
    goto LAB94;

LAB95:    xsi_vlog_unsigned_bit_combine(t85, 32, t125, 32, t130, 32);
    goto LAB99;

LAB97:    memcpy(t85, t125, 8);
    goto LAB99;

LAB102:    t9 = (t41 + 4);
    *((unsigned int *)t41) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB104;

LAB103:    *((unsigned int *)t41) = 1;
    goto LAB104;

LAB106:    *((unsigned int *)t40) = 1;
    goto LAB109;

LAB108:    t22 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB109;

LAB110:    t44 = ((char*)((ng2)));
    goto LAB111;

LAB112:    t45 = ((char*)((ng1)));
    goto LAB113;

LAB114:    xsi_vlog_unsigned_bit_combine(t10, 32, t44, 32, t45, 32);
    goto LAB118;

LAB116:    memcpy(t10, t44, 8);
    goto LAB118;

}


extern void work_m_07043312352245072413_2725559894_init()
{
	static char *pe[] = {(void *)Always_40_0};
	xsi_register_didat("work_m_07043312352245072413_2725559894", "isim/alu_tb_isim_beh.exe.sim/work/m_07043312352245072413_2725559894.didat");
	xsi_register_executes(pe);
}
