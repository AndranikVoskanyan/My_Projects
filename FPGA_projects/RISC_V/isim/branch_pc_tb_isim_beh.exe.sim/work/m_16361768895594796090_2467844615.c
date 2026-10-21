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
static const char *ng0 = "/home/ise/Desktop/RISC_V/branch_pc.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {4294967294U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {3U, 0U};
static unsigned int ng6[] = {4U, 0U};
static unsigned int ng7[] = {5U, 0U};
static int ng8[] = {0, 0};



static void Always_37_0(char *t0)
{
    char t7[8];
    char t13[8];
    char t46[8];
    char t47[8];
    char t48[8];
    char t55[8];
    char t56[8];
    char t60[8];
    char t84[8];
    char t85[8];
    char t88[8];
    char t97[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    int t37;
    int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    char *t49;
    char *t50;
    char *t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t57;
    char *t58;
    char *t59;
    char *t61;
    char *t62;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    char *t86;
    char *t87;
    char *t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    char *t96;
    char *t98;
    char *t99;
    unsigned int t100;
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
    char *t112;
    char *t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    char *t119;
    char *t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    char *t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    char *t129;
    char *t130;

LAB0:    t1 = (t0 + 4456U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(37, ng0);
    t2 = (t0 + 4776);
    *((int *)t2) = 1;
    t3 = (t0 + 4488);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(37, ng0);

LAB5:    xsi_set_current_line(38, ng0);
    t4 = (t0 + 1864U);
    t5 = *((char **)t4);
    t4 = (t0 + 2344U);
    t6 = *((char **)t4);
    memset(t7, 0, 8);
    xsi_vlog_unsigned_add(t7, 32, t5, 32, t6, 32);
    t4 = (t0 + 3544);
    xsi_vlogvar_assign_value(t4, t7, 0, 0, 32);
    xsi_set_current_line(39, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(40, ng0);
    t2 = (t0 + 2824U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t8 = *((unsigned int *)t2);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(44, ng0);
    t2 = (t0 + 2664U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t8 = *((unsigned int *)t2);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB13;

LAB14:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 2984U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t8 = *((unsigned int *)t2);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB16;

LAB17:
LAB18:
LAB15:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(40, ng0);

LAB9:    xsi_set_current_line(41, ng0);
    t4 = (t0 + 2024U);
    t5 = *((char **)t4);
    t4 = (t0 + 2344U);
    t6 = *((char **)t4);
    memset(t7, 0, 8);
    xsi_vlog_unsigned_add(t7, 32, t5, 32, t6, 32);
    t4 = ((char*)((ng2)));
    t14 = *((unsigned int *)t7);
    t15 = *((unsigned int *)t4);
    t16 = (t14 & t15);
    *((unsigned int *)t13) = t16;
    t17 = (t7 + 4);
    t18 = (t4 + 4);
    t19 = (t13 + 4);
    t20 = *((unsigned int *)t17);
    t21 = *((unsigned int *)t18);
    t22 = (t20 | t21);
    *((unsigned int *)t19) = t22;
    t23 = *((unsigned int *)t19);
    t24 = (t23 != 0);
    if (t24 == 1)
        goto LAB10;

LAB11:
LAB12:    t45 = (t0 + 3544);
    xsi_vlogvar_assign_value(t45, t13, 0, 0, 32);
    xsi_set_current_line(42, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB8;

LAB10:    t25 = *((unsigned int *)t13);
    t26 = *((unsigned int *)t19);
    *((unsigned int *)t13) = (t25 | t26);
    t27 = (t7 + 4);
    t28 = (t4 + 4);
    t29 = *((unsigned int *)t7);
    t30 = (~(t29));
    t31 = *((unsigned int *)t27);
    t32 = (~(t31));
    t33 = *((unsigned int *)t4);
    t34 = (~(t33));
    t35 = *((unsigned int *)t28);
    t36 = (~(t35));
    t37 = (t30 & t32);
    t38 = (t34 & t36);
    t39 = (~(t37));
    t40 = (~(t38));
    t41 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t41 & t39);
    t42 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t42 & t40);
    t43 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t43 & t39);
    t44 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t44 & t40);
    goto LAB12;

LAB13:    xsi_set_current_line(45, ng0);
    t4 = ((char*)((ng3)));
    t5 = (t0 + 3384);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    goto LAB15;

LAB16:    xsi_set_current_line(46, ng0);

LAB19:    xsi_set_current_line(47, ng0);
    t4 = (t0 + 2504U);
    t5 = *((char **)t4);

LAB20:    t4 = ((char*)((ng1)));
    t37 = xsi_vlog_unsigned_case_compare(t5, 3, t4, 3);
    if (t37 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng3)));
    t37 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t37 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng4)));
    t37 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t37 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng5)));
    t37 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t37 == 1)
        goto LAB27;

