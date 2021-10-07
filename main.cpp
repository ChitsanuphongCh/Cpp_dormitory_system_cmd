#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <time.h>

using namespace std;

// Menu main
void showMenu();

// function for person
void show_dataPerson();
void search_dataPerson();
void insert_dataPerson();
void delete_dataPerson();

// function for room
void show_dataRoom();
void search_dataRoom();
void insert_dataRoom();
void delete_dataRoom();

// function for stay
void show_stay();
void stay_room();
void stay_payments();
void stay_paymentPriceRoom();
void stay_pay_water();
void stay_pay_electric();

// Return room
void returnRoomMain();
void returnRoom();

// report
void report();
void reportRoomBusy();
void reportRoomEmpty();
void reportRoomNotYetPriceRoom();
void reportRoomNotYetPayWater();
void reportRoomNotYetPayElectric();

// global variable
int unitPerson = 0, totalPerson = 5;
int unitRoom = 0, totalRoom = 5;
int totalRelation = 2;
float total_UID_PERSON = 1005, total_UID_ROOM = 105;

// data Person
string	dataPerson[100][4] = {{"6306021621138","Chitsanuphong Chaihong","09876543219"}, 
			      {"6306021621139","Napat Tapan","09876543218"}, 
			      {"6306021621140","Natdanai Ianadtan","09876543217"}, 
			      {"6306021621141","Supawit Tiwapus","09876543216"}, 
			      {"6306021621142","Alien Neila","09876543215"}};

// data room				no. type price 	status
float   dataRoom[100][7] = {{101, 1, 2500, 0, 0, 554, 715},
			    {102 , 2, 4000, 0, 0, 910, 615},
			    {103, 2, 4000, 1, 0, 0, 0},
			    {104, 2, 4000, 0, 0, 612, 342},
			    {105, 1, 2500, 1, 0, 531, 543}};

// data relationship
string dataRelation[100][2] = {{"103","6306021621142"},
							   {"105","6306021621139"}};
// string dataRelation[100][2];


int main() {
	
	system("cls");

	// variable set
	int choice; // select menu

	// call function
	showMenu();

	reInput:
	cout << "Enter menu : ";
	cin >> choice;

	switch (choice) {
		case 1 :
			show_dataPerson();
			break;
		case 2 :
			show_dataRoom();
			break;
		case 3 :
			show_stay();
			break;
		case 4 :
			returnRoomMain();
			break;
		case 5 :
			report();
			break;
		case 6 :
			exit(0);
			break;
		default :
			if (choice > 6) {
				goto reInput;
				cout << "Not found number of menu input again" << endl;
			}
	}

	cout << endl;
	system("pause");
	return 0;
}

							//		SHOW MENU
void showMenu()
{
	system("cls");
	
	cout << "|" << string(20, '-') << "MENU" << string(20, '-') << "|" << endl;
	cout << endl;
	cout << string(10, ' ') << "1. Data Person" << endl;
	cout << string(10, ' ') << "2. Data Room" << endl;
	cout << string(10, ' ') << "3. Stay" << endl;
	cout << string(10, ' ') << "4. Return Room" << endl;
	cout << string(10, ' ') << "5. Report" << endl;
	cout << string(10, ' ') << "6. Exit" << endl;
	cout << endl;
}

							//		MAIN SHOW DATA PERSON
void show_dataPerson()
{
	system("cls");

	// variable set
	int choice; // select menu

	cout << endl << endl;
	cout << setw(42) << setfill(' ') << "DATA PERSON" << endl << endl;
	cout << setw(75) << setfill('-') << "" << endl;
	cout << string(5, ' ') << "NO." << string(3, ' ') << "STD ID" << string(14, ' ') << "FULLNAME" << string(20, ' ') << "TEL" << endl;
	cout << setw(75) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalPerson; i++){
		cout << left << string(5,' ') << setw(6) << setfill(' ') << i+1 
			 << setw(20) << setfill(' ') << dataPerson[i][0] 
		     << setw(28) << setfill(' ') << dataPerson[i][1] 
			 << setw(8) << setfill(' ') << dataPerson[i][2] << endl;
	}
	cout << endl << setw(75) << setfill('-') << "" << endl;
	
	cout << endl;
	cout << string(42, ' ') << "Menu : " << endl;
	cout << string(50, ' ') << "1. Search data person" << endl;
	cout << string(50, ' ') << "2. Insert data person" << endl;
	cout << string(50, ' ') << "3. Delete data person" << endl;
	cout << string(50, ' ') << "4. Back" << endl;
	reInput:
	cout << string(26, ' ') << "Enter number of menu :  ";
	cin >> choice;

	switch (choice) {
		case 1 :
			search_dataPerson();
			break;
		case 2 :
			insert_dataPerson();
			break;
		case 3 :
			delete_dataPerson();
			break;
		case 4 :
			main();
			break;
		default :
			if (choice > 5) {
				goto reInput;
				cout << "Not found number of menu input again" << endl;
			}
	}
}

							//		INSERT DATA PERSON
void insert_dataPerson()
{
	system("cls");
	
	// variable set
	string ID;	// put to array

	cout << "|" << string(20, '-') << "INSERT DATA PERSON" << string(20, '-') << "|" << endl;
	cout << endl;
	
	cout << string(10, ' ') << "Enter number of person : ";
	cin >> unitPerson;
	cout << endl;

	for (int i = totalPerson; i < totalPerson+unitPerson; i++) {
		
		/*
		// ID put
		total_UID_PERSON++;
		stringstream string_ID;
		string_ID << total_UID_PERSON;
		ID = string_ID.str();
		dataPerson[i][0] = ID;
		*/

		//do {
		cout << string(10, ' ') << "Enter ID Card : ";
		cin >> dataPerson[i][1];
		//} while (dataPerson[i][2].length() != 13);
		
		cin.get();
		cout << string(10, ' ') << "Enter Fullname : ";
		getline(cin, dataPerson[i][0]);

		//do {
		cout << string(10, ' ') << "Enter Telephone : ";
		cin >> dataPerson[i][2];
		//} while (dataPerson[i][3].length() != 10);

		cout << endl;
	}
	totalPerson += unitPerson;
	show_dataPerson();

}

							//		SEARCH DATA PERSON
