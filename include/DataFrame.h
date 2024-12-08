#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

class DataFrame {
private:
    // 컬럼 이름을 키로 하고, 해당 컬럼의 데이터를 저장하는 벡터를 값으로 하는 맵
    std::map<std::string, std::vector<std::string>> data;
    size_t n_rows = 0; // 현재 데이터 프레임의 행 수

public:
    // 새로운 컬럼을 추가하는 메소드
    void add_column(const std::string& name, const std::vector<std::string>& column_data) {
        if (data.empty()) {
            // 첫 번째 컬럼 추가 시 행 수를 설정
            n_rows = column_data.size();
        }
        if (column_data.size() != n_rows) {
            std::cerr << "Error: Column size does not match the number of rows." << std::endl;
            return;
        }
        data[name] = column_data;
    }

    // 새로운 행을 추가하는 메소드
    void add_row(const std::map<std::string, std::string>& row_data) {
        // 주어진 데이터에 대해 각 키가 현재 데이터 프레임의 컬럼에 존재하는지 확인
        for (const auto& kv : row_data) {
            const std::string& key = kv.first;
            const std::string& value = kv.second;
            if (data.find(key) != data.end()) {
                data[key].push_back(value);
            } else {
                // 컬럼이 존재하지 않으면, 새 컬럼을 생성하고 빈 값으로 채움
                data[key] = std::vector<std::string>(n_rows, "");
                data[key].push_back(value);
            }
        }
        // 존재하지 않는 컬럼에 대해 빈 값을 추가
        for (auto& kv : data) {
            const std::string& key = kv.first;
            std::vector<std::string>& values = kv.second;
            if (row_data.find(key) == row_data.end()) {
                values.push_back("");
            }
        }
        ++n_rows;
    }

    // 데이터 프레임을 출력하는 메소드
    void print() const {
        // 헤더 출력 (컬럼 이름)
        for (const auto& kv : data) {
            const std::string& key = kv.first;
            std::cout << std::setw(12) << key << " ";
        }
        std::cout << std::endl;

        // 각 행의 데이터를 출력
        for (size_t i = 0; i < n_rows; ++i) {
            for (const auto& kv : data) {
                const std::vector<std::string>& values = kv.second;
                std::cout << std::setw(12) << values[i] << " ";
            }
            std::cout << std::endl;
        }
    }
};
