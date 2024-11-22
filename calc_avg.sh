#!/bin/bash

# Define the data file and output file
DATA_FILE="processed_weather_data.txt"
AVERAGE_FILE="average.txt"

# Check if the data file exists and is not empty
if [ ! -f "$DATA_FILE" ] || [ ! -s "$DATA_FILE" ]; then
    echo "Error: $DATA_FILE does not exist or is empty."
    exit 1
fi

# Use awk to calculate averages, print to terminal, and write to average.txt
awk '
/Temperature:/ { temp_sum += $2; temp_count++ }
/Humidity:/ { hum_sum += $2; hum_count++ }
/Pressure:/ { pres_sum += $2; pres_count++ }
/Wind Speed:/ { wind_sum += $3; wind_count++ }
END {
    if (temp_count > 0) {
        printf "Average Temperature: %.1f\n", temp_sum / temp_count
    }
    if (hum_count > 0) {
        printf "Average Humidity: %.1f\n", hum_sum / hum_count
    }
    if (pres_count > 0) {
        printf "Average Pressure: %.1f\n", pres_sum / pres_count
    }
    if (wind_count > 0) {
        printf "Average Wind Speed: %.1f\n", wind_sum / wind_count
    }
}
' "$DATA_FILE" | tee "$AVERAGE_FILE"

# Check if the file was successfully written
if [ -s "$AVERAGE_FILE" ]; then
    echo "Averages written to $AVERAGE_FILE"
else
    echo "Error: Failed to write averages to $AVERAGE_FILE."
fi