void search_dataPerson() 
{
	system("cls");

	// variable set
	string ID_Crad_search; // search data
	bool check = false;	   // status search

	cout << "ENTER ID Card For Search : ";
	cin >> ID_Crad_search;

	cout << endl << endl;
	cout << string(30,' ') << "DATA PERSON" << endl << endl;
	cout << setw(75) << setfill('-') << "" << endl;
	cout << string(5, ' ') << "STD ID" << string(14, ' ') << "FULLNAME" << string(20, ' ') << "TEL" << endl;
	cout << setw(75) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalPerson; i++){
		if (ID_Crad_search == dataPerson[i][0]) {
			cout << left << string(5,' ') << setw(20) << setfill(' ') << dataPerson[i][0] << setw(28) << setfill(' ') << dataPerson[i][1] << setw(8) << setfill(' ') << dataPerson[i][2] << endl;
			check = true;
			break;
		}
	}
	
	if (check == false) cout << string(29, ' ') << "Data not found." << endl;
	cout << endl << setw(75) << setfill('-') << "" << endl << endl;
	
	cout << "Please enter to go back . . .";
	cin.get();
	cin.ignore();
	show_dataPerson();

}

							//		DELETE DATA PERSON
void delete_dataPerson() 
{
	system("cls");

	// variable set
	int ID_delete; // ID check for delete

	cout << endl << endl;
	cout << setw(42) << setfill(' ') << "DATA PERSON" << endl << endl;
	cout << setw(75) << setfill('-') << "" << endl;
	cout << string(5, ' ') << "NO." << string(3, ' ') << "STD ID" << string(14, ' ') << "FULLNAME" << string(20, ' ') << "TEL" << endl;
	cout << setw(75) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalPerson; i++){
		cout << left << string(5,' ') << setw(6) << setfill(' ') << i+1 << setw(20) << setfill(' ') << dataPerson[i][0] << setw(28) << setfill(' ') << dataPerson[i][1] << setw(8) << setfill(' ') << dataPerson[i][2] << endl;
	}
	
	cout << endl << setw(75) << setfill('-') << "" << endl << endl;

	cout << string(45, ' ') << "Enter NO. to delete :  ";
	cin >> ID_delete;

	for (int i = 0; i < totalPerson; i++){

		if ((ID_delete-1) == i) {
			dataPerson[i][0] = "";
			dataPerson[i][1] = "";
			dataPerson[i][2] = "";
			totalPerson--;
		}
	
		if (dataPerson[i][0] == "") {
			dataPerson[i][0] = dataPerson[i+1][0];
			dataPerson[i][1] = dataPerson[i+1][1];
			dataPerson[i][2] = dataPerson[i+1][2];
			dataPerson[i+1][0] = "";
			dataPerson[i+1][1] = "";
			dataPerson[i+1][2] = "";
		}
	}
	show_dataPerson();
}


//	------------------------------------------------------------------------------------------------------  //

							//		MAIN SHOW DATA ROOM
void show_dataRoom() {
	system("cls");

	// variable set
	int choice; // select menu
	string status; // show status
	string type; // type room
	
	cout << endl << endl;
	cout << string(50,' ') << "DATA ROOM" << endl << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
	cout << string(10, ' ') << "ROOM NO." << string(6,' ') << "TYPE" << string(8, ' ')<< "PRICE" 
		 << string(6, ' ') << "STATUS" 
		 << string(6, ' ') << "WATER" 
		 << string(6, ' ') << "ELECTRIC" << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalRoom; i++){
		if (dataRoom[i][3] == 0) status = "EMTPY";
		else status = "BUSY";
		if (dataRoom[i][1] == 1) type = "Room + Fan";
		else type = "Room + Air";
		cout << string(12,' ') << dataRoom[i][0] 
			 << string(6,' ') << type 
			 << string(6,' ') << dataRoom[i][2] 
			 << string(6, ' ') << left << setw(8) << setfill(' ') << dataRoom[i][5]
			 << string(6, ' ') << left << setw(8) << setfill(' ') << dataRoom[i][6]
			 << string(6, ' ') << left << setw(8) << setfill(' ') << status << endl;
	}
	
	cout << endl << string(5,' ') << setw(100) << setfill('-') << "" << endl;
	
	cout << endl;
	cout << string(50, ' ') << "MENU" << endl;
	cout << string(55, ' ') << "1. SEARCH" << endl;
	cout << string(55, ' ') << "2. INSERT" << endl;
	cout << string(55, ' ') << "3. DELETE" << endl;
	cout << string(55, ' ') << "4. BACK" << endl;
	reInput:
	cout << endl << string(50, ' ') << "Select : ";
	cin >> choice;

	switch (choice) {
		case 1 :
			search_dataRoom();
			break;
		case 2 :
			insert_dataRoom();
			break;
		case 3 :
			delete_dataRoom();
			break;
		case 4 :
			main();
			break;
		default :
			if (choice > 5) {
				goto reInput;
				cout << "Not found number of menu input again" << endl;
			}
	}	
}

							//		INSERT DATA ROOM
