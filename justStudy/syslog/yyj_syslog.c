#include<stdio.h>
#include<signal.h>
#include<syslog.h>


void test_sig_handler(int signum){
    printf("[YYJ SIGNAL]\n");
    openlog("[YYJ-SYSLOG TEST]", LOG_CONS|LOG_NDELAY|LOG_PID, LOG_LOCAL0);
    syslog(LOG_EMERG, "YYJ LOG_EMERG TEST %d", signum);
    syslog(LOG_NOTICE, "YYJ LOG_NOTICE TEST %d", signum);
    closelog();
    printf("[YYJ CLOSE SIGNAL]\n");

    _exit(127);

}

int main(int argc, char **argv){
    signal(SIGINT, test_sig_handler);
    signal(SIGILL, test_sig_handler);
    signal(SIGABRT, test_sig_handler);
    signal(SIGBUS, test_sig_handler);
    signal(SIGSTKFLT, test_sig_handler);
    signal(SIGFPE, test_sig_handler);
    signal(SIGSEGV, test_sig_handler);

    while(1){
	sleep(1);
    }
    return 0;

}
