// Package main provides ...
package main

import "fmt"

func search(nums []int, target int) int {

  lo := 0
  hi := len(nums) - 1

  for lo <= hi {

    mid := (lo + hi) / 2

    if nums[lo] < nums[mid] {
      
      if nums[lo] <= target && target <= nums[mid] {
        hi = mid - 1
      } else {
        lo = mid + 1

      }

    } else {

      if nums[lo] <= target || target <= nums[mid] {
        hi = mid - 1
      } else {
        lo = mid + 1
      }

    }

  }

  // fmt.Println("lo is ", lo)

  if nums[lo] == target {
    return lo
  }

  return -1
    
}

func main() {

  nums := []int{5,6,7,8,9,0,1,3}
  target := 3

  fmt.Println("Ans is ", search(nums, target))

}
