// There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
// Find the median of the two sorted arrays. The overall run time complexity
// should be O(log (m+n)).
//
// Example 1:
// nums1 = [1, 3]
// nums2 = [2]
// The median is 2.0
//
// Example 2:
// nums1 = [1, 2]
// nums2 = [3, 4]
// The median is (2 + 3)/2 = 2.5


#include <vector>
#include <iostream>


using namespace std;


class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //derp
    cout << nums1.size() << endl;
    return 0.0;
  }

  int binarySearch(vector<int>& nums) {

  }

}; // END OF CLASS


int main(int argc, char** argv)
{
  static const int arr1[] = {1, 2};
  vector<int> nums1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
  static const int arr2[] = {3, 4};
  vector<int> nums2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));

  Solution sol;
  double answer = sol.findMedianSortedArrays(nums1, nums2);
  cout << "answer = " << answer << endl;

  return 0;
}
