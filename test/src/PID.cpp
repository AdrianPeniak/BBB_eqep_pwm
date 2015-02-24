#include "../include/motor_controller/PID.hpp"

PID::PID()
{
  this->Kp = 0.0;
  this->Ki = 0.0;
  this->Kd = 0.0;
  this->min_output = 0.0;
  this->max_output = 100.0;
}

PID::PID(float Kp, float Ki, float Kd)
{
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  this->min_output = 0.0;
  this->max_output = 100.0;
}

PID::PID(float Kp, float Ki, float Kd, float min_output, float max_output)
{
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  this->min_output = min_output;
  this->max_output = max_output;
}

float PID::getValue(float curValue, float desValue, float time_step)
{
  static float sumError = 0;
  static float prevError = 0;

  float error = desValue - curValue;

  // calc potential term
  float potentialTerm = Kp * error;  

  // calc integral term
  sumError += error;
  float integralTerm = Ki *  sumError; 
  
  integralTerm = this->bound(integralTerm);

  // calc differential term
  float diffError = (error - prevError) / time_step;
  float differentialTerm = Kd * diffError;

  // calculate the PID value
  float pidValue = potentialTerm + integralTerm + differentialTerm;

  pidValue = this->bound(pidValue);

  return pidValue;   
}

float PID::bound(float value)
{
	//bound the output
  if(value > this->max_output)
  {
    value = this->max_output;
  } else if(value < this->min_output)
  {
    value = this->min_output;     
  }
  
  return value;
  
}




