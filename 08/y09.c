float temperature_readings[30] [24], average_day_temp [30];
float sum_day_temp, sum_month_temp, average_month_temp;
int day, hour;

for (sum_month_temp = 0, day = 0; day < 30; day++) {
    for (sum_day_temp = 0, hour = 0; hour < 24; hour++) {
        sum_day_temp += temperature_readings[day] [hour];
    }
    sum_month_temp += sum_day_temp;
    average_day_temp [day] = sum_day_temp / 24;
}
average_month_temp = sum_day_temp / 30;
