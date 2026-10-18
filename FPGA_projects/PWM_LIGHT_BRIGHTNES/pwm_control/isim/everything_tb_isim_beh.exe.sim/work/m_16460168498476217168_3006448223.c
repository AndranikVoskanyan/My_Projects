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
static const char *ng0 = "/home/ise/Desktop/PWM_LIGHT_BRIGHTNES/pwm_control/brightness_control.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {255U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {3U, 0U};



static void Cont_33_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;

LAB0:    t1 = (t0 + 3272U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(33, ng0);
    t2 = (t0 + 1800U);
    t3 = *((char **)t2);
    t2 = (t0 + 4200);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t2, 0, 0);
    t16 = (t0 + 4088);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Cont_34_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;

LAB0:    t1 = (t0 + 3520U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(34, ng0);
    t2 = (t0 + 1640U);
    t3 = *((char **)t2);
    t2 = (t0 + 4264);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t2, 1, 1);
    t16 = (t0 + 4104);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Always_35_2(char *t0)
{
    char t14[8];
    char t15[8];
    char t17[8];
    char t31[8];
    char t32[8];
    char t37[8];
    char t69[8];
    char t70[8];
    char t80[8];
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
    int t13;
    char *t16;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
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
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    char *t65;
    char *t66;
    char *t67;
    char *t68;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;

LAB0:    t1 = (t0 + 3768U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(35, ng0);
    t2 = (t0 + 4120);
    *((int *)t2) = 1;
    t3 = (t0 + 3800);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(35, ng0);

LAB5:    xsi_set_current_line(36, ng0);
    t4 = (t0 + 1480U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(39, ng0);

LAB10:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 1960U);
    t3 = *((char **)t2);

LAB11:    t2 = ((char*)((ng1)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 2, t2, 2);
    if (t13 == 1)
        goto LAB12;

LAB13:    t2 = ((char*)((ng2)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 2, t2, 2);
    if (t13 == 1)
        goto LAB14;

LAB15:    t2 = ((char*)((ng4)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 2, t2, 2);
    if (t13 == 1)
        goto LAB16;

LAB17:    t2 = ((char*)((ng5)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 2, t2, 2);
    if (t13 == 1)
        goto LAB18;

LAB19:
LAB21:
LAB20:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 2360);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t11 = (t0 + 2360);
    xsi_vlogvar_wait_assign_value(t11, t5, 0, 0, 8, 0LL);

LAB22:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(36, ng0);

LAB9:    xsi_set_current_line(37, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2360);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 8, 0LL);
    goto LAB8;

LAB12:    xsi_set_current_line(41, ng0);
    t4 = (t0 + 2360);
    t5 = (t4 + 56U);
    t11 = *((char **)t5);
    t12 = (t0 + 2360);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 8, 0LL);
    goto LAB22;

LAB14:    xsi_set_current_line(42, ng0);
    t4 = (t0 + 2360);
    t5 = (t4 + 56U);
    t11 = *((char **)t5);
    t12 = (t0 + 608);
    t16 = *((char **)t12);
    memset(t17, 0, 8);
    t12 = (t11 + 4);
    if (*((unsigned int *)t12) != 0)
        goto LAB24;

LAB23:    t18 = (t16 + 4);
    if (*((unsigned int *)t18) != 0)
        goto LAB24;

LAB27:    if (*((unsigned int *)t11) > *((unsigned int *)t16))
        goto LAB26;

LAB25:    *((unsigned int *)t17) = 1;

LAB26:    memset(t15, 0, 8);
    t20 = (t17 + 4);
    t6 = *((unsigned int *)t20);
    t7 = (~(t6));
    t8 = *((unsigned int *)t17);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB28;

LAB29:    if (*((unsigned int *)t20) != 0)
        goto LAB30;

LAB31:    t22 = (t15 + 4);
    t23 = *((unsigned int *)t15);
    t24 = *((unsigned int *)t22);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB32;

LAB33:    t27 = *((unsigned int *)t15);
    t28 = (~(t27));
    t29 = *((unsigned int *)t22);
    t30 = (t28 || t29);
    if (t30 > 0)
        goto LAB34;

LAB35:    if (*((unsigned int *)t22) > 0)
        goto LAB36;

LAB37:    if (*((unsigned int *)t15) > 0)
        goto LAB38;

LAB39:    memcpy(t14, t31, 8);

LAB40:    t78 = (t0 + 2360);
    xsi_vlogvar_wait_assign_value(t78, t14, 0, 0, 8, 0LL);
    goto LAB22;

LAB16:    xsi_set_current_line(47, ng0);
    t4 = (t0 + 2360);
    t5 = (t4 + 56U);
    t11 = *((char **)t5);
    t12 = ((char*)((ng3)));
    t16 = (t0 + 608);
    t18 = *((char **)t16);
    memset(t17, 0, 8);
    xsi_vlog_unsigned_minus(t17, 32, t12, 32, t18, 32);
    memset(t31, 0, 8);
    t16 = (t11 + 4);
    if (*((unsigned int *)t16) != 0)
        goto LAB59;

LAB58:    t19 = (t17 + 4);
    if (*((unsigned int *)t19) != 0)
        goto LAB59;

LAB62:    if (*((unsigned int *)t11) > *((unsigned int *)t17))
        goto LAB61;

LAB60:    *((unsigned int *)t31) = 1;

LAB61:    memset(t15, 0, 8);
    t21 = (t31 + 4);
    t6 = *((unsigned int *)t21);
    t7 = (~(t6));
    t8 = *((unsigned int *)t31);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB63;

LAB64:    if (*((unsigned int *)t21) != 0)
        goto LAB65;

LAB66:    t26 = (t15 + 4);
    t23 = *((unsigned int *)t15);
    t24 = *((unsigned int *)t26);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB67;

LAB68:    t27 = *((unsigned int *)t15);
    t28 = (~(t27));
    t29 = *((unsigned int *)t26);
    t30 = (t28 || t29);
    if (t30 > 0)
        goto LAB69;

LAB70:    if (*((unsigned int *)t26) > 0)
        goto LAB71;

LAB72:    if (*((unsigned int *)t15) > 0)
        goto LAB73;

LAB74:    memcpy(t14, t36, 8);

LAB75:    t39 = (t0 + 2360);
    xsi_vlogvar_wait_assign_value(t39, t14, 0, 0, 8, 0LL);
    goto LAB22;

LAB18:    xsi_set_current_line(48, ng0);
    t4 = (t0 + 2360);
    t5 = (t4 + 56U);
    t11 = *((char **)t5);
    t12 = (t0 + 2360);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 8, 0LL);
    goto LAB22;

LAB24:    t19 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB26;

LAB28:    *((unsigned int *)t15) = 1;
    goto LAB31;

LAB30:    t21 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB31;

LAB32:    t26 = ((char*)((ng1)));
    goto LAB33;

LAB34:    t33 = (t0 + 2360);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    t36 = ((char*)((ng3)));
    memset(t37, 0, 8);
    t38 = (t35 + 4);
    t39 = (t36 + 4);
    t40 = *((unsigned int *)t35);
    t41 = *((unsigned int *)t36);
    t42 = (t40 ^ t41);
    t43 = *((unsigned int *)t38);
    t44 = *((unsigned int *)t39);
    t45 = (t43 ^ t44);
    t46 = (t42 | t45);
    t47 = *((unsigned int *)t38);
    t48 = *((unsigned int *)t39);
    t49 = (t47 | t48);
    t50 = (~(t49));
    t51 = (t46 & t50);
    if (t51 != 0)
        goto LAB44;

LAB41:    if (t49 != 0)
        goto LAB43;

LAB42:    *((unsigned int *)t37) = 1;

LAB44:    memset(t32, 0, 8);
    t53 = (t37 + 4);
    t54 = *((unsigned int *)t53);
    t55 = (~(t54));
    t56 = *((unsigned int *)t37);
    t57 = (t56 & t55);
    t58 = (t57 & 1U);
    if (t58 != 0)
        goto LAB45;

LAB46:    if (*((unsigned int *)t53) != 0)
        goto LAB47;

LAB48:    t60 = (t32 + 4);
    t61 = *((unsigned int *)t32);
    t62 = *((unsigned int *)t60);
    t63 = (t61 || t62);
    if (t63 > 0)
        goto LAB49;

LAB50:    t71 = *((unsigned int *)t32);
    t72 = (~(t71));
    t73 = *((unsigned int *)t60);
    t74 = (t72 || t73);
    if (t74 > 0)
        goto LAB51;

LAB52:    if (*((unsigned int *)t60) > 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t32) > 0)
        goto LAB55;

LAB56:    memcpy(t31, t80, 8);

LAB57:    goto LAB35;

LAB36:    xsi_vlog_unsigned_bit_combine(t14, 32, t26, 32, t31, 32);
    goto LAB40;

LAB38:    memcpy(t14, t26, 8);
    goto LAB40;

LAB43:    t52 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t52) = 1;
    goto LAB44;

