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
static const char *ng0 = "/home/ise/Desktop/RISC_V/immediate_generator.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {0U, 0U};
static int ng3[] = {20, 0};
static unsigned int ng4[] = {1U, 0U};
static unsigned int ng5[] = {2U, 0U};
static int ng6[] = {19, 0};
static int ng7[] = {31, 0};
static int ng8[] = {13, 0};
static int ng9[] = {12, 0};
static int ng10[] = {11, 0};
static int ng11[] = {10, 0};
static int ng12[] = {5, 0};
static int ng13[] = {4, 0};
static int ng14[] = {1, 0};
static unsigned int ng15[] = {3U, 0U};
static unsigned int ng16[] = {4U, 0U};
static int ng17[] = {21, 0};



static void Always_32_0(char *t0)
{
    char t7[8];
    char t8[8];
    char t16[8];
    char t20[8];
    char t30[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t17;
    char *t18;
    char *t19;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    int t39;
    char *t40;
    int t41;
    int t42;
    char *t43;
    int t44;
    int t45;
    int t46;
    int t47;
    int t48;

LAB0:    t1 = (t0 + 3200U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(32, ng0);
    t2 = (t0 + 3520);
    *((int *)t2) = 1;
    t3 = (t0 + 3232);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(32, ng0);

LAB5:    xsi_set_current_line(33, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 2288);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);
    xsi_set_current_line(34, ng0);
    t2 = (t0 + 1888U);
    t3 = *((char **)t2);

LAB6:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 3, t2, 3);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 3, t2, 3);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 3, t2, 3);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng15)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 3, t2, 3);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng16)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 3, t2, 3);
    if (t6 == 1)
        goto LAB15;

LAB16:
LAB18:
LAB17:    xsi_set_current_line(60, ng0);
    t2 = ((char*)((ng2)));
    t4 = (t0 + 2288);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 32);

LAB19:    goto LAB2;

LAB7:    xsi_set_current_line(35, ng0);

LAB20:    xsi_set_current_line(36, ng0);
    t4 = (t0 + 1728U);
    t5 = *((char **)t4);
    memset(t8, 0, 8);
    t4 = (t8 + 4);
    t9 = (t5 + 4);
    t10 = *((unsigned int *)t5);
    t11 = (t10 >> 20);
    *((unsigned int *)t8) = t11;
    t12 = *((unsigned int *)t9);
    t13 = (t12 >> 20);
    *((unsigned int *)t4) = t13;
    t14 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t14 & 4095U);
    t15 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t15 & 4095U);
    t17 = ((char*)((ng3)));
    t18 = (t0 + 1728U);
    t19 = *((char **)t18);
    memset(t20, 0, 8);
    t18 = (t20 + 4);
    t21 = (t19 + 4);
    t22 = *((unsigned int *)t19);
    t23 = (t22 >> 31);
    t24 = (t23 & 1);
    *((unsigned int *)t20) = t24;
    t25 = *((unsigned int *)t21);
    t26 = (t25 >> 31);
    t27 = (t26 & 1);
    *((unsigned int *)t18) = t27;
    xsi_vlog_mul_concat(t16, 20, 1, t17, 1U, t20, 1);
    xsi_vlogtype_concat(t7, 32, 32, 2U, t16, 20, t8, 12);
    t28 = (t0 + 2288);
    xsi_vlogvar_assign_value(t28, t7, 0, 0, 32);
    goto LAB19;

LAB9:    xsi_set_current_line(38, ng0);