void insert_dataRoom()
{
	system("cls");
	char ch;
	float numberRoom, ID_Room;
	int menu, choiceBill;
	int index;
	string type;
	string status;

	cout << endl << endl << endl;

	cout << "|" << string(20, '-') << "INSERT DATA ROOM" << string(20, '-') << "|" << endl << endl;
	
	cout << string(4, ' ') << "MENU" << endl;
	cout << string(6, ' ') << "1.INSERT ROOM" << endl;
	cout << string(6, ' ') << "2.INSERT PRICE OF WATER & ELECTRIC" << endl;
	cout << string(6, ' ') << "3.BILL PRICE OF WATER & ELECTRIC" << endl;
	cout << string(6, ' ') << "4.BACK" << endl;
	cout << endl;

	cout << string(10, ' ') << "Enter menu : ";
	cin >> menu;

	if (menu == 1) {
		
		system("cls");
		
		cout << string(10, ' ') << "Enter unit insert of room : ";
		cin >> unitRoom;
		cout << endl;

		cout << string(4, ' ') << "TYPE ROOM" << endl;
		cout << string(6, ' ') << "1.Normal Room + Fan\t2500 Baht" << endl;
		cout << string(6, ' ') << "2.Special Room + Air\t4000 Baht" << endl;
		cout << endl;

		for (int i = totalRoom; i < totalRoom+unitRoom; i++){
		
			cout << "You can change number room (Y/N) ? : ";
			cin >> ch;
		
			if (ch == 'Y' || ch == 'y') {
				
				cout << "Enter number room : ";
				cin >> numberRoom;

				do {
					cout << string(10, ' ') << "Enter type room : ";
					cin >> dataRoom[i][1];
				} while(dataRoom[i][1] != 1 && dataRoom[i][1] != 2);
		
				if (dataRoom[i][1] == 1) {
					dataRoom[i][2] = 2500;
					cout << string(36, ' ') << "Normal room" << endl;
				} else if (dataRoom[i][1] == 2) {
					dataRoom[i][2] = 4000;
					cout << string(36, ' ') << "Premium room" << endl;
				}

				dataRoom[i][0] = numberRoom;
			
			} else if (ch == 'N' || ch == 'n') {

				total_UID_ROOM++;
				do {
					cout << string(10, ' ') << "Enter type room : ";
					cin >> dataRoom[i][1];
				} while(dataRoom[i][1] != 1 && dataRoom[i][1] != 2);
		
				if (dataRoom[i][1] == 1) {
					dataRoom[i][2] = 2500;
					cout << string(36, ' ') << "Normal room" << endl;
				} else if (dataRoom[i][1] == 2) {
					dataRoom[i][2] = 4000;
					cout << string(36, ' ') << "Premium room" << endl;
				}
				dataRoom[i][0] = total_UID_ROOM;
			}
		}	
        
        // fn:
		cout << "Insert data successfully,\n\t\t\t\tPlease enter to go back . . .";
		cin.get();
		cin.ignore();
		totalRoom += unitRoom;
		show_dataRoom();
	
	} else if (menu == 2) {

		system("cls");

		cout << endl << endl;
		cout << string(50,' ') << "INSERT BILL ROOM" << endl << endl;
		cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
		cout << string(10, ' ') << "ROOM NO." << string(6,' ') << "TYPE" << string(8, ' ')<< "PRICE" << string(6, ' ') << "STATUS" << endl;
		cout << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

		for (int i = 0; i < totalRoom; i++) {

			if (dataRoom[i][3] == 0) status = "- EMTPY";
			else status = "BUSY";
			if (dataRoom[i][1] == 1) type = "Room + Fan";
			else type = "Room + Air";

			cout << string(12,' ') << dataRoom[i][0] << string(6,' ') << type << string(6,' ') << dataRoom[i][2] << string(6, ' ') << left << setw(8) << setfill(' ') << status << endl;
		
		}
		
		cout << endl << "Enter number room of insert bills : ";	
		cin >> ID_Room;
	
		cout << endl << "You have insert water(1) or electric(2) and All(3): ";
		cin >> choiceBill;
		
		for (int i = 0; i < totalRoom; i++) {

			if (ID_Room == dataRoom[i][0]) {
				index = i;
			}
			
		}

		if (choiceBill == 1) {
			cout << "Insert price of water : ";
			cin >> dataRoom[index][5];
		}
		else if (choiceBill == 2) {
			cout << "Insert price of electric : ";
			cin >> dataRoom[index][6];
		}
		else if (choiceBill == 3) {
			cout << "Insert price of water : ";
			cin >> dataRoom[index][5];
			cout << "Insert price of electric : ";
			cin >> dataRoom[index][6];
		}
	} else if (menu == 3) {
		stay_payments();
	}
	
	if (menu != 4) {
		cout << "Insert price successfully,\n\t\t\t\tPlease enter to go back . . .";
		cin.get();
		cin.ignore();
		totalRoom += unitRoom;
		show_dataRoom();
	} else {
		show_dataRoom();
	}

}

							//		SEARCH DATA ROOM
void search_dataRoom(){
	system("cls");
	// variable set
	string status; // show status
	string type;
	float ID_Room; // search data
	bool check = false;	   // status search

	cout << endl << endl << endl;

	cout << "ENTER ID Room For Search : ";
	cin >> ID_Room;
	cout << endl << endl;

	cout << string(50,' ') << "SEARCH DATA ROOM" << endl << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
	cout << string(10, ' ') << "ROOM NO." << string(6,' ') << "TYPE" << string(8, ' ')<< "PRICE" << string(6, ' ') << "STATUS" << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalRoom; i++){
		
		if (dataRoom[i][3] == 0) status = "- EMTPY";
		else status = "BUSY";
		if (dataRoom[i][1] == 1) type = "Room + Fan";
		else type = "Room + Air";
		if (ID_Room == dataRoom[i][0]) {
			cout << string(12,' ') << dataRoom[i][0] << string(6,' ') << type << string(6,' ') << dataRoom[i][2] << string(6, ' ') << left << setw(8) << setfill(' ') << status << endl;
			check = true;
		}
	}

	
	if (check == false) cout << string(50, ' ') << "Data not found." << endl;
	cout << endl << string(5,' ') << setw(100) << setfill('-') << "" << endl << endl;

	cout << "Please enter to go back . . .";
	cin.get();
	cin.ignore();
	show_dataRoom();

}

							//		DELETE DATA ROOM
