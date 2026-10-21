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
static const char *ng0 = "/home/ise/Desktop/RISC_V/register_file_tb.v";
static unsigned int ng1[] = {0U, 0U};
static int ng2[] = {1, 0};
static const char *ng3 = "FAIL %s";
static const char *ng4 = "  rs1 x%0d expected=%h actual=%h";
static const char *ng5 = "  rs2 x%0d expected=%h actual=%h";
static const char *ng6 = "PASS %s";
static int ng7[] = {0, 0};
static int ng8[] = {2053468783, 0, 1633973024, 0, 807432805, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng9[] = {286331153U, 0U};
static int ng10[] = {1696626737, 0, 1467115892, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng11[] = {2, 0};
static unsigned int ng12[] = {572662306U, 0U};
static int ng13[] = {1869771891, 0, 1633951856, 0, 1864397413, 0, 21623, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng14[] = {31, 0};
static unsigned int ng15[] = {4275878552U, 0U};
static int ng16[] = {544748337, 0, 1937007986, 0, 1382377321, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng17[] = {4294967295U, 0U};
static int ng18[] = {1869768036, 0, 543778670, 0, 1919513701, 0, 2016419959, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng19[] = {1431655765U, 0U};
static int ng20[] = {1651271012, 0, 1684632417, 0, 1651270944, 0, 543518305, 0, 1919513701, 0, 87, 0, 0, 0, 0, 0};
static unsigned int ng21[] = {3735928559U, 0U};
static int ng22[] = {1696626738, 0, 2003986804, 0, 1333159282, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng23[] = {1919246692, 0, 1952805408, 0, 1701276019, 0, 1835347314, 0, 1931506529, 0, 1852141429, 0, 1970041953, 0, 5466477, 0};
static int ng24[] = {1919246692, 0, 1851878432, 0, 1635019119, 0, 1835166062, 0, 17263, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng25[] = {305419896U, 0U};
static int ng26[] = {1701078885, 0, 1768843040, 0, 544369011, 0, 1718579813, 0, 16997, 0, 0, 0, 0, 0, 0, 0};
static int ng27[] = {1701078885, 0, 1768843040, 0, 544369011, 0, 1718904178, 0, 65, 0, 0, 0, 0, 0, 0, 0};
static int ng28[] = {3, 0};
static int ng29[] = {30, 0};
static unsigned int ng30[] = {2768240640U, 0U};
static int ng31[] = {1919246692, 0, 1769235759, 0, 1914730354, 0, 1769174117, 0, 5399911, 0, 0, 0, 0, 0, 0, 0};
static int ng32[] = {1920361828, 0, 1919251301, 0, 1702043760, 0, 1986096245, 0, 1952805408, 0, 1701276019, 0, 82, 0, 0, 0};
static int ng33[] = {1700881523, 0, 1853104242, 0, 1701733477, 0, 1852073328, 0, 73, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng34[] = {2768240670U, 0U};
static int ng35[] = {2053468783, 0, 1768846112, 0, 1919249761, 0, 7876640, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static const char *ng36 = "--------------------------------------";
static const char *ng37 = "Tests: %0d Passed: %0d Failed: %0d";
static const char *ng38 = "REGISTER FILE TEST PASSED";
static const char *ng39 = "REGISTER FILE TEST FAILED";



static int sp_write_reg(char *t1, char *t2)
{
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 848);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(31, ng0);

LAB5:    xsi_set_current_line(32, ng0);
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

LAB6:    xsi_set_current_line(33, ng0);
    t4 = (t1 + 3912);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 3112);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 5);
    xsi_set_current_line(34, ng0);
    t4 = (t1 + 4072);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 3272);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);
    xsi_set_current_line(35, ng0);
    t4 = (t1 + 4232);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 2632);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 1);
    xsi_set_current_line(36, ng0);
    t4 = (t2 + 88U);
    t5 = *((char **)t4);
    t6 = (t5 + 16U);
    xsi_wp_set_status(t6, 1);
    *((char **)t3) = &&LAB7;
    goto LAB1;

LAB7:    xsi_set_current_line(37, ng0);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 1000LL);
    *((char **)t3) = &&LAB8;
    t0 = 1;
    goto LAB1;

LAB8:    xsi_set_current_line(38, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t1 + 2632);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    goto LAB4;

}

static int sp_check(char *t1, char *t2)
{
    char t9[8];
    char t11[8];
    char t28[8];
    char t31[8];
    char t39[8];
    char t77[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t29;
    char *t30;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
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
    int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    char *t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    char *t74;
    char *t75;
    char *t76;
    char *t78;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 1280);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(46, ng0);

LAB5:    xsi_set_current_line(47, ng0);
    t5 = (t1 + 4392);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t1 + 2792);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 5);
    xsi_set_current_line(48, ng0);
    t4 = (t1 + 4552);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 2952);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 5);
    xsi_set_current_line(49, ng0);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 1000LL);
    *((char **)t3) = &&LAB6;
    t0 = 1;

LAB1:    return t0;
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;
    goto LAB1;

