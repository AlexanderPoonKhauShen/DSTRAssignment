// Assignmentcpluspluss.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

//creating List for <WAITING_LIST>
struct waiting_list
{
	// Patient Elements
	string Patient_ID, First_Name, Last_Name, Gender, Disability_Option, age, phone, Patient_IC;
	//Optional Elements
	string Doctor_Name, Sickness_Description;
	waiting_list* nextAddress;
}*header, * newnode, * current;

//creating List for <PATIENT_VISIT_HISTORY_LIST>
struct Visit_History_List
{
	// Patient Elements
	string Patient_ID, First_Name, Last_Name, Gender, Disability_Option;
	// Visit Date Time
	string Visit_Date, Visit_Time;
	//Optional Elements
	string Doctor_Name, Sickness_Description, Medicine_Information;
	history_list* nextAddress;
}*head, * newnodes, * currents, * tails;

//global variable for the sequence
int size = 0;

//ALL FUNCTIONS ABOUT NURSE STARTS HERE

// FUNCTION OF <ADD NEW PATIENT INTO WAITING LIST>
void Add_Patient(string Patient_ID, string First_Name, string Last_Name, string Gender, string Disability_Option,
	string Doctor_Name, string Sickness_Description, string age, string phone, string Patient_IC)
{
	//Create a new node
	newnode = new waiting_list;

	//Insert all Details into newnode
	newnode->Patient_ID = Patient_ID;
	newnode->First_Name = First_Name;
	newnode->Last_Name = Last_Name;
	newnode->Gender = Gender;
	newnode->Disability_Option = Disability_Option;
	newnode->Doctor_Name = Doctor_Name;
	newnode->Sickness_Description = Sickness_Description;
	newnode->age = age;
	newnode->phone = phone;
	newnode->Patient_IC = Patient_IC;
	newnode->nextAddress = NULL;

	//Check the Context of List is Empty or Not
	if (header == NULL)
	{
		//Make header pointer to refer newnode
		header = newnode;
	}
	else
	{
		//Assign newnode to front of header if List NOT EMPTY
		newnode->nextAddress = header;
		//Assign header to refer newnode
		header = newnode;
	}
	::size++;
}
	

//FUNCTION OF <CHANGE PATIENT ORDER>
void ChangePatientOrder()
{

}

//FUNCTION OF <DISPLAY PATIENT LIST>
void DisplayWaitingList()
{
	current = header;
	//Read all the content from the list one-by-one
	while (current != NULL) // NULL = List ended
	{
		//Display Patient Details
		cout << "Patient-ID: " << current->Patient_ID << "\n";
		cout << "First Name: " << current->First_Name << "\n";
		cout << "Last Name: " << current->Last_Name << "\n";
		cout << "Gender: " << current->Gender << "\n";
		cout << "Disability Option: " << current->Disability_Option << "\n";
		cout << "Doctor Name: " << current->Doctor_Name << "\n";
		cout << "Sickness Description: " << current->Sickness_Description << "\n";
		cout << "Patient Age: " << current->age << "\n";
		cout << "Phone Number: " << current->phone << "\n";
		cout << "Patient-IC: " << current->Patient_IC << endl << endl;

		//Change current to nextadress to Prevent Looping
		current = current->nextAddress;
	}
}


//FUNCTION OF <CALLING PATIENTS>
void CallPatients()
{
	if (header == NULL)
	{
		cout << "The Patient List already empty! No deletion needed" << endl;
		return;
	}

	//Step 1: Create Variable,current and initialize to head
	current = header;
	//Step 2: Assign head value with header->nextAddress
	header = header->nextAddress;
	//Step 3: Delete Current
	cout << "Patient " << current->First_Name << " is being removed from the Patient List." << endl;
	delete current;
	//SAtep 4: Decrement variable size by 1
	::size - 1;
}