LAB45:    *((unsigned int *)t32) = 1;
    goto LAB48;

LAB47:    t59 = (t32 + 4);
    *((unsigned int *)t32) = 1;
    *((unsigned int *)t59) = 1;
    goto LAB48;

LAB49:    t64 = (t0 + 2360);
    t65 = (t64 + 56U);
    t66 = *((char **)t65);
    t67 = (t0 + 608);
    t68 = *((char **)t67);
    memset(t69, 0, 8);
    xsi_vlog_unsigned_minus(t69, 32, t66, 8, t68, 32);
    t67 = ((char*)((ng2)));
    memset(t70, 0, 8);
    xsi_vlog_unsigned_add(t70, 32, t69, 32, t67, 32);
    goto LAB50;

LAB51:    t75 = (t0 + 2360);
    t76 = (t75 + 56U);
    t77 = *((char **)t76);
    t78 = (t0 + 608);
    t79 = *((char **)t78);
    memset(t80, 0, 8);
    xsi_vlog_unsigned_minus(t80, 32, t77, 8, t79, 32);
    goto LAB52;

LAB53:    xsi_vlog_unsigned_bit_combine(t31, 32, t70, 32, t80, 32);
    goto LAB57;

LAB55:    memcpy(t31, t70, 8);
    goto LAB57;

LAB59:    t20 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB61;

LAB63:    *((unsigned int *)t15) = 1;
    goto LAB66;

LAB65:    t22 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB66;

LAB67:    t33 = (t0 + 2360);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    t36 = (t0 + 608);
    t38 = *((char **)t36);
    memset(t32, 0, 8);
    xsi_vlog_unsigned_add(t32, 32, t35, 8, t38, 32);
    goto LAB68;

LAB69:    t36 = ((char*)((ng3)));
    goto LAB70;

LAB71:    xsi_vlog_unsigned_bit_combine(t14, 32, t32, 32, t36, 32);
    goto LAB75;

LAB73:    memcpy(t14, t32, 8);
    goto LAB75;

}


extern void work_m_16460168498476217168_3006448223_init()
{
	static char *pe[] = {(void *)Cont_33_0,(void *)Cont_34_1,(void *)Always_35_2};
	xsi_register_didat("work_m_16460168498476217168_3006448223", "isim/everything_tb_isim_beh.exe.sim/work/m_16460168498476217168_3006448223.didat");
	xsi_register_executes(pe);
}