LAB21:    xsi_set_current_line(39, ng0);
    t4 = (t0 + 1728U);
    t5 = *((char **)t4);
    memset(t8, 0, 8);
    t4 = (t8 + 4);
    t9 = (t5 + 4);
    t10 = *((unsigned int *)t5);
    t11 = (t10 >> 7);
    *((unsigned int *)t8) = t11;
    t12 = *((unsigned int *)t9);
    t13 = (t12 >> 7);
    *((unsigned int *)t4) = t13;
    t14 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t14 & 31U);
    t15 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t15 & 31U);
    t17 = (t0 + 1728U);
    t18 = *((char **)t17);
    memset(t16, 0, 8);
    t17 = (t16 + 4);
    t19 = (t18 + 4);
    t22 = *((unsigned int *)t18);
    t23 = (t22 >> 25);
    *((unsigned int *)t16) = t23;
    t24 = *((unsigned int *)t19);
    t25 = (t24 >> 25);
    *((unsigned int *)t17) = t25;
    t26 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t26 & 127U);
    t27 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t27 & 127U);
    t21 = ((char*)((ng3)));
    t28 = (t0 + 1728U);
    t29 = *((char **)t28);
    memset(t30, 0, 8);
    t28 = (t30 + 4);
    t31 = (t29 + 4);
    t32 = *((unsigned int *)t29);
    t33 = (t32 >> 31);
    t34 = (t33 & 1);
    *((unsigned int *)t30) = t34;
    t35 = *((unsigned int *)t31);
    t36 = (t35 >> 31);
    t37 = (t36 & 1);
    *((unsigned int *)t28) = t37;
    xsi_vlog_mul_concat(t20, 20, 1, t21, 1U, t30, 1);
    xsi_vlogtype_concat(t7, 32, 32, 3U, t20, 20, t16, 7, t8, 5);
    t38 = (t0 + 2288);
    xsi_vlogvar_assign_value(t38, t7, 0, 0, 32);
    goto LAB19;

LAB11:    xsi_set_current_line(41, ng0);

LAB22:    xsi_set_current_line(42, ng0);
    t4 = ((char*)((ng6)));
    t5 = (t0 + 1728U);
    t9 = *((char **)t5);
    memset(t8, 0, 8);
    t5 = (t8 + 4);
    t17 = (t9 + 4);
    t10 = *((unsigned int *)t9);
    t11 = (t10 >> 31);
    t12 = (t11 & 1);
    *((unsigned int *)t8) = t12;
    t13 = *((unsigned int *)t17);
    t14 = (t13 >> 31);
    t15 = (t14 & 1);
    *((unsigned int *)t5) = t15;
    xsi_vlog_mul_concat(t7, 19, 1, t4, 1U, t8, 1);
    t18 = (t0 + 2288);
    t19 = (t0 + 2288);
    t21 = (t19 + 72U);
    t28 = *((char **)t21);
    t29 = ((char*)((ng7)));
    t31 = ((char*)((ng8)));
    xsi_vlog_convert_partindices(t16, t20, t30, ((int*)(t28)), 2, t29, 32, 1, t31, 32, 1);
    t38 = (t16 + 4);
    t22 = *((unsigned int *)t38);
    t39 = (!(t22));
    t40 = (t20 + 4);
    t23 = *((unsigned int *)t40);
    t41 = (!(t23));
    t42 = (t39 && t41);
    t43 = (t30 + 4);
    t24 = *((unsigned int *)t43);
    t44 = (!(t24));
    t45 = (t42 && t44);
    if (t45 == 1)
        goto LAB23;

LAB24:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 1728U);
    t4 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t5 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 31);
    t12 = (t11 & 1);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t5);
    t14 = (t13 >> 31);
    t15 = (t14 & 1);
    *((unsigned int *)t2) = t15;
    t9 = (t0 + 2288);
    t17 = (t0 + 2288);
    t18 = (t17 + 72U);
    t19 = *((char **)t18);
    t21 = ((char*)((ng9)));
    xsi_vlog_generic_convert_bit_index(t8, t19, 2, t21, 32, 1);
    t28 = (t8 + 4);
    t22 = *((unsigned int *)t28);
    t6 = (!(t22));
    if (t6 == 1)
        goto LAB25;

LAB26:    xsi_set_current_line(44, ng0);
    t2 = (t0 + 1728U);
    t4 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t5 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 7);
    t12 = (t11 & 1);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t5);
    t14 = (t13 >> 7);
    t15 = (t14 & 1);
    *((unsigned int *)t2) = t15;
    t9 = (t0 + 2288);
    t17 = (t0 + 2288);
    t18 = (t17 + 72U);
    t19 = *((char **)t18);
    t21 = ((char*)((ng10)));
    xsi_vlog_generic_convert_bit_index(t8, t19, 2, t21, 32, 1);
    t28 = (t8 + 4);
    t22 = *((unsigned int *)t28);
    t6 = (!(t22));
    if (t6 == 1)
        goto LAB27;

