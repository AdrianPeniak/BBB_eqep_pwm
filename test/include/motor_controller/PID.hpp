
#ifndef PID_HPP_
#define PID_HPP_

class PID
{
  public:
    PID();
    PID(float Kp, float Ki, float Kd);
    PID(float Kp, float Ki, float Kd, float min_output, float max_output);
    float getValue(float curValue, float prevValue, float time_step);

  private:
    float Kp;
    float Ki;
    float Kd;
    float time_step; //seconds
    float min_output;
    float max_output;
    float bound(float value);
};

#endif