LAB28:    t2 = ((char*)((ng6)));
    t37 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t37 == 1)
        goto LAB29;

LAB30:    t2 = ((char*)((ng7)));
    t37 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t37 == 1)
        goto LAB31;

LAB32:
LAB34:
LAB33:    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB35:    goto LAB18;

LAB21:    xsi_set_current_line(48, ng0);
    t6 = (t0 + 2024U);
    t17 = *((char **)t6);
    t6 = (t0 + 2184U);
    t18 = *((char **)t6);
    memset(t7, 0, 8);
    t6 = (t17 + 4);
    t19 = (t18 + 4);
    t14 = *((unsigned int *)t17);
    t15 = *((unsigned int *)t18);
    t16 = (t14 ^ t15);
    t20 = *((unsigned int *)t6);
    t21 = *((unsigned int *)t19);
    t22 = (t20 ^ t21);
    t23 = (t16 | t22);
    t24 = *((unsigned int *)t6);
    t25 = *((unsigned int *)t19);
    t26 = (t24 | t25);
    t29 = (~(t26));
    t30 = (t23 & t29);
    if (t30 != 0)
        goto LAB39;

LAB36:    if (t26 != 0)
        goto LAB38;

LAB37:    *((unsigned int *)t7) = 1;

LAB39:    t28 = (t0 + 3384);
    xsi_vlogvar_assign_value(t28, t7, 0, 0, 1);
    goto LAB35;

LAB23:    xsi_set_current_line(49, ng0);
    t3 = (t0 + 2024U);
    t4 = *((char **)t3);
    t3 = (t0 + 2184U);
    t6 = *((char **)t3);
    memset(t7, 0, 8);
    t3 = (t4 + 4);
    t17 = (t6 + 4);
    t8 = *((unsigned int *)t4);
    t9 = *((unsigned int *)t6);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t3);
    t12 = *((unsigned int *)t17);
    t14 = (t11 ^ t12);
    t15 = (t10 | t14);
    t16 = *((unsigned int *)t3);
    t20 = *((unsigned int *)t17);
    t21 = (t16 | t20);
    t22 = (~(t21));
    t23 = (t15 & t22);
    if (t23 != 0)
        goto LAB41;

LAB40:    if (t21 != 0)
        goto LAB42;

LAB43:    t19 = (t0 + 3384);
    xsi_vlogvar_assign_value(t19, t7, 0, 0, 1);
    goto LAB35;

