//
////==============================================
//// Name:           gozde arslan
//// Student Number: 150320190
//// Email:          garslan@myseneca.ca
//// Section:        DBS211
//// Date:           2020/12/02
//// Final Project
////==============================================
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <occi.h>
//#include <cstring>
//#include <iomanip>
//
//using oracle::occi::Environment;
//using oracle::occi::Connection;
//using namespace oracle::occi;
//using namespace std;
//struct Employee {
//	int employeeNumber;
//	char lastName[50];
//	char firstName[50];
//	char email[100];
//	char phone[50];
//	char extension[10];
//	char reportsTo[100];
//	char jobTitle[50];
//	char city[10];
//};
//
////Function prototypes
//int menu(void);
//int getInt();
//int getIntRange(int min, int max);
//int findEmployee(Connection* conn, int employeeNumber, Employee* emp);
//void insertEmployee(Connection* conn, Employee* emp);
//void displayAllEmployees(Connection* conn);
//void displayEmployee(Connection* conn, Employee emp);
//void updateEmployee(Connection* conn, int employeeNumber);
//void deleteEmployee(Connection* con, int employeeNumber);
////Function Definitions
//int getInt() { // get selection from user
//	int value = 0;
//	bool badEntry;
//	char nextChar;
//	do {
//		badEntry = false;
//		cin >> value;
//		if (cin.fail()) {
//			cout << "Bad integer value, try again: ";
//			cin.clear();
//			cin.ignore(3000, '\n');
//			badEntry = true;
//		}
//		else {
//			nextChar = cin.get();
//			if (nextChar != '\n') {
//				cout << "Only enter an integer, try again: ";
//				cin.ignore(3000, '\n');
//				badEntry = true;
//			}
//		}
//	} while (badEntry);
//	return value;
//}
//
//int getIntRange(int min, int max)//check the input value that user enter if it is in the range 
//{
//	int val = getInt();// the getInt function was given and assigning integer valut to func
//	while (val < min || val > max) {// checks the range of values
//		cout << "Invalid value enterd, retry[0 <= value <= 6]: ";
//		val = getIntRange(1, 6);// and sets the val range
//	}
//	return val;
//
//}
//int menu(void)///prints menu and set user input 
//
//{
//
//	cout << "********************* HR Menu *********************" << endl;
//	cout << "1)	Find Employee" << endl;
//	cout << "2)	Employees Report" << endl;
//	cout << "3)	Add Employee" << endl;
//	cout << "4)	Update Employee" << endl;
//	cout << "5)	Remove Employee" << endl;
//	cout << "6)	Exit" << endl;
//	cout << "Please enter an option: ";
//	
//	int menuOption = -1;
//
//	
//		string selection;
//	
//		cin >> selection;
//
//		while (menuOption ==-1) {
//			if (selection == "1")
//			{
//				menuOption = 1;
//			}
//
//			else if (selection == "2")
//
//			{
//
//				menuOption = 2;
//
//			}
//
//			else if (selection == "3")
//
//			{
//
//				menuOption = 3;
//
//			}
//
//			else if (selection == "4")
//
//			{
//
//				menuOption = 4;
//
//			}
//
//			else if (selection == "5")
//
//			{
//
//				menuOption = 5;
//
//			}
//
//			else if (selection == "6")
//
//			{
//
//				menuOption = 0;
//
//			}
//
//			else
//
//			{
//
//				cout << "Please enter a valid option from the list: ";
//
//				menuOption = -1;
//
//			}
//
//			cin.clear();
//
//			cin.ignore(2000, '\n');
//
//
//
//
//		}
//
//
//	return menuOption;
//
//}
//
//int main() {
//
//	Environment* env = nullptr;
//	Connection* conn = nullptr;
//	string str;
//	string usr = "dbs211_203b02";
//	string pass = "57903788";
//	string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";
//	
//	Employee* emp = nullptr;
//	emp = new Employee;
//
//
//	try {
//
//		env = Environment::createEnvironment(Environment::DEFAULT);
//		conn = env->createConnection(usr, pass, srv);
//		cout << "Connection is Successful!" << endl << endl;
//		int selection = 0;
//		int flag = 0;
//		int employeeNumber = 0;
//		int check = 0;
//
//		while (!flag)
//		{
//			selection = menu();
//			switch (selection)
//			{
//			case 1:
//		
//				cout << "Enter Employee Number: ";
//				cin >> employeeNumber;
//
//				check = findEmployee(conn, employeeNumber, emp);
//
//				if (check == 1)
//				{
//					displayEmployee(conn, *emp);
//				}
//				else
//				{
//					cout << "Employee " << employeeNumber << " does not exist." << endl;
//				}
//
//			
//				break;
//
//			case 2:
//				displayAllEmployees(conn);
//				break;
//
//			case 3:	
//				insertEmployee(conn, emp);
//				break;
//
//			case 4:
//				cout << "Enter Employee Number: ";
//				cin >> employeeNumber;
//				check = findEmployee(conn, employeeNumber, emp);
//				if (check == 1)
//				{
//					
//					updateEmployee(conn, employeeNumber);
//				}
//				else
//				{
//					cout << "Employee " << employeeNumber << " does not exist." << endl;
//				}
//
//				break;
//
//			case 5:
//
//				cout << "Employee Number: ";
//				cin >> employeeNumber;
//
//				check = findEmployee(conn, employeeNumber, emp);
//
//				if (check == 1)
//				{
//
//					deleteEmployee(conn, employeeNumber);
//
//				}
//				else
//				{
//					cout << "Employee " << employeeNumber << " does not exist." << endl;
//				}
//
//				break;
//
//			case 6:
//				env->terminateConnection(conn);
//				Environment::terminateEnvironment(env);
//				cout << "Exiting";
//			    flag= 1;
//			}
//		}
//	}
//	catch (SQLException& sqlExcp) {
//		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
//	}
//	return 0;
//}
//
//
//
//int findEmployee(Connection* conn, int employeeNumber, Employee* emp) {
//	int flag= 0;
//	try
//	{
//		Statement* stmt = conn->createStatement("SELECT * FROM employees WHERE employeenumber = :1");
//		stmt->setInt(1, employeeNumber);
//		ResultSet* rs = stmt->executeQuery();
//
//		
//
//			emp->employeeNumber = rs->getInt(1);
//			strcpy(emp->lastName, rs->getString(2).c_str());
//			strcpy(emp->firstName, rs->getString(3).c_str());
//			strcpy(emp->email, rs->getString(4).c_str());
//			strcpy(emp->extension, rs->getString(5).c_str());
//			strcpy(emp->phone, rs->getString(6).c_str());		
//			strcpy(emp->reportsTo, rs->getString(7).c_str());
//			strcpy(emp->jobTitle, rs->getString(8).c_str());
//			strcpy(emp->city, rs->getString(9).c_str());
//
//		}	
//	catch (SQLException& sqlExcp)
//	{
//		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
//	
//	}
//
//	return flag;
//
//	
//}
//void displayEmployee(Connection* conn, Employee emp) {
//	
//
//
//	cout << "-------------- Employee Information -------------" << endl;
//	cout << "Employee Number: " << emp.employeeNumber << endl;
//	cout << "Last Name: " << emp.lastName << endl;
//	cout << "First Name: " << emp.firstName << endl;
//	cout << "Email: " << emp.email << endl;
//	cout << "Phone: " << emp.phone << endl;
//	cout << "Extension: " << emp.extension << endl;
//	cout << "Reporsto: " << emp.reportsTo << endl;
//	cout << "Job Title: " << emp.jobTitle << endl;
//	cout << "City: " << emp.city << endl;
//
//}
//
//void displayAllEmployees(Connection* conn) {
//	try {
//		Statement* stmt = conn->createStatement();
//		ResultSet* rs = stmt->executeQuery("SELECT *FROM (SELECT DISTINCT emp.EMPLOYEENUMBER, emp.FIRSTNAME || ' ' || emp.LASTNAME AS \"Employee Name\", emp.Email, x.PHONE, emp.EXTENSION ,b.FIRSTNAME || ' ' || b.LASTNAME AS \"Manager Name\" FROM EMPLOYEES emp FULL OUTER JOIN EMPLOYEES b ON emp.REPORTSTO=b.EMPLOYEENUMBER FULL OUTER JOIN OFFICES x ON emp.CITY= x.CITY WHERE emp.EMPLOYEENUMBER IS NOT NULL ORDER BY emp.EMPLOYEENUMBER)");
//	
//		
//			cout << left << setw(15) << "E" << setw(20) << "Employee Name" << setw(35) << "Email" << setw(25) << "Phone" << setw(15) << "Extension" << setw(25) << "Manager" << endl;
//			
//
//			while (rs->next()) {
//				int employeeID = rs->getInt(1);
//				string empName = rs->getString(2);
//				string email = rs->getString(3);
//				string phone = rs->getString(4);
//				string extension = rs->getString(5);
//				string manName = rs->getString(6);
//				cout << left << setw(17) << employeeID << setw(15) << empName << setw(25) << email << setw(25) << phone << setw(15) << extension << setw(25) << manName << endl;
//			}
//		}
//	
//			
//		
//	
//	catch (SQLException& sqlExcp) {
//		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
//	}
//
//
//}
//void insertEmployee(Connection* conn, Employee* emp) {
//	try {
//		Statement* stmt = conn->createStatement();
//		
//		stmt->setInt(1, emp->employeeNumber);
//		stmt->setString(2, emp->lastName);
//		stmt->setString(3, emp->firstName);
//		stmt->setString(4, emp->extension);
//		stmt->setString(5, emp->email);
//		stmt->setString(6, emp->city);
//		stmt->setString(7, emp->reportsTo);
//		stmt->setString(8, emp->jobTitle);
//		stmt->executeUpdate();
//		cout << "\nThe new employee is added successfully." << endl;
//
//	}
//	catch (SQLException& sqlExcp)
//	{
//		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
//	}
//
//}
//
//void updateEmployee(Connection* conn, int employeeNumber)//Final part
//{
//	try
//	{
//		string extension = "x0000";
//		cout << "Extension: ";
//		cin >> extension;
//
//		Statement* stmt = conn->createStatement("UPDATE employees SET extension = :1 WHERE employeenumber = :2");
//		stmt->setString(1, extension);
//		stmt->setInt(2, employeeNumber);
//		stmt->executeUpdate();
//
//		cout << "The employee's extension is updated succesfully." << endl;
//
//	}
//	catch (SQLException& sqlExcp)
//	{
//		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
//	}
//}
//
//
//
//void deleteEmployee(Connection* conn, int employeeNumber)//Final part
//{
//
//	try {
//
//		Statement* stmt = conn->createStatement("DELETE FROM employees WHERE employeenumber =1");
//		stmt->setInt(1, employeeNumber);
//		stmt->executeUpdate();
//
//		cout << "Employee with ID  is deleted sucessfully." << endl;
//
//
//	}
//	catch (SQLException& err) {
//		cout << err.getErrorCode() << ": " << err.getMessage();
//	}
//}
//
#include <iostream>
#include <string>
#include <occi.h>
#include <cctype>

