-- 1. Create Database
CREATE DATABASE CollegeMIS;
USE CollegeMIS;

-- 2. Create Tables
CREATE TABLE Department (
  DepartmentID INT PRIMARY KEY,
  DeptName VARCHAR(50)
);

CREATE TABLE Student (
  StudentID INT PRIMARY KEY,
  Name VARCHAR(50),
  Gender CHAR(1),
  DOB DATE,
  DepartmentID INT,
  Email VARCHAR(100),
  FOREIGN KEY (DepartmentID) REFERENCES Department(DepartmentID)
);

CREATE TABLE Course (
  CourseID INT PRIMARY KEY,
  CourseName VARCHAR(100),
  DepartmentID INT,
  FOREIGN KEY (DepartmentID) REFERENCES Department(DepartmentID)
);

CREATE TABLE Enrollment (
  EnrollmentID INT PRIMARY KEY,
  StudentID INT,
  CourseID INT,
  Semester VARCHAR(10),
  Marks INT,
  FOREIGN KEY (StudentID) REFERENCES Student(StudentID) ON DELETE CASCADE,
  FOREIGN KEY (CourseID) REFERENCES Course(CourseID) ON DELETE CASCADE
);

-- 3. Insert Sample Data
INSERT INTO Department VALUES
(1, 'Computer Science'),
(2, 'Information Technology'),
(3, 'Electronics'),
(4, 'Management'),
(5, 'Arts'),
(6, 'Humanities'),
(7, 'Economics');

SELECT * FROM Department;

INSERT INTO Student VALUES
(101, 'Rita Sharma', 'F', '2003-06-15', 1, 'rita.sharma@gmail.com'),
(102, 'Suman Rai', 'M', '2002-04-12', 2, 'suman.rai@yahoo.com'),
(103, 'Bikash Thapa', 'M', '2001-09-21', 1, 'bikash.t@gmail.com'),
(104, 'Nisha Lama', 'F', '2003-12-01', 3, 'nisha.lama@gmail.com'),
(105, 'Amit Joshi', 'M', '2002-02-19', 4, 'amit.j@gmail.com'),
(106, 'Kamal Pandey', 'M', '2002-11-11', 5, 'kamal.pandey@gmail.com'),
(107, 'Manisha Karki', 'F', '2004-01-09', 6, 'manisha.karki@hotmail.com'),
(108, 'Roshan Shrestha', 'M', '2001-03-25', 7, 'roshan.shrestha@gmail.com');


SELECT * FROM Student;

INSERT INTO Course VALUES
(201, 'Data Structures', 1),
(202, 'DBMS', 1),
(203, 'Computer Networks', 2),
(204, 'Digital Logic', 3),
(205, 'Organizational Behavior', 4),
(206, 'Microprocessors', 3),
(207, 'Artificial Intelligence', 4);

SELECT * FROM Course;

INSERT INTO Enrollment VALUES
(301, 101, 201, 'Spring', 87),
(302, 101, 202, 'Fall', 91),
(303, 102, 203, 'Spring', 77),
(304, 103, 201, 'Fall', 89),
(305, 103, 202, 'Spring', 94),
(306, 104, 204, 'Fall', 75),
(307, 105, 205, 'Fall', 78);

SELECT * FROM Enrollment;

-- 4. SQL Queries

-- 2.
SELECT s.StudentID, s.Name, d.DeptName
FROM Student s
JOIN Department d ON s.DepartmentID = d.DepartmentID;

-- 3.
SELECT CourseName
FROM Course c
JOIN Department d ON c.DepartmentID = d.DepartmentID
WHERE d.DeptName = 'Computer Science';

-- 4.
SELECT s.Name
FROM Student s
JOIN Enrollment e ON s.StudentID = e.StudentID
JOIN Course c ON e.CourseID = c.CourseID
WHERE c.CourseName = 'Data Structures';

-- 5.
SELECT d.DeptName, COUNT(s.StudentID) AS StudentCount
FROM Department d
LEFT JOIN Student s ON d.DepartmentID = s.DepartmentID
GROUP BY d.DeptName;

-- 6.
SELECT DISTINCT s.Name
FROM Student s
JOIN Enrollment e ON s.StudentID = e.StudentID
WHERE e.Marks > 80;

-- 7.
SELECT c.CourseName, AVG(e.Marks) AS AverageMarks
FROM Course c
JOIN Enrollment e ON c.CourseID = e.CourseID
GROUP BY c.CourseName;

