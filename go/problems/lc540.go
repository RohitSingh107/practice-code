package main

import "fmt"

func singleNonDuplicate(nums []int) int {

  lo := 0
  hi := len(nums) - 2

  for lo <= hi {
    mid := (lo + hi) / 2
    // fmt.Println(mid)
    if nums[mid] == nums[mid ^ 1] { // Even -> Front, Odd -> Back
      lo = mid + 1
    } else {
      hi = mid - 1
    }
  }

  return nums[lo]
}

func main(){
  // nums := []int{1,1,2,3,3,4,4,8,8}
  nums := []int{3,3,7,7,10, 10,11}

  fmt.Printf("Ans is %v\n", singleNonDuplicate(nums))

}
