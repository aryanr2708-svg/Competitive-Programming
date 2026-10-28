# Write your MySQL query statement below
select d.name as Department,
e.name as Employee,
e.salary as Salary
from employee as e
join department as d on e.departmentId = d.id
where e.salary = ( select max(salary) from employee where departmentId = e.departmentId)