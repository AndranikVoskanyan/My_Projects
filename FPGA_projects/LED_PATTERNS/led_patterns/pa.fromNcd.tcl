
# PlanAhead Launch Script for Post PAR Floorplanning, created by Project Navigator

create_project -name led_patterns -dir "/home/ise/Desktop/LED_PATTERNS/led_patterns/planAhead_run_1" -part xc6slx9tqg144-2
set srcset [get_property srcset [current_run -impl]]
set_property design_mode GateLvl $srcset
set_property edif_top_file "/home/ise/Desktop/LED_PATTERNS/led_patterns/everything.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {/home/ise/Desktop/LED_PATTERNS/led_patterns} }
set_property target_constrs_file "/home/ise/Desktop/LED_PATTERNS/led_patterns/pinout.ucf" [current_fileset -constrset]
add_files [list {pinout.ucf}] -fileset [get_property constrset [current_run]]
add_files [list {everything.ucf}] -fileset [get_property constrset [current_run]]
link_design
read_xdl -file "/home/ise/Desktop/LED_PATTERNS/led_patterns/everything.ncd"
if {[catch {read_twx -name results_1 -file "/home/ise/Desktop/LED_PATTERNS/led_patterns/everything.twx"} eInfo]} {
   puts "WARNING: there was a problem importing \"/home/ise/Desktop/LED_PATTERNS/led_patterns/everything.twx\": $eInfo"
}
