#include <iostream>
#include <string>

class Car {
  private:
    std::string model;
    int year;

  public:
    //생성자
    Car(std::string model_name, int model_year) {
      model = model_name;
      year  = model_year;
  }

    // 멤버 함수 : 객체 정보 출력
    void display_info() {
      std::cout << "Car Model: " << model << ", Year: " << year << std::endl;
    }
};

int main() {
  // Car object 생성
  Car myCar("Tesla", 2024);

  // object 정보 출력
  myCar.display_info();

  return 0;
}
