#include "pid.h"

PID *init_pid (
    const double SP,
    const double Kp,
    const double Ki,
    const double Kd
) {
    PID *pid = malloc(sizeof(PID));
    pid->SP = SP;
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;

    pid->error = malloc(sizeof(double) * E_BLOCK_SIZE);
    pid->error[0] = 0;
    pid->t = 0;

    return pid;
}

void print_pid(PID *pid)
{
    printf(
        "PID:\nSP = %l\nKpid = (%l, %l, %l)\nt = %l\ne(t) = %l\n",
        pid->SP, pid->Kp, pid->Ki, pid->Kd, pid->t, pid->e(pid->t)
    );
}

void free_pid(PID *pid)
{
    free(pid);
}

void step(PID *pid);
void step_n(PID *pid);
