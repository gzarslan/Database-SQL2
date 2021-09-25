

-- Question 1: How many tables have been created? List the names of the created tables. 
Answer : 
 8 tables created.
Customer
Employees
offices
Orderdetails
orders
payments
productslines
products 



-- Question 2 : Click on table customers. Click on the Data tab near the top of the worksheet. How many rows are there in the table customers?
Answer :  13 columns and 122 rows

-- Question 3: What SQL statement would return the same results. Write the statement in the .sql file and execute it.  
Answer :  SELECT * FROM customer;  

-- Question 4 : How many columns does the customers table have? List the column names.
Answer : There is 13 colums in the customer table
 customer number
 customer name
 contact last name
 contact first name
 phone
 adressline1
 adressline2
 city 
 state
 postalcode
 country 
 sales reemployee number
 credit limit



-- Question 5 : What is the value of each column in the first row in table customers? Write the column name and the column data type in addition to the value.
Answer : customer number data type is number

-- Question 6: Write the number of rows and columns for the rest of the tables in your schema.  Format it something like the following.
Answer : Table Name    Rows           columns
Customer	           122	    13
Employees	            23	    8
offices	             7	                    9
Orderdetails      2996  	    5
orders	          326  	    6
payments	          273	    4
productslines       7	                    2
products	          110    	    9

-- Question 7: Right Click on the orderdetails table and choose tables/count rows.  How many rows does the order details table include?
Answer : orderdetails table include 2996 rows 


-- Question 8:Write the following SQL statement in the new tab.
desc offices; 
	You can also write
describe offices;
Answer : 
Name           Null?             Type         
------------   --------             ------------ 
OFFICECODE   NOT NULL VARCHAR2(10) 
CITY               NOT NULL VARCHAR2(50) 
PHONE           NOT NULL VARCHAR2(50) 
ADDRESSLINE1 NOT NULL VARCHAR2(50) 
ADDRESSLINE2                  VARCHAR2(50) 
STATE                               VARCHAR2(50) 
COUNTRY      NOT NULL VARCHAR2(50) 
POSTALCODE   NOT NULL VARCHAR2(15) 
TERRITORY    NOT NULL VARCHAR2(10) 


-- Question 9: Type the following statements in, execute them, then briefly describe what the statement is doing!
SELECT * FROM employees;
SELECT * FROM customer ORDER BY ContactLastName;

Answer : desc * employees-->It gives all the rows information of employees tables
select * from customers order by contactlastname-->  this command displays information customerlastname line by ascending order  in the customer table 



-- Question 10: How many constraints does the products table have?
Answer :  There is 11 constraints in products table 


