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
static const char *ng0 = "/home/ise/Desktop/RISC_V/alu_tb_2.v";
static int ng1[] = {1, 0};
static const char *ng2 = "FAIL %s: expected=%h got=%h";
static const char *ng3 = "PASS %s";
static int ng4[] = {0, 0};
static unsigned int ng5[] = {0U, 0U};
static int ng6[] = {15, 0};
static int ng7[] = {7, 0};
static int ng8[] = {22, 0};
static int ng9[] = {1919770988, 0, 1142976111, 0, 16708, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng10[] = {4294967295U, 0U};
static int ng11[] = {1869966948, 0, 1634754930, 0, 1142978418, 0, 16708, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng12[] = {2147483647U, 0U};
static unsigned int ng13[] = {2147483648U, 0U};
static int ng14[] = {1718382455, 0, 1870030194, 0, 1094992928, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng15[] = {2053468783, 0, 1094992928, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng16[] = {1U, 0U};
static int ng17[] = {5, 0};
static int ng18[] = {12, 0};
static unsigned int ng19[] = {4294967289U, 0U};
static int ng20[] = {1953068645, 0, 1852139361, 0, 1398096416, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng21[] = {1718382455, 0, 1852073330, 0, 1430397045, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng22[] = {1869966948, 0, 1634754930, 0, 1109423986, 0, 21333, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng23[] = {1903518060, 0, 1430397029, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng24[] = {2U, 0U};
static unsigned int ng25[] = {12U, 0U};
static unsigned int ng26[] = {10U, 0U};
static unsigned int ng27[] = {8U, 0U};
static int ng28[] = {4279876, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng29[] = {61680U, 0U};
static unsigned int ng30[] = {4080U, 0U};
static unsigned int ng31[] = {240U, 0U};
static int ng32[] = {1634954099, 0, 1313087597, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng33[] = {3U, 0U};
static unsigned int ng34[] = {14U, 0U};
static int ng35[] = {20306, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng36[] = {305419896U, 0U};
static int ng37[] = {2053468783, 0, 5198368, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng38[] = {4U, 0U};
static unsigned int ng39[] = {6U, 0U};
static int ng40[] = {5787474, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng41[] = {1768120684, 0, 1684369012, 0, 1330782313, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng42[] = {5U, 0U};
static int ng43[] = {3, 0};
static int ng44[] = {2, 0};
static int ng45[] = {1652105266, 0, 1397509152, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng46[] = {31, 0};
static int ng47[] = {2032153393, 0, 1280057442, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng48[] = {32, 0};
static int ng49[] = {1835103083, 0, 1768322080, 0, 1277195112, 0, 21324, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng50[] = {4294967294U, 0U};
static int ng51[] = {1718382455, 0, 1870030194, 0, 1397509152, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng52[] = {1073741824U, 0U};
static int ng53[] = {1768120684, 0, 543977319, 0, 5460556, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng54[] = {2032153393, 0, 1380720738, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng55[] = {33, 0};
static int ng56[] = {1835103083, 0, 1768322080, 0, 1277195112, 0, 21330, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng57[] = {7U, 0U};
static unsigned int ng58[] = {3221225472U, 0U};
static int ng59[] = {1952804452, 0, 1847616888, 0, 544434535, 0, 5460545, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng60[] = {1953068645, 0, 1852139361, 0, 1397899552, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng61[] = {1073741823U, 0U};
static int ng62[] = {1953068645, 0, 1886352233, 0, 1397899552, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng63[] = {2032153393, 0, 1379999842, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng64[] = {1835103083, 0, 1768322080, 0, 1092645736, 0, 21330, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng65[] = {1953068645, 0, 1852139361, 0, 1397511200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng66[] = {1701999461, 0, 544367990, 0, 5459028, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng67[] = {544039288, 0, 544041326, 0, 5459028, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng68[] = {1903518060, 0, 1280581733, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng69[] = {1953068645, 0, 1886352233, 0, 1397511200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng70[] = {9U, 0U};
static int ng71[] = {544039288, 0, 1397511253, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng72[] = {1701999461, 0, 544367990, 0, 1397511253, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng73[] = {1903518060, 0, 1414864997, 0, 21324, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng74[] = {2053468783, 0, 1280595232, 0, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng75[] = {1428189040, 0, 1679835468, 0, 1986096233, 0, 18798, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static const char *ng76 = "--------------------------------------";
static const char *ng77 = "Tests: %0d Passed: %0d Failed: %0d";
static const char *ng78 = "ALU TEST PASSED";
static const char *ng79 = "ALU TEST FAILED";



static int sp_check(char *t1, char *t2)
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

LAB2:    t4 = (t1 + 2208);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(29, ng0);

LAB5:    xsi_set_current_line(30, ng0);
    t5 = (t1 + 4040);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t1 + 3560);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 4);
    xsi_set_current_line(31, ng0);
    t4 = (t1 + 4200);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 3240);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);
    xsi_set_current_line(32, ng0);
    t4 = (t1 + 4360);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 3400);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);
    xsi_set_current_line(33, ng0);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB6;
    t0 = 1;

LAB1:    return t0;
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;
    goto LAB1;

LAB6:    xsi_set_current_line(34, ng0);
    t4 = (t1 + 3720);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    memset(t9, 0, 8);
    xsi_vlog_signed_add(t9, 32, t6, 32, t7, 32);
    t8 = (t1 + 3720);
    xsi_vlogvar_assign_value(t8, t9, 0, 0, 32);
    xsi_set_current_line(36, ng0);
    t4 = (t1 + 2840U);
    t5 = *((char **)t4);
    t4 = (t1 + 4520);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    memset(t9, 0, 8);
    if (*((unsigned int *)t5) != *((unsigned int *)t7))
        goto LAB8;

LAB7:    t8 = (t5 + 4);
    t10 = (t7 + 4);
    if (*((unsigned int *)t8) != *((unsigned int *)t10))
        goto LAB8;

LAB9:    t11 = (t9 + 4);
    t12 = *((unsigned int *)t11);
    t13 = (~(t12));
    t14 = *((unsigned int *)t9);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(42, ng0);
    t4 = (t1 + 4680);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 2208);
    xsi_vlogfile_write(1, 0, 0, ng3, 2, t7, (char)118, t6, 256);

LAB12:    goto LAB4;

LAB8:    *((unsigned int *)t9) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(36, ng0);

LAB13:    xsi_set_current_line(37, ng0);
    t17 = (t1 + 3880);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = ((char*)((ng1)));
    memset(t21, 0, 8);
    xsi_vlog_signed_add(t21, 32, t19, 32, t20, 32);
    t22 = (t1 + 3880);
    xsi_vlogvar_assign_value(t22, t21, 0, 0, 32);
    xsi_set_current_line(38, ng0);
    t4 = (t1 + 4680);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 4520);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    t11 = (t1 + 2840U);
    t17 = *((char **)t11);
    t11 = (t1 + 2208);
    xsi_vlogfile_write(1, 0, 0, ng2, 4, t11, (char)118, t6, 256, (char)118, t10, 32, (char)118, t17, 32);
    goto LAB12;

}

static void Initial_46_0(char *t0)
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

LAB0:    t1 = (t0 + 5592U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(46, ng0);

LAB4:    xsi_set_current_line(47, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3720);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(48, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3880);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(49, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3240);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(50, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3400);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(51, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3560);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng5)));
    t3 = ((char*)((ng6)));
    t4 = ((char*)((ng7)));
    t5 = ((char*)((ng8)));
    t6 = ((char*)((ng9)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB7:    t15 = (t0 + 5496);
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

LAB5:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB6:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng5)));
    t3 = ((char*)((ng10)));
    t4 = ((char*)((ng1)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng11)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB13:    t15 = (t0 + 5496);
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

LAB11:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB12:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng5)));
    t3 = ((char*)((ng12)));
    t4 = ((char*)((ng1)));
    t5 = ((char*)((ng13)));
    t6 = ((char*)((ng14)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB19:    t15 = (t0 + 5496);
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

LAB17:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB18:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(58, ng0);
    t2 = ((char*)((ng5)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng15)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB25:    t15 = (t0 + 5496);
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

LAB23:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB24:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng16)));
    t3 = ((char*)((ng17)));
    t4 = ((char*)((ng18)));
    t5 = ((char*)((ng19)));
    t6 = ((char*)((ng20)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB31:    t15 = (t0 + 5496);
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

LAB29:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB30:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(62, ng0);
    t2 = ((char*)((ng16)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng1)));
    t5 = ((char*)((ng10)));
    t6 = ((char*)((ng21)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB37:    t15 = (t0 + 5496);
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

LAB35:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB36:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(63, ng0);
    t2 = ((char*)((ng16)));
    t3 = ((char*)((ng13)));
    t4 = ((char*)((ng1)));
    t5 = ((char*)((ng12)));
    t6 = ((char*)((ng22)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB43:    t15 = (t0 + 5496);
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

LAB41:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB42:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng16)));
    t3 = ((char*)((ng7)));
    t4 = ((char*)((ng7)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng23)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB49:    t15 = (t0 + 5496);
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

LAB47:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB48:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng24)));
    t3 = ((char*)((ng25)));
    t4 = ((char*)((ng26)));
    t5 = ((char*)((ng27)));
    t6 = ((char*)((ng28)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB55:    t15 = (t0 + 5496);
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

LAB53:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB54:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng24)));
    t3 = ((char*)((ng29)));
    t4 = ((char*)((ng30)));
    t5 = ((char*)((ng31)));
    t6 = ((char*)((ng32)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB61:    t15 = (t0 + 5496);
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

LAB59:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB60:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng33)));
    t3 = ((char*)((ng25)));
    t4 = ((char*)((ng26)));
    t5 = ((char*)((ng34)));
    t6 = ((char*)((ng35)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB67:    t15 = (t0 + 5496);
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

LAB65:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB66:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng33)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng36)));
    t5 = ((char*)((ng36)));
    t6 = ((char*)((ng37)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB73:    t15 = (t0 + 5496);
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

LAB71:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB72:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng38)));
    t3 = ((char*)((ng25)));
    t4 = ((char*)((ng26)));
    t5 = ((char*)((ng39)));
    t6 = ((char*)((ng40)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB79:    t15 = (t0 + 5496);
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

LAB77:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB78:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng38)));
    t3 = ((char*)((ng10)));
    t4 = ((char*)((ng10)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng41)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB85:    t15 = (t0 + 5496);
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

LAB83:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB84:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(79, ng0);
    t2 = ((char*)((ng42)));
    t3 = ((char*)((ng43)));
    t4 = ((char*)((ng44)));
    t5 = ((char*)((ng18)));
    t6 = ((char*)((ng45)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB91:    t15 = (t0 + 5496);
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

LAB89:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB90:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(80, ng0);
    t2 = ((char*)((ng42)));
    t3 = ((char*)((ng1)));
    t4 = ((char*)((ng46)));
    t5 = ((char*)((ng13)));
    t6 = ((char*)((ng47)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB97:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB99:    if (t23 != 0)
        goto LAB100;

LAB95:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB96:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng42)));
    t3 = ((char*)((ng1)));
    t4 = ((char*)((ng48)));
    t5 = ((char*)((ng1)));
    t6 = ((char*)((ng49)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB103:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB105:    if (t23 != 0)
        goto LAB106;

LAB101:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB102:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(82, ng0);
    t2 = ((char*)((ng42)));
    t3 = ((char*)((ng10)));
    t4 = ((char*)((ng1)));
    t5 = ((char*)((ng50)));
    t6 = ((char*)((ng51)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB109:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB111:    if (t23 != 0)
        goto LAB112;

LAB107:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB108:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(86, ng0);
    t2 = ((char*)((ng39)));
    t3 = ((char*)((ng13)));
    t4 = ((char*)((ng1)));
    t5 = ((char*)((ng52)));
    t6 = ((char*)((ng53)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB115:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB117:    if (t23 != 0)
        goto LAB118;

LAB113:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB114:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(88, ng0);
    t2 = ((char*)((ng39)));
    t3 = ((char*)((ng10)));
    t4 = ((char*)((ng46)));
    t5 = ((char*)((ng1)));
    t6 = ((char*)((ng54)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB121:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB123:    if (t23 != 0)
        goto LAB124;

LAB119:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB120:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(89, ng0);
    t2 = ((char*)((ng39)));
    t3 = ((char*)((ng13)));
    t4 = ((char*)((ng55)));
    t5 = ((char*)((ng52)));
    t6 = ((char*)((ng56)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB127:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB129:    if (t23 != 0)
        goto LAB130;

LAB125:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB126:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(93, ng0);
    t2 = ((char*)((ng57)));
    t3 = ((char*)((ng13)));
    t4 = ((char*)((ng1)));
    t5 = ((char*)((ng58)));
    t6 = ((char*)((ng59)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB133:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB135:    if (t23 != 0)
        goto LAB136;

LAB131:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB132:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(95, ng0);
    t2 = ((char*)((ng57)));
    t3 = ((char*)((ng10)));
    t4 = ((char*)((ng46)));
    t5 = ((char*)((ng10)));
    t6 = ((char*)((ng60)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB139:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB141:    if (t23 != 0)
        goto LAB142;

LAB137:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB138:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(97, ng0);
    t2 = ((char*)((ng57)));
    t3 = ((char*)((ng12)));
    t4 = ((char*)((ng1)));
    t5 = ((char*)((ng61)));
    t6 = ((char*)((ng62)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB145:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB147:    if (t23 != 0)
        goto LAB148;

LAB143:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB144:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(99, ng0);
    t2 = ((char*)((ng57)));
    t3 = ((char*)((ng13)));
    t4 = ((char*)((ng46)));
    t5 = ((char*)((ng10)));
    t6 = ((char*)((ng63)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB151:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB153:    if (t23 != 0)
        goto LAB154;

LAB149:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB150:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(101, ng0);
    t2 = ((char*)((ng57)));
    t3 = ((char*)((ng13)));
    t4 = ((char*)((ng48)));
    t5 = ((char*)((ng13)));
    t6 = ((char*)((ng64)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB157:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB159:    if (t23 != 0)
        goto LAB160;

LAB155:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB156:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(105, ng0);
    t2 = ((char*)((ng27)));
    t3 = ((char*)((ng10)));
    t4 = ((char*)((ng1)));
    t5 = ((char*)((ng1)));
    t6 = ((char*)((ng65)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB163:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB165:    if (t23 != 0)
        goto LAB166;

LAB161:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB162:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(106, ng0);
    t2 = ((char*)((ng27)));
    t3 = ((char*)((ng1)));
    t4 = ((char*)((ng10)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng66)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB169:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB171:    if (t23 != 0)
        goto LAB172;

LAB167:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB168:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(107, ng0);
    t2 = ((char*)((ng27)));
    t3 = ((char*)((ng13)));
    t4 = ((char*)((ng12)));
    t5 = ((char*)((ng1)));
    t6 = ((char*)((ng67)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB175:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB177:    if (t23 != 0)
        goto LAB178;

LAB173:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB174:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(109, ng0);
    t2 = ((char*)((ng27)));
    t3 = ((char*)((ng7)));
    t4 = ((char*)((ng7)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng68)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB181:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB183:    if (t23 != 0)
        goto LAB184;

LAB179:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB180:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(110, ng0);
    t2 = ((char*)((ng27)));
    t3 = ((char*)((ng43)));
    t4 = ((char*)((ng17)));
    t5 = ((char*)((ng1)));
    t6 = ((char*)((ng69)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB187:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB189:    if (t23 != 0)
        goto LAB190;

LAB185:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB186:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(113, ng0);
    t2 = ((char*)((ng70)));
    t3 = ((char*)((ng10)));
    t4 = ((char*)((ng1)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng71)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB193:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB195:    if (t23 != 0)
        goto LAB196;

LAB191:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB192:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(114, ng0);
    t2 = ((char*)((ng70)));
    t3 = ((char*)((ng1)));
    t4 = ((char*)((ng10)));
    t5 = ((char*)((ng1)));
    t6 = ((char*)((ng72)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB199:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB201:    if (t23 != 0)
        goto LAB202;

LAB197:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB198:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(115, ng0);
    t2 = ((char*)((ng70)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng4)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng73)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB205:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB207:    if (t23 != 0)
        goto LAB208;

LAB203:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB204:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(116, ng0);
    t2 = ((char*)((ng70)));
    t3 = ((char*)((ng4)));
    t4 = ((char*)((ng10)));
    t5 = ((char*)((ng1)));
    t6 = ((char*)((ng74)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB211:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB213:    if (t23 != 0)
        goto LAB214;

LAB209:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB210:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(119, ng0);
    t2 = ((char*)((ng26)));
    t3 = ((char*)((ng10)));
    t4 = ((char*)((ng10)));
    t5 = ((char*)((ng4)));
    t6 = ((char*)((ng75)));
    t7 = (t0 + 5400);
    t8 = (t0 + 2208);
    t9 = xsi_create_subprogram_invocation(t7, 0, t0, t8, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t8, t9);
    t10 = (t0 + 4040);
    xsi_vlogvar_assign_value(t10, t2, 0, 0, 4);
    t11 = (t0 + 4200);
    xsi_vlogvar_assign_value(t11, t3, 0, 0, 32);
    t12 = (t0 + 4360);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 32);
    t13 = (t0 + 4520);
    xsi_vlogvar_assign_value(t13, t5, 0, 0, 32);
    t14 = (t0 + 4680);
    xsi_vlogvar_assign_value(t14, t6, 0, 0, 256);

LAB217:    t15 = (t0 + 5496);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t23 = ((int  (*)(char *, char *))t22)(t0, t16);

LAB219:    if (t23 != 0)
        goto LAB220;

LAB215:    t16 = (t0 + 2208);
    xsi_vlog_subprogram_popinvocation(t16);

LAB216:    t24 = (t0 + 5496);
    t25 = *((char **)t24);
    t24 = (t0 + 2208);
    t26 = (t0 + 5400);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    xsi_set_current_line(122, ng0);
    xsi_vlogfile_write(1, 0, 0, ng76, 1, t0);
    xsi_set_current_line(123, ng0);
    t2 = (t0 + 3720);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3720);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 3880);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t28, 0, 8);
    xsi_vlog_signed_minus(t28, 32, t7, 32, t10, 32);
    t11 = (t0 + 3880);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    xsi_vlogfile_write(1, 0, 0, ng77, 4, t0, (char)119, t4, 32, (char)119, t28, 32, (char)119, t13, 32);
    xsi_set_current_line(125, ng0);
    xsi_vlogfile_write(1, 0, 0, ng76, 1, t0);
    xsi_set_current_line(127, ng0);
    t2 = (t0 + 3880);
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
        goto LAB221;

LAB222:    xsi_set_current_line(130, ng0);
    xsi_vlogfile_write(1, 0, 0, ng79, 1, t0);

LAB223:    xsi_set_current_line(132, ng0);
    xsi_vlog_finish(1);

LAB1:    return;
LAB8:;
LAB10:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB7;
    goto LAB1;

LAB14:;
LAB16:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB13;
    goto LAB1;

LAB20:;
LAB22:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB19;
    goto LAB1;

LAB26:;
LAB28:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB25;
    goto LAB1;

LAB32:;
LAB34:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB31;
    goto LAB1;

LAB38:;
LAB40:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB37;
    goto LAB1;

LAB44:;
LAB46:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB43;
    goto LAB1;

LAB50:;
LAB52:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB49;
    goto LAB1;

LAB56:;
LAB58:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB55;
    goto LAB1;

LAB62:;
LAB64:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB61;
    goto LAB1;

LAB68:;
LAB70:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB67;
    goto LAB1;

LAB74:;
LAB76:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB73;
    goto LAB1;

LAB80:;
LAB82:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB79;
    goto LAB1;

LAB86:;
LAB88:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB85;
    goto LAB1;

LAB92:;
LAB94:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB91;
    goto LAB1;

LAB98:;
LAB100:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB97;
    goto LAB1;

LAB104:;
LAB106:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB103;
    goto LAB1;

LAB110:;
LAB112:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB109;
    goto LAB1;

LAB116:;
LAB118:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB115;
    goto LAB1;

LAB122:;
LAB124:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB121;
    goto LAB1;

LAB128:;
LAB130:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB127;
    goto LAB1;

LAB134:;
LAB136:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB133;
    goto LAB1;

LAB140:;
LAB142:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB139;
    goto LAB1;

LAB146:;
LAB148:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB145;
    goto LAB1;

LAB152:;
LAB154:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB151;
    goto LAB1;

LAB158:;
LAB160:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB157;
    goto LAB1;

LAB164:;
LAB166:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB163;
    goto LAB1;

LAB170:;
LAB172:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB169;
    goto LAB1;

LAB176:;
LAB178:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB175;
    goto LAB1;

LAB182:;
LAB184:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB181;
    goto LAB1;

LAB188:;
LAB190:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB187;
    goto LAB1;

LAB194:;
LAB196:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB193;
    goto LAB1;

LAB200:;
LAB202:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB199;
    goto LAB1;

LAB206:;
LAB208:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB205;
    goto LAB1;

LAB212:;
LAB214:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB211;
    goto LAB1;

LAB218:;
LAB220:    t15 = (t0 + 5592U);
    *((char **)t15) = &&LAB217;
    goto LAB1;

LAB221:    xsi_set_current_line(128, ng0);
    xsi_vlogfile_write(1, 0, 0, ng78, 1, t0);
    goto LAB223;

}


extern void work_m_18421745076850685961_0954491383_init()
{
	static char *pe[] = {(void *)Initial_46_0};
	static char *se[] = {(void *)sp_check};
	xsi_register_didat("work_m_18421745076850685961_0954491383", "isim/alu_tb_2_isim_beh.exe.sim/work/m_18421745076850685961_0954491383.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