LAB6:    xsi_set_current_line(50, ng0);
    t4 = (t1 + 3432);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng2)));
    memset(t9, 0, 8);
    xsi_vlog_signed_add(t9, 32, t6, 32, t7, 32);
    t8 = (t1 + 3432);
    xsi_vlogvar_assign_value(t8, t9, 0, 0, 32);
    xsi_set_current_line(52, ng0);
    t4 = (t1 + 1912U);
    t5 = *((char **)t4);
    t4 = (t1 + 4712);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    memset(t9, 0, 8);
    if (*((unsigned int *)t5) != *((unsigned int *)t7))
        goto LAB8;

LAB7:    t8 = (t5 + 4);
    t10 = (t7 + 4);
    if (*((unsigned int *)t8) != *((unsigned int *)t10))
        goto LAB8;

LAB9:    memset(t11, 0, 8);
    t12 = (t9 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t9);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) != 0)
        goto LAB12;

LAB13:    t19 = (t11 + 4);
    t20 = *((unsigned int *)t11);
    t21 = (!(t20));
    t22 = *((unsigned int *)t19);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB14;

LAB15:    memcpy(t39, t11, 8);

LAB16:    t67 = (t39 + 4);
    t68 = *((unsigned int *)t67);
    t69 = (~(t68));
    t70 = *((unsigned int *)t39);
    t71 = (t70 & t69);
    t72 = (t71 != 0);
    if (t72 > 0)
        goto LAB27;

LAB28:    xsi_set_current_line(61, ng0);
    t4 = (t1 + 5032);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 1280);
    xsi_vlogfile_write(1, 0, 0, ng6, 2, t7, (char)118, t6, 256);

LAB29:    goto LAB4;

LAB8:    *((unsigned int *)t9) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t11) = 1;
    goto LAB13;

LAB12:    t18 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB13;

LAB14:    t24 = (t1 + 2072U);
    t25 = *((char **)t24);
    t24 = (t1 + 4872);
    t26 = (t24 + 56U);
    t27 = *((char **)t26);
    memset(t28, 0, 8);
    if (*((unsigned int *)t25) != *((unsigned int *)t27))
        goto LAB18;

LAB17:    t29 = (t25 + 4);
    t30 = (t27 + 4);
    if (*((unsigned int *)t29) != *((unsigned int *)t30))
        goto LAB18;

LAB19:    memset(t31, 0, 8);
    t32 = (t28 + 4);
    t33 = *((unsigned int *)t32);
    t34 = (~(t33));
    t35 = *((unsigned int *)t28);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB20;

LAB21:    if (*((unsigned int *)t32) != 0)
        goto LAB22;

LAB23:    t40 = *((unsigned int *)t11);
    t41 = *((unsigned int *)t31);
    t42 = (t40 | t41);
    *((unsigned int *)t39) = t42;
    t43 = (t11 + 4);
    t44 = (t31 + 4);
    t45 = (t39 + 4);
    t46 = *((unsigned int *)t43);
    t47 = *((unsigned int *)t44);
    t48 = (t46 | t47);
    *((unsigned int *)t45) = t48;
    t49 = *((unsigned int *)t45);
    t50 = (t49 != 0);
    if (t50 == 1)
        goto LAB24;

LAB25:
LAB26:    goto LAB16;

LAB18:    *((unsigned int *)t28) = 1;
    goto LAB19;

LAB20:    *((unsigned int *)t31) = 1;
    goto LAB23;

LAB22:    t38 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB23;

LAB24:    t51 = *((unsigned int *)t39);
    t52 = *((unsigned int *)t45);
    *((unsigned int *)t39) = (t51 | t52);
    t53 = (t11 + 4);
    t54 = (t31 + 4);
    t55 = *((unsigned int *)t53);
    t56 = (~(t55));
    t57 = *((unsigned int *)t11);
    t58 = (t57 & t56);
    t59 = *((unsigned int *)t54);
    t60 = (~(t59));
    t61 = *((unsigned int *)t31);
    t62 = (t61 & t60);
    t63 = (~(t58));
    t64 = (~(t62));
    t65 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t65 & t63);
    t66 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t66 & t64);
    goto LAB26;

LAB27:    xsi_set_current_line(53, ng0);

LAB30:    xsi_set_current_line(54, ng0);
    t73 = (t1 + 3592);
    t74 = (t73 + 56U);
    t75 = *((char **)t74);
    t76 = ((char*)((ng2)));
    memset(t77, 0, 8);
    xsi_vlog_signed_add(t77, 32, t75, 32, t76, 32);
    t78 = (t1 + 3592);
    xsi_vlogvar_assign_value(t78, t77, 0, 0, 32);
    xsi_set_current_line(55, ng0);
    t4 = (t1 + 5032);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 1280);
    xsi_vlogfile_write(1, 0, 0, ng3, 2, t7, (char)118, t6, 256);
    xsi_set_current_line(56, ng0);
    t4 = (t1 + 4392);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 4712);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    t12 = (t1 + 1912U);
    t18 = *((char **)t12);
    t12 = (t1 + 1280);
    xsi_vlogfile_write(1, 0, 0, ng4, 4, t12, (char)118, t6, 5, (char)118, t10, 32, (char)118, t18, 32);
    xsi_set_current_line(58, ng0);
    t4 = (t1 + 4552);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 4872);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    t12 = (t1 + 2072U);
    t18 = *((char **)t12);
    t12 = (t1 + 1280);
    xsi_vlogfile_write(1, 0, 0, ng5, 4, t12, (char)118, t6, 5, (char)118, t10, 32, (char)118, t18, 32);
    goto LAB29;

}

