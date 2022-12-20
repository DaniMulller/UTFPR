LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY Cont_74163 IS
    Port (  	 CP:  in std_logic; -- Clock input
                SR:  in std_logic; -- Synchonous RESET input 
                P:   in std_logic_vector(3 downto 0); -- Parallel LOAD input
                PE:  in std_logic; -- Parallel LOAD ENABLE input
                CEP: in std_logic; -- Count ENABLE Parallel Input
                CET: in std_logic; -- Count Enable Trickle Input
                TC:      out std_logic; -- Terminal count  
                counter: out std_logic_vector(3 downto 0) -- output 4-bit counter
         );
END Cont_74163;

ARCHITECTURE BEHAVIOR OF Cont_74163 IS
    TYPE type_fstate IS (state0,state1,state2,state3,state4,state5,state6,state7,state8,state9,state10,state11,state12,state13,state14,state15);
    SIGNAL state_at, state_next : type_fstate;
	 
BEGIN
	PROCESS(CP)
		BEGIN
			IF(CP = '1' AND CP'event) THEN
			state_at <= state_next;
				IF(SR = '0') THEN
				state_at <= state0;
				END IF;
			END IF;
	END PROCESS;
	
	PROCESS(state_at, P, PE, CEP, CET)
		BEGIN
			TC <= '0';
			state_next <= state_at;
			
			CASE state_at IS
				WHEN state0 => 
					counter <= "0000";
					IF (PE = '0') THEN -- Load Ativado
						IF (P = "0000") THEN
						state_next <= state0;
						ELSIF (P = "0001") THEN
							state_next <= state1;
						ELSIF (P = "0010") THEN
							state_next <= state2;
						ELSIF (P = "0011") THEN
							state_next <= state3;
						ELSIF (P = "0100") THEN
							state_next <= state4;
						ELSIF (P = "0101") THEN
							state_next <= state5;
						ELSIF (P = "0110") THEN
							state_next <= state6;
						ELSIF (P = "0111") THEN
							state_next <= state7;
						ELSIF (P = "1000") THEN
							state_next <= state8;
						ELSIF (P = "1001") THEN
							state_next <= state9;
						ELSIF (P = "1010") THEN
							state_next <= state10;
						ELSIF (P = "1011") THEN
							state_next <= state11;
						ELSIF (P = "1100") THEN
							state_next <= state12;
						ELSIF (P = "1101") THEN
							state_next <= state13;
						ELSIF (P = "1110") THEN
							state_next <= state14;
						ELSIF (P = "1111") THEN
							state_next <= state15;
						END IF;
					ELSE
						IF (CET ='0' OR CEP = '0') THEN -- Load desativado e CET ou CEP desativados
							state_next <= state0;
						ELSE
							state_next <= state1; -- Load desativado e CET/CEP ativados
						END IF;								  
				  END IF;
				  
				  WHEN state1 => 
					counter <= "0001";
					IF (PE = '0') THEN
						IF (P = "0000") THEN
						state_next <= state0;
						ELSIF (P = "0001") THEN
							state_next <= state1;
						ELSIF (P = "0010") THEN
							state_next <= state2;
						ELSIF (P = "0011") THEN
							state_next <= state3;
						ELSIF (P = "0100") THEN
							state_next <= state4;
						ELSIF (P = "0101") THEN
							state_next <= state5;
						ELSIF (P = "0110") THEN
							state_next <= state6;
						ELSIF (P = "0111") THEN
							state_next <= state7;
						ELSIF (P = "1000") THEN
							state_next <= state8;
						ELSIF (P = "1001") THEN
							state_next <= state9;
						ELSIF (P = "1010") THEN
							state_next <= state10;
						ELSIF (P = "1011") THEN
							state_next <= state11;
						ELSIF (P = "1100") THEN
							state_next <= state12;
						ELSIF (P = "1101") THEN
							state_next <= state13;
						ELSIF (P = "1110") THEN
							state_next <= state14;
						ELSIF (P = "1111") THEN
							state_next <= state15;
						END IF;
					ELSE
						IF (CET ='0' OR CEP = '0') THEN 
							state_next <= state1;
						ELSE
							state_next <= state2; 
						END IF;					  
				  END IF; 				
				  
				  WHEN state2 => 
					counter <= "0010";
					IF (PE = '0') THEN
						IF (P = "0000") THEN
						state_next <= state0;
						ELSIF (P = "0001") THEN
							state_next <= state1;
						ELSIF (P = "0010") THEN
							state_next <= state2;
						ELSIF (P = "0011") THEN
							state_next <= state3;
						ELSIF (P = "0100") THEN
							state_next <= state4;
						ELSIF (P = "0101") THEN
							state_next <= state5;
						ELSIF (P = "0110") THEN
							state_next <= state6;
						ELSIF (P = "0111") THEN
							state_next <= state7;
						ELSIF (P = "1000") THEN
							state_next <= state8;
						ELSIF (P = "1001") THEN
							state_next <= state9;
						ELSIF (P = "1010") THEN
							state_next <= state10;
						ELSIF (P = "1011") THEN
							state_next <= state11;
						ELSIF (P = "1100") THEN
							state_next <= state12;
						ELSIF (P = "1101") THEN
							state_next <= state13;
						ELSIF (P = "1110") THEN
							state_next <= state14;
						ELSIF (P = "1111") THEN
							state_next <= state15;
						END IF;
					ELSE
						IF (CET ='0' OR CEP = '0') THEN 
							state_next <= state2;
						ELSE
							state_next <= state3; 
						END IF;							  
				  END IF; 
				  
				 
				  WHEN state3 => 
					counter <= "0011";
					IF (PE = '0') THEN
						IF (P = "0000") THEN
						state_next <= state0;
						ELSIF (P = "0001") THEN
							state_next <= state1;
						ELSIF (P = "0010") THEN
							state_next <= state2;
						ELSIF (P = "0011") THEN
							state_next <= state3;
						ELSIF (P = "0100") THEN
							state_next <= state4;
						ELSIF (P = "0101") THEN
							state_next <= state5;
						ELSIF (P = "0110") THEN
							state_next <= state6;
						ELSIF (P = "0111") THEN
							state_next <= state7;
						ELSIF (P = "1000") THEN
							state_next <= state8;
						ELSIF (P = "1001") THEN
							state_next <= state9;
						ELSIF (P = "1010") THEN
							state_next <= state10;
						ELSIF (P = "1011") THEN
							state_next <= state11;
						ELSIF (P = "1100") THEN
							state_next <= state12;
						ELSIF (P = "1101") THEN
							state_next <= state13;
						ELSIF (P = "1110") THEN
							state_next <= state14;
						ELSIF (P = "1111") THEN
							state_next <= state15;
						END IF;
					ELSE
						IF (CET ='0' OR CEP = '0') THEN 
							state_next <= state3;
						ELSE
							state_next <= state4; 
						END IF;				 
				  END IF;  
				  
				  
				  WHEN state4 => 
					counter <= "0100";
					IF (PE = '0') THEN
						IF (P = "0000") THEN
						state_next <= state0;
						ELSIF (P = "0001") THEN
							state_next <= state1;
						ELSIF (P = "0010") THEN
							state_next <= state2;
						ELSIF (P = "0011") THEN
							state_next <= state3;
						ELSIF (P = "0100") THEN
							state_next <= state4;
						ELSIF (P = "0101") THEN
							state_next <= state5;
						ELSIF (P = "0110") THEN
							state_next <= state6;
						ELSIF (P = "0111") THEN
							state_next <= state7;
						ELSIF (P = "1000") THEN
							state_next <= state8;
						ELSIF (P = "1001") THEN
							state_next <= state9;
						ELSIF (P = "1010") THEN
							state_next <= state10;
						ELSIF (P = "1011") THEN
							state_next <= state11;
						ELSIF (P = "1100") THEN
							state_next <= state12;
						ELSIF (P = "1101") THEN
							state_next <= state13;
						ELSIF (P = "1110") THEN
							state_next <= state14;
						ELSIF (P = "1111") THEN
							state_next <= state15;
						END IF;
					ELSE
						IF (CET ='0' OR CEP = '0') THEN 
							state_next <= state4;
						ELSE
							state_next <= state5; 
						END IF;							  
				  END IF; 
				  
				  WHEN state5 => 
					counter <= "0101";
					IF (PE = '0') THEN
						IF (P = "0000") THEN
						state_next <= state0;
						ELSIF (P = "0001") THEN
							state_next <= state1;
						ELSIF (P = "0010") THEN
							state_next <= state2;
						ELSIF (P = "0011") THEN
							state_next <= state3;
						ELSIF (P = "0100") THEN
							state_next <= state4;
						ELSIF (P = "0101") THEN
							state_next <= state5;
						ELSIF (P = "0110") THEN
							state_next <= state6;
						ELSIF (P = "0111") THEN
							state_next <= state7;
						ELSIF (P = "1000") THEN
							state_next <= state8;
						ELSIF (P = "1001") THEN
							state_next <= state9;
						ELSIF (P = "1010") THEN
							state_next <= state10;
						ELSIF (P = "1011") THEN
							state_next <= state11;
						ELSIF (P = "1100") THEN
							state_next <= state12;
						ELSIF (P = "1101") THEN
							state_next <= state13;
						ELSIF (P = "1110") THEN
							state_next <= state14;
						ELSIF (P = "1111") THEN
							state_next <= state15;
						END IF;
					ELSE
						IF (CET ='0' OR CEP = '0') THEN 
							state_next <= state5;
						ELSE
							state_next <= state6; 
						END IF;							  
				  END IF; 
				  
				  WHEN state6 => 
					counter <= "0110";
					IF (PE = '0') THEN
						IF (P = "0000") THEN
						state_next <= state0;
						ELSIF (P = "0001") THEN
							state_next <= state1;
						ELSIF (P = "0010") THEN
							state_next <= state2;
						ELSIF (P = "0011") THEN
							state_next <= state3;
						ELSIF (P = "0100") THEN
							state_next <= state4;
						ELSIF (P = "0101") THEN
							state_next <= state5;
						ELSIF (P = "0110") THEN
							state_next <= state6;
						ELSIF (P = "0111") THEN
							state_next <= state7;
						ELSIF (P = "1000") THEN
							state_next <= state8;
						ELSIF (P = "1001") THEN
							state_next <= state9;
						ELSIF (P = "1010") THEN
							state_next <= state10;
						ELSIF (P = "1011") THEN
							state_next <= state11;
						ELSIF (P = "1100") THEN
							state_next <= state12;
						ELSIF (P = "1101") THEN
							state_next <= state13;
						ELSIF (P = "1110") THEN
							state_next <= state14;
						ELSIF (P = "1111") THEN
							state_next <= state15;
						END IF;
					ELSE
						IF (CET ='0' OR CEP = '0') THEN 
							state_next <= state6;
						ELSE
							state_next <= state7; 
						END IF;				
				  END IF; 
				  
					WHEN state7 => 
					counter <= "0111";
					IF (PE = '0') THEN
						IF (P = "0000") THEN
						state_next <= state0;
						ELSIF (P = "0001") THEN
							state_next <= state1;
						ELSIF (P = "0010") THEN
							state_next <= state2;
						ELSIF (P = "0011") THEN
							state_next <= state3;
						ELSIF (P = "0100") THEN
							state_next <= state4;
						ELSIF (P = "0101") THEN
							state_next <= state5;
						ELSIF (P = "0110") THEN
							state_next <= state6;
						ELSIF (P = "0111") THEN
							state_next <= state7;
						ELSIF (P = "1000") THEN
							state_next <= state8;
						ELSIF (P = "1001") THEN
							state_next <= state9;
						ELSIF (P = "1010") THEN
							state_next <= state10;
						ELSIF (P = "1011") THEN
							state_next <= state11;
						ELSIF (P = "1100") THEN
							state_next <= state12;
						ELSIF (P = "1101") THEN
							state_next <= state13;
						ELSIF (P = "1110") THEN
							state_next <= state14;
						ELSIF (P = "1111") THEN
							state_next <= state15;
						END IF;
					ELSE
						IF (CET ='0' OR CEP = '0') THEN 
							state_next <= state7;
						ELSE
							state_next <= state8; 
						END IF;								  
				  END IF; 
				  				  				  
				  WHEN state8 => 
					counter <= "1000";
					IF (PE = '0') THEN
						IF (P = "0000") THEN
						state_next <= state0;
						ELSIF (P = "0001") THEN
							state_next <= state1;
						ELSIF (P = "0010") THEN
							state_next <= state2;
						ELSIF (P = "0011") THEN
							state_next <= state3;
						ELSIF (P = "0100") THEN
							state_next <= state4;
						ELSIF (P = "0101") THEN
							state_next <= state5;
						ELSIF (P = "0110") THEN
							state_next <= state6;
						ELSIF (P = "0111") THEN
							state_next <= state7;
						ELSIF (P = "1000") THEN
							state_next <= state8;
						ELSIF (P = "1001") THEN
							state_next <= state9;
						ELSIF (P = "1010") THEN
							state_next <= state10;
						ELSIF (P = "1011") THEN
							state_next <= state11;
						ELSIF (P = "1100") THEN
							state_next <= state12;
						ELSIF (P = "1101") THEN
							state_next <= state13;
						ELSIF (P = "1110") THEN
							state_next <= state14;
						ELSIF (P = "1111") THEN
							state_next <= state15;
						END IF;
					ELSE
						IF (CET ='0' OR CEP = '0') THEN 
							state_next <= state8;
						ELSE
							state_next <= state9; 
						END IF;						  
				  END IF; 
				  
				  WHEN state9 => 
					counter <= "1001";
					IF (PE = '0') THEN
						IF (P = "0000") THEN
						state_next <= state0;
					ELSIF (P = "0001") THEN
							state_next <= state1;
						ELSIF (P = "0010") THEN
							state_next <= state2;
						ELSIF (P = "0011") THEN
							state_next <= state3;
						ELSIF (P = "0100") THEN
							state_next <= state4;
						ELSIF (P = "0101") THEN
							state_next <= state5;
						ELSIF (P = "0110") THEN
							state_next <= state6;
						ELSIF (P = "0111") THEN
							state_next <= state7;
						ELSIF (P = "1000") THEN
							state_next <= state8;
						ELSIF (P = "1001") THEN
							state_next <= state9;
						ELSIF (P = "1010") THEN
							state_next <= state10;
						ELSIF (P = "1011") THEN
							state_next <= state11;
						ELSIF (P = "1100") THEN
							state_next <= state12;
						ELSIF (P = "1101") THEN
							state_next <= state13;
						ELSIF (P = "1110") THEN
							state_next <= state14;
						ELSIF (P = "1111") THEN
							state_next <= state15;
						END IF;
					ELSE
						IF (CET ='0' OR CEP = '0') THEN 
							state_next <= state9;
						ELSE
							state_next <= state0; 
						END IF;							  
				  END IF; 
				  
				  WHEN state10 => 
					counter <= "1010";
					IF (PE = '0') THEN
						IF (P = "0000") THEN
						state_next <= state0;
						ELSIF (P = "0001") THEN
							state_next <= state1;
						ELSIF (P = "0010") THEN
							state_next <= state2;
						ELSIF (P = "0011") THEN
							state_next <= state3;
						ELSIF (P = "0100") THEN
							state_next <= state4;
						ELSIF (P = "0101") THEN
							state_next <= state5;
						ELSIF (P = "0110") THEN
							state_next <= state6;
						ELSIF (P = "0111") THEN
							state_next <= state7;
						ELSIF (P = "1000") THEN
							state_next <= state8;
						ELSIF (P = "1001") THEN
							state_next <= state9;
						ELSIF (P = "1010") THEN
							state_next <= state10;
						ELSIF (P = "1011") THEN
							state_next <= state11;
						ELSIF (P = "1100") THEN
							state_next <= state12;
						ELSIF (P = "1101") THEN
							state_next <= state13;
						ELSIF (P = "1110") THEN
							state_next <= state14;
						ELSIF (P = "1111") THEN
							state_next <= state15;
						END IF;
					ELSE
						IF (CET ='0' OR CEP = '0') THEN 
							state_next <= state10;
						ELSE
							state_next <= state11; 
						END IF;						  
				  END IF; 
				  
				  WHEN state11 => 
					counter <= "1011";
					IF (PE = '0') THEN
						IF (P = "0000") THEN
						state_next <= state0;
						ELSIF (P = "0001") THEN
							state_next <= state1;
						ELSIF (P = "0010") THEN
							state_next <= state2;
						ELSIF (P = "0011") THEN
							state_next <= state3;
						ELSIF (P = "0100") THEN
							state_next <= state4;
						ELSIF (P = "0101") THEN
							state_next <= state5;
						ELSIF (P = "0110") THEN
							state_next <= state6;
						ELSIF (P = "0111") THEN
							state_next <= state7;
						ELSIF (P = "1000") THEN
							state_next <= state8;
						ELSIF (P = "1001") THEN
							state_next <= state9;
						ELSIF (P = "1010") THEN
							state_next <= state10;
						ELSIF (P = "1011") THEN
							state_next <= state11;
						ELSIF (P = "1100") THEN
							state_next <= state12;
						ELSIF (P = "1101") THEN
							state_next <= state13;
						ELSIF (P = "1110") THEN
							state_next <= state14;
						ELSIF (P = "1111") THEN
							state_next <= state15;
						END IF;
					ELSE
						IF (CET ='0' OR CEP = '0') THEN 
							state_next <= state11;
						ELSE
							state_next <= state12; 
						END IF;							  
				  END IF; 			  
				  
				  WHEN state12 => 
					counter <= "1100";
					IF (PE = '0') THEN
						IF (P = "0000") THEN
						state_next <= state0;
						ELSIF (P = "0001") THEN
							state_next <= state1;
						ELSIF (P = "0010") THEN
							state_next <= state2;
						ELSIF (P = "0011") THEN
							state_next <= state3;
						ELSIF (P = "0100") THEN
							state_next <= state4;
						ELSIF (P = "0101") THEN
							state_next <= state5;
						ELSIF (P = "0110") THEN
							state_next <= state6;
						ELSIF (P = "0111") THEN
							state_next <= state7;
						ELSIF (P = "1000") THEN
							state_next <= state8;
						ELSIF (P = "1001") THEN
							state_next <= state9;
						ELSIF (P = "1010") THEN
							state_next <= state10;
						ELSIF (P = "1011") THEN
							state_next <= state11;
						ELSIF (P = "1100") THEN
							state_next <= state12;
						ELSIF (P = "1101") THEN
							state_next <= state13;
						ELSIF (P = "1110") THEN
							state_next <= state14;
						ELSIF (P = "1111") THEN
							state_next <= state15;
						END IF;
					ELSE
						IF (CET ='0' OR CEP = '0') THEN 
							state_next <= state12;
						ELSE
							state_next <= state13; 
						END IF;							  
				  END IF; 
				  
				  WHEN state13 => 
					counter <= "1101";
					IF (PE = '0') THEN
						IF (P = "0000") THEN
						state_next <= state0;
						ELSIF (P = "0001") THEN
							state_next <= state1;
						ELSIF (P = "0010") THEN
							state_next <= state2;
						ELSIF (P = "0011") THEN
							state_next <= state3;
						ELSIF (P = "0100") THEN
							state_next <= state4;
						ELSIF (P = "0101") THEN
							state_next <= state5;
						ELSIF (P = "0110") THEN
							state_next <= state6;
						ELSIF (P = "0111") THEN
							state_next <= state7;
						ELSIF (P = "1000") THEN
							state_next <= state8;
						ELSIF (P = "1001") THEN
							state_next <= state9;
						ELSIF (P = "1010") THEN
							state_next <= state10;
						ELSIF (P = "1011") THEN
							state_next <= state11;
						ELSIF (P = "1100") THEN
							state_next <= state12;
						ELSIF (P = "1101") THEN
							state_next <= state13;
						ELSIF (P = "1110") THEN
							state_next <= state14;
						ELSIF (P = "1111") THEN
							state_next <= state15;
						END IF;
					ELSE
						IF (CET ='0' OR CEP = '0') THEN 
							state_next <= state13;
						ELSE
							state_next <= state14; 
						END IF;							  
				  END IF; 
				  
				  WHEN state14 => 
					counter <= "1110";
					IF (PE = '0') THEN
						IF (P = "0000") THEN
						state_next <= state0;
						ELSIF (P = "0001") THEN
							state_next <= state1;
						ELSIF (P = "0010") THEN
							state_next <= state2;
						ELSIF (P = "0011") THEN
							state_next <= state3;
						ELSIF (P = "0100") THEN
							state_next <= state4;
						ELSIF (P = "0101") THEN
							state_next <= state5;
						ELSIF (P = "0110") THEN
							state_next <= state6;
						ELSIF (P = "0111") THEN
							state_next <= state7;
						ELSIF (P = "1000") THEN
							state_next <= state8;
						ELSIF (P = "1001") THEN
							state_next <= state9;
						ELSIF (P = "1010") THEN
							state_next <= state10;
						ELSIF (P = "1011") THEN
							state_next <= state11;
						ELSIF (P = "1100") THEN
							state_next <= state12;
						ELSIF (P = "1101") THEN
							state_next <= state13;
						ELSIF (P = "1110") THEN
							state_next <= state14;
						ELSIF (P = "1111") THEN
							state_next <= state15;
						END IF;
					ELSE
						IF (CET ='0' OR CEP = '0') THEN 
							state_next <= state14;
						ELSE
							state_next <= state15; 
						END IF;				
				  END IF; 
				  
				  WHEN state15 =>
				 	TC <= '1'; 
					counter <= "1111";
					IF (PE = '0') THEN
						IF (P = "0000") THEN
						state_next <= state0;
						ELSIF (P = "0001") THEN
							state_next <= state1;
						ELSIF (P = "0010") THEN
							state_next <= state2;
						ELSIF (P = "0011") THEN
							state_next <= state3;
						ELSIF (P = "0100") THEN
							state_next <= state4;
						ELSIF (P = "0101") THEN
							state_next <= state5;
						ELSIF (P = "0110") THEN
							state_next <= state6;
						ELSIF (P = "0111") THEN
							state_next <= state7;
						ELSIF (P = "1000") THEN
							state_next <= state8;
						ELSIF (P = "1001") THEN
							state_next <= state9;
						ELSIF (P = "1010") THEN
							state_next <= state10;
						ELSIF (P = "1011") THEN
							state_next <= state11;
						ELSIF (P = "1100") THEN
							state_next <= state12;
						ELSIF (P = "1101") THEN
							state_next <= state13;
						ELSIF (P = "1110") THEN
							state_next <= state14;
						ELSIF (P = "1111") THEN
							state_next <= state15;
						END IF;
					ELSE
						IF (CET ='0' OR CEP = '0') THEN 
							state_next <= state15;
						ELSE
							state_next <= state0; 
					END IF;				
				  END IF;	  
		END CASE; 
	END PROCESS;
END BEHAVIOR;