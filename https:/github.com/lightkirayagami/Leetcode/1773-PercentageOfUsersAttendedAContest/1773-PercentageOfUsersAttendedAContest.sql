-- Last updated: 16/05/2026, 19:21:12
# Write your MySQL query statement below
select contest_id ,round(((count(distinct(r.user_id)))/(SELECT COUNT(*) FROM Users))*100,2) as percentage from Register r join Users u on u.user_id=r.user_id group by r.contest_id order by percentage DESC,r.contest_id ASC  ;