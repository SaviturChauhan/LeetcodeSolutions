# Write your MySQL query statement below
SELECT 
Students.student_id, Students.student_name,Subjects.subject_name,
FROM Students CROSS JOIN Subjects LEFT JOIN Examinations 
GROUP BY Students.student_id,Students.student_name,Subjects.subject_name
ON Students.student_id = Examinations.student_id  AND Examinations.subject_name = Subjects.subject_name 
count(Examinations.student_id) as attended_exams 
ORDER BY Students.student_id,Subjects.subject_name;