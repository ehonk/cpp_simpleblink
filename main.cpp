//============================================================================
// Name        : cppjuly.cpp
// Author      : Andreas
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(){

	std::cout << "< Info > main start" << std::endl;

	string inputstate;
 	string sGPIO;
	string dir;
	string val;

	sGPIO="18";
	dir ="out";

	// Export
    cout << "< Info > GPIOHandle::export_gpio : " << sGPIO << endl;
    string export_str = "/sys/class/gpio/export";
    ofstream exportgpio(export_str.c_str()); // Open "export" file. Convert C++ string to C string. Required for all Linux pathnames
    if (exportgpio < 0){
        cout << " OPERATION FAILED: Unable to export GPIO"<< sGPIO <<" ."<< endl;
    }

    exportgpio << sGPIO ; //write GPIO number to export
    exportgpio.close(); //close export file

	// Set Direction

    cout << "< Info > GPIOHandle::setdir_gpio direction: " << dir << endl;
    usleep(50000);

    string setdir_str ="/sys/class/gpio/gpio" + sGPIO + "/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
    if (setdirgpio == 0){
        cout << " OPERATION FAILED: Unable to set direction of GPIO"<< sGPIO <<" ."<< endl;

    }

    setdirgpio << dir; //write direction to direction file
    setdirgpio.close(); // close direction file

	// Turn on

	val = "1";
    cout << "< Info > GPIOHandle::setval_gpio pin: " << sGPIO << " .value: " << val << endl;
    string setval_str = "/sys/class/gpio/gpio" + sGPIO + "/value";
    ofstream setvalgpioOn(setval_str.c_str()); // open value file for gpio
    if (setvalgpioOn < 0){
        cout << " OPERATION FAILED: Unable to set the value of GPIO"<< sGPIO <<" ."<< endl;
    }

    setvalgpioOn << val ;//write value to value file
    setvalgpioOn.close();// close value file

	// Turn off
	usleep(5000000);
	val = "0";
	ofstream setvalgpioOff(setval_str.c_str()); // open value file for gpio
    setvalgpioOff << val ;//write value to value file
    setvalgpioOff.close();// close value file

	//Unexport

    cout << "< Info > GPIOHandle::unexport_gpio : " << sGPIO << endl;
    string unexport_str = "/sys/class/gpio/unexport";
    ofstream unexportgpio(unexport_str.c_str()); //Open unexport file
    if (unexportgpio < 0){
        cout << " OPERATION FAILED: Unable to unexport GPIO"<< sGPIO <<" ."<< endl;
    }

    unexportgpio << sGPIO ; //write GPIO number to unexport
    unexportgpio.close(); //close unexport file

    return 0;

}