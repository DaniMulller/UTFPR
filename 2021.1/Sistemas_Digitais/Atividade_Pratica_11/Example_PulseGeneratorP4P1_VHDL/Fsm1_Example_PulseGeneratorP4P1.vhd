---------------------------------------------------------------------------------------------------
-- Deeds (Digital Electronics Education and Design Suite)
-- VHDL Code generated on (17/08/2021, 16:30:45)
--      by the Deeds (Finite State Machine Simulator)(Deeds-FsM)
--      Ver. 2.40.330 (Jan 07, 2021)
-- Copyright (c) 2002-2020 University of Genoa, Italy
--      Web Site:  https://www.digitalelectronicsdeeds.com
---------------------------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY Fsm1_Example_PulseGeneratorP4P1 IS
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
END Fsm1_Example_PulseGeneratorP4P1;

ARCHITECTURE behavioral OF Fsm1_Example_PulseGeneratorP4P1 IS       -- (Behavioral Description)
  TYPE states is ( state_a,
                   state_b,
                   state_c,
                   state_f,
                   dummy_0100,
                   state_h,
                   state_p,
                   state_d,
                   state_n,
                   dummy_1001,
                   dummy_1010,
                   dummy_1011,
                   state_m,
                   dummy_1101,
                   dummy_1110,
                   dummy_1111 );
  SIGNAL State,
         Next_State: states;
BEGIN

  -- Next State Combinational Logic ----------------------------------
  FSM: process( State, i_P1, i_P2, i_P3, i_P4 )
  begin
    CASE State IS
      when state_a =>
                 if (i_P1 = '1') then
                   Next_State <= state_b;
                 else
                   if (i_P2 = '1') then
                     Next_State <= state_c;
                   else
                     if (i_P3 = '1') then
                       Next_State <= state_d;
                     else
                       if (i_P4 = '1') then
                         Next_State <= state_f;
                       else
                         Next_State <= state_a;
                       end if;
                     end if;
                   end if;
                 end if;
      when state_b =>
                 if (i_P1 = '1') then
                   Next_State <= state_b;
                 else
                   Next_State <= state_p;
                 end if;
      when state_c =>
                 if (i_P2 = '1') then
                   Next_State <= state_c;
                 else
                   Next_State <= state_n;
                 end if;
      when state_f =>
                 if (i_P4 = '1') then
                   Next_State <= state_f;
                 else
                   Next_State <= state_h;
                 end if;
      when state_h =>
                 Next_State <= state_m;
      when state_p =>
                 Next_State <= state_a;
      when state_m =>
                 Next_State <= state_n;
      when state_d =>
                 if (i_P3 = '1') then
                   Next_State <= state_d;
                 else
                   Next_State <= state_m;
                 end if;
      when state_n =>
                 Next_State <= state_p;
      when OTHERS =>
                 Next_State <= state_a;
    END case;
  end process;

  -- State Register --------------------------------------------------
  REG: process( Ck, Reset )
  begin
    if (Reset = '0') then
              State <= state_a;
    elsif rising_edge(Ck) then
              State <= Next_State;
       end if;
  end process;

  -- Outputs Combinational Logic -----------------------------------
  OUTPUTS: process( State, i_P1, i_P2, i_P3, i_P4 )
  begin
    -- Set output defaults:
    o_LIT <= '0';
    o_PLS <= '0';

    -- Set output as function of current state and input:
    CASE State IS
      when state_b =>
                 o_LIT <= '1';
      when state_c =>
                 o_LIT <= '1';
      when state_f =>
                 o_LIT <= '1';
      when state_h =>
                 o_PLS <= '1';
      when state_p =>
                 o_PLS <= '1';
      when state_m =>
                 o_PLS <= '1';
      when state_d =>
                 o_LIT <= '1';
      when state_n =>
                 o_PLS <= '1';
      when OTHERS =>
                 o_LIT <= '0';
                 o_PLS <= '0';
    END case;
  end process;

END behavioral;
