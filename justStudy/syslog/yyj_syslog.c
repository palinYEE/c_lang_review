#include<stdio.h>
#include<signal.h>
#include<syslog.h>

void test_sig_handler_1(int signum);
void test_sig_handler_2(int signum);

#define CASE 2

#if CASE == 1
#define sig_handler test_sig_handler_1
#elif CASE == 2
#define sig_handler test_sig_handler_2
#endif


void test_sig_handler_1(int signum){
    printf("[YYJ SIGNAL_1]\n");
    openlog("[YYJ-SYSLOG TEST]", LOG_CONS|LOG_NDELAY|LOG_PID, LOG_LOCAL0);
    syslog(LOG_EMERG, "YYJ LOG_EMERG TEST %d", signum);
    syslog(LOG_NOTICE, "YYJ LOG_NOTICE TEST %d", signum);
    closelog();
    printf("[YYJ CLOSE SIGNAL_1]\n");

    _exit(127);
}

void test_sig_handler_2(int signum){
    printf("[YYJ SIGNAL_2]\n");
    // openlog("[YYJ-SYSLOG TEST]", LOG_CONS|LOG_NDELAY|LOG_PID, LOG_LOCAL0);
    syslog(LOG_EMERG, "YYJ LOG_EMERG TEST %d", signum);
    syslog(LOG_NOTICE, "YYJ LOG_NOTICE TEST %d", signum);
    // closelog();
    printf("[YYJ CLOSE SIGNAL_2]\n");

    _exit(127);
}

/* TODO: vsyslog example */


int main(int argc, char **argv){
    signal(SIGINT, sig_handler);
    signal(SIGILL, sig_handler);
    signal(SIGABRT, sig_handler);
    signal(SIGBUS, sig_handler);
    signal(SIGSTKFLT, sig_handler);
    signal(SIGFPE, sig_handler);
    signal(SIGSEGV, sig_handler);

    while(1){
	sleep(1);
    }
    return 0;

}
