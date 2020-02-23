#include <iostream>
using namespace std;

int static j = 1; // A counter that starts from 1 when each event created.
class Event {
	int year,month,day,hour,minute;
	public:
	int id;
	virtual void print() const=0; 	// Pure virtual function (That means, there is subclasses' print function which is defined seperately.)
	
	Event *next;	// To create a linked list, we need a pointer which is type of Event.
	Event(int x,int y,int z, int t,int k){
			id=j;
			j++;
			year = x;
			month = y;
			day = z;
			hour = t;
			minute = k;
	}
	int getYear(){
		return year;
	}
	int getMonth(){
		return month;
	}
	int getDay(){
		return day;
	}
	int getHour(){
		return hour;
	}
	int getMinute(){
		return minute;
	}
};

class Task: public Event{
	string taskName;
	int day,month,year,hour,minute;
	public:
	Task(int year,int month,int day, int hour,int minute) : Event(year,month,day,hour,minute){ 
	this->year = year;
	this->month = month;
	this->day = day;
	this->hour = hour;
	this->minute = minute;
	}
	void print() const {
			cout<<"Task with id "<<id<<" "<<"at"<<" "<<day<<"/"<<month<<"/"<<year<<", "<<hour<<":"<<minute<<" :"<<endl<<taskName<<endl;
		}
	void setTaskName(string x){
		taskName = x;
	}
	string getTaskName(){
		return taskName;
	}
	
};

class Appointment: public Event{
	string personName,place;
	int day,month,year,hour,minute;
	public:
	Appointment(int year,int month,int day, int hour,int minute) : Event(year,month,day,hour,minute)
	{
		this->year = year;
		this->month = month;
		this->day = day;
		this->hour = hour;
		this->minute = minute;	
	}
	void setPersonName(string x){
		personName = x;
	}
	void setPlace(string x){
		place = x;
	}
	string getPersonName(){
		return personName;
	}
	string getPlace(){
		return place;
	}
	void print() const{
		cout<<"Appointment with id "<<id<<" "<<"at "<<day<<"/"<<month<<"/"<< year<<", "<<hour<<":"<<minute<<" :"<<endl<<personName<<", "<<place<<endl;
	}
	
};

class Calendar {
		Event *head,*tail; //head and tail pointers of linked list.
		public:
		Calendar(){head=NULL;tail=NULL;}  //Initialize head and tail to NULL in constructor.
		
		
	Event * addEvent(int eventType,int year1,int month1,int day1,int hour1,int minute1){	//Create a linked list.
		
		if (head==NULL){ // If linked list is empty
			if (eventType==0){ // If Event is a task
				Task *t = new Task (year1,month1,day1,hour1,minute1); // Create a new task
				head=t;	//Equalize head and tail to new task which we have already created.
				tail=t;
				tail->next = NULL; // Equalize the tail's next pointer to NULL which means if we add another pointer here, we need a space.	
			}
			else if(eventType ==1){	// If Event is an appointment
				Appointment *a = new Appointment(year1,month1,day1,hour1,minute1);
				head=a;
				tail=a;
				tail->next = NULL;
			}
		}
		else if (head!= NULL){ // If linked list is not empty
			if (eventType==0){
				Task *t = new Task(year1,month1,day1,hour1,minute1);
				tail->next = t; // Add new task to end of the linked list.
				tail=t; // Change the tail of the list to new end of the list.
				tail->next=NULL;
			}
			else if(eventType ==1){
				Appointment *a = new Appointment(year1,month1,day1,hour1,minute1);
				tail->next = a;
				tail=a;
				tail->next=NULL;
			}
		
		}
		}
	
	void listEvents(){	// List all Events in linked list
		Event *temp;
		try{
			temp=head; // Event object is equal to head(beginning of the linked list).
			if (temp == NULL){
				throw "List is Empty!"; // throw to catch function if any error occurred while try block was executing.
			}
		}catch(const char* x){
			cout<<x<<endl; // print the error which is in throw statement.
		}
		while (temp!=NULL){ // If the list is not empty
			temp->print(); // Print the object's print function which refers to Appointment or Task ' s print function.
			cout<<endl;
			temp=temp->next; // Event object is equal to next Event object.
		}
	};
	void deleteEvent(int k){ //Delete an event with specific id.
		try{
		Event *temp = head; //Create a temporary event object to iterate on linked list.
		while (temp->next->id != k){
			temp= temp->next;
			throw "Event Not Found"; 
		}
		Event *temp1 = temp->next; // Create another object(temp1) and equalize it to temp object's next object. (So we have a two object connected with temp)
		temp->next = temp1->next;  // We connected temp and temp1's next.(That means we broke connection between temp and temp->next)
		delete temp1; //temp1 is an object with id that we want to delete. Thus, We don't need it anymore. (Memory deallocation)
		}catch(char const* x){
			cout<<x<<endl; 
		}
		
	};
	void filterEvents(int year,int month){ // We just want Events with specific year and month
		Event *temp;
		temp=head;
		
		while(temp!=NULL){
			try{
				if (temp->getYear()== year && temp->getMonth() == month){ // Refer to Event's get functions and if they are equal to given year and month:
					temp->print();
					cout<<endl;
					temp = temp->next;
				}
				else{
					throw "No Matching Event";
				}
			}catch(const char* x){
				cout<<x<<endl;
				break; //if throw statement executed and the code fell to the catch block,break the while loop.
			}
			
		
		}
	};
};

int main(){
Calendar a;
Task* b = static_cast<Task*>(a.addEvent(0,2019,11,26,10,20)); //Static cast which converts an Event object to Task object,so we can set Task's TaskName.
Task* c = static_cast<Task*>(a.addEvent(0,2015,10,26,10,20));
Task* d = static_cast<Task*>(a.addEvent(0,2014,05,26,10,20));
Task* e = static_cast<Task*>(a.addEvent(0,2000,02,26,10,20));
Task* f = static_cast<Task*>(a.addEvent(0,2003,01,26,10,20));
b->setTaskName("Finish your Homework");
c->setTaskName("Buy the plane ticket");
d->setTaskName("Pay your bills");
e->setTaskName("Go to work");
f->setTaskName("Get coffee");
Appointment* g = static_cast<Appointment*>(a.addEvent(1,1995,10,04,11,20));//Static cast which converts an Event object to Appointment object,so we can set Appointment's PersonName and Place.
Appointment* h = static_cast<Appointment*>(a.addEvent(1,1997,8,12,9,40));
Appointment* i = static_cast<Appointment*>(a.addEvent(1,1996,12,26,7,51));
Appointment* j = static_cast<Appointment*>(a.addEvent(1,1992,05,25,10,20));
Appointment* k = static_cast<Appointment*>(a.addEvent(1,1996,12,20,4,43));
g->setPersonName("Dr. Mustafa");
g->setPlace("Cafeteria");
h->setPersonName("Sn. Ismail Bulur");
h->setPlace("Conference");
i->setPersonName("Tuccar");
i->setPlace("Hal");
j->setPersonName("Ogretmen");
j->setPlace("Sinif");
k->setPersonName("Korpiklaani");
a.listEvents();
}
