
/*Gozde Arslan
studentID:150320190
email:garslan@myseneca.ca
DBS211NBB*-LAB6/
/*1
  	List the 4 ways that we know that a transaction can be started,


  1- if the user has a new connection to the server and has a blank sheet ready to go, starts a new transaction
  2- if the user uses the BEGIN statement in Oracle SQL, this will start a new transaction
  3-  if the the user executes a COMMIT statement, the current transaction is commited, and a new transaction starts.
  4- if the user executes ANY DDL statement.  This automatically triggers an auto-commit of the current transaction and starts a new transaction.
  references: http://dbs211.ca/Weeks/Week06/index.html#security

/*2.	Using SQL, create an empty table, that is the same as the employees table, and name it newEmployees.*/
CREATE TABLE newEmployees AS SELECT *FROM employees;

/*3*/
SET AUTCOMMIT OFF;
SET TRANSACTION READ WRITE;

/*4*/
INSERT INTO newemployees
VALUES (100,'Patel','Ralph',22333,'rpatel@mail.com',1,NULL,'Sales Rep'),
		(101,'Denis','Betty',33444,'bdenis@mail.com',4,NULL,'Sales Rep'),
        (102,'Biri','Ben',44555,'bbirir@mail.com',2,NULL,'Sales Rep'),
        (103,'Newman','Chad',66777,'cnewman@mail.com',3,NULL,'Sales Rep'),
        (104,'Ropeburn','Audrey',77888,'aropebur@mail.com',1,NULL,'Sales Rep');
    
    
 /*5*//* 5 rows selected*/
SELECT *FROM newemployees;
   

/*6*/
/* 0 row selected*/
ROLLBACK ;
SELECT *FROM newemployees;  

/*7*/   
INSERT INTO newemployees
VALUES (100,'Patel','Ralph',22333,'rpatel@mail.com',1,NULL,'Sales Rep'),
		(101,'Denis','Betty',33444,'bdenis@mail.com',4,NULL,'Sales Rep'),
        (102,'Biri','Ben',44555,'bbirir@mail.com',2,NULL,'Sales Rep'),
        (103,'Newman','Chad',66777,'cnewman@mail.com',3,NULL,'Sales Rep'),
        (104,'Ropeburn','Audrey',77888,'aropebur@mail.com',1,NULL,'Sales Rep');
    
COMMIT;
SELECT * FROM newemployees;
          /*28 rows inserted*/

/*8*/
UPDATE newemployees SET JOBTITLE = 'unknown';

/*9*/COMMIT;

/*10*/ ROLLBACK;
/*10a*/ SELECT *FROM newemployees WHERE JOBTITLE='unknown';
/*10b- The roll back was not effective */
/*10c -The differences is that when you run COMMIT before ROLLBACK it makes changes permanent therefore it was not effective.*/

/*11*/ DELETE FROM newemployees ;

/*12*/CREATE VIEW vwNewEmps  SELECT *From newemployees ORDER BY lastname,firstname;

/*13*/ROLLBACK;
/*13a- There is no employees in the table */
/*13b- It was effective because the changes that we made it was not permanent by commint statement. */

/*14*/
INSERT INTO newemployees
VALUES (100,'Patel','Ralph',22333,'rpatel@mail.com',1,NULL,'Sales Rep'),
		(101,'Denis','Betty',33444,'bdenis@mail.com',4,NULL,'Sales Rep'),
        (102,'Biri','Ben',44555,'bbirir@mail.com',2,NULL,'Sales Rep'),
        (103,'Newman','Chad',66777,'cnewman@mail.com',3,NULL,'Sales Rep'),
        (104,'Ropeburn','Audrey',77888,'aropebur@mail.com',1,NULL,'Sales Rep');
    
/*15*/
SAVEPOINT insertion;
/*16*/
UPDATE newemployees SET JOBTITLE = 'unknown';

/*17*/ROLLBACK TO insertion;
/*-It deleted  the data from newemployees table.*/


/*18-it creates view with 23 rows rather than 25 rows. it is deleted last 2 rows that we added.*/
ROLLBACK ;
CREATE VIEW vwNewEmps  As SELECT *FROM newemployees;

/*19*/ REVOKE ALL ON newemloyees FROM PUBLIC;

/*20*/ GRANT READ ON newemployees to dbs211_202d45;

/*21*/ GRAND INSERT DELETE UPDATE ON newemployees to  dbs211_202d45;

/*22*/ REVOKE ALL ON newemployees from dbs211_202d45;

/*23*/ DROP TABLE newemployees ;
DROP VIEW vwNewEmps;
COMMIT;