using oracle::occi::Environment;

using oracle::occi::Connection;

using namespace oracle::occi;
using namespace std;

struct ShoppingCart {
	int product_id;
	double price;
	int quantity;
};

double findProduct(Connection* conn, int product_id) {
	Statement* stmt = conn->createStatement();
	stmt->setSQL("BEGIN find_product(:1, :2); END;");
	double price;
	stmt->setInt(1, product_id);
	stmt->registerOutParam(2, Type::OCCIDOUBLE, sizeof(price));
	stmt->executeUpdate();
	price = stmt->getDouble(2);
	conn->terminateStatement(stmt);

	if (price > 0) {
		return price;
	}
	else
	{
		return 0;
	}
}

int mainMenu() {
	int chose = 0;
	do {
		cout << "******************** Main Menu ********************\n"
			<< "1)\tLogin\n"
			<< "0)\tExit\n";

		if (chose != 0 && chose != 1) {
			cout << "You entered a wrong value. Enter an option (0-1): ";
		}
		else
			cout << "Enter an option (0-1): ";

		cin >> chose;
	} while (chose != 0 && chose != 1);

	return chose;
}






int customerLogin(Connection* conn, int customerId) {

	Statement* stmt = conn->createStatement();
	stmt->setSQL("BEGIN find_customer(:1, :2); END;");
	int search_id;
	stmt->setInt(1, customerId);
	stmt->registerOutParam(2, Type::OCCIINT, sizeof(search_id));
	stmt->executeUpdate();
	search_id = stmt->getInt(2);
	conn->terminateStatement(stmt);

	return search_id;
}

