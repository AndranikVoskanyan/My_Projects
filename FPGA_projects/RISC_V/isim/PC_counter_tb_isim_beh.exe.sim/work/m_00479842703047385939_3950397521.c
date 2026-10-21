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
static const char *ng0 = "/home/ise/Desktop/RISC_V/PC_counter_tb.v";
static int ng1[] = {1, 0};
static const char *ng2 = "FAIL %s expected=%h got=%h";
static const char *ng3 = "PASS %s";
static int ng4[] = {0, 0};
static unsigned int ng5[] = {305419896U, 0U};
static unsigned int ng6[] = {0U, 0U};
static int ng7[] = {1702061428, 0, 1970479218, 0, 1919905391, 0, 2037277544, 0, 1634476147, 0, 1852404841, 0, 73, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng8[] = {4096U, 0U};
static int ng9[] = {825241648, 0, 1126183032, 0, 1633951824, 0, 19567, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng10[] = {4100U, 0U};
static int ng11[] = {1931488052, 0, 1685218675, 0, 1814061412, 0, 1853122913, 0, 1701934437, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng12[] = {4104U, 0U};
static int ng13[] = {1734437230, 0, 1936924769, 0, 1684304485, 0, 1634476129, 0, 1701737577, 0, 1399157109, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng14[] = {8192U, 0U};
static int ng15[] = {1931497539, 0, 1752132708, 0, 1634495520, 0, 21364, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng16[] = {12288U, 0U};
static int ng17[] = {1931497539, 0, 1752132708, 0, 1768713248, 0, 1814066036, 0, 1400136044, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng18[] = {1952541804, 0, 1701978227, 0, 543254132, 0, 1937075557, 0, 21093, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng19[] = {256U, 0U};
static int ng20[] = {1919251315, 0, 543253604, 0, 1870095730, 0, 1953439852, 0, 1970106400, 0, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng21[] = {2147483648U, 0U};
static int ng22[] = {1919251315, 0, 543253604, 0, 761424244, 0, 1214867304, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng23[] = {4294967295U, 0U};
static int ng24[] = {1919251315, 0, 543253604, 0, 761424244, 0, 1830826802, 0, 2020175221, 0, 19809, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng25[] = {3U, 0U};
static int ng26[] = {1651078259, 0, 1634892064, 0, 1651078258, 0, 1931501938, 0, 1667592308, 0, 1126195555, 0, 80, 0, 0, 0, 0, 0, 0, 0};
static int ng27[] = {2053468783, 0, 542130976, 0, 1852143732, 0, 1667855392, 0, 2020633705, 0, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng28[] = {16384U, 0U};
static int ng29[] = {1952805748, 0, 1768843040, 0, 544500077, 0, 1885434469, 0, 5272165, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng30[] = {20480U, 0U};
static int ng31[] = {1684108389, 0, 1126200688, 0, 1970479184, 0, 1919905391, 0, 2037277544, 0, 1864393075, 0, 78, 0, 0, 0, 0, 0, 0, 0};
static int ng32[] = {1701078885, 0, 1768843040, 0, 544369011, 0, 1696624494, 0, 1885626740, 0, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng33[] = {3735928559U, 0U};
static int ng34[] = {1852798323, 0, 1667789423, 0, 1634957678, 0, 1852797984, 0, 1936028704, 0, 21093, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng35[] = {1952541804, 0, 1702043763, 0, 1920100708, 0, 544175717, 0, 1702061428, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng36[] = {24576U, 0U};
static int ng37[] = {1702061428, 0, 1701978226, 0, 543254132, 0, 2053468783, 0, 1869374496, 0, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng38[] = {1702061428, 0, 1869422706, 0, 1696622194, 0, 1702065517, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng39[] = {1684108389, 0, 1126200688, 0, 1702043728, 0, 1920100708, 0, 544175717, 0, 1702061428, 0, 82, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng40[] = {4U, 0U};
static int ng41[] = {1702061428, 0, 1852055666, 0, 1936024431, 0, 1952805408, 0, 1696620902, 0, 1885626740, 0, 85, 0, 0, 0, 0, 0, 0, 0};
static const char *ng42 = "--------------------------------------";
static const char *ng43 = "Tests: %0d   Passed: %0d   Failed: %0d";
static const char *ng44 = "PC TEST PASSED";
static const char *ng45 = "PC TEST FAILED";



static int sp_check_pc(char *t1, char *t2)
{
    char t9[8];
    char t21[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t22;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 848);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(25, ng0);

LAB5:    xsi_set_current_line(26, ng0);
    t5 = (t1 + 2952);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = ((char*)((ng1)));
    memset(t9, 0, 8);
    xsi_vlog_signed_add(t9, 32, t7, 32, t8, 32);
    t10 = (t1 + 2952);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 32);
    xsi_set_current_line(27, ng0);
    t4 = (t1 + 1912U);
    t5 = *((char **)t4);
    t4 = (t1 + 3272);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    memset(t9, 0, 8);
    if (*((unsigned int *)t5) != *((unsigned int *)t7))
        goto LAB7;

LAB6:    t8 = (t5 + 4);
    t10 = (t7 + 4);
    if (*((unsigned int *)t8) != *((unsigned int *)t10))
        goto LAB7;

LAB8:    t11 = (t9 + 4);
    t12 = *((unsigned int *)t11);
    t13 = (~(t12));
    t14 = *((unsigned int *)t9);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB9;

LAB10:    xsi_set_current_line(31, ng0);

LAB13:    xsi_set_current_line(32, ng0);
    t4 = (t1 + 3432);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng3, 2, t7, (char)118, t6, 320);

LAB11:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB7:    *((unsigned int *)t9) = 1;
    goto LAB8;

LAB9:    xsi_set_current_line(27, ng0);

LAB12:    xsi_set_current_line(28, ng0);
    t17 = (t1 + 3112);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = ((char*)((ng1)));
    memset(t21, 0, 8);
    xsi_vlog_signed_add(t21, 32, t19, 32, t20, 32);
    t22 = (t1 + 3112);
    xsi_vlogvar_assign_value(t22, t21, 0, 0, 32);
    xsi_set_current_line(29, ng0);
    t4 = (t1 + 3432);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 3272);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    t11 = (t1 + 1912U);
    t17 = *((char **)t11);
    t11 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng2, 4, t11, (char)118, t6, 320, (char)118, t10, 32, (char)118, t17, 32);
    goto LAB11;

}

static int sp_step(char *t1, char *t2)
{
    int t0;
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
    int t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 1280);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(42, ng0);

LAB5:    xsi_set_current_line(43, ng0);
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

LAB6:    xsi_set_current_line(44, ng0);
    t4 = (t1 + 3592);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 2792);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);
    xsi_set_current_line(45, ng0);
    t4 = (t1 + 3912);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 2472);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 1);
    xsi_set_current_line(46, ng0);
    t4 = (t1 + 4072);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 2632);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 1);
    xsi_set_current_line(48, ng0);
    t4 = (t2 + 88U);
    t5 = *((char **)t4);
    t6 = (t5 + 16U);
    xsi_wp_set_status(t6, 1);
    *((char **)t3) = &&LAB7;
    goto LAB1;

LAB7:    xsi_set_current_line(49, ng0);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 1000LL);
    *((char **)t3) = &&LAB8;
    t0 = 1;
    goto LAB1;

LAB8:    xsi_set_current_line(50, ng0);
    t4 = (t1 + 3752);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 4232);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t2 + 56U);
    t11 = *((char **)t10);
    t12 = (t2 + 56U);
    t13 = *((char **)t12);
    xsi_vlog_subprograminvocation_setJumpstate(t2, t13, &&LAB9);
    t14 = (t2 + 56U);
    t15 = *((char **)t14);
    t16 = (t1 + 848);
    t17 = xsi_create_subprogram_invocation(t15, 0, t1, t16, 0, t2);
    xsi_vlog_subprogram_pushinvocation(t16, t17);
    t18 = (t1 + 3272);
    xsi_vlogvar_assign_value(t18, t6, 0, 0, 32);
    t19 = (t1 + 3432);
    xsi_vlogvar_assign_value(t19, t9, 0, 0, 320);

LAB11:    t20 = (t2 + 64U);
    t21 = *((char **)t20);
    t22 = (t21 + 80U);
    t23 = *((char **)t22);
    t24 = (t23 + 272U);
    t25 = *((char **)t24);
    t26 = (t25 + 0U);
    t27 = *((char **)t26);
    t28 = ((int  (*)(char *, char *))t27)(t1, t21);
    if (t28 == -1)
        goto LAB12;

LAB13:    if (t28 != 0)
        goto LAB14;

LAB9:    t21 = (t1 + 848);
    xsi_vlog_subprogram_popinvocation(t21);

LAB10:    t29 = (t2 + 64U);
    t30 = *((char **)t29);
    t29 = (t1 + 848);
    t31 = (t2 + 56U);
    t32 = *((char **)t31);
    xsi_delete_subprogram_invocation(t29, t30, t1, t32, t2);
    goto LAB4;

LAB12:    t0 = -1;
    goto LAB1;

LAB14:    t20 = (t2 + 48U);
    *((char **)t20) = &&LAB11;
    goto LAB1;

}

static void Always_20_0(char *t0)
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

LAB0:    t1 = (t0 + 5144U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(20, ng0);
    t2 = (t0 + 4952);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(20, ng0);
    t4 = (t0 + 2312);
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
    t24 = (t0 + 2312);
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

static void Initial_54_1(char *t0)
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
    int t17;
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
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;

LAB0:    t1 = (t0 + 5392U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(54, ng0);

LAB4:    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2312);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2472);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2632);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(58, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 2792);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2952);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(60, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3112);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(63, ng0);
    t2 = (t0 + 5744);
    *((int *)t2) = 1;
    t3 = (t0 + 5424);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(64, ng0);
    t2 = (t0 + 5200);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng6)));
    t3 = ((char*)((ng7)));
    t4 = (t0 + 5200);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3272);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 32);
    t8 = (t0 + 3432);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 320);

