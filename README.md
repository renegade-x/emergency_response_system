1.	Introduction
The Centralized Emergency Response System is a connected plaform which deals with civil emergencies in a timely fashion. The platform provides as an connection point for emergencies such as police, fire brigade and paramedics.  This system provides an all-in-one solution for these emergencies. Emergencies are registered, processed and tracked according to severity. This project highlights the importance of a structured approach to emergency response. 
2.	Objective
The main goal of this project is creating a system that can efficiently manage emergencies by:
•	Registering Emergencies: Capturing details such as type, severity, description, and location.
•	Processing Emergencies: Resolving incidents based on severity, ensuring critical cases are handled first.
•	Categorizing Emergencies: Viewing and managing emergencies under distinct categories (Police, Fire, Medical).
•	Tracking Resolved Cases: Maintaining a history of resolved emergencies for accountability and analysis.
•	Providing Statistics: Offering insights into reported, resolved, and pending emergencies.
The project aims to simulate a real-world use case where emergency response systems are critical for saving lives and resources.
3.	Functionality
The Emergency Response System offers the following key features:
1.	Register New Emergency:
o	Adds new emergencies with details such as type, severity, description, and location.
o	Automatically categorizes emergencies based on type.
2.	Process Emergency:
o	Resolves emergencies in the order of registration while considering their severity.
o	Removes processed emergencies from active lists and logs them as resolved cases.

3.	View Emergencies by Category:
o	Displays active emergencies categorized as Police, Fire, or Medical for better organization and analysis.
4.	View Resolved Emergencies:
o	Shows the history of resolved cases in reverse order of processing.
5.	Display Statistics:
o	Provides an overview of total emergencies reported, resolved, and pending.

4.	Technology
•	Programming Language: C++ (with standard libraries)
•	Data Structures:
o	Queue: To manage the order of emergency processing.
o	Doubly Linked List: To categorize and display emergencies.
o	Stack: To maintain a history of resolved emergencies.
•	Algorithms:
o	Sorting by severity using a simple bubble sort.
