#include <iostream>
#include <string>	
using namespace std;

//use-wide variable for whole system
int Option = 0;
int size = 0;
void LoginInterface();
void NurseMainInterface();
void DoctorMainInterface();
void PatientDetailTemp();
void DeleteOrderNumber(string patientid);

// Set up the Waiting List
struct Waiting_List
{
	//Patient Elements
	string Patient_ID, First_Name, Last_Name, Gender, Disability_Option, age, phone, Patient_IC;
	//Optional Elements
	string Doctor_Name, Sickness_Description;
	//Set It As Null
	string Medicine_Information, Visit_Date, Visit_Time;
	Waiting_List* nextAddress = nullptr;
	Waiting_List* prevAddress = nullptr;
}*header, * newnode, * current, * tail;

//Set Up the Patient Visit History List
struct Visit_History_List
{
	// Patient Elements
	string Patient_ID, First_Name, Last_Name, Gender, Disability_Option, age, phone, Patient_IC;
	// Visit Date Time
	string Visit_Date, Visit_Time;
	//Optional Elements
	string Doctor_Name, Sickness_Description, Medicine_Information;
	Visit_History_List* nextAddress = nullptr;
	Visit_History_List* prevaddress = nullptr;
}*head, * newnodes, * currents, * tails;

//Process of Add New Patient to End of List
void AddPatient(string Patient_ID, string First_Name, string Last_Name, string Gender,
	string Disability_Option, string age, string phone, string Patient_IC, string Doctor_Name, string Sickness_Description,
	string Medicine_Information, string Visit_Date, string Visit_Time)
{
	//create a newnode
	newnode = new Waiting_List;

	//Insert all Detail into Newnode
	newnode->Patient_ID = Patient_ID;
	newnode->First_Name = First_Name;
	newnode->Last_Name = Last_Name;
	newnode->Gender = Gender;
	newnode->Disability_Option = Disability_Option;
	newnode->age = age;
	newnode->phone = phone;
	newnode->Patient_IC = Patient_IC;
	newnode->Doctor_Name = Doctor_Name;
	newnode->Sickness_Description = Sickness_Description;
	newnode->Medicine_Information = Medicine_Information;
	newnode->Visit_Date = Visit_Date;
	newnode->Visit_Time = Visit_Time;
	newnode->nextAddress = NULL;

	//Check the Context of List is Empty or Not
	if (header == NULL)
	{
		//Make Header Pointer to Refer newnode
		header = newnode;
	}
	else
	{
		//assign noewnode to front header if list not empty
		newnode->nextAddress = header;
		header->prevAddress = newnode;
		//Assign header to refer newnode
		header = newnode;
	}
	::size++;
}

