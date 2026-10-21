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
static const char *ng0 = "/home/ise/Desktop/RISC_V/instruction_decoder_tb.v";
static int ng1[] = {1, 0};
static const char *ng2 = "FAIL %s";
static const char *ng3 = "  Instruction=%h";
static const char *ng4 = "  Reconstructed=%h";
static const char *ng5 = "  opcode=%h rd=%h funct3=%h";
static const char *ng6 = "  rs1=%h rs2=%h funct7=%h";
static const char *ng7 = "PASS %s";
static unsigned int ng8[] = {0U, 0U};
static int ng9[] = {0, 0};
static int ng10[] = {1701998451, 0, 1819025530, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng11[] = {1869505907, 0, 1097624608, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng12[] = {4294967295U, 0U};
static int ng13[] = {1852252225, 0, 1851880553, 0, 1819567474, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng14[] = {2863311530U, 0U};
static int ng15[] = {1852252213, 0, 1851880553, 0, 1819567474, 0, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng16[] = {1431655765U, 0U};
static int ng17[] = {1668244581, 0, 2032168816, 0, 5205612, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng18[] = {127U, 0U};
static int ng19[] = {2032169572, 0, 5205612, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng20[] = {3968U, 0U};
static int ng21[] = {1852011571, 0, 2032166517, 0, 5205612, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng22[] = {28672U, 0U};
static int ng23[] = {544371505, 0, 1332636793, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng24[] = {1015808U, 0U};
static int ng25[] = {544371506, 0, 1332636793, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng26[] = {32505856U, 0U};
static int ng27[] = {1852011575, 0, 2032166517, 0, 5205612, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng28[] = {4261412864U, 0U};
static int ng29[] = {2016422965, 0, 544747820, 0, 1094992969, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng30[] = {5243027U, 0U};
static int ng31[] = {824997938, 0, 2016619640, 0, 1094992928, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng32[] = {2130355U, 0U};
static int ng33[] = {842216501, 0, 741374001, 0, 1226864689, 0, 19541, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng34[] = {305418423U, 0U};
static int ng35[] = {1128352844, 0, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng36[] = {115U, 0U};
static int ng37[] = {1380270411, 0, 17730, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng38[] = {1048691U, 0U};
static unsigned int ng39[] = {2900471820U, 0U};
static int ng40[] = {64, 0};
static int ng41[] = {1952805748, 0, 1701998112, 0, 1885434996, 0, 1114207277, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static const char *ng42 = "--------------------------------------";
static const char *ng43 = "Tests: %0d Passed: %0d Failed: %0d";
static const char *ng44 = "INSTRUCTION DECODER TEST PASSED";
static const char *ng45 = "INSTRUCTION DECODER TEST FAILED";



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

LAB2:    t4 = (t1 + 848);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(32, ng0);

LAB5:    xsi_set_current_line(33, ng0);
    t5 = (t1 + 3800);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t1 + 2840);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    xsi_set_current_line(34, ng0);
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

LAB6:    xsi_set_current_line(35, ng0);
    t4 = (t1 + 3000);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    memset(t9, 0, 8);
    xsi_vlog_signed_add(t9, 32, t6, 32, t7, 32);
    t8 = (t1 + 3000);
    xsi_vlogvar_assign_value(t8, t9, 0, 0, 32);
    xsi_set_current_line(37, ng0);
    t4 = (t1 + 2440U);
    t5 = *((char **)t4);
    t4 = (t1 + 3800);
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

LAB11:    xsi_set_current_line(49, ng0);
    t4 = (t1 + 3640);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng7, 2, t7, (char)118, t6, 256);

LAB12:    goto LAB4;

LAB8:    *((unsigned int *)t9) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(37, ng0);

LAB13:    xsi_set_current_line(38, ng0);
    t17 = (t1 + 3160);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = ((char*)((ng1)));
    memset(t21, 0, 8);
    xsi_vlog_signed_add(t21, 32, t19, 32, t20, 32);
    t22 = (t1 + 3160);
    xsi_vlogvar_assign_value(t22, t21, 0, 0, 32);
    xsi_set_current_line(40, ng0);
    t4 = (t1 + 3640);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng2, 2, t7, (char)118, t6, 256);
    xsi_set_current_line(41, ng0);
    t4 = (t1 + 3800);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng3, 2, t7, (char)118, t6, 32);
    xsi_set_current_line(42, ng0);
    t4 = (t1 + 2440U);
    t5 = *((char **)t4);
    t4 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng4, 2, t4, (char)118, t5, 32);
    xsi_set_current_line(43, ng0);
    t4 = (t1 + 1480U);
    t5 = *((char **)t4);
    t4 = (t1 + 1800U);
    t6 = *((char **)t4);
    t4 = (t1 + 2280U);
    t7 = *((char **)t4);
    t4 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng5, 4, t4, (char)118, t5, 7, (char)118, t6, 5, (char)118, t7, 3);
    xsi_set_current_line(45, ng0);
    t4 = (t1 + 1960U);
    t5 = *((char **)t4);
    t4 = (t1 + 2120U);
    t6 = *((char **)t4);
    t4 = (t1 + 1640U);
    t7 = *((char **)t4);
    t4 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng6, 4, t4, (char)118, t5, 5, (char)118, t6, 5, (char)118, t7, 7);
    goto LAB12;

}

static void NetDecl_25_0(char *t0)
{
    char t3[8];
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

LAB0:    t1 = (t0 + 4712U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(25, ng0);
    t2 = (t0 + 1480U);
    t4 = *((char **)t2);
    t2 = (t0 + 1800U);
    t5 = *((char **)t2);
    t2 = (t0 + 2280U);
    t6 = *((char **)t2);
    t2 = (t0 + 1960U);
    t7 = *((char **)t2);
    t2 = (t0 + 2120U);
    t8 = *((char **)t2);
    t2 = (t0 + 1640U);
    t9 = *((char **)t2);
    xsi_vlogtype_concat(t3, 32, 32, 6U, t9, 7, t8, 5, t7, 5, t6, 3, t5, 5, t4, 7);
    t2 = (t0 + 5360);
    t10 = (t2 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t3, 8);
    xsi_driver_vfirst_trans(t2, 0, 31U);
    t14 = (t0 + 5280);
    *((int *)t14) = 1;

LAB1:    return;
}

static void Initial_53_1(char *t0)
{
    char t22[8];
    char t28[8];
    char t29[8];
    char t36[8];
    char t43[8];
    char t56[8];
    char t65[8];
    char t82[8];
    char t91[8];
    char t105[8];
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
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
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
    char *t54;
    char *t55;
    char *t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    char *t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    char *t79;
    char *t80;
    char *t81;
    char *t83;
    char *t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    char *t95;
    char *t96;
    char *t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    char *t106;
    char *t107;
    char *t108;
    char *t109;
    char *t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    char *t117;

LAB0:    t1 = (t0 + 4960U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(53, ng0);

LAB4:    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 2840);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 3000);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 3160);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng10)));
    t3 = ((char*)((ng8)));
    t4 = (t0 + 4768);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3640);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 256);
    t8 = (t0 + 3800);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 32);

LAB7:    t9 = (t0 + 4864);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB9:    if (t17 != 0)
        goto LAB10;

LAB5:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB6:    t18 = (t0 + 4864);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 4768);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(60, ng0);
    t2 = ((char*)((ng11)));
    t3 = ((char*)((ng12)));
    t4 = (t0 + 4768);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3640);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 256);
    t8 = (t0 + 3800);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 32);

