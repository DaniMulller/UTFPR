onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /tb_74_163/clk
add wave -noupdate /tb_74_163/reset
add wave -noupdate /tb_74_163/cep
add wave -noupdate /tb_74_163/cet
add wave -noupdate /tb_74_163/pe
add wave -noupdate /tb_74_163/tc
add wave -noupdate -radix unsigned /tb_74_163/p
add wave -noupdate -radix unsigned /tb_74_163/q
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {1690000 ps} 0}
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
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {0 ps} {1785 ns}
