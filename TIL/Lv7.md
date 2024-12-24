# C++ 포인터 종합 가이드

## 포인터란 무엇인가?
포인터는 다른 변수의 메모리 주소를 저장하는 변수입니다. C++에서 포인터는 메모리를 직접 액세스하고 조작할 수 있는 강력한 도구입니다.

### 문법
```cpp
int* ptr; // 정수를 가리키는 포인터
```

- `*`는 해당 변수가 포인터임을 나타냅니다.
- 타입(e.g., `int`, `char`)은 포인터가 가리킬 데이터의 타입을 나타냅니다.

---

## 포인터 선언 및 초기화
### 선언
```cpp
int* ptr;    // 정수를 가리키는 포인터
char* cptr;  // 문자를 가리키는 포인터
```

### 초기화
```cpp
int var = 10;
int* ptr = &var; // `&`는 `var`의 주소를 가져옵니다.
```

---

## 포인터 역참조(Dereferencing)
포인터 역참조는 포인터가 가리키는 메모리 주소에 저장된 값에 접근하는 것을 의미합니다.

### 예제
```cpp
int var = 10;
int* ptr = &var;

// 포인터를 통해 값에 접근하기
std::cout << *ptr << std::endl; // 출력: 10

// 포인터를 통해 값 수정하기
*ptr = 20;
std::cout << var << std::endl; // 출력: 20
```

---

## 널 포인터(Null Pointer)
유효한 주소로 초기화되지 않은 포인터는 `nullptr`로 설정하여 정의되지 않은 동작을 방지할 수 있습니다.

### 예제
```cpp
int* ptr = nullptr;
if (ptr == nullptr) {
    std::cout << "포인터는 null입니다" << std::endl;
}
```

---

## 포인터 연산(Pointer Arithmetic)
포인터를 증가시키거나 감소시켜 배열이나 메모리 블록을 탐색할 수 있습니다.

### 예제
```cpp
int arr[] = {10, 20, 30};
int* ptr = arr;

std::cout << *ptr << std::endl;   // 출력: 10
ptr++;
std::cout << *ptr << std::endl;   // 출력: 20
```

---

## 배열과 포인터
C++에서 배열 이름은 배열의 첫 번째 요소를 가리키는 포인터로 작동합니다.

### 예제
```cpp
int arr[] = {10, 20, 30};
int* ptr = arr;

std::cout << *ptr << std::endl;       // 출력: 10
std::cout << *(ptr + 1) << std::endl; // 출력: 20
```

---

## 함수 포인터
포인터는 함수도 가리킬 수 있어 동적 함수 호출이 가능합니다.

### 예제
```cpp
void greet() {
    std::cout << "Hello, World!" << std::endl;
}

void (*funcPtr)() = &greet;
funcPtr(); // greet 함수 호출
```

---

## 동적 메모리 할당
포인터는 `new`와 `delete`를 사용하여 메모리를 동적으로 할당하고 해제하는 데 필수적입니다.

### 예제
```cpp
int* ptr = new int(10); // 메모리를 동적으로 할당
std::cout << *ptr << std::endl; // 출력: 10

delete ptr; // 할당된 메모리를 해제
ptr = nullptr; // 댕글링 포인터 방지
```

---

## 일반적인 문제 및 모범 사례
### 댕글링 포인터(Dangling Pointer)
해제된 메모리 위치를 참조하는 포인터입니다.
- **해결 방법**: `delete` 후 포인터를 `nullptr`로 설정.

### 메모리 누수(Memory Leak)
동적으로 할당된 메모리가 해제되지 않을 때 발생합니다.
- **해결 방법**: 항상 `new`와 `delete`를 짝지어 사용.

### 와일드 포인터(Wild Pointer)
초기화되지 않은 포인터가 임의의 메모리 위치를 가리킬 때 발생합니다.
- **해결 방법**: 포인터를 `nullptr`로 초기화.

---

## 요약
- **포인터**는 메모리에 직접 접근할 수 있게 해줍니다.
- `*`는 역참조에, `&`는 주소를 가져오는 데 사용됩니다.
- 포인터를 신중하게 관리하여 정의되지 않은 동작, 메모리 누수 또는 충돌을 방지하십시오.

### 추가 학습 자료
- [C++ 공식 문서](https://en.cppreference.com/)
- [Modern C++ Features](https://moderncpp.com/)