void delete_dataRoom(){
	system("cls");

	// variable set
	float ID_Room; // ID check for delete
	string status;
	string type;
	
	cout << endl << endl << endl;

	cout << string(50,' ') << "DELETE DATA ROOM" << endl << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
	cout << string(10, ' ') << "ROOM NO." << string(6,' ') << "TYPE" << string(8, ' ')<< "PRICE" << string(6, ' ') << "STATUS" << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalRoom; i++){
		if (dataRoom[i][3] == 0) status = "EMTPY";
		else status = "BUSY";
		if (dataRoom[i][1] == 1) type = "Room + Fan";
		else type = "Room + Air";
		cout << string(12,' ') << dataRoom[i][0] << string(6,' ') << type << string(6,' ') << dataRoom[i][2] << string(6, ' ') << left << setw(8) << setfill(' ') << status << endl;
	}
	
	cout << endl << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

	cout << string(35, ' ') << "Enter ID to delete :  ";
	cin >> ID_Room;

	for (int i = 0; i < totalRoom; i++){

		if (ID_Room == dataRoom[i][0]) {
			dataRoom[i][0] = 0;
			dataRoom[i][1] = 0;
			dataRoom[i][2] = 0;
			dataRoom[i][3] = 0;
			dataRoom[i][4] = 0;
			dataRoom[i][5] = 0;
			dataRoom[i][6] = 0;
			totalRoom--;
		}

        if (dataRoom[i][0] == 0) {
			dataRoom[i][0] = dataRoom[i+1][0];
			dataRoom[i][1] = dataRoom[i+1][1];
			dataRoom[i][2] = dataRoom[i+1][2];
			dataRoom[i][3] = dataRoom[i+1][3];
			dataRoom[i][4] = dataRoom[i+1][4];
			dataRoom[i][5] = dataRoom[i+1][5];
			dataRoom[i][6] = dataRoom[i+1][6];
			dataRoom[i+1][0] = 0;
			dataRoom[i+1][1] = 0;
			dataRoom[i+1][2] = 0;
			dataRoom[i+1][3] = 0;
			dataRoom[i+1][4] = 0;
			dataRoom[i+1][5] = 0;
			dataRoom[i+1][6] = 0;
		}
	}

	show_dataRoom();
}

//	------------------------------------------------------------------------------------------------------  //

							//		MAIN SHOW DATA STAY
void show_stay() {
	system("cls");

	// variable set
	int choice; // select menu

	string status;
	string type;
	
	cout << endl << endl << endl;

	cout << string(50,' ') << "DATA STAY" << endl << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
	cout << string(10, ' ') << "ROOM NO." << string(6,' ') << "TYPE" << string(8, ' ') << "PRICE" << string(6, ' ') << "PLEDGE" << string(6, ' ') << "STATUS"  << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalRoom; i++){
		if (dataRoom[i][3] == 0) status = "EMTPY";
		else status = "BUSY";
		if (dataRoom[i][1] == 1) type = "Room + Fan";
		else type = "Room + Air";
		if (dataRoom[i][3] == 1) {
			cout << string(12,' ') << dataRoom[i][0] 
				<< string(6,' ') << type 
				<< string(6,' ') << dataRoom[i][2]
				<< string(6,' ') << dataRoom[i][4]
				<< string(6, ' ') << left << setw(8) << setfill(' ') << status << endl;
		}
	}
	
	cout << endl << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

	cout << endl;
	cout << string(42, ' ') << "Menu : " << endl;
	cout << string(50, ' ') << "1. Stay room" << endl;
	cout << string(50, ' ') << "2. Payment price room" << endl;
	cout << string(50, ' ') << "2. Back" << endl;
	reInput:
	cout << string(26, ' ') << "Enter number of menu :  ";
	cin >> choice;

	switch (choice) {
		case 1 :
			stay_room();
			break;
		case 2 :
			stay_paymentPriceRoom();
			break;
		case 3 :
			main();
			break;
		default :
			if (choice > 3) {
				goto reInput;
				cout << "Not found number of menu input again" << endl;
			}
	}
}

							//		INSERT DATA STAY
void stay_room(){
	system("cls");

	float ID_Room;
	string ID_STD;
	string status;
	string type;
	int index_room, index_uid;
	float pledge;
	bool check_STD = false, check_Room = false;

	cout << endl << endl << endl;

	cout << string(50,' ') << "STAY" << endl << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
	cout << string(10, ' ') << "ROOM NO." << string(6,' ') << "TYPE" << string(8, ' ') << "PRICE" << string(8, ' ') << "STATUS"  << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalRoom; i++){
		if (dataRoom[i][3] == 0) status = "EMTPY";
		else status = "BUSY";
		if (dataRoom[i][1] == 1) type = "Room + Fan";
		else type = "Room + Air";
		if (dataRoom[i][3] == 0)
			cout << string(12,' ') << dataRoom[i][0] 
			<< string(6,' ') << type
			<< string(6, ' ') << left << setw(8) << setfill(' ') << dataRoom[i][2]
			<< string(6, ' ') << left << setw(8) << setfill(' ') << status << endl;
	}

	cout << endl << endl;
	cout << "\tInput [ NO. ROOM ] is want to stay : ";
	cin >> ID_Room;
	cout << "\tInput [ ID STD ] is want to stay : ";
	cin >> ID_STD;

	do {
		cout << "\tPay pledge minimum = 300 bath : ";
		cin >> pledge;

	} while(pledge < 300);

	for (int i = 0; i < totalRoom; i++) {
		if (dataRoom[i][3] == 0) {
			if (ID_Room ==  dataRoom[i][0]) {
				dataRoom[i][2] -= pledge;
				index_room = i;
				check_Room = true;
			}
		}
	}

	for (int i = 0; i < totalPerson; i++) {
		if (ID_STD == dataPerson[i][0]) {
			index_uid = i;
			check_STD = true;
		}
	}
	
	system("cls");

