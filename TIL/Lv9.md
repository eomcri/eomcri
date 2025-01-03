# C++ 템플릿 가이드

## 템플릿이란?
템플릿은 C++에서 코드의 재사용성을 높이고 일반화된 코드를 작성할 수 있도록 지원하는 기능입니다. 클래스와 함수에서 사용할 수 있으며, 다양한 데이터 타입에 대해 동일한 로직을 적용할 수 있습니다.

---

## 함수 템플릿
함수 템플릿은 다양한 데이터 타입에서 동작하는 함수를 작성할 수 있게 해줍니다.

### 문법
```cpp
template <typename T>
T 함수이름(T 매개변수) {
    // 함수 구현
}
```
- `typename` 또는 `class` 키워드를 사용할 수 있습니다.
- `T`는 템플릿 파라미터로, 데이터 타입을 나타냅니다.

### 예제
```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(5, 10) << std::endl;      // 정수 덧셈
    std::cout << add(5.5, 10.5) << std::endl;  // 실수 덧셈
    return 0;
}
```

---

## 클래스 템플릿
클래스 템플릿은 데이터 타입에 독립적인 클래스를 설계할 수 있게 해줍니다.

### 문법
```cpp
template <typename T>
class 클래스이름 {
    T 멤버변수;
public:
    클래스이름(T 값) : 멤버변수(값) {}
    T getValue() { return 멤버변수; }
};
```

### 예제
```cpp
template <typename T>
class Book {
    T title;
    T author;
public:
    Book(T t, T a) : title(t), author(a) {}
    T getTitle() { return title; }
    T getAuthor() { return author; }
};

int main() {
    Book<std::string> myBook("C++ Programming", "John tonny");

    std::cout << "Title: " << myBook.getTitle() << std::endl;   // 출력: Title: C++ Programming
    std::cout << "Author: " << myBook.getAuthor() << std::endl; // 출력: Author: John Doe
    return 0;
}
```

---

## 템플릿 특수화
템플릿 특수화는 특정 데이터 타입에 대해 별도의 구현을 제공하는 기능입니다.

### 문법
```cpp
template <>
class 클래스이름<특정타입> {
    // 특정 타입에 대한 구현
};
```

### 예제
```cpp
template <typename T>
class Author {
public:
    void display(T name) {
        std::cout << "Author: " << name << std::endl;
    }
};

// 특수화
template <>
class Author<std::string> {
public:
    void display(std::string name) {
        std::cout << "Famous Author: " << name << std::endl;
    }
};

int main() {
    Author<int> unknownAuthor;
    Author<std::string> famousAuthor;

    unknownAuthor.display(123);       // 출력: Author: 123
    famousAuthor.display("John Doe"); // 출력: Famous Author: John Doe
    return 0;
}
```

---

## 템플릿 가변 인자(Variadic Templates)
가변 인자 템플릿은 여러 개의 템플릿 인자를 처리할 수 있습니다.

### 문법
```cpp
template <typename... Args>
void 함수이름(Args... args) {
    // 구현
}
```

### 예제
```cpp
template <typename... Args>
void displayBooks(Args... args) {
    (std::cout << ... << args) << std::endl;
}

int main() {
    displayBooks("Book1", ", ", "Book2", ", ", "Book3"); // 출력: Book1, Book2, Book3
    return 0;
}
```

---

## 템플릿의 장단점
### 장점
1. **코드 재사용성**: 동일한 로직을 여러 타입에 사용할 수 있습니다.
2. **유연성**: 데이터 타입에 의존하지 않는 일반화된 코드를 작성할 수 있습니다.

### 단점
1. **디버깅 어려움**: 컴파일 에러 메시지가 복잡할 수 있습니다.
2. **코드 부피 증가**: 여러 타입에 대해 인스턴스화될 때 코드 크기가 증가할 수 있습니다.

---

## 요약
- 템플릿은 코드의 재사용성을 높이는 데 유용합니다.
- 함수 템플릿과 클래스 템플릿을 통해 일반화된 코드를 작성할 수 있습니다.
- 특수화와 가변 인자 템플릿을 활용하면 더욱 세밀한 제어가 가능합니다.
