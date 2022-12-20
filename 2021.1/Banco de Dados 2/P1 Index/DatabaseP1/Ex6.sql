-- 6) Compare na prática o custo de executar uma consulta com e sem um índice clusterizado
-- na tabela aluno. Ou seja, faça uma consulta sobre algum dado indexado, clusterize a tabela naquele
-- índice e refaça a consulta. Mostre os comandos e os resultados do explain analyze:

    -- Criando o índice em idade:
        create index idxalunoidade on Aluno(idade);

    -- Busca:
        select A.nome as Nome, A.idade as Idade
        from Aluno A
        where A.idade<27 and A.idade>23
        order by A.idade asc, A.nome asc;

    -- EXPLAIN ANALYZE (sem índice clusterizado)
    --            Sort  (cost=112.87..114.68 rows=723 width=11) (actual time=1.901..1.920 rows=723 loops=1)
    --          Sort Key: idade, nome
    --          Sort Method: quicksort  Memory: 59kB
    --          ->  Bitmap Heap Scan on aluno a  (cost=19.69..78.54 rows=723 width=11) (actual time=0.073..0.143 rows=723 loops=1)
    --                Recheck Cond: ((idade < '27'::numeric) AND (idade > '23'::numeric))
    --                Heap Blocks: exact=9
    --                ->  Bitmap Index Scan on idxalunoidade  (cost=0.00..19.51 rows=723 width=0) (actual time=0.067..0.067 rows=723 loops=1)
    --                      Index Cond: ((idade < '27'::numeric) AND (idade > '23'::numeric))
    --        Planning Time: 0.107 ms
    --        Execution Time: 1.950 ms

    -- Clusterizando a tabela Aluno no índice idxalunoidade
        ALTER TABLE aluno CLUSTER ON idxalunoidade;
        analyze aluno;
        cluster aluno;

    -- EXPLAIN ANALYZE (com índice Clusterizado)
    --        Sort  (cost=73.07..74.88 rows=723 width=11) (actual time=1.937..1.957 rows=723 loops=1)
    --      Sort Key: idade, nome
    --      Sort Method: quicksort  Memory: 59kB
    --      ->  Index Scan using idxalunoidade on aluno a  (cost=0.28..38.74 rows=723 width=11) (actual time=0.044..0.174 rows=723 loops=1)
    --            Index Cond: ((idade < '27'::numeric) AND (idade > '23'::numeric))
    --    Planning Time: 2.000 ms
    --    Execution Time: 1.980 ms

    
