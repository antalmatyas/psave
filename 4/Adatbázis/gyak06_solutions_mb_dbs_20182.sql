
---- INLINE n�zet

-- El�sz�r megn�zz�k a t�bl�kat

SELECT dcu_id FROM dcdb.dc_usage;
SELECT * FROM dcdb.components;
SELECT * FROM DCDB.ATC_CODES;
SELECT * FROM DCDB.TARGETS;

--1. Feladat. Az egyes gy�gyszerekhez (components), h�ny darab ATC k�d tartozik (atc_codes)? (Azokat a komponenseket is vedd figyelembe, amelyekhez nincsen ATC k�d annot�lva.)
SELECT t0.dcc_id,
  COUNT(t1.ATC_ID) nr_atc_codes
FROM dcdb.components t0
LEFT OUTER JOIN DCDB.DCC_TO_ATC t1
ON t1.dcc_id = t0.dcc_id
GROUP BY t0.dcc_id;

--2. Feladat. Az egyes gy�gyszereknek h�ny darab c�lpontjuk van? (targets)
SELECT t0.dcc_id,
  COUNT(t1.tar_id) nr_targets
FROM DCDB.components t0
LEFT OUTER JOIN DCDB.DCC_TO_TARGETS t1
ON t0.dcc_id = t1.dcc_id
GROUP BY t0.dcc_id;

select* from dcdb.dcc_to_atc;

--3. Feladat. Az egyes gy�gyszereknek h�ny darab c�lpontjuk �s h�ny darab ATC k�djuk van? (egym�s mellett ki�rva)
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

  
---- Analitikus f�ggv�nyek

--4. Feladat. �rd ki tant�rgyank�nt az �tlagpontokat!

select tantargy, avg(pontszam) atlagpont
from verseny
group by TANTARGY;

select tantargy, versenyzo, pontszam, avg(pontszam) over(partition by tantargy) atlagpont
from verseny;

--5. Feladat. �rd ki, hogy ki h�ny ponttal t�rt el az �tlagpontt�l (tant�rgyank�nt)!

SELECT tantargy, versenyzo, pontszam,
floor(pontszam -(AVG(pontszam) OVER(PARTITION BY tantargy))) atlagponttol_elteres
FROM verseny;


--6. Feladat.�rd ki tant�rgyank�nt az els� 3 helyezettet!
SELECT * FROM(
SELECT tantargy, versenyzo, pontszam,
RANK() OVER(PARTITION BY tantargy ORDER BY pontszam DESC) rangsor,
DENSE_RANK() OVER(PARTITION BY tantargy ORDER BY pontszam DESC)suru_rangsor
FROM verseny)
WHERE rangsor<4;

--7. Feladat.�rd ki, hogy ki h�ny ponttal maradt le az eggyel jobb helyezett�l (t�rgyank�nt)!
SELECT tantargy, versenyzo, pontszam,
LAG(pontszam) OVER(PARTITION BY tantargy ORDER BY pontszam DESC) elozo_ember_pontja,
(LAG(pontszam) OVER(PARTITION BY tantargy ORDER BY pontszam DESC)-pontszam) lemaradas
FROM verseny;

--8. feladat �rd az egyes gy�gyszerek mell�, hogy milyen ATC k�dok tartoznak hozz�juk! Az ATC k�dokat vessz�vel v�laszd el egym�st�l! A feladathoz haszn�ld a Listagg() f�ggv�nyt!
SELECT
t0.DCC_ID, t0.generic_name,
LISTAGG(t2.codes, '; ') WITHIN GROUP (ORDER BY t2.CODES desc)
FROM dcdb.components t0
LEFT OUTER JOIN DCDB.DCC_TO_ATC t1
ON t1.dcc_id= t0.dcc_id
LEFT OUTER JOIN DCDB.ATC_CODES t2
ON t2.atc_id = t1.atc_id
GROUP BY t0.dcc_id, t0.generic_name;


--9. Feladat. K�s�rletenk�nt (exp_id) rangsorold a kombin�ci�kat a score-k alapj�n! (jaccard_auc t�bla)
SELECT 
exp_id,
dc_id,
jm,
rank() OVER (PARTITION BY exp_id ORDER BY jm DESC) sima_rang,
dense_rank() OVER (PARTITION BY exp_id ORDER BY jm DESC) suru_rank
FROM dcdb.jaccard_auc;

--10. Feladat. T�rgyank�nt az indulok neve, pontszam szerint sorrendben:

SELECT
tantargy,
LISTAGG(versenyzo, '; ') WITHIN GROUP (ORDER BY pontszam desc)
FROM verseny
Group by TANTARGY;


