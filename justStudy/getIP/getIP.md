# Local IP 를 얻는 방법

해당 문서는 로컬 IP를 얻는 방법에 대해서 기술한다. 
 * 구조체: `ifaddrs`
 * 함수: `getifaddrs`, `getnameinfo`  

관련 헤더 파일들은 다음과 같다. 
```c
#include <sys/types.h>
#include <sys/socket.h>
#include <ifaddrs.h>
```

## `getifaddrs` (함수)

함수의 원형은 다음과 같다. 
```c
int getifaddrs(struct ifaddrs **ifap);
void freeifaddrs(struct ifaddrs *ifp);
```
* 해당 함수를 통해서 IP 정보들을 가져올수 있다. 
* 주의할 점으로 `getifaddrs` 함수를 통해서 가져오면 *ifap 변수가 할당되는 방식임으로 `freeifaddrs`를 통해서 free 해주어야 한다. 
* 성공시 `0` 실패시 음수를 반환한다. 


## `getnameinfo` (함수)

함수 원형은 다음과 같다. 
```c
int getnameinfo(const struct sockaddr *sa, socklen_t salen, char *host, socklen_t hostlen, char *serv, socklen_t servlen, int flags);
```
* sockaddr 구조체를 통해 address 정보를 주면 host와 service에 대한 정보를 얻을 수 있다.
* 해당 플래그에 대한 변수 설명은 다음곽 같다. 
  * NI_DGRAM: 데이터그램 소켓에 대한 정보를 리턴하도록 강제한다.
  * NI_NAMEREQD: 호스트명을 찾을 수 없으면 숫자를 기본적으로 리턴하나 해당 플레그로 에러 리턴
  * NI_NOFQDN: 기본적으로 FQDN을 리턴, 호스트가 로컬일 경우만 FQDN의 첫 부분만 리턴
  * NI_NUMERICHOST: DNS 대신 host에 숫자 형식의 문자열을 리턴하도록 강제
  * NI_NUMERICSERV: 십진수 포트 번호를 리턴하도록 강제, /etc/services에 검색하지 않음.

## `ifaddrs` (구조체)
구조체의 구조는 다음과 같다. 
```c
struct ifaddrs   *ifa_next;         /* Pointer to next struct */
char             *ifa_name;         /* Interface name */
u_int             ifa_flags;        /* Interface flags */
struct sockaddr  *ifa_addr;         /* Interface address */
struct sockaddr  *ifa_netmask;      /* Interface netmask */
struct sockaddr  *ifa_dstaddr;      /* P2P interface destination */
void             *ifa_data;         /* Address specific data */
```
해당 구조체는 링크드리스트 구조로 되어있다. 

# 참고 사이트

* https://chipmaker.tistory.com/entry/IP%EC%A3%BC%EC%86%8C-%EB%B0%8F-%ED%8F%AC%ED%8A%B8-%EC%A0%95%EB%B3%B4%EA%B4%80%EB%A0%A8-%EC%8B%9C%EC%8A%A4%ED%85%9C-%ED%95%A8%EC%88%98