int addToCart(Connection* conn, struct ShoppingCart cart[]) {
	cout << "-------------- Add Products to Cart --------------" << endl;
	int i = 0;
	while (i < 5) {


		int id_P;
		int product_quantity;
		ShoppingCart list;
		int chose;

		do {
			cout << "Enter the product ID: ";
			cin >> id_P;
			cout << isdigit(id_P);
			if (findProduct(conn, id_P) == 0) {
				cout << "The product does not exist. Try again..." << endl;
			}
		} while (findProduct(conn, id_P) == 0);

		cout << "Product Price: " << findProduct(conn, id_P) << endl;
		cout << "Enter the product Quantity: ";
		cin >> product_quantity;

		list.product_id = id_P;
		list.price = findProduct(conn, id_P);	// Error handling
		list.quantity = product_quantity;
		cart[i] = list;

		if (i == 4)
			return i + 1;
		else {
			do {
				cout << "Enter 1 to add more products or 0 to check out: ";
				cin >> chose;
			} while (chose != 0 && chose != 1);
		}

		if (chose == 0) {
			return i + 1;
		}

		++i;
	}
}


void displayProducts(struct ShoppingCart cart[], int productCount) {
	if (productCount > 0) {
		double total = 0;
		cout << "------- Ordered Products ---------" << endl;
		for (int i = 0; i < productCount; ++i) {
			cout << "---Item " << i + 1 << endl;
			cout << "Product ID: " << cart[i].product_id << endl;
			cout << "Price: " << cart[i].price << endl;
			cout << "Quantity: " << cart[i].quantity << endl;
			total += cart[i].price * cart[i].quantity;
		}
		cout << "----------------------------------\nTotal: " << total << endl;
	}
}



