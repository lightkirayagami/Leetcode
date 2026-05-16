-- Last updated: 16/05/2026, 19:20:52
# Write your MySQL query statement below
select  teacher_id,(count(distinct(subject_id)))  as cnt from Teacher group by teacher_id