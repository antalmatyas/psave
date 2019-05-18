drop table patient cascade constraints purge;
drop table staff cascade constraints purge;
drop table treatment cascade constraints purge;

CREATE TABLE patient(
patient_id VARCHAR(255) PRIMARY KEY,
patient_name VARCHAR(255) NOT NULL,
sex VARCHAR(6),
age NUMBER,
admission_date DATE,
alzheimer_diagnosis VARCHAR(255)
);

CREATE TABLE staff(
  staff_id VARCHAR2(255) PRIMARY KEY,
  staff_name VARCHAR2(255) NOT NULL,
  salary NUMBER,
  post VARCHAR2(255) NOT NULL,
  manager_id VARCHAR2(255) REFERENCES staff(staff_id) -- külsõ kulcs
);

CREATE TABLE treatment(
    treatment_id VARCHAR(255) PRIMARY KEY,
    patient_id VARCHAR(255) REFERENCES patient (patient_id),
    drug VARCHAR(255),
    t_cost NUMBER,
    t_time DATE,
    consultant VARCHAR(255) REFERENCES staff(staff_id)
);

INSERT INTO patient
VALUES     ( 'P1500',
          'Irvin Brody',
          'male',
          46,
          to_date('24-10-2004', 'dd-mm-yyyy'),
          'mild');

INSERT INTO patient
VALUES     ( 'P9700',
          'Clifton Norman',
          'male',
          85,
          To_date('02-08-2010', 'dd-mm-yyyy'),
          'severe');

INSERT INTO patient
VALUES     ( 'P9500',
          'Arden Rodger',
          'female',
          72,
          To_date('04-09-2010', 'dd-mm-yyyy'),
          'moderate');

INSERT INTO patient
VALUES     ( 'P4000',
          'Harland Wilbur',
          'male',
          69,
          To_date('17-06-2008', 'dd-mm-yyyy'),
          'moderate');

INSERT INTO patient
VALUES     ( 'P8000',
          'Henry Kip',
          'male',
          73,
          To_date('28-07-2009', 'dd-mm-yyyy'),
          'severe');

INSERT INTO staff
VALUES('S0001', 'Dr Boss',20000, 'Manager', NULL);

INSERT INTO staff
VALUES('S0002', 'Dr Green', 18000, 'Surgeon', 'S0001');

INSERT INTO staff
VALUES('S0003', 'Dr Smith', 16000, 'Internist', 'S0001');

INSERT INTO staff
VALUES('S0004', 'Ms Jacques', 10000, 'Matron', 'S0001');

INSERT INTO staff
VALUES('S0005', 'Ms Ball', 8000, 'Sister', 'S0004');

INSERT INTO treatment
VALUES('T0001', 'P1500', 'Donepezil', 57, TO_DATE('24-10-2004 21:18:27', 'DD-MM-YYYY HH24:MI:SS'), 'S0003');

INSERT INTO treatment
VALUES('T0002', 'P8000', NULL , 150, TO_DATE('26-10-2004 21:18:27', 'DD-MM-YYYY HH24:MI:SS'), 'S0002');

INSERT INTO treatment
VALUES('T0003', 'P9700', 'Memantine', 128, TO_DATE('25-10-2004 21:18:27', 'DD-MM-YYYY HH24:MI:SS'), 'S0004');

INSERT INTO treatment
VALUES('T0004', 'P4000', NULL , 150, TO_DATE('27-10-2004 21:18:27', 'DD-MM-YYYY HH24:MI:SS'), 'S0002');
INSERT INTO treatment
VALUES('T0005', 'P4000', NULL , NULL, TO_DATE('21-10-2004 12:10:01', 'DD-MM-YYYY HH24:MI:SS'), 'S0002');

INSERT INTO treatment
VALUES('T0006', 'P9700', 'Memantine' , NULL, TO_DATE('02-11-2004 11:18:27', 'DD-MM-YYYY HH24:MI:SS'), 'S0002');
COMMIT;