LAB9:    t9 = (t0 + 5296);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB11:    if (t17 != 0)
        goto LAB12;

LAB7:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB8:    t18 = (t0 + 5296);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 5200);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng8)));
    t3 = ((char*)((ng8)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng9)));
    t7 = (t0 + 5200);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 3592);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 32);
    t11 = (t0 + 3752);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 3912);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 4072);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 4232);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 320);

LAB15:    t15 = (t0 + 5296);
    t16 = *((char **)t15);
    t18 = (t16 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t17 = ((int  (*)(char *, char *))t23)(t0, t16);

LAB17:    if (t17 != 0)
        goto LAB18;

LAB13:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB14:    t24 = (t0 + 5296);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 5200);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng10)));
    t3 = ((char*)((ng10)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng11)));
    t7 = (t0 + 5200);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 3592);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 32);
    t11 = (t0 + 3752);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 3912);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 4072);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 4232);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 320);

LAB21:    t15 = (t0 + 5296);
    t16 = *((char **)t15);
    t18 = (t16 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t17 = ((int  (*)(char *, char *))t23)(t0, t16);

LAB23:    if (t17 != 0)
        goto LAB24;

LAB19:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB20:    t24 = (t0 + 5296);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 5200);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng12)));
    t3 = ((char*)((ng12)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng13)));
    t7 = (t0 + 5200);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 3592);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 32);
    t11 = (t0 + 3752);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 3912);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 4072);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 4232);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 320);

