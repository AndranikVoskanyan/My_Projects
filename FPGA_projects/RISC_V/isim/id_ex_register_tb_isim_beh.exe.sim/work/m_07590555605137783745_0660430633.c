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
static const char *ng0 = "/home/ise/Desktop/RISC_V/id_ex_register_tb.v";
static int ng1[] = {1, 0};
static const char *ng2 = "FAIL before clock: %s";
static unsigned int ng3[] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
static const char *ng4 = "FAIL %s";
static const char *ng5 = " expected=%h";
static const char *ng6 = " actual  =%h";
static const char *ng7 = "PASS %s";
static int ng8[] = {0, 0};
static int ng9[] = {1702061428, 0, 1634476146, 0, 1852404841, 0, 73, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng10[] = {4294967295U, 0U, 4294967295U, 0U, 4294967295U, 0U, 4294967295U, 0U, 4294967295U, 0U, 255U, 0U};
static int ng11[] = {1869505907, 0, 1634495520, 0, 1970431264, 0, 1130459252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng12[] = {1886745715, 0, 544175476, 0, 543255660, 0, 1869374579, 0, 1819025512, 0, 5469281, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng13[] = {2036558949, 0, 1701060707, 0, 1952541804, 0, 1852055667, 0, 1399153519, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng14[] = {1952541804, 0, 1702043763, 0, 1920100708, 0, 544175717, 0, 1819636584, 0, 70, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng15[] = {1819636584, 0, 1701978214, 0, 543254132, 0, 1953854053, 0, 4415856, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng16[] = {1952541804, 0, 1702043763, 0, 1920100708, 0, 544175717, 0, 1702061428, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng17[] = {1819636584, 0, 1702043750, 0, 1920100708, 0, 544175717, 0, 1702061428, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng18[] = {1701998451, 0, 1819025530, 0, 1919230049, 0, 1634759797, 0, 67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng19[] = {1701016691, 0, 543516262, 0, 1936286821, 0, 1952805664, 0, 1696622433, 0, 1969381996, 0, 1768169570, 0, 1853251948, 0, 73, 0, 0, 0};
static unsigned int ng20[] = {4294967295U, 0U, 4294967295U, 0U, 4294967295U, 0U, 4294967295U, 0U, 4294967295U, 0U, 127U, 0U};
static int ng21[] = {1650617445, 0, 1914724981, 0, 1634104421, 0, 1818846240, 0, 22113, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng22[] = {1953066862, 0, 2019910517, 0, 1852252261, 0, 1685418601, 0, 1970497568, 0, 18028, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng23[] = {167, 0};
static unsigned int ng24[] = {1U, 0U};
static int ng25[] = {543320436, 0, 1852863860, 0, 1852252265, 0, 1634495337, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng26[] = {1702061428, 0, 1634476146, 0, 4614510, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static const char *ng27 = "--------------------------------------";
static const char *ng28 = "Tests: %0d Passed: %0d Failed: %0d";
static const char *ng29 = "ID/EX PIPELINE REGISTER TEST PASSED";
static const char *ng30 = "ID/EX PIPELINE REGISTER TEST FAILED";



static int sp_step(char *t1, char *t2)
{
    char t8[48];
    char t19[8];
    char t25[8];
    char t32[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;
    char *t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    char *t46;
    char *t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    char *t67;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 848);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(97, ng0);

LAB5:    xsi_set_current_line(98, ng0);
    t5 = (t2 + 88U);
    t6 = *((char **)t5);
    t7 = (t6 + 0U);
    xsi_wp_set_status(t7, 1);
    *((char **)t3) = &&LAB6;

LAB1:    return t0;
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;
    goto LAB1;

LAB6:    xsi_set_current_line(100, ng0);
    t4 = (t1 + 10840);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 9240);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 1);
    xsi_set_current_line(101, ng0);
    t4 = (t1 + 11000);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 9560);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 1);
    xsi_set_current_line(102, ng0);
    t4 = (t1 + 11160);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 9400);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 1);
    xsi_set_current_line(103, ng0);
    t4 = (t1 + 11320);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 9720);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 168);
    xsi_set_current_line(106, ng0);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 1000LL);
    *((char **)t3) = &&LAB7;
    t0 = 1;
    goto LAB1;

LAB7:    xsi_set_current_line(107, ng0);
    t4 = (t1 + 8520U);
    t5 = *((char **)t4);
    t4 = (t1 + 9880);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    xsi_vlog_unsigned_case_noteq(t8, 168, t5, 168, t7, 168);
    t9 = (t8 + 4);
    t10 = *((unsigned int *)t9);
    t11 = (~(t10));
    t12 = *((unsigned int *)t8);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB8;

LAB9:
LAB10:    xsi_set_current_line(113, ng0);
    t4 = (t1 + 9240);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t19, 0, 8);
    t7 = (t6 + 4);
    t10 = *((unsigned int *)t7);
    t11 = (~(t10));
    t12 = *((unsigned int *)t6);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t7) != 0)
        goto LAB14;

LAB15:    t15 = (t19 + 4);
    t21 = *((unsigned int *)t19);
    t22 = (!(t21));
    t23 = *((unsigned int *)t15);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB16;

LAB17:    memcpy(t32, t19, 8);

LAB18:    t60 = (t32 + 4);
    t61 = *((unsigned int *)t60);
    t62 = (~(t61));
    t63 = *((unsigned int *)t32);
    t64 = (t63 & t62);
    t65 = (t64 != 0);
    if (t65 > 0)
        goto LAB26;

LAB27:    xsi_set_current_line(115, ng0);
    t4 = (t1 + 9400);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t19, 0, 8);
    t7 = (t6 + 4);
    t10 = *((unsigned int *)t7);
    t11 = (~(t10));
    t12 = *((unsigned int *)t6);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB32;

LAB30:    if (*((unsigned int *)t7) == 0)
        goto LAB29;

LAB31:    t9 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t9) = 1;

LAB32:    t15 = (t19 + 4);
    t21 = *((unsigned int *)t15);
    t22 = (~(t21));
    t23 = *((unsigned int *)t19);
    t24 = (t23 & t22);
    t26 = (t24 != 0);
    if (t26 > 0)
        goto LAB33;

LAB34:
LAB35:
LAB28:    xsi_set_current_line(118, ng0);
    t4 = (t2 + 88U);
    t5 = *((char **)t4);
    t6 = (t5 + 16U);
    xsi_wp_set_status(t6, 1);
    *((char **)t3) = &&LAB36;
    goto LAB1;

LAB8:    xsi_set_current_line(107, ng0);

LAB11:    xsi_set_current_line(108, ng0);
    t15 = (t1 + 10200);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = ((char*)((ng1)));
    memset(t19, 0, 8);
    xsi_vlog_signed_add(t19, 32, t17, 32, t18, 32);
    t20 = (t1 + 10200);
    xsi_vlogvar_assign_value(t20, t19, 0, 0, 32);
    xsi_set_current_line(109, ng0);
    t4 = (t1 + 10680);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng2, 2, t7, (char)118, t6, 320);
    goto LAB10;

LAB12:    *((unsigned int *)t19) = 1;
    goto LAB15;

LAB14:    t9 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB15;

