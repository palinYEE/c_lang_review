/*
 - 해당 코드는 getifaddrs 함수를 이용한 local ip를 얻는 방법에 대한 예제이다. 
 - author: YYJ 
*/
#include<stdio.h>
#include<string.h>
#include<netdb.h>
#include<ifaddrs.h>
#include<sys/types.h>
#include<sys/socket.h>

int main(int argc, char *argv[]){
    int s;
    char host[NI_MAXHOST];
    struct ifaddrs *ifaddr, *ifa;
    if(getifaddrs(&ifaddr) < 0) {
        printf("ERROR :: %s() : getifaddr()\n", __FUNCTION__);
        return -1;
    }
    memset(host, 0, sizeof(host));
    for(ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if(ifa->ifa_addr == NULL) {
            continue;
        }
        if(ifa->ifa_addr->sa_family == AF_INET){
            s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
            if(s != 0 ){
                printf("getnameinfo() fail : %s\n", gai_strerror(s));
                freeifaddrs(ifaddr);
                return -1;
            }
            printf("\tInterface: <%s>\n", ifa->ifa_name);
            printf("\tAddress: <%s>\n", host);
        }
    }
    freeifaddrs(ifaddr);
    return 0;
}