LAB27:    t15 = (t0 + 5296);
    t16 = *((char **)t15);
    t18 = (t16 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t17 = ((int  (*)(char *, char *))t23)(t0, t16);

LAB29:    if (t17 != 0)
        goto LAB30;

LAB25:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB26:    t24 = (t0 + 5296);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 5200);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng14)));
    t3 = ((char*)((ng12)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng1)));
    t6 = ((char*)((ng15)));
    t7 = (t0 + 5200);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 3592);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 32);
    t11 = (t0 + 3752);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 3912);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 4072);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 4232);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 320);

LAB33:    t15 = (t0 + 5296);
    t16 = *((char **)t15);
    t18 = (t16 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t17 = ((int  (*)(char *, char *))t23)(t0, t16);

LAB35:    if (t17 != 0)
        goto LAB36;

LAB31:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB32:    t24 = (t0 + 5296);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 5200);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng16)));
    t3 = ((char*)((ng12)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng1)));
    t6 = ((char*)((ng17)));
    t7 = (t0 + 5200);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 3592);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 32);
    t11 = (t0 + 3752);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 3912);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 4072);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 4232);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 320);

LAB39:    t15 = (t0 + 5296);
    t16 = *((char **)t15);
    t18 = (t16 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t17 = ((int  (*)(char *, char *))t23)(t0, t16);

LAB41:    if (t17 != 0)
        goto LAB42;

LAB37:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB38:    t24 = (t0 + 5296);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 5200);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(84, ng0);
    t2 = ((char*)((ng14)));
    t3 = ((char*)((ng14)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng18)));
    t7 = (t0 + 5200);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 3592);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 32);
    t11 = (t0 + 3752);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 3912);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 4072);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 4232);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 320);