LAB25:    xsi_set_current_line(50, ng0);
    t3 = (t0 + 2024U);
    t4 = *((char **)t3);
    memset(t46, 0, 8);
    t3 = (t46 + 4);
    t6 = (t4 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 31);
    t10 = (t9 & 1);
    *((unsigned int *)t46) = t10;
    t11 = *((unsigned int *)t6);
    t12 = (t11 >> 31);
    t14 = (t12 & 1);
    *((unsigned int *)t3) = t14;
    t17 = (t0 + 2184U);
    t18 = *((char **)t17);
    memset(t47, 0, 8);
    t17 = (t47 + 4);
    t19 = (t18 + 4);
    t15 = *((unsigned int *)t18);
    t16 = (t15 >> 31);
    t20 = (t16 & 1);
    *((unsigned int *)t47) = t20;
    t21 = *((unsigned int *)t19);
    t22 = (t21 >> 31);
    t23 = (t22 & 1);
    *((unsigned int *)t17) = t23;
    memset(t48, 0, 8);
    t27 = (t46 + 4);
    t28 = (t47 + 4);
    t24 = *((unsigned int *)t46);
    t25 = *((unsigned int *)t47);
    t26 = (t24 ^ t25);
    t29 = *((unsigned int *)t27);
    t30 = *((unsigned int *)t28);
    t31 = (t29 ^ t30);
    t32 = (t26 | t31);
    t33 = *((unsigned int *)t27);
    t34 = *((unsigned int *)t28);
    t35 = (t33 | t34);
    t36 = (~(t35));
    t39 = (t32 & t36);
    if (t39 != 0)
        goto LAB47;

LAB44:    if (t35 != 0)
        goto LAB46;

LAB45:    *((unsigned int *)t48) = 1;

LAB47:    memset(t13, 0, 8);
    t49 = (t48 + 4);
    t40 = *((unsigned int *)t49);
    t41 = (~(t40));
    t42 = *((unsigned int *)t48);
    t43 = (t42 & t41);
    t44 = (t43 & 1U);
    if (t44 != 0)
        goto LAB48;

LAB49:    if (*((unsigned int *)t49) != 0)
        goto LAB50;

LAB51:    t51 = (t13 + 4);
    t52 = *((unsigned int *)t13);
    t53 = *((unsigned int *)t51);
    t54 = (t52 || t53);
    if (t54 > 0)
        goto LAB52;

LAB53:    t80 = *((unsigned int *)t13);
    t81 = (~(t80));
    t82 = *((unsigned int *)t51);
    t83 = (t81 || t82);
    if (t83 > 0)
        goto LAB54;

LAB55:    if (*((unsigned int *)t51) > 0)
        goto LAB56;

LAB57:    if (*((unsigned int *)t13) > 0)
        goto LAB58;

LAB59:    memcpy(t7, t84, 8);

LAB60:    t130 = (t0 + 3384);
    xsi_vlogvar_assign_value(t130, t7, 0, 0, 1);
    goto LAB35;

LAB27:    xsi_set_current_line(51, ng0);
    t3 = (t0 + 2024U);
    t4 = *((char **)t3);
    memset(t46, 0, 8);
    t3 = (t46 + 4);
    t6 = (t4 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 31);
    t10 = (t9 & 1);
    *((unsigned int *)t46) = t10;
    t11 = *((unsigned int *)t6);
    t12 = (t11 >> 31);
    t14 = (t12 & 1);
    *((unsigned int *)t3) = t14;
    t17 = (t0 + 2184U);
    t18 = *((char **)t17);
    memset(t47, 0, 8);
    t17 = (t47 + 4);
    t19 = (t18 + 4);
    t15 = *((unsigned int *)t18);
    t16 = (t15 >> 31);
    t20 = (t16 & 1);
    *((unsigned int *)t47) = t20;
    t21 = *((unsigned int *)t19);
    t22 = (t21 >> 31);
    t23 = (t22 & 1);
    *((unsigned int *)t17) = t23;
    memset(t48, 0, 8);
    t27 = (t46 + 4);
    t28 = (t47 + 4);
    t24 = *((unsigned int *)t46);
    t25 = *((unsigned int *)t47);
    t26 = (t24 ^ t25);
    t29 = *((unsigned int *)t27);
    t30 = *((unsigned int *)t28);
    t31 = (t29 ^ t30);
    t32 = (t26 | t31);
    t33 = *((unsigned int *)t27);
    t34 = *((unsigned int *)t28);
    t35 = (t33 | t34);
    t36 = (~(t35));
    t39 = (t32 & t36);
    if (t39 != 0)
        goto LAB99;

