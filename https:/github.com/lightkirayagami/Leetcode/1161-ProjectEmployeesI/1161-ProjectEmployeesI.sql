-- Last updated: 16/05/2026, 19:21:30
# Write your MySQL query statement below


select p.project_id,round(SUM(e.experience_years)/count(p.project_id),2 )as average_years from Project p join Employee e on p.employee_id =e.employee_id group by p.project_id order by p.project_id;
