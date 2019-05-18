/*1*/
select c.title,t.id t_id
from (((uni.course c inner join uni.section s on c.course_id=s.course_id) inner join uni.teaches t on (s.course_id=t.course_id and s.semester=t.semester and s.year=t.year and s.sec_id=t.sec_id)))
where lower(c.dept_name) like 'history' and c.credits=3
order by t_id asc,c.title desc;

/*2*/
select count(distinct st.id) count
from (((uni.student st inner join uni.takes t on st.id=t.id) inner join uni.section se on (t.course_id=se.course_id and t.sec_id=se.sec_id and t.semester=se.semester and t.year=se.year)) inner join uni.course c on se.course_id=c.course_id)
where lower(c.title) like '%design%';

/*3*/
/*number of students/dept in 2007 Fall*/
create view f2007 as (
select c.dept_name dept_name , count(distinct st.id) count
from (((uni.student st inner join uni.takes t on st.id=t.id) inner join uni.section se on (t.course_id=se.course_id and t.sec_id=se.sec_id and t.semester=se.semester and t.year=se.year)) inner join uni.course c on se.course_id=c.course_id)
where t.semester='Fall' and t.year='2007'
group by c.dept_name
);

select dept_name
from f2007
where count=(select max(count) from f2007);

/*4*/
/*course ids of student 63039)*/
create view stu as (
select t.course_id
from uni.student s inner join uni.takes t on s.id=t.id
where s.id='63039'
);

/*division*/
select distinct s.id
from uni.student s inner join uni.takes t on s.id=t.id
where t.course_id in (select * from stu)
group by s.id
having count(distinct t.course_id)=(select count(*) from stu);
