DROP TABLE DB1_TERMES cascade constraint purge;
DROP TABLE DB1_OSTERMELO cascade constraint purge;

CREATE TABLE "DB1_OSTERMELO"
  (
     "ID"           NUMBER(8, 0),
     "VEZETEKNEV"   VARCHAR2(30),
     "KERESZTNEV"   VARCHAR2(30),
     "IRANYITOSZAM" NUMBER(4, 0),
     "TELEPULES"    VARCHAR2(30),
     "UTCA"         VARCHAR2(30),
     "HAZSZAM"      VARCHAR2(5),
     "FOLDTERULET"  NUMBER(3, 0)
  );
CREATE TABLE "DB1_TERMES"
  (
     "ID"           NUMBER(8, 0),
     "OSTERMELO_ID" NUMBER(8, 0),
     "EV"           NUMBER(4, 0),
     "TERMEK"       VARCHAR2(30),
     "MENNYISEG"    NUMBER(4, 0)
  );

ALTER TABLE "DB1_OSTERMELO" ADD constraint "DB1_OSTERMELO_PK" primary key ("ID");
ALTER TABLE "DB1_OSTERMELO" MODIFY ("ID" NOT NULL enable);
ALTER TABLE "DB1_OSTERMELO" MODIFY ("VEZETEKNEV" NOT NULL enable);  
ALTER TABLE "DB1_TERMES" ADD constraint "DB1_TERMES_PK" primary key ("ID");
ALTER TABLE "DB1_TERMES" MODIFY ("ID" NOT NULL enable);
ALTER TABLE "DB1_TERMES" ADD constraint "DB1_TERMES_TERMELO" foreign key ("OSTERMELO_ID") references "DB1_OSTERMELO" ("ID") enable;  

INSERT INTO db1_ostermelo
            (id,vezeteknev,keresztnev,iranyitoszam,telepules,utca,hazszam,
             foldterulet)
VALUES      (1,'Minta','Anna',8642,'Aszófõ','Kossuth','44',4);

INSERT INTO db1_ostermelo
            (id,vezeteknev,keresztnev,iranyitoszam,telepules,utca,hazszam,
             foldterulet)
VALUES      (2,'Tóth','János',2478,'Pázmánd','Mátyás','33',7);

INSERT INTO db1_ostermelo
            (id,vezeteknev,keresztnev,iranyitoszam,telepules,utca,hazszam,
             foldterulet)
VALUES      (3,'Kiss','Zsombor',3477,'Rozsály','Domb','7',12);

INSERT INTO db1_ostermelo
            (id,vezeteknev,keresztnev,iranyitoszam,telepules,utca,hazszam,
             foldterulet)
VALUES      (4,'Kovács','István',4478,'Hosszúhetény','Kanyargós','47',9);

INSERT INTO db1_ostermelo
            (id,vezeteknev,keresztnev,iranyitoszam,telepules,utca,hazszam,
             foldterulet)
VALUES      (5,'Takács','Nándor',7847,'Székkutas','Kossuth','17',20);
INSERT INTO db1_termes
            (id,ostermelo_id,ev,termek,mennyiseg)
VALUES      (1,1,2010,'burgonya',100);

INSERT INTO db1_termes
        	(id,ostermelo_id,ev,termek,mennyiseg)
VALUES      (2,1,2010,'paradicsom',30);

INSERT INTO db1_termes
        	(id,ostermelo_id,ev,termek,mennyiseg)
VALUES      (3,1,2011,'paradicsom',15);

INSERT INTO db1_termes
        	(id,ostermelo_id,ev,termek,mennyiseg)
VALUES      (4,2,2010,'burgonya',500);

INSERT INTO db1_termes
        	(id,ostermelo_id,ev,termek,mennyiseg)
VALUES      (5,2,2010,'rózsaburgonya',600);

INSERT INTO db1_termes
        	(id,ostermelo_id,ev,termek,mennyiseg)
VALUES      (6,3,2011,'vöröshagyma',170);

INSERT INTO db1_termes
        	(id,ostermelo_id,ev,termek,mennyiseg)
VALUES      (7,3,2011,'póréhagyma',20);

INSERT INTO db1_termes
        	(id,ostermelo_id,ev,termek,mennyiseg)
VALUES      (8,3,2011,'görögdinnye',600);

INSERT INTO db1_termes
        	(id,ostermelo_id,ev,termek,mennyiseg)
VALUES      (9,4,2010,'sárgarépa',120);

INSERT INTO db1_termes
        	(id,ostermelo_id,ev,termek,mennyiseg)
VALUES      (10,4,2010,'zöldborsó',70);

INSERT INTO db1_termes
        	(id,ostermelo_id,ev,termek,mennyiseg)
VALUES      (11,4,2011,'sárgarépa',150);

INSERT INTO db1_termes
        	(id,ostermelo_id,ev,termek,mennyiseg)
VALUES      (12,4,2011,'csemegekukorica',600);

INSERT INTO db1_termes
        	(id,ostermelo_id,ev,termek,mennyiseg)
VALUES      (13,4,2011,'zöldborsó',90);

INSERT INTO db1_termes
        	(id,ostermelo_id,ev,termek,mennyiseg)
VALUES      (14,5,2011,'paradiccsom',70);

INSERT INTO db1_termes
        	(id,ostermelo_id,ev,termek,mennyiseg)
VALUES      (15,5,2011,'zöldborsó',90);

INSERT INTO db1_termes
        	(id,ostermelo_id,ev,termek,mennyiseg)
VALUES      (16,5,2011,'uborka',40);

COMMIT;