LAB16:    t16 = (t1 + 9560);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memset(t25, 0, 8);
    t20 = (t18 + 4);
    t26 = *((unsigned int *)t20);
    t27 = (~(t26));
    t28 = *((unsigned int *)t18);
    t29 = (t28 & t27);
    t30 = (t29 & 1U);
    if (t30 != 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t20) != 0)
        goto LAB21;

LAB22:    t33 = *((unsigned int *)t19);
    t34 = *((unsigned int *)t25);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = (t19 + 4);
    t37 = (t25 + 4);
    t38 = (t32 + 4);
    t39 = *((unsigned int *)t36);
    t40 = *((unsigned int *)t37);
    t41 = (t39 | t40);
    *((unsigned int *)t38) = t41;
    t42 = *((unsigned int *)t38);
    t43 = (t42 != 0);
    if (t43 == 1)
        goto LAB23;

LAB24:
LAB25:    goto LAB18;

LAB19:    *((unsigned int *)t25) = 1;
    goto LAB22;

LAB21:    t31 = (t25 + 4);
    *((unsigned int *)t25) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB22;

LAB23:    t44 = *((unsigned int *)t32);
    t45 = *((unsigned int *)t38);
    *((unsigned int *)t32) = (t44 | t45);
    t46 = (t19 + 4);
    t47 = (t25 + 4);
    t48 = *((unsigned int *)t46);
    t49 = (~(t48));
    t50 = *((unsigned int *)t19);
    t51 = (t50 & t49);
    t52 = *((unsigned int *)t47);
    t53 = (~(t52));
    t54 = *((unsigned int *)t25);
    t55 = (t54 & t53);
    t56 = (~(t51));
    t57 = (~(t55));
    t58 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t58 & t56);
    t59 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t59 & t57);
    goto LAB25;

LAB26:    xsi_set_current_line(114, ng0);
    t66 = ((char*)((ng3)));
    t67 = (t1 + 9880);
    xsi_vlogvar_assign_value(t67, t66, 0, 0, 168);
    goto LAB28;

LAB29:    *((unsigned int *)t19) = 1;
    goto LAB32;

LAB33:    xsi_set_current_line(116, ng0);
    t16 = (t1 + 8680U);
    t17 = *((char **)t16);
    t16 = (t1 + 9880);
    xsi_vlogvar_assign_value(t16, t17, 0, 0, 168);
    goto LAB35;

LAB36:    xsi_set_current_line(119, ng0);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 1000LL);
    *((char **)t3) = &&LAB37;
    t0 = 1;
    goto LAB1;

LAB37:    xsi_set_current_line(121, ng0);
    t4 = (t1 + 10040);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    memset(t19, 0, 8);
    xsi_vlog_signed_add(t19, 32, t6, 32, t7, 32);
    t9 = (t1 + 10040);
    xsi_vlogvar_assign_value(t9, t19, 0, 0, 32);
    xsi_set_current_line(123, ng0);
    t4 = (t1 + 8520U);
    t5 = *((char **)t4);
    t4 = (t1 + 9880);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    xsi_vlog_unsigned_case_noteq(t8, 168, t5, 168, t7, 168);
    t9 = (t8 + 4);
    t10 = *((unsigned int *)t9);
    t11 = (~(t10));
    t12 = *((unsigned int *)t8);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB38;

LAB39:    xsi_set_current_line(130, ng0);
    t4 = (t1 + 10680);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng7, 2, t7, (char)118, t6, 320);

LAB40:    goto LAB4;

LAB38:    xsi_set_current_line(123, ng0);

LAB41:    xsi_set_current_line(124, ng0);
    t15 = (t1 + 10200);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = ((char*)((ng1)));
    memset(t19, 0, 8);
    xsi_vlog_signed_add(t19, 32, t17, 32, t18, 32);
    t20 = (t1 + 10200);
    xsi_vlogvar_assign_value(t20, t19, 0, 0, 32);
    xsi_set_current_line(125, ng0);
    t4 = (t1 + 10680);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng4, 2, t7, (char)118, t6, 320);
    xsi_set_current_line(126, ng0);
    t4 = (t1 + 9880);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng5, 2, t7, (char)118, t6, 168);
    xsi_set_current_line(127, ng0);
    t4 = (t1 + 8520U);
    t5 = *((char **)t4);
    t4 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng6, 2, t4, (char)118, t5, 168);
    goto LAB40;

}

static void Cont_31_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    char *t54;
    char *t55;
    char *t56;
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    char *t61;
    char *t62;
    char *t63;
    char *t64;
    char *t65;
    char *t66;
    char *t67;
    char *t68;
    char *t69;
    char *t70;
    char *t71;
    char *t72;
    char *t73;
    char *t74;
    char *t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    char *t87;
    char *t88;
    char *t89;
    char *t90;
    char *t91;
    char *t92;
    char *t93;
    char *t94;
    char *t95;
    char *t96;
    char *t97;
    char *t98;
    char *t99;
    char *t100;
    char *t101;
    char *t102;
    char *t103;
    char *t104;
    char *t105;
    char *t106;
    char *t107;
    char *t108;
    char *t109;
    char *t110;
    char *t111;
    char *t112;
    char *t113;
    char *t114;
    char *t115;