static void Always_25_0(char *t0)
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

LAB0:    t1 = (t0 + 5944U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(25, ng0);
    t2 = (t0 + 5752);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(25, ng0);
    t4 = (t0 + 2472);
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
    t24 = (t0 + 2472);
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

static void Initial_65_1(char *t0)
{
    char t28[8];
    char t34[8];
    char t41[8];
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
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    char *t63;
    char *t64;
    char *t65;
    char *t66;
    char *t67;
    char *t68;
    char *t69;
    char *t70;
    char *t71;
    int t72;
    char *t73;
    char *t74;
    char *t75;
    char *t76;

LAB0:    t1 = (t0 + 6192U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(65, ng0);

LAB4:    xsi_set_current_line(66, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 2472);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 2632);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 2792);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 2952);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(70, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 3112);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 3272);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 3432);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(73, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 3592);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(76, ng0);
    t2 = ((char*)((ng7)));
    t3 = ((char*)((ng7)));
    t4 = ((char*)((ng7)));
    t5 = ((char*)((ng7)));
    t6 = ((char*)((ng8)));
    t7 = (t0 + 6000);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4392);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 5);
    t11 = (t0 + 4552);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 5);
    t12 = (t0 + 4712);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4872);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 5032);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB7:    t15 = (t0 + 6096);
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

LAB5:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB6:    t24 = (t0 + 6096);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 6000);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(79, ng0);
    t2 = ((char*)((ng2)));
    t3 = ((char*)((ng9)));
    t4 = ((char*)((ng2)));
    t5 = (t0 + 6000);
    t6 = (t0 + 848);
    t7 = xsi_create_subprogram_invocation(t5, 0, t0, t6, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t6, t7);
    t8 = (t0 + 3912);
    xsi_vlogvar_assign_value(t8, t2, 0, 0, 5);
    t9 = (t0 + 4072);
    xsi_vlogvar_assign_value(t9, t3, 0, 0, 32);
    t10 = (t0 + 4232);
    xsi_vlogvar_assign_value(t10, t4, 0, 0, 1);

LAB13:    t11 = (t0 + 6096);
    t12 = *((char **)t11);
    t13 = (t12 + 80U);
    t14 = *((char **)t13);
    t15 = (t14 + 272U);
    t16 = *((char **)t15);
    t17 = (t16 + 0U);
    t18 = *((char **)t17);
    t23 = ((int  (*)(char *, char *))t18)(t0, t12);

LAB15:    if (t23 != 0)
        goto LAB16;

LAB11:    t12 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t12);

LAB12:    t19 = (t0 + 6096);
    t20 = *((char **)t19);
    t19 = (t0 + 848);
    t21 = (t0 + 6000);
    t22 = 0;
    xsi_delete_subprogram_invocation(t19, t20, t0, t21, t22);
    xsi_set_current_line(80, ng0);
    t2 = ((char*)((ng2)));
    t3 = ((char*)((ng7)));
    t4 = ((char*)((ng9)));
    t5 = ((char*)((ng7)));
    t6 = ((char*)((ng10)));
    t7 = (t0 + 6000);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4392);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 5);
    t11 = (t0 + 4552);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 5);
    t12 = (t0 + 4712);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4872);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 5032);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB19:    t15 = (t0 + 6096);
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

LAB17:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB18:    t24 = (t0 + 6096);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 6000);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(83, ng0);
    t2 = ((char*)((ng11)));
    t3 = ((char*)((ng12)));
    t4 = ((char*)((ng2)));
    t5 = (t0 + 6000);
    t6 = (t0 + 848);
    t7 = xsi_create_subprogram_invocation(t5, 0, t0, t6, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t6, t7);
    t8 = (t0 + 3912);
    xsi_vlogvar_assign_value(t8, t2, 0, 0, 5);
    t9 = (t0 + 4072);
    xsi_vlogvar_assign_value(t9, t3, 0, 0, 32);
    t10 = (t0 + 4232);
    xsi_vlogvar_assign_value(t10, t4, 0, 0, 1);

LAB25:    t11 = (t0 + 6096);
    t12 = *((char **)t11);
    t13 = (t12 + 80U);
    t14 = *((char **)t13);
    t15 = (t14 + 272U);
    t16 = *((char **)t15);
    t17 = (t16 + 0U);
    t18 = *((char **)t17);
    t23 = ((int  (*)(char *, char *))t18)(t0, t12);

LAB27:    if (t23 != 0)
        goto LAB28;

LAB23:    t12 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t12);

