#include <iostream>

using namespace std;

int CalculateInvestmentMonthly(int current_month) {
    int investment_monthly = 0;
    if (current_month > 12 && current_month <=24) {
        investment_monthly = 200;
        return investment_monthly;
    }
    if (current_month > 24) {
        investment_monthly = 333;
    }
    switch (current_month)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        investment_monthly = 50;
        break;
    case 6:
    case 7:
    case 8:
    case 9:
        investment_monthly = 70;
        break;
    case 10:
    case 11:
    case 12:
        investment_monthly = 100;
        break;
    default:
        break;
    }
    return investment_monthly;
}

int CalculateResultMoney(int current_month, int total_time_years, int investment_monthly, const int initial_sum,
    const double percent_from_gov, const double inflation, const double percent_per_year) {
    int result_sum = initial_sum;
    int investment_this_year = 0;
    for (int current_month_i = current_month; current_month_i <= total_time_years * 12; current_month_i++) //runs each month
    {
        if (investment_this_year > 4000 && current_month % 12 != 0) {
            continue;
        }
        investment_monthly = CalculateInvestmentMonthly(current_month_i);
        investment_this_year += investment_monthly;
        if (current_month_i % 12 == 0) {
            result_sum += investment_this_year + investment_this_year * percent_from_gov + investment_this_year * percent_per_year;
            investment_this_year = 0;
        }
    }
    result_sum -= result_sum * inflation;
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
    cout << "Current inv, month 2: " << CalculateInvestmentMonthly(2) << endl;
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

/* 
Initial investment: 1000 pounds.
Scope: 5 years.
Result: 7413 pounds.
*/

/* right investment per month
Initial investment: 1000 pounds.
Scope: 5 years.
Result: 32660 pounds.
*/

/* right investment per month and main function calcultions
Current inv, month 2: 50
Initial investment: 1000 pounds.
Scope: 5 years.
Result: 20124 pounds.
*/