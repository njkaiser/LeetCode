// 3479. Fruits Into Baskets III
// You are given two arrays of integers, fruits and baskets, each of length n,
// where fruits[i] represents the quantity of the ith type of fruit, and
// baskets[j] represents the capacity of the jth basket.
//
// From left to right, place the fruits according to these rules:
//
// Each fruit type must be placed in the leftmost available basket with a
// capacity greater than or equal to the quantity of that fruit type.
// Each basket can hold only one type of fruit.
// If a fruit type cannot be placed in any basket, it remains unplaced.
// Return the number of fruit types that remain unplaced after all possible
// allocations are made.
// 
//
// Example 1:
//   Input: fruits = [4,2,5], baskets = [3,5,4]
//
//   Output: 1
//
//   Explanation:
//
//   fruits[0] = 4 is placed in baskets[1] = 5.
//   fruits[1] = 2 is placed in baskets[0] = 3.
//   fruits[2] = 5 cannot be placed in baskets[2] = 4.
//   Since one fruit type remains unplaced, we return 1.
//
// Example 2:
//   Input: fruits = [3,6,1], baskets = [6,4,7]
//
//   Output: 0
//
//   Explanation:
//
//   fruits[0] = 3 is placed in baskets[0] = 6.
//   fruits[1] = 6 cannot be placed in baskets[1] = 4 (insufficient capacity) but can be placed in the next available basket, baskets[2] = 7.
//   fruits[2] = 1 is placed in baskets[1] = 4.
//   Since all fruits are successfully placed, we return 0.
//  
//
// Constraints:
//  - n == fruits.length == baskets.length
//  - 1 <= n <= 105
//  - 1 <= fruits[i], baskets[i] <= 109

#include <iostream>
#include <vector>
//#include <list>
#include <algorithm>


class SegTree {
  private:
    inline void buildImpl(const int idx, const int lo, const int hi, const std::vector<int>& baskets) {
      if (lo == hi) {
        seg_tree[idx] = baskets[lo];
        return;
      }

      const int mid = (lo + hi) / 2;

      buildImpl(2 * idx + 1, lo,      mid, baskets);
      buildImpl(2 * idx + 2, mid + 1, hi,  baskets);

      seg_tree[idx] = std::max(seg_tree[2 * idx + 1], seg_tree[2 * idx + 2]);
    }

    inline int getImpl(const int idx, const int lo, const int hi, const int val) {
      if (seg_tree[idx] < val) {
        return -1;
      }
      if (lo == hi) {
        seg_tree[idx] = -1;
        return lo;
      }

      const int mid = (lo + hi) / 2;

      int pos;
      if (seg_tree[2 * idx + 1] >= val) {
        pos = getImpl(2 * idx + 1, lo,      mid, val);
      } else {
        pos = getImpl(2 * idx + 2, mid + 1, hi,  val);
      }

      seg_tree[idx] = std::max(seg_tree[2 * idx + 1], seg_tree[2 * idx + 2]);
      return pos;
    }

    std::vector<int> seg_tree{};
    int n;

  public:
    SegTree(const std::vector<int>& baskets) : n{static_cast<int>(baskets.size())} {
      seg_tree.resize(4 * n);
      buildImpl(0, 0, n - 1, baskets);
    }

    inline int get(const int val) {
      return getImpl(0, 0, n - 1, val);
    }
};


class Solution {
  public:
    // TRY 1, TOO SLOW:
    // int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
    //   // std::list<int> basket_list{baskets.begin(), baskets.end()};
    //   int num_unplaced_fruits = 0;
    //   for (const auto& f : fruits) {
    //     auto it = std::find_if(basket_list.begin(), basket_list.end(), [f](int b) { return b >= f; });
    //     if (it == basket_list.end()) {
    //     if (it == basket_list.end()) {
    //       ++num_unplaced_fruits;
    //     } else {
    //       basket_list.erase(it);
    //     }
    //   }
    //   return num_unplaced_fruits;
    // }

    // TRY 2, ALSO TOO SLOW:
    // int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
    //   std::vector<bool> used(baskets.size(), false);
    //   int first_unused = 0;
    //
    //   int num_unplaced_fruits = 0;
    //   for (const auto& f : fruits) {
    //     for (int i = first_unused; i < used.size()+1; ++i) {
    //       if (i == used.size()) {
    //         ++num_unplaced_fruits;
    //         break;
    //       }
    //
    //       if (baskets[i] >= f && used[i] == false) {
    //         used[i] = true;
    //         if (i == first_unused) {
    //           first_unused = i + 1;
    //           // const auto unused_it = std::find(used.cbegin() + first_unused, used.cend(), false);
    //           // first_unused = std::distance(used.cbegin(), unused_it);
    //         }
    //         break;
    //       }
    //     }
    //   }
    //
    //   return num_unplaced_fruits;
    // }

    int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
      SegTree seg_tree{baskets};

      int num_unplaced_fruits = 0;
      for (const auto& f : fruits) {
        if (seg_tree.get(f) == -1) {
          ++num_unplaced_fruits;
        }
      }
      return num_unplaced_fruits;
    }
};


int main(int argc, char** argv) {
  // std::vector<int> fruits{{4, 2, 5}};
  // std::vector<int> baskets{{3, 5, 4}};

  std::vector<int> fruits{{3, 6, 1}};
  std::vector<int> baskets{{6, 4, 7}};
  
  Solution s{};
  const auto answer = s.numOfUnplacedFruits(fruits, baskets);
  std::cout << "ANSWER: " << answer << std::endl;
  return 0;
}