LAB24:    t19 = (t0 + 6096);
    t20 = *((char **)t19);
    t19 = (t0 + 848);
    t21 = (t0 + 6000);
    t22 = 0;
    xsi_delete_subprogram_invocation(t19, t20, t0, t21, t22);
    xsi_set_current_line(84, ng0);
    t2 = ((char*)((ng2)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng9)));
    t5 = ((char*)((ng12)));
    t6 = ((char*)((ng13)));
    t7 = (t0 + 6000);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4392);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 5);
    t11 = (t0 + 4552);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 5);
    t12 = (t0 + 4712);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4872);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 5032);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB31:    t15 = (t0 + 6096);
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

LAB29:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB30:    t24 = (t0 + 6096);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 6000);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(88, ng0);
    t2 = ((char*)((ng14)));
    t3 = ((char*)((ng15)));
    t4 = ((char*)((ng2)));
    t5 = (t0 + 6000);
    t6 = (t0 + 848);
    t7 = xsi_create_subprogram_invocation(t5, 0, t0, t6, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t6, t7);
    t8 = (t0 + 3912);
    xsi_vlogvar_assign_value(t8, t2, 0, 0, 5);
    t9 = (t0 + 4072);
    xsi_vlogvar_assign_value(t9, t3, 0, 0, 32);
    t10 = (t0 + 4232);
    xsi_vlogvar_assign_value(t10, t4, 0, 0, 1);

LAB37:    t11 = (t0 + 6096);
    t12 = *((char **)t11);
    t13 = (t12 + 80U);
    t14 = *((char **)t13);
    t15 = (t14 + 272U);
    t16 = *((char **)t15);
    t17 = (t16 + 0U);
    t18 = *((char **)t17);
    t23 = ((int  (*)(char *, char *))t18)(t0, t12);

LAB39:    if (t23 != 0)
        goto LAB40;

LAB35:    t12 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t12);

LAB36:    t19 = (t0 + 6096);
    t20 = *((char **)t19);
    t19 = (t0 + 848);
    t21 = (t0 + 6000);
    t22 = 0;
    xsi_delete_subprogram_invocation(t19, t20, t0, t21, t22);
    xsi_set_current_line(89, ng0);
    t2 = ((char*)((ng14)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng15)));
    t5 = ((char*)((ng12)));
    t6 = ((char*)((ng16)));
    t7 = (t0 + 6000);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4392);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 5);
    t11 = (t0 + 4552);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 5);
    t12 = (t0 + 4712);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4872);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 5032);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB43:    t15 = (t0 + 6096);
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

LAB41:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB42:    t24 = (t0 + 6096);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 6000);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(93, ng0);
    t2 = ((char*)((ng7)));
    t3 = ((char*)((ng17)));
    t4 = ((char*)((ng2)));
    t5 = (t0 + 6000);
    t6 = (t0 + 848);
    t7 = xsi_create_subprogram_invocation(t5, 0, t0, t6, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t6, t7);
    t8 = (t0 + 3912);
    xsi_vlogvar_assign_value(t8, t2, 0, 0, 5);
    t9 = (t0 + 4072);
    xsi_vlogvar_assign_value(t9, t3, 0, 0, 32);
    t10 = (t0 + 4232);
    xsi_vlogvar_assign_value(t10, t4, 0, 0, 1);

LAB49:    t11 = (t0 + 6096);
    t12 = *((char **)t11);
    t13 = (t12 + 80U);
    t14 = *((char **)t13);
    t15 = (t14 + 272U);
    t16 = *((char **)t15);
    t17 = (t16 + 0U);
    t18 = *((char **)t17);
    t23 = ((int  (*)(char *, char *))t18)(t0, t12);

LAB51:    if (t23 != 0)
        goto LAB52;

LAB47:    t12 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t12);

LAB48:    t19 = (t0 + 6096);
    t20 = *((char **)t19);
    t19 = (t0 + 848);
    t21 = (t0 + 6000);
    t22 = 0;
    xsi_delete_subprogram_invocation(t19, t20, t0, t21, t22);
    xsi_set_current_line(94, ng0);
    t2 = ((char*)((ng7)));
    t3 = ((char*)((ng14)));
    t4 = ((char*)((ng7)));
    t5 = ((char*)((ng15)));
    t6 = ((char*)((ng18)));
    t7 = (t0 + 6000);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4392);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 5);
    t11 = (t0 + 4552);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 5);
    t12 = (t0 + 4712);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4872);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 5032);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB55:    t15 = (t0 + 6096);
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

LAB53:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB54:    t24 = (t0 + 6096);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 6000);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(98, ng0);
    t2 = ((char*)((ng2)));
    t3 = ((char*)((ng19)));
    t4 = ((char*)((ng7)));
    t5 = (t0 + 6000);
    t6 = (t0 + 848);
    t7 = xsi_create_subprogram_invocation(t5, 0, t0, t6, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t6, t7);
    t8 = (t0 + 3912);
    xsi_vlogvar_assign_value(t8, t2, 0, 0, 5);
    t9 = (t0 + 4072);
    xsi_vlogvar_assign_value(t9, t3, 0, 0, 32);
    t10 = (t0 + 4232);
    xsi_vlogvar_assign_value(t10, t4, 0, 0, 1);

