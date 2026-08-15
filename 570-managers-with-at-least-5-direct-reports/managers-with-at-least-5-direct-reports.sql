# Write your MySQL query statement below
select e.name 
from Employee as e 
join Employee as t
on e.id = t.managerId
group by e.id,e.name 
having count(t.managerId) >=5