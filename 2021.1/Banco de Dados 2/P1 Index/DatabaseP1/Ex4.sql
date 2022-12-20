-- 4) Faca consultas com juncoes entre as tabelas e mostre o desempenho criando-se indices para cada chave estrangeira.

    --INDICE EM FK_RA

    --Utilizando os mesmos índices e a mesma busca realizada no Ex3, podemos notar a diferenca no tempo de resolucao do banco:
    --Busca sem Indices
        select A.nome as Nome, M.RA as RA
        from Aluno A join Matricula M on A.RA=M.RA
        where A.periodo=9 and M.notafim >=90 and M.frequencia >=90
        order by M.notafim desc, A.nome asc
    -- EXPLAIN ANALYZE
    --        Sort  (cost=242.67..242.68 rows=4 width=17) (actual time=0.916..0.917 rows=8 loops=1)
    --      Sort Key: m.notafim DESC, a.nome
    --      Sort Method: quicksort  Memory: 25kB
    --      ->  Hash Join  (cost=147.54..242.63 rows=4 width=17) (actual time=0.660..0.904 rows=8 loops=1)
    --            Hash Cond: (a.ra = m.ra)
    --            ->  Seq Scan on aluno a  (cost=0.00..94.00 rows=417 width=13) (actual time=0.013..0.334 rows=417 loops=1)
    --                  Filter: (periodo = 9)
    --                  Rows Removed by Filter: 3583
    --            ->  Hash  (cost=147.00..147.00 rows=43 width=11) (actual time=0.531..0.531 rows=43 loops=1)
    --                  Buckets: 1024  Batches: 1  Memory Usage: 10kB
    --                  ->  Seq Scan on matricula m  (cost=0.00..147.00 rows=43 width=11) (actual time=0.014..0.524 rows=43 loops=1)
    --                        Filter: ((notafim >= '90'::numeric) AND (frequencia >= '90'::numeric))
    --                        Rows Removed by Filter: 3957
    --    Planning Time: 0.189 ms
    --    Execution Time: 0.931 ms

    -- Criando os índices
        CREATE INDEX IdxFreq90 ON Matricula(RA) where Matricula.frequencia >= 90;
        CREATE INDEX IdxNotaFim90 ON Matricula(RA) where Matricula.notafim >= 90;
        CREATE INDEX IdxAluno9 ON Aluno(Nome) where Aluno.periodo = 9;

    -- Realiza-se a busca novamente
    -- EXPLAIN ANALYZE
    --        Sort  (cost=180.32..180.33 rows=4 width=17) (actual time=0.258..0.259 rows=8 loops=1)
    --      Sort Key: m.notafim DESC, a.nome
    --      Sort Method: quicksort  Memory: 25kB
    --      ->  Hash Join  (cost=129.97..180.28 rows=4 width=17) (actual time=0.178..0.247 rows=8 loops=1)
    --            Hash Cond: (a.ra = m.ra)
    --            ->  Bitmap Heap Scan on aluno a  (cost=18.46..67.67 rows=417 width=13) (actual time=0.041..0.102 rows=417 loops=1)
    --                  Recheck Cond: (periodo = 9)
    --                  Heap Blocks: exact=44
    --                  ->  Bitmap Index Scan on idxaluno9  (cost=0.00..18.36 rows=417 width=0) (actual time=0.034..0.034 rows=417 loops=1)
    --            ->  Hash  (cost=110.97..110.97 rows=43 width=11) (actual time=0.099..0.099 rows=43 loops=1)
    --                  Buckets: 1024  Batches: 1  Memory Usage: 10kB
    --                  ->  Bitmap Heap Scan on matricula m  (cost=36.93..110.97 rows=43 width=11) (actual time=0.073..0.090 rows=43 loops=1)
    --                        Recheck Cond: ((notafim >= '90'::numeric) AND (frequencia >= '90'::numeric))
    --                        Heap Blocks: exact=25
    --                        ->  BitmapAnd  (cost=36.93..36.93 rows=43 width=0) (actual time=0.070..0.071 rows=0 loops=1)
    --                              ->  Bitmap Index Scan on idxnotafim90  (cost=0.00..18.21 rows=388 width=0) (actual time=0.031..0.031 rows=388 loops=1)
    --                              ->  Bitmap Index Scan on idxfreq90  (cost=0.00..18.44 rows=447 width=0) (actual time=0.036..0.036 rows=434 loops=1)
    --    Planning Time: 2.020 ms
    --    Execution Time: 0.327 ms

    -- É possivel observar que o Tempo de Planejamento é maior com Indices mas o Tempo de Execucao é bem menor,
    -- considerando um banco com milhões de tuplas, os índices geralmente otimizam as buscas;