void InsertVisitHistoryList(string Patient_ID, string First_Name, string Last_Name, string Gender,
	string Disability_Option, string age, string phone, string Patient_IC, string Doctor_Name, string Sickness_Description,
	string Medicine_Information, string Visit_Date, string Visit_Time) // insertion sorting 
{
	//create a newnode
	newnodes = new Visit_History_List;

	//Insert all Detail into Newnode
	newnodes->Patient_ID = Patient_ID;
	newnodes->First_Name = First_Name;
	newnodes->Last_Name = Last_Name;
	newnodes->Gender = Gender;
	newnodes->Disability_Option = Disability_Option;
	newnodes->age = age;
	newnodes->phone = phone;
	newnodes->Patient_IC = Patient_IC;
	newnodes->Doctor_Name = Doctor_Name;
	newnodes->Sickness_Description = Sickness_Description;
	newnodes->Medicine_Information = Medicine_Information;
	newnodes->Visit_Date = Visit_Date;
	newnodes->Visit_Time = Visit_Time;
	newnodes->nextAddress = NULL;

	//Check the Context of List is Empty or Not
	if (head == NULL)
	{
		//Make Header Pointer to Refer newnode
		head = newnodes;
	}
	else
	{
		//assign noewnode to front header if list not empty
		newnodes->nextAddress = head;
		head->prevaddress = newnodes;
		//Assign header to refer newnode
		head = newnodes;
	}
	::size++;
}
//Process of Displaying PatientVisitHistory List Page by Page
void PageByPageHistoryList()
{
	current = header;
	int decision = 1;
	while (decision != 3)
	{
		system("CLS");
		cout << "\n=====================================================\n";
		cout << "\nDetails for Patient Visit History List " << current->Patient_ID << " :";
		cout << "\n=====================================================\n";
		cout << "Patient ID: " << current->Patient_ID << endl;
		cout << "Patient First Name: " << current->First_Name << endl;
		cout << "Patient Last Name: " << current->Last_Name << endl;
		cout << "Patient Gender: " << current->Gender << endl;
		cout << "Patient Disability Option: " << current->Disability_Option << endl;
		cout << "Patient Age: " << current->age << endl;
		cout << "Patient Phone: " << current->phone << endl;
		cout << "Patient IC: " << current->Patient_IC << endl;
		cout << "Doctor Name: " << current->Doctor_Name << endl;
		cout << "Patient Sickness Description: " << current->Sickness_Description << endl;
		cout << "Medicine Information: " << current->Medicine_Information << endl;
		cout << "Patient Visit Date: " << current->Visit_Date << endl;
		cout << "Patient Visit Time: " << current->Visit_Time << endl;
		cout << "\n=====================================================\n";
		cout << "1. Go to Next Patient\t 2. Go to Previous Patient\t 3. Exit Viewing Page\n";
		cout << "Please Enter Your Option: ";
		cin >> decision;
		switch (decision) {
		case 1: //1st Situation Which Proceeds to Next Patient
			if (current->nextAddress != NULL)
			{
				current = current->nextAddress;
			}
			else
			{
				cout << "No More Records Found! Can't Proceed To Next Patient!" << endl;
				system("Pause");
			}
			break;
		case 2: //2nd Situation Which Proceeds to Previous Patient
			if (current->prevAddress != NULL)
			{
				current = current->prevAddress;
			}
			else
			{
				cout << "No More Records Found! Can't Proceed To Next Patient!" << endl;
				system("Pause");
			}
			break;
		case 3:
			cout << "================================ Leaving View Patient Visit History Page ================================";
			exit(0);
		}
	}
}
void ChangePatientOrder()
{
	string PatientModification;
	string inputOrderNumber;
	int orderNumber;
	int size = ::size;

	cin.ignore();
	cout << "Enter Patient ID: ";
	getline(cin, PatientModification);

	current = header;


	if (header == NULL) {
		cout << "The waiting list is empty!";
		return NurseMainInterface();
	}

	while (current != NULL) {
		
		if (current->Patient_ID == PatientModification) {
			newnode = current;
			cout << "Enter order number: ";
			cin >> orderNumber;
			cin.ignore();


			if (orderNumber < 1 || orderNumber > size + 1) {
				cout << "Invalid Position!";
				return NurseMainInterface();
			}
			else {
				DeleteOrderNumber(PatientModification);
				current = header;
				if (orderNumber == 1) {
					newnode->nextAddress = header;
					header->prevAddress = newnode;
					header = newnode;
				}
				else {
					current = header->nextAddress;
					int current_position = 2;
					while (current != NULL && current_position != orderNumber)
					{
						current = current->nextAddress;
						current_position++;

					}

					// current->Previous => heksagon
					try {
						current->prevAddress->nextAddress = newnode;
					}
					catch (exception) {

					}
					newnode->prevAddress = current->prevAddress;
					newnode->nextAddress = current;
					current->prevAddress = newnode;
				}

			}
			::size++;
			cout << "index has been updated";
			return NurseMainInterface();

		}
		current = current->nextAddress;
	}

}

void DeleteOrderNumber(string patientID) {


	current = header;
	while (current != NULL)
	{
		//situation 1: the item is in the first location
		if (current->Patient_ID == patientID && current == header)
		{
			current = header;
			header = header->nextAddress;
			if (header != NULL)
			{
				header->prevAddress = NULL;
			}
			else
			{
				tail = NULL;
			}
			
		
			::size--;
			return;
		}
		//situation 2: the item is in the middle / last location
		else if (current->Patient_ID == patientID)
		{
			//current->previous = previous node
			current->prevAddress->nextAddress = current->nextAddress;
			if (current->nextAddress != NULL)
			{
				current->nextAddress->prevAddress = current->prevAddress;
			}
			else //no next node after delete
			{
				tail = NULL;
			}

			::size--;
			return;
		}
		current = current->nextAddress;
		
	}
}


//Process of delete node from front of WaitingList
void DeleteFrontWaitingList()
{
	if (header == NULL)
	{
		cout << "No records found in Waiting List!" << endl;
		return;
	}
	current = header;
	header = header->nextAddress;
	if (header != NULL)
	{
		header->prevAddress = NULL;
	}
	else
	{
		tail = NULL;
	}
	cout << "Patient Name: " << current->First_Name << " " << current->Last_Name << " is Called and Removed from Waiting List!" << endl;
	delete current;
}