LAB28:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 1728U);
    t4 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t5 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 25);
    *((unsigned int *)t7) = t11;
    t12 = *((unsigned int *)t5);
    t13 = (t12 >> 25);
    *((unsigned int *)t2) = t13;
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 & 63U);
    t15 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t15 & 63U);
    t9 = (t0 + 2288);
    t17 = (t0 + 2288);
    t18 = (t17 + 72U);
    t19 = *((char **)t18);
    t21 = ((char*)((ng11)));
    t28 = ((char*)((ng12)));
    xsi_vlog_convert_partindices(t8, t16, t20, ((int*)(t19)), 2, t21, 32, 1, t28, 32, 1);
    t29 = (t8 + 4);
    t22 = *((unsigned int *)t29);
    t6 = (!(t22));
    t31 = (t16 + 4);
    t23 = *((unsigned int *)t31);
    t39 = (!(t23));
    t41 = (t6 && t39);
    t38 = (t20 + 4);
    t24 = *((unsigned int *)t38);
    t42 = (!(t24));
    t44 = (t41 && t42);
    if (t44 == 1)
        goto LAB29;

LAB30:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 1728U);
    t4 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t5 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 8);
    *((unsigned int *)t7) = t11;
    t12 = *((unsigned int *)t5);
    t13 = (t12 >> 8);
    *((unsigned int *)t2) = t13;
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 & 15U);
    t15 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t15 & 15U);
    t9 = (t0 + 2288);
    t17 = (t0 + 2288);
    t18 = (t17 + 72U);
    t19 = *((char **)t18);
    t21 = ((char*)((ng13)));
    t28 = ((char*)((ng14)));
    xsi_vlog_convert_partindices(t8, t16, t20, ((int*)(t19)), 2, t21, 32, 1, t28, 32, 1);
    t29 = (t8 + 4);
    t22 = *((unsigned int *)t29);
    t6 = (!(t22));
    t31 = (t16 + 4);
    t23 = *((unsigned int *)t31);
    t39 = (!(t23));
    t41 = (t6 && t39);
    t38 = (t20 + 4);
    t24 = *((unsigned int *)t38);
    t42 = (!(t24));
    t44 = (t41 && t42);
    if (t44 == 1)
        goto LAB31;

LAB32:    xsi_set_current_line(47, ng0);
    t2 = ((char*)((ng2)));
    t4 = (t0 + 2288);
    t5 = (t0 + 2288);
    t9 = (t5 + 72U);
    t17 = *((char **)t9);
    t18 = ((char*)((ng1)));
    xsi_vlog_generic_convert_bit_index(t7, t17, 2, t18, 32, 1);
    t19 = (t7 + 4);
    t10 = *((unsigned int *)t19);
    t6 = (!(t10));
    if (t6 == 1)
        goto LAB33;

LAB34:    goto LAB19;

LAB13:    xsi_set_current_line(49, ng0);

LAB35:    xsi_set_current_line(50, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t0 + 1728U);
    t9 = *((char **)t5);
    memset(t8, 0, 8);
    t5 = (t8 + 4);
    t17 = (t9 + 4);
    t10 = *((unsigned int *)t9);
    t11 = (t10 >> 12);
    *((unsigned int *)t8) = t11;
    t12 = *((unsigned int *)t17);
    t13 = (t12 >> 12);
    *((unsigned int *)t5) = t13;
    t14 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t14 & 1048575U);
    t15 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t15 & 1048575U);
    xsi_vlogtype_concat(t7, 32, 32, 2U, t8, 20, t4, 12);
    t18 = (t0 + 2288);
    xsi_vlogvar_assign_value(t18, t7, 0, 0, 32);
    goto LAB19;

LAB15:    xsi_set_current_line(52, ng0);

