# Write your MySQL query statement below
select t.unique_id,w.name
from Employees as w
left join EmployeeUNI as t
on w.id = t.id