//Process of copying info from WaitingList to PatientVisitHistory List for 1.4
void CopyPatientToVisit()
{
	newnode = new Waiting_List;
	newnode->Patient_ID = current->Patient_ID;
	newnode->First_Name = current->First_Name;
	newnode->Last_Name = current->Last_Name;
	newnode->Gender = current->Gender;
	newnode->Disability_Option = current->Disability_Option;
	newnode->age = current->age;
	newnode->phone = current->phone;
	newnode->Patient_IC = current->Patient_IC;
	newnode->Doctor_Name = current->Doctor_Name;
	newnode->Sickness_Description = current->Sickness_Description;
	newnode->Medicine_Information = current->Medicine_Information;
	newnode->Visit_Date = current->Visit_Date;
	newnode->Visit_Time = current->Visit_Time;
	newnode->nextAddress = NULL;
}

//Process of Entering Details into Front of Waiting List.
void Insert_To_Front_Of_Doubly_Waiting_List(string Patient_ID, string First_Name, string Last_Name, string Gender,
	string Disability_Option, string age, string phone, string Patient_IC, string Doctor_Name, string Sickness_Description,
	string Medicine_Information, string Visit_Date, string Visit_Time)
{
	newnode = new Waiting_List;
	newnode->Patient_ID = Patient_ID;
	newnode->First_Name = First_Name;
	newnode->Last_Name = Last_Name;
	newnode->Gender = Gender;
	newnode->Disability_Option = Disability_Option;
	newnode->age = age;
	newnode->phone = phone;
	newnode->Patient_IC = Patient_IC;
	newnode->Doctor_Name = Doctor_Name;
	newnode->Sickness_Description = Sickness_Description;
	newnode->Medicine_Information = Medicine_Information;
	newnode->Visit_Date = Visit_Date;
	newnode->Visit_Time = Visit_Time;
	newnode->nextAddress = NULL;
	newnode->prevAddress = NULL;

	if (header == NULL)
	{
		header = tail = newnode;
	}
	else
	{
		newnode->nextAddress = header;
		header->prevAddress = newnode;
		header = newnode;
		
	}
}

//Process of Entering Details into End of Waiting List
void Insert_To_End_Of_Doubly_Waiting_List(string Patient_ID, string First_Name, string Last_Name, string Gender,
	string Disability_Option, string age, string phone, string Patient_IC, string Doctor_Name, string Sickness_Description,
	string Medicine_Information, string Visit_Date, string Visit_Time)
{
	newnode = new Waiting_List;
	newnode->Patient_ID = Patient_ID;
	newnode->First_Name = First_Name;
	newnode->Last_Name = Last_Name;
	newnode->Gender = Gender;
	newnode->Disability_Option = Disability_Option;
	newnode->age = age;
	newnode->phone = phone;
	newnode->Patient_IC = Patient_IC;
	newnode->Doctor_Name = Doctor_Name;
	newnode->Sickness_Description = Sickness_Description;
	newnode->Medicine_Information = Medicine_Information;
	newnode->Visit_Date = Visit_Date;
	newnode->Visit_Time = Visit_Time;
	newnode->nextAddress = NULL;
	newnode->prevAddress = NULL;

	if (header == NULL)
	{
		header = tail = newnode;
	}
	else
	{
		newnode->prevAddress = tail;
		tail->nextAddress = newnode;
		tail = newnode;
	}
}

//FUNCTION OF DISPLAY WAITING LIST FROM FRONT
void Display_Waiting_List_From_Front() // normal printing
{
	current = header;
	while (current != NULL)
	{
		//Display Patient Details
		cout << "Patient-ID: " << current->Patient_ID << endl;
		cout << "First Name: " << current->First_Name << endl;
		cout << "Last Name: " << current->Last_Name << endl;
		cout << "Gender: " << current->Gender << endl;
		cout << "Disability Option: " << current->Disability_Option << endl;
		cout << "Doctor Name: " << current->Doctor_Name << endl;
		cout << "Sickness Description: " << current->Sickness_Description << endl;
		cout << "Patient Age: " << current->age << endl;
		cout << "Phone Number: " << current->phone << endl;
		cout << "Patient-IC: " << current->Patient_IC << endl;
		cout << "Patient-IC: " << current->Patient_IC << endl;
		current = current->nextAddress;
	}
	cout << "Waiting List Ends Here." << endl;
}

