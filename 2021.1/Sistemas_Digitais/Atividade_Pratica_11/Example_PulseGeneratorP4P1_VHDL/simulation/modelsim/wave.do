onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -divider Input
add wave -noupdate /example_pulsegeneratorp4p1/iCK
add wave -noupdate /example_pulsegeneratorp4p1/inReset
add wave -noupdate /example_pulsegeneratorp4p1/iP1
add wave -noupdate /example_pulsegeneratorp4p1/iP2
add wave -noupdate /example_pulsegeneratorp4p1/iP3
add wave -noupdate /example_pulsegeneratorp4p1/iP4
add wave -noupdate /example_pulsegeneratorp4p1/C040/State
add wave -noupdate -divider Output
add wave -noupdate /example_pulsegeneratorp4p1/oLIGHT
add wave -noupdate /example_pulsegeneratorp4p1/oPULSE
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {5000 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 100000
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits us
update
WaveRestoreZoom {0 ps} {5000 ns}
force sim:/example_pulsegeneratorp4p1/iCK 0 0, 1 100ns -r 200ns
force sim:/example_pulsegeneratorp4p1/inReset 0 0, 1 100ns, 0 4900ns
force sim:/example_pulsegeneratorp4p1/iP1 0 0, 1 400ns, 0 700ns
force sim:/example_pulsegeneratorp4p1/iP2 0 0
force sim:/example_pulsegeneratorp4p1/iP3 0 0, 1 1200ns, 0 1600ns
force sim:/example_pulsegeneratorp4p1/iP4 0 0, 1 2900ns, 0 3100ns
run 5000ns