LAB45:    t15 = (t0 + 5296);
    t16 = *((char **)t15);
    t18 = (t16 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t17 = ((int  (*)(char *, char *))t23)(t0, t16);

LAB47:    if (t17 != 0)
        goto LAB48;

LAB43:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB44:    t24 = (t0 + 5296);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 5200);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(88, ng0);
    t2 = ((char*)((ng19)));
    t3 = ((char*)((ng19)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng20)));
    t7 = (t0 + 5200);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 3592);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 32);
    t11 = (t0 + 3752);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 3912);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 4072);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 4232);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 320);

LAB51:    t15 = (t0 + 5296);
    t16 = *((char **)t15);
    t18 = (t16 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t17 = ((int  (*)(char *, char *))t23)(t0, t16);

LAB53:    if (t17 != 0)
        goto LAB54;

LAB49:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB50:    t24 = (t0 + 5296);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 5200);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(91, ng0);
    t2 = ((char*)((ng21)));
    t3 = ((char*)((ng21)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng22)));
    t7 = (t0 + 5200);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 3592);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 32);
    t11 = (t0 + 3752);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 3912);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 4072);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 4232);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 320);

LAB57:    t15 = (t0 + 5296);
    t16 = *((char **)t15);
    t18 = (t16 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t17 = ((int  (*)(char *, char *))t23)(t0, t16);

LAB59:    if (t17 != 0)
        goto LAB60;

LAB55:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB56:    t24 = (t0 + 5296);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 5200);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(94, ng0);
    t2 = ((char*)((ng23)));
    t3 = ((char*)((ng23)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng24)));
    t7 = (t0 + 5200);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 3592);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 32);
    t11 = (t0 + 3752);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 3912);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 4072);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 4232);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 320);

LAB63:    t15 = (t0 + 5296);
    t16 = *((char **)t15);
    t18 = (t16 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t17 = ((int  (*)(char *, char *))t23)(t0, t16);

LAB65:    if (t17 != 0)
        goto LAB66;

LAB61:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB62:    t24 = (t0 + 5296);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 5200);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(97, ng0);
    t2 = ((char*)((ng25)));
    t3 = ((char*)((ng25)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng26)));
    t7 = (t0 + 5200);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 3592);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 32);
    t11 = (t0 + 3752);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 3912);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 4072);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 4232);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 320);

