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
static const char *ng0 = "/home/ise/Desktop/LED_PATTERNS/led_patterns/edge_detector.v";
static int ng1[] = {0, 0};



static void Always_33_0(char *t0)
{
    char t4[8];
    char t25[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
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
    char *t24;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    int t48;
    int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;

LAB0:    t1 = (t0 + 3320U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(33, ng0);
    t2 = (t0 + 4136);
    *((int *)t2) = 1;
    t3 = (t0 + 3352);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(33, ng0);

LAB5:    xsi_set_current_line(34, ng0);
    t5 = (t0 + 1208U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t5 = (t6 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t5) == 0)
        goto LAB6;

LAB8:    t12 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t12) = 1;

LAB9:    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t4);
    t17 = (t16 & t15);
    t18 = (t17 != 0);
    if (t18 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(40, ng0);

LAB14:    xsi_set_current_line(41, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(42, ng0);
    t2 = (t0 + 2088);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    memset(t4, 0, 8);
    t6 = (t5 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB18;

LAB16:    if (*((unsigned int *)t6) == 0)
        goto LAB15;

LAB17:    t12 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t12) = 1;

LAB18:    t13 = (t4 + 4);
    t19 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = (~(t14));
    *((unsigned int *)t4) = t15;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t19) != 0)
        goto LAB20;

LAB19:    t22 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t22 & 1U);
    t23 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t23 & 1U);
    t20 = (t0 + 1368U);
    t24 = *((char **)t20);
    t26 = *((unsigned int *)t4);
    t27 = *((unsigned int *)t24);
    t28 = (t26 & t27);
    *((unsigned int *)t25) = t28;
    t20 = (t4 + 4);
    t29 = (t24 + 4);
    t30 = (t25 + 4);
    t31 = *((unsigned int *)t20);
    t32 = *((unsigned int *)t29);
    t33 = (t31 | t32);
    *((unsigned int *)t30) = t33;
    t34 = *((unsigned int *)t30);
    t35 = (t34 != 0);
    if (t35 == 1)
        goto LAB21;

LAB22:
LAB23:    t56 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t56, t25, 0, 0, 1, 0LL);
    xsi_set_current_line(43, ng0);
    t2 = (t0 + 2088);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 1368U);
    t12 = *((char **)t6);
    memset(t4, 0, 8);
    t6 = (t12 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t12);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB27;

LAB25:    if (*((unsigned int *)t6) == 0)
        goto LAB24;

LAB26:    t13 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t13) = 1;

LAB27:    t19 = (t4 + 4);
    t20 = (t12 + 4);
    t14 = *((unsigned int *)t12);
    t15 = (~(t14));
    *((unsigned int *)t4) = t15;
    *((unsigned int *)t19) = 0;
    if (*((unsigned int *)t20) != 0)
        goto LAB29;

LAB28:    t22 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t22 & 1U);
    t23 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t23 & 1U);
    t26 = *((unsigned int *)t5);
    t27 = *((unsigned int *)t4);
    t28 = (t26 & t27);
    *((unsigned int *)t25) = t28;
    t24 = (t5 + 4);
    t29 = (t4 + 4);
    t30 = (t25 + 4);
    t31 = *((unsigned int *)t24);
    t32 = *((unsigned int *)t29);
    t33 = (t31 | t32);
    *((unsigned int *)t30) = t33;
    t34 = *((unsigned int *)t30);
    t35 = (t34 != 0);
    if (t35 == 1)
        goto LAB30;

LAB31:
LAB32:    t56 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t56, t25, 0, 0, 1, 0LL);

LAB12:    goto LAB2;

LAB6:    *((unsigned int *)t4) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(34, ng0);

LAB13:    xsi_set_current_line(35, ng0);
    t19 = ((char*)((ng1)));
    t20 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t20, t19, 0, 0, 1, 0LL);
    xsi_set_current_line(36, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(37, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB12;

LAB15:    *((unsigned int *)t4) = 1;
    goto LAB18;

LAB20:    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t19);
    *((unsigned int *)t4) = (t16 | t17);
    t18 = *((unsigned int *)t13);
    t21 = *((unsigned int *)t19);
    *((unsigned int *)t13) = (t18 | t21);
    goto LAB19;

LAB21:    t36 = *((unsigned int *)t25);
    t37 = *((unsigned int *)t30);
    *((unsigned int *)t25) = (t36 | t37);
    t38 = (t4 + 4);
    t39 = (t24 + 4);
    t40 = *((unsigned int *)t4);
    t41 = (~(t40));
    t42 = *((unsigned int *)t38);
    t43 = (~(t42));
    t44 = *((unsigned int *)t24);
    t45 = (~(t44));
    t46 = *((unsigned int *)t39);
    t47 = (~(t46));
    t48 = (t41 & t43);
    t49 = (t45 & t47);
    t50 = (~(t48));
    t51 = (~(t49));
    t52 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t52 & t50);
    t53 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t53 & t51);
    t54 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t54 & t50);
    t55 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t55 & t51);
    goto LAB23;

LAB24:    *((unsigned int *)t4) = 1;
    goto LAB27;

LAB29:    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t20);
    *((unsigned int *)t4) = (t16 | t17);
    t18 = *((unsigned int *)t19);
    t21 = *((unsigned int *)t20);
    *((unsigned int *)t19) = (t18 | t21);
    goto LAB28;

LAB30:    t36 = *((unsigned int *)t25);
    t37 = *((unsigned int *)t30);
    *((unsigned int *)t25) = (t36 | t37);
    t38 = (t5 + 4);
    t39 = (t4 + 4);
    t40 = *((unsigned int *)t5);
    t41 = (~(t40));
    t42 = *((unsigned int *)t38);
    t43 = (~(t42));
    t44 = *((unsigned int *)t4);
    t45 = (~(t44));
    t46 = *((unsigned int *)t39);
    t47 = (~(t46));
    t48 = (t41 & t43);
    t49 = (t45 & t47);
    t50 = (~(t48));
    t51 = (~(t49));
    t52 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t52 & t50);
    t53 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t53 & t51);
    t54 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t54 & t50);
    t55 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t55 & t51);
    goto LAB32;

}

static void Cont_47_1(char *t0)
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

LAB0:    t1 = (t0 + 3568U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 2248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4248);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1U;
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
    xsi_driver_vfirst_trans(t5, 0, 0);
    t18 = (t0 + 4152);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_48_2(char *t0)
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

LAB0:    t1 = (t0 + 3816U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 2408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4312);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1U;
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
    xsi_driver_vfirst_trans(t5, 0, 0);
    t18 = (t0 + 4168);
    *((int *)t18) = 1;

LAB1:    return;
}


extern void work_m_09083878758799696133_4129626524_init()
{
	static char *pe[] = {(void *)Always_33_0,(void *)Cont_47_1,(void *)Cont_48_2};
	xsi_register_didat("work_m_09083878758799696133_4129626524", "isim/everything_tb_isim_beh.exe.sim/work/m_09083878758799696133_4129626524.didat");
	xsi_register_executes(pe);
}
