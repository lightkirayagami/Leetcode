-- Last updated: 15/05/2026, 18:54:53
# Write your MySQL query statement below
select distinct author_id as id from Views where author_id=viewer_id order by id;