LAB96:    if (t35 != 0)
        goto LAB98;

LAB97:    *((unsigned int *)t48) = 1;

LAB99:    memset(t13, 0, 8);
    t49 = (t48 + 4);
    t40 = *((unsigned int *)t49);
    t41 = (~(t40));
    t42 = *((unsigned int *)t48);
    t43 = (t42 & t41);
    t44 = (t43 & 1U);
    if (t44 != 0)
        goto LAB100;

LAB101:    if (*((unsigned int *)t49) != 0)
        goto LAB102;

LAB103:    t51 = (t13 + 4);
    t52 = *((unsigned int *)t13);
    t53 = *((unsigned int *)t51);
    t54 = (t52 || t53);
    if (t54 > 0)
        goto LAB104;

LAB105:    t80 = *((unsigned int *)t13);
    t81 = (~(t80));
    t82 = *((unsigned int *)t51);
    t83 = (t81 || t82);
    if (t83 > 0)
        goto LAB106;

LAB107:    if (*((unsigned int *)t51) > 0)
        goto LAB108;

LAB109:    if (*((unsigned int *)t13) > 0)
        goto LAB110;

LAB111:    memcpy(t7, t84, 8);

LAB112:    t130 = (t0 + 3384);
    xsi_vlogvar_assign_value(t130, t7, 0, 0, 1);
    goto LAB35;

LAB29:    xsi_set_current_line(52, ng0);
    t3 = (t0 + 2024U);
    t4 = *((char **)t3);
    t3 = (t0 + 2184U);
    t6 = *((char **)t3);
    memset(t7, 0, 8);
    t3 = (t4 + 4);
    if (*((unsigned int *)t3) != 0)
        goto LAB149;

LAB148:    t17 = (t6 + 4);
    if (*((unsigned int *)t17) != 0)
        goto LAB149;

LAB152:    if (*((unsigned int *)t4) < *((unsigned int *)t6))
        goto LAB150;

LAB151:    t19 = (t0 + 3384);
    xsi_vlogvar_assign_value(t19, t7, 0, 0, 1);
    goto LAB35;

LAB31:    xsi_set_current_line(53, ng0);
    t3 = (t0 + 2024U);
    t4 = *((char **)t3);
    t3 = (t0 + 2184U);
    t6 = *((char **)t3);
    memset(t7, 0, 8);
    t3 = (t4 + 4);
    if (*((unsigned int *)t3) != 0)
        goto LAB154;

LAB153:    t17 = (t6 + 4);
    if (*((unsigned int *)t17) != 0)
        goto LAB154;

LAB157:    if (*((unsigned int *)t4) < *((unsigned int *)t6))
        goto LAB156;

LAB155:    *((unsigned int *)t7) = 1;

LAB156:    t19 = (t0 + 3384);
    xsi_vlogvar_assign_value(t19, t7, 0, 0, 1);
    goto LAB35;

LAB38:    t27 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t27) = 1;
    goto LAB39;

LAB41:    *((unsigned int *)t7) = 1;
    goto LAB43;

LAB42:    t18 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB43;

LAB46:    t45 = (t48 + 4);
    *((unsigned int *)t48) = 1;
    *((unsigned int *)t45) = 1;
    goto LAB47;

LAB48:    *((unsigned int *)t13) = 1;
    goto LAB51;

LAB50:    t50 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t50) = 1;
    goto LAB51;

LAB52:    t57 = (t0 + 2024U);
    t58 = *((char **)t57);
    t57 = (t0 + 2184U);
    t59 = *((char **)t57);
    memset(t60, 0, 8);
    t57 = (t58 + 4);
    if (*((unsigned int *)t57) != 0)
        goto LAB62;

LAB61:    t61 = (t59 + 4);
    if (*((unsigned int *)t61) != 0)
        goto LAB62;

LAB65:    if (*((unsigned int *)t58) < *((unsigned int *)t59))
        goto LAB63;

