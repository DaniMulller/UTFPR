-- INDICE ALUNO - NOMEMAE - IDADE
        CREATE UNIQUE INDEX IdxAlunoNNI ON Aluno (Nome, NomeMae, Idade);
        drop index IdxAlunoNNI;

-- 1. Escreva uma consulta que utilize esse índice.
        select A.nome as Nome
        from Aluno A
        where idade = 20 and idade = 30 -- usando AND
        order by A.nome asc;

        -- EXPLAIN ANALYZE
        --            Result  (cost=0.28..195.18 rows=1 width=6) (actual time=0.000..0.001 rows=0 loops=1)
        --      One-Time Filter: false
        --      ->  Index Only Scan using idxalunonni on aluno a  (cost=0.28..195.18 rows=1 width=6) (never executed)
        --            Index Cond: (idade = '20'::numeric)
        --            Heap Fetches: 0
        --    Planning Time: 0.083 ms
        --    Execution Time: 0.009 ms

--------------------------------------------------------------------------------------------------------------------------------

-- 2. Mostre um exemplo onde o índice não é usado mesmo utilizando algum campo indexado na cláusula where, e explique por quê.
        select nome
        from Aluno 
        where nome like 'A%'
        order by nome asc;

        -- ou

        select A.nome as Nome
        from Aluno A
        where idade = 20 or idade = 30  -- usando OR
        order by A.nome asc;

        -- EXPLAIN ANALYZE 1
        --            Sort  (cost=208.25..209.09 rows=339 width=6) (actual time=1.103..1.112 rows=339 loops=1)
        --      Sort Key: nome
        --      Sort Method: quicksort  Memory: 40kB
        --      ->  Seq Scan on aluno  (cost=0.00..194.00 rows=339 width=6) (actual time=0.012..0.527 rows=339 loops=1)
        --            Filter: ((nome)::text ~~ 'A%'::text)
        --            Rows Removed by Filter: 7661
        --    Planning Time: 0.112 ms
        --    Execution Time: 1.131 ms

        -- EXPLAIN ANALYZE 2
        --            Sort  (cost=237.41..238.70 rows=519 width=6) (actual time=1.827..1.841 rows=528 loops=1)
        --      Sort Key: nome
        --      Sort Method: quicksort  Memory: 49kB
        --      ->  Seq Scan on aluno a  (cost=0.00..214.00 rows=519 width=6) (actual time=0.012..0.856 rows=528 loops=1)
        --            Filter: ((idade = '20'::numeric) OR (idade = '30'::numeric))
        --            Rows Removed by Filter: 7472
        --    Planning Time: 0.081 ms
        --    Execution Time: 1.862 ms

        -- Quando o where da expresão tem OR ou LIKE o index não acessado, pra usar o index é necessário fazer uma pesquisa com AND
