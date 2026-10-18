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
static const char *ng0 = "/home/ise/Desktop/LED_PATTERNS/led_patterns/led_pattern.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static int ng3[] = {7, 0};
static unsigned int ng4[] = {2U, 0U};
static int ng5[] = {1, 0};
static unsigned int ng6[] = {3U, 0U};
static unsigned int ng7[] = {85U, 0U};
static unsigned int ng8[] = {170U, 0U};
static int ng9[] = {0, 0};



static void Always_28_0(char *t0)
{
    char t7[8];
    char t16[8];
    char t17[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t13;
    int t14;
    char *t15;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
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

LAB0:    t1 = (t0 + 2680U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(28, ng0);
    t2 = (t0 + 3248);
    *((int *)t2) = 1;
    t3 = (t0 + 2712);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(28, ng0);

LAB5:    xsi_set_current_line(29, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 1768);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(30, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);

LAB6:    t2 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 2, t2, 2);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 2, t2, 2);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 2, t2, 2);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 2, t2, 2);
    if (t6 == 1)
        goto LAB13;

LAB14:
LAB16:
LAB15:    xsi_set_current_line(40, ng0);

LAB39:    xsi_set_current_line(41, ng0);
    t2 = ((char*)((ng9)));
    t4 = (t0 + 1768);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 8);

LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(31, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t0 + 1768);
    t8 = (t0 + 1768);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 1208U);
    t12 = *((char **)t11);
    xsi_vlog_generic_convert_bit_index(t7, t10, 2, t12, 3, 2);
    t11 = (t7 + 4);
    t13 = *((unsigned int *)t11);
    t14 = (!(t13));
    if (t14 == 1)
        goto LAB18;

LAB19:    goto LAB17;

LAB9:    xsi_set_current_line(32, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t0 + 1768);
    t8 = (t0 + 1768);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = ((char*)((ng3)));
    t12 = (t0 + 1208U);
    t15 = *((char **)t12);
    memset(t16, 0, 8);
    xsi_vlog_unsigned_minus(t16, 32, t11, 32, t15, 3);
    xsi_vlog_generic_convert_bit_index(t7, t10, 2, t16, 32, 2);
    t12 = (t7 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (!(t13));
    if (t14 == 1)
        goto LAB20;

LAB21:    goto LAB17;

LAB11:    xsi_set_current_line(33, ng0);

LAB22:    xsi_set_current_line(34, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t0 + 1768);
    t8 = (t0 + 1768);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 1208U);
    t12 = *((char **)t11);
    xsi_vlog_generic_convert_bit_index(t7, t10, 2, t12, 3, 2);
    t11 = (t7 + 4);
    t13 = *((unsigned int *)t11);
    t14 = (!(t13));
    if (t14 == 1)
        goto LAB23;

LAB24:    xsi_set_current_line(35, ng0);
    t2 = (t0 + 1768);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t8 = ((char*)((ng2)));
    memset(t7, 0, 8);
    xsi_vlog_unsigned_minus(t7, 8, t5, 8, t8, 8);
    t9 = ((char*)((ng5)));
    memset(t16, 0, 8);
    xsi_vlog_unsigned_lshift(t16, 8, t7, 8, t9, 32);
    t10 = ((char*)((ng2)));
    memset(t17, 0, 8);
    xsi_vlog_unsigned_add(t17, 8, t16, 8, t10, 8);
    t11 = (t0 + 1768);
    xsi_vlogvar_assign_value(t11, t17, 0, 0, 8);
    goto LAB17;

LAB13:    xsi_set_current_line(37, ng0);

LAB25:    xsi_set_current_line(38, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);
    memset(t17, 0, 8);
    t4 = (t17 + 4);
    t8 = (t5 + 4);
    t13 = *((unsigned int *)t5);
    t18 = (t13 >> 0);
    t19 = (t18 & 1);
    *((unsigned int *)t17) = t19;
    t20 = *((unsigned int *)t8);
    t21 = (t20 >> 0);
    t22 = (t21 & 1);
    *((unsigned int *)t4) = t22;
    memset(t16, 0, 8);
    t9 = (t17 + 4);
    t23 = *((unsigned int *)t9);
    t24 = (~(t23));
    t25 = *((unsigned int *)t17);
    t26 = (t25 & t24);
    t27 = (t26 & 1U);
    if (t27 != 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t9) != 0)
        goto LAB28;

LAB29:    t11 = (t16 + 4);
    t28 = *((unsigned int *)t16);
    t29 = *((unsigned int *)t11);
    t30 = (t28 || t29);
    if (t30 > 0)
        goto LAB30;

LAB31:    t31 = *((unsigned int *)t16);
    t32 = (~(t31));
    t33 = *((unsigned int *)t11);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t11) > 0)
        goto LAB34;

LAB35:    if (*((unsigned int *)t16) > 0)
        goto LAB36;

LAB37:    memcpy(t7, t15, 8);

LAB38:    t35 = (t0 + 1768);
    xsi_vlogvar_assign_value(t35, t7, 0, 0, 8);
    goto LAB17;

LAB18:    xsi_vlogvar_assign_value(t5, t4, 0, *((unsigned int *)t7), 1);
    goto LAB19;

LAB20:    xsi_vlogvar_assign_value(t5, t4, 0, *((unsigned int *)t7), 1);
    goto LAB21;

LAB23:    xsi_vlogvar_assign_value(t5, t4, 0, *((unsigned int *)t7), 1);
    goto LAB24;

LAB26:    *((unsigned int *)t16) = 1;
    goto LAB29;

LAB28:    t10 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB29;

LAB30:    t12 = ((char*)((ng7)));
    goto LAB31;

LAB32:    t15 = ((char*)((ng8)));
    goto LAB33;

LAB34:    xsi_vlog_unsigned_bit_combine(t7, 8, t12, 8, t15, 8);
    goto LAB38;

LAB36:    memcpy(t7, t12, 8);
    goto LAB38;

}

static void Cont_45_1(char *t0)
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
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 2928U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 1768);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3344);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 255U;
    t11 = t10;
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t5, 0, 7);
    t18 = (t0 + 3264);
    *((int *)t18) = 1;

LAB1:    return;
}


extern void work_m_17057933908097970836_4252524221_init()
{
	static char *pe[] = {(void *)Always_28_0,(void *)Cont_45_1};
	xsi_register_didat("work_m_17057933908097970836_4252524221", "isim/everything_tb_isim_beh.exe.sim/work/m_17057933908097970836_4252524221.didat");
	xsi_register_executes(pe);
}
