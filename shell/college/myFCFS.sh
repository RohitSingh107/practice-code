#!/bin/bash





# tat = ct - at
# wt = tat - bt

main(){
  
  at=()
  bt=()
  echo -n "Enter the number of processes: "
  read -r n
  # echo "num is $n"
  for ((i = 0; i < n; i++)){
    echo -n "Enter the aarival time of P$i: "
    read -r arrival
    echo -n "Enter burst time of P$i: "
    read -r burst

    at+=("$arrival")
    bt+=("$burst")
  }

  wt=()
  tat=()

  awt=0
  atat=0



  wt[0]=0
  for ((i = 1; i < n; i++)){
    wt[i]=$(( at[i-1] + wt[i-1] + bt[i-1] - at[i] ))
    # echo -e "wt[i] is ${wt[i]}"
    if ((wt[i] < 0)); then
      wt[i]=0
    fi
    awt=$((awt + wt[i]))
  }
  awt=$(echo "scale=2; $awt / $n" | bc -l)

  for ((i = 0; i < n; i++)); do
    tat[i]=$((bt[i] + wt[i]))
    atat=$((atat + tat[i]))
  done
  atat=$(echo "$atat / $n" | bc -l)

  echo -e "Average waiting time is $awt and average turnaround time is $atat"



  # echo -e "${wt[@]}"
  # echo -e "${tat[@]}"
  # echo -e "${at[@]}"
  # echo -e "${bt[@]}"
}


main
