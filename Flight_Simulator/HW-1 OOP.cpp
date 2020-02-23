#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

string currentStatus;		// Ucagin o anki durumunu gosteren degiskendir.
int currentTime = 9*3600;	// Saniye cinsinden simdiki zamani belirtir.
int sleepTime = 1000; 	// Main icindeki dongunun uyku zamanidir.(milisaniye cinsinden)
class Flight{
	public:
		int rpt = 0; 	// Park konumundan Taxi yapana kadar gecen zamanda sürekli ekrana basmamasi için atanmis bir degiskendir.
		int currentSpeed=0;
		int currentAltitude=0;
		string make_and_model,orig,dest,airline,flightNumber;
		unsigned long int departure_time,arrival_time,departure_time_hour,departure_time_minute,arrival_time_hour,arrival_time_minute;
		
		void simulate(){			//Fonksiyon, Departure ve Arrival zamanlarini sadece saat cinsinden bekler
			arrival_time = (arrival_time_hour*3600 + arrival_time_minute *60);	//Saat cinsinden alinan zamanlari isleyebilmek icin saniyeye donusturur!
			departure_time = (departure_time_hour*3600 + departure_time_minute * 60);
			if(currentTime <= (departure_time-(5*60)) && rpt == 0 ){
				currentStatus = "Parked";
				cout<<"Airline: "<<airline<<"	Flight Number: "<<flightNumber<<endl;
				cout<<endl<<"Origination: "<<orig<<"		Destination: "<<dest<<"		Departure Time: "<<departure_time_hour<<"."<<departure_time_minute<<endl;
				cout<<endl<<"Current Status : " << currentStatus <<"		Current Time: "<<currentTime/3600<<"."<<(currentTime%3600)/60<<"."<<((currentTime%3600)%60)<<"		Estimated Arrival Time: "<<arrival_time_hour<<"."<<arrival_time_minute<<endl;
				cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
				rpt++;
			}		
			if(currentTime == (departure_time-(5*60))){
				currentStatus = "Taxiing to Taking Off";
				currentSpeed = 20;
				cout<<"Airline: "<<airline<<"	Flight Number: "<<flightNumber<<endl;
				cout<<endl<<"Origination: "<<orig<<"		Destination: "<<dest<<"		Current Speed: "<<currentSpeed<<" km/h"<<endl;
				cout<<endl<<"Current Status : " << currentStatus <<"	Current Time: "<<currentTime/3600<<"."<<(currentTime%3600)/60<<"."<<((currentTime%3600)%60)<<"		Estimated Arrival Time: "<<arrival_time_hour<<"."<<arrival_time_minute<<endl;
				cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
			}
			if (currentTime == departure_time){
				currentStatus = "Taking off";
				currentSpeed = 250;
				cout<<"Airline: "<<airline<<"	Flight Number: "<<flightNumber<<endl;
				cout<<endl<<"Origination: "<<orig<<"		Destination: "<<dest<<"		Current Speed: "<<currentSpeed<<" km/h"<<endl;
				cout<<endl<<"Current Status : " << currentStatus <<"	Current Time: "<<currentTime/3600<<"."<<(currentTime%3600)/60<<"."<<((currentTime%3600)%60)<<"		Estimated Arrival Time: "<<arrival_time_hour<<"."<<arrival_time_minute<<endl;
				cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
			}
			if (currentTime == (departure_time + (3*60))){
				currentStatus = "Climbing";
				cout<<"Airline: "<<airline<<"	Flight Number: "<<flightNumber<<endl;
			cout<<endl<<"Origination: "<<orig<<"		Destination: "<<dest<<"		Current Speed: "<<currentSpeed<<" km/h"<<endl;
				cout<<endl<<"Current Status : " << currentStatus <<"	Current Time: "<<currentTime/3600<<"."<<(currentTime%3600)/60<<"."<<((currentTime%3600)%60)<<"		Estimated Arrival Time: "<<arrival_time_hour<<"."<<arrival_time_minute<<endl;
				cout<<endl<<"Current Altitude: "<<currentAltitude<<" feet"<<"	We are climbing..."<<endl<<endl;
				cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
			}
			if (currentTime == (departure_time + (3*60+2*60+20))){
				currentStatus = "Cruising";
				currentSpeed = 700;
				currentAltitude = 35000;
				cout<<"Airline: "<<airline<<"	Flight Number: "<<flightNumber<<endl;
				cout<<endl<<"Origination: "<<orig<<"		Destination: "<<dest<<"		Current Speed: "<<currentSpeed<<" km/h"<<endl;
				cout<<endl<<"Current Status : " << currentStatus <<"	Current Time: "<<currentTime/3600<<"."<<(currentTime%3600)/60<<"."<<((currentTime%3600)%60)<<"		Estimated Arrival Time: "<<arrival_time_hour<<"."<<arrival_time_minute<<endl;
				cout<<endl<<"Altitude is changed. Current Altitude: "<<currentAltitude<<" feet"<<endl;
				cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
			}
			if (currentTime ==(arrival_time - (72*60 + 55))){
				currentStatus = "Descending";
				cout<<"Airline: "<<airline<<"	Flight Number: "<<flightNumber<<endl;
				cout<<endl<<"Origination: "<<orig<<"		Destination: "<<dest<<"		Current Speed: "<<currentSpeed<<" km/h"<<endl;
				cout<<endl<<"Current Status : " << currentStatus <<"	Current Time: "<<currentTime/3600<<"."<<(currentTime%3600)/60<<"."<<((currentTime%3600)%60)<<"		Estimated Arrival Time: "<<arrival_time_hour<<"."<<arrival_time_minute<<endl;
				cout<<endl<<"Current Altitude: "<<currentAltitude<<" feet"<<"	We are descending..."<<endl<<endl;
				cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
			}
			if (currentTime == (arrival_time - (2*60 + 55))){
				currentStatus = "Landing";
				currentSpeed = 250;
				currentAltitude=1400;
				cout<<"Airline: "<<airline<<"	Flight Number: "<<flightNumber<<endl;
				cout<<endl<<"Origination: "<<orig<<"		Destination: "<<dest<<"		Current Speed: "<<currentSpeed<<" km/h"<<endl;
				cout<<endl<<"Current Status : " << currentStatus <<"	Current Time: "<<currentTime/3600<<"."<<(currentTime%3600)/60<<"."<<((currentTime%3600)%60)<<"		Estimated Arrival Time: "<<arrival_time_hour<<"."<<arrival_time_minute<<endl;
				cout<<endl<<"Altitude is changed. Current Altitude: "<<currentAltitude<<" feet	  "<<"We are still descending..."<<endl;;
				cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
			}
			if (currentTime == (arrival_time)){
				currentStatus = "Taxiing to Parked";
				currentSpeed = 20;
				currentAltitude = 0;
				cout<<"Airline: "<<airline<<"	Flight Number: "<<flightNumber<<endl;
				cout<<endl<<"Origination: "<<orig<<"		Destination: "<<dest<<"		Current Speed: "<<currentSpeed<<" km/h"<<endl;
				cout<<endl<<"Current Status : " << currentStatus <<"	Current Time: "<<currentTime/3600<<"."<<(currentTime%3600)/60<<"."<<((currentTime%3600)%60)<<"		Estimated Arrival Time: "<<arrival_time_hour<<"."<<arrival_time_minute<<endl;
				cout<<endl<<"Altitude is changed. Current Altitude: "<<currentAltitude<<" feet"<<endl;
				cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
			}
			if (currentTime == (arrival_time + (5*60))){
				currentStatus = "Parked";
				currentSpeed = 0;
				cout<<"Airline: "<<airline<<"	Flight Number: "<<flightNumber<<endl;
				cout<<endl<<"Origination: "<<orig<<"		Destination: "<<dest<<"		Current Speed: "<<currentSpeed<<" km/h"<<endl;
				cout<<endl<<"Current Status : " << currentStatus <<"	Current Time: "<<currentTime/3600<<"."<<(currentTime%3600)/60<<"."<<((currentTime%3600)%60)<<"			Estimated Arrival Time: "<<arrival_time_hour<<"."<<arrival_time_minute<<endl;
				cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
			}
		
			
				}	
			
		
		