LAB0:    t1 = (t0 + 12232U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(31, ng0);
    t2 = (t0 + 9720);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 15032);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    xsi_vlog_bit_copy(t9, 0, t4, 0, 1);
    xsi_driver_vfirst_trans(t5, 0, 0);
    t10 = (t0 + 14968);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    xsi_vlog_bit_copy(t14, 0, t4, 1, 1);
    xsi_driver_vfirst_trans(t10, 0, 0);
    t15 = (t0 + 14904);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    xsi_vlog_bit_copy(t19, 0, t4, 2, 1);
    xsi_driver_vfirst_trans(t15, 0, 0);
    t20 = (t0 + 14840);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    xsi_vlog_bit_copy(t24, 0, t4, 3, 1);
    xsi_driver_vfirst_trans(t20, 0, 0);
    t25 = (t0 + 14776);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    xsi_vlog_bit_copy(t29, 0, t4, 4, 1);
    xsi_driver_vfirst_trans(t25, 0, 0);
    t30 = (t0 + 14712);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    xsi_vlog_bit_copy(t34, 0, t4, 5, 3);
    xsi_driver_vfirst_trans(t30, 0, 2);
    t35 = (t0 + 14648);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    xsi_vlog_bit_copy(t39, 0, t4, 8, 1);
    xsi_driver_vfirst_trans(t35, 0, 0);
    t40 = (t0 + 14584);
    t41 = (t40 + 56U);
    t42 = *((char **)t41);
    t43 = (t42 + 56U);
    t44 = *((char **)t43);
    xsi_vlog_bit_copy(t44, 0, t4, 9, 4);
    xsi_driver_vfirst_trans(t40, 0, 3);
    t45 = (t0 + 14520);
    t46 = (t45 + 56U);
    t47 = *((char **)t46);
    t48 = (t47 + 56U);
    t49 = *((char **)t48);
    xsi_vlog_bit_copy(t49, 0, t4, 13, 1);
    xsi_driver_vfirst_trans(t45, 0, 0);
    t50 = (t0 + 14456);
    t51 = (t50 + 56U);
    t52 = *((char **)t51);
    t53 = (t52 + 56U);
    t54 = *((char **)t53);
    xsi_vlog_bit_copy(t54, 0, t4, 14, 2);
    xsi_driver_vfirst_trans(t50, 0, 1);
    t55 = (t0 + 14392);
    t56 = (t55 + 56U);
    t57 = *((char **)t56);
    t58 = (t57 + 56U);
    t59 = *((char **)t58);
    xsi_vlog_bit_copy(t59, 0, t4, 16, 1);
    xsi_driver_vfirst_trans(t55, 0, 0);
    t60 = (t0 + 14328);
    t61 = (t60 + 56U);
    t62 = *((char **)t61);
    t63 = (t62 + 56U);
    t64 = *((char **)t63);
    xsi_vlog_bit_copy(t64, 0, t4, 17, 1);
    xsi_driver_vfirst_trans(t60, 0, 0);
    t65 = (t0 + 14264);
    t66 = (t65 + 56U);
    t67 = *((char **)t66);
    t68 = (t67 + 56U);
    t69 = *((char **)t68);
    xsi_vlog_bit_copy(t69, 0, t4, 18, 2);
    xsi_driver_vfirst_trans(t65, 0, 1);
    t70 = (t0 + 14200);
    t71 = (t70 + 56U);
    t72 = *((char **)t71);
    t73 = (t72 + 56U);
    t74 = *((char **)t73);
    xsi_vlog_bit_copy(t74, 0, t4, 20, 4);
    xsi_driver_vfirst_trans(t70, 0, 3);
    t75 = (t0 + 14136);
    t76 = (t75 + 56U);
    t77 = *((char **)t76);
    t78 = (t77 + 56U);
    t79 = *((char **)t78);
    xsi_vlog_bit_copy(t79, 0, t4, 24, 5);
    xsi_driver_vfirst_trans(t75, 0, 4);
    t80 = (t0 + 14072);
    t81 = (t80 + 56U);
    t82 = *((char **)t81);
    t83 = (t82 + 56U);
    t84 = *((char **)t83);
    xsi_vlog_bit_copy(t84, 0, t4, 29, 5);
    xsi_driver_vfirst_trans(t80, 0, 4);
    t85 = (t0 + 14008);
    t86 = (t85 + 56U);
    t87 = *((char **)t86);
    t88 = (t87 + 56U);
    t89 = *((char **)t88);
    xsi_vlog_bit_copy(t89, 0, t4, 34, 5);
    xsi_driver_vfirst_trans(t85, 0, 4);
    t90 = (t0 + 13944);
    t91 = (t90 + 56U);
    t92 = *((char **)t91);
    t93 = (t92 + 56U);
    t94 = *((char **)t93);
    xsi_vlog_bit_copy(t94, 0, t4, 39, 32);
    xsi_driver_vfirst_trans(t90, 0, 31);
    t95 = (t0 + 13880);
    t96 = (t95 + 56U);
    t97 = *((char **)t96);
    t98 = (t97 + 56U);
    t99 = *((char **)t98);
    xsi_vlog_bit_copy(t99, 0, t4, 71, 32);
    xsi_driver_vfirst_trans(t95, 0, 31);
    t100 = (t0 + 13816);
    t101 = (t100 + 56U);
    t102 = *((char **)t101);
    t103 = (t102 + 56U);
    t104 = *((char **)t103);
    xsi_vlog_bit_copy(t104, 0, t4, 103, 32);
    xsi_driver_vfirst_trans(t100, 0, 31);
    t105 = (t0 + 13752);
    t106 = (t105 + 56U);
    t107 = *((char **)t106);
    t108 = (t107 + 56U);
    t109 = *((char **)t108);
    xsi_vlog_bit_copy(t109, 0, t4, 135, 32);
    xsi_driver_vfirst_trans(t105, 0, 31);
    t110 = (t0 + 13688);
    t111 = (t110 + 56U);
    t112 = *((char **)t111);
    t113 = (t112 + 56U);
    t114 = *((char **)t113);
    xsi_vlog_bit_copy(t114, 0, t4, 167, 1);
    xsi_driver_vfirst_trans(t110, 0, 0);
    t115 = (t0 + 13544);
    *((int *)t115) = 1;

LAB1:    return;
}

static void NetDecl_40_1(char *t0)
{
    char t3[48];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;

LAB0:    t1 = (t0 + 12480U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 8360U);
    t4 = *((char **)t2);
    t2 = (t0 + 8200U);
    t5 = *((char **)t2);
    t2 = (t0 + 8040U);
    t6 = *((char **)t2);
    t2 = (t0 + 7880U);
    t7 = *((char **)t2);
    t2 = (t0 + 7720U);
    t8 = *((char **)t2);
    t2 = (t0 + 7560U);
    t9 = *((char **)t2);
    t2 = (t0 + 7400U);
    t10 = *((char **)t2);
    t2 = (t0 + 6440U);
    t11 = *((char **)t2);
    t2 = (t0 + 7240U);
    t12 = *((char **)t2);
    t2 = (t0 + 6760U);
    t13 = *((char **)t2);
    t2 = (t0 + 7080U);
    t14 = *((char **)t2);
    t2 = (t0 + 6920U);
    t15 = *((char **)t2);
    t2 = (t0 + 6600U);
    t16 = *((char **)t2);
    t2 = (t0 + 6280U);
    t17 = *((char **)t2);
    t2 = (t0 + 6120U);
    t18 = *((char **)t2);
    t2 = (t0 + 5960U);
    t19 = *((char **)t2);
    t2 = (t0 + 5800U);
    t20 = *((char **)t2);
    t2 = (t0 + 5640U);
    t21 = *((char **)t2);
    t2 = (t0 + 5480U);
    t22 = *((char **)t2);
    t2 = (t0 + 5320U);
    t23 = *((char **)t2);
    t2 = (t0 + 5160U);
    t24 = *((char **)t2);
    t2 = (t0 + 5000U);
    t25 = *((char **)t2);
    xsi_vlogtype_concat(t3, 168, 168, 22U, t25, 1, t24, 32, t23, 32, t22, 32, t21, 32, t20, 5, t19, 5, t18, 5, t17, 4, t16, 2, t15, 1, t14, 1, t13, 2, t12, 1, t11, 4, t10, 1, t9, 3, t8, 1, t7, 1, t6, 1, t5, 1, t4, 1);
    t2 = (t0 + 15096);
    t26 = (t2 + 56U);
    t27 = *((char **)t26);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    xsi_vlog_bit_copy(t29, 0, t3, 0, 168);
    xsi_driver_vfirst_trans(t2, 0, 167U);
    t30 = (t0 + 13560);
    *((int *)t30) = 1;

LAB1:    return;
}

