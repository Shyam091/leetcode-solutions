# Write your MySQL query statement below
SELECT Employee.name, Bonus.bonus 
FROM Employee
LEFT JOIN  BONUS
ON employee.empID = Bonus.empId
Where Bonus.bonus < 1000 || Bonus.bonus IS NULL;