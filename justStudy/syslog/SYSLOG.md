# SYSLOG 정리

## 사용 방법

* `openlog -> syslog or vsyslog -> closelog` 순으로 사용
* syslog 단독으로 사용해도 상관 없음. 단 openlog 에서 설정할 수 있는 로그의 주체를 데몬 이름으로 디폴트로 설정됨. 

## 사용 함수 원형

```c
#include <syslog.h>

/*
 * openlog: 해당 시스템의 logger와 연결해주는 함수 
 *      ident: 모든 로그 앞에 공통적으로 붙여지는 prefix 같은 역할 (const char *)
 *      option: logger 연결 옵션 (int). 해당 옵션들중 1개 이상을 설정할 수 있다. ex.) LOG_CONS | LOG_NDELAY | LOG_PID
 *          LOG_CONS        /* 	시스템 로그 기록자(syslogd) 에 데이터를 보내는 중에 에러가 발생한다면 직접적으로 시스템 콘솔에 기록합니다.
 *          LOG_NDELAY      /* 로그 기록자(syslogd)에 대한 연결을 즉시 연다.
 *          LOG_NOWAIT      /* 
 *          LOG_ODELAY      /* 첫번째 메세지가 로그에 기록될 때 까지 연결을 여는것을 미룬다.
 *          LOG_PERROR      /* 로그 메세지 역시 표준 에러로 출력한다
 *          LOG_PID         /* 각각의 메세지마다 PID를 포함시킨다. 
 *      facility:  메시지를 기록할 프로그램 유형을 지정하는 데 사용
 *          LOG_AUTH        /* 보안/인증 메시지 (상수가 정의된 시스템대신 LOG_AUTHPRIV 를 사용)
 *          LOG_AUTHPRIV    /* 보안/인증 메시지 (private)
 *          LOG_CRON        /* 클락 데몬clock daemon (cron and at)
 *          LOG_DAEMON	    /* 다른 시스템 데몬
 *          LOG_KERN	    /* 커널 메시지
 *          LOG_LOCAL0 ... LOG_LOCAL7	/* 로컬 사용을 위해 예약된 것
 *          LOG_LPR	        /* 라인 프린터 하위시스템
 *          LOG_MAIL	    /* 메일 하위 시스템
 *          LOG_NEWS	    /* USENET 뉴스 하위 시스템
 *          LOG_SYSLOG	    /* syslogd에 의해 내부적으로 생성된 메시지
 *          LOG_USER	    /* 일반적인 사용자 수준의 메시지
 *          LOG_UUCP	    /* UUCP 하위 시스템
 */
void openlog(const char *ident, int option, int facility);
/*
 * syslog: syslogd를 통해 분배되는 로그 메세지를 생성한다.
 * 사용 변수 
 *      priority: 해당 로그의 우선순위를 설정한다. ORing을 통해서 설정 가능 (int)
 *          #define LOG_EMERG   0   /* system is unusable 
 *          #define LOG_ALERT   1   /* action must be taken immediately 
 *          #define LOG_CRIT    2   /* critical conditions 
 *          #define LOG_ERR     3   /* error conditions 
 *          #define LOG_WARNING 4   /* warning conditions 
 *          #define LOG_NOTICE  5   /* normal but significant condition 
 *          #define LOG_INFO    6   /* informational 
 *          #define LOG_DEBUG   7   /* debug-level messages 
 *      format: 이는 printf와 동일 (const char *)
 */
void syslog(int priority, const char *format, ...);
/*
 * closelog: 시스템 logger에 쓰는데 사용된 file descriptor 를 닫는다. 해당 함수는 optional 하게 사용하면 된다.
 */
void closelog(void);

/*
 * vsyslog: syslog 에서 가변 인수를 입력받는 것 제외하고는 syslog 와 동일하다.
 */
void vsyslog(int priority, const char *format, va_list ap);
```

## 간단 사용 예시

```c
#include <syslog.h>

setlogmask (LOG_UPTO (LOG_NOTICE));

openlog ("exampleprog", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);

syslog (LOG_NOTICE, "Program started by User %d", getuid ());
syslog (LOG_INFO, "A tree falls in a forest");

closelog ();
```