static void NetDecl_50_2(char *t0)
{
    char t3[48];
    char t6[8];
    char t40[8];
    char t74[8];
    char t108[8];
    char t142[8];
    char t177[8];
    char t212[8];
    char t247[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    int t29;
    int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    char *t38;
    char *t39;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    char *t53;
    char *t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    int t63;
    int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    char *t71;
    char *t72;
    char *t73;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    char *t78;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    char *t87;
    char *t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    int t97;
    int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    char *t105;
    char *t106;
    char *t107;
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
    unsigned int t119;
    unsigned int t120;
    char *t121;
    char *t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    int t131;
    int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    char *t139;
    char *t140;
    char *t141;
    unsigned int t143;
    unsigned int t144;
    unsigned int t145;
    char *t146;
    char *t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    unsigned int t154;
    char *t155;
    char *t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    unsigned int t164;
    int t165;
    int t166;
    unsigned int t167;
    unsigned int t168;
    unsigned int t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    char *t173;
    char *t174;
    char *t175;
    char *t176;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    char *t181;
    char *t182;
    unsigned int t183;
    unsigned int t184;
    unsigned int t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    unsigned int t189;
    char *t190;
    char *t191;
    unsigned int t192;
    unsigned int t193;
    unsigned int t194;
    unsigned int t195;
    unsigned int t196;
    unsigned int t197;
    unsigned int t198;
    unsigned int t199;
    int t200;
    int t201;
    unsigned int t202;
    unsigned int t203;
    unsigned int t204;
    unsigned int t205;
    unsigned int t206;
    unsigned int t207;
    char *t208;
    char *t209;
    char *t210;
    char *t211;
    unsigned int t213;
    unsigned int t214;
    unsigned int t215;
    char *t216;
    char *t217;
    unsigned int t218;
    unsigned int t219;
    unsigned int t220;
    unsigned int t221;
    unsigned int t222;
    unsigned int t223;
    unsigned int t224;
    char *t225;
    char *t226;
    unsigned int t227;
    unsigned int t228;
    unsigned int t229;
    unsigned int t230;
    unsigned int t231;
    unsigned int t232;
    unsigned int t233;
    unsigned int t234;
    int t235;
    int t236;
    unsigned int t237;
    unsigned int t238;
    unsigned int t239;
    unsigned int t240;
    unsigned int t241;
    unsigned int t242;
    char *t243;
    char *t244;
    char *t245;
    char *t246;
    unsigned int t248;
    unsigned int t249;
    unsigned int t250;
    char *t251;
    char *t252;
    unsigned int t253;
    unsigned int t254;
    unsigned int t255;
    unsigned int t256;
    unsigned int t257;
    unsigned int t258;
    unsigned int t259;
    char *t260;
    char *t261;
    unsigned int t262;
    unsigned int t263;
    unsigned int t264;
    unsigned int t265;
    unsigned int t266;
    unsigned int t267;
    unsigned int t268;
    unsigned int t269;
    int t270;
    int t271;
    unsigned int t272;
    unsigned int t273;
    unsigned int t274;
    unsigned int t275;
    unsigned int t276;
    unsigned int t277;
    char *t278;
    char *t279;
    char *t280;
    char *t281;
    char *t282;
    char *t283;
    char *t284;
    char *t285;
    char *t286;
    char *t287;
    char *t288;
    char *t289;
    char *t290;
    char *t291;
    char *t292;
    char *t293;
    char *t294;

LAB0:    t1 = (t0 + 12728U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(50, ng0);
    t2 = (t0 + 1480U);
    t4 = *((char **)t2);
    t2 = (t0 + 4840U);
    t5 = *((char **)t2);
    t7 = *((unsigned int *)t4);
    t8 = *((unsigned int *)t5);
    t9 = (t7 & t8);
    *((unsigned int *)t6) = t9;
    t2 = (t4 + 4);
    t10 = (t5 + 4);
    t11 = (t6 + 4);
    t12 = *((unsigned int *)t2);
    t13 = *((unsigned int *)t10);
    t14 = (t12 | t13);
    *((unsigned int *)t11) = t14;
    t15 = *((unsigned int *)t11);
    t16 = (t15 != 0);
    if (t16 == 1)
        goto LAB4;

LAB5:
LAB6:    t37 = (t0 + 1480U);
    t38 = *((char **)t37);
    t37 = (t0 + 4680U);
    t39 = *((char **)t37);
    t41 = *((unsigned int *)t38);
    t42 = *((unsigned int *)t39);
    t43 = (t41 & t42);
    *((unsigned int *)t40) = t43;
    t37 = (t38 + 4);
    t44 = (t39 + 4);
    t45 = (t40 + 4);
    t46 = *((unsigned int *)t37);
    t47 = *((unsigned int *)t44);
    t48 = (t46 | t47);
    *((unsigned int *)t45) = t48;
    t49 = *((unsigned int *)t45);
    t50 = (t49 != 0);
    if (t50 == 1)
        goto LAB7;

LAB8:
LAB9:    t71 = (t0 + 1480U);
    t72 = *((char **)t71);
    t71 = (t0 + 4520U);
    t73 = *((char **)t71);
    t75 = *((unsigned int *)t72);
    t76 = *((unsigned int *)t73);
    t77 = (t75 & t76);
    *((unsigned int *)t74) = t77;
    t71 = (t72 + 4);
    t78 = (t73 + 4);
    t79 = (t74 + 4);
    t80 = *((unsigned int *)t71);
    t81 = *((unsigned int *)t78);
    t82 = (t80 | t81);
    *((unsigned int *)t79) = t82;
    t83 = *((unsigned int *)t79);
    t84 = (t83 != 0);
    if (t84 == 1)
        goto LAB10;

LAB11:
LAB12:    t105 = (t0 + 1480U);
    t106 = *((char **)t105);
    t105 = (t0 + 4360U);
    t107 = *((char **)t105);
    t109 = *((unsigned int *)t106);
    t110 = *((unsigned int *)t107);
    t111 = (t109 & t110);
    *((unsigned int *)t108) = t111;
    t105 = (t106 + 4);
    t112 = (t107 + 4);
    t113 = (t108 + 4);
    t114 = *((unsigned int *)t105);
    t115 = *((unsigned int *)t112);
    t116 = (t114 | t115);
    *((unsigned int *)t113) = t116;
    t117 = *((unsigned int *)t113);
    t118 = (t117 != 0);
    if (t118 == 1)
        goto LAB13;

LAB14:
LAB15:    t139 = (t0 + 1480U);
    t140 = *((char **)t139);
    t139 = (t0 + 4200U);
    t141 = *((char **)t139);
    t143 = *((unsigned int *)t140);
    t144 = *((unsigned int *)t141);
    t145 = (t143 & t144);
    *((unsigned int *)t142) = t145;
    t139 = (t140 + 4);
    t146 = (t141 + 4);
    t147 = (t142 + 4);
    t148 = *((unsigned int *)t139);
    t149 = *((unsigned int *)t146);
    t150 = (t148 | t149);
    *((unsigned int *)t147) = t150;
    t151 = *((unsigned int *)t147);
    t152 = (t151 != 0);
    if (t152 == 1)
        goto LAB16;

LAB17:
LAB18:    t173 = (t0 + 4040U);
    t174 = *((char **)t173);
    t173 = (t0 + 1480U);
    t175 = *((char **)t173);
    t173 = (t0 + 3880U);
    t176 = *((char **)t173);
    t178 = *((unsigned int *)t175);
    t179 = *((unsigned int *)t176);
    t180 = (t178 & t179);
    *((unsigned int *)t177) = t180;
    t173 = (t175 + 4);
    t181 = (t176 + 4);
    t182 = (t177 + 4);
    t183 = *((unsigned int *)t173);
    t184 = *((unsigned int *)t181);
    t185 = (t183 | t184);
    *((unsigned int *)t182) = t185;
    t186 = *((unsigned int *)t182);
    t187 = (t186 != 0);
    if (t187 == 1)
        goto LAB19;

LAB20:
LAB21:    t208 = (t0 + 2920U);
    t209 = *((char **)t208);
    t208 = (t0 + 1480U);
    t210 = *((char **)t208);
    t208 = (t0 + 3720U);
    t211 = *((char **)t208);
    t213 = *((unsigned int *)t210);
    t214 = *((unsigned int *)t211);
    t215 = (t213 & t214);
    *((unsigned int *)t212) = t215;
    t208 = (t210 + 4);
    t216 = (t211 + 4);
    t217 = (t212 + 4);
    t218 = *((unsigned int *)t208);
    t219 = *((unsigned int *)t216);
    t220 = (t218 | t219);
    *((unsigned int *)t217) = t220;
    t221 = *((unsigned int *)t217);
    t222 = (t221 != 0);
    if (t222 == 1)
        goto LAB22;

LAB23:
LAB24:    t243 = (t0 + 3240U);
    t244 = *((char **)t243);
    t243 = (t0 + 1480U);
    t245 = *((char **)t243);
    t243 = (t0 + 3560U);
    t246 = *((char **)t243);
    t248 = *((unsigned int *)t245);
    t249 = *((unsigned int *)t246);
    t250 = (t248 & t249);
    *((unsigned int *)t247) = t250;
    t243 = (t245 + 4);
    t251 = (t246 + 4);
    t252 = (t247 + 4);
    t253 = *((unsigned int *)t243);
    t254 = *((unsigned int *)t251);
    t255 = (t253 | t254);
    *((unsigned int *)t252) = t255;
    t256 = *((unsigned int *)t252);
    t257 = (t256 != 0);
    if (t257 == 1)
        goto LAB25;

LAB26:
LAB27:    t278 = (t0 + 3400U);
    t279 = *((char **)t278);
    t278 = (t0 + 3080U);
    t280 = *((char **)t278);
    t278 = (t0 + 2760U);
    t281 = *((char **)t278);
    t278 = (t0 + 2600U);
    t282 = *((char **)t278);
    t278 = (t0 + 2440U);
    t283 = *((char **)t278);
    t278 = (t0 + 2280U);
    t284 = *((char **)t278);
    t278 = (t0 + 2120U);
    t285 = *((char **)t278);
    t278 = (t0 + 1960U);
    t286 = *((char **)t278);
    t278 = (t0 + 1800U);
    t287 = *((char **)t278);
    t278 = (t0 + 1640U);
    t288 = *((char **)t278);
    t278 = (t0 + 1480U);
    t289 = *((char **)t278);
    xsi_vlogtype_concat(t3, 168, 168, 22U, t289, 1, t288, 32, t287, 32, t286, 32, t285, 32, t284, 5, t283, 5, t282, 5, t281, 4, t280, 2, t279, 1, t247, 1, t244, 2, t212, 1, t209, 4, t177, 1, t174, 3, t142, 1, t108, 1, t74, 1, t40, 1, t6, 1);
    t278 = (t0 + 15160);
    t290 = (t278 + 56U);
    t291 = *((char **)t290);
    t292 = (t291 + 56U);
    t293 = *((char **)t292);
    xsi_vlog_bit_copy(t293, 0, t3, 0, 168);
    xsi_driver_vfirst_trans(t278, 0, 167U);
    t294 = (t0 + 13576);
    *((int *)t294) = 1;

LAB1:    return;
LAB4:    t17 = *((unsigned int *)t6);
    t18 = *((unsigned int *)t11);
    *((unsigned int *)t6) = (t17 | t18);
    t19 = (t4 + 4);
    t20 = (t5 + 4);
    t21 = *((unsigned int *)t4);
    t22 = (~(t21));
    t23 = *((unsigned int *)t19);
    t24 = (~(t23));
    t25 = *((unsigned int *)t5);
    t26 = (~(t25));
    t27 = *((unsigned int *)t20);
    t28 = (~(t27));
    t29 = (t22 & t24);
    t30 = (t26 & t28);
    t31 = (~(t29));
    t32 = (~(t30));
    t33 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t33 & t31);
    t34 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t34 & t32);
    t35 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t35 & t31);
    t36 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t36 & t32);
    goto LAB6;

