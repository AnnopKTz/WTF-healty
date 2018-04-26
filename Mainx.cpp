#include "FuncFindx.h"

using namespace std;

int main(){
	bool check,check2 = true,check3,checkname;
	int day=0;
	string name;
	int age,date,count=0;
	float hight,weight,bmi,bmr,tdee,focus;
	char gender;
	double cal_eat;
	char command;
	FindAll A(name,age,hight,weight,gender);
	do{
		cout << "You ever use this programs Y/N : ";
		cin >> command;
		command = toupper(command);
		if(command == 'N'){
			fstream namelist("namelist.txt",ios::app);
			cout<<"Enter name : ";
			cin.ignore();
			getline(cin,A.name);
			string name = A.name;
			string text;
			for(int i=0;i<name.size();i++){
					(name[i]) = toupper(name[i]);
				};
			while(getline(namelist,text)){
					const char *textchar = text.c_str();
					char format[] = "%[^:]: %d %f %f %c %f %f %f %f %d";
					char namechar[100];
					sscanf(textchar,format,namechar,&A.age,&A.hight,&A.weight,&A.gender,&A.bmi,&A.bmr,&A.tdee,&A.focus,&A.remain_date);
					for(int i=0;i<100;i++){
						(namechar[i]) = toupper(namechar[i]);
					};
					
					if(namechar == name){ 
						checkname = false; 
						continue;
					} 
			}
			if(checkname){
				cout << "Hello " << A.name << " plase fill the information\n";
				cout << "Age : ";
				cin >> A.age;
				do{
					cout << "Gender M/F : ";
					cin >> A.gender;
					A.gender = toupper(A.gender);
					if(!(A.gender != 'M' or A.gender != 'F')) cout << "Invalid command. Please input gender again." << endl;
					else break;
				}while(true);
				cout << "Hight : ";
				cin >> A.hight;
				cout << "Weight : ";
				cin >> A.weight;
				cout << "BMI = " << A.BMI() << endl;
				cout << "BMR = " << A.BMR() << endl;
				cout << "TDEE = " << A.TDEE() <<endl;
				cout << "You must the enegy " << A.Diet() << "(Kcal) per day" << endl;
				break;
			}
			
		}else if(command == 'Y'){
			ifstream namelist("namelist.txt");
			ofstream copy("copy.txt");
			do{
				cout << "Enter name : ";
				cin.ignore();
				getline(cin,name);
				string names = name;
				string text;
				for(int i=0;i<name.size();i++){
						(name[i]) = toupper(name[i]);
					};
				
				cout << "Hello " << names << endl;
				while(getline(namelist,text)){
					const char *textchar = text.c_str();
					char format[] = "%[^:]: %d %f %f %c %f %f %f %f %d";
					char namechar[100];
					sscanf(textchar,format,namechar,&A.age,&A.hight,&A.weight,&A.gender,&A.bmi,&A.bmr,&A.tdee,&A.focus,&A.remain_date);
					A.name = namechar;
					for(int i=0;i<100;i++){
						(namechar[i]) = toupper(namechar[i]);
					};
					
					if(namechar == name){
						cout << "Age : " << A.age << endl;
						cout << "Gender : " << A.gender << endl;
						cout << "Hight : " << A.hight << endl;
						cout << "Weight : " << A.weight << endl;
						cout << "BMI = " << A.bmi <<endl;
						cout << "BMR = " << A.bmr << endl;
						cout << "TDEE = " << A.tdee << endl;
						check2 = false; count++;
					}else{
						check2 = true;
					}
					if(count == 0 or check2 == true) copy << textchar << endl;
					check3 = true;
				}
				if(count == 0) cout << "Cannot Found. Please input your name again." << endl;
				}while(count == 0);
				namelist.close();
				copy.close();
			}
			if(checkname == false) cout << "You have information in program." << endl;
			else if(count == 0) cout << "Invalid command. Please input Y or N." << endl;
		}while(count == 0 or check3 == false);
	
	
	do{
		char i;
		day++;
		A.CalFood();
		cout<<A.CalCal(day)<<endl;
		cout<<"\nYou want to fill cal next day Y/N : ";
		cin>>i;
		i=toupper(i);
		if(i=='Y'){
			check=true;
		}else if(i=='N'){
			check=false;
		}
	}while(check);
	remove("namelist.txt");
	ifstream copy("copy.txt");
	ofstream namelist("namelist.txt",ios::app);
	string text;
	while(getline(copy,text)){
		namelist << text << endl;
	}
	namelist << A.name << ": " << A.age << " " << A.hight << " " << A.weight << " " << A.gender << " " << A.bmi << " " << A.bmr << " " << A.tdee << " " << A.focus << " " << A.remain_date << endl;
	namelist.close();
	copy.close();
	remove("copy.txt");
	
	return 0;
}
