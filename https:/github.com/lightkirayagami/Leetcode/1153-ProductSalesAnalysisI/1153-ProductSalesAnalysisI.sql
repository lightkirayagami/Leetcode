-- Last updated: 16/05/2026, 19:21:31
# Write your MySQL query statement below
select p.product_name,s.year,s.price from Sales s join Product p on s.product_id=p.product_id