		void set_Make_and_Model(string x){
			make_and_model = x;
		}
		void get_Make_and_Model(){
			cout<<make_and_model<<endl;
		}
		void toString(){
			cout<<currentStatus<<endl;
		}
		
		void setOrig(string x){  
			orig = x;
		}
		void setDest(string x){
			dest = x;
		}
		void getOrig(){
			cout<<"Originate: "<<orig<<endl;
		}
		void getDest(){
			cout<<"Destination: "<<dest<<endl;
		}
		void setAirline(string x){
			airline = x;
		}
		void getAirline(){
			cout<<"Airline: "<<airline<<endl;
		}
		void setFlightNumber(string x){
			flightNumber = x;
		}
		void getFlightNumber(){
			cout<<"Flight Number: "<<flightNumber<<endl;
		}
		void setDepartTime(int x,int y){
			departure_time_hour = x;
			departure_time_minute = y;
		}
		void getDepartTime(){
			cout<<"Departure time: "<<departure_time_hour<<"."<<departure_time_minute<<endl;
		}
		void setEstArrTime(int x, int y){	//Estimated Arrival Time set eder.
			arrival_time_hour = x;
			arrival_time_minute = y;
		}
		void getEstArrTime(){
			cout<<"Estimated Arrival Time: "<<arrival_time_hour<<"."<<arrival_time_minute<<endl;
		}
		void setAltitude(int x){	//feet cinsinden altitude set eder.
			currentAltitude = x;
		}
		void getAltitude(){
			cout<<"Current Altitude: "<<currentAltitude<<" feet"<<endl;
		}
		void setCurrSpeed(int x){	// km/h cinsinden hizi set eder.
			currentSpeed = x;
		}
		void getCurrSpeed(){
			cout<<"Current Speed : "<<currentSpeed<<" km/h"<<endl;
		}
		
	
	
};