LAB7:    t51 = *((unsigned int *)t40);
    t52 = *((unsigned int *)t45);
    *((unsigned int *)t40) = (t51 | t52);
    t53 = (t38 + 4);
    t54 = (t39 + 4);
    t55 = *((unsigned int *)t38);
    t56 = (~(t55));
    t57 = *((unsigned int *)t53);
    t58 = (~(t57));
    t59 = *((unsigned int *)t39);
    t60 = (~(t59));
    t61 = *((unsigned int *)t54);
    t62 = (~(t61));
    t63 = (t56 & t58);
    t64 = (t60 & t62);
    t65 = (~(t63));
    t66 = (~(t64));
    t67 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t67 & t65);
    t68 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t68 & t66);
    t69 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t69 & t65);
    t70 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t70 & t66);
    goto LAB9;

LAB10:    t85 = *((unsigned int *)t74);
    t86 = *((unsigned int *)t79);
    *((unsigned int *)t74) = (t85 | t86);
    t87 = (t72 + 4);
    t88 = (t73 + 4);
    t89 = *((unsigned int *)t72);
    t90 = (~(t89));
    t91 = *((unsigned int *)t87);
    t92 = (~(t91));
    t93 = *((unsigned int *)t73);
    t94 = (~(t93));
    t95 = *((unsigned int *)t88);
    t96 = (~(t95));
    t97 = (t90 & t92);
    t98 = (t94 & t96);
    t99 = (~(t97));
    t100 = (~(t98));
    t101 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t101 & t99);
    t102 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t102 & t100);
    t103 = *((unsigned int *)t74);
    *((unsigned int *)t74) = (t103 & t99);
    t104 = *((unsigned int *)t74);
    *((unsigned int *)t74) = (t104 & t100);
    goto LAB12;

LAB13:    t119 = *((unsigned int *)t108);
    t120 = *((unsigned int *)t113);
    *((unsigned int *)t108) = (t119 | t120);
    t121 = (t106 + 4);
    t122 = (t107 + 4);
    t123 = *((unsigned int *)t106);
    t124 = (~(t123));
    t125 = *((unsigned int *)t121);
    t126 = (~(t125));
    t127 = *((unsigned int *)t107);
    t128 = (~(t127));
    t129 = *((unsigned int *)t122);
    t130 = (~(t129));
    t131 = (t124 & t126);
    t132 = (t128 & t130);
    t133 = (~(t131));
    t134 = (~(t132));
    t135 = *((unsigned int *)t113);
    *((unsigned int *)t113) = (t135 & t133);
    t136 = *((unsigned int *)t113);
    *((unsigned int *)t113) = (t136 & t134);
    t137 = *((unsigned int *)t108);
    *((unsigned int *)t108) = (t137 & t133);
    t138 = *((unsigned int *)t108);
    *((unsigned int *)t108) = (t138 & t134);
    goto LAB15;