//FUNCTION OF DISPLAY WAITING LIST FROM BEHIND
void Display_Waiting_List_From_End() //reverse printing
{
	current = tail;
	while (current != NULL)
	{
		//Display Patient Details
		cout << "Patient-ID: " << current->Patient_ID << endl;
		cout << "First Name: " << current->First_Name << endl;
		cout << "Last Name: " << current->Last_Name << endl;
		cout << "Gender: " << current->Gender << endl;
		cout << "Disability Option: " << current->Disability_Option << endl;
		cout << "Doctor Name: " << current->Doctor_Name << endl;
		cout << "Sickness Description: " << current->Sickness_Description << endl;
		cout << "Patient Age: " << current->age << endl;
		cout << "Phone Number: " << current->phone << endl;
		cout << "Patient-IC: " << current->Patient_IC << endl;
		current = current->nextAddress;
	}
	cout << "Waiting List Ends Here." << endl;
	NurseMainInterface();
}

//Function of Doctor Search and Modify Patient on Patient Visit History List - 2.2
void DoctorSearchandModify()
{
	string PatientModification;
	cout << "Two Parts Needed For Modification: Sickness Description and Medicine Information." << endl;
	cin.ignore();
	cout << "Please Enter Patient-ID: ";
	getline(cin, PatientModification);
	// 1st Scenario: No records found in List
	if (header == NULL) // later on need to change it because now haven't save into the Visit History List, currently using Waiting List
	{
		cout << "The Visit History List is Empty Now! Can't Search Anything! " << endl;
		return;
	}
	// 2nd Scenario: Record found in list but in first location
	else if (head->Patient_ID == PatientModification)
	{
		cout << "1. Please Enter The Patient's Sickness Description: ";
		getline(cin, head->Sickness_Description);
		cout << "2. Please Enter The Patient's Medicine Information: ";
		getline(cin, head->Medicine_Information);
	}
	// 3rd Scenario: Record found in list but not in first location
	else
	{
		Visit_History_List* prevaddress = head;
		currents = head->nextAddress;
		while (currents != NULL)
		{
			if (currents->Patient_ID == PatientModification)
			{
				cout << "1. Please Enter The Patient's Sickness Description: ";
				getline(cin, currents->Sickness_Description);

				cout << "2. Please Enter The Patient's Medicine Information: ";
				getline(cin, currents->Medicine_Information);
				return;
			}
			currents = currents->nextAddress;
		}
		cout << "No More Modification Slots Detected For The Patient." << endl;
	}

	cout << "End of Modification." << endl;
	DoctorMainInterface();
}

