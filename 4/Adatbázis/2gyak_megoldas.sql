--0. Feladat. Users table

SELECT * FROM user_tables;

--1. Feladat. Listazd ki a betegeket az aktualis eletkorukkal (age mezo: eletkor elso felvetelkor)
SELECT patient_id,
       patient_name,
       age,
       admission_date,
       Round(( SYSDATE - admission_date ) / 365) + age
FROM   patient;

--2. Feladat. Listazd ki azokat a pacienseket koruk szerint csokkeno sorrendbe rendezve (azonos kor eseten nevsorban), akik 2005.01.01. utan kerultek felvetelre!
SELECT *
FROM   patient
WHERE  admission_date >= To_date('20050101', 'yyyymmdd')
ORDER  BY age DESC,
          patient_name;

--3. Feladat. P9500 azonositoju beteg diagnozisa megvaltozott moderate-rol severe-re. Ennek megfeleloen frissitsd az adatbazist!
UPDATE patient
SET ALZHEIMER_DIAGNOSIS = 'severe'
WHERE patient_id        = 'P9500';

--4. Feladat. Opcionalis: Frissitsd az eletkort ugy, hogy az aktualis eletkort mutassa, ne pedig a felvetelkorit!
UPDATE patient
SET age = ROUND(( SYSDATE - admission_date ) / 365) + age;


--5. Feladat. Torold az osszes nonemu beteget!
DELETE
FROM patient
WHERE sex ='female';

--6. Feladat. A Henry Kip nevu beteget athelyeztek, torold az adatbazisbol!
DELETE
FROM patient
WHERE patient_name = 'Henry Kip';

alter table treatment drop constraint SYS_C0018653;

--7. Feladat. Torold az osszes rekordot a tablabol!  

DELETE
FROM patient;

--8. Feladat. Mik az 'Ar' karaktereket tartalmazo betegek adatai?
SELECT *
FROM patient
WHERE patient_name LIKE '%Ar%'
OR patient_name LIKE '%ar%';

--9. Feladat. Mi az azonositoja es a kora a ' Henry' string-gel kezdodo betegeknek?
SELECT patient_id, age
FROM patient
WHERE patient_name LIKE 'Henry%';		  

--10. Feladat. Valasszatok ki azokat a sorokat a treatment tablabol, amelyek cost attributuma nem 'ures'!
SELECT * 
FROM   treatment 
WHERE  t_cost IS NOT NULL; 

--11. Feladat. Valasszatok ki az osszes rekordot, de ugy, hogy a Cost mezoben hianyzo ertekeket 0-val helyettesititek! (Hasznald az nvl() fuggvenyt)
SELECT treatment_id, patient_id, NVL(t_cost, '0') 
FROM treatment;

--12. Feladat. Mit ad vissza a kovetkezo lekerdezes?  (ahol NULL azt nem adja vissza)
SELECT *
FROM   treatment
WHERE  t_cost < 60
       OR t_cost >= 60;
       
select * from treatment;
       	   
--13. Feladat.	ird ki a gyogyszerek nevet kisbetuvel!
SELECT drug, Lower(drug) 
FROM treatment;

--14. Feladat.	Mennyi az atlag fizetes?
SELECT Avg(salary) as "Átlag fizetés"
FROM STAFF;

--15. Feladat.	Egy honapban a korhaz mennyi penzt kolt a dolgozok fizetesere?
SELECT Sum(salary)
FROM STAFF;

--16. Feladat.	Mikor volt a legkorabbi es a legkesobbi kezeles?
SELECT Min(t_time) as legkorabbi_kezeles, 
       Max(t_time) as legkesobbi_kezeles 
FROM   treatment;

--17. Feladat.	Hany kezeles volt osszesen?
SELECT Count(*)
FROM treatment;

--18. Feladat.	Hanyszor adtak gyogyszert osszesen?
SELECT Count(drug)
FROM treatment;

select * from treatment;

--19. Feladat.	Opcionális: mi a betegek vezeték - es keresztneve? Milyen fuggvenyek kellenek ehhez? (hasznald a google-t)
SELECT patient_name, 
       Substr(patient_name, 0, Instr(patient_name, ' '))   keresztnev, 
       Substr(patient_name, Instr( patient_name, ' ') + 1) vezeteknev 
FROM   patient; 
