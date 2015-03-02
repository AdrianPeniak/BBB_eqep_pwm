#include "../include/motor_controller/controller.hpp"

int main(int argc, char **argv)
{
	
	if(argc != 5)
	{
		// Print out a usage example
        std::cerr << "Usage: " << argv[0] << " <path of config file>. kp ki kd kp ki kd" << std::endl;
        
        // Exit
        return 1;
	}

	//assign the pid gains
	float Kp_vel = atof(argv[2]);
	float Ki_vel = atof(argv[3]);
	float Kd_vel = atof(argv[4]);

	std::cout << Kp_vel << "," << Ki_vel << "," << Kd_vel << std::endl;
	
	// Initialize GPIO
	BlackLib::BlackGPIO ENA(BlackLib::GPIO_11,BlackLib::output, BlackLib::SecureMode);   
	BlackLib::BlackGPIO ENB(BlackLib::GPIO_10,BlackLib::output, BlackLib::SecureMode);
	BlackLib::BlackGPIO INA(BlackLib::GPIO_81,BlackLib::output, BlackLib::SecureMode);
	BlackLib::BlackGPIO INB(BlackLib::GPIO_9,BlackLib::output, BlackLib::SecureMode);
    
	ENA.setValue(BlackLib::high);          // turn on the led1
	ENB.setValue(BlackLib::high);          // turn on the led1
	INA.setValue(BlackLib::low);          // turn on the led1
	INB.setValue(BlackLib::low);          // turn on the led1
		
	//Initialize PWM
	BlackLib::BlackPWM pwmMotor(BlackLib::EHRPWM2A);
	pwmMotor.setDutyPercent(0.0);
        pwmMotor.setPeriodTime(1000000000, BlackLib::picosecond); //0.001
	pwmMotor.setPolarity(BlackLib::reverse);

	// Allocate an instane of eqep
	eQEP eqep(argv[1], eQEP::eQEP_Mode_Relative);

	// Set the unit time period on eqep
	time_step_s = time_step_ns/pow(10,9);
	eqep.set_period(time_step_ns);

	// initialize PID loops
	PID vel_PID = PID(Kp_vel, Ki_vel, Kd_vel, min_vel_output, max_vel_output);

	float setMotor = 0;
	int prev_deltaEncoder_ticks = 0;
	float prev_vel = 0.0;	
	float max_accel = 0.0;
	int i =0;
	//gives current motor speed, motor current, temperature, wheel position
	while(true)
	{
		i++;
		if(i > 100){
			desVel_mps = 1.0;
		}
		// get the encoder count
		int deltaEncoder_ticks = eqep.get_position();
		if(deltaEncoder_ticks == -1 && prev_deltaEncoder_ticks == -1)
		{
			deltaEncoder_ticks = 0;
		}

		// calculate the position
		float deltaPosition_m = (((float)deltaEncoder_ticks) / ticks_per_rev) * (2 * M_PI * wheel_radius_m); 
		curPos_m += deltaPosition_m;
		prev_deltaEncoder_ticks = deltaEncoder_ticks;
		
		// calculate the velocity
		float curVel_mps = deltaPosition_m/time_step_s;
		
		// calculate the acceleration
		float accel = (curVel_mps - prev_vel)/time_step_s;
  		prev_vel = curVel_mps;
		
		if(accel > abs(max_accel)){
			max_accel = accel;
		}

		// calculate the appropriate  PID value
		setMotor = vel_PID.getValue(curVel_mps,desVel_mps,time_step_s); 
		  
		if(setMotor < 0)
		{
			INA.setValue(BlackLib::low);
			INB.setValue(BlackLib::high);         
			setMotor = -1*setMotor;
		} else if(setMotor > 0) 
		{
			INA.setValue(BlackLib::high);
			INB.setValue(BlackLib::low);          
        	} else if(setMotor == 0){
			INA.setValue(BlackLib::low);
			INB.setValue(BlackLib::low);          
		}

		//set the motor PWM value
//		setMotor = 100.0 - setMotor;
		pwmMotor.setDutyPercent(setMotor);

		std::cout << "Velocity: " << curVel_mps << " ::: des_vel: " << desVel_mps << " ::: PWM value: " << setMotor << std::endl; 

	}
	pwmMotor.setDutyPercent(0.0);
}




