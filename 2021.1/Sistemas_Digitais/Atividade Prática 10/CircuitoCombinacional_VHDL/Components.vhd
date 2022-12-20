------------------------------------------------------------
-- Deeds (Digital Electronics Education and Design Suite)
-- VHDL Code generated on (14/08/2021, 14:27:23)
--      by Deeds (Digital Circuit Simulator)(Deeds-DcS)
--      Ver. 2.40.330 (Jan 07, 2021)
-- Copyright (c) 2002-2020 University of Genoa, Italy
--      Web Site:  https://www.digitalelectronicsdeeds.com
------------------------------------------------------------

--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

ENTITY NOT_gate IS
  PORT( I: IN std_logic;
  	O: OUT std_logic );
END NOT_gate;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF NOT_gate IS
BEGIN
  O <= (not I);
END behavioral;



--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

ENTITY AND2_gate IS
  PORT( I0,I1: IN std_logic;
        O: OUT std_logic );
END AND2_gate;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF AND2_gate IS
BEGIN
  O <= (I0 and I1);
END behavioral;


--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

ENTITY OR2_gate IS
  PORT( I0,I1: IN std_logic;
        O: OUT std_logic );
END OR2_gate;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF OR2_gate IS
BEGIN
  O <= (I0 or I1);
END behavioral;


--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

ENTITY OR3_gate IS
  PORT( I0,I1,I2: IN std_logic;
        O: OUT std_logic );
END OR3_gate;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF OR3_gate IS
BEGIN
  O <= (I0 or I1 or I2);
END behavioral;


--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

ENTITY NOR2_gate IS
  PORT( I0,I1: IN std_logic;
        O: OUT std_logic );
END NOR2_gate;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF NOR2_gate IS
BEGIN
  O <= (not (I0 or I1));
END behavioral;



