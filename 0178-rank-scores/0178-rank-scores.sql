# Write your MySQL query statement below
select s.score,(select count(distinct s1.score) from scores s1 where s1.score>=s.score ) as 'rank'
from scores s
order by s.score desc