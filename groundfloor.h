#ifndef GROUNDFLOOR_H
#define GROUNDFLOOR_H

using namespace std;

class GroundFloor{
	private:
		int Ng; //visitors'capacity at ground floor
		int no_visitors; //current number of visitors at the ground floor
		int waiting_number;

	public:
		
		//constructor of ground floor
		//to construct/create the ground floor needs the capacity(Ng) 
		//initializes: Ng, no_visitors, waiting_number
		GroundFloor(int Ng){ 
			this->Ng = Ng; 
			no_visitors = 0; // which is empty of visitors
			waiting_number = 0;
			cout << "The ground floor has been created" << endl;
		}
		
		//check if the visitor can join the ground floor
		//	Increase the number of visitors the current time
		int Enter(){
			if(no_visitors < Ng){ 
				cout << "Visitor can join the ground floor" <<endl;
				return 1;
			}else{ 
				return 0;
			}
		}

		int GetNoVisitors(){
			return no_visitors;
		}
		
		//Give priority number to visitors that join the ground floor
		int Wait(Visitor* vis){
			waiting_number++;
			vis->SetPriorityNumber(waiting_number);
			cout << "Waiting for the lift!" << endl;
			return waiting_number;
		}

		void IncreaseVisitors(){
			no_visitors++;
		}
		
		//Destructor of ground floor
		~GroundFloor(){ 
			cout << "End of service!" << endl;
		}

};

#endif