LAB13:    t9 = (t0 + 4864);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB15:    if (t17 != 0)
        goto LAB16;

LAB11:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB12:    t18 = (t0 + 4864);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 4768);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng13)));
    t3 = ((char*)((ng14)));
    t4 = (t0 + 4768);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3640);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 256);
    t8 = (t0 + 3800);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 32);

LAB19:    t9 = (t0 + 4864);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB21:    if (t17 != 0)
        goto LAB22;

LAB17:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB18:    t18 = (t0 + 4864);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 4768);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(62, ng0);
    t2 = ((char*)((ng15)));
    t3 = ((char*)((ng16)));
    t4 = (t0 + 4768);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3640);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 256);
    t8 = (t0 + 3800);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 32);

LAB25:    t9 = (t0 + 4864);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB27:    if (t17 != 0)
        goto LAB28;

LAB23:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB24:    t18 = (t0 + 4864);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 4768);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(64, ng0);
    t2 = ((char*)((ng17)));
    t3 = ((char*)((ng18)));
    t4 = (t0 + 4768);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3640);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 256);
    t8 = (t0 + 3800);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 32);

LAB31:    t9 = (t0 + 4864);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB33:    if (t17 != 0)
        goto LAB34;

LAB29:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB30:    t18 = (t0 + 4864);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 4768);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng19)));
    t3 = ((char*)((ng20)));
    t4 = (t0 + 4768);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3640);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 256);
    t8 = (t0 + 3800);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 32);

