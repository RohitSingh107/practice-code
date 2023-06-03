#!/bin/bash

# Process information
processes=('P1' 'P2' 'P3' 'P4' 'P5')
arrival_time=(0 1 2 4 5)
burst_time=(3 8 6 4 2)

# Calculate the total number of processes
n=${#processes[@]}

# Initialize variables
current_time=0
waiting_time=0
turnaround_time=0

# Loop through all processes
for ((i=0; i<$n; i++)); do
  # Check if the process has arrived
  if ((current_time < ${arrival_time[$i]})); then
    current_time=${arrival_time[$i]}
  fi
  
  # Update waiting time and turnaround time
  waiting_time=$(($waiting_time + $current_time - ${arrival_time[$i]}))
  turnaround_time=$(($turnaround_time + $current_time + ${burst_time[$i]} - ${arrival_time[$i]}))
  
  # Update current time
  current_time=$(($current_time + ${burst_time[$i]}))
done

# Calculate average waiting time and turnaround time
avg_waiting_time=$(bc -l <<< "scale=2; $waiting_time / $n")
avg_turnaround_time=$(bc -l <<< "scale=2; $turnaround_time / $n")

# Print the results
echo "FCFS Scheduling Algorithm"
echo "-------------------------"
echo "Processes: ${processes[@]}"
echo "Arrival Time: ${arrival_time[@]}"
echo "Burst Time: ${burst_time[@]}"
echo "Average Waiting Time: $avg_waiting_time"
echo "Average Turnaround Time: $avg_turnaround_time"

