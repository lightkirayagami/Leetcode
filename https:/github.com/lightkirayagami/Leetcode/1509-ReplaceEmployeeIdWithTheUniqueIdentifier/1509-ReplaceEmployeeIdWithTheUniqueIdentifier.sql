-- Last updated: 16/05/2026, 19:21:19
# Write your MySQL query statement below
Select u.unique_id,e.name from Employees e left join EmployeeUNI u on e.id=u.id;