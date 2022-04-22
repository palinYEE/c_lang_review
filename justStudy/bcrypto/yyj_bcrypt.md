# bcrypt.h 사용법 정리

* 해당 마크다운 문서는 `bcrypt.h` 을 사용하여 난수 생성에 대한 내용을 다룬다. 
* 만약 해당 내용 외에 블록암호, 해시 함수 등을 사용하는 방법을 원한다면 `참고` 란에 있는 링크를 이용하면 된다.  

## CNG 프로그래밍 이란?

* CNG: `Cryptography API: Next Generation` 의 약자
* CNG는 암호화 API 를 지원
* 기능은 다음과 같다.
  * 암호화 민첩성 향상을 지 원하는 새로운 암호화 구성 시스템
  * 키 저장소에 대 한 세분화 된 추상화 및 알고리즘 작업의 저장소 분리입니다.
  * 장기 키가 있는 작업에 대 한 격리를 처리 합니다.
  * 대체 가능한 난수 생성기입니다.
  * 내보내기 서명 제한에서의 릴리프입니다.
  * 스택 전체에서 스레드로부터 안전 합니다.
  * 커널 모드 암호화 API.

## 일반적이 CNG 프로그래밍

* CNG API를 사용하는 일반적인 단계는 다음과 같다. 
  * 알고리즘 공급자 열기 (`BCryptOpenAlgorithmProvider`)
  * 알고리즘 속성 가져오기 또는 설정
  * 키 만들기 또는 가져오기
  * 암호화 작업 수행
  * 알고리즘 공급자 닫기 (`BCryptCloseAlgorithmProvider`)

## 해당 예제 코드에서 사용하는 함수 소개

* `BCryptOpenAlgorithmProvider`
```c
NTSTATUS BCryptOpenAlgorithmProvider(
  [out] BCRYPT_ALG_HANDLE *phAlgorithm, // CNG 공급자 핸들을 수신하는 BCRYPT_ALG_HANDLE 변수에 대한 포인터
  [in]  LPCWSTR           pszAlgId,     // 암호 알고리즘 식별자
  [in]  LPCWSTR           pszImplementation,    // 암호 알고리즘의 기본 공급자
  [in]  ULONG             dwFlags   // 함수 동작을 수정하는 플래그 
    /*
     * BCRYPT_ALG_HANDLE_HMAC_FLAG
     * BCRYPT_PROV_DISPATCH
     * BCRYPT_HASH_REUSABLE_FLAG
    */
);

[설명]
  * `phAlgorithm` 변수는 `BCryptCloseAlgorithmProvider` 함수를 통해서 반드시 close 시켜줘야 한다.
```
* `BCryptGenRandom`
```
NTSTATUS BCryptGenRandom(
  [in, out] BCRYPT_ALG_HANDLE hAlgorithm,       // CNG 공급자 핸들러
  [in, out] PUCHAR            pbBuffer,         // 난수 값을 넣을 공간
  [in]      ULONG             cbBuffer,         // 난수 값 크기
  [in]      ULONG             dwFlags           // 함수 동작 수정 플래그
    /*
        * BCRYPT_RNG_USE_ENTROPY_IN_BUFFER
        * BCRYPT_USE_SYSTEM_PREFERRED_RNG
    */
);
```
* `BCryptCloseAlgorithmProvider`
```
NTSTATUS BCryptCloseAlgorithmProvider(
  [in, out] BCRYPT_ALG_HANDLE hAlgorithm,
  [in]      ULONG             dwFlags
);
```

# 참고 

* https://docs.microsoft.com/en-us/windows/win32/api/bcrypt/ 
* https://docs.microsoft.com/ko-kr/windows/win32/seccng/typical-cng-programming
* https://hizstory.tistory.com/45