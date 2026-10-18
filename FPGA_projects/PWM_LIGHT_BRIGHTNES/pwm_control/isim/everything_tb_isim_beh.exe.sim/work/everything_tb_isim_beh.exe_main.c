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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_01143400237404727721_1182845832_init();
    work_m_14149211872692675295_3630152564_init();
    work_m_04124990478099961944_4129626524_init();
    work_m_04850038999019615009_0977497003_init();
    work_m_16460168498476217168_3006448223_init();
    work_m_00067213377227476099_0812341347_init();
    work_m_16928905285324363028_3663289426_init();
    work_m_16597389700404012008_2700879761_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_16597389700404012008_2700879761");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}