LAB69:    t15 = (t0 + 5296);
    t16 = *((char **)t15);
    t18 = (t16 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t17 = ((int  (*)(char *, char *))t23)(t0, t16);

LAB71:    if (t17 != 0)
        goto LAB72;

LAB67:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB68:    t24 = (t0 + 5296);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 5200);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(100, ng0);
    t2 = ((char*)((ng6)));
    t3 = ((char*)((ng6)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng27)));
    t7 = (t0 + 5200);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 3592);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 32);
    t11 = (t0 + 3752);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 3912);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 4072);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 4232);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 320);

LAB75:    t15 = (t0 + 5296);
    t16 = *((char **)t15);
    t18 = (t16 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t17 = ((int  (*)(char *, char *))t23)(t0, t16);

LAB77:    if (t17 != 0)
        goto LAB78;

LAB73:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB74:    t24 = (t0 + 5296);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 5200);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(104, ng0);
    t2 = ((char*)((ng28)));
    t3 = ((char*)((ng28)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng29)));
    t7 = (t0 + 5200);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 3592);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 32);
    t11 = (t0 + 3752);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 3912);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 4072);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 4232);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 320);

LAB81:    t15 = (t0 + 5296);
    t16 = *((char **)t15);
    t18 = (t16 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t17 = ((int  (*)(char *, char *))t23)(t0, t16);

LAB83:    if (t17 != 0)
        goto LAB84;

LAB79:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB80:    t24 = (t0 + 5296);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 5200);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(107, ng0);
    t2 = (t0 + 5760);
    *((int *)t2) = 1;
    t3 = (t0 + 5424);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB85;
    goto LAB1;

LAB10:;
LAB12:    t9 = (t0 + 5392U);
    *((char **)t9) = &&LAB9;
    goto LAB1;

LAB16:;
LAB18:    t15 = (t0 + 5392U);
    *((char **)t15) = &&LAB15;
    goto LAB1;

LAB22:;
LAB24:    t15 = (t0 + 5392U);
    *((char **)t15) = &&LAB21;
    goto LAB1;

LAB28:;
LAB30:    t15 = (t0 + 5392U);
    *((char **)t15) = &&LAB27;
    goto LAB1;

LAB34:;
LAB36:    t15 = (t0 + 5392U);
    *((char **)t15) = &&LAB33;
    goto LAB1;

LAB40:;
LAB42:    t15 = (t0 + 5392U);
    *((char **)t15) = &&LAB39;
    goto LAB1;

LAB46:;
LAB48:    t15 = (t0 + 5392U);
    *((char **)t15) = &&LAB45;
    goto LAB1;

LAB52:;
LAB54:    t15 = (t0 + 5392U);
    *((char **)t15) = &&LAB51;
    goto LAB1;

LAB58:;
LAB60:    t15 = (t0 + 5392U);
    *((char **)t15) = &&LAB57;
    goto LAB1;

LAB64:;
LAB66:    t15 = (t0 + 5392U);
    *((char **)t15) = &&LAB63;
    goto LAB1;

LAB70:;
LAB72:    t15 = (t0 + 5392U);
    *((char **)t15) = &&LAB69;
    goto LAB1;

LAB76:;
LAB78:    t15 = (t0 + 5392U);
    *((char **)t15) = &&LAB75;
    goto LAB1;

LAB82:;
LAB84:    t15 = (t0 + 5392U);
    *((char **)t15) = &&LAB81;
    goto LAB1;

LAB85:    xsi_set_current_line(108, ng0);
    t2 = ((char*)((ng30)));
    t3 = (t0 + 2792);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(109, ng0);
    t2 = (t0 + 5200);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB86;
    goto LAB1;

LAB86:    xsi_set_current_line(110, ng0);
    t2 = ((char*)((ng28)));
    t3 = ((char*)((ng31)));
    t4 = (t0 + 5200);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3272);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 32);
    t8 = (t0 + 3432);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 320);