LAB36:    xsi_set_current_line(53, ng0);
    t4 = ((char*)((ng10)));
    t5 = (t0 + 1728U);
    t9 = *((char **)t5);
    memset(t8, 0, 8);
    t5 = (t8 + 4);
    t17 = (t9 + 4);
    t10 = *((unsigned int *)t9);
    t11 = (t10 >> 31);
    t12 = (t11 & 1);
    *((unsigned int *)t8) = t12;
    t13 = *((unsigned int *)t17);
    t14 = (t13 >> 31);
    t15 = (t14 & 1);
    *((unsigned int *)t5) = t15;
    xsi_vlog_mul_concat(t7, 11, 1, t4, 1U, t8, 1);
    t18 = (t0 + 2288);
    t19 = (t0 + 2288);
    t21 = (t19 + 72U);
    t28 = *((char **)t21);
    t29 = ((char*)((ng7)));
    t31 = ((char*)((ng17)));
    xsi_vlog_convert_partindices(t16, t20, t30, ((int*)(t28)), 2, t29, 32, 1, t31, 32, 1);
    t38 = (t16 + 4);
    t22 = *((unsigned int *)t38);
    t39 = (!(t22));
    t40 = (t20 + 4);
    t23 = *((unsigned int *)t40);
    t41 = (!(t23));
    t42 = (t39 && t41);
    t43 = (t30 + 4);
    t24 = *((unsigned int *)t43);
    t44 = (!(t24));
    t45 = (t42 && t44);
    if (t45 == 1)
        goto LAB37;

LAB38:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 1728U);
    t4 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t5 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 31);
    t12 = (t11 & 1);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t5);
    t14 = (t13 >> 31);
    t15 = (t14 & 1);
    *((unsigned int *)t2) = t15;
    t9 = (t0 + 2288);
    t17 = (t0 + 2288);
    t18 = (t17 + 72U);
    t19 = *((char **)t18);
    t21 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t8, t19, 2, t21, 32, 1);
    t28 = (t8 + 4);
    t22 = *((unsigned int *)t28);
    t6 = (!(t22));
    if (t6 == 1)
        goto LAB39;

LAB40:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 1728U);
    t4 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t5 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 12);
    *((unsigned int *)t7) = t11;
    t12 = *((unsigned int *)t5);
    t13 = (t12 >> 12);
    *((unsigned int *)t2) = t13;
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 & 255U);
    t15 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t15 & 255U);
    t9 = (t0 + 2288);
    t17 = (t0 + 2288);
    t18 = (t17 + 72U);
    t19 = *((char **)t18);
    t21 = ((char*)((ng6)));
    t28 = ((char*)((ng9)));
    xsi_vlog_convert_partindices(t8, t16, t20, ((int*)(t19)), 2, t21, 32, 1, t28, 32, 1);
    t29 = (t8 + 4);
    t22 = *((unsigned int *)t29);
    t6 = (!(t22));
    t31 = (t16 + 4);
    t23 = *((unsigned int *)t31);
    t39 = (!(t23));
    t41 = (t6 && t39);
    t38 = (t20 + 4);
    t24 = *((unsigned int *)t38);
    t42 = (!(t24));
    t44 = (t41 && t42);
    if (t44 == 1)
        goto LAB41;

LAB42:    xsi_set_current_line(56, ng0);
    t2 = (t0 + 1728U);
    t4 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t5 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 20);
    t12 = (t11 & 1);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t5);
    t14 = (t13 >> 20);
    t15 = (t14 & 1);
    *((unsigned int *)t2) = t15;
    t9 = (t0 + 2288);
    t17 = (t0 + 2288);
    t18 = (t17 + 72U);
    t19 = *((char **)t18);
    t21 = ((char*)((ng10)));
    xsi_vlog_generic_convert_bit_index(t8, t19, 2, t21, 32, 1);
    t28 = (t8 + 4);
    t22 = *((unsigned int *)t28);
    t6 = (!(t22));
    if (t6 == 1)
        goto LAB43;

LAB44:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 1728U);
    t4 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t5 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 21);
    *((unsigned int *)t7) = t11;
    t12 = *((unsigned int *)t5);
    t13 = (t12 >> 21);
    *((unsigned int *)t2) = t13;
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 & 1023U);
    t15 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t15 & 1023U);
    t9 = (t0 + 2288);
    t17 = (t0 + 2288);
    t18 = (t17 + 72U);
    t19 = *((char **)t18);
    t21 = ((char*)((ng11)));
    t28 = ((char*)((ng14)));
    xsi_vlog_convert_partindices(t8, t16, t20, ((int*)(t19)), 2, t21, 32, 1, t28, 32, 1);
    t29 = (t8 + 4);
    t22 = *((unsigned int *)t29);
    t6 = (!(t22));
    t31 = (t16 + 4);
    t23 = *((unsigned int *)t31);
    t39 = (!(t23));
    t41 = (t6 && t39);
    t38 = (t20 + 4);
    t24 = *((unsigned int *)t38);
    t42 = (!(t24));
    t44 = (t41 && t42);
    if (t44 == 1)
        goto LAB45;

