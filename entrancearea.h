#ifndef ENTRANCEAREA_H
#define ENTRANCEAREA_H
#ifndef PG_H
#include "pg.h"
#endif
#ifndef VISITOR_H
#include "visitor.h"
#endif
#include <iostream>

using namespace std;

class EntranceArea{
	private:
		int no_visitors; //current number of visitors at the entrance area
		int Ne;
		Queue queueInEA;

	public:
		
		//constructor of entrance area 
		//to construct/create the area needs the capacity(Ne) 
		//initializes: Ne, no_visitors=0(is empty of visitors)
		EntranceArea(int Ne){ 
			cout << "The entrance has been created" << endl;		
			no_visitors = 0; //is empty of visitors
			this->Ne = Ne;
		}
		
		//check if the visitor can join the entrance area
		//Increase the number of visitors the current time
		int Enter(){
			if(no_visitors < Ne ){
				IncreaseVisitors();
				return 1;
			}else{
				return 0;
			}
		}

		int GetNoVisitors(){
			return no_visitors;
		}
		
		void PutInEA(Visitor* vis){
			queueInEA.insert(vis);
		}

		Queue GetQueue(){
			return queueInEA;
		}
		
		void ReduceVisitors(){
			no_visitors--;
		}

		//Increase the number of visitors the current time
		void IncreaseVisitors(){ 
			no_visitors++;
			cout << "Waiting for the lift and my priority number is: " << no_visitors << endl;
		}
		
		//Destructor of entrance area
		~EntranceArea(){ 
			cout << "End of waiting people" << endl;
		}

	
};

#endif