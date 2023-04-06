#include "MS51_16K.H"
#include "timer.H"

#define PWM_PERIOD 191

void set_pwm_period(unsigned int period) {
  PWMPL = period;
  PWMPH = period >> 8;
}

void set_pwm_duty_cycle(unsigned int channel, unsigned int duty_cycle) {
  switch (channel) {
    case 1:
      PWM1L = duty_cycle;
      PWM1H = duty_cycle >> 8;
      break;
    default:
      return;
  }
  set_LOAD;
}

void timer0_isr(void) __interrupt 1
{
  static unsigned int duty_cycle = 0;
  set_pwm_duty_cycle(1, duty_cycle * 5);
  duty_cycle = !duty_cycle;
}

void main(void) {
  ALL_GPIO_QUASI_MODE;
  PWM_IMDEPENDENT_MODE;
  PWM_EDGE_TYPE;
  set_CLRPWM;
  PWM_CLOCK_FSYS;
  PWM_CLOCK_DIV_64;
  PWM_OUTPUT_ALL_NORMAL;
  set_pwm_period(PWM_PERIOD);
  set_PWMRUN;

  TIMER0_MODE1_ENABLE;
  TIMER0_FSYS_DIV12;
  ENABLE_GLOBAL_INTERRUPT;

  PWM1_P14_OUTPUT_ENABLE;

  while (1) {
  }
}
