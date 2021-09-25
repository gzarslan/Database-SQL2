SET AUTOCOMMIT ON;
/*Gozde Arslan
studentID:150320190
email:garslan@myseneca.ca
DBS211NBB*-LAB4/


/*1	Create a query that shows employee number, first name, last name, city, phone number and postal code for all employees in France.
a.	Answer this question using an ANSI-89 Join
b.	Answer this question using an ANSI-92 Join*/
/*Answer 1a*/SELECT e.employeenumber ,e.firstName, e.lastName,o.city,o.phone,o.postalCode FROM employees e, offices o where o.country= 'FRANCE';
/*Answer 1b*/SELECT employeeNumber ,firstName, lastName,city,phone,postalCode FROM employees,offices WHERE UPPER(country)= 'FRANCE';
SELECT employeeNumber ,firstName, lastName,phone,extension FROM employees JOIN offices USING(officecode) WHERE LOWER(city)= 'san francisco' ORDER BY employeenumber;
SELECT employeeNumber ,firstName, lastName,phone,extension FROM employees JOIN offices USING(officecode) WHERE employeenumber='1002' ORDER BY employeenumber;



/*2 Create a query that displays all payments made by customers from Canada. 
a.	Sort the output by Customer Number. 
b.	Only display the Customer Number, Customer Name, Payment Date and Amount. 
c.	Make sure the date is displayed clearly to know what date it is. (i.e. what date is 02-04-19??? – Feb 4, 2019, April 2, 2019, April 19, 2002, ….)*/
/*Answer 2*/ 
SELECT c.customerNumber,customerName, TO_CHAR(paymentDate,'Month DD YYYY') ,amount
FROM customers  c, payments
WHERE c.customernumber=payments.customernumber AND c.country='CANADA' ORDER BY customerNumber ;


/*3	Create a query that shows all USA customers who have not made a payment.  Display only the customer number and customer name sorted by customer number.*/
/*Answer 3*/SELECT DISTINCT customers.customerNumber,customerName,country 
FROM customers,payments
WHERE customers.customerNumber !=payments.customerNumber AND customers.country='USA'
ORDER BY customerNumber DESC;


/*4a Create a view (vwCustomerOrder) to list all orders with the following data for all ustomers:  */
/*Answer 4a*/
CREATE VIEW vwCustomerOrder  AS SELECT o.orderNumber,o.orderDate,p.productName,od.quantityOrdered,od.priceEach,o.customerNumber,od.orderlineNumber
FROM orders o, products p,orderDetails od 
 WHERE o.orderNumber=od.orderNumber;
/*Answer 4b*/SELECT *FROM vwCustomerOrder;


/*5 Using the vwCustomerOrder  view, display the order information for customer number 124. Sort the output based on order number and then order line number. (Yes, I know orderLineNumber is not in the view)*/
/*Answer 5*/SELECT vwCustomerOrder FROM customers WHERE customerNumber = '124' ORDER BY orderNumber,orderLineNumber;
               
               
/*6 Create a query that displays the customer number, first name, last name, phone, and credit limits for all customers who do not have any orders.  */                      
/*Answer 6*/ SELECT customernumber,contactfirstname,phone,creditlimit FROM customers where customers.customernumber NOT IN (SELECT customernumber FROM orders);
                    
/*7 Create a view (vwEmployeeManager) to display all information of all employees and the name and the last name of their managers if there is any manager that the employee reports to.  Include all employees, including those who do not report to anyone.*/                
/*Answer 7*/CREATE VIEW  vmEmployeeManager AS SELECT e.* ,m.firstName as managerFirstName,m.lastName as managerLastName FROM employees e, employees m WHERE e.reportsTo=m.employeeNumber;


/*8.	Modify the employee_manager view so the view returns only employee information for employees who have a manager. Do not DROP and recreate the view – modify it. (Google is your friend).*/                    
/*Answer 8*/ CREATE OR REPLACE VIEW vmEmployeeManager  AS SELECT *FROM employees WHERE reportsto IS NULL;
                       
/*9 Drop both customer_order and employee_manager views. */
/*Answer 9*/DROP VIEW vwCustomerOrder;
/*Answer 9*/DROP VIEW vmEmployeeManager;