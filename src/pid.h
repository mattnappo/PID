#ifndef PID_H
#define PID_H

#define E_BLOCK_SIZE 512

typedef struct pid {
    const double SP;

    const double Kp;
    const double Ki;
    const double Kd;

    double *error;

    double t;
} PID;

PID *init_pid(double SP, double Kp, double Ki, double Kd);
void free_pid(PID *pid);

void step(PID *pid, double PV);
void step_n(PID *pid, double PV);

#endif