LAB61:    t11 = (t0 + 6096);
    t12 = *((char **)t11);
    t13 = (t12 + 80U);
    t14 = *((char **)t13);
    t15 = (t14 + 272U);
    t16 = *((char **)t15);
    t17 = (t16 + 0U);
    t18 = *((char **)t17);
    t23 = ((int  (*)(char *, char *))t18)(t0, t12);

LAB63:    if (t23 != 0)
        goto LAB64;

LAB59:    t12 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t12);

LAB60:    t19 = (t0 + 6096);
    t20 = *((char **)t19);
    t19 = (t0 + 848);
    t21 = (t0 + 6000);
    t22 = 0;
    xsi_delete_subprogram_invocation(t19, t20, t0, t21, t22);
    xsi_set_current_line(99, ng0);
    t2 = ((char*)((ng2)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng9)));
    t5 = ((char*)((ng12)));
    t6 = ((char*)((ng20)));
    t7 = (t0 + 6000);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4392);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 5);
    t11 = (t0 + 4552);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 5);
    t12 = (t0 + 4712);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4872);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 5032);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB67:    t15 = (t0 + 6096);
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

LAB65:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB66:    t24 = (t0 + 6096);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 6000);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(103, ng0);
    t2 = ((char*)((ng11)));
    t3 = ((char*)((ng21)));
    t4 = ((char*)((ng2)));
    t5 = (t0 + 6000);
    t6 = (t0 + 848);
    t7 = xsi_create_subprogram_invocation(t5, 0, t0, t6, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t6, t7);
    t8 = (t0 + 3912);
    xsi_vlogvar_assign_value(t8, t2, 0, 0, 5);
    t9 = (t0 + 4072);
    xsi_vlogvar_assign_value(t9, t3, 0, 0, 32);
    t10 = (t0 + 4232);
    xsi_vlogvar_assign_value(t10, t4, 0, 0, 1);

LAB73:    t11 = (t0 + 6096);
    t12 = *((char **)t11);
    t13 = (t12 + 80U);
    t14 = *((char **)t13);
    t15 = (t14 + 272U);
    t16 = *((char **)t15);
    t17 = (t16 + 0U);
    t18 = *((char **)t17);
    t23 = ((int  (*)(char *, char *))t18)(t0, t12);

LAB75:    if (t23 != 0)
        goto LAB76;

LAB71:    t12 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t12);

LAB72:    t19 = (t0 + 6096);
    t20 = *((char **)t19);
    t19 = (t0 + 848);
    t21 = (t0 + 6000);
    t22 = 0;
    xsi_delete_subprogram_invocation(t19, t20, t0, t21, t22);
    xsi_set_current_line(104, ng0);
    t2 = ((char*)((ng11)));
    t3 = ((char*)((ng2)));
    t4 = ((char*)((ng21)));
    t5 = ((char*)((ng9)));
    t6 = ((char*)((ng22)));
    t7 = (t0 + 6000);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4392);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 5);
    t11 = (t0 + 4552);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 5);
    t12 = (t0 + 4712);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4872);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 5032);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB79:    t15 = (t0 + 6096);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB81:    if (t23 != 0)
        goto LAB82;

LAB77:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB78:    t24 = (t0 + 6096);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 6000);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(108, ng0);
    t2 = ((char*)((ng11)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng21)));
    t5 = ((char*)((ng21)));
    t6 = ((char*)((ng23)));
    t7 = (t0 + 6000);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4392);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 5);
    t11 = (t0 + 4552);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 5);
    t12 = (t0 + 4712);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4872);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 5032);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB85:    t15 = (t0 + 6096);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB87:    if (t23 != 0)
        goto LAB88;

LAB83:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB84:    t24 = (t0 + 6096);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 6000);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(112, ng0);
    t2 = ((char*)((ng7)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng7)));
    t5 = ((char*)((ng21)));
    t6 = ((char*)((ng24)));
    t7 = (t0 + 6000);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4392);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 5);
    t11 = (t0 + 4552);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 5);
    t12 = (t0 + 4712);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4872);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 5032);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB91:    t15 = (t0 + 6096);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB93:    if (t23 != 0)
        goto LAB94;

LAB89:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB90:    t24 = (t0 + 6096);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 6000);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(116, ng0);
    t2 = (t0 + 6544);
    *((int *)t2) = 1;
    t3 = (t0 + 6224);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB95;

LAB1:    return;
LAB8:;
LAB10:    t15 = (t0 + 6192U);
    *((char **)t15) = &&LAB7;
    goto LAB1;

LAB14:;
LAB16:    t11 = (t0 + 6192U);
    *((char **)t11) = &&LAB13;
    goto LAB1;

LAB20:;
LAB22:    t15 = (t0 + 6192U);
    *((char **)t15) = &&LAB19;
    goto LAB1;

LAB26:;
LAB28:    t11 = (t0 + 6192U);
    *((char **)t11) = &&LAB25;
    goto LAB1;