LAB37:    t9 = (t0 + 4864);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB39:    if (t17 != 0)
        goto LAB40;

LAB35:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB36:    t18 = (t0 + 4864);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 4768);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(66, ng0);
    t2 = ((char*)((ng21)));
    t3 = ((char*)((ng22)));
    t4 = (t0 + 4768);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3640);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 256);
    t8 = (t0 + 3800);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 32);

LAB43:    t9 = (t0 + 4864);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB45:    if (t17 != 0)
        goto LAB46;

LAB41:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB42:    t18 = (t0 + 4864);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 4768);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng23)));
    t3 = ((char*)((ng24)));
    t4 = (t0 + 4768);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3640);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 256);
    t8 = (t0 + 3800);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 32);

LAB49:    t9 = (t0 + 4864);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB51:    if (t17 != 0)
        goto LAB52;

LAB47:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB48:    t18 = (t0 + 4864);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 4768);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng25)));
    t3 = ((char*)((ng26)));
    t4 = (t0 + 4768);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3640);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 256);
    t8 = (t0 + 3800);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 32);

LAB55:    t9 = (t0 + 4864);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB57:    if (t17 != 0)
        goto LAB58;

LAB53:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB54:    t18 = (t0 + 4864);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 4768);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng27)));
    t3 = ((char*)((ng28)));
    t4 = (t0 + 4768);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3640);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 256);
    t8 = (t0 + 3800);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 32);

LAB61:    t9 = (t0 + 4864);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB63:    if (t17 != 0)
        goto LAB64;

LAB59:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB60:    t18 = (t0 + 4864);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 4768);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng29)));
    t3 = ((char*)((ng30)));
    t4 = (t0 + 4768);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3640);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 256);
    t8 = (t0 + 3800);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 32);

LAB67:    t9 = (t0 + 4864);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB69:    if (t17 != 0)
        goto LAB70;

LAB65:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB66:    t18 = (t0 + 4864);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 4768);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(73, ng0);
    t2 = ((char*)((ng31)));
    t3 = ((char*)((ng32)));
    t4 = (t0 + 4768);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3640);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 256);
    t8 = (t0 + 3800);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 32);

LAB73:    t9 = (t0 + 4864);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB75:    if (t17 != 0)
        goto LAB76;

LAB71:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB72:    t18 = (t0 + 4864);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 4768);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng33)));
    t3 = ((char*)((ng34)));
    t4 = (t0 + 4768);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3640);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 256);
    t8 = (t0 + 3800);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 32);

LAB79:    t9 = (t0 + 4864);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB81:    if (t17 != 0)
        goto LAB82;

LAB77:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB78:    t18 = (t0 + 4864);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 4768);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng35)));
    t3 = ((char*)((ng36)));
    t4 = (t0 + 4768);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3640);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 256);
    t8 = (t0 + 3800);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 32);

LAB85:    t9 = (t0 + 4864);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB87:    if (t17 != 0)
        goto LAB88;

LAB83:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB84:    t18 = (t0 + 4864);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 4768);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(76, ng0);
    t2 = ((char*)((ng37)));
    t3 = ((char*)((ng38)));
    t4 = (t0 + 4768);
    t5 = (t0 + 848);
    t6 = xsi_create_subprogram_invocation(t4, 0, t0, t5, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t5, t6);
    t7 = (t0 + 3640);
    xsi_vlogvar_assign_value(t7, t2, 0, 0, 256);
    t8 = (t0 + 3800);
    xsi_vlogvar_assign_value(t8, t3, 0, 0, 32);