//Function of Doctor View All Patients on Waiting List - 2.1
void DoctorViewPatientList()
{
	current = header;
	while (current != NULL)
	{
		//Display Patient Detail
		cout << "          ********************************************* Patient Detail *********************************************" << endl;
		cout << "Patient ID: " << current->Patient_ID << endl;
		cout << "Patient First Name: " << current->First_Name << endl;
		cout << "Patient Last Name: " << current->Last_Name << endl;
		cout << "Patient Gender: " << current->Gender << endl;
		cout << "Patient Disability Option: " << current->Disability_Option << endl;
		cout << "Patient Age: " << current->age << endl;
		cout << "Patient Phone Number: " << current->phone << endl;
		cout << "Patient IC: " << current->Patient_IC << endl;
		cout << "Doctor Name: " << current->Doctor_Name << endl;
		cout << "Patient Sickness Description: " << current->Sickness_Description << endl;
		cout << "patient medicine" << current->Medicine_Information << endl;
		cout << "Patient Visit Date: " << current->Visit_Date << endl;
		cout << "Patient Visit Time: " << current->Visit_Time << endl;

		current = current->nextAddress;
	}
	cout << "          ********************************************* End of Patient Detail *********************************************" << endl;
	DoctorMainInterface();
}
//doctor search
void DoctorSearchPatient()
{
	string keyword;
	cout << "Which Method Will Be Used To Search Patient? " << endl;
	cout << "1. Sickness Description" << endl;
	cout << "2. Patient First Name" << endl;
	cout << "Please Choose Your Option: ";
	cin >> Option;
	if (Option == 1)
	{
		cout << "Please insert sickness decriptopn for Information: ";
		cin >> keyword;
		currents = head; 
		while (currents != NULL)
		{
			if (currents->Sickness_Description.find(keyword) != string::npos) {
				cout << "====== Information For Patient First Name " << currents->First_Name << " Are As Below ======" << endl;
				cout << "Patient ID: " << currents->Patient_ID << endl;
				cout << "Patient First Name: " << currents->First_Name << endl;
				cout << "Patient Last Name: " << currents->Last_Name << endl;
				cout << "Patient Gender: " << currents->Gender << endl;
				cout << "Patient Disability Option: " << currents->Disability_Option << endl;
				cout << "Patient Age: " << currents->age << endl;
				cout << "Patient Phone Number: " << currents->phone << endl;
				cout << "Patient IC: " << currents->Patient_IC << endl;
				cout << "Doctor Name: " << currents->Doctor_Name << endl;
				cout << "Patient Sickness Description: " << currents->Sickness_Description << endl;
				cout << "patient medicine" << currents->Medicine_Information << endl;
				cout << "Patient Visit Date: " << currents->Visit_Date << endl;
				cout << "Patient Visit Time: " << currents->Visit_Time << endl;
				cout << "================================================================================" << endl;
			}
			currents = currents->nextAddress;
		}
		return DoctorMainInterface();	
	}
	else if (Option == 2)
	{
		cout << "Please Insert Patient First Name for Information: ";
		cin >> keyword;
		currents = head;
		while (currents != NULL)
		{
			if (currents->First_Name.find(keyword) != string::npos) {
				cout << "====== Information For Patient First Name " << currents->First_Name << " Are As Below ======" << endl;
				cout << "Patient ID: " << currents->Patient_ID << endl;
				cout << "Patient First Name: " << currents->First_Name << endl;
				cout << "Patient Last Name: " << currents->Last_Name << endl;
				cout << "Patient Gender: " << currents->Gender << endl;
				cout << "Patient Disability Option: " << currents->Disability_Option << endl;
				cout << "Patient Age: " << currents->age << endl;
				cout << "Patient Phone Number: " << currents->phone << endl;
				cout << "Patient IC: " << currents->Patient_IC << endl;
				cout << "Doctor Name: " << currents->Doctor_Name << endl;
				cout << "Patient Sickness Description: " << currents->Sickness_Description << endl;
				cout << "patient medicine" << currents->Medicine_Information << endl;
				cout << "Patient Visit Date: " << currents->Visit_Date << endl;
				cout << "Patient Visit Time: " << currents->Visit_Time << endl;
				cout << "================================================================================" << endl;
			}
			currents = currents->nextAddress;
		}
		return DoctorMainInterface();
	}
	else
	{
		cout << "Wrong Input For Options! Please Retry Again!" << endl;

		DoctorMainInterface();
	}
}

void VisitHistoryPageByPage()
{
	if (head == NULL)
	{
		return DoctorMainInterface();
	}

	currents = head;

	int i = ::size; int decision = 1;
	while (decision != 0)
	{
		cout << "====== Information For Patient-ID " << currents->Patient_ID << " Are As Below ======" << endl;
		cout << "Patient ID: " << currents->Patient_ID << endl;
		cout << "Patient First Name: " << currents->First_Name << endl;
		cout << "Patient Last Name: " << currents->Last_Name << endl;
		cout << "Patient Gender: " << currents->Gender << endl;
		cout << "Patient Disability Option: " << currents->Disability_Option << endl;
		cout << "Patient Age: " << currents->age << endl;
		cout << "Patient Phone Number: " << currents->phone << endl;
		cout << "Patient IC: " << currents->Patient_IC << endl;
		cout << "Doctor Name: " << currents->Doctor_Name << endl;
		cout << "Patient Sickness Description: " << currents->Sickness_Description << endl;
		cout << "patient medicine" << currents->Medicine_Information << endl;
		cout << "Patient Visit Date: " << currents->Visit_Date << endl;
		cout << "Patient Visit Time: " << currents->Visit_Time << endl;

		cout << "\n=========================================================================================================\n";
		cout << "| 1. Next patient\t 2.Previous patient\t 0.Exit to Menu Page \t|";
		cout << "\n=========================================================================================================\n";
		cout << "Select an option:";
		cin >> decision;
		cin.ignore();

		if (decision == 1 && currents->nextAddress != NULL)
		{
			currents = currents->nextAddress;
			i++;
		}
		else if (decision == 2 && currents->prevaddress != NULL)
		{
				currents = currents->prevaddress;
				i--;
			

		}
		else if (decision == 0)
		{
			return DoctorMainInterface();
		}
		else if (decision != 1 && decision != 2 && decision != 0)
		{
			cout << "Invalid option!";
			system("pause");
		}
		else
		{
			cout << "There is no more patient!" << endl;
			system("pause");
		}

	}
}
//Main Doctor Interface After Login
void DoctorMainInterface()
{
	cout << "=================== Doctor Interface ===================" << endl;
	cout << "1. View all Patients on Original Waiting List." << endl;
	cout << "2. Search Specific Patient from Patient Visit History & Modify Patient Records." << endl;
	cout << "3. Sort & Display All Records from Patient Visit History List." << endl;
	cout << "4. Search Patients from Patient Visit History List." << endl;
	cout << "5. Logout System." << endl;
	cout << "Please Enter Your Options: ";
	cin >> Option;
	bool Switches = true;
	switch (Option) {
	case 1:
		cout << "**********************Entering Original Waiting List For View**********************" << endl;
		DoctorViewPatientList();
		Switches = true;
		break;
	case 2:
		cout << "**********************Entering Patient Visit History For Searching & Modification**********************" << endl;
		DoctorSearchandModify();
		Switches = true;
		break;
	case 3:
		cout << "**********************Entering Patient Visit History For Sorting & Displaying**********************" << endl;
		VisitHistoryPageByPage();
		Switches = true;
		break;
	case 4:
		cout << "**********************Entering Patient Visit History - Sickness Description For Searching**********************" << endl;
		DoctorSearchPatient();
		Switches = true;
		break;
	case 5:
		cout << "=========================Terminate System, Returning Main Interface=========================" << endl;
		LoginInterface();
		Switches = true;
		break;
	default:
		Switches = false;
	}
	if (Switches == false)
	{
		cout << "Wrong Option Input Detected! Please Enter Again!" << endl << endl;
		DoctorMainInterface();
	}
}