LAB32:;
LAB34:    t15 = (t0 + 6192U);
    *((char **)t15) = &&LAB31;
    goto LAB1;

LAB38:;
LAB40:    t11 = (t0 + 6192U);
    *((char **)t11) = &&LAB37;
    goto LAB1;

LAB44:;
LAB46:    t15 = (t0 + 6192U);
    *((char **)t15) = &&LAB43;
    goto LAB1;

LAB50:;
LAB52:    t11 = (t0 + 6192U);
    *((char **)t11) = &&LAB49;
    goto LAB1;

LAB56:;
LAB58:    t15 = (t0 + 6192U);
    *((char **)t15) = &&LAB55;
    goto LAB1;

LAB62:;
LAB64:    t11 = (t0 + 6192U);
    *((char **)t11) = &&LAB61;
    goto LAB1;

LAB68:;
LAB70:    t15 = (t0 + 6192U);
    *((char **)t15) = &&LAB67;
    goto LAB1;

LAB74:;
LAB76:    t11 = (t0 + 6192U);
    *((char **)t11) = &&LAB73;
    goto LAB1;

LAB80:;
LAB82:    t15 = (t0 + 6192U);
    *((char **)t15) = &&LAB79;
    goto LAB1;

LAB86:;
LAB88:    t15 = (t0 + 6192U);
    *((char **)t15) = &&LAB85;
    goto LAB1;

LAB92:;
LAB94:    t15 = (t0 + 6192U);
    *((char **)t15) = &&LAB91;
    goto LAB1;

LAB95:    xsi_set_current_line(117, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3112);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(118, ng0);
    t2 = ((char*)((ng25)));
    t3 = (t0 + 3272);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(119, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2632);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(121, ng0);
    t2 = ((char*)((ng2)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng9)));
    t5 = ((char*)((ng21)));
    t6 = ((char*)((ng26)));
    t7 = (t0 + 6000);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4392);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 5);
    t11 = (t0 + 4552);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 5);
    t12 = (t0 + 4712);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4872);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 5032);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB98:    t15 = (t0 + 6096);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB100:    if (t23 != 0)
        goto LAB101;

LAB96:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB97:    t24 = (t0 + 6096);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 6000);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(124, ng0);
    t2 = (t0 + 6560);
    *((int *)t2) = 1;
    t3 = (t0 + 6224);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB102;
    goto LAB1;

LAB99:;
LAB101:    t15 = (t0 + 6192U);
    *((char **)t15) = &&LAB98;
    goto LAB1;

LAB102:    xsi_set_current_line(125, ng0);
    t2 = (t0 + 6000);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB103;
    goto LAB1;

LAB103:    xsi_set_current_line(126, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 2632);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(128, ng0);
    t2 = ((char*)((ng2)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng25)));
    t5 = ((char*)((ng21)));
    t6 = ((char*)((ng27)));
    t7 = (t0 + 6000);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4392);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 5);
    t11 = (t0 + 4552);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 5);
    t12 = (t0 + 4712);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4872);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 5032);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB106:    t15 = (t0 + 6096);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB108:    if (t23 != 0)
        goto LAB109;

LAB104:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB105:    t24 = (t0 + 6096);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 6000);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(132, ng0);
    xsi_set_current_line(132, ng0);
    t2 = ((char*)((ng28)));
    t3 = (t0 + 3752);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB110:    t2 = (t0 + 3752);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng29)));
    memset(t28, 0, 8);
    xsi_vlog_signed_leq(t28, 32, t4, 32, t5, 32);
    t6 = (t28 + 4);
    t29 = *((unsigned int *)t6);
    t30 = (~(t29));
    t31 = *((unsigned int *)t28);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB111;

LAB112:    xsi_set_current_line(141, ng0);
    t2 = ((char*)((ng2)));
    t3 = ((char*)((ng14)));
    t4 = ((char*)((ng25)));
    t5 = ((char*)((ng15)));
    t6 = ((char*)((ng32)));
    t7 = (t0 + 6000);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4392);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 5);
    t11 = (t0 + 4552);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 5);
    t12 = (t0 + 4712);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4872);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 5032);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB134:    t15 = (t0 + 6096);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB136:    if (t23 != 0)
        goto LAB137;

LAB132:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB133:    t24 = (t0 + 6096);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 6000);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(144, ng0);
    t2 = ((char*)((ng11)));
    t3 = ((char*)((ng2)));
    t4 = ((char*)((ng21)));
    t5 = ((char*)((ng25)));
    t6 = ((char*)((ng33)));
    t7 = (t0 + 6000);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4392);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 5);
    t11 = (t0 + 4552);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 5);
    t12 = (t0 + 4712);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4872);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 5032);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB140:    t15 = (t0 + 6096);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB142:    if (t23 != 0)
        goto LAB143;

LAB138:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB139:    t24 = (t0 + 6096);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 6000);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(147, ng0);
    t2 = ((char*)((ng7)));
    t3 = ((char*)((ng29)));
    t4 = ((char*)((ng7)));
    t5 = ((char*)((ng34)));
    t6 = ((char*)((ng35)));
    t7 = (t0 + 6000);
    t8 = (t0 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4392);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 5);
    t11 = (t0 + 4552);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 5);
    t12 = (t0 + 4712);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4872);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 5032);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB146:    t15 = (t0 + 6096);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB148:    if (t23 != 0)
        goto LAB149;

