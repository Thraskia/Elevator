#ifndef OFFICE_H
#define OFFICE_H
#include <iostream>

using namespace std;

class Office{
	private:
		int No; //visitors'capacity per office
		int office_number; //number of office
		int no_visitors; //current number of visitors at the office

	public:
		
		//constructor of office 
		//to construct/create the office needs the capacity(No) 
		//and office_number
		//initializes: No, no_visitors, office_number
		Office(int No, int office_number){ 
			this->No = No; 
			this->office_number = office_number; 
			this->no_visitors = 0; //empty of visitors
			cout << "Office number: " << office_number << " has been created." << endl; 
		}

		int GetNoVisitors(){
			return this->no_visitors;
		}
		
		//check if the visitor can join the office
		//Increase the number of visitors the current time
		int Enter(){
			if(this->no_visitors < this->No){
				IncreaseVisitors();
				cout << "Entering office number: " << office_number << endl;
				return 1;
			}else{
				return 0;
			}
		}
		
		void IncreaseVisitors(){
			this->no_visitors++;
		}

		void ReduceVisitors(){
			this->no_visitors--;
		}

		//Destructor of office
		~Office(){ 
			cout << "End of the work!" << endl;
		}
};

#endif