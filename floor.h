#ifndef FLOOR_H
#define FLOOR_H
#ifndef ENTRANCEAREA_H
#include "entrancearea.h"
#endif
#ifndef OFFICE_H
#include "office.h"
#endif
#include <iostream>
#include <assert.h>
using namespace std;

class Floor{
	private:
		int Nf; //visitors'capacity per floor 
		int floor_number; //number of floor
		int no_visitors; //current number of visitors at the floor
		EntranceArea* area;
		Office* offices[10];
		Queue queueInOffices;
	public:
		
		//constructor of floor 
		//to construct/create the floor needs the capacity(Nf)
		//and the floor_number 
		//initializes: Nf, no_visitors, floor_number
		Floor(int Nf, int floor_number){ 
			this->Nf = Nf; 
			this->floor_number = floor_number;
			no_visitors = 0; //is empty of visitors 
			cout << "A floor has been created with number: " << floor_number << endl;
		}

		int GetFloorNumber(){
			return floor_number;
		}

		void CreateFArea(EntranceArea* area){
			this->area = area;
		}
		
		EntranceArea* GetFArea(){
			return area;
		}

		void CreateOffices(int No){
			for(int i=0; i<=9; i++){
				Office* office = new Office(No, i+1);
				offices[i] = office;
			}
		}
		
		//check if the visitor can join the entrance area
		int EnterEa(){
			if(area->Enter() == 1){
				return 1;
			}else{
				return 0;
			}
		}
		
		//check if the visitor can join the floor
		//Increase the number of visitors the current time
		int Enter(){
			if(no_visitors < Nf){ //Visitor can join the floor
				IncreaseVisitors();
				cout << "Entering floor number: " << floor_number << endl;
				return 1;
			}
			cout << "Sorry, floor number " << floor_number << "is full" << endl;
			return 0;
		}
		
		//check if the visitor can join the office
		//Increase the number of visitors the current time
		int EnterOffice(int off){
			if(offices[off-1]->Enter() == 1){
				cout << "Visitor can join the office " << off << endl;
				offices[off-1]->IncreaseVisitors();
				return 1;
			}
			return 0;
		}

		void ReduceVisitorsOffice(int off){
			offices[off-1]->ReduceVisitors();
		}

		void ReduceVisitors(){
			no_visitors--;
		} 

		void PutInOffices(Visitor* vis){
			queueInOffices.insert(vis);
		}
		
		void PutInEA(Visitor* vis){
			area->PutInEA(vis);
		}

		Queue& ReturnQueue(){
			return queueInOffices;
		}

		//Increase the number of visitors the current time
		void IncreaseVisitors(){ 
			no_visitors++;
		}

		void IncreaseEA(){
			area->IncreaseVisitors();
		}

		void ReduceEA(){
			area->ReduceVisitors();
		}
		
		//Destructor of floor
		~Floor(){ 
			cout << "End of service!" << endl;
		}

};

#endif