# C++ STL Vector 종합 가이드

## Vector란 무엇인가?
`std::vector`는 C++ STL(Standard Template Library)에서 제공하는 동적 배열 컨테이너입니다. 배열과 유사하지만 크기가 자동으로 조정되며, 다양한 유틸리티 메서드를 제공합니다. 연속적인 메모리를 사용하므로 배열과 같이 빠른 랜덤 접근이 가능합니다.

---

## 주요 특징
1. **동적 크기 조정**
   - 요소를 추가하거나 제거할 때 크기가 자동으로 조정됩니다.
2. **연속적인 메모리**
   - 배열처럼 메모리가 연속적으로 할당됩니다.
3. **랜덤 접근 가능**
   - 특정 인덱스에 `O(1)` 복잡도로 접근할 수 있습니다.
4. **다양한 메서드 제공**
   - 삽입, 삭제, 정렬 등의 유틸리티 메서드가 제공됩니다.

---

## Vector의 선언 및 초기화
```cpp
#include <vector>

std::vector<int> vec1;              // 빈 벡터
std::vector<int> vec2(5);           // 크기 5, 값은 디폴트(0)
std::vector<int> vec3(5, 10);       // 크기 5, 모든 값 10
std::vector<int> vec4 = {1, 2, 3};  // 리스트 초기화
```

---

## 요소 추가 및 제거

### 추가
```cpp
vec1.push_back(10);  // 끝에 10 추가
vec1.push_back(20);  // 끝에 20 추가
```

### 제거
```cpp
vec1.pop_back();     // 마지막 요소 제거
```

---

## 요소 접근

### 인덱스 접근
```cpp
std::cout << vec1[0] << std::endl;  // 첫 번째 요소
```

### 안전한 접근
```cpp
std::cout << vec1.at(0) << std::endl;  // 범위 초과 시 예외 발생
```

---

## 벡터 크기 및 용량 관리

### 크기 확인
```cpp
std::cout << "크기: " << vec1.size() << std::endl;
```

### 용량 확인
```cpp
std::cout << "용량: " << vec1.capacity() << std::endl;
```

### 동적 크기 조정
```cpp
vec1.resize(10, 42);  // 크기를 10으로 늘리고 추가된 요소는 42로 초기화
```

### 벡터 비우기
```cpp
vec1.clear();  // 모든 요소 제거
```

### 벡터가 비었는지 확인
```cpp
if (vec1.empty()) {
    std::cout << "벡터가 비었습니다." << std::endl;
}
```

---

## 삽입 및 삭제

### 삽입
```cpp
vec1.insert(vec1.begin(), 5);  // 첫 번째 위치에 5 삽입
```

### 삭제
```cpp
vec1.erase(vec1.begin());  // 첫 번째 요소 삭제
```

---

## 벡터 정렬
```cpp
#include <algorithm> // sort 함수 포함

std::vector<int> vec = {3, 1, 4, 1, 5};
std::sort(vec.begin(), vec.end());  // 오름차순 정렬

for (int val : vec) {
    std::cout << val << " ";
}  // 출력: 1 1 3 4 5
```

---

## 벡터와 반복자

벡터는 반복자를 사용하여 요소를 순회할 수 있습니다.

### 반복자 사용 예시
```cpp
std::vector<int> vec = {10, 20, 30};

for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
}  // 출력: 10 20 30
```

### 범위 기반 for문
```cpp
for (int val : vec) {
    std::cout << val << " ";
}
```

---

## 벡터와 배열

### 배열처럼 사용하기
벡터는 배열처럼 연속된 메모리를 사용하므로 배열과 유사하게 동작합니다.
```cpp
std::vector<int> vec = {1, 2, 3};
std::cout << vec[0] << std::endl;  // 첫 번째 요소
```

### 배열로 변환
벡터의 내부 데이터를 배열로 변환할 수 있습니다.
```cpp
int* arr = vec.data();
std::cout << arr[0] << std::endl;  // 첫 번째 요소
```

---

## 동적 메모리 관리
벡터는 내부적으로 동적 메모리를 관리하므로, 메모리 할당과 해제를 자동으로 처리합니다.

### 메모리 최적화
```cpp
vec1.shrink_to_fit();  // 사용되지 않는 메모리 반환
```

---

## 일반적인 문제와 해결 방법

### 메모리 초과
- 큰 데이터를 처리할 때 `resize()`나 `reserve()`를 사용하여 미리 메모리를 할당합니다.

### 중간 삽입/삭제 성능 저하
- 중간 삽입/삭제가 빈번하면 `std::list`와 같은 다른 컨테이너를 고려하세요.
