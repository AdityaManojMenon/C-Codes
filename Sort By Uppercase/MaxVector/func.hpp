#pragma once

#include <vector>
#include <algorithm>
#include <iterator>

template <typename T>
std::vector<T> MaxVector(std::vector<T> const & vec_a, std::vector<T> const & vec_b) {
    typename std::vector<T>::const_iterator safe_vec_a_end = vec_a.end();
    bool vec_a_is_as_long_as_b = static_cast<int>(vec_a.size()) >= static_cast<int>(vec_b.size());
    if (vec_a_is_as_long_as_b) {
        safe_vec_a_end = vec_a.begin() + vec_b.size();
    } 
    std::vector<T> result;
    std::transform(vec_a.begin(), safe_vec_a_end, vec_b.begin(), std::back_inserter(result), 
        [](T const & left, T const & right){return std::max(left, right);}
    );
    if (!vec_a_is_as_long_as_b) {
        std::copy(vec_b.begin() + vec_a.size(), vec_b.end(), std::back_inserter(result));
    } else {
        std::copy(safe_vec_a_end, vec_a.end(), std::back_inserter(result));
    }
    return result;
}