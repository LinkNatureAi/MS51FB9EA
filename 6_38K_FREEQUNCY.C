#include "MS51_16K.H"
#include "timer.H"

void set_pwm_period(unsigned int period) {
  PWMPL = period;
  PWMPH = period >> 8;
}

void set_pwm_duty_cycle(unsigned int duty_cycle) {
      PWM1L = duty_cycle;
      PWM1H = duty_cycle >> 8;
     set_LOAD;
}

void main(void) {
  unsigned int duty_cycle = 0; 
  ALL_GPIO_QUASI_MODE;
  PWM_IMDEPENDENT_MODE;
  PWM_EDGE_TYPE;
  set_CLRPWM;
  PWM_CLOCK_FSYS;
  PWM_CLOCK_DIV_64;
  PWM_OUTPUT_ALL_NORMAL;
  set_pwm_period(1);
  set_PWMRUN;
  
  PWM1_P14_OUTPUT_ENABLE;
  while (1) {
    set_pwm_duty_cycle(duty_cycle * 200);
    duty_cycle = (duty_cycle + 1) % 2; 
  }
}
