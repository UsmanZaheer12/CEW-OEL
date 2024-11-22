#!/bin/bash

# Initialize the count variable
count=0

# Run the loop 5 times
while [ $count -lt 22 ]; do
    # Run your file (replace ./file2 with the correct file or command)
    ./fetch_weather.sh

    # Increment the count
    count=$((count + 1))
    
    # Optionally, print the current count
    echo "Run #$count completed"
done