LAB89:    t9 = (t0 + 5296);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB91:    if (t17 != 0)
        goto LAB92;

LAB87:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB88:    t18 = (t0 + 5296);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 5200);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(113, ng0);
    t2 = (t0 + 5776);
    *((int *)t2) = 1;
    t3 = (t0 + 5424);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB93;
    goto LAB1;

LAB90:;
LAB92:    t9 = (t0 + 5392U);
    *((char **)t9) = &&LAB89;
    goto LAB1;

LAB93:    xsi_set_current_line(114, ng0);
    t2 = (t0 + 5200);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB94;
    goto LAB1;

LAB94:    xsi_set_current_line(115, ng0);
    t2 = ((char*)((ng30)));
    t3 = ((char*)((ng32)));
    t4 = (t0 + 5200);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3272);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 32);
    t8 = (t0 + 3432);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 320);

LAB97:    t9 = (t0 + 5296);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB99:    if (t17 != 0)
        goto LAB100;

LAB95:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB96:    t18 = (t0 + 5296);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 5200);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(119, ng0);
    t2 = (t0 + 5792);
    *((int *)t2) = 1;
    t3 = (t0 + 5424);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB101;
    goto LAB1;

LAB98:;
LAB100:    t9 = (t0 + 5392U);
    *((char **)t9) = &&LAB97;
    goto LAB1;

LAB101:    xsi_set_current_line(120, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2472);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(121, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2632);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(122, ng0);
    t2 = ((char*)((ng33)));
    t3 = (t0 + 2792);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(124, ng0);
    t2 = (t0 + 5200);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB102;
    goto LAB1;

LAB102:    xsi_set_current_line(125, ng0);
    t2 = ((char*)((ng30)));
    t3 = ((char*)((ng34)));
    t4 = (t0 + 5200);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3272);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 32);
    t8 = (t0 + 3432);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 320);

LAB105:    t9 = (t0 + 5296);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB107:    if (t17 != 0)
        goto LAB108;

LAB103:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB104:    t18 = (t0 + 5296);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 5200);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(128, ng0);
    t2 = (t0 + 5808);
    *((int *)t2) = 1;
    t3 = (t0 + 5424);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB109;
    goto LAB1;

LAB106:;
LAB108:    t9 = (t0 + 5392U);
    *((char **)t9) = &&LAB105;
    goto LAB1;

LAB109:    xsi_set_current_line(129, ng0);
    t2 = (t0 + 5200);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB110;
    goto LAB1;

LAB110:    xsi_set_current_line(130, ng0);
    t2 = ((char*)((ng6)));
    t3 = ((char*)((ng35)));
    t4 = (t0 + 5200);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3272);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 32);
    t8 = (t0 + 3432);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 320);

LAB113:    t9 = (t0 + 5296);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB115:    if (t17 != 0)
        goto LAB116;

LAB111:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB112:    t18 = (t0 + 5296);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 5200);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(134, ng0);
    t2 = ((char*)((ng36)));
    t3 = ((char*)((ng6)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng1)));
    t6 = ((char*)((ng37)));
    t7 = (t0 + 5200);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 3592);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 32);
    t11 = (t0 + 3752);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 3912);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 4072);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 4232);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 320);

LAB119:    t15 = (t0 + 5296);
    t16 = *((char **)t15);
    t18 = (t16 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t17 = ((int  (*)(char *, char *))t23)(t0, t16);

LAB121:    if (t17 != 0)
        goto LAB122;

LAB117:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB118:    t24 = (t0 + 5296);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 5200);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(137, ng0);
    t2 = ((char*)((ng36)));
    t3 = ((char*)((ng36)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng38)));
    t7 = (t0 + 5200);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 3592);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 32);
    t11 = (t0 + 3752);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 3912);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 4072);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 4232);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 320);

