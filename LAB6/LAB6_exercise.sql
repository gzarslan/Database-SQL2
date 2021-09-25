SET AUTOCOMMIT ON;
/*Gozde Arslan
studentID:150320190
email:garslan@myseneca.ca
DBS211NBB*-LAB5/





/*1*/
Create TABLE MOVIES (
mid int PRIMARY KEY,
title varChar(35) NOT NULL UNIQUE,
releaseyear int NOT NULL,
director int NOT NULL,
score decimal(3,2),
CONSTRAINTS movies_unique UNIQUE(title),
CONSTRAINTS movies_score_check CHECK(score between 0 and 5 )
);
Create TABLE ACTORS (
actorid int PRIMARY KEY,
firstName varChar(20) NOT NULL,
lastname varChar(30) NOT NULL,
);
/Create TABLE CASTINGS (
movieid int PRIMARY KEY,
actorid int PRIMARY KEY,
CONSTRAINTS fkmovieid foreign key (movieid) references MOVIES (movieid),
CONSTRAINTS fkactorid foreign key (actorid) references MOVIES (actorid),
);


Create TABLE DIRECTORS (
directorid	Int PRIMARY KEY,
firstname	varchar(20)  NOT NULL,
lastname	varchar(30)   NOT NULL,

);


/*2*/
ALTER TABLE MOVIES add CONSTRAINT 
moviedir FOREIGN KEY (director) references DIRECTORS(directorid);



/*3*/
ALTER TABLE MOVIES 
add CONSTRAINTS newmov movie unique (title);


/*4*/
 INSERT INTO DIRECTORS values(1010,"Rob","Minkoff"),
(1020,	"Bill"	,"Condon"),
(1050,	"Josh",	"Cooley"),
(2010,	"Brad",	"Bird"),
(3020,	"Lake"	,"Bell");

/*4*/
INSERT INTO MOVIES
values(100,"The Lion King",2019,3020,3.50),
(200,"Beauty and the Beast"	,2017,1050,4.20),
(300,"Toy Story ",4,2019,1020,4.50),
(400,"Mission Impossible",2018,2010,5.00),
(500,"The Secret Life of Pets",2016,1010,3.90);
/*5*/
Drop TABLE MOVIES;
DROP TABLE  DIRECTORS;
DROP TABLE CASTINGS;
DROP TABLE  ACTORS;
/*6*/
CREATE TABLE EMPLOYEE2(
EMPLOYEENUMBER	NUMBER(38) PRIMARY KEY,
LASTNAME	VARCHAR2(50 )  NOT NULL,
FIRSTNAME	VARCHAR2(50 ) NOT NULL,
EXTENSION	VARCHAR2(10 )NOT NULL,
EMAIL	   VARCHAR2(100 )NOT NULL,
OFFICECODE	VARCHAR2(10 ) NOT NULL,
REPORTSTO	NUMBER(38) NOT NULL,
JOBTITLE	VARCHAR2(50) NOT NULL,
CONSTRAINTS OFFICECODE foreign key (OFFICECODE) references OFFICES (OFFICECODE),
CONSTRAINTS REPORTSTO foreign key (REPORTSTO) references EMPLOYEES (REPORTSTO),
);
/*Part B (More DML):*/
/*7*/ALTER TABLE EMPLOYEE2 ADD username  VARCHAR(20);
/*8*/ DROP TABLE EMPLOYEE2;
/*9*/INSERT INTO  EMPLOYEE2 SELECT * FROM employees;
/*10*/UPDATE EMPLOYEE2 SET firstName = 'Gozde', lastName = 'Arslan' WHERE employeeNumber = 1002;
/*11*/UPDATE EMPLOYEE2 SET username = CONCAT(LOWER(LEFT(fistname, 1)), LOWER(lastname), "@gmail.com");
/*12*/DELETE FROM EMPLOYEE2 WHERE officeCode = 4;
/*13*/DROP TABLE EMPLOYEE2;
