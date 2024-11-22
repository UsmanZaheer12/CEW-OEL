#!/bin/bash

# Initialize the count variable
count=0

# Run the loop 5 times
while true; do
    ./fetch_weather.sh
    #sleep 60  #runs the code every 1 minute

    # Increment the count
    count=$((count + 1))
    
    # Optionally, print the current count
    echo "Run #$count completed"
done