LAB16:    t153 = *((unsigned int *)t142);
    t154 = *((unsigned int *)t147);
    *((unsigned int *)t142) = (t153 | t154);
    t155 = (t140 + 4);
    t156 = (t141 + 4);
    t157 = *((unsigned int *)t140);
    t158 = (~(t157));
    t159 = *((unsigned int *)t155);
    t160 = (~(t159));
    t161 = *((unsigned int *)t141);
    t162 = (~(t161));
    t163 = *((unsigned int *)t156);
    t164 = (~(t163));
    t165 = (t158 & t160);
    t166 = (t162 & t164);
    t167 = (~(t165));
    t168 = (~(t166));
    t169 = *((unsigned int *)t147);
    *((unsigned int *)t147) = (t169 & t167);
    t170 = *((unsigned int *)t147);
    *((unsigned int *)t147) = (t170 & t168);
    t171 = *((unsigned int *)t142);
    *((unsigned int *)t142) = (t171 & t167);
    t172 = *((unsigned int *)t142);
    *((unsigned int *)t142) = (t172 & t168);
    goto LAB18;

LAB19:    t188 = *((unsigned int *)t177);
    t189 = *((unsigned int *)t182);
    *((unsigned int *)t177) = (t188 | t189);
    t190 = (t175 + 4);
    t191 = (t176 + 4);
    t192 = *((unsigned int *)t175);
    t193 = (~(t192));
    t194 = *((unsigned int *)t190);
    t195 = (~(t194));
    t196 = *((unsigned int *)t176);
    t197 = (~(t196));
    t198 = *((unsigned int *)t191);
    t199 = (~(t198));
    t200 = (t193 & t195);
    t201 = (t197 & t199);
    t202 = (~(t200));
    t203 = (~(t201));
    t204 = *((unsigned int *)t182);
    *((unsigned int *)t182) = (t204 & t202);
    t205 = *((unsigned int *)t182);
    *((unsigned int *)t182) = (t205 & t203);
    t206 = *((unsigned int *)t177);
    *((unsigned int *)t177) = (t206 & t202);
    t207 = *((unsigned int *)t177);
    *((unsigned int *)t177) = (t207 & t203);
    goto LAB21;

LAB22:    t223 = *((unsigned int *)t212);
    t224 = *((unsigned int *)t217);
    *((unsigned int *)t212) = (t223 | t224);
    t225 = (t210 + 4);
    t226 = (t211 + 4);
    t227 = *((unsigned int *)t210);
    t228 = (~(t227));
    t229 = *((unsigned int *)t225);
    t230 = (~(t229));
    t231 = *((unsigned int *)t211);
    t232 = (~(t231));
    t233 = *((unsigned int *)t226);
    t234 = (~(t233));
    t235 = (t228 & t230);
    t236 = (t232 & t234);
    t237 = (~(t235));
    t238 = (~(t236));
    t239 = *((unsigned int *)t217);
    *((unsigned int *)t217) = (t239 & t237);
    t240 = *((unsigned int *)t217);
    *((unsigned int *)t217) = (t240 & t238);
    t241 = *((unsigned int *)t212);
    *((unsigned int *)t212) = (t241 & t237);
    t242 = *((unsigned int *)t212);
    *((unsigned int *)t212) = (t242 & t238);
    goto LAB24;

LAB25:    t258 = *((unsigned int *)t247);
    t259 = *((unsigned int *)t252);
    *((unsigned int *)t247) = (t258 | t259);
    t260 = (t245 + 4);
    t261 = (t246 + 4);
    t262 = *((unsigned int *)t245);
    t263 = (~(t262));
    t264 = *((unsigned int *)t260);
    t265 = (~(t264));
    t266 = *((unsigned int *)t246);
    t267 = (~(t266));
    t268 = *((unsigned int *)t261);
    t269 = (~(t268));
    t270 = (t263 & t265);
    t271 = (t267 & t269);
    t272 = (~(t270));
    t273 = (~(t271));
    t274 = *((unsigned int *)t252);
    *((unsigned int *)t252) = (t274 & t272);
    t275 = *((unsigned int *)t252);
    *((unsigned int *)t252) = (t275 & t273);
    t276 = *((unsigned int *)t247);
    *((unsigned int *)t247) = (t276 & t272);
    t277 = *((unsigned int *)t247);
    *((unsigned int *)t247) = (t277 & t273);
    goto LAB27;

}

static void Always_90_3(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 12976U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(90, ng0);
    t2 = (t0 + 12784);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(90, ng0);
    t4 = (t0 + 9080);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB8;

LAB6:    if (*((unsigned int *)t7) == 0)
        goto LAB5;

LAB7:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB8:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB10;

LAB9:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 9080);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB2;

LAB5:    *((unsigned int *)t3) = 1;
    goto LAB8;

LAB10:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB9;

}

static void Initial_134_4(char *t0)
{
    char t28[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    int t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    char *t35;

LAB0:    t1 = (t0 + 13224U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(134, ng0);

LAB4:    xsi_set_current_line(135, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 9080);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(136, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 9240);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(137, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 9400);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(138, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 9560);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(139, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 9720);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 168);
    xsi_set_current_line(140, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 9880);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 168);
    xsi_set_current_line(141, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 10040);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(142, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 10200);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(145, ng0);
    t2 = ((char*)((ng9)));
    t3 = ((char*)((ng1)));
    t4 = ((char*)((ng8)));
    t5 = ((char*)((ng8)));
    t6 = ((char*)((ng10)));
    t7 = (t0 + 13032);
    t8 = (t0 + 848);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 10680);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 320);
    t11 = (t0 + 10840);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 1);
    t12 = (t0 + 11000);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 11160);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 11320);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 168);

LAB7:    t15 = (t0 + 13128);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB9:    if (t23 != 0)
        goto LAB10;

LAB5:    t16 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t16);

LAB6:    t24 = (t0 + 13128);
    t25 = *((char **)t24);
    t24 = (t0 + 848);
    t26 = (t0 + 13032);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(146, ng0);
    t2 = ((char*)((ng11)));
    t3 = ((char*)((ng8)));
    t4 = ((char*)((ng8)));
    t5 = ((char*)((ng8)));
    t6 = ((char*)((ng10)));
    t7 = (t0 + 13032);
    t8 = (t0 + 848);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 10680);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 320);
    t11 = (t0 + 10840);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 1);
    t12 = (t0 + 11000);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 11160);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 11320);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 168);

LAB13:    t15 = (t0 + 13128);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB15:    if (t23 != 0)
        goto LAB16;

LAB11:    t16 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t16);

LAB12:    t24 = (t0 + 13128);
    t25 = *((char **)t24);
    t24 = (t0 + 848);
    t26 = (t0 + 13032);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(147, ng0);
    t2 = ((char*)((ng12)));
    t3 = ((char*)((ng8)));
    t4 = ((char*)((ng8)));
    t5 = ((char*)((ng1)));
    t6 = ((char*)((ng3)));
    t7 = (t0 + 13032);
    t8 = (t0 + 848);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 10680);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 320);
    t11 = (t0 + 10840);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 1);
    t12 = (t0 + 11000);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 11160);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 11320);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 168);

LAB19:    t15 = (t0 + 13128);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB21:    if (t23 != 0)
        goto LAB22;

LAB17:    t16 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t16);

LAB18:    t24 = (t0 + 13128);
    t25 = *((char **)t24);
    t24 = (t0 + 848);
    t26 = (t0 + 13032);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(148, ng0);
    t2 = ((char*)((ng13)));
    t3 = ((char*)((ng8)));
    t4 = ((char*)((ng8)));
    t5 = ((char*)((ng1)));
    t6 = ((char*)((ng10)));
    t7 = (t0 + 13032);
    t8 = (t0 + 848);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 10680);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 320);
    t11 = (t0 + 10840);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 1);
    t12 = (t0 + 11000);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 11160);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 11320);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 168);