//Doctor Login Function and Coded Names
void DoctorLogin()
{
	string InsertDoctorUsername, InsertDoctorPassword;
	string DoctorUsername = "1";
	string DoctorPassword = "1";
	cout << "\nPlease Enter Doctor Username: ";
	cin >> InsertDoctorUsername;
	cout << endl;
	cout << "Please Enter Doctor Password: ";
	cin >> InsertDoctorPassword;
	cout << endl;
	if (InsertDoctorUsername != DoctorUsername && InsertDoctorPassword != DoctorPassword)
	{
		cout << "Wrong Entry! Please Enter Again!" << endl;
		DoctorLogin();
	}

	if (InsertDoctorUsername == DoctorUsername && InsertDoctorPassword == DoctorPassword)
	{
		cout << "Correct Entry! Entering Main Interface." << endl;
		DoctorMainInterface();
	}
}

//Function for Sort Waiting List in Ascending/ Descending Order. - 1.6
void NurseSortList()
{
	Display_Waiting_List_From_End();
}

//Function for Search Patient from Waiting list based on ID/First Name. - 1.5
void NurseSearchPatient()
{
	string keyword;
	cout << "Which Method Will Be Used To Search Patient? " << endl;
	cout << "1. Patient-ID" << endl;
	cout << "2. Patient First Name" << endl;
	cout << "Please Choose Your Option: ";
	cin >> Option;
	if (Option == 1)
	{
		cout << "### Patient-ID Searching Method Activate. ###" << endl;
		cout << "Please Insert Patient-ID for Information: ";
		cin >> keyword;
		current = header;  //this one need to change later as well
		while (current != NULL)
		{
			if (current->Patient_ID.find(keyword) != string::npos) {
				cout << "====== Information For Patient-ID " << current->Patient_ID << " Are As Below ======" << endl;
				cout << "Patient ID: " << current->Patient_ID << endl;
				cout << "Patient First Name: " << current->First_Name << endl;
				cout << "Patient Last Name: " << current->Last_Name << endl;
				cout << "Patient Gender: " << current->Gender << endl;
				cout << "Patient Disability Option: " << current->Disability_Option << endl;
				cout << "Patient Age: " << current->age << endl;
				cout << "Patient Phone Number: " << current->phone << endl;
				cout << "Patient IC: " << current->Patient_IC << endl;
				cout << "Doctor Name: " << current->Doctor_Name << endl;
				cout << "Patient Sickness Description: " << current->Sickness_Description << endl;
				cout << "Patient Visit Date: " << current->Visit_Date << endl;
				cout << "Patient Visit Time: " << current->Visit_Time << endl;
				cout << "================================================================================" << endl;
			}
			current = current->nextAddress;
		}
		cout << "End of Searching. To Continue Press 1, To Terminate Press 0: ";
		return;
	}
	else if (Option == 2)
	{
		cout << "### Patient First Name Searching Method Activate. ###" << endl;
		cout << "Please Insert Patient First Name for Information: ";
		cin >> keyword;
		current = header;
		while (current != NULL)
		{
			if (current->First_Name.find(keyword) != string::npos) {
				cout << "====== Information For Patient First Name " << current->First_Name << " Are As Below ======" << endl;
				cout << "Patient ID: " << current->Patient_ID << endl;
				cout << "Patient First Name: " << current->First_Name << endl;
				cout << "Patient Last Name: " << current->Last_Name << endl;
				cout << "Patient Gender: " << current->Gender << endl;
				cout << "Patient Disability Option: " << current->Disability_Option << endl;
				cout << "Patient Age: " << current->age << endl;
				cout << "Patient Phone Number: " << current->phone << endl;
				cout << "Patient IC: " << current->Patient_IC << endl;
				cout << "Doctor Name: " << current->Doctor_Name << endl;
				cout << "Patient Sickness Description: " << current->Sickness_Description << endl;
				cout << "Patient Visit Date: " << current->Visit_Date << endl;
				cout << "Patient Visit Time: " << current->Visit_Time << endl;
				cout << "================================================================================" << endl;
			}
			current = current->nextAddress;
		}
		return;
	}
	else
	{
		cout << "Wrong Input For Options! Please Retry Again!" << endl;
		cout << "Wrong Input For Options! Please Retry Again!" << endl;
		NurseMainInterface();
	}
}

