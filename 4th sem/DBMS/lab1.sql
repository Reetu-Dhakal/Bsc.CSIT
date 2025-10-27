-- Create Database 
CREATE DATABASE Lab1;
USE Lab1;

--Create Table
CREATE TABLE Student
(
    StudentID INT PRIMARY KEY,
    SName VARCHAR(50),         
    Gender CHAR(10),           
    Age INT,
    Class VARCHAR(30),         
    Marks INT,
    Email VARCHAR(100),        
    Address VARCHAR(255)       
);

-- Insert 15 student records
INSERT INTO Student (StudentID, SName, Gender, Age, Class, Marks, Email, Address) VALUES
(1, 'Rohit Lama', 'Male', 17, '11A', 85, 'rohit.lama@gmail.com', 'Kathmandu'),
(2, 'Anita Shrestha', 'Female', 16, '10B', 92, 'anita.shrestha@yahoo.com', 'Lalitpur'),
(3, 'Bibek Raut', 'Male', 15, '10A', 78, 'bibek.raut@gmail.com', 'Bhaktapur'),
(4, 'Ritika Thapa', 'Female', 18, '12A', 89, 'ritika.thapa@yahoo.com', 'Kathmandu'),
(5, 'Kiran KC', 'Male', 21, 'Bachelor 1st Year', 81, NULL, 'Bhaktapur'),
(6, 'Manisha Bista', 'Female', 23, 'Bachelor 2nd Year', 74, 'manisha.bista@yahoo.com', NULL),
(7, 'Sujan Neupane', 'Male', 16, '10C', 88, 'sujan.neupane@gmail.com', 'Dharan'),
(8, 'Pooja Maharjan', 'Female', 20, '12A', 93, NULL, 'Patan'),
(9, 'Bishal Shahi', 'Male', 22, 'Bachelor 3rd Year', 65, 'bishal.shahi@yahoo.com', 'Lalitpur'),
(10, 'Renuka Karki', 'Female', 15, '10A', 90, 'renuka.karki@gmail.com', NULL),
(11, 'Ashim Basnet', 'Male', 19, '12B', 77, 'ashim.basnet@yahoo.com', 'Dharan'),
(12, 'Rachana Rai', 'Female', 21, 'Bachelor 1st Year', 83, NULL, 'Kathmandu'),
(13, 'Nirajan Adhikari', 'Male', 17, '11B', 69, 'nirajan.adhikari@gmail.com', 'Chitwan'),
(14, 'Sabina Tamang', 'Female', 24, 'Bachelor 4th Year', 87, 'sabina.tamang@yahoo.com', 'Nepalgunj'),
(15, 'Prabin Khadka', 'Male', 22, 'Bachelor 2nd Year', 91, 'prabin.khadka@gmail.com', NULL);

-- General Queries
SELECT * FROM Student;

SELECT SName, Email, Marks FROM Student;

SELECT * FROM Student WHERE Address LIKE '%Kathmandu%';

SELECT * FROM Student WHERE Email LIKE '%@gmail.com';

UPDATE Student SET Address = 'Pokhara' WHERE StudentID = 5;

SELECT * FROM Student;

SELECT * FROM Student WHERE Marks > 80 AND Age < 20;

SELECT COUNT(*) AS YahooCount FROM Student WHERE Email LIKE '%@yahoo.com';

SELECT * FROM Student WHERE Email IS NULL;

SELECT * FROM Student ORDER BY SName ASC;

SELECT Class, MAX(Marks) AS HighestMarks FROM Student GROUP BY Class;

DELETE FROM Student WHERE Address IS NULL;

SELECT * FROM Student;

-- Add phone number
ALTER TABLE Student ADD PhoneNumber VARCHAR(15);

SELECT * FROM Student;

-- Create View
CREATE VIEW ContactList AS
SELECT SName, Email, PhoneNumber
FROM Student;

SELECT * FROM ContactList;

-- Name pattern match
SELECT * FROM Student WHERE SName LIKE 'R%a';

-- Count by Address
SELECT Address, COUNT(*) AS StudentCount 
FROM Student
WHERE Address IS NOT NULL
GROUP BY Address;

-- Gender count
SELECT Gender, COUNT(*) AS Count 
FROM Student 
GROUP BY Gender;

-- Trigger to prevent email update
CREATE TRIGGER PreventEmailUpdate
ON Student
FOR UPDATE
AS
BEGIN
    IF UPDATE(Email)
    BEGIN
        IF EXISTS (
            SELECT * FROM inserted i
            JOIN deleted d ON i.StudentID = d.StudentID
            WHERE d.Email IS NOT NULL AND i.Email <> d.Email
        )
        BEGIN
            RAISERROR ('Email cannot be updated once entered.', 16, 1);
            ROLLBACK TRANSACTION;
        END
    END
END;

-- Order by address
SELECT * FROM Student
ORDER BY Address;

-- Find students sharing same address
SELECT * FROM Student
WHERE Address IS NOT NULL
AND Address IN (
    SELECT Address FROM Student
    GROUP BY Address
    HAVING COUNT(DISTINCT SName) > 1
);

-- ✅ Rename column Marks to TotalMarks
EXEC sp_rename 'Student.Marks', 'TotalMarks', 'COLUMN';
SELECT * FROM Student;

