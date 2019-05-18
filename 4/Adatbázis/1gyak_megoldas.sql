

--1. Feladat. Hozd letre az alabbi tablakat sql-ben! Melyik oszlopnak mi lesz a tipusa?

CREATE TABLE patient(
 patient_id VARCHAR(255) PRIMARY KEY,
 name VARCHAR(255),
 sex VARCHAR(6),
 admission_date DATE,
 alzheimer_diagnosis VARCHAR(255)
 );
 
 CREATE TABLE treatment(
 	treatment_id VARCHAR(255) PRIMARY KEY,
 	patient_id VARCHAR(255),
 	drug VARCHAR(255),
 	cost NUMBER,
 	t_time DATE,
 	consultant VARCHAR(255),
 	FOREIGN KEY (patient_id) REFERENCES patient (patient_id)
);

-- 2. Feladat. A patient tablahoz add hozza az age attributumot!
ALTER TABLE patient ADD (age NUMBER);

-- 3. Feladat. Modosotsd ugy a patient tablat, hogy a p_name attributum megadasa kotelezo legyen!
ALTER TABLE patient MODIFY (name VARCHAR(255) NOT NULL);

-- 4. Feladat. A treatment nevu tablabol torld a consultant attributumot!
ALTER TABLE treatment DROP COLUMN  consultant;


-- 5. Feladat. Toroljetek a treatment tablat!

DROP TABLE treatment;

-- 6. Feladat. Toltsetek fel az alabbi adatokkal a korabban definialt tablat 

INSERT INTO patient
            (patient_id,
             name,
             sex,
             age,
             admission_date,
             alzheimer_diagnosis)
VALUES     ( 'P1500',
             'Irvin Brody',
             'male',
             46,
             To_date('24-10-2004', 'dd-mm-yyyy'),
             'mild');

INSERT INTO patient
            (patient_id,
             name,
             sex,
             age,
             admission_date,
             alzheimer_diagnosis)
VALUES     ( 'P9700',
             'Clifton Norman',
             'male',
             85,
             To_date('02-08-2010', 'dd-mm-yyyy'),
             'severe');

INSERT INTO patient
            (patient_id,
             name,
             sex,
             age,
             admission_date,
             alzheimer_diagnosis)
VALUES     ( 'P9500',
             'Arden Rodger',
             'female',
             72,
             To_date('04-09-2010', 'dd-mm-yyyy'),
             'moderate');

INSERT INTO patient
            (patient_id,
             name,
             sex,
             age,
             admission_date,
             alzheimer_diagnosis)
VALUES     ( 'P4000',
             'Harland Wilbur',
             'male',
             69,
             To_date('17-06-2008', 'dd-mm-yyyy'),
             'moderate');

INSERT INTO patient
            (patient_id,
             name,
             sex,
             age,
             admission_date,
             alzheimer_diagnosis)
VALUES     ( 'P8000',
             'Henry Kip',
             'male',
             73,
             To_date('28-07-2009', 'dd-mm-yyyy'),
             'severe'); 

--7.	Feladat. Milyen rekordok vannak a patient tablaban?
SELECT * FROM   patient;

--8.	Feladat. Valaszd ki a patient_id, nev es alzheimer_diagnozis oszlopokat!

SELECT patient_id, name, alzheimer_diagnosis
FROM   patient;


--9.	Feladat. Listazd ki a 70 evesnel oregebb betegek adatait!

SELECT patient_id, name, alzheimer_diagnosis
FROM   patient
WHERE  age>70;