//Function for Calling Patient to be Treated. - 1.4
void NurseCallPatient()
{
	string PatientModification;

	current = header;
	cout << "Enter Patient ID: ";
	getline(cin, PatientModification);

	if (header == NULL) {
		cout << "List is empty!";
		return;
	}
	// Patient in the first index
	else if (header->Patient_ID == PatientModification) {
		DeleteFrontWaitingList();
		cout << "Patient has been successfully removed from the queue, being called.";
	}
}

//Function for View All Patients From Original Waiting List. - 1.3
void NurseViewPatientList()
{
	current = header;
	while (current != NULL)
	{
		//Display Patient Detail
		cout << "********************************************* Patient Detail *********************************************" << endl;
		cout << "Patient ID: " << current->Patient_ID << endl;
		cout << "Patient First Name: " << current->First_Name << endl;
		cout << "Patient Last Name: " << current->Last_Name << endl;
		cout << "Patient Gender: " << current->Gender << endl;
		cout << "Patient Disability Option: " << current->Disability_Option << endl;
		cout << "Patient Age: " << current->age << endl;
		cout << "Patient Phone Number: " << current->phone << endl;
		cout << "Patient IC: " << current->Patient_IC << endl;
		cout << "Doctor Name: " << current->Doctor_Name << endl;
		cout << "Patient Sickness Description: " << current->Sickness_Description << endl;
		cout << "Patient Visit Date: " << current->Visit_Date << endl;
		cout << "Patient Visit Time: " << current->Visit_Time << endl;

		current = current->nextAddress;
	}
	cout << "********************************************* End of Patient Detail *********************************************" << endl;
	NurseMainInterface();
}

//Function of Change Patient Order - 1.2
void NurseChangePatient()
{

}

//Function of Add New Patient - 1.1
void NurseAddPatient()
{
	string Patient_ID, First_Name, Last_Name, Gender, Disability_Option, age, phone, Patient_IC, Doctor_Name;
	string Visit_Date, Visit_Time;
	//For continuous loop usage int
	int decision = 1;
	string Medicine_Information = "Pending";
	string Sickness_Description = "Pending";

	//Time for User to Insert Information
	while (decision != 0)
	{
		cout << "1. Please Enter Patient-ID: ";
		cin >> Patient_ID;
		cout << "2. Please Enter Patient First Name: ";
		cin >> First_Name;
		cin.ignore();
		cout << "3. Please Enter Patient Last Name: ";
		getline(cin, Last_Name);
		cout << "4. Please Enter Patient Gender [Male/Female]: ";
		cin >> Gender;
		cout << "5. Please Enter Patient Disability Option: ";
		cin >> Disability_Option;
		cout << "6. Please Enter Patient Age: ";
		cin >> age;
		cout << "7. Please Enter Patient Phone: ";
		cin >> phone;
		cout << "8. Please Enter Patient IC: ";
		cin >> Patient_IC;
		cin.ignore();
		cout << "General: Doctor Tan\nEmergency: Doctor Suresh" << endl;
		cout << "9. Please Enter Doctor Name: ";
		getline(cin, Doctor_Name);
		cout << "10. Please Enter Patient Visit Date: ";
		cin >> Visit_Date;
		cin.ignore();
		cout << "11. Please Enter Patient Visit Time: ";
		cin >> Visit_Time;
		cout << "Notice! Medicine Description will be Entered by Doctor." << endl;
		//Execute Process of add patient
		AddPatient(Patient_ID, First_Name, Last_Name, Gender, Disability_Option, age, phone, Patient_IC, Doctor_Name,
			Sickness_Description, Medicine_Information, Visit_Date, Visit_Time);
		InsertVisitHistoryList(Patient_ID, First_Name, Last_Name, Gender, Disability_Option, age, phone, Patient_IC, Doctor_Name,
			Sickness_Description, Medicine_Information, Visit_Date, Visit_Time);
		cout << "End of Adding 1 Patient. Press 1 to CONTINUE or Press 0 to Return: ";
		cin >> decision;
	}
	if (decision == 0)
	{
		cout << "**********************Return to Nurse Interface**********************" << endl;
		NurseMainInterface();
		cin.ignore();
	}
}

