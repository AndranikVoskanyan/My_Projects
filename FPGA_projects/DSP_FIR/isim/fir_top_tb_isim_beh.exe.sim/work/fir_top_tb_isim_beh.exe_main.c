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
    work_m_00703211026043178410_0395741853_init();
    work_m_16629543706195202750_0953534304_init();
    work_m_00048530468777105897_0437428265_init();
    work_m_10391002736903121463_0257065294_init();
    work_m_04904424990872388133_1863452270_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_04904424990872388133_1863452270");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}
