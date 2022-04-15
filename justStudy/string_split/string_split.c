/*
 * file: string_split.c
 * explanation:  해당 소스코드는 string split 예제 소스이다.
 * */
#include<stdio.h>
#include<string.h>

int main()
{
	char test_string[] = "dhcp:eth0:4";
	char *interface_name;
	char *ip_version;
	char *ret_ptr;
	char *next_ptr;

	ret_ptr = strtok_r(test_string, ":", &next_ptr);
	ret_ptr = strtok_r(NULL, ":", &next_ptr);
	interface_name = ret_ptr;
	ret_ptr = strtok_r(NULL, ":", &next_ptr);
	ip_version = ret_ptr;

	printf("[String split] Origin: %s\n", test_string);
	printf("	- interface_name: %s\n", interface_name);
	printf("	- ip_version: %s\n", ip_version);

	return 0;

}

