------------------------------------------------------------
-- Deeds (Digital Electronics Education and Design Suite)
-- VHDL Code generated on (17/08/2021, 16:30:45)
--      by Deeds (Digital Circuit Simulator)(Deeds-DcS)
--      Ver. 2.40.330 (Jan 07, 2021)
-- Copyright (c) 2002-2020 University of Genoa, Italy
--      Web Site:  https://www.digitalelectronicsdeeds.com
------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.all;


ENTITY Example_PulseGeneratorP4P1 IS
  PORT( 
    --------------------------------------> Inputs:
    iP1:          IN  std_logic;
    iCK:          IN  std_logic;
    inReset:      IN  std_logic;
    iP2:          IN  std_logic;
    iP3:          IN  std_logic;
    iP4:          IN  std_logic;
    --------------------------------------> Outputs:
    oLIGHT:       OUT std_logic;
    oPULSE:       OUT std_logic 
    ------------------------------------------------------
    );
END Example_PulseGeneratorP4P1;


ARCHITECTURE structural OF Example_PulseGeneratorP4P1 IS 

  ----------------------------------------> Finite State Machine(s):
  COMPONENT Fsm1_Example_PulseGeneratorP4P1 IS
    PORT( ----------------------------------->Clock & Reset:
          Ck:    IN std_logic;
          Reset: IN std_logic;
          ----------------------------------->Inputs:
          i_P1:  IN std_logic;
          i_P2:  IN std_logic;
          i_P3:  IN std_logic;
          i_P4:  IN std_logic;
          ----------------------------------->Outputs:
          o_LIT: OUT std_logic;
          o_PLS: OUT std_logic
          -------------------------------------------
          );
  END COMPONENT;

  ----------------------------------------> Signals:
  SIGNAL S001: std_logic;
  SIGNAL S002: std_logic;
  SIGNAL S003: std_logic;
  SIGNAL S004: std_logic;
  SIGNAL S005: std_logic;
  SIGNAL S006: std_logic;
  SIGNAL S007: std_logic;
  SIGNAL S008: std_logic;


BEGIN -- structural

  ----------------------------------------> Input:
  S001 <= iP1;
  S002 <= iCK;
  S003 <= inReset;
  S005 <= iP2;
  S006 <= iP3;
  S007 <= iP4;

  ----------------------------------------> Output:
  oLIGHT <= S004;
  oPULSE <= S008;

  ----------------------------------------> Component Mapping:
  C040: Fsm1_Example_PulseGeneratorP4P1 PORT MAP ( S002, S003, 
                                                   S001, S005, 
                                                   S006, S007, 
                                                   S004, S008 );
END structural;