---------------------------------------------------------------------------------------------------------------------------------------------------------------------

    -- INDICE EM FK_SIGLA

    --Buscar Disciplinas do ano 2000, aluno e sua nota final
        select D.Sigla as SiglaDiscip, D.nome as NomeDiscip, A.nome as NomeAluno, M.NotaFIM as NotaFinal
        from Discip D join matricula m on D.sigla = m.sigla join aluno a on a.ra = m.ra
        where M.ano='2000'
        order by D.sigla asc

    -- Realiza-se a busca novamente
    -- EXPLAIN ANALYZE
    --        Sort  (cost=347.42..347.80 rows=153 width=44) (actual time=1.681..1.687 rows=153 loops=1)
    --        Sort Key: d.sigla
    --        Sort Method: quicksort  Memory: 37kB
    --        ->  Hash Join  (cost=235.34..341.87 rows=153 width=44) (actual time=0.984..1.440 rows=153 loops=1)
    --            Hash Cond: (d.sigla = m.sigla)
    --            ->  Seq Scan on discip d  (cost=0.00..90.00 rows=4000 width=34) (actual time=0.009..0.164 rows=4000 loops=1)
    --            ->  Hash  (cost=233.42..233.42 rows=153 width=18) (actual time=0.966..0.967 rows=153 loops=1)
    --                    Buckets: 1024  Batches: 1  Memory Usage: 16kB
    --                    ->  Hash Join  (cost=138.91..233.42 rows=153 width=18) (actual time=0.388..0.937 rows=153 loops=1)
    --                        Hash Cond: (a.ra = m.ra)
    --                        ->  Seq Scan on aluno a  (cost=0.00..84.00 rows=4000 width=13) (actual time=0.005..0.176 rows=4000 loops=1)
    --                        ->  Hash  (cost=137.00..137.00 rows=153 width=19) (actual time=0.376..0.376 rows=153 loops=1)
    --                                Buckets: 1024  Batches: 1  Memory Usage: 16kB
    --                                ->  Seq Scan on matricula m  (cost=0.00..137.00 rows=153 width=19) (actual time=0.010..0.346 rows=153 loops=1)
    --                                    Filter: (ano = '2000'::bpchar)
    --                                    Rows Removed by Filter: 3847
    --    Planning Time: 0.322 ms
    --    Execution Time: 1.710 ms

    -- Criando indice que guarda a Sigla da disciplina cursada no ano 2000
        CREATE INDEX IdxDiscipAno2000 ON Matricula(Sigla) where Matricula.ano = '2000';
    --EXPLAIN ANALYZE
    --        Sort  (cost=310.45..310.83 rows=153 width=44) (actual time=1.368..1.373 rows=153 loops=1)
    --      Sort Key: d.sigla
    --      Sort Method: quicksort  Memory: 37kB
    --      ->  Hash Join  (cost=198.37..304.90 rows=153 width=44) (actual time=0.672..1.129 rows=153 loops=1)
    --            Hash Cond: (d.sigla = m.sigla)
    --            ->  Seq Scan on discip d  (cost=0.00..90.00 rows=4000 width=34) (actual time=0.007..0.173 rows=4000 loops=1)
    --            ->  Hash  (cost=196.46..196.46 rows=153 width=18) (actual time=0.661..0.662 rows=153 loops=1)
    --                  Buckets: 1024  Batches: 1  Memory Usage: 16kB
    --                  ->  Hash Join  (cost=101.95..196.46 rows=153 width=18) (actual time=0.097..0.634 rows=153 loops=1)
    --                        Hash Cond: (a.ra = m.ra)
    --                        ->  Seq Scan on aluno a  (cost=0.00..84.00 rows=4000 width=13) (actual time=0.005..0.172 rows=4000 loops=1)
    --                        ->  Hash  (cost=100.03..100.03 rows=153 width=19) (actual time=0.086..0.086 rows=153 loops=1)
    --                               Buckets: 1024  Batches: 1  Memory Usage: 16kB
    --                              ->  Bitmap Heap Scan on matricula m  (cost=8.95..100.03 rows=153 width=19) (actual time=0.023..0.065 rows=153 loops=1)
    --                                    Recheck Cond: (ano = '2000'::bpchar)
    --                                    Heap Blocks: exact=42
    --                                    ->  Bitmap Index Scan on idxdiscipano2000  (cost=0.00..8.91 rows=153 width=0) (actual time=0.016..0.016 rows=153 loops=1)
    --    Planning Time: 1.183 ms
    --    Execution Time: 1.435 ms

    -- Assim como no primeiro exemplo, é possivel observar que o Tempo de Planejamento é maior com Indice mas o Tempo de Execucao é menor,
    -- considerando um banco com milhões de tuplas, o índice melhoraria o desempenho dessa simples busca;