// STAY REPORT
	cout << "ID Student : " << ID_STD << "\nStay room :" << ID_Room << endl;
	cout << endl;

	if (check_STD && check_Room) {

		// Relationship data put to array new

		string UID_Room, ID;
		// ID put
		stringstream string_ID;
		string_ID << dataRoom[index_room][0];
		ID = string_ID.str();
		UID_Room = ID;
	
		for (int i = totalRelation; i < totalRelation+1; i++) {
			dataRelation[i][0] = UID_Room;
			dataRelation[i][1] = dataPerson[index_uid][0];
		}
		
		totalRelation++;

		cout << string(50,' ') << "STAY REPORT" << endl << endl;
		cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
		cout << string(10, ' ') << "ROOM NO." << string(6,' ') << "TYPE" << string(8, ' ') << "ID STUDENT" << string(8, ' ') << "FULLNAME" << string(6, ' ') << "PLEDGE" << endl;
		
		if (dataRoom[index_uid][1] == 1) type = "Room + Fan";
		else type = "Room + Air";
		
		dataRoom[index_room][3] = 1;
		dataRoom[index_room][4] = pledge;

		cout << string(12,' ') << dataRoom[index_room][0];
		cout << string(4,' ') << type;
		cout << string(4,' ') << dataPerson[index_uid][1];
		cout << string(4,' ') << dataPerson[index_uid][2];
		cout << string(4,' ') << dataRoom[index_room][4] << endl;

		cout << endl << "Stay Successfully,\n\t\t\t\tPlease enter to go back . . .";
	} else {
		if (check_STD == false)  cout << "Not found -> ID Student." << endl;
		if (check_Room == false)	 cout << "Not found -> Room." << endl;
		cout << endl << "Stay Fail,\n\t\t\t\tPlease enter to go back . . ." << endl;
	}
	cin.get();
	cin.ignore();
	totalRoom += unitRoom;
	show_stay();
}

							//		INSERT PAYMENTS STAY
void stay_payments() {
	system("cls");

	int menu;
	string type;
	
	cout << endl << endl << endl;

	cout << string(50,' ') << "STATUS PAYMENT" << endl << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
	cout << string(10, ' ') << "ROOM NO." << string(6,' ') << "TYPE" << string(8, ' ') << "WATER" << string(6, ' ') << "ELECTRIC"  << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalRoom; i++){
		if (dataRoom[i][1] == 1) type = "Room + Fan";
		else type = "Room + Air";
		if (dataRoom[i][3] == 1) {
			cout << string(12,' ') << dataRoom[i][0] 
				<< string(6,' ') << type
				<< string(6, ' ') << right << setw(8) << setfill(' ') << dataRoom[i][5]
				<< string(6, ' ') << right << setw(8) << setfill(' ') << dataRoom[i][6] << endl;
		}
	}

	cout << endl;
	cout << string(42, ' ') << "Menu : " << endl;
	cout << string(50, ' ') << "1. Bill Water" << endl;
	cout << string(50, ' ') << "2. Bill Electric" << endl;
	cout << string(50, ' ') << "3. Back" << endl;
	reInput:
	cout << string(26, ' ') << "Enter menu :  ";
	cin >> menu;

	switch (menu) {
		case 1 :
			stay_pay_water();
			break;
		case 2 :
			stay_pay_electric();
			break;
		case 3 :
			show_dataRoom();
			break;
		default :
			if (menu > 3) {
				goto reInput;
				cout << "Not found number of menu input again" << endl;
			}
	}
}

							//		STAY PAY PRICE ROOM

void stay_paymentPriceRoom() {
	float ID_Room;
	string type;
	float money = 0;
	
	cout << endl;
	cout << "Enter number room to pay : ";
	cin >> ID_Room;

	system("cls");

	cout << string(50,' ') << "PAY PRICE ROOM" << endl << endl;

	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
	cout << string(10, ' ') << "ROOM NO." << string(8, ' ') << "PRICE ROOM" << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalRoom; i++){
		if (dataRoom[i][1] == 1) type = "Room + Fan";
		else type = "Room + Air";
		if (ID_Room == dataRoom[i][0]) {
			cout << string(12,' ') << dataRoom[i][0] 
				<< string(6, ' ') << right << setw(8) << setfill(' ') << dataRoom[i][2] << endl;
			cout << "Price of room is " << dataRoom[i][2] << endl;
			
			do {
				cout << "Enter money to pay : ";
				cin >> money;
			} while (money > dataRoom[i][2]);
			dataRoom[i][2] -= money;		
			if (dataRoom[i][2] > 0) {
				cout << "Pay successfully balance = " << dataRoom[i][2] << endl;
				cout << endl << "Please enter to back . . ." << endl;
			} else {
				cout << "Pay successfully";
			}
		}
	}

	cin.get();
	cin.ignore();
	stay_payments();
}
							//		STAY PAY WATER
void stay_pay_water() {

	float ID_Room;
	string type;
	float money = 0;
	
	cout << endl;
	cout << "Enter number room to pay : ";
	cin >> ID_Room;

	system("cls");

	cout << string(50,' ') << "PAY WATER" << endl << endl;

	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
	cout << string(10, ' ') << "ROOM NO." << string(8, ' ') << "WATER" << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalRoom; i++){
		if (dataRoom[i][1] == 1) type = "Room + Fan";
		else type = "Room + Air";
		if (ID_Room == dataRoom[i][0]) {
			cout << string(12,' ') << dataRoom[i][0] 
				<< string(6, ' ') << right << setw(8) << setfill(' ') << dataRoom[i][5] << endl;
			cout << "Price of water is " << dataRoom[i][5] << endl;
			
			do {
				cout << "Enter money to pay : ";
				cin >> money;
			} while (money > dataRoom[i][5]);
			dataRoom[i][5] -= money;		
			if (dataRoom[i][5] > 0) {
				cout << "Pay successfully balance = " << dataRoom[i][5] << endl;
				cout << endl << "Please enter to back . . ." << endl;
			} else {
				cout << "Pay successfully";
			}
		}
	}

	cin.get();
	cin.ignore();
	stay_payments();
}

							//		STAY PAY ELECTRIC
