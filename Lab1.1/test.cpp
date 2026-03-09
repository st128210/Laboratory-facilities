#include <iostream>
#include <cmath>
#include <iomanip>

int main(int argc, char* argv[])
{
    // Данные грубых измерений
    const int COARSE_N = 10;
    double coarseData[COARSE_N] = {
        0.349, 0.348, 0.349, 0.349, 0.350,
        0.350, 0.349, 0.350, 0.350, 0.349
    };
    // Данные точных измерений
    const int FINE_N = 50;
    double fineData[FINE_N] = {
        0.3512, 0.3506, 0.3513, 0.3513, 0.3510, 0.3502, 0.3500, 0.3501, 0.3500, 0.3503,
        0.3503, 0.3504, 0.3508, 0.3509, 0.3505, 0.3505, 0.3507, 0.3508, 0.3512, 0.3509,
        0.3510, 0.3509, 0.3510, 0.3512, 0.3521, 0.3516, 0.3513, 0.3510, 0.3509, 0.3511,
        0.3510, 0.3501, 0.3502, 0.3500, 0.3504, 0.3501, 0.3502, 0.3500, 0.3511, 0.3514,
        0.3513, 0.3511, 0.3513, 0.3500, 0.3499, 0.3501, 0.3514, 0.3513, 0.3502, 0.3504
    };

    // Считаем среднее 
    long double sum = 0;
    for (int i = 0; i < FINE_N; ++i)
    {
        sum += fineData[i];
    }
    long double sr = sum / FINE_N;
    std::cout << '\n' << sr << '\n';

    // Случайные отклонения от среднего
    std::cout << "Random deviations from the average:\n";
    std::cout << std::fixed << std::setprecision(6);
    for (int i = 0; i < FINE_N; ++i)
    {
        long double d_i = fineData[i] - sr;
        std::cout << d_i << '\n';
    }

    // Квадраты случайных отклонений от среднего
    std::cout << "\nSquares of random deviations from the mean:\n";
    std::cout << std::fixed << std::setprecision(10);
    for (int i = 0; i < FINE_N; ++i)
    {
        long double d_i = fineData[i] - sr;
        long double square_d_i = d_i * d_i;
        std::cout << square_d_i << '\n';
    }
    
    // Дисперсия распределения 
    
    long double sum_square_d_i = 0;
    for (int i = 0; i < FINE_N; ++i)
    {
        long double d_i = fineData[i] - sr;
        long double square_d_i = d_i * d_i;
        sum_square_d_i += square_d_i;
    }
    long double disp = std::sqrt(sum_square_d_i/(FINE_N - 1));
    std::cout << "\n" << disp;

    // Средняя квадратичная погрешность среднего
    long double skps = disp / std::sqrt(FINE_N);
    std::cout << '\n' << skps;

    return 0;
}