LAB125:    t15 = (t0 + 5296);
    t16 = *((char **)t15);
    t18 = (t16 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t17 = ((int  (*)(char *, char *))t23)(t0, t16);

LAB127:    if (t17 != 0)
        goto LAB128;

LAB123:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB124:    t24 = (t0 + 5296);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 5200);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(140, ng0);
    t2 = ((char*)((ng23)));
    t3 = ((char*)((ng6)));
    t4 = ((char*)((ng1)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng39)));
    t7 = (t0 + 5200);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 3592);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 32);
    t11 = (t0 + 3752);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 3912);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 4072);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 4232);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 320);

LAB131:    t15 = (t0 + 5296);
    t16 = *((char **)t15);
    t18 = (t16 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t17 = ((int  (*)(char *, char *))t23)(t0, t16);

LAB133:    if (t17 != 0)
        goto LAB134;

LAB129:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB130:    t24 = (t0 + 5296);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 5200);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(143, ng0);
    t2 = ((char*)((ng40)));
    t3 = ((char*)((ng40)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng41)));
    t7 = (t0 + 5200);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 3592);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 32);
    t11 = (t0 + 3752);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 3912);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 1);
    t13 = (t0 + 4072);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 1);
    t14 = (t0 + 4232);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 320);

LAB137:    t15 = (t0 + 5296);
    t16 = *((char **)t15);
    t18 = (t16 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t17 = ((int  (*)(char *, char *))t23)(t0, t16);

LAB139:    if (t17 != 0)
        goto LAB140;

LAB135:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB136:    t24 = (t0 + 5296);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 5200);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(146, ng0);
    xsi_vlogfile_write(1, 0, 0, ng42, 1, t0);
    xsi_set_current_line(147, ng0);
    t2 = (t0 + 2952);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2952);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 3112);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t28, 0, 8);
    xsi_vlog_signed_minus(t28, 32, t7, 32, t10, 32);
    t11 = (t0 + 3112);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    xsi_vlogfile_write(1, 0, 0, ng43, 4, t0, (char)119, t4, 32, (char)119, t28, 32, (char)119, t13, 32);
    xsi_set_current_line(149, ng0);
    xsi_vlogfile_write(1, 0, 0, ng42, 1, t0);
    xsi_set_current_line(151, ng0);
    t2 = (t0 + 3112);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t28, 0, 8);
    xsi_vlog_signed_equal(t28, 32, t4, 32, t5, 32);
    t6 = (t28 + 4);
    t29 = *((unsigned int *)t6);
    t30 = (~(t29));
    t31 = *((unsigned int *)t28);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB141;

LAB142:    xsi_set_current_line(154, ng0);
    xsi_vlogfile_write(1, 0, 0, ng45, 1, t0);

LAB143:    xsi_set_current_line(156, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

LAB114:;
LAB116:    t9 = (t0 + 5392U);
    *((char **)t9) = &&LAB113;
    goto LAB1;

LAB120:;
LAB122:    t15 = (t0 + 5392U);
    *((char **)t15) = &&LAB119;
    goto LAB1;

LAB126:;
LAB128:    t15 = (t0 + 5392U);
    *((char **)t15) = &&LAB125;
    goto LAB1;

LAB132:;
LAB134:    t15 = (t0 + 5392U);
    *((char **)t15) = &&LAB131;
    goto LAB1;

LAB138:;
LAB140:    t15 = (t0 + 5392U);
    *((char **)t15) = &&LAB137;
    goto LAB1;

LAB141:    xsi_set_current_line(152, ng0);
    xsi_vlogfile_write(1, 0, 0, ng44, 1, t0);
    goto LAB143;

}


extern void work_m_00479842703047385939_3950397521_init()
{
	static char *pe[] = {(void *)Always_20_0,(void *)Initial_54_1};
	static char *se[] = {(void *)sp_check_pc,(void *)sp_step};
	xsi_register_didat("work_m_00479842703047385939_3950397521", "isim/PC_counter_tb_isim_beh.exe.sim/work/m_00479842703047385939_3950397521.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