void stay_pay_electric(){

	float ID_Room;
	string type;
	float money = 0;
	
	cout << endl;
	cout << "Enter number room to pay : ";
	cin >> ID_Room;

	system("cls");

	cout << string(50,' ') << "PAY ELECTRIC" << endl << endl;

	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
	cout << string(10, ' ') << "ROOM NO." << string(8, ' ') << "WATER" << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalRoom; i++){
		if (dataRoom[i][1] == 1) type = "Room + Fan";
		else type = "Room + Air";
		if (ID_Room == dataRoom[i][0]) {
			cout << string(12,' ') << dataRoom[i][0] 
				<< string(6, ' ') << right << setw(8) << setfill(' ') << dataRoom[i][6
				] << endl;
			cout << "Price of water is " << dataRoom[i][6] << endl;
			 
			do {
				cout << "Enter money to pay : ";
				cin >> money;
			} while (money > dataRoom[i][6]);
			dataRoom[i][6] -= money;		
			if (dataRoom[i][6] > 0) {
				cout << "Pay successfully balance = " << dataRoom[i][6] << endl;
				cout << endl << "Please enter to back . . ." << endl;
			} else {
				cout << "Pay successfully";
			}
		}
	}

	cin.get();
	cin.ignore();
	stay_payments();
}

//	------------------------------------------------------------------------------------------------------  //

							//		MAIN RETURN ROOM
void returnRoomMain() {

	system("cls");

	int menu;
	bool status = false;
	string type;

	cout << endl << endl;
	cout << string(50,' ') << "DATA ROOM" << endl << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
	cout << string(10, ' ') << "ROOM NO." 
		 << string(6,' ') << "TYPE"
		 << string(6, ' ') << "WATER"
		 << string(6, ' ') << "ELECTRIC" << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalRoom; i++){
		if (dataRoom[i][3] == 0) status = "EMTPY";
		else status = "BUSY";
		if (dataRoom[i][1] == 1) type = "Room + Fan";
		else type = "Room + Air";
		if (dataRoom[i][3] == 1) {
			cout << string(12,' ') << dataRoom[i][0] 
				 << string(6,' ') << type 
				 << string(6, ' ') << left << setw(8) << setfill(' ') << dataRoom[i][5]
				 << string(6, ' ') << left << setw(8) << setfill(' ') << dataRoom[i][6] << endl;
			status = true;
		}
	}

	if (status == false) {
		cout << string(32,' ') << "Data not found!" << endl;
	}

	cout << endl << string(5,' ') << setw(55) << setfill('-') << "" << endl;
	
	cout << endl;
	cout << string(50, ' ') << "MENU" << endl;
	cout << string(55, ' ') << "1. RETURN ROOM" << endl;
	cout << string(55, ' ') << "2. BACK" << endl;
	do {
		cout << endl << string(50, ' ') << "Select : ";
		cin >> menu;
	} while (menu > 2);

	cout << endl;
	
	switch(menu) {
		case 1 :
			returnRoom();
		case 2 :
			main();
	}
}

							//		RETURN ROOM MENU 1
void returnRoom() {

	float ID_Room;
	string idRoom;
	string status;
	string type;
	string str_idRoom;
	int index_relation, index_room, index_person;
	char sure;
	string rela_id_room, rela_id_std;
	bool check = false, check2 = false, checkReturn = false;

	reInput:
	cout << endl << "\tInput [ NO. ROOM ] is level to stay : ";
	cin >> ID_Room;

	for (int i = 0; i < totalRoom; i++) {
		
		if (ID_Room == dataRoom[i][0]) {
			index_room = i;
			check = true;
		}
	}

	if (check) {
		// numberic-real to string
		stringstream ss_idRoom;
		ss_idRoom << dataRoom[index_room][0];
		idRoom = ss_idRoom.str();
		
		for (int i = 0; i < totalRelation; i++) {
			if (idRoom == dataRelation[i][0]) {
				index_relation = i;
				cout << index_relation;
				check2 = true;
			} 
		}
		// string to numberic - real
		str_idRoom = idRoom;
		float num_idRoom = stof(str_idRoom);

		if (check2) {
			system("cls");

			for (int i = 0; i < totalRoom; i++) {
				if (num_idRoom == dataRoom[i][0]) {
					index_room = i;
				}
			}

			for (int i = 0; i < totalPerson; i++) {
				if (dataRelation[index_relation][1] == dataPerson[i][0]) {
					index_person = i;
				}
			}

			cout << string(50,' ') << "STAY REPORT" << endl << endl;
			cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
			cout << string(10, ' ') << "ROOM NO." << string(8, ' ') << "ID STUDENT" << string(8, ' ') << "FULLNAME" << string(6, ' ') << endl;
			cout << string(5, ' ') << dataRoom[index_room][0]
				 << string(5, ' ') << dataPerson[index_person][0]
				 << string(5, ' ') << dataPerson[index_person][1] << endl;
			
			reSure:
			cout << "You sure return room (Y/N) : ";
			cin >> sure;
			bool stt_price_room = true;

			if (sure == 'Y' || sure == 'y') {
				
				if (dataRoom[index_room][5] != 0 && dataRoom[index_room][6] != 0) {
					cout << "You not yet pay water and electric room";
					checkReturn = true;
				}
				if (dataRoom[index_room][7] != 0) {
					cout << "You not yet pay price room";
					checkReturn = true;						
				}

				if (checkReturn == false) {
					for (int i = 0; i < totalRoom; i++) {		
						for (int i = 0; i < totalRelation; i++) {
							if (dataRelation[i][0] == idRoom) {
								dataRelation[i][0] = "";
								dataRelation[i][1] = "";
								if (dataRelation[i][0] == "") {
									dataRelation[i][0] == dataRelation[i+1][1];
									dataRelation[i][1] == dataRelation[i+1][1];
									dataRelation[i+1][0] == "";
									dataRelation[i+1][1] == "";
									dataRoom[index_room][3] = 0;		
									cout << "Return room success,   Please enter to back. . .";		
									break;
								}
							}
						}
				
					}
				}
			
			} else if (sure == 'N' || sure == 'n') {
				returnRoomMain();	
			} else {
				cout << "Input ( 'Y' or 'N' ) only!!" << endl;
				goto reSure;
			}
				
		} else {
			cout << "Not found number room!,  try agian";
			goto reInput;
		}
	}
	cin.get();
	cin.ignore();
	returnRoomMain();	
}

