//#include <iostream>
//#include <random>
//#include <chrono>
//
//int64_t firstSolution(int32_t* arr, int len, int64_t L, int64_t R) {
//    int64_t count = 0;
//    int64_t sum;
//    for (int i = 0; i < len; ++i) {
//        for (int j = i, sum = 0; j < len; ++j) {
//            sum += arr[j];
//            if (sum >= L && sum <= R)
//                ++count;
//        }
//    }
//    return count;
//}
//
//void solve() {
//    std::random_device rd;
//    std::mt19937 gen(23456);
//    std::uniform_int_distribution<> distrib(1, 1000);
//    std::uniform_int_distribution<> distrib1(-10000, 10000);
//    std::uniform_int_distribution<> distrib2(-1000000, 1000000);
//    int64_t min, max;
//    int len = 50000;
//    int32_t* array = new int32_t[len];
//
//    for (int i = 0; i < len; ++i) {
//        array[i] = distrib1(gen);
//    }
//
//    min = distrib2(gen);
//    max = min + distrib(gen);
//
//    int64_t check = firstSolution(array, len, min, max);
//    std::cout << check << "\n";
//    delete[] array;
//
//}
//
//int main() {
//    std::ios_base::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::chrono::system_clock::time_point start1 = std::chrono::system_clock::now();
//    solve();
//    std::chrono::system_clock::time_point end1 = std::chrono::system_clock::now();
//    std::chrono::duration<double> sec1 = end1 - start1;
//    std::cout << "Time1 = " << sec1.count() << "\n";
//}