LAB64:    memset(t56, 0, 8);
    t63 = (t60 + 4);
    t64 = *((unsigned int *)t63);
    t65 = (~(t64));
    t66 = *((unsigned int *)t60);
    t67 = (t66 & t65);
    t68 = (t67 & 1U);
    if (t68 != 0)
        goto LAB66;

LAB67:    if (*((unsigned int *)t63) != 0)
        goto LAB68;

LAB69:    t70 = (t56 + 4);
    t71 = *((unsigned int *)t56);
    t72 = *((unsigned int *)t70);
    t73 = (t71 || t72);
    if (t73 > 0)
        goto LAB70;

LAB71:    t75 = *((unsigned int *)t56);
    t76 = (~(t75));
    t77 = *((unsigned int *)t70);
    t78 = (t76 || t77);
    if (t78 > 0)
        goto LAB72;

LAB73:    if (*((unsigned int *)t70) > 0)
        goto LAB74;

LAB75:    if (*((unsigned int *)t56) > 0)
        goto LAB76;

LAB77:    memcpy(t55, t79, 8);

LAB78:    goto LAB53;

LAB54:    t86 = (t0 + 2024U);
    t87 = *((char **)t86);
    memset(t88, 0, 8);
    t86 = (t88 + 4);
    t89 = (t87 + 4);
    t90 = *((unsigned int *)t87);
    t91 = (t90 >> 31);
    t92 = (t91 & 1);
    *((unsigned int *)t88) = t92;
    t93 = *((unsigned int *)t89);
    t94 = (t93 >> 31);
    t95 = (t94 & 1);
    *((unsigned int *)t86) = t95;
    t96 = ((char*)((ng3)));
    memset(t97, 0, 8);
    t98 = (t88 + 4);
    t99 = (t96 + 4);
    t100 = *((unsigned int *)t88);
    t101 = *((unsigned int *)t96);
    t102 = (t100 ^ t101);
    t103 = *((unsigned int *)t98);
    t104 = *((unsigned int *)t99);
    t105 = (t103 ^ t104);
    t106 = (t102 | t105);
    t107 = *((unsigned int *)t98);
    t108 = *((unsigned int *)t99);
    t109 = (t107 | t108);
    t110 = (~(t109));
    t111 = (t106 & t110);
    if (t111 != 0)
        goto LAB82;

LAB79:    if (t109 != 0)
        goto LAB81;

LAB80:    *((unsigned int *)t97) = 1;

LAB82:    memset(t85, 0, 8);
    t113 = (t97 + 4);
    t114 = *((unsigned int *)t113);
    t115 = (~(t114));
    t116 = *((unsigned int *)t97);
    t117 = (t116 & t115);
    t118 = (t117 & 1U);
    if (t118 != 0)
        goto LAB83;

LAB84:    if (*((unsigned int *)t113) != 0)
        goto LAB85;

LAB86:    t120 = (t85 + 4);
    t121 = *((unsigned int *)t85);
    t122 = *((unsigned int *)t120);
    t123 = (t121 || t122);
    if (t123 > 0)
        goto LAB87;

LAB88:    t125 = *((unsigned int *)t85);
    t126 = (~(t125));
    t127 = *((unsigned int *)t120);
    t128 = (t126 || t127);
    if (t128 > 0)
        goto LAB89;

LAB90:    if (*((unsigned int *)t120) > 0)
        goto LAB91;

LAB92:    if (*((unsigned int *)t85) > 0)
        goto LAB93;

LAB94:    memcpy(t84, t129, 8);

LAB95:    goto LAB55;

LAB56:    xsi_vlog_unsigned_bit_combine(t7, 1, t55, 1, t84, 1);
    goto LAB60;

LAB58:    memcpy(t7, t55, 8);
    goto LAB60;

LAB62:    t62 = (t60 + 4);
    *((unsigned int *)t60) = 1;
    *((unsigned int *)t62) = 1;
    goto LAB64;

LAB63:    *((unsigned int *)t60) = 1;
    goto LAB64;