//	------------------------------------------------------------------------------------------------------  //

							//		MAIN REPORT
void report() {
	system("cls");

	// variable set
	int choice; // select menu
	string status; // show status
	string type; // type room
	string idRoom;
	int index_relation;

	cout << endl << endl;
	cout << string(50,' ') << "REPORT ROOM" << endl << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
	cout << string(10, ' ') << "ROOM NO." << string(6,' ') << "TYPE" << string(8, ' ')<< "PRICE"
		 << string(6, ' ') << "STATUS"
		 << string(6, ' ') << "WATER" 
		 << string(6, ' ') << "ELECTRIC" << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalRoom; i++){
		if (dataRoom[i][3] == 0) status = "EMTPY";
		else status = "BUSY";
		if (dataRoom[i][1] == 1) type = "Room + Fan";
		else type = "Room + Air";

		// numberic-real to string
		cout << string(12,' ') << dataRoom[i][0] 
			 << string(6,' ') << type
			 << string(6,' ') << dataRoom[i][2] 
			 << string(6, ' ') << left << setw(8) << setfill(' ') << dataRoom[i][5]
			 << string(6, ' ') << left << setw(8) << setfill(' ') << dataRoom[i][6]
			 << string(6, ' ') << left << setw(8) << setfill(' ') << status << endl;
	}
	
	cout << endl << string(5,' ') << setw(100) << setfill('-') << "" << endl;
	
	cout << endl;
	cout << string(50, ' ') << "MENU" << endl;
	cout << string(55, ' ') << "1. BUSY" << endl;
	cout << string(55, ' ') << "2. EMPTY" << endl;
	cout << string(55, ' ') << "3. NOT YET PAY WATER" << endl;
	cout << string(55, ' ') << "4. NOT YET PAY ELECTRIC" << endl;
	cout << string(55, ' ') << "5. NOT YET PAY PRICE ROOM" << endl;
	cout << string(55, ' ') << "6. BACK" << endl;
	reInput:
	cout << endl << string(50, ' ') << "Select : ";
	cin >> choice;

	switch (choice) {
		case 1 :
			reportRoomBusy();
			break;
		case 2 :
			reportRoomEmpty();
			break;
		case 3 :
			reportRoomNotYetPayWater();
			break;
		case 4 :
			reportRoomNotYetPayElectric();
			break;
		case 5 :
			reportRoomNotYetPriceRoom();
			break;
		case 6 :
			main();
			break;
		default :
			if (choice > 6) {
				goto reInput;
				cout << "Not found number of menu input again" << endl;
			}
	}
}

							//		REPORT ROOM BUSY
void reportRoomBusy() {
	system("cls");

	string status; // show status
	string type; // type room
	string idRoom;
	int index_relation;

	cout << endl << endl;
	cout << string(50,' ') << "BUSY ROOM" << endl << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
	cout << string(10, ' ') << "ROOM NO." << string(6,' ') << "TYPE" << string(8, ' ')<< "PRICE"
		 << string(6, ' ') << "STATUS"
		 << string(6, ' ') << "WATER" 
		 << string(6, ' ') << "ELECTRIC" << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalRoom; i++){
		if (dataRoom[i][3] == 0) status = "EMTPY";
		else status = "BUSY";
		if (dataRoom[i][1] == 1) type = "Room + Fan";
		else type = "Room + Air";

		if (dataRoom[i][3] == 1) {
			// numberic-real to string
			stringstream ss_idRoom;
			ss_idRoom << dataRoom[i][0];
			idRoom = ss_idRoom.str();
			cout << endl;
			cout << string(12,' ') << dataRoom[i][0] 
				 << string(6,' ') << type
				 << string(6,' ') << dataRoom[i][2] 
				 << string(6, ' ') << left << setw(8) << setfill(' ') << dataRoom[i][5]
				 << string(6, ' ') << left << setw(8) << setfill(' ') << dataRoom[i][6]
				 << string(6, ' ') << left << setw(8) << setfill(' ') << status << endl;
		
			for (int n = 0; n < totalRelation; n++) {
				if (dataRelation[n][0] == idRoom) {
					index_relation = n;
					cout << string(20, ' ') << "   " << dataRelation[n][1] << endl << endl;		
				}
			}
		} 
	}
	
	cout << endl << string(5,' ') << setw(100) << setfill('-') << "" << endl;
	cout << "Please enter to back . . .";
	cin.get();
	cin.ignore();
	report();	
}

							//		REPORT ROOM EMPTY
