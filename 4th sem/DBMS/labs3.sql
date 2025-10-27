CREATE DATABASE LAB3
USE LAB3;
CREATE TABLE student(
sid int identity(1,1) primary key,
sname varchar(20) NOT NULL,
saddress varchar(20),
DOB DATE,
Marks float
);
SELECT * FROM Student;
ROLLBACK

CREATE TABLE student(
sid int identity(1,1) primary key,
sname varchar(20) NOT NULL,
saddress varchar(20),
DOB DATE,
Marks float
);
COMMIT
SELECT * FROM student;

INSERT INTO student (sname, saddress, DOB, Marks) VALUES
('Ankit Sharma', 'Lalitpur', '2005-01-12', 84.5),
('Nisha Gurung', 'Pokhara', '2004-09-18', 91.2),
('Bipin Rai', 'Dharan', '2006-02-25', 77.8),
('Sneha Shrestha', 'Butwal', '2005-08-07', 89.4),
('Prakash Yadav', 'Birgunj', '2004-11-03', 72.6),
('Rojina Magar', 'Janakpur', '2005-04-21', 86.9),
('Saurav KC', 'Nepalgunj', '2006-10-15', 79.5),
('Kusum Lama', 'Chitwan', '2004-07-28', 93.1),
('Manoj Thapa', 'Bhaktapur', '2005-12-19', 70.8),
('Rachana Bhandari', 'Dhangadhi', '2006-05-09', 88.7);

ROLLBACK
COMMIT
DELETE FROM student WHERE saddress = 'Chitwan';
ROLLBACK
COMMIT
UPDATE student
SET saddress = 'Lalitpur'
WHERE Marks > 80
COMMIT
ROLLBACK
DROP TABLE student;
ROLLBACK
COMMIT