LAB66:    *((unsigned int *)t56) = 1;
    goto LAB69;

LAB68:    t69 = (t56 + 4);
    *((unsigned int *)t56) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB69;

LAB70:    t74 = ((char*)((ng3)));
    goto LAB71;

LAB72:    t79 = ((char*)((ng1)));
    goto LAB73;

LAB74:    xsi_vlog_unsigned_bit_combine(t55, 1, t74, 1, t79, 1);
    goto LAB78;

LAB76:    memcpy(t55, t74, 8);
    goto LAB78;

LAB81:    t112 = (t97 + 4);
    *((unsigned int *)t97) = 1;
    *((unsigned int *)t112) = 1;
    goto LAB82;

LAB83:    *((unsigned int *)t85) = 1;
    goto LAB86;

LAB85:    t119 = (t85 + 4);
    *((unsigned int *)t85) = 1;
    *((unsigned int *)t119) = 1;
    goto LAB86;

LAB87:    t124 = ((char*)((ng3)));
    goto LAB88;

LAB89:    t129 = ((char*)((ng1)));
    goto LAB90;

LAB91:    xsi_vlog_unsigned_bit_combine(t84, 1, t124, 1, t129, 1);
    goto LAB95;

LAB93:    memcpy(t84, t124, 8);
    goto LAB95;

LAB98:    t45 = (t48 + 4);
    *((unsigned int *)t48) = 1;
    *((unsigned int *)t45) = 1;
    goto LAB99;

LAB100:    *((unsigned int *)t13) = 1;
    goto LAB103;

LAB102:    t50 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t50) = 1;
    goto LAB103;

LAB104:    t57 = (t0 + 2024U);
    t58 = *((char **)t57);
    t57 = (t0 + 2184U);
    t59 = *((char **)t57);
    memset(t60, 0, 8);
    t57 = (t58 + 4);
    if (*((unsigned int *)t57) != 0)
        goto LAB114;

LAB113:    t61 = (t59 + 4);
    if (*((unsigned int *)t61) != 0)
        goto LAB114;

LAB117:    if (*((unsigned int *)t58) < *((unsigned int *)t59))
        goto LAB116;

LAB115:    *((unsigned int *)t60) = 1;

LAB116:    memset(t56, 0, 8);
    t63 = (t60 + 4);
    t64 = *((unsigned int *)t63);
    t65 = (~(t64));
    t66 = *((unsigned int *)t60);
    t67 = (t66 & t65);
    t68 = (t67 & 1U);
    if (t68 != 0)
        goto LAB118;

LAB119:    if (*((unsigned int *)t63) != 0)
        goto LAB120;

LAB121:    t70 = (t56 + 4);
    t71 = *((unsigned int *)t56);
    t72 = *((unsigned int *)t70);
    t73 = (t71 || t72);
    if (t73 > 0)
        goto LAB122;

LAB123:    t75 = *((unsigned int *)t56);
    t76 = (~(t75));
    t77 = *((unsigned int *)t70);
    t78 = (t76 || t77);
    if (t78 > 0)
        goto LAB124;

LAB125:    if (*((unsigned int *)t70) > 0)
        goto LAB126;

LAB127:    if (*((unsigned int *)t56) > 0)
        goto LAB128;

LAB129:    memcpy(t55, t79, 8);

LAB130:    goto LAB105;

LAB106:    t86 = (t0 + 2024U);
    t87 = *((char **)t86);
    memset(t88, 0, 8);
    t86 = (t88 + 4);
    t89 = (t87 + 4);
    t90 = *((unsigned int *)t87);
    t91 = (t90 >> 31);
    t92 = (t91 & 1);
    *((unsigned int *)t88) = t92;
    t93 = *((unsigned int *)t89);
    t94 = (t93 >> 31);
    t95 = (t94 & 1);
    *((unsigned int *)t86) = t95;
    t96 = ((char*)((ng3)));
    memset(t97, 0, 8);
    t98 = (t88 + 4);
    t99 = (t96 + 4);
    t100 = *((unsigned int *)t88);
    t101 = *((unsigned int *)t96);
    t102 = (t100 ^ t101);
    t103 = *((unsigned int *)t98);
    t104 = *((unsigned int *)t99);
    t105 = (t103 ^ t104);
    t106 = (t102 | t105);
    t107 = *((unsigned int *)t98);
    t108 = *((unsigned int *)t99);
    t109 = (t107 | t108);
    t110 = (~(t109));
    t111 = (t106 & t110);
    if (t111 != 0)
        goto LAB134;

