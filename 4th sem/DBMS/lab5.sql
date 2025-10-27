-- Create database and use it
CREATE DATABASE LAB5;
USE LAB5;

-- Create student table
CREATE TABLE student(
    sid INT PRIMARY KEY,
    sname VARCHAR(20),
    marks INT,
    saddress VARCHAR(20)
);
Select * From student


CREATE TABLE student_log(
    logid INT IDENTITY(1,1) PRIMARY KEY,
    sid INT,
    actiontype VARCHAR(20),
    actiontime DATETIME,
    CONSTRAINT fk_student FOREIGN KEY(sid) REFERENCES student(sid)
);

SELECT * FROM student_log;

-- Trigger to log inserts into student table
CREATE TRIGGER student_log_trigger
ON student
AFTER INSERT
AS
BEGIN
    INSERT INTO student_log(sid, actiontype, actiontime)
    SELECT sid, 'INSERT', GETDATE()
    FROM inserted;
END;

INSERT INTO student(sid, sname, marks, saddress)
VALUES (2, 'Ritu', 64, 'kathmandu');

SELECT * FROM student_log;

-- View student table
SELECT * FROM student;

-- Trigger to print message after insert
CREATE TRIGGER student_message
ON student
AFTER INSERT
AS
BEGIN
    PRINT 'New student record has been inserted into the student table.';
END;

-- Trigger to calculate total marks after insert
CREATE TRIGGER student_totalmarks
ON student
AFTER INSERT
AS
BEGIN
    DECLARE @total DECIMAL(10,2);
    SELECT @total = SUM(marks)
    FROM student;
    PRINT 'Total marks of all students: ' + CAST(@total AS VARCHAR(20));
END;

-- Insert another student record
INSERT INTO student(sid, sname, marks, saddress)
VALUES (10, 'Ram', 91, 'kathmandu');
select * from student