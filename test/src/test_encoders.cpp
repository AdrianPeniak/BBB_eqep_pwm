#include "../interface/encoders/include/eqep.h"
#include <cstring>

int main (int argc, char** argv)
{
    // If argc less than two, whoops
    if(argc < 3)
    {
        // Print out a usage example
        std::cerr << "Usage: " << argv[0] << " <mode> <root path of eQEP sysfs entry>.  e.g. " << argv[0] << "<mode> /sys/devices/ocp.2/48302000.epwmss/48302180.eqep" << "\n mode: 0 -> absolute, 1 -> relative" << std::endl;
        
        // Exit
        return 1;
    }
    
    eQEP eqep(argv[2], eQEP::eQEP_Mode_Absolute);
    if(strcmp(argv[1],"0") == 0){
		// Allocate an instane of 
		eQEP eqep(argv[2], eQEP::eQEP_Mode_Absolute);
	} else if(strcmp(argv[1],"1") == 0){
		// Allocate an instane of 
		eQEP eqep(argv[2], eQEP::eQEP_Mode_Relative);
	} else {
		std::cerr << "Mode is either:\n 0 -> absolute\n 1 -> relative" << std::endl;
		
		return 1;
	}
    
    // Set the unit time period to 100,000,000 ns, or 0.1 seconds
    eqep.set_period(100000000L);
    
    // Query back the period
    std::cout << "[eQEP " << argv[1] << "] Period = " << eqep.get_period() << " ns" << std::endl;
    
    // Read position indefintely
    while(1)
    {
        std::cout << "[eQEP " << argv[1] << "] Position = " << eqep.get_position() << std::endl;
    }
    
    // Return success
    return 0;
}
