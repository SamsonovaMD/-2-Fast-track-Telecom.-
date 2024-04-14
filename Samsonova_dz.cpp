// Samsonova_dz.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdint>
#include <bit>

void invertBits(uint64_t* ptr, size_t length, int startBit, int endBit) {
    if (ptr == nullptr || length == 0 || startBit < 0 || endBit < 0 || startBit >= 64 || endBit >= 64 || startBit > endBit)
        return;

    for (size_t i = 0; i < length; ++i) {
        uint64_t& value = ptr[i];

        for (int j = startBit; j <= endBit; ++j) {
            value ^= (1ULL << j); // Инвертировать выбранный бит
        }
    }
}

int main() {
    // Пример использования
    uint64_t data[] = { 0b0101010101010101, 0b1010101010101010 }; // Пример данных
    size_t dataLength = sizeof(data) / sizeof(data[0]);

    // Инвертировать биты с позиции 4 до 11
    int startBit = 4;
    int endBit = 11;

    std::cout << "Before:" << std::endl;
    for (size_t i = 0; i < dataLength; ++i) {
        std::cout << std::hex << data[i] << " ";
    }
    std::cout << std::endl;

    invertBits(data, dataLength, startBit, endBit);

    std::cout << "After:" << std::endl;
    for (size_t i = 0; i < dataLength; ++i) {
        std::cout << std::hex << data[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}