//FUNCTION OF <SEARCH PATIENTS>
void SearchPatient()
{
	int searchOption;
	cout << " Which Method Do You Want to Use to Search Patient?\n";
	cout << "1. Search via PatientID\n";
	cout << "2. Search via First Name\n" << endl;
	cin >> searchOption;
	if (searchOption == 1)
	{
		cout << "PatientID Method Selected.\nPlease Enter PatientID: ";
		//insert PatientID
	}
	else if (searchOption == 2)
	{
		cout << "Patient First Name Method Selected.\nPlease Enter Patient First Name: ";
		//insert First Name
	}

}

//FUNCTION OF <SORT WAITING LIST>
void SortWaitingList()
{

}

void getsize()
{
	//Start to read list
	current = header;

	//Prepare variable to store size value
	int size = 0;

	//count the item in list using while loop
	while (current != NULL)
	{
		size++;
		current = current->nextAddress;
	}

	//display answer using cout
	cout << "The size of the list now is: " << size << endl;
}

//ALL FUNCTIONS ABOUT DOCTOR STARTS HERE

//FUNCTION OF <DOCTOR VIEW ORIGINAL WAITING LIST>
void DoctorViewWaitingList()
{
	current = header;
	while (current != NULL)
	{
		cout << "Patient-ID: " << current->Patient_ID << "\n";
		cout << "First Name: " << current->First_Name << "\n";
		cout << "Last Name: " << current->Last_Name << "\n";
		cout << "Gender: " << current->Gender << "\n";
		cout << "Disability Option: " << current->Disability_Option << "\n";
		cout << "Doctor Name: " << current->Doctor_Name << "\n";
		cout << "Sickness Description: " << current->Sickness_Description << "\n";
		cout << "Patient Age: " << current->age << "\n";
		cout << "Phone Number: " << current->phone << "\n";
		cout << "Patient-IC: " << current->Patient_IC << endl << endl;
		current = current->nextAddress;
	}
	cout << "List is endeded" << endl << endl;
	cout << "A1";

	current = header;
	while (current!=NULL) {

	}
}

//FUNCTION OF <DOCTOR SEARCH AND MODIFY PATIENT RECORD>
void DoctorSearchAndModify()//sequenctial searching https://www.hellgeeks.com/sequential-search/
{
	int option;
	cout << "1. Modify patient medicine" <<endl;
	cout << "2. Modify sickness description" << endl;
	cout << "Enter the option you want to modify: ";
	cin >> option;
	switch (option)
	{
	case 1:
		DoctorModifyMedicine;
	case 2:
		DoctorModifySickness;
	default:
		break;
	}
}

void DoctorModifySickness() {
	string patientID;
	cout << "Enter Patient ID";
	getline(cin, patientID);

	if (head == NULL) {
		cout << " the list is empty now! cant search anything here" << endl;
		return;
	}
	else if (head->Patient_ID == patientID) {
		cout << "Enter the sickeness description:" << endl;
		getline(cin, head->Sickness_Description);
	}
	else { // situaltion 3 list not empty and item not the first node
		Visit_History_List* prev = head;
		current = head->nextAddress;// detect the item to update
		while (current != NULL) {
			if (current->Patient_ID == patientID) {
				cout << "please retype your book detail here" << endl;
				getline(cin, current->Sickness_Description);
				return;
			}
			current = current->nextAddress;
		}
		cout << "The system can't find any for updating! " << endl;
	}
	cout << "A2";
}

