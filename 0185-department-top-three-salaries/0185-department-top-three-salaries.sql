# Write your MySQL query statement below
select d.name as department , e1.name as employee , e1.salary as salary
from employee as e1
join department d on e1.departmentId=d.Id
where 3>(select count(distinct e2.salary)from employee e2 where e2.departmentId=e1.departmentId and e2.salary>e1.salary)