-- 8.
SELECT s.Name
FROM Student s
LEFT JOIN Enrollment e ON s.StudentID = e.StudentID
WHERE e.StudentID IS NULL;

Select * From Student;

-- 9.
SELECT c.CourseName, COUNT(e.StudentID) AS EnrolledStudents
FROM Course c
LEFT JOIN Enrollment e ON c.CourseID = e.CourseID
GROUP BY c.CourseName;

-- 10. (MySQL alternative to TOP 1)
SELECT TOP 1 s.Name, e.Marks 
FROM Student s
JOIN Enrollment e ON s.StudentID = e.StudentID
JOIN Course c ON e.CourseID = c.CourseID
WHERE c.CourseName = 'DBMS'
ORDER BY e.Marks DESC;


-- 11.
UPDATE Student SET DepartmentID = 2 WHERE StudentID = 101;
SELECT * FROM Student WHERE StudentID = 101;

-- 12.
DELETE FROM Course WHERE CourseName = 'Digital Logic';
SELECT * FROM Course;

-- 13.
SELECT d.DeptName, COUNT(c.CourseID) AS CourseCount
FROM Department d
JOIN Course c ON d.DepartmentID = c.DepartmentID
GROUP BY d.DeptName;


-- 14.
SELECT s.Name, COUNT(e.CourseID)*3 AS TotalCredits
FROM Student s
JOIN Enrollment e ON s.StudentID = e.StudentID
GROUP BY s.Name;

-- 15.
CREATE VIEW TopPerformers AS
SELECT s.StudentID, s.Name, AVG(e.Marks) AS AvgMarks
FROM Student s
JOIN Enrollment e ON s.StudentID = e.StudentID
GROUP BY s.StudentID, s.Name
HAVING AVG(e.Marks) > 85;
SELECT * FROM TopPerformers;



-- 16.
CREATE VIEW StudentDetails AS
SELECT s.StudentID, s.Name, d.DeptName AS Department, s.Email
FROM Student s
JOIN Department d ON s.DepartmentID = d.DepartmentID;
SELECT * FROM StudentDetails;



-- 17.
SELECT s.Name, c.CourseName, e.Marks
FROM Student s
JOIN Enrollment e ON s.StudentID = e.StudentID
JOIN Course c ON e.CourseID = c.CourseID;

-- Enroll Rita (101) in Computer Networks (203 - DepartmentID 2)
INSERT INTO Enrollment VALUES
(308, 101, 203, 'Summer', 88);

-- 18.
SELECT s.StudentID, s.Name
FROM Student s
JOIN Enrollment e ON s.StudentID = e.StudentID
JOIN Course c ON e.CourseID = c.CourseID
GROUP BY s.StudentID, s.Name
HAVING COUNT(DISTINCT c.DepartmentID) > 1;



INSERT INTO Department VALUES (8, 'Philosophy');
SELECT d.DeptName
FROM Department d
LEFT JOIN Student s ON d.DepartmentID = s.DepartmentID
WHERE s.StudentID IS NULL;

-- 20.
EXEC sp_rename 'Student.DOB', 'DateofBirth', 'COLUMN';
SELECT * FROM Student;


-- 21.
SELECT s.Name
FROM Student s
JOIN Enrollment e ON s.StudentID = e.StudentID
JOIN Course c ON e.CourseID = c.CourseID
JOIN Department d ON s.DepartmentID = d.DepartmentID
WHERE d.DeptName = 'Information Technology'
  AND c.CourseName = 'Computer Networks';

-- 22.
SELECT * FROM Student WHERE Email LIKE '%@gmail.com';

-- 23.
SELECT DISTINCT s.Name
FROM Student s
JOIN Enrollment e ON s.StudentID = e.StudentID
WHERE e.Marks > (SELECT AVG(Marks) FROM Enrollment);

-- 24.
SELECT c.CourseName, AVG(e.Marks) AS AvgMarks
FROM Course c
JOIN Enrollment e ON c.CourseID = e.CourseID
GROUP BY c.CourseName;

-- 25.
SELECT s.Name, c.CourseName, e.Marks
FROM Student s
JOIN Enrollment e ON s.StudentID = e.StudentID
JOIN Course c ON e.CourseID = c.CourseID
ORDER BY e.Marks DESC;