//Main Nurse Interface After Login
void NurseMainInterface()
{
	cout << "=================== Nurse Interface ===================" << endl;
	cout << "1. Add a New Patient on Waiting List." << endl;
	cout << "2. Change Patient Order According to Priority on Waiting List." << endl;
	cout << "3. View All Patients on Original Waiting List." << endl;
	cout << "4. Calling Patient to be Treated." << endl;
	cout << "5. Search Patient from Waiting List." << endl;
	cout << "6. Sort Waiting List by Patient's Current Visit Time." << endl;
	cout << "7. Logout System." << endl;
	cout << "Please Enter Your Options: ";
	cin >> Option;
	switch (Option) {
	case 1:
		cout << "**********************Adding New Patient Into Waiting List**********************" << endl;
		NurseAddPatient();
		break;
	case 2:
		cout << "**********************Entering Waiting List To Change Order**********************" << endl;
		ChangePatientOrder();
		break;
	case 3:
		cout << "**********************Entering Waiting List To View All Patients**********************" << endl;
		NurseViewPatientList();
		break;
	case 4:
		cout << "**********************Calling Patients To Be Treated**********************" << endl;
		NurseCallPatient();
		break;
	case 5:
		cout << "**********************Entering Waiting List For Searching**********************" << endl;
		NurseSearchPatient();
		break;
	case 6:
		cout << "**********************Entering Waiting List For Sorting**********************" << endl;
		NurseSortList();
		break;
	case 7:
		cout << "=========================Terminate System, Returning Main Interface=========================" << endl;
		LoginInterface();
		break;
	}
	if (Option != 1 && Option != 2 && Option != 3 && Option != 4 && Option != 5 && Option != 6 && Option != 7)
	{
		cout << "Wrong Options Detected! Please Enter Options Again." << endl << endl;;
		NurseMainInterface();
	}
}

//Nurse Login Function and Coded Names
void NurseLogin()
{
	string InsertNurseUsername, InsertNursePassword;
	string NurseUsername = "2";
	string NursePassword = "2";
	cout << "\nPlease Enter Nurse Username: ";
	cin >> InsertNurseUsername;
	cout << endl;
	cout << "Please Enter Nurse Password: ";
	cin >> InsertNursePassword;
	cout << endl;
	if (InsertNurseUsername != NurseUsername && InsertNursePassword != NursePassword)
	{
		cout << "Wrong Entry! Please Enter Again!" << endl;
		NurseLogin();
	}

	if (InsertNurseUsername == NurseUsername && InsertNursePassword == NursePassword)
	{
		cout << "Correct Entry! Entering Main Interface." << endl;
		NurseMainInterface();
	}
}

//Login Interface of the System
void LoginInterface()
{
	int Options = 0;
	cout << " =================== Welcome To Klinik Sulaiman Patient Queue Management System ===================" << endl;
	cout << "1. Doctor Login" << endl;
	cout << "2. Nurse Login" << endl;
	cout << "3. Exit Program" << endl;
	cout << "Please Choose Your Option: ";
	cin >> Options;
	if (Options == 1)
	{
		DoctorLogin();
	}
	else if (Options == 2)
	{
		NurseLogin();
	}
	else if (Options == 3)
	{
		cout << " =================== Terminate System ===================" << endl;
		exit;
	}
}

//Execution Starting Point
int main()
{
	LoginInterface();
	return 0;
}