LAB25:    t15 = (t0 + 13128);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB27:    if (t23 != 0)
        goto LAB28;

LAB23:    t16 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t16);

LAB24:    t24 = (t0 + 13128);
    t25 = *((char **)t24);
    t24 = (t0 + 848);
    t26 = (t0 + 13032);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(149, ng0);
    t2 = ((char*)((ng14)));
    t3 = ((char*)((ng8)));
    t4 = ((char*)((ng1)));
    t5 = ((char*)((ng1)));
    t6 = ((char*)((ng10)));
    t7 = (t0 + 13032);
    t8 = (t0 + 848);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 10680);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 320);
    t11 = (t0 + 10840);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 1);
    t12 = (t0 + 11000);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 11160);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 11320);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 168);

LAB31:    t15 = (t0 + 13128);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB33:    if (t23 != 0)
        goto LAB34;

LAB29:    t16 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t16);

LAB30:    t24 = (t0 + 13128);
    t25 = *((char **)t24);
    t24 = (t0 + 848);
    t26 = (t0 + 13032);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(150, ng0);
    t2 = ((char*)((ng15)));
    t3 = ((char*)((ng8)));
    t4 = ((char*)((ng8)));
    t5 = ((char*)((ng8)));
    t6 = ((char*)((ng10)));
    t7 = (t0 + 13032);
    t8 = (t0 + 848);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 10680);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 320);
    t11 = (t0 + 10840);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 1);
    t12 = (t0 + 11000);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 11160);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 11320);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 168);

LAB37:    t15 = (t0 + 13128);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB39:    if (t23 != 0)
        goto LAB40;

LAB35:    t16 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t16);

LAB36:    t24 = (t0 + 13128);
    t25 = *((char **)t24);
    t24 = (t0 + 848);
    t26 = (t0 + 13032);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(151, ng0);
    t2 = ((char*)((ng16)));
    t3 = ((char*)((ng1)));
    t4 = ((char*)((ng8)));
    t5 = ((char*)((ng1)));
    t6 = ((char*)((ng10)));
    t7 = (t0 + 13032);
    t8 = (t0 + 848);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 10680);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 320);
    t11 = (t0 + 10840);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 1);
    t12 = (t0 + 11000);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 11160);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 11320);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 168);

LAB43:    t15 = (t0 + 13128);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB45:    if (t23 != 0)
        goto LAB46;

LAB41:    t16 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t16);

LAB42:    t24 = (t0 + 13128);
    t25 = *((char **)t24);
    t24 = (t0 + 848);
    t26 = (t0 + 13032);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(152, ng0);
    t2 = ((char*)((ng17)));
    t3 = ((char*)((ng1)));
    t4 = ((char*)((ng1)));
    t5 = ((char*)((ng8)));
    t6 = ((char*)((ng10)));
    t7 = (t0 + 13032);
    t8 = (t0 + 848);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 10680);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 320);
    t11 = (t0 + 10840);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 1);
    t12 = (t0 + 11000);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 11160);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 11320);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 168);

LAB49:    t15 = (t0 + 13128);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB51:    if (t23 != 0)
        goto LAB52;

LAB47:    t16 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t16);

LAB48:    t24 = (t0 + 13128);
    t25 = *((char **)t24);
    t24 = (t0 + 848);
    t26 = (t0 + 13032);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(153, ng0);
    t2 = ((char*)((ng18)));
    t3 = ((char*)((ng8)));
    t4 = ((char*)((ng8)));
    t5 = ((char*)((ng8)));
    t6 = ((char*)((ng3)));
    t7 = (t0 + 13032);
    t8 = (t0 + 848);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 10680);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 320);
    t11 = (t0 + 10840);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 1);
    t12 = (t0 + 11000);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 11160);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 11320);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 168);

LAB55:    t15 = (t0 + 13128);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB57:    if (t23 != 0)
        goto LAB58;

LAB53:    t16 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t16);

LAB54:    t24 = (t0 + 13128);
    t25 = *((char **)t24);
    t24 = (t0 + 848);
    t26 = (t0 + 13032);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(156, ng0);
    t2 = ((char*)((ng19)));
    t3 = ((char*)((ng8)));
    t4 = ((char*)((ng8)));
    t5 = ((char*)((ng8)));
    t6 = ((char*)((ng20)));
    t7 = (t0 + 13032);
    t8 = (t0 + 848);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 10680);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 320);
    t11 = (t0 + 10840);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 1);
    t12 = (t0 + 11000);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 11160);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 11320);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 168);

LAB61:    t15 = (t0 + 13128);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB63:    if (t23 != 0)
        goto LAB64;

LAB59:    t16 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t16);

LAB60:    t24 = (t0 + 13128);
    t25 = *((char **)t24);
    t24 = (t0 + 848);
    t26 = (t0 + 13032);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(159, ng0);
    t2 = ((char*)((ng21)));
    t3 = ((char*)((ng8)));
    t4 = ((char*)((ng8)));
    t5 = ((char*)((ng8)));
    t6 = ((char*)((ng10)));
    t7 = (t0 + 13032);
    t8 = (t0 + 848);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 10680);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 320);
    t11 = (t0 + 10840);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 1);
    t12 = (t0 + 11000);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 11160);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 11320);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 168);

LAB67:    t15 = (t0 + 13128);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB69:    if (t23 != 0)
        goto LAB70;

LAB65:    t16 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t16);

LAB66:    t24 = (t0 + 13128);
    t25 = *((char **)t24);
    t24 = (t0 + 848);
    t26 = (t0 + 13032);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(160, ng0);
    t2 = ((char*)((ng22)));
    t3 = ((char*)((ng8)));
    t4 = ((char*)((ng1)));
    t5 = ((char*)((ng8)));
    t6 = ((char*)((ng10)));
    t7 = (t0 + 13032);
    t8 = (t0 + 848);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 10680);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 320);
    t11 = (t0 + 10840);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 1);
    t12 = (t0 + 11000);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 11160);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 11320);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 168);

LAB73:    t15 = (t0 + 13128);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB75:    if (t23 != 0)
        goto LAB76;

LAB71:    t16 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t16);

LAB72:    t24 = (t0 + 13128);
    t25 = *((char **)t24);
    t24 = (t0 + 848);
    t26 = (t0 + 13032);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(164, ng0);
    xsi_set_current_line(164, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 10360);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB77:    t2 = (t0 + 10360);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng23)));
    memset(t28, 0, 8);
    xsi_vlog_signed_less(t28, 32, t4, 32, t5, 32);
    t6 = (t28 + 4);
    t29 = *((unsigned int *)t6);
    t30 = (~(t29));
    t31 = *((unsigned int *)t28);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB78;

LAB79:    xsi_set_current_line(172, ng0);
    t2 = ((char*)((ng26)));
    t3 = ((char*)((ng1)));
    t4 = ((char*)((ng8)));
    t5 = ((char*)((ng8)));
    t6 = ((char*)((ng3)));
    t7 = (t0 + 13032);
    t8 = (t0 + 848);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 10680);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 320);
    t11 = (t0 + 10840);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 1);
    t12 = (t0 + 11000);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 11160);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 11320);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 168);

