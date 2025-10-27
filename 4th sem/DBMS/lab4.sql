CREATE DATABASE constraintlab4
USE constraintlab4;

CREATE TABLE department(
did int primary key,
dname varchar(20) NOT NULL,
location varchar(20) default 'head office'
);

CREATE TABLE employee(
eid int identity(1,1) primary key,
fname varchar(20) NOT NULL,
mname varchar(20),
lname varchar(20) NOT NULL,
Email varchar(50) unique,
salary decimal(10,2) check(salary >= 18000),
did int , foreign key(did) references department(did),
joindate date default getdate()
)
select*
from department

select *
from employee


INSERT INTO department (did, dname, location) VALUES
(1, 'Human Capital', 'Lalitpur'),
(2, 'Accounting', 'Birgunj'),
(3, 'IT','Kathmandu'),
(4, 'Public Relations', 'Pokhara'),
(5, 'Sales & Distribution', 'Dharan'),
(6, 'Production', 'Hetauda'),
(7, 'Compliance', 'Bhaktapur'),
(8, 'Innovation Lab', 'Butwal'),
(9, 'Support Center', 'Janakpur'),
(10, 'Corporate Affairs', 'Nepalgunj');

INSERT INTO employee (fname, mname, lname, Email, salary, did, joindate) VALUES
('Arjun', 'Bahadur', 'KC', 'arjun.kc@gmail.com', 26000.00, 1, '2023-04-14'),
('Ritika', NULL, 'Shah', 'ritika.shah@yahoo.com', 24500.00, 2, '2024-07-22'),
('Deepak', 'Man', 'Basnet', 'deepak.basnet@gmail.com', 28000.00, 3, '2022-09-05'),
('Kritika', NULL, 'Joshi', 'kritika.joshi@yahoo.com', 21000.00, 4, '2025-01-19'),
('Roshan', 'Prasad', 'Gurung', 'roshan.gurung@gmail.com', 23500.00, 3, '2023-10-12'),
('Mina', NULL, 'Magar', 'mina.magar@yahoo.com', 22000.00, 6, '2024-03-28'),
('Anil', 'Kumar', 'Shrestha', 'anil.shrestha@gmail.com', 25500.00, 1, '2022-12-15'),
('Sita', 'Devi', 'Maharjan', 'sita.maharjan@yahoo.com', 20000.00, 8, '2023-05-08'),
('Ganesh', NULL, 'Yogi', 'ganesh.yogi@gmail.com', 22500.00, 9, '2024-08-30'),
('Pramila', NULL, 'Bhandari', 'pramila.bhandari@yahoo.com', 27500.00, 2, '2025-02-11');

select*
from department

select*
from employee

INSERT INTO employee (fname, mname, lname, Email, salary, did) 
VALUES
	('Suresh', 'Kumar', 'Yadav', 'suresh.yadav@gmail.com', 22000, 1),
	('Alina', NULL, 'Shrestha', 'alina.shrestha@yahoo.com', 18000, 1),
	('Bikash', 'Prasad', 'Rai', 'bikash.rai@gmail.com', 25000, 1);


DELETE from department
WHERE dname = 'IT'

SELECT *
from employee e
LEFT JOIN department d
ON e.did = d.did
WHERE d.did IS NULL;