void faster(){			// Programin anlik hizini 2 katina cikarir.Program varsayilan olarak gercek zamanlidir!
	sleepTime = sleepTime/2;
		}
void slower(){			//Programin anlik hizini yariya dusurur!
	sleepTime = sleepTime*2;
		}		

int main(){
	//Asagidaki atamalar deneme amacli yapilmistir.
	
	cout<<"------Welcome to Air Traffic Simulator-----"<<endl<<endl<<"----------------------------------------------------------------------------------------------------------------"<<endl;
	bool x=true;	// Asagidaki while dongusunun bitis zamanini ayarlamak icin atanmistir.
	Flight A;
	Flight B;
	Flight C;
	A.setOrig("IST");
	A.setDest("ESB");
	A.setDepartTime(10,0);
	A.setEstArrTime(12,0);
	A.setAirline("Turkish Airlines");
	A.setFlightNumber("TK2572");
	
	B.setOrig("IST");
	B.setDest("ADB");
	B.setAirline("Onur Air");
	B.setDepartTime(11,0);
	B.setEstArrTime(14,0);	
	B.setFlightNumber("OHY150");
	
	C.setOrig("IST");
	C.setDest("ADA");
	C.setDepartTime(11,30),
	C.setEstArrTime(15,30);
	C.setAirline("Pegasus");
	C.setFlightNumber("PC3309");
	
	
	while (x){
		A.simulate();
		B.simulate();
		C.simulate(); //Fonksiyonlar 4 degisken almaktadir, ilk iki degisken sirasiyla departure hour ve minute seklinde, son ikisi ise arrival hour ve minute seklindedir.(Minute degerinin "0" olmasi durumunda lutfen 0 olarak belirtiniz!)
		if(currentTime == 17*3600){				// Saat 17.00 oldugunda program sonlanmaktadir.
			x=false;
		}
		Sleep(sleepTime);
		currentTime++;
	}
	
	return 0;
}
