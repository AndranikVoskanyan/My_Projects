
# PlanAhead Launch Script for Post PAR Floorplanning, created by Project Navigator

create_project -name DSP_FIR -dir "/home/ise/Desktop/DSP_FIR/planAhead_run_2" -part xc6slx9tqg144-2
set srcset [get_property srcset [current_run -impl]]
set_property design_mode GateLvl $srcset
set_property edif_top_file "/home/ise/Desktop/DSP_FIR/fir_filter_top.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {/home/ise/Desktop/DSP_FIR} }
set_property target_constrs_file "fir_filter_top.ucf" [current_fileset -constrset]
add_files [list {fir_filter_top.ucf}] -fileset [get_property constrset [current_run]]
link_design
read_xdl -file "/home/ise/Desktop/DSP_FIR/fir_filter_top.xdl"
if {[catch {read_twx -name results_1 -file "/home/ise/Desktop/DSP_FIR/fir_filter_top.twx"} eInfo]} {
   puts "WARNING: there was a problem importing \"/home/ise/Desktop/DSP_FIR/fir_filter_top.twx\": $eInfo"
}
