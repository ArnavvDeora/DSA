# Write your MySQL query statement below
Select s.student_id, s.student_name, sub.subject_name, count(e.student_id) as attended_exams 
from Students as s 
cross join Subjects as sub 
LEFT JOIN examinations as e
on s.student_id= e.student_id
and sub.subject_name=e.subject_name
group by
s.student_id, s.student_name, sub.subject_name
order by s.student_id, sub.subject_name;