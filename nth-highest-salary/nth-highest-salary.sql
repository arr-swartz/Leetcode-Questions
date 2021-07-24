CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  declare m INT;
  set m=N-1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT distinct Salary FROM Employee ORDER BY Salary DESC LIMIT 1 OFFSET m
  );
END