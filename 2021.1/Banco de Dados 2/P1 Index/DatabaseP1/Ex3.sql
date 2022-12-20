-- 3) Crie índices e mostre exemplos de consultas (resultados e explain) que usam os seguintes tipos de acessos:
   -- a) Sequential Scan
                    -- Buscar todos os RA's dos monitores
                        select D.monitor as RA_Monitor
                        from Discip D;

                    -- EXPLAIN
                    --   Seq Scan on discip d  (cost=0.00..90.00 rows=4000 width=6)

   -- b) Bitmap Index Scan
                    -- Indice que recupera os Alunos no perto do fim do curso    
                        CREATE INDEX IdxAluno9 ON Aluno(Nome) where Aluno.periodo = 9;

                    -- Buscar Alunos que se formaram no fim de 2013
                        select A.nome as nome, A.periodo as Periodo, M.ano as Ano 
                        from Aluno A join Matricula M on A.RA=M.RA
                        where A.periodo='9' and M.ano='2013'
                        order by A.nome asc;

                    -- EXPLAIN
                    --  Sort  (cost=206.25..206.26 rows=4 width=15)
                    --    Sort Key: a.nome
                    --    ->  Hash Join  (cost=155.90..206.21 rows=4 width=15)
                    --          Hash Cond: (a.ra = m.ra)
                    --          ->  Bitmap Heap Scan on aluno a  (cost=18.46..67.67 rows=417 width=17)
                    --                Recheck Cond: (periodo = 9)
                    --                ->  Bitmap Index Scan on idxaluno9  (cost=0.00..18.36 rows=417 width=0)
                    --          ->  Hash  (cost=137.00..137.00 rows=35 width=12)
                    --                ->  Seq Scan on matricula m  (cost=0.00..137.00 rows=35 width=12)
                    --                      Filter: (ano = '2013'::bpchar)

   -- c) Index Scan
                    -- Indice criado como PrimaryKey de Discip (discip_pkey)
                    -- Busca simples de 10 RA's de monitores
                        select D.monitor as RA_Monitor
                        from Discip D
                        where D.id<10;

                    -- EXPLAIN
                    -- Index Scan using discip_pkey on discip d  (cost=0.28..8.44 rows=9 width=6)
                    --    Index Cond: (id < 10)               
          
   -- d) Index-Only Scan
                    -- Indice que indica o RA dos alunos que passaram com mais de 90 na Nota Final
                        CREATE INDEX IdxNotaFim90 ON Matricula(RA) where Matricula.notafim >= 90;
                        -- Reutilizando o Indice de alunos no 9º periodo ja criado

                    -- Buscar alunos no fim do curso que passaram com mais de 90 para oportunidade de intercâmbio
                        select A.nome as Nome, M.RA as RA
                        from Aluno A join Matricula M on A.RA=M.RA
                        where A.periodo=9 and M.notafim >=90
                        order by M.notafim desc, A.nome ASC;

                    -- EXPLAIN
                    --  Sort  (cost=185.13..185.23 rows=40 width=17)
                    --      Sort Key: m.notafim DESC, a.nome
                    --      ->  Hash Join  (cost=91.20..184.06 rows=40 width=17)
                    --           Hash Cond: (m.ra = a.ra)
                    --            ->  Bitmap Heap Scan on matricula m  (cost=18.31..110.16 rows=388 width=11)
                    --                  Recheck Cond: (notafim >= '90'::numeric)
                    --                  ->  Bitmap Index Scan on idxnotafim90  (cost=0.00..18.21 rows=388 width=0)
                    --            ->  Hash  (cost=67.67..67.67 rows=417 width=13)
                    --                  ->  Bitmap Heap Scan on aluno a  (cost=18.46..67.67 rows=417 width=13)
                    --                        Recheck Cond: (periodo = 9)
                    --                        ->  Bitmap Index Scan on idxaluno9  (cost=0.00..18.36 rows=417 width=0)

   -- e) Multi-Index Scan
                    -- Indice que mostra RA de alunos com 90% ou mais de Frequencia nas aulas
                        CREATE INDEX IdxFreq90 ON Matricula(RA) where Matricula.frequencia >= 90;
                        -- Reutilizando os Indices de alunos no 9º periodo e de NotaFIM>=90 ja criados

                    -- Buscar alunos no fim do curso que passaram com mais de 90 de nota e no mínimo 90% de frequencia para oportunidade de intercâmbio
                        select A.nome as Nome, M.RA as RA
                        from Aluno A join Matricula M on A.RA=M.RA
                        where A.periodo=9 and M.notafim >=90 and M.frequencia >=90
                        order by M.notafim desc, A.nome asc;

                    -- EXPLAIN (foram usados vários índices nessa consulta)
                    -- Sort  (cost=180.32..180.33 rows=4 width=17)
                    --   Sort Key: m.notafim DESC, a.nome
                    --  ->  Hash Join  (cost=129.97..180.28 rows=4 width=17)
                    --        Hash Cond: (a.ra = m.ra)
                    --        ->  Bitmap Heap Scan on aluno a  (cost=18.46..67.67 rows=417 width=13)
                    --              Recheck Cond: (periodo = 9)
                    --              ->  Bitmap Index Scan on idxaluno9  (cost=0.00..18.36 rows=417 width=0)
                    --        ->  Hash  (cost=110.97..110.97 rows=43 width=11)
                    --              ->  Bitmap Heap Scan on matricula m  (cost=36.93..110.97 rows=43 width=11)
                    --                    Recheck Cond: ((notafim >= '90'::numeric) AND (frequencia >= '90'::numeric))
                    --                    ->  BitmapAnd  (cost=36.93..36.93 rows=43 width=0)
                    --                          ->  Bitmap Index Scan on idxnotafim90  (cost=0.00..18.21 rows=388 width=0)
                    --                          ->  Bitmap Index Scan on idxfreq90  (cost=0.00..18.44 rows=447 width=0)
