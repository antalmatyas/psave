
---- INLINE nézet

-- Elõször megnézzük a táblákat

SELECT dcu_id FROM dcdb.dc_usage;
SELECT * FROM dcdb.components;
SELECT * FROM DCDB.ATC_CODES;
SELECT * FROM DCDB.TARGETS;

--1. Feladat. Az egyes gyógyszerekhez (components), hány darab ATC kód tartozik (atc_codes)? (Azokat a komponenseket is vedd figyelembe, amelyekhez nincsen ATC kód annotálva.)
SELECT t0.dcc_id,
  COUNT(t1.ATC_ID) nr_atc_codes
FROM dcdb.components t0
LEFT OUTER JOIN DCDB.DCC_TO_ATC t1
ON t1.dcc_id = t0.dcc_id
GROUP BY t0.dcc_id;

--2. Feladat. Az egyes gyógyszereknek hány darab célpontjuk van? (targets)
SELECT t0.dcc_id,
  COUNT(t1.tar_id) nr_targets
FROM DCDB.components t0
LEFT OUTER JOIN DCDB.DCC_TO_TARGETS t1
ON t0.dcc_id = t1.dcc_id
GROUP BY t0.dcc_id;

select* from dcdb.dcc_to_atc;

--3. Feladat. Az egyes gyógyszereknek hány darab célpontjuk és hány darab ATC kódjuk van? (egymás mellett kiírva)
SELECT t0.dcc_id,
  t0.nr_atc_codes,
  COUNT(t1.tar_id) nr_targets
FROM
  (SELECT t0.dcc_id,
    COUNT(t1.ATC_ID) nr_atc_codes
  FROM dcdb.components t0
  LEFT OUTER JOIN DCDB.DCC_TO_ATC t1
  ON t1.dcc_id = t0.dcc_id
  GROUP BY t0.dcc_id
  ) t0
LEFT OUTER JOIN DCDB.DCC_TO_TARGETS t1
ON t0.dcc_id = t1.dcc_id
GROUP BY t0.dcc_id,
  t0.nr_atc_codes ;

  
---- Analitikus függvények

--4. Feladat. Írd ki tantárgyanként az átlagpontokat!

select tantargy, avg(pontszam) atlagpont
from verseny
group by TANTARGY;

select tantargy, versenyzo, pontszam, avg(pontszam) over(partition by tantargy) atlagpont
from verseny;

--5. Feladat. Írd ki, hogy ki hány ponttal tért el az átlagponttól (tantárgyanként)!

SELECT tantargy, versenyzo, pontszam,
floor(pontszam -(AVG(pontszam) OVER(PARTITION BY tantargy))) atlagponttol_elteres
FROM verseny;


--6. Feladat.Írd ki tantárgyanként az elsõ 3 helyezettet!
SELECT * FROM(
SELECT tantargy, versenyzo, pontszam,
RANK() OVER(PARTITION BY tantargy ORDER BY pontszam DESC) rangsor,
DENSE_RANK() OVER(PARTITION BY tantargy ORDER BY pontszam DESC)suru_rangsor
FROM verseny)
WHERE rangsor<4;

--7. Feladat.Írd ki, hogy ki hány ponttal maradt le az eggyel jobb helyezettõl (tárgyanként)!
SELECT tantargy, versenyzo, pontszam,
LAG(pontszam) OVER(PARTITION BY tantargy ORDER BY pontszam DESC) elozo_ember_pontja,
(LAG(pontszam) OVER(PARTITION BY tantargy ORDER BY pontszam DESC)-pontszam) lemaradas
FROM verseny;

--8. feladat Írd az egyes gyógyszerek mellé, hogy milyen ATC kódok tartoznak hozzájuk! Az ATC kódokat vesszõvel válaszd el egymástól! A feladathoz használd a Listagg() függvényt!
SELECT
t0.DCC_ID, t0.generic_name,
LISTAGG(t2.codes, '; ') WITHIN GROUP (ORDER BY t2.CODES desc)
FROM dcdb.components t0
LEFT OUTER JOIN DCDB.DCC_TO_ATC t1
ON t1.dcc_id= t0.dcc_id
LEFT OUTER JOIN DCDB.ATC_CODES t2
ON t2.atc_id = t1.atc_id
GROUP BY t0.dcc_id, t0.generic_name;


--9. Feladat. Kísérletenként (exp_id) rangsorold a kombinációkat a score-k alapján! (jaccard_auc tábla)
SELECT 
exp_id,
dc_id,
jm,
rank() OVER (PARTITION BY exp_id ORDER BY jm DESC) sima_rang,
dense_rank() OVER (PARTITION BY exp_id ORDER BY jm DESC) suru_rank
FROM dcdb.jaccard_auc;

--10. Feladat. Tárgyanként az indulok neve, pontszam szerint sorrendben:

SELECT
tantargy,
LISTAGG(versenyzo, '; ') WITHIN GROUP (ORDER BY pontszam desc)
FROM verseny
Group by TANTARGY;


