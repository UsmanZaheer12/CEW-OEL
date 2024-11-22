#!/bin/bash

# File and threshold definitions
AVERAGE_FILE="average.txt"
LOW_TEMP_THRESHOLD=45.0
HIGH_TEMP_THRESHOLD=76.0
LOW_HUM_THRESHOLD=60.0
HIGH_HUM_THRESHOLD=80.0
LOW_PRESSURE_THRESHOLD=1010.0
HIGH_PRESSURE_THRESHOLD=1025.0
LOW_WIND_THRESHOLD=10.0
HIGH_WIND_THRESHOLD=20.0

# Check if the average file exists
if [ ! -f "$AVERAGE_FILE" ]; then
    echo "Error: $AVERAGE_FILE does not exist."
    exit 1
fi

# Extract average values from the file
AVG_TEMP=$(grep "Average Temperature:" "$AVERAGE_FILE" | awk '{print $3}')
AVG_HUM=$(grep "Average Humidity:" "$AVERAGE_FILE" | awk '{print $3}')
AVG_PRESSURE=$(grep "Average Pressure:" "$AVERAGE_FILE" | awk '{print $3}')
AVG_WIND=$(grep "Average Wind Speed:" "$AVERAGE_FILE" | awk '{print $4}')

# Function to trigger an alert (example: using notify-send)
trigger_alert() {
    MESSAGE=$1
    echo "$MESSAGE"  # Print the message to the terminal
    notify-send "Weather Alert" "$MESSAGE"  # For desktop notifications (Linux with GUI)
    # Uncomment below line to send an email (requires 'mail' or 'sendmail' setup)
    echo "$MESSAGE" | mail -s "Weather Alert" usmanzaheer177@gmail.com
}

# Check for low and high thresholds for each parameter and trigger alerts

# Temperature alerts
if (( $(echo "$AVG_TEMP <= $LOW_TEMP_THRESHOLD" | bc -l) )); then
    trigger_alert "Alert: Average Temperature is too low! ($AVG_TEMP ≤ $LOW_TEMP_THRESHOLD)"
fi

if (( $(echo "$AVG_TEMP >= $HIGH_TEMP_THRESHOLD" | bc -l) )); then
    trigger_alert "Alert: Average Temperature is too high! ($AVG_TEMP ≥ $HIGH_TEMP_THRESHOLD)"
fi

# Humidity alerts
if (( $(echo "$AVG_HUM <= $LOW_HUM_THRESHOLD" | bc -l) )); then
    trigger_alert "Alert: Average Humidity is too low! ($AVG_HUM ≤ $LOW_HUM_THRESHOLD)"
fi

if (( $(echo "$AVG_HUM >= $HIGH_HUM_THRESHOLD" | bc -l) )); then
    trigger_alert "Alert: Average Humidity is too high! ($AVG_HUM ≥ $HIGH_HUM_THRESHOLD)"
fi

# Pressure alerts
if (( $(echo "$AVG_PRESSURE <= $LOW_PRESSURE_THRESHOLD" | bc -l) )); then
    trigger_alert "Alert: Average Pressure is too low! ($AVG_PRESSURE ≤ $LOW_PRESSURE_THRESHOLD)"
fi

if (( $(echo "$AVG_PRESSURE >= $HIGH_PRESSURE_THRESHOLD" | bc -l) )); then
    trigger_alert "Alert: Average Pressure is too high! ($AVG_PRESSURE ≥ $HIGH_PRESSURE_THRESHOLD)"
fi

# Wind speed alerts
if (( $(echo "$AVG_WIND <= $LOW_WIND_THRESHOLD" | bc -l) )); then
    trigger_alert "Alert: Average Wind Speed is too low! ($AVG_WIND ≤ $LOW_WIND_THRESHOLD)"
fi

if (( $(echo "$AVG_WIND >= $HIGH_WIND_THRESHOLD" | bc -l) )); then
    trigger_alert "Alert: Average Wind Speed is too high! ($AVG_WIND ≥ $HIGH_WIND_THRESHOLD)"
fi