int checkout(Connection* conn, struct ShoppingCart cart[], int customerId, int productCount) {
	char chose;
	do {
		cout << "Would you like to checkout ? (Y / y or N / n) ";
		cin >> chose;

		if (chose != 'Y' && chose != 'y' && chose != 'N' && chose != 'n')
			cout << "Wrong input. Try again..." << endl;
	} while (chose != 'Y' && chose != 'y' && chose != 'N' && chose != 'n');

	if (chose == 'N' || chose == 'n') {
		cout << "The order is cancelled." << endl;
		return 0;
	}
	else {

		Statement* stmt = conn->createStatement();
		stmt->setSQL("BEGIN add_order(:1, :2); END;");
		int id_order;
		stmt->setInt(1, customerId);
		stmt->registerOutParam(2, Type::OCCIINT, sizeof(id_order));
		stmt->executeUpdate();
		id_order = stmt->getInt(2);

		int i = 0;
		while (i < productCount) {
			stmt->setSQL("BEGIN add_order_item(:1, :2, :3, :4, :5); END;");
			stmt->setInt(1, id_order);
			stmt->setInt(2, i + 1);
			stmt->setInt(3, cart[i].product_id);
			stmt->setInt(4, cart[i].quantity);
			stmt->setDouble(5, cart[i].price);
			stmt->executeUpdate();
			++i;
		}

		cout << "The order is successfully completed." << endl;
		conn->terminateStatement(stmt);

		return 1;
	}
}

int main() {
	Environment* env = nullptr;
	Connection* conn = nullptr;

	string user = "dbs311_211f07";
	string pass = "25281307";
	string constr = "myoracle12c.senecacollege.ca:1521/oracle12c";

	try {
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(user, pass, constr);
		cout << "Connection is successful!" << endl;


		int chose;
		int customerId;
		do {
			chose = mainMenu();

			if (chose == 1) {
				cout << "Enter the customer ID: ";
				cin >> customerId;

				if (customerLogin(conn, customerId) == 0) {
					cout << "The customer does not exist." << endl;
				}
				else {
					ShoppingCart cart[5];
					int count = addToCart(conn, cart);
					displayProducts(cart, count);
					checkout(conn, cart, customerId, count);
				}

			}


		} while (chose != 0);

		cout << "Good bye!..." << endl;

		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);
	}
	catch (SQLException& sqlExcp) {
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
	return 0;
}