void DoctorModifyMedicine() {
	string patientID;
	cout << "Enter Patient ID";
	getline(cin, patientID);

	if (head == NULL) {
		cout << " the list is empty now! cant search anything here" << endl;
		return;
	}
	else if (head->Patient_ID == patientID) {
		cout << "Enter the sickeness description:" << endl;
		getline(cin, head->Sickness_Description);
	}
	else { // situaltion 3 list not empty and item not the first node
		Visit_History_List* prev = head;
		current = head->nextAddress;// detect the item to update
		while (current != NULL) {
			if (current->Patient_ID == patientID) {
				cout << "please retype your book detail here" << endl;
				getline(cin, currents->Medicine_Information);
				return;
			}
			current = current->nextAddress;
		}
		cout << "The system can't find any for updating! " << endl;
	}
	cout << "A2";
}
void DoctorModifyDoctorName() {
	string patientID;
	cout << "Enter Patient ID";
	getline(cin, patientID);

	if (head == NULL) {
		cout << " the list is empty now! cant search anything here" << endl;
		return;
	}
	else if (head->Patient_ID == patientID) {
		cout << "Enter the sickeness description:" << endl;
		getline(cin, head->Doctor_Name);
	}
	else { // situaltion 3 list not empty and item not the first node
		Visit_History_List* prev = head;
		current = head->nextAddress;// detect the item to update
		while (current != NULL) {
			if (current->Patient_ID == patientID) {
				cout << "please enter doctor name here" << endl;
				getline(cin, currents->Doctor_Name);
				return;
			}
			current = current->nextAddress;
		}
		cout << "The system can't find any for updating! " << endl;
	}
	cout << "A2";
}

//FUNCTION OF <DOCTOR SORT AND DISPLAY PATIENT VISIT HISTORY>
void DoctorSortAndDisplay()//heap sort https://www.geeksforgeeks.org/heap-sort-for-decreasing-order-using-min-heap/
{

	cout << "A3";

} 

//FUNCTION OF <DOCTOR SEARCH PATIENT VISIT HISTORY>
void DoctorSearchPatient() //sequnctial; search
{
	string keyword;
	cout << "enter patient name";
	currents = head;
	int position = 1;
	cout << "\nbooklist that contain the word of " << keyword << "as below: " << endl;
	while (currents != NULL) {
		if (currents->First_Name.find(keyword) != string::npos) {
			cout << position << "-" << current->First_Name << endl;

		}
		currents = currents->nextAddress;
		position++;
	}
	cout << "A4";

}

//FUNCTION OF <NURSE INTERFACE>
void NurseInterface()
{
	int option = 0;
	cout << "=========================Nurse Main Interface=========================";
	cout << "1. Add New Patient On The Waiting List.\n";
	cout << "2. Change The Patient Order According To The Priority On Waiting List.\n";
	cout << "3. View All Patients On The Original Waiting List.\n";
	cout << "4. Calling Patient To Be Treated.\n";
	cout << "5. Search Patient From Waiting List Based On PatientID Or First Name.\n";
	cout << "6. Sort Waiting List By Patient's Current Visit Time.\n";
	cout << "7. Logout System.\n";
	cout << "Please Enter Your Option: " << endl;
	cin >> option;
	switch (option) {
	case 1:
		cout << "**********************Adding New Patient Into Waiting List**********************";
	//	Add_Patient(); add parameter 
		break;
	case 2:
		cout << "**********************Entering Waiting List To Change Order**********************";
		ChangePatientOrder();
		break;
	case 3:
		cout << "**********************Entering Waiting List To View All Patients**********************";
		DisplayWaitingList();
		break;
	case 4:
		cout << "**********************Calling Patients To Be Treated**********************";
		CallPatients();
		break;
	case 5:
		cout << "**********************Entering Waiting List For Searching**********************";
		SearchPatient();
		break;
	case 6:
		cout << "**********************Entering Waiting List For Sorting**********************";
		SortWaitingList();
		break;
	case 7:
		cout << "=========================Terminate System, Returning Main Interface=========================";
		break;
	}
	while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6 && option !=7)
	{
		cout << "Wrong Input! Please Enter Again!" << endl;
	}
}