void reportRoomEmpty(){
	system("cls");

	string status; // show status
	string type; // type room
	string idRoom;

	cout << endl << endl;
	cout << string(50,' ') << "EMTRY ROOM" << endl << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
	cout << string(10, ' ') << "ROOM NO." << string(6,' ') << "TYPE" << string(8, ' ')<< "PRICE"
		 << string(6, ' ') << "STATUS"
		 << string(6, ' ') << "WATER" 
		 << string(6, ' ') << "ELECTRIC" << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalRoom; i++){
		if (dataRoom[i][3] == 0) status = "EMTPY";
		else status = "BUSY";
		if (dataRoom[i][1] == 1) type = "Room + Fan";
		else type = "Room + Air";

		if (dataRoom[i][3] == 0) {
			// numberic-real to string
			stringstream ss_idRoom;
			ss_idRoom << dataRoom[i][0];
			idRoom = ss_idRoom.str();
			cout << string(12,' ') << dataRoom[i][0] 
				 << string(6,' ') << type
				 << string(6,' ') << dataRoom[i][2] 
				 << string(6, ' ') << left << setw(8) << setfill(' ') << dataRoom[i][5]
				 << string(6, ' ') << left << setw(8) << setfill(' ') << dataRoom[i][6]
				 << string(6, ' ') << left << setw(8) << setfill(' ') << status << endl;
		} 
	}
	
	cout << endl << string(5,' ') << setw(100) << setfill('-') << "" << endl;
	cout << "Please enter to back . . .";
	cin.get();
	cin.ignore();
	report();
}

							//		REPORT ROOM NOT YET WATER
void reportRoomNotYetPayWater(){
	system("cls");

	string status; // show status
	string type; // type room
	string idRoom;

	cout << endl << endl;
	cout << string(50,' ') << "EMTRY ROOM" << endl << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
	cout << string(10, ' ') << "ROOM NO." << string(6,' ') << "TYPE" << string(8, ' ')<< "PRICE"
		 << string(6, ' ') << "STATUS"
		 << string(6, ' ') << "WATER" << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalRoom; i++){
		if (dataRoom[i][3] == 0) status = "EMTPY";
		else status = "BUSY";
		if (dataRoom[i][1] == 1) type = "Room + Fan";
		else type = "Room + Air";

		if (dataRoom[i][5] == 0) {
			// numberic-real to string
			stringstream ss_idRoom;
			ss_idRoom << dataRoom[i][0];
			idRoom = ss_idRoom.str();
			cout << string(12,' ') << dataRoom[i][0]
				 << string(6,' ') << type
				 << string(6,' ') << dataRoom[i][2] 
				 << string(6, ' ') << left << setw(8) << setfill(' ') << dataRoom[i][5]
				 << string(6, ' ') << left << setw(8) << setfill(' ') << status << endl;
		}
	}
	
	cout << endl << string(5,' ') << setw(100) << setfill('-') << "" << endl;
	cout << "Please enter to back . . .";
	cin.get();
	cin.ignore();
	report();
}

							//		REPORT ROOM NOT YET ELECTRIC
void reportRoomNotYetPayElectric(){
	system("cls");

	string status; // show status
	string type; // type room
	string idRoom;

	cout << endl << endl;
	cout << string(50,' ') << "EMTRY ROOM" << endl << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
	cout << string(10, ' ') << "ROOM NO." << string(6,' ') << "TYPE" << string(8, ' ')<< "PRICE"
		 << string(6, ' ') << "STATUS"
		 << string(6, ' ') << "ELECTRIC" << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalRoom; i++){
		if (dataRoom[i][3] == 0) status = "EMTPY";
		else status = "BUSY";
		if (dataRoom[i][1] == 1) type = "Room + Fan";
		else type = "Room + Air";

		if (dataRoom[i][5] == 0) {
			// numberic-real to string
			stringstream ss_idRoom;
			ss_idRoom << dataRoom[i][0];
			idRoom = ss_idRoom.str();
			cout << string(12,' ') << dataRoom[i][0]
				 << string(6,' ') << type
				 << string(6,' ') << dataRoom[i][2] 
				 << string(6, ' ') << left << setw(8) << setfill(' ') << dataRoom[i][6]
				 << string(6, ' ') << left << setw(8) << setfill(' ') << status << endl;
		}
	}
	
	cout << endl << string(5,' ') << setw(100) << setfill('-') << "" << endl;
	cout << "Please enter to back . . .";
	cin.get();
	cin.ignore();
	report();
}

							//		REPORT ROOM NOT YET PRICE
void reportRoomNotYetPriceRoom(){
	system("cls");

	string status; // show status
	string type; // type room
	string idRoom;
	int index_relation;

	cout << endl << endl;
	cout << string(50,' ') << "BUSY ROOM" << endl << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl;
	cout << string(10, ' ') << "ROOM NO." << string(6,' ') << "TYPE" << string(8, ' ')<< "PRICE"
		 << string(6, ' ') << "STATUS"
		 << string(6, ' ') << "WATER" 
		 << string(6, ' ') << "ELECTRIC" << endl;
	cout << string(5,' ') << setw(55) << setfill('-') << "" << endl << endl;

	for (int i = 0; i < totalRoom; i++){
		if (dataRoom[i][3] == 0) status = "EMTPY";
		else status = "BUSY";
		if (dataRoom[i][1] == 1) type = "Room + Fan";
		else type = "Room + Air";

		if (dataRoom[i][2] != 0) {
			// numberic-real to string
			stringstream ss_idRoom;
			ss_idRoom << dataRoom[i][0];
			idRoom = ss_idRoom.str();
			cout << endl;
			cout << string(12,' ') << dataRoom[i][0] 
				 << string(6,' ') << type
				 << string(6,' ') << dataRoom[i][2] 
				 << string(6, ' ') << left << setw(8) << setfill(' ') << dataRoom[i][5]
				 << string(6, ' ') << left << setw(8) << setfill(' ') << dataRoom[i][6]
				 << string(6, ' ') << left << setw(8) << setfill(' ') << status << endl;
			for (int n = 0; n < totalRelation; n++) {
				if (dataRelation[n][0] == idRoom) {
					index_relation = n;
					cout << string(20, ' ') << "   " << dataRelation[n][1] << endl << endl;		
				}
			}
		} 
	}
	
	cout << endl << string(5,' ') << setw(100) << setfill('-') << "" << endl;
	cout << "Please enter to back . . .";
	cin.get();
	cin.ignore();
	report();	
}