LAB91:    t9 = (t0 + 4864);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t12 = *((char **)t11);
    t13 = (t12 + 272U);
    t14 = *((char **)t13);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t17 = ((int  (*)(char *, char *))t16)(t0, t10);

LAB93:    if (t17 != 0)
        goto LAB94;

LAB89:    t10 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t10);

LAB90:    t18 = (t0 + 4864);
    t19 = *((char **)t18);
    t18 = (t0 + 848);
    t20 = (t0 + 4768);
    t21 = 0;
    xsi_delete_subprogram_invocation(t18, t19, t0, t20, t21);
    xsi_set_current_line(79, ng0);
    t2 = ((char*)((ng39)));
    t3 = (t0 + 3480);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(81, ng0);
    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 3320);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB95:    t2 = (t0 + 3320);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng40)));
    memset(t22, 0, 8);
    xsi_vlog_signed_less(t22, 32, t4, 32, t5, 32);
    t6 = (t22 + 4);
    t23 = *((unsigned int *)t6);
    t24 = (~(t23));
    t25 = *((unsigned int *)t22);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB96;

LAB97:    xsi_set_current_line(91, ng0);
    xsi_vlogfile_write(1, 0, 0, ng42, 1, t0);
    xsi_set_current_line(92, ng0);
    t2 = (t0 + 3000);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3000);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 3160);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t22, 0, 8);
    xsi_vlog_signed_minus(t22, 32, t7, 32, t10, 32);
    t11 = (t0 + 3160);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    xsi_vlogfile_write(1, 0, 0, ng43, 4, t0, (char)119, t4, 32, (char)119, t22, 32, (char)119, t13, 32);
    xsi_set_current_line(94, ng0);
    xsi_vlogfile_write(1, 0, 0, ng42, 1, t0);
    xsi_set_current_line(96, ng0);
    t2 = (t0 + 3160);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng9)));
    memset(t22, 0, 8);
    xsi_vlog_signed_equal(t22, 32, t4, 32, t5, 32);
    t6 = (t22 + 4);
    t23 = *((unsigned int *)t6);
    t24 = (~(t23));
    t25 = *((unsigned int *)t22);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB114;

LAB115:    xsi_set_current_line(99, ng0);
    xsi_vlogfile_write(1, 0, 0, ng45, 1, t0);

LAB116:    xsi_set_current_line(101, ng0);
    xsi_vlog_finish(1);

LAB1:    return;
LAB8:;
LAB10:    t9 = (t0 + 4960U);
    *((char **)t9) = &&LAB7;
    goto LAB1;

LAB14:;
LAB16:    t9 = (t0 + 4960U);
    *((char **)t9) = &&LAB13;
    goto LAB1;

LAB20:;
LAB22:    t9 = (t0 + 4960U);
    *((char **)t9) = &&LAB19;
    goto LAB1;

LAB26:;
LAB28:    t9 = (t0 + 4960U);
    *((char **)t9) = &&LAB25;
    goto LAB1;

LAB32:;
LAB34:    t9 = (t0 + 4960U);
    *((char **)t9) = &&LAB31;
    goto LAB1;

LAB38:;
LAB40:    t9 = (t0 + 4960U);
    *((char **)t9) = &&LAB37;
    goto LAB1;

LAB44:;
LAB46:    t9 = (t0 + 4960U);
    *((char **)t9) = &&LAB43;
    goto LAB1;

LAB50:;
LAB52:    t9 = (t0 + 4960U);
    *((char **)t9) = &&LAB49;
    goto LAB1;

LAB56:;
LAB58:    t9 = (t0 + 4960U);
    *((char **)t9) = &&LAB55;
    goto LAB1;

LAB62:;
LAB64:    t9 = (t0 + 4960U);
    *((char **)t9) = &&LAB61;
    goto LAB1;