LAB131:    if (t109 != 0)
        goto LAB133;

LAB132:    *((unsigned int *)t97) = 1;

LAB134:    memset(t85, 0, 8);
    t113 = (t97 + 4);
    t114 = *((unsigned int *)t113);
    t115 = (~(t114));
    t116 = *((unsigned int *)t97);
    t117 = (t116 & t115);
    t118 = (t117 & 1U);
    if (t118 != 0)
        goto LAB135;

LAB136:    if (*((unsigned int *)t113) != 0)
        goto LAB137;

LAB138:    t120 = (t85 + 4);
    t121 = *((unsigned int *)t85);
    t122 = *((unsigned int *)t120);
    t123 = (t121 || t122);
    if (t123 > 0)
        goto LAB139;

LAB140:    t125 = *((unsigned int *)t85);
    t126 = (~(t125));
    t127 = *((unsigned int *)t120);
    t128 = (t126 || t127);
    if (t128 > 0)
        goto LAB141;

LAB142:    if (*((unsigned int *)t120) > 0)
        goto LAB143;

LAB144:    if (*((unsigned int *)t85) > 0)
        goto LAB145;

LAB146:    memcpy(t84, t129, 8);

LAB147:    goto LAB107;

LAB108:    xsi_vlog_unsigned_bit_combine(t7, 1, t55, 1, t84, 1);
    goto LAB112;

LAB110:    memcpy(t7, t55, 8);
    goto LAB112;

LAB114:    t62 = (t60 + 4);
    *((unsigned int *)t60) = 1;
    *((unsigned int *)t62) = 1;
    goto LAB116;

LAB118:    *((unsigned int *)t56) = 1;
    goto LAB121;

LAB120:    t69 = (t56 + 4);
    *((unsigned int *)t56) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB121;

LAB122:    t74 = ((char*)((ng3)));
    goto LAB123;

LAB124:    t79 = ((char*)((ng1)));
    goto LAB125;

LAB126:    xsi_vlog_unsigned_bit_combine(t55, 1, t74, 1, t79, 1);
    goto LAB130;

LAB128:    memcpy(t55, t74, 8);
    goto LAB130;

LAB133:    t112 = (t97 + 4);
    *((unsigned int *)t97) = 1;
    *((unsigned int *)t112) = 1;
    goto LAB134;

LAB135:    *((unsigned int *)t85) = 1;
    goto LAB138;

LAB137:    t119 = (t85 + 4);
    *((unsigned int *)t85) = 1;
    *((unsigned int *)t119) = 1;
    goto LAB138;

LAB139:    t124 = ((char*)((ng1)));
    goto LAB140;

LAB141:    t129 = ((char*)((ng3)));
    goto LAB142;

LAB143:    xsi_vlog_unsigned_bit_combine(t84, 1, t124, 1, t129, 1);
    goto LAB147;

LAB145:    memcpy(t84, t124, 8);
    goto LAB147;

LAB149:    t18 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB151;

LAB150:    *((unsigned int *)t7) = 1;
    goto LAB151;

LAB154:    t18 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB156;

}


extern void work_m_16361768895594796090_2467844615_init()
{
	static char *pe[] = {(void *)Always_37_0};
	xsi_register_didat("work_m_16361768895594796090_2467844615", "isim/branch_pc_tb_isim_beh.exe.sim/work/m_16361768895594796090_2467844615.didat");
	xsi_register_executes(pe);
}