LAB144:    t16 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t16);

LAB145:    t24 = (t0 + 6096);
    t25 = *((char **)t24);
    t24 = (t0 + 1280);
    t26 = (t0 + 6000);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(150, ng0);
    xsi_vlogfile_write(1, 0, 0, ng36, 1, t0);
    xsi_set_current_line(151, ng0);
    t2 = (t0 + 3432);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3432);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 3592);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t28, 0, 8);
    xsi_vlog_signed_minus(t28, 32, t7, 32, t10, 32);
    t11 = (t0 + 3592);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    xsi_vlogfile_write(1, 0, 0, ng37, 4, t0, (char)119, t4, 32, (char)119, t28, 32, (char)119, t13, 32);
    xsi_set_current_line(153, ng0);
    xsi_vlogfile_write(1, 0, 0, ng36, 1, t0);
    xsi_set_current_line(155, ng0);
    t2 = (t0 + 3592);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng7)));
    memset(t28, 0, 8);
    xsi_vlog_signed_equal(t28, 32, t4, 32, t5, 32);
    t6 = (t28 + 4);
    t29 = *((unsigned int *)t6);
    t30 = (~(t29));
    t31 = *((unsigned int *)t28);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB150;

LAB151:    xsi_set_current_line(158, ng0);
    xsi_vlogfile_write(1, 0, 0, ng39, 1, t0);

LAB152:    xsi_set_current_line(160, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

LAB107:;
LAB109:    t15 = (t0 + 6192U);
    *((char **)t15) = &&LAB106;
    goto LAB1;

LAB111:    xsi_set_current_line(132, ng0);

LAB113:    xsi_set_current_line(133, ng0);
    t7 = (t0 + 3752);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t34, 0, 8);
    t10 = (t34 + 4);
    t11 = (t9 + 4);
    t35 = *((unsigned int *)t9);
    t36 = (t35 >> 0);
    *((unsigned int *)t34) = t36;
    t37 = *((unsigned int *)t11);
    t38 = (t37 >> 0);
    *((unsigned int *)t10) = t38;
    t39 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t39 & 31U);
    t40 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t40 & 31U);
    t12 = ((char*)((ng30)));
    t13 = (t0 + 3752);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t42 = *((unsigned int *)t12);
    t43 = *((unsigned int *)t15);
    t44 = (t42 | t43);
    *((unsigned int *)t41) = t44;
    t16 = (t12 + 4);
    t17 = (t15 + 4);
    t18 = (t41 + 4);
    t45 = *((unsigned int *)t16);
    t46 = *((unsigned int *)t17);
    t47 = (t45 | t46);
    *((unsigned int *)t18) = t47;
    t48 = *((unsigned int *)t18);
    t49 = (t48 != 0);
    if (t49 == 1)
        goto LAB114;

LAB115:
LAB116:    t21 = ((char*)((ng2)));
    t22 = (t0 + 6000);
    t24 = (t0 + 848);
    t25 = xsi_create_subprogram_invocation(t22, 0, t0, t24, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t24, t25);
    t26 = (t0 + 3912);
    xsi_vlogvar_assign_value(t26, t34, 0, 0, 5);
    t27 = (t0 + 4072);
    xsi_vlogvar_assign_value(t27, t41, 0, 0, 32);
    t63 = (t0 + 4232);
    xsi_vlogvar_assign_value(t63, t21, 0, 0, 1);

LAB119:    t64 = (t0 + 6096);
    t65 = *((char **)t64);
    t66 = (t65 + 80U);
    t67 = *((char **)t66);
    t68 = (t67 + 272U);
    t69 = *((char **)t68);
    t70 = (t69 + 0U);
    t71 = *((char **)t70);
    t72 = ((int  (*)(char *, char *))t71)(t0, t65);

LAB121:    if (t72 != 0)
        goto LAB122;

LAB117:    t65 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t65);

LAB118:    t73 = (t0 + 6096);
    t74 = *((char **)t73);
    t73 = (t0 + 848);
    t75 = (t0 + 6000);
    t76 = 0;
    xsi_delete_subprogram_invocation(t73, t74, t0, t75, t76);
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 3752);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t28, 0, 8);
    t5 = (t28 + 4);
    t6 = (t4 + 4);
    t29 = *((unsigned int *)t4);
    t30 = (t29 >> 0);
    *((unsigned int *)t28) = t30;
    t31 = *((unsigned int *)t6);
    t32 = (t31 >> 0);
    *((unsigned int *)t5) = t32;
    t33 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t33 & 31U);
    t35 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t35 & 31U);
    t7 = ((char*)((ng1)));
    t8 = ((char*)((ng30)));
    t9 = (t0 + 3752);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t36 = *((unsigned int *)t8);
    t37 = *((unsigned int *)t11);
    t38 = (t36 | t37);
    *((unsigned int *)t34) = t38;
    t12 = (t8 + 4);
    t13 = (t11 + 4);
    t14 = (t34 + 4);
    t39 = *((unsigned int *)t12);
    t40 = *((unsigned int *)t13);
    t42 = (t39 | t40);
    *((unsigned int *)t14) = t42;
    t43 = *((unsigned int *)t14);
    t44 = (t43 != 0);
    if (t44 == 1)
        goto LAB123;

