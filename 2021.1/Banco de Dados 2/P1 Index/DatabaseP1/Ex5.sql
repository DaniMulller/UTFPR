-- 5) Utilize um indice bitmap para periodo e mostre-o em uso nas consultas.

    -- Criando a extensão e o índice Bitmap:
        create extension btree_gin;
        CREATE INDEX IdxAluno9Bitmap ON Aluno using gin(periodo);

    -- Busca simples de Alunos no 9º período:
        select A.nome as Nome, A.periodo as Periodo
        from Aluno A
        where A.periodo=9
        order by A.nome asc

    -- EXPLAIN ANALYZE
    --        Sort  (cost=78.59..79.63 rows=417 width=10) (actual time=0.878..0.890 rows=417 loops=1)
    --      Sort Key: nome
    --      Sort Method: quicksort  Memory: 44kB
    --      ->  Bitmap Heap Scan on aluno a  (cost=11.23..60.44 rows=417 width=10) (actual time=0.050..0.139 rows=417 loops=1)
    --            Recheck Cond: (periodo = 9)
    --            Heap Blocks: exact=44
    --            ->  Bitmap Index Scan on idxaluno9bitmap  (cost=0.00..11.13 rows=417 width=0) (actual time=0.043..0.043 rows=417 loops=1)
    --                  Index Cond: (periodo = 9)
    --    Planning Time: 0.949 ms
    --    Execution Time: 0.929 ms
