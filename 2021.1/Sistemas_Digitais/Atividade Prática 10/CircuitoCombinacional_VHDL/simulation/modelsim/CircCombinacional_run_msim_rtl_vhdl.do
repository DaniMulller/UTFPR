transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vcom -93 -work work {C:/Users/Pichau/Desktop/Tudo/UTFPR/2021.2/Sistemas Digitais/Atividade Prática 10/CircuitoCombinacional_VHDL/Components.vhd}
vcom -93 -work work {C:/Users/Pichau/Desktop/Tudo/UTFPR/2021.2/Sistemas Digitais/Atividade Prática 10/CircuitoCombinacional_VHDL/CircuitoCombinacional.vhd}

