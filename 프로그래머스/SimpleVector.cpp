#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1. 기본 생성자는 크기 10의 배열을 생성
// 2. 숫자를 하나 받는 생성자는 해당 숫자에 해당되는 크기의 배열을 만듭니다.
// 3. 멤버 함수를 포함 push_back, pop_back, size, capacity

template <typename T>
class SimpleVector {
private:
    T* data; //템플릿 포인터
    int Size;  //현재 요소의 개수
    int Capacity;   //배열의 크기

    void resize() {
        Capacity *= 2;
        T* newData = new T[Capacity];
        for (int i = 0; i < Size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    // 기본 생성자는 크기 10을 생성해줘야함
    SimpleVector() : Size(0), Capacity(10){
    
        data = new T[Capacity];
    }

    SimpleVector(int capacity) : Size(0), Capacity(capacity) {
    if (capacity <= 0) {
        Capacity = 10;
        data = new T[Capacity];
    }
    else {
        data = new T[Capacity];
    }
}

    // new 들어와서 소멸자
    ~SimpleVector() {
        delete[] data;
    }

    // 원소 추가
    void push_back(const T& value) {
        if (Size == Capacity)
        {
            resize();
        }
        data[Size++] = value;
    }

    // 원소 제거
    void pop_back() {
        if (Size == 0) {
            return;
        }
        --Size;
    }

    //원소 개수 반환
    int size() const {
        return Size;
    }

    //배열 크기 반환
    int capacity() const {
        return Capacity;
    }
};

int main() {
    SimpleVector<int> vec; // 기본 생성자 호출

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    cout << "원소개수: " << vec.size() << endl;
    cout << "배열크기: " << vec.capacity() << endl;

    vec.pop_back();
    cout << "삭제후 크기: " << vec.size() << endl;

    return 0;
}
