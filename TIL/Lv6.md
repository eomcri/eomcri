# C++ 기초 및 객체지향 프로그래밍 (OOP) 정리

## 1. C++ 기초

### 1.1 변수와 데이터 타입

- **변수 선언**: 
    ```cpp
    int a = 10;  // 정수형 변수
    float b = 3.14;  // 실수형 변수
    char c = 'A';  // 문자형 변수
    ```

- **기본 데이터 타입**:
    - `int`: 정수형 (예: `int a = 10;`)
    - `float`: 실수형 (예: `float b = 3.14;`)
    - `double`: 더 높은 정확도의 실수형 (예: `double d = 3.14159;`)
    - `char`: 문자형 (예: `char c = 'A';`)
    - `bool`: 불린형 (참/거짓) (예: `bool isTrue = true;`)

### 1.2 연산자

- **산술 연산자**: `+`, `-`, `*`, `/`, `%`
- **비교 연산자**: `==`, `!=`, `<`, `>`, `<=`, `>=`
- **논리 연산자**: `&&` (AND), `||` (OR), `!` (NOT)

### 1.3 제어문

- **조건문**:
    ```cpp
    if (a > b) {
        // a가 b보다 클 때 실행
    } else {
        // 그 외의 경우 실행
    }
    ```

- **반복문**:
    ```cpp
    for (int i = 0; i < 10; i++) {
        // 반복 작업
    }
    
    while (condition) {
        // 조건이 참일 때 반복
    }
    ```

### 1.4 함수

- **함수 정의**:
    ```cpp
    return_type function_name(parameter) {
        // 함수 내용
    }
    ```

    예시:
    ```cpp
    int add(int a, int b) {
        return a + b;
    }
    ```

- **함수 호출**:
    ```cpp
    int result = add(2, 3);
    ```

### 1.5 배열

- **배열 선언**:
    ```cpp
    int arr[5];  // 5개의 정수를 저장할 수 있는 배열
    ```

- **배열 사용**:
    ```cpp
    arr[0] = 10;
    arr[1] = 20;
    ```

## 2. 객체지향 프로그래밍 (OOP)

### 2.1 클래스와 객체

- **클래스 선언**:
    ```cpp
    class MyClass {
    public:
        int x;
        void display() {
            cout << "x: " << x << endl;
        }
    };
    ```

- **객체 생성**:
    ```cpp
    MyClass obj;  // MyClass 클래스의 객체 obj 생성
    obj.x = 5;
    obj.display();  // "x: 5" 출력
    ```

### 2.2 생성자와 소멸자

- **생성자**: 객체가 생성될 때 자동 호출되는 특수 함수
    ```cpp
    class MyClass {
    public:
        MyClass() {  // 생성자
            cout << "객체가 생성되었습니다!" << endl;
        }
    };
    ```

- **소멸자**: 객체가 파괴될 때 자동 호출되는 특수 함수
    ```cpp
    class MyClass {
    public:
        ~MyClass() {  // 소멸자
            cout << "객체가 파괴되었습니다!" << endl;
        }
    };
    ```

### 2.3 상속 (Inheritance)

- **상속**: 기존 클래스를 확장하여 새로운 클래스를 만드는 방법
    ```cpp
    class Animal {
    public:
        void sound() {
            cout << "동물의 소리" << endl;
        }
    };

    class Dog : public Animal {  // Animal 클래스를 상속받은 Dog 클래스
    public:
        void sound() {
            cout << "멍멍!" << endl;
        }
    };
    ```

### 2.4 다형성 (Polymorphism)

- **다형성**: 동일한 이름의 함수가 서로 다른 동작을 하는 특성
    ```cpp
    class Animal {
    public:
        virtual void sound() {  // 가상 함수
            cout << "동물의 소리" << endl;
        }
    };

    class Dog : public Animal {
    public:
        void sound() override {  // 오버라이딩
            cout << "멍멍!" << endl;
        }
    };
    ```

- **다형성 예시**:
    ```cpp
    Animal* a = new Dog();
    a->sound();  // "멍멍!" 출력
    ```

### 2.5 캡슐화 (Encapsulation)

- **캡슐화**: 데이터와 그 데이터를 처리하는 메소드를 하나의 클래스에 묶는 것
    ```cpp
    class Account {
    private:
        int balance;
    public:
        void deposit(int amount) {
            if (amount > 0) {
                balance += amount;
            }
        }
        
        int getBalance() {
            return balance;
        }
    };
    ```

### 2.6 추상화 (Abstraction)

- **추상화**: 불필요한 세부사항을 숨기고, 중요한 부분만 노출하는 것
    ```cpp
    class Shape {  // 추상 클래스
    public:
        virtual void draw() = 0;  // 순수 가상 함수
    };

    class Circle : public Shape {
    public:
        void draw() override {
            cout << "원을 그립니다." << endl;
        }
    };
    ```

## 3. C++ 주요 표준 라이브러리

### 3.1 입력과 출력 (I/O)

- **입력**:
    ```cpp
    int x;
    cin >> x;  // 사용자로부터 입력 받기
    ```

- **출력**:
    ```cpp
    cout << "Hello, World!" << endl;
    ```

### 3.2 문자열 처리

- **문자열 선언**:
    ```cpp
    string str =
