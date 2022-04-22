#include<stdio.h>
#include<windows.h>
#include<bcrypt.h>

#pragma comment(lib, "bcrypt.lib")

/*
 * 참고 사이트: https://docs.microsoft.com/en-us/windows/win32/api/bcrypt/ 
 *		https://docs.microsoft.com/ko-kr/windows/win32/seccng/typical-cng-programming
 */

int main()
{
	static unsigned char buffer[32] = { 0, };
	int length = 32;
	BCRYPT_ALG_HANDLE pHandle = NULL;		/* bcrypt를 사용하는데 필요한 핸들러 */
	NTSTATUS ret = BCryptOpenAlgorithmProvider(&pHandle, BCRYPT_RNG_ALGORITHM, MS_PRIMITIVE_PROVIDER, 0);		/* bcrypt 핸들러를 선언한다. */
	
	if (BCRYPT_SUCCESS(ret)) {	/* BCryptOpenAlgorithmProvider SUCCESS */
		ret = BCryptGenRandom(pHandle, buffer, (ULONG)(sizeof(unsigned char) * length), BCRYPT_RNG_USE_ENTROPY_IN_BUFFER); /* 난수 생성 */
		if (!BCRYPT_SUCCESS(ret)) {
			printf("[YYJ] ERROR BCryptGenRandom!! \n");
		}
		else {
			printf("[YYJ] GEN RANDOM NUMBER : %s\n", buffer);
		}
		ret = BCryptCloseAlgorithmProvider(pHandle, 0);	/* 선언한 bcrypt 를 close 한다. */
		if (!BCRYPT_SUCCESS(ret)) {
			printf("[YYJ] ERROR BCryptCloseAlgorithmProvider!! \n");
			return 0;
		}
		else {
			return 0;
		}
	}
	else { /* BCryptOpenAlgorithmProvider FAIL */
		printf("[YYJ] ERROR BCryptOpenAlgorithmProvider!!\n");
	}

	return 1;

}
