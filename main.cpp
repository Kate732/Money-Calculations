#include <iostream>

using namespace std;

int CalculateInvetmentMonthly(int current_month) {
    int investment_monthly = 0;
    switch (current_month)
    {
    case 1:
        investment_monthly = 50;
    case 6:
        investment_monthly = 70;
    case 10:
        investment_monthly = 100;
    case 12:
        investment_monthly = 200;
    default:
        break;
    }
    return investment_monthly;
}

int CalculateResultMoney(int current_month, int total_time_years, int investment_monthly, const int initial_sum,
    const double percent_from_gov, const double inflation, const double percent_per_year) {
    int result_sum = initial_sum;
    for (int current_month{}; current_month <= total_time_years * 12; current_month++) //runs each month
    {
        investment_monthly = CalculateInvetmentMonthly(current_month);
        result_sum += investment_monthly;
        if (current_month % 12 == 0) {
            result_sum += result_sum * percent_from_gov + result_sum * percent_per_year;
            result_sum -= result_sum * inflation;
        }
    }

    return result_sum;
}

int main() {
    int current_month = 1;
    int total_time_years = 5;
    int investment_monthly{};
    const int initial_sum = 1000;
    const double percent_from_gov = 0.25;
    const double inflation = 0.028;
    const double percent_per_year = 0.045;
    int money_by_the_end = CalculateResultMoney(current_month, total_time_years, investment_monthly, initial_sum, percent_from_gov, inflation, percent_per_year);

    cout << "Initial investment: " << initial_sum << " pounds." << endl;
    cout << "Scope: " << total_time_years << " years." << endl;
    cout << "Result: " << money_by_the_end << " pounds." << endl;
    return 0;
}


/* counting inflation each year without bonuses (percentages)
Initial investment: 1000 pounds.
Scope: 5 years.
Result: 6744 pounds.
*/

/* counting inflation each year with bonuses (percentages) !!most accurate one!! (?)
Initial investment: 1000 pounds.
Scope: 5 years.
Result: 6498 pounds.
*/

/* counting inflation each month
result_sum += investment_monthly - investment_monthly * inflation;
result_sum += result_sum * percent_from_gov - (result_sum * percent_from_gov * inflation) + result_sum * percent_per_year - result_sum * percent_per_year*inflation;

Initial investment: 1000 pounds.
Scope: 5 years.
Result: 7270 pounds.
*/