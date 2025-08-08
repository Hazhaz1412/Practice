#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> quicksort(const std::vector<int>& arr) {
    if (arr.size() <= 1)
        return arr;
    int pivot = arr[arr.size() / 2];
    std::vector<int> left, middle, right;
    for (int x : arr) {
        if (x < pivot)
            left.push_back(x);
        else if (x == pivot)
            middle.push_back(x);
        else
            right.push_back(x);
    }
    std::vector<int> sorted_left = quicksort(left);
    std::vector<int> sorted_right = quicksort(right);
    sorted_left.insert(sorted_left.end(), middle.begin(), middle.end());
    sorted_left.insert(sorted_left.end(), sorted_right.begin(), sorted_right.end());
    return sorted_left;
}

int main() {
    std::vector<int> a = {5, 2, 9, 1, 5, 6};
    std::vector<int> b = {3, 4, 7, 2, 8, 1};

    std::vector<int> sorted_a = quicksort(a);
    std::vector<int> sorted_b = quicksort(b);

    std::cout << "Sorted a:";
    for (int x : sorted_a) std::cout << " " << x;
    std::cout << std::endl;

    std::cout << "Sorted b:";
    for (int x : sorted_b) std::cout << " " << x;
    std::cout << std::endl;

    return 0;
}