LAB124:
LAB125:    t17 = ((char*)((ng1)));
    t18 = ((char*)((ng31)));
    t19 = (t0 + 6000);
    t20 = (t0 + 1280);
    t21 = xsi_create_subprogram_invocation(t19, 0, t0, t20, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t20, t21);
    t22 = (t0 + 4392);
    xsi_vlogvar_assign_value(t22, t28, 0, 0, 5);
    t24 = (t0 + 4552);
    xsi_vlogvar_assign_value(t24, t7, 0, 0, 5);
    t25 = (t0 + 4712);
    xsi_vlogvar_assign_value(t25, t34, 0, 0, 32);
    t26 = (t0 + 4872);
    xsi_vlogvar_assign_value(t26, t17, 0, 0, 32);
    t27 = (t0 + 5032);
    xsi_vlogvar_assign_value(t27, t18, 0, 0, 256);

LAB128:    t63 = (t0 + 6096);
    t64 = *((char **)t63);
    t65 = (t64 + 80U);
    t66 = *((char **)t65);
    t67 = (t66 + 272U);
    t68 = *((char **)t67);
    t69 = (t68 + 0U);
    t70 = *((char **)t69);
    t72 = ((int  (*)(char *, char *))t70)(t0, t64);

LAB130:    if (t72 != 0)
        goto LAB131;

LAB126:    t64 = (t0 + 1280);
    xsi_vlog_subprogram_popinvocation(t64);

LAB127:    t71 = (t0 + 6096);
    t73 = *((char **)t71);
    t71 = (t0 + 1280);
    t74 = (t0 + 6000);
    t75 = 0;
    xsi_delete_subprogram_invocation(t71, t73, t0, t74, t75);
    xsi_set_current_line(132, ng0);
    t2 = (t0 + 3752);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t28, 0, 8);
    xsi_vlog_signed_add(t28, 32, t4, 32, t5, 32);
    t6 = (t0 + 3752);
    xsi_vlogvar_assign_value(t6, t28, 0, 0, 32);
    goto LAB110;

LAB114:    t50 = *((unsigned int *)t41);
    t51 = *((unsigned int *)t18);
    *((unsigned int *)t41) = (t50 | t51);
    t19 = (t12 + 4);
    t20 = (t15 + 4);
    t52 = *((unsigned int *)t19);
    t53 = (~(t52));
    t54 = *((unsigned int *)t12);
    t23 = (t54 & t53);
    t55 = *((unsigned int *)t20);
    t56 = (~(t55));
    t57 = *((unsigned int *)t15);
    t58 = (t57 & t56);
    t59 = (~(t23));
    t60 = (~(t58));
    t61 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t61 & t59);
    t62 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t62 & t60);
    goto LAB116;

LAB120:;
LAB122:    t64 = (t0 + 6192U);
    *((char **)t64) = &&LAB119;
    goto LAB1;

LAB123:    t45 = *((unsigned int *)t34);
    t46 = *((unsigned int *)t14);
    *((unsigned int *)t34) = (t45 | t46);
    t15 = (t8 + 4);
    t16 = (t11 + 4);
    t47 = *((unsigned int *)t15);
    t48 = (~(t47));
    t49 = *((unsigned int *)t8);
    t23 = (t49 & t48);
    t50 = *((unsigned int *)t16);
    t51 = (~(t50));
    t52 = *((unsigned int *)t11);
    t58 = (t52 & t51);
    t53 = (~(t23));
    t54 = (~(t58));
    t55 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t55 & t53);
    t56 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t56 & t54);
    goto LAB125;

LAB129:;
LAB131:    t63 = (t0 + 6192U);
    *((char **)t63) = &&LAB128;
    goto LAB1;

LAB135:;
LAB137:    t15 = (t0 + 6192U);
    *((char **)t15) = &&LAB134;
    goto LAB1;

LAB141:;
LAB143:    t15 = (t0 + 6192U);
    *((char **)t15) = &&LAB140;
    goto LAB1;

LAB147:;
LAB149:    t15 = (t0 + 6192U);
    *((char **)t15) = &&LAB146;
    goto LAB1;

LAB150:    xsi_set_current_line(156, ng0);
    xsi_vlogfile_write(1, 0, 0, ng38, 1, t0);
    goto LAB152;

}


extern void work_m_01622699053583640706_3476323984_init()
{
	static char *pe[] = {(void *)Always_25_0,(void *)Initial_65_1};
	static char *se[] = {(void *)sp_write_reg,(void *)sp_check};
	xsi_register_didat("work_m_01622699053583640706_3476323984", "isim/register_file_tb_isim_beh.exe.sim/work/m_01622699053583640706_3476323984.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
