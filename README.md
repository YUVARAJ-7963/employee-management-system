🧑‍💼 Employee Management System – C Project
This is a simple C-based mini project designed to manage employee information efficiently within an organization. It includes essential operations like adding, modifying, deleting, and displaying employee records along with salary calculations.

📌 Features
🔐 Login System
Secure login for admin access.

➕ Add Employee
Collects employee data including Name, Age, Qualification, Mobile Number, Email ID, Designation, and Salary. Auto-generates a unique Employee ID.

🧾 Display Details
View:

Individual employee data

Designation-wise salary records

All employees' salary details

✏️ Modify Employee
Update personal and professional details, with automatic recalculations of salary components.

❌ Delete Employee
Remove employee records from all relevant files.

📁 File Structure
Employee management Project.c – Main program logic

Mail & Number Checking.C – Input validation for Email ID and Mobile Number

Salary Headings.c – Salary heading initializations for each designation

display Details.c – Functions to display various employee and salary details

remove.c – Handles deletion of employee data

modify.c – Handles modification of employee data

🧮 Salary Calculation
Based on the employee's Designation, the system calculates:

DA – Dearness Allowance

HRA – House Rent Allowance

PF – Provident Fund

IT – Income Tax

Gross Salary = Basic + DA + HRA

Detection = PF + IT

Net Salary = Gross Salary - Detection

Each role has different calculation percentages:

Designation	DA	HRA	PF	IT

Software Architect	4%	3%	2%	1%

Developer	4.5%	3.5%	2.5%	1.5%

Designer	5%	4%	3%	2%

Quality Assurance	5.5%	4.5%	3.5%	2.5%

Business Analyst	6%	5%	4%	3%

💻 Technologies Used
Language: C

Compiler: GCC

Platform: Windows Terminal / Turbo C (for conio.h and getch() support)

📚 References
Book
E. Balagurusamy, “Programming in ANSI C”, McGraw Hill, 8th Edition (2019)

Online
GeeksforGeeks

W3Schools

Javatpoint

Programiz

🙋‍♂️ Author
Yuvaraj
Mini-project developed as part of an academic submission.

