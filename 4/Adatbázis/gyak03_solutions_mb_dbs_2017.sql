
--1. Feladat. Melyik kezelest ki vegezte es mennyibe kerult? Az eredmenyt rendezd kezeles ara alapjan csokkeno sorrendbe!
SELECT t0.treatment_id, 
       t1.staff_name, 
       t0.t_cost 
FROM   treatment t0 
       INNER JOIN staff t1 
               ON t1.staff_id = t0.consultant
ORDER BY t0.t_cost desc;

SELECT t0.treatment_id, 
       t1.staff_name, 
       t0.t_cost 
FROM   treatment t0 
       RIGHT OUTER JOIN staff t1 
               ON t1.staff_id = t0.consultant
ORDER BY t0.t_cost desc;

--2. Feladat. Melyik beteget ki kezelte es mikor?
SELECT t0.patient_name, 
       t2.staff_name, 
       t1.t_time 
FROM   patient t0 
       INNER JOIN treatment t1 
               ON t1.patient_id = t0.patient_id 
       INNER JOIN staff t2 
               ON t2.staff_id = t1.consultant; 	  
               

--3. Feladat. Kinek ki a kozvetlen fonoke?
SELECT t0.staff_name beosztott, 
       t1.staff_name fonok
FROM   staff t0 
       INNER JOIN staff t1 
               ON t1.staff_id = t0.manager_id; 

--4. Feladat. Az eddig kezelesek soran milyen gyogyszereket hasznaltak?

Select drug
from treatment;

SELECT DISTINCT drug 
FROM   treatment;


--5. Feladat Listázd ki a paciensek es az orvosok id-jat, duplikaciok nelkul!


select distinct patient_id,consultant
from treatment;
	   
--6. Feladat.	Ki az, aki nem vegzett egyetlen kezelest sem?
SELECT staff_id
FROM   staff 
MINUS 
SELECT consultant 
FROM   treatment; 

--7. Feladat.	Ki az, aki fonoke valakinek, de nem o az igazgato?

SELECT manager_id 
FROM   staff 
where manager_id is not null
MINUS 
SELECT staff_id 
FROM   staff 
WHERE  manager_id IS NULL;


--8. Feladat.	Listazd ki az osszes korhazban levo ember nevet, es azt, hogy beteg-e, vagy alkalmazott!

SELECT staff_name    AS name, 
       'alkalmazott' AS status 
FROM   staff 
UNION 
SELECT patient_name, 
       'beteg' 
FROM   patient; 

--9. Feladat.	Hozz letre egy view-t a kovetkezo lekerdesekhez: melyik beteget ki kezelte es mikor? (2. feladat selectje!)
CREATE OR replace VIEW patientname2staff 
AS 
  SELECT t0.patient_name, 
         t2.staff_name, 
         t1.t_time 
  FROM   patient t0 
         inner join treatment t1 
                 ON t1.patient_id = t0.patient_id 
         inner join staff t2 
                 ON t2.staff_id = t1.consultant; 

--10. Feladat.	A nezet hasznalatanak segitsegevel valaszold meg, hogy mely betegeket kezelte Dr. Green 2004 oktobereben.
SELECT * 
FROM   patientname2staff 
WHERE  staff_name = 'Dr Green' 
       AND t_time > To_date('20041001', 'yyyymmdd') 
       AND t_time < To_date('20041101', 'yyyymmdd'); 

--11. Feladat.	Melyik dolgozonak mennyivel tobb vagy kevesebb a fizetese, mint az atlagos fizetes?
SELECT staff_id, 
       staff_name, 
       salary - (SELECT Avg(salary) 
                 FROM   staff) 
FROM   staff;

--12. Feladat.	Melyek azok az orvosok, aki vegeztek mar legalabb egy kezelest?
SELECT DISTINCT consultant 
FROM   treatment 
INTERSECT 
SELECT staff_id 
FROM   staff 
WHERE  staff_name LIKE 'Dr%'; 

-- Ezeket akar hasznalhatjuk is tovabbi lekerdezesekben pl. joinolhatunk is hozza (pl. az o nevuk kiirasa)
SELECT t0.staff_id, 
       t0.staff_name 
FROM   staff t0 
       inner join (SELECT DISTINCT consultant staff_id 
                   FROM   treatment 
                   INTERSECT 
                   SELECT staff_id 
                   FROM   staff 
                   WHERE  staff_name LIKE 'Dr%') t1 
               ON t1.staff_id = t0.staff_id; 

-- VAGY --- 
SELECT staff_id, 
       staff_name 
FROM   staff 
WHERE  staff_id IN (SELECT DISTINCT consultant staff_id 
                    FROM   treatment 
                    INTERSECT 
                    SELECT staff_id 
                    FROM   staff 
                    WHERE  staff_name LIKE 'Dr%');    

