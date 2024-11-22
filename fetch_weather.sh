#!/bin/bash

# Define the file names
DATA_FILE="raw_data.txt"
AVERAGE_FILE="average.txt"
COUNT_FILE="count.txt"
PROCESSED_DATA_FILE="processed_weather_data.txt"

# Initialize or read the count of fetched data
if [ ! -f "$COUNT_FILE" ]; then
    echo 0 > "$COUNT_FILE"
fi
COUNT=$(<"$COUNT_FILE")

# Run the compiled C program to fetch data 
./file2 >> "$DATA_FILE"

# Increment the count
COUNT=$((COUNT + 1))
echo $COUNT > "$COUNT_FILE"

# If we've fetched data 10 times, calculate the average
if [ $COUNT -ge 10 ]; then
    # Calculate averages
    ./calc_avg.sh
    ./alert.sh
    #"$DATA_FILE" > "$AVERAGE_FILE"
    
    # Reset the data files and count
    echo 0 > "$COUNT_FILE"
    > "$DATA_FILE"  # Clear the raw_data.txt file
    > "$PROCESSED_DATA_FILE"
fi

