#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


class dictionary{
	public:
		void insert(){
			string word,definition;
			ofstream myfile;
			myfile.open("DicData.txt",ios::app);
			cout << "kalame mored nazar ra vared konid(english word)\n";
			cin >> word;
			cout << "manaye kalame ra vared konid(persian word)\n";
			cin >> definition;
			myfile << word + "\n" + definition+ "\n";
			myfile.close();
			cout <<" amaliat ba movafaqiat anjam shod \n";
		}
		void mydelete(){
			string line;
			string eraseLine;
			ifstream fin;
			fin.open("DicData.txt");
			ofstream temp;
			temp.open("temp.txt");
			cout << "kalame mored nazar ra vared konid(english word)\n";
			cin >> eraseLine;
			while (getline(fin, line)) {
    			if (line != eraseLine){
       				temp << line << endl;
       			}
       			else{
       				getline(fin, line);	
				}
			}
			temp.close();
			fin.close();
			const char * p = "DicData.txt";
			remove(p);
			rename("temp.txt", p);
			cout <<" amaliat ba movafaqiat anjam shod \n";
		}
		void search(){
			string line;
			string findingword;
			ifstream fin;
			fin.open("DicData.txt");
			cout << "kalame mored nazar ra vared konid(english word)\n";
			cin >> findingword;
			while (getline(fin, line)) {
    			if (line == findingword){
       				getline(fin, line);
       				cout << "manaye kalame mored nazar shoma : " << line <<endl;
       			}
			}
			fin.close();
		}
};

int main(int argc, char** argv) {
	dictionary dic;
	char choice;
	while(1){
		cout << "yeki az gozine haye zir ra entekhab konid ( lotfan tanha addad gozine ra vared konid) \n";
		cout << "1-ezafe kardan kalame" << endl;
		cout << "2-hazf kardan kalame" << endl;
		cout << "3-peida kardan kalame" << endl;
		cout << "4-khoroj" << endl;
		cin >> choice;
		switch(choice){
			case '1':
				dic.insert();
				break;
			case '2':
				dic.mydelete();
				break;
			case '3':
				dic.search();
				break;
			case '4':
				return 0;
			default: 
				break;
		}
	}
	return 0;
}
