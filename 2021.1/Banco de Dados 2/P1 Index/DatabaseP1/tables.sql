CREATE TABLE Aluno(
    id SERIAL PRIMARY KEY,
    RA DECIMAL(8) UNIQUE,
    Nome VARCHAR(50),
    DataNasc DATE,
    Idade DECIMAL(3),
    NomeMae VARCHAR(50),
    Cidade VARCHAR(30),
    Estado CHAR(2),
    Curso VARCHAR(50),
    Periodo integer
);

CREATE TABLE Discip(
    id SERIAL PRIMARY KEY,
    Sigla CHAR(7) UNIQUE,
    Nome VARCHAR(25),
    SiglaPreReq CHAR(7),
    NNCred DECIMAL(2),
    Monitor DECIMAL(8),
    Depto CHAR(8)
);

CREATE TABLE Matricula(
    id SERIAL PRIMARY KEY,
    RA DECIMAL(8) UNIQUE,
    Sigla CHAR(7) UNIQUE,
    Ano CHAR(4),
    Semestre CHAR(1),
    CodTurma DECIMAL(4),
    NotaP1 NUMERIC(3,1),
    NotaP2 NUMERIC(3,1),
    NotaTrab NUMERIC(3,1),
    NotaFIM NUMERIC(3,1),
    Frequencia DECIMAL(3),
    CONSTRAINT FK_RA FOREIGN KEY (RA) REFERENCES Aluno(RA),
    CONSTRAINT FK_Sigla FOREIGN KEY (Sigla) REFERENCES Discip(Sigla)
);