LAB46:    xsi_set_current_line(58, ng0);
    t2 = ((char*)((ng2)));
    t4 = (t0 + 2288);
    t5 = (t0 + 2288);
    t9 = (t5 + 72U);
    t17 = *((char **)t9);
    t18 = ((char*)((ng1)));
    xsi_vlog_generic_convert_bit_index(t7, t17, 2, t18, 32, 1);
    t19 = (t7 + 4);
    t10 = *((unsigned int *)t19);
    t6 = (!(t10));
    if (t6 == 1)
        goto LAB47;

LAB48:    goto LAB19;

LAB23:    t25 = *((unsigned int *)t30);
    t46 = (t25 + 0);
    t26 = *((unsigned int *)t16);
    t27 = *((unsigned int *)t20);
    t47 = (t26 - t27);
    t48 = (t47 + 1);
    xsi_vlogvar_assign_value(t18, t7, t46, *((unsigned int *)t20), t48);
    goto LAB24;

LAB25:    xsi_vlogvar_assign_value(t9, t7, 0, *((unsigned int *)t8), 1);
    goto LAB26;

LAB27:    xsi_vlogvar_assign_value(t9, t7, 0, *((unsigned int *)t8), 1);
    goto LAB28;

LAB29:    t25 = *((unsigned int *)t20);
    t45 = (t25 + 0);
    t26 = *((unsigned int *)t8);
    t27 = *((unsigned int *)t16);
    t46 = (t26 - t27);
    t47 = (t46 + 1);
    xsi_vlogvar_assign_value(t9, t7, t45, *((unsigned int *)t16), t47);
    goto LAB30;

LAB31:    t25 = *((unsigned int *)t20);
    t45 = (t25 + 0);
    t26 = *((unsigned int *)t8);
    t27 = *((unsigned int *)t16);
    t46 = (t26 - t27);
    t47 = (t46 + 1);
    xsi_vlogvar_assign_value(t9, t7, t45, *((unsigned int *)t16), t47);
    goto LAB32;

LAB33:    xsi_vlogvar_assign_value(t4, t2, 0, *((unsigned int *)t7), 1);
    goto LAB34;

LAB37:    t25 = *((unsigned int *)t30);
    t46 = (t25 + 0);
    t26 = *((unsigned int *)t16);
    t27 = *((unsigned int *)t20);
    t47 = (t26 - t27);
    t48 = (t47 + 1);
    xsi_vlogvar_assign_value(t18, t7, t46, *((unsigned int *)t20), t48);
    goto LAB38;

LAB39:    xsi_vlogvar_assign_value(t9, t7, 0, *((unsigned int *)t8), 1);
    goto LAB40;

LAB41:    t25 = *((unsigned int *)t20);
    t45 = (t25 + 0);
    t26 = *((unsigned int *)t8);
    t27 = *((unsigned int *)t16);
    t46 = (t26 - t27);
    t47 = (t46 + 1);
    xsi_vlogvar_assign_value(t9, t7, t45, *((unsigned int *)t16), t47);
    goto LAB42;

LAB43:    xsi_vlogvar_assign_value(t9, t7, 0, *((unsigned int *)t8), 1);
    goto LAB44;

LAB45:    t25 = *((unsigned int *)t20);
    t45 = (t25 + 0);
    t26 = *((unsigned int *)t8);
    t27 = *((unsigned int *)t16);
    t46 = (t26 - t27);
    t47 = (t46 + 1);
    xsi_vlogvar_assign_value(t9, t7, t45, *((unsigned int *)t16), t47);
    goto LAB46;

LAB47:    xsi_vlogvar_assign_value(t4, t2, 0, *((unsigned int *)t7), 1);
    goto LAB48;

}


extern void work_m_17441793534667333270_1747155116_init()
{
	static char *pe[] = {(void *)Always_32_0};
	xsi_register_didat("work_m_17441793534667333270_1747155116", "isim/immediate_generator_tb_isim_beh.exe.sim/work/m_17441793534667333270_1747155116.didat");
	xsi_register_executes(pe);
}
