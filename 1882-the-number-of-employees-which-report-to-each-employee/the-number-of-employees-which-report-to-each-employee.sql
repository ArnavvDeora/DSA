# Write your MySQL query statement below
select e.employee_id, e.name, count(emp.employee_id) as reports_count,
round (
    avg(emp.age),
    0
)
as average_age
from Employees e join Employees as emp
on e.employee_id= emp.reports_to
group by e.employee_id, e.name
ORDER by e.employee_id

