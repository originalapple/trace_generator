#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

// using std::endl;
// using std::cout;

class DataFrame {
private:
    std::map<std::string, std::vector<std::string>> data; //멤버 변수: 칼럼 이름과 데이터를 저장할 맵
    size_t n_rows = 0; // 멤버 변수: 현재 데이터 프레임의 행 수

public:
    // 컬럼 추가
    void add_column(const std::string& name, const std::vector<std::string>& column_data) {
        if (data.empty()) {
            n_rows = column_data.size();
        }
        if (column_data.size() != n_rows) {
            std::cerr << "Error: Column size does not match the number of rows." << std::endl;
            return;
        }
        data[name] = column_data;
    }

    // 멤버함수: 새로운 행 추가, 새로운 행을 추가하는 함수/메소드 
    void add_row(const std::map<std::string, std::string>& row_data) {
        for (const auto& [key, value] : row_data) {
            if (data.find(key) != data.end()) {
                data[key].push_back(value);
            } else {
                // 새 컬럼 생성
                data[key] = std::vector<std::string>(n_rows, "");
                data[key].push_back(value);
            }
        }
        // 존재하지 않는 컬럼에 대해 빈 문자열 추가
        for (auto& [key, values] : data) {
            if (row_data.find(key) == row_data.end()) {
                values.push_back("");
            }
        }
        ++n_rows;
    }

    // 멤버 함수 : 데이터 프레임을 출력하는 함수
    void print() const {
        // 헤더 출력, 맵의 키(칼럼 이름)를 출력
        for (const auto& [key, _] : data) {
            std::cout << std::setw(12) << key << " ";
        }
        std::cout << std::endl;

        // 각 행의 데이터 출력
        for (size_t i = 0; i < n_rows; ++i) {
            for (const auto& [key, values] : data) {
                std::cout << std::setw(12) << values[i] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    DataFrame df;

    // 컬럼 추가
    df.add_column("Name", {"Alice", "Bob", "Charlie"});
    df.add_column("Age", {"25", "30", "22"});
    df.add_column("Salary", {"50000", "60000.5", "45000"});

    // 데이터 프레임 출력
    std::cout << "Initial DataFrame:" << std::endl;
    df.print();

    // 행 추가
    df.add_row({{"Name", "Dave"}, {"Age", "28"}, {"Salary", "55000"}});

    // 갱신된 데이터 프레임 출력
    std::cout << "\nUpdated DataFrame:" << std::endl;
    df.print();

    return 0;
}