//FUNCTION OF <DOCTOR INTERFACE>
void DoctorInterface()
{
	int options = 0;

		cout << "=========================Doctor Main Interface=========================" << endl;
		cout << "1. View All Patients On The Original Waiting List.\n";
		cout << "2. Search Specific Patient From The Patient's Visit History & Modify Patient Record.\n";
		cout << "3. Sort & Display Records From Patient's Visit History.\n";
		cout << "4. Search Patients From Patient's Visit History List Based On Sickness Description.\n";
		cout << "5. Logout System.\n";
		cout << "Please Enter Your Option: " << endl;
		cin >> options;

		switch (options) {
		case 1:
			cout << "**********************Entering Original Waiting List For View**********************";
			DoctorViewWaitingList();
			break;
		case 2:
			cout << "**********************Entering Patient Visit History For Searching & Modification**********************";
			DoctorSearchAndModify();
			break;
		case 3:
			cout << "**********************Entering Patient Visit History For Sorting & Displaying**********************";
			DoctorSortAndDisplay();
			break;
		case 4:
			cout << "**********************Entering Patient Visit History - Sickness Description For Searching**********************";
			DoctorSearchPatient();
			break;
		case 5:
			cout << "=========================Terminate System, Returning Main Interface=========================";
			break;
		}
		if (options != 1 && options != 2 && options != 3 && options != 4 && options != 5)
		{
			cout << "Wrong Input! Please Enter Again!" << endl;
			return DoctorInterface();
		}
	
}

int main()
{
	int option = 0;

	cout << "=========================Welcome To Klinik Sulaiman Patient Queue Management System========================="<<endl;
	cout << "1. Nurse Login\n";
	cout << "2. Doctor Login\n";
	cout << "3. Terminate System\n";
	cout << "Please Enter Your Option: " << endl;
	cin >> option;
	if (option == 1)
	{
		//Login Program
		string NurseUsername, NursePassword;
		static int chances = 5;
		while (chances > 0)
		{
			cout << "Please Enter Nurse Username: " << endl;
			getline(cin, NurseUsername);
			cout << "Please Enter Nurse Password: " << endl;
			getline(cin, NursePassword);
			chances = chances - 1;

			while (NurseUsername != "UC2F2102SE" && NursePassword != "140084DSTR")
			{
				cout << "Wrong Username and Password!" << "\n" << endl;
				chances--;

			}
			if (chances < 0)
			{
				cout << "Too Much Attempt! Auto Terminate Program Mode Activate.";
				break;
			}
		}

		string Patient_ID, First_Name, Last_Name, Gender, Disability_Option, age, phone, Patient_IC;
		//Optional Elements
		string Doctor_Name, Sickness_Description;
		header = current = NULL;

		// A boolean
		int decision = 1;

		//Read Waiting_List Information from User
		while (decision != 0)
		{
			cout << "Enter Patient-ID: ";
			getline(cin, Patient_ID);
			cout << "Enter Patient First Name: ";
			getline(cin, First_Name);
			cout << "Enter Patient Last Name: ";
			getline(cin, Last_Name);
			cout << "Enter Patient Gender: ";
			getline(cin, Gender);
			cout << "Enter Patient Disability: ";
			getline(cin, Disability_Option);
			cout << "Enter Patient Age: ";
			getline(cin, age);
			cout << "Enter Phone Number: ";
			getline(cin, phone);
			cout << "Enter Patient-IC: ";
			getline(cin, Patient_IC);
			cout << "Enter Doctor Name ";
			getline(cin, Doctor_Name);
			cout << "Enter Sickness Description: ";
			getline(cin, Sickness_Description);

			Add_Patient(Patient_ID, First_Name, Last_Name, Gender, Disability_Option, age, phone, Patient_IC, Doctor_Name, Sickness_Description);
			cout << endl;
			cout << "To add new Patient press 1, No for 0. \n";
			cin >> decision;
			Sleep(5000); // wait 5 seconds
			cout << endl;
			cin.ignore();
		}
		
		
	}
	else if (option == 2)
	{
		string DoctorUsername, DoctorPassword;
		cout << "Please Enter Doctor Username: " << endl;
		getline(cin, DoctorUsername);
		cout << "Please Enter Doctor Password: " << endl;
		getline(cin,DoctorPassword);
		DoctorInterface();
	}
	else if (option == 3)
	{
		cout << "=========================Terminate System, Goodbye=========================";
		exit;
	}
	
	DisplayWaitingList();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
