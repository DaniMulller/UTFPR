-- 7) Acrescente um campo adicional na tabela de Aluno, chamado de informacoesExtras, do
-- tipo JSON. Insira dados diferentes telefônicos e de times de futebol que o aluno torce para cada aluno
-- neste JSON. Crie índices para o JSON e mostre consultas que o utiliza (explain analyze). Exemplo: retorne os alunos que torcem para o Internacional.

        ALTER TABLE Aluno ADD informacoesextras jsonb;

   -- Populando o JSONB com comandos
        -- Função Número aleatório (Quantidade max de digitos por parametro)
        create or replace function numero(digitos integer) returns integer as
        $$
	        begin
		        return trunc(random()*power(10,digitos));
	        end;
        $$language plpgsql;

        -- Populando...
        do $$
            declare varID int;
	        declare varTimes varchar[] = '{"palmeiras","fortaleza","flamengo","internacional","santos","gremio","bahia","corinthians","sao paulo","fluminense","vasco","botafogo"}';
	        begin
                for i in 1..4000
                    for j in 1..12 loop
	                    select id into varID
                        from aluno
                        order by random()
                        limit 1;
                        update Aluno
                        set informacoesextras = (
                            (
                                '{
                                "telefone" : ' || numero(9) || ',
                                "time" : "' || varTimes [j] || '"
                                }'
                            )::json
                          )
                        where id = varID;
                end loop;
	        end loop;
        end; $$
        language plpgsql;
        analyze aluno;

   -- Retornar os alunos que torcem para o Internacional:
        select nome, informacoesextras ->> 'time' as timefut
        from aluno
        where informacoesextras ->> 'time' = 'internacional';

   -- EXPLAIN ANALYZE
   --            Seq Scan on aluno  (cost=0.00..176.05 rows=20 width=38) (actual time=0.168..0.624 rows=224 loops=1)
   --           Filter: ((informacoesextras ->> 'time'::text) = 'internacional'::text)
   --           Rows Removed by Filter: 3776
   --         Planning Time: 0.052 ms
   --         Execution Time: 0.637 ms

   -- Criando indice em time de futebol na tabela Aluno
        create index idxTime on Aluno using BTREE((informacoesextras->>'time'));

    -- Realizando a mesma busca feita anterirormente
    -- EXPLAIN ANALYZE
    --            Bitmap Heap Scan on aluno  (cost=4.44..57.72 rows=20 width=38) (actual time=0.061..0.147 rows=224 loops=1)
    --          Recheck Cond: ((informacoesextras ->> 'time'::text) = 'internacional'::text)
    --          Heap Blocks: exact=68
    --          ->  Bitmap Index Scan on idxtime  (cost=0.00..4.43 rows=20 width=0) (actual time=0.051..0.051 rows=224 loops=1)
    --                Index Cond: ((informacoesextras ->> 'time'::text) = 'internacional'::text)
    --        Planning Time: 0.935 ms
    --        Execution Time: 0.173 ms
