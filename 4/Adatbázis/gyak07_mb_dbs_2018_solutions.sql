drop table persons cascade constraints purge;

--1. veszteséges dekompozicio; kozos attributum building

create table persons as
select distinct id, name, salary,building from allinfo;


create table buildings as
select distinct building, dept_name,budget from allinfo;

select * from allinfo
order by building;

select * from persons inner join buildings
on persons.building= buildings.BUILDING
order by buildings.building;

-- a ketto joinja; --> sortobbszorozodes; veszteseges decomp.
select id,name,salary,dept_name,buildings.building,budget from persons inner join buildings
on persons.building= buildings.BUILDING
minus
select * from allinfo;

-- funkcionalis fuggoseg vizsgalata
select building, count(distinct dept_name)
from buildings
group by BUILDING
having count(distinct dept_name)>1;

select building, count(distinct budget)
from buildings
group by BUILDING
having count(distinct budget)>1;

--> mivel van olyan hogy egy buildinghez tobb kulonbozo department/budget tartozik, nincs funkc fugges


--2. veszteségmentes; kozos attributum dept_name
create table persons2 as
select distinct id, name, salary,dept_name from allinfo;

create table departments as
select distinct dept_name, building, budget from allinfo;

--a ketto joinja

select id,name,salary,departments.dept_name,building,budget from persons2 inner join departments
on persons2.DEPT_NAME= departments.DEPT_NAME
minus
select * from allinfo;

-- funkcionalis fuggoseg vizsgalata
select dept_name, count(distinct budget)
from departments
group by dept_name
having count(distinct budget)>1;

select dept_name, count(distinct building)
from departments
group by dept_name
having count(distinct building)>1;

--> mivel nincs olyan hogy egy dept_namehez tobb kulonbozo building/budget tartozik, funkc fugges van (a peldaadatok alapjan)
