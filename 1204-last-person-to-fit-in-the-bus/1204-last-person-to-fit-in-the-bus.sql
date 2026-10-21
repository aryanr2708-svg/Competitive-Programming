# Write your MySQL query statement below
select person_name
from(select turn,person_id as ID, person_name, weight , sum(weight) over (order by turn) as total_weight from queue) subquery
where total_weight<=1000
order by turn desc
limit 1