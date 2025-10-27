CREATE DATABASE LAB3
USE LAB3;
CREATE TABLE student(
sid int identity(1,1) primary key,
sname varchar(20) NOT NULL,
saddress varchar(20),
DOB DATE,
Marks float
);
Select * From student 
Rollback
CREATE TABLE student(
sid int identity(1,1) primary key,
sname varchar(20) NOT NULL,
saddress varchar(20),
DOB DATE,
Marks float
);
BEGIN TRANSACTION;
  COMMIT;
SELECT * FROM student
INSERT INTO student (sname, saddress, DOB, Marks) VALUES
('Krishna Adhikari', 'Pokhara', '2005-02-10', 90.2),
('Manisha Basnet', 'Birgunj', '2004-12-05', 76.4),
('Suman Kharel', 'Chitwan', '2006-03-22', 82.7),
('Pooja Tamang', 'Dhankuta', '2005-07-14', 88.1),
('Roshan Maharjan', 'Bhaktapur', '2004-10-28', 73.9),
('Sarita Pandey', 'Janakpur', '2005-05-17', 85.6),
('Deepak Shahi', 'Nepalgunj', '2006-09-09', 79.3),
('Kritika Koirala', 'Hetauda', '2004-08-02', 92.5),
('Sunil Thapa', 'Biratnagar', '2005-11-26', 68.4),
('Asmita KC', 'Dhangadhi', '2006-06-30', 87.0);
ROLLBACK
COMMIT
DELETE FROM student WHERE sname = 'Sunil Thapa';
ROLLBACK
COMMIT 
UPDATE student
SET saddress = 'Lalitpur'
WHERE Marks > 80

SELECT * FROM student
commit
rollback
DROP TABLE student;