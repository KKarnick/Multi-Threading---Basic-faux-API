
#include <thread>
#include <map>
#include <chrono>
#include <iostream>

using namespace std::chrono_literals;  //needed for sleeping thread


void UpdateCurrentTemp(std::map<std::string, int> currentTemp) {
	   //set infinite loop to constantly update via background thread
	while (true) {
		for (auto& item : currentTemp) {
			item.second--;     //simulating cold front across US

			//display city & temp upon calling this background (updating) thread
			std::cout << item.first << ":  " << item.second << std::endl;
		}
		std::this_thread::sleep_for(3000ms);
	}

}


int main()
{
	//dummy data representing API
	std::map<std::string, int> currentTemp = {
		{"Detroit", 42},
		{"Chicago", 34},
		{"Las Angeles", 69},
		{"Las Vegas", 53}
	};

	   //set independent background thread to update current temps
	std::thread t1(UpdateCurrentTemp, currentTemp);


	system("pause>nul");


}