LAB68:;
LAB70:    t9 = (t0 + 4960U);
    *((char **)t9) = &&LAB67;
    goto LAB1;

LAB74:;
LAB76:    t9 = (t0 + 4960U);
    *((char **)t9) = &&LAB73;
    goto LAB1;

LAB80:;
LAB82:    t9 = (t0 + 4960U);
    *((char **)t9) = &&LAB79;
    goto LAB1;

LAB86:;
LAB88:    t9 = (t0 + 4960U);
    *((char **)t9) = &&LAB85;
    goto LAB1;

LAB92:;
LAB94:    t9 = (t0 + 4960U);
    *((char **)t9) = &&LAB91;
    goto LAB1;

LAB96:    xsi_set_current_line(81, ng0);

LAB98:    xsi_set_current_line(82, ng0);
    t7 = (t0 + 3480);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t29, 0, 8);
    t10 = (t29 + 4);
    t11 = (t9 + 4);
    t30 = *((unsigned int *)t9);
    t31 = (t30 >> 31);
    t32 = (t31 & 1);
    *((unsigned int *)t29) = t32;
    t33 = *((unsigned int *)t11);
    t34 = (t33 >> 31);
    t35 = (t34 & 1);
    *((unsigned int *)t10) = t35;
    t12 = (t0 + 3480);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memset(t36, 0, 8);
    t15 = (t36 + 4);
    t16 = (t14 + 4);
    t37 = *((unsigned int *)t14);
    t38 = (t37 >> 21);
    t39 = (t38 & 1);
    *((unsigned int *)t36) = t39;
    t40 = *((unsigned int *)t16);
    t41 = (t40 >> 21);
    t42 = (t41 & 1);
    *((unsigned int *)t15) = t42;
    t44 = *((unsigned int *)t29);
    t45 = *((unsigned int *)t36);
    t46 = (t44 ^ t45);
    *((unsigned int *)t43) = t46;
    t18 = (t29 + 4);
    t19 = (t36 + 4);
    t20 = (t43 + 4);
    t47 = *((unsigned int *)t18);
    t48 = *((unsigned int *)t19);
    t49 = (t47 | t48);
    *((unsigned int *)t20) = t49;
    t50 = *((unsigned int *)t20);
    t51 = (t50 != 0);
    if (t51 == 1)
        goto LAB99;

LAB100:
LAB101:    t21 = (t0 + 3480);
    t54 = (t21 + 56U);
    t55 = *((char **)t54);
    memset(t56, 0, 8);
    t57 = (t56 + 4);
    t58 = (t55 + 4);
    t59 = *((unsigned int *)t55);
    t60 = (t59 >> 1);
    t61 = (t60 & 1);
    *((unsigned int *)t56) = t61;
    t62 = *((unsigned int *)t58);
    t63 = (t62 >> 1);
    t64 = (t63 & 1);
    *((unsigned int *)t57) = t64;
    t66 = *((unsigned int *)t43);
    t67 = *((unsigned int *)t56);
    t68 = (t66 ^ t67);
    *((unsigned int *)t65) = t68;
    t69 = (t43 + 4);
    t70 = (t56 + 4);
    t71 = (t65 + 4);
    t72 = *((unsigned int *)t69);
    t73 = *((unsigned int *)t70);
    t74 = (t72 | t73);
    *((unsigned int *)t71) = t74;
    t75 = *((unsigned int *)t71);
    t76 = (t75 != 0);
    if (t76 == 1)
        goto LAB102;

LAB103:
LAB104:    t79 = (t0 + 3480);
    t80 = (t79 + 56U);
    t81 = *((char **)t80);
    memset(t82, 0, 8);
    t83 = (t82 + 4);
    t84 = (t81 + 4);
    t85 = *((unsigned int *)t81);
    t86 = (t85 >> 0);
    t87 = (t86 & 1);
    *((unsigned int *)t82) = t87;
    t88 = *((unsigned int *)t84);
    t89 = (t88 >> 0);
    t90 = (t89 & 1);
    *((unsigned int *)t83) = t90;
    t92 = *((unsigned int *)t65);
    t93 = *((unsigned int *)t82);
    t94 = (t92 ^ t93);
    *((unsigned int *)t91) = t94;
    t95 = (t65 + 4);
    t96 = (t82 + 4);
    t97 = (t91 + 4);
    t98 = *((unsigned int *)t95);
    t99 = *((unsigned int *)t96);
    t100 = (t98 | t99);
    *((unsigned int *)t97) = t100;
    t101 = *((unsigned int *)t97);
    t102 = (t101 != 0);
    if (t102 == 1)
        goto LAB105;

