#pragma once
#include <iostream>
#include <random>
#include <chrono>

void countFunc(int64_t part_sum[], int const left, int const mid,
    int const right, int64_t* count, int64_t max) {
    int p_s, p_f, new_start;
    new_start = mid + 1;
    int64_t s_xy;
    for (p_s = left; p_s <= mid; ++p_s) {
        p_f = new_start;
        while (p_f <= right) {
            s_xy = part_sum[p_f] - part_sum[p_s];
            if (s_xy >= max) {
                (*count) += right - p_f + 1;
                break;
            }
            else {
                new_start = ++p_f;
            }
        }
    }
}

void merge(int64_t array[], int64_t buffer[], int const left, int const mid, int const right,
    int64_t* count, int64_t min, int64_t max, int const len) {

    int64_t  count_before = count[0];
    countFunc(array, left, mid, right, &count[0], min);
    if (count_before < count[0])
        countFunc(array, left, mid, right, &count[1], max + 1);

    int const len_left = mid - left + 1;
    int const len_right = right - mid;
    int pbufs = 0;

    for (int i = 0; i < len_left; ++i) {
        buffer[i] = array[left + i];
        ++pbufs;
    }
    for (int j = 0; j < len_right; ++j) {
        buffer[pbufs + j] = array[mid + 1 + j];
    }
    
    int index_left = 0, index_right = 0;
    int index_merged = left;

    while (index_left < len_left && index_right < len_right) {
        if (buffer[index_left] <= buffer[pbufs + index_right]) {
            array[index_merged] = buffer[index_left];
            index_left++;
        }
        else {
            array[index_merged] = buffer[pbufs + index_right];
            index_right++;
        }
        index_merged++;
    }
    while (index_left < len_left) {
        array[index_merged] = buffer[index_left];
        index_left++;
        index_merged++;
    }

    while (index_right < len_right) {
        array[index_merged] = buffer[pbufs + index_right];
        index_right++;
        index_merged++;
    }
}

void mergeSort(int64_t array[], int64_t buffer[], int const begin, int const end, int64_t* count,
    int64_t min, int64_t max, int const len) {
    if (begin >= end)
        return;

    int const mid = (end + begin) / 2;
    mergeSort(array, buffer, begin, mid, count, min, max, len);
    mergeSort(array, buffer, mid + 1, end, count, min, max, len);
    merge(array, buffer, begin, mid, end, count, min, max, len);
}

void solve() {
    std::random_device rd;
    std::mt19937 gen(23456);
    std::uniform_int_distribution<> distrib(1, 1000);
    std::uniform_int_distribution<> distrib1(-10000, 10000);
    std::uniform_int_distribution<> distrib2(-1000000, 1000000);
    int64_t min, max;
    int len = 50000;

    int32_t* array = new int32_t[len];
    int64_t count[2] = { 0, 0 };
    int64_t* partial_sum = new int64_t[len + 1];
    int64_t* buffer = new int64_t[len + 1];
    partial_sum[0] = 0;

    for (int i = 0; i < len; ++i) {
        array[i] = distrib1(gen);
        partial_sum[i + 1] = partial_sum[i] + array[i];
    }

    min = distrib2(gen);
    max = min + distrib(gen);
  
    mergeSort(partial_sum, buffer, 0, len, count, min, max, len);
    std::cout << count[0] - count[1] << "\n";

    delete[] array;
    delete[] partial_sum;
    delete[] buffer;

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    solve();
    std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
    std::chrono::duration<double> sec = end - start;
    std::cout << "Time = " << sec.count() << "\n";
}