LAB93:    t15 = (t0 + 13128);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB95:    if (t23 != 0)
        goto LAB96;

LAB91:    t16 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t16);

LAB92:    t24 = (t0 + 13128);
    t25 = *((char **)t24);
    t24 = (t0 + 848);
    t26 = (t0 + 13032);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(174, ng0);
    xsi_vlogfile_write(1, 0, 0, ng27, 1, t0);
    xsi_set_current_line(175, ng0);
    t2 = (t0 + 10040);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 10040);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 10200);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t28, 0, 8);
    xsi_vlog_signed_minus(t28, 32, t7, 32, t10, 32);
    t11 = (t0 + 10200);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    xsi_vlogfile_write(1, 0, 0, ng28, 4, t0, (char)119, t4, 32, (char)119, t28, 32, (char)119, t13, 32);
    xsi_set_current_line(177, ng0);
    xsi_vlogfile_write(1, 0, 0, ng27, 1, t0);
    xsi_set_current_line(179, ng0);
    t2 = (t0 + 10200);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng8)));
    memset(t28, 0, 8);
    xsi_vlog_signed_equal(t28, 32, t4, 32, t5, 32);
    t6 = (t28 + 4);
    t29 = *((unsigned int *)t6);
    t30 = (~(t29));
    t31 = *((unsigned int *)t28);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB97;

LAB98:    xsi_set_current_line(182, ng0);
    xsi_vlogfile_write(1, 0, 0, ng30, 1, t0);

LAB99:    xsi_set_current_line(184, ng0);
    xsi_vlog_finish(1);

LAB1:    return;
LAB8:;
LAB10:    t15 = (t0 + 13224U);
    *((char **)t15) = &&LAB7;
    goto LAB1;

LAB14:;
LAB16:    t15 = (t0 + 13224U);
    *((char **)t15) = &&LAB13;
    goto LAB1;

LAB20:;
LAB22:    t15 = (t0 + 13224U);
    *((char **)t15) = &&LAB19;
    goto LAB1;

LAB26:;
LAB28:    t15 = (t0 + 13224U);
    *((char **)t15) = &&LAB25;
    goto LAB1;

LAB32:;
LAB34:    t15 = (t0 + 13224U);
    *((char **)t15) = &&LAB31;
    goto LAB1;

LAB38:;
LAB40:    t15 = (t0 + 13224U);
    *((char **)t15) = &&LAB37;
    goto LAB1;

LAB44:;
LAB46:    t15 = (t0 + 13224U);
    *((char **)t15) = &&LAB43;
    goto LAB1;

LAB50:;
LAB52:    t15 = (t0 + 13224U);
    *((char **)t15) = &&LAB49;
    goto LAB1;

LAB56:;
LAB58:    t15 = (t0 + 13224U);
    *((char **)t15) = &&LAB55;
    goto LAB1;

LAB62:;
LAB64:    t15 = (t0 + 13224U);
    *((char **)t15) = &&LAB61;
    goto LAB1;

LAB68:;
LAB70:    t15 = (t0 + 13224U);
    *((char **)t15) = &&LAB67;
    goto LAB1;

LAB74:;
LAB76:    t15 = (t0 + 13224U);
    *((char **)t15) = &&LAB73;
    goto LAB1;

LAB78:    xsi_set_current_line(164, ng0);

LAB80:    xsi_set_current_line(165, ng0);
    t7 = ((char*)((ng3)));
    t8 = (t0 + 10520);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 168);
    xsi_set_current_line(166, ng0);
    t2 = ((char*)((ng24)));
    t3 = (t0 + 10520);
    t4 = (t0 + 10520);
    t5 = (t4 + 72U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng23)));
    xsi_vlog_generic_convert_bit_index(t28, t6, 2, t7, 32, 1);
    t8 = (t28 + 4);
    t29 = *((unsigned int *)t8);
    t23 = (!(t29));
    if (t23 == 1)
        goto LAB81;

LAB82:    xsi_set_current_line(167, ng0);
    t2 = ((char*)((ng24)));
    t3 = (t0 + 10520);
    t4 = (t0 + 10520);
    t5 = (t4 + 72U);
    t6 = *((char **)t5);
    t7 = (t0 + 10360);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    xsi_vlog_generic_convert_bit_index(t28, t6, 2, t9, 32, 1);
    t10 = (t28 + 4);
    t29 = *((unsigned int *)t10);
    t23 = (!(t29));
    if (t23 == 1)
        goto LAB83;

LAB84:    xsi_set_current_line(169, ng0);
    t2 = ((char*)((ng25)));
    t3 = ((char*)((ng8)));
    t4 = ((char*)((ng8)));
    t5 = ((char*)((ng8)));
    t6 = (t0 + 10520);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t0 + 13032);
    t10 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t9, 0, t0, t10, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t10, t11);
    t12 = (t0 + 10680);
    xsi_vlogvar_assign_value(t12, t2, 0, 0, 320);
    t13 = (t0 + 10840);
    xsi_vlogvar_assign_value(t13, t3, 0, 0, 1);
    t14 = (t0 + 11000);
    xsi_vlogvar_assign_value(t14, t4, 0, 0, 1);
    t15 = (t0 + 11160);
    xsi_vlogvar_assign_value(t15, t5, 0, 0, 1);
    t16 = (t0 + 11320);
    xsi_vlogvar_assign_value(t16, t8, 0, 0, 168);

LAB87:    t17 = (t0 + 13128);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t24 = (t22 + 0U);
    t25 = *((char **)t24);
    t23 = ((int  (*)(char *, char *))t25)(t0, t18);

LAB89:    if (t23 != 0)
        goto LAB90;

LAB85:    t18 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t18);

LAB86:    t26 = (t0 + 13128);
    t27 = *((char **)t26);
    t26 = (t0 + 848);
    t34 = (t0 + 13032);
    t35 = 0;
    xsi_delete_subprogram_invocation(t26, t27, t0, t34, t35);
    xsi_set_current_line(164, ng0);
    t2 = (t0 + 10360);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t28, 0, 8);
    xsi_vlog_signed_add(t28, 32, t4, 32, t5, 32);
    t6 = (t0 + 10360);
    xsi_vlogvar_assign_value(t6, t28, 0, 0, 32);
    goto LAB77;

LAB81:    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t28), 1);
    goto LAB82;

LAB83:    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t28), 1);
    goto LAB84;

LAB88:;
LAB90:    t17 = (t0 + 13224U);
    *((char **)t17) = &&LAB87;
    goto LAB1;

LAB94:;
LAB96:    t15 = (t0 + 13224U);
    *((char **)t15) = &&LAB93;
    goto LAB1;

LAB97:    xsi_set_current_line(180, ng0);
    xsi_vlogfile_write(1, 0, 0, ng29, 1, t0);
    goto LAB99;

}


extern void work_m_07590555605137783745_0660430633_init()
{
	static char *pe[] = {(void *)Cont_31_0,(void *)NetDecl_40_1,(void *)NetDecl_50_2,(void *)Always_90_3,(void *)Initial_134_4};
	static char *se[] = {(void *)sp_step};
	xsi_register_didat("work_m_07590555605137783745_0660430633", "isim/id_ex_register_tb_isim_beh.exe.sim/work/m_07590555605137783745_0660430633.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