LAB106:
LAB107:    t106 = (t0 + 3480);
    t107 = (t106 + 56U);
    t108 = *((char **)t107);
    memset(t105, 0, 8);
    t109 = (t105 + 4);
    t110 = (t108 + 4);
    t111 = *((unsigned int *)t108);
    t112 = (t111 >> 0);
    *((unsigned int *)t105) = t112;
    t113 = *((unsigned int *)t110);
    t114 = (t113 >> 0);
    *((unsigned int *)t109) = t114;
    t115 = *((unsigned int *)t105);
    *((unsigned int *)t105) = (t115 & 2147483647U);
    t116 = *((unsigned int *)t109);
    *((unsigned int *)t109) = (t116 & 2147483647U);
    xsi_vlogtype_concat(t28, 32, 32, 2U, t105, 31, t91, 1);
    t117 = (t0 + 3480);
    xsi_vlogvar_assign_value(t117, t28, 0, 0, 32);
    xsi_set_current_line(88, ng0);
    t2 = ((char*)((ng41)));
    t3 = (t0 + 3480);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 4768);
    t7 = (t0 + 848);
    t8 = xsi_create_subprogram_invocation(t6, 0, t0, t7, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t7, t8);
    t9 = (t0 + 3640);
    xsi_vlogvar_assign_value(t9, t2, 0, 0, 256);
    t10 = (t0 + 3800);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 32);

LAB110:    t11 = (t0 + 4864);
    t12 = *((char **)t11);
    t13 = (t12 + 80U);
    t14 = *((char **)t13);
    t15 = (t14 + 272U);
    t16 = *((char **)t15);
    t18 = (t16 + 0U);
    t19 = *((char **)t18);
    t17 = ((int  (*)(char *, char *))t19)(t0, t12);

LAB112:    if (t17 != 0)
        goto LAB113;

LAB108:    t12 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t12);

LAB109:    t20 = (t0 + 4864);
    t21 = *((char **)t20);
    t20 = (t0 + 848);
    t54 = (t0 + 4768);
    t55 = 0;
    xsi_delete_subprogram_invocation(t20, t21, t0, t54, t55);
    xsi_set_current_line(81, ng0);
    t2 = (t0 + 3320);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t22, 0, 8);
    xsi_vlog_signed_add(t22, 32, t4, 32, t5, 32);
    t6 = (t0 + 3320);
    xsi_vlogvar_assign_value(t6, t22, 0, 0, 32);
    goto LAB95;

LAB99:    t52 = *((unsigned int *)t43);
    t53 = *((unsigned int *)t20);
    *((unsigned int *)t43) = (t52 | t53);
    goto LAB101;

LAB102:    t77 = *((unsigned int *)t65);
    t78 = *((unsigned int *)t71);
    *((unsigned int *)t65) = (t77 | t78);
    goto LAB104;

LAB105:    t103 = *((unsigned int *)t91);
    t104 = *((unsigned int *)t97);
    *((unsigned int *)t91) = (t103 | t104);
    goto LAB107;

LAB111:;
LAB113:    t11 = (t0 + 4960U);
    *((char **)t11) = &&LAB110;
    goto LAB1;

LAB114:    xsi_set_current_line(97, ng0);
    xsi_vlogfile_write(1, 0, 0, ng44, 1, t0);
    goto LAB116;

}


extern void work_m_03098873492532307281_4133059610_init()
{
	static char *pe[] = {(void *)NetDecl_25_0,(void *)Initial_53_1};
	static char *se[] = {(void *)sp_check};
	xsi_register_didat("work_m_03098873492532307281_4133059610", "isim/instruction_decoder_tb_isim_beh.exe.sim/work/m_03098873492532307281_4133059610.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
