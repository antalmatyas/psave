
--1. Feladat. Az egyes gyógyszereket hányszor használták kezelésre? 
SELECT drug, 
       Count(*) 
FROM   treatment 
GROUP  BY drug; 

--2. Feladat. Listázd ki azokat a gyógyszereket, amiket legalább 2x használták valamilyen kezelésben!

SELECT drug, 
       Count(*) 
FROM   treatment 
GROUP  BY drug
HAVING count(*)>=2;

--3. Feladat. Listázd ki betegekként a kezelések számát! (id, név, kezelések száma)

SELECT patient.patient_name, patient.patient_id, count(treatment.treatment_id)
FROM patient
INNER JOIN treatment
ON patient.patient_id=treatment.patient_id
GROUP BY patient.patient_name,
		 patient.patient_id;

--4. Feladat. A 2. feladatot megoldását egészítsd egy ki egy új oszloppal, ami a kezelések összköltségét tartalmazza!

SELECT drug, 
       Count(*),
       sum(t_cost)
FROM   treatment 
GROUP  BY drug
HAVING count(*)>=2;

--5. Feladat. Melyik orvos hány kezelést végzett el? (Csak azokat listázd, akik legalább 1 kezelést végeztek el)

SELECT t1.consultant, t2.staff_name, count(t1.treatment_id)
FROM treatment t1
inner JOIN staff t2
ON t1.consultant=t2.staff_id
GROUP BY t1.consultant, t2.staff_name
HAVING count(treatment_id)>=1;


--6. Feladat. Írd ki azokat az orvosokat, akik legalább 2kezelést végeztek el. 
SELECT t0.consultant, 
       t1.staff_name, 
       Count(treatment_id) 
FROM   treatment t0 
       INNER JOIN staff t1 
               ON t1.staff_id = t0.consultant 
GROUP  BY t0.consultant, 
          t1.staff_name 
HAVING Count(treatment_id) > 1; 

--7. Feladat. Az egyes beosztásokban (staff.post) mik az átlagos jövedelmek? 
SELECT post, Avg(salary)
FROM   staff 
GROUP  BY post;   

--8. Feladat. Mi a fonokok atlagos jovedelme?

SELECT avg(salary)
FROM staff
WHERE staff_id IN (SELECT manager_id
                   FROM staff);
                   
SELECT avg(salary)
FROM staff
group by POST
having post='Manager';


--9. Feladat. �?tlagosan, aki főnök vagy orvos mennyivel keres többet azoknál, akik nem tartoznak ezekbe a csoportokba (se nem főnök, se nem orvos)? 	  

SELECT
 (SELECT avg(salary)
  FROM staff
  WHERE staff_id IN (SELECT manager_id
                   FROM staff)
  OR staff_name LIKE 'Dr%')
  -
  (SELECT avg(salary)
  FROM staff
  WHERE staff_id NOT IN (SELECT manager_id
                   FROM staff
				   WHERE manager_id IS NOT NULL)
  AND staff_name NOT LIKE 'Dr%') AS difference from dual;
 
