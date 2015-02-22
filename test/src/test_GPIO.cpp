#include "../interface/BlackLib/v2_0/include/BlackGPIO.h"
#include <string>
#include <iostream>
#include "../interface/BlackLib/v2_0/include/Timing.h"
#include <unistd.h>

int main (int argc, char** argv)
{

    BlackLib::BlackGPIO   testPin(BlackLib::GPIO_51,BlackLib::output, BlackLib::SecureMode);   // initialization first output, secure mode
    
    led1.setValue(BlackLib::high);         
    for(int i = 0; i < 10; i++)
    {
		testPin.setValue(BlackLib::high);          

		usleep(500000);
		testPin.setValue(BlackLib::low);          

		usleep(500000);
	}
	
}
