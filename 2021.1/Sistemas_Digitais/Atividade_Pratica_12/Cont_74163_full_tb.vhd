library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.NUMERIC_STD.all;
-- 
-- Testbench para teste completo do contador 74_162
--
entity tb_74_163 is
end tb_74_163;

architecture Behavioral of tb_74_163 is

component Cont_74163 
        Port (  CP:  in std_logic; -- Clock input
                SR:  in std_logic; -- Synchonous RESET input 
                P:   in std_logic_vector(3 downto 0); -- Parallel LOAD input
                PE:  in std_logic; -- Parallel LOAD ENABLE input
                CEP: in std_logic; -- Count ENABLE parallel input
                CET: in std_logic; -- Count ENABLE
                TC:      out std_logic; -- Terminal count  
                counter: out std_logic_vector(3 downto 0) -- output 4-bit counter
                );
end component;
signal clk, reset, cep, cet, pe: std_logic;
signal p, q:std_logic_vector(3 downto 0);
signal tc: std_logic;
type INT_ARRAY is array (integer range <>) of integer;
constant SEQ : INT_ARRAY(0 to 15) := (3, 8, 0, 14, 2, 7, 10, 15, 6, 11, 13, 1, 9, 4, 5, 12);

begin
dut: Cont_74163 port map (clk, reset, p, pe, cep, cet, tc, q);

-- Processo gerador de clock (periodo de 20 ns)
clock_process :process
begin
     clk <= '0';
     wait for 10 ns;
     clk <= '1';
     wait for 10 ns;
end process;


-- Testing processes
All_tests: process
variable I : integer;
begin
   -- ==== LOAD test ====
   -- inicializacao
   cet <= '1';
   cep <= '1';
   pe <= '1';
   p <= "1111";
   reset <= '0';
   wait until falling_edge(clk);
   assert (q = "0000") report "RESET falhou";
   assert (tc = '0') report "TC errado no RESET";
   reset <= '1';

   -- Testa toda a sequencia
   pe <= '0';
   I := 0;
   p <= std_logic_vector(to_unsigned(SEQ(I), p'length));
   while (I <= 15) loop
	-- Testes especiais
        if (I = 7) then
	    -- Testa RESET com PE ativado
	    reset <= '0';
	    wait for 1 ns;
	    assert (q /= "0000") report "RESET assincrono";
   	    wait until falling_edge(clk);
	    assert (q = "0000") report "RESET falhou";
            assert (tc = '0') report "TC errado no RESET";
	    reset <= '1';
	elsif (I = 13) then
	    -- Testa CET e CEP com PE ativado
	    cep <= '0';
            cet <= '1';
            p <= "1000";
   	    wait until falling_edge(clk);
	    assert (q = p) report "CEP falhou";
            assert (tc = '0') report "TC errado no CEP";

	    cep <= '0';
            cet <= '0';
            p <= "0100";
   	    wait until falling_edge(clk);
	    assert (q = p) report "CEP e CET falhou";
            assert (tc = '0') report "TC errado no CEP e CET";

	    cep <= '1';
            cet <= '0';
            p <= "0010";
   	    wait until falling_edge(clk);
	    assert (q = p) report "CET falhou";
            assert (tc = '0') report "TC errado no CET";

	    cep <= '1';
	    cet <= '1';
	    p <= std_logic_vector(to_unsigned(SEQ(I), p'length));
	end if;

	wait until falling_edge(clk);
	assert (q = p) report "LOAD falhou para SEQ=";
        if(q = "1111") then
	    assert (tc = '1') report "TC errado para SEQ=";
	else
	    assert (tc = '0') report "TC errado para SEQ=";
	end if;
        I := I + 1;
	if (I <= 15) then
	    p <= std_logic_vector(to_unsigned(SEQ(I), p'length));
	end if;
   end loop;

   -- ==== COUNT & HOLD test ====
   -- inicializacao
   cet <= '1';
   cep <= '1';
   pe <= '1';
   p <= "1111";
   reset <= '0';
   wait for 1 ns;
   assert (q /= "0000") report "RESET assincrono";
   wait until falling_edge(clk);
   assert (q = "0000") report "RESET falhou";
   assert (tc = '0') report "TC errado no RESET";
   reset <= '1';

   -- Sequencia de clocks
   I := 1;
   while (I <= 9) loop
	-- Testes especiais
	if (I = 4) then
	   -- Testa CET e CEP em COUNT
	   cep <= '0';
	   cet <= '1';
	   wait until falling_edge(clk);
	   assert (q = std_logic_vector(to_unsigned(I-1, q'length))) report "CEP - COUNT falhou";
	   assert (tc = '0') report "TC errado no CEP - COUNT";

	   cep <= '0';
	   cet <= '0';
	   wait until falling_edge(clk);
	   assert (q = std_logic_vector(to_unsigned(I-1, q'length))) report "CEP e CET - COUNT falhou";
	   assert (tc = '0') report "TC errado no CEP e CET - COUNT";

	   cep <= '1';
	   cet <= '0';
	   wait until falling_edge(clk);
	   assert (q = std_logic_vector(to_unsigned(I-1, q'length))) report "CET - COUNT falhou";
	   assert (tc = '0') report "TC errado no CET - COUNT";

	   cep <= '1';
	   cet <= '1';
	end if;

	wait until falling_edge(clk);
	assert (q = std_logic_vector(to_unsigned(I, p'length))) report "COUNT falhou";
        if(q = "1111") then
	    assert (tc = '1') report "TC errado no COUNT";
	else
	    assert (tc = '0') report "TC errado no COUNT";
	end if;
        I := I + 1;
   end loop;

   -- ==== COUNT & LOAD test ====
   -- inicializacao
   cet <= '1';
   cep <= '1';
   pe <= '0';
   p <= "0010";
   reset <= '1';
   wait until falling_edge(clk);
   assert (q = "0010") report "LOAD falhou";
   assert (tc = '0') report "TC errado no LOAD";
   pe <= '1';

   -- Sequencia de clocks
   wait until falling_edge(clk);
   assert (q = "0011") report "COUNT (HOLD) falhou";
   assert (tc = '0') report "TC errado no COUNT (HOLD)";

   wait until falling_edge(clk);
   assert (q = "0100") report "COUNT (HOLD) falhou";
   assert (tc = '0') report "TC errado no COUNT (HOLD)";

   wait until falling_edge(clk);
   assert (q = "0101") report "COUNT (HOLD) falhou";
   assert (tc = '0') report "TC errado no COUNT (HOLD)";

   -- Carrega 10
   pe <= '0';
   p <= "1010";
   wait until falling_edge(clk);
   assert (q = "1010") report "LOAD falhou";
   assert (tc = '0') report "TC errado no LOAD";
   pe <= '1';

   wait until falling_edge(clk);
   assert (q = "1011") report "COUNT (HOLD) falhou";
   assert (tc = '0') report "TC errado no COUNT (HOLD)";

   wait until falling_edge(clk);
   assert (q = "1100") report "COUNT (HOLD) falhou";
   assert (tc = '0') report "TC errado no COUNT (HOLD)";

   wait until falling_edge(clk);
   assert (q = "1101") report "COUNT (HOLD) falhou";
   assert (tc = '0') report "TC errado no COUNT (HOLD)";

   -- Carrega 5
   pe <= '0';
   p <= "0101";
   wait until falling_edge(clk);
   assert (q = "0101") report "LOAD falhou";
   assert (tc = '0') report "TC errado no LOAD";
   pe <= '1';

   wait until falling_edge(clk);
   assert (q = "0110") report "COUNT (HOLD) falhou";
   assert (tc = '0') report "TC errado no COUNT (HOLD)";

   wait until falling_edge(clk);
   assert (q = "0111") report "COUNT (HOLD) falhou";
   assert (tc = '0') report "TC errado no COUNT (HOLD)";

   wait until falling_edge(clk);
   assert (q = "1000") report "COUNT (HOLD) falhou";
   assert (tc = '0') report "TC errado no COUNT (HOLD)";

   -- Carrega 14
   pe <= '0';
   p <= "1110";
   wait until falling_edge(clk);
   assert (q = "1110") report "LOAD falhou";
   assert (tc = '0') report "TC errado no LOAD";
   pe <= '1';

   wait until falling_edge(clk);
   assert (q = "1111") report "COUNT (HOLD) falhou";
   assert (tc = '1') report "TC errado no COUNT (HOLD)";

   wait until falling_edge(clk);
   assert (q = "0000") report "COUNT (HOLD) falhou";
   assert (tc = '0') report "TC errado no COUNT (HOLD)";

   wait until falling_edge(clk);
   assert (q = "0001") report "COUNT (HOLD) falhou";
   assert (tc = '0') report "TC errado no COUNT (HOLD)";

   -- ==== COUNT & RESET test ====
   -- inicializacao
   cet <= '1';
   cep <= '1';
   pe <= '1';
   reset <= '0';
   wait for 1 ns;
   assert (q /= "0000") report "RESET assincrono";
   wait until falling_edge(clk);
   assert (q = "0000") report "RESET falhou";
   assert (tc = '0') report "TC errado no RESET";
   reset <= '1';

   -- Sequencia de clocks
   wait until falling_edge(clk);
   assert (q = "0001") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   wait until falling_edge(clk);
   assert (q = "0010") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   wait until falling_edge(clk);
   assert (q = "0011") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   wait until falling_edge(clk);
   assert (q = "0100") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   wait until falling_edge(clk);
   assert (q = "0101") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   -- RESET
   reset <= '0';
   wait for 1 ns;
   assert (q /= "0000") report "RESET assincrono";
   wait until falling_edge(clk);
   assert (q = "0000") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   wait until falling_edge(clk);
   assert (q = "0000") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   wait until falling_edge(clk);
   assert (q = "0000") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";
   reset <= '1';

   -- Sequencia de clocks
   wait until falling_edge(clk);
   assert (q = "0001") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   wait until falling_edge(clk);
   assert (q = "0010") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   wait until falling_edge(clk);
   assert (q = "0011") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   wait until falling_edge(clk);
   assert (q = "0100") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   wait until falling_edge(clk);
   assert (q = "0101") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   -- Disable CET & CEP
   cet <= '0';
   cep <= '0';
   wait until falling_edge(clk);
   assert (q = "0101") report "COUNT (HOLD) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   wait until falling_edge(clk);
   assert (q = "0101") report "COUNT (HOLD) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   wait until falling_edge(clk);
   assert (q = "0101") report "COUNT (HOLD) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   -- RESET com HOLD
   reset <= '0';
   wait for 1 ns;
   assert (q /= "0000") report "RESET assincrono";
   wait until falling_edge(clk);
   assert (q = "0000") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";
   cet <= '1';
   cep <= '1';
   reset <= '1';   

-- Sequencia de clocks
   wait until falling_edge(clk);
   assert (q = "0001") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   wait until falling_edge(clk);
   assert (q = "0010") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   wait until falling_edge(clk);
   assert (q = "0011") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   wait until falling_edge(clk);
   assert (q = "0100") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   wait until falling_edge(clk);
   assert (q = "0101") report "COUNT (RESET) falhou";
   assert (tc = '0') report "TC errado no COUNT (RESET)";

   wait;

end process;

end Behavioral;