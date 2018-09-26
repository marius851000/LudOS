// -*- C++ -*-
//===-------------------------- algorithm ---------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP_ALGORITHM
#define _LIBCPP_ALGORITHM

/*
    algorithm synopsis

#include <initializer_list>

namespace std
{

template <class InputIterator, class Predicate>
    bool
    all_of(InputIterator first, InputIterator last, Predicate pred);

template <class InputIterator, class Predicate>
    bool
    any_of(InputIterator first, InputIterator last, Predicate pred);

template <class InputIterator, class Predicate>
    bool
    none_of(InputIterator first, InputIterator last, Predicate pred);

template <class InputIterator, class Function>
    Function
    for_each(InputIterator first, InputIterator last, Function f);

template<class InputIterator, class Size, class Function>
    InputIterator for_each_n(InputIterator first, Size n, Function f); // C++17

template <class InputIterator, class T>
    InputIterator
    find(InputIterator first, InputIterator last, const T& value);

template <class InputIterator, class Predicate>
    InputIterator
    find_if(InputIterator first, InputIterator last, Predicate pred);

template<class InputIterator, class Predicate>
    InputIterator
    find_if_not(InputIterator first, InputIterator last, Predicate pred);

template <class ForwardIterator1, class ForwardIterator2>
    ForwardIterator1
    find_end(ForwardIterator1 first1, ForwardIterator1 last1,
             ForwardIterator2 first2, ForwardIterator2 last2);

template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
    ForwardIterator1
    find_end(ForwardIterator1 first1, ForwardIterator1 last1,
             ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred);

template <class ForwardIterator1, class ForwardIterator2>
    ForwardIterator1
    find_first_of(ForwardIterator1 first1, ForwardIterator1 last1,
                  ForwardIterator2 first2, ForwardIterator2 last2);

template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
    ForwardIterator1
    find_first_of(ForwardIterator1 first1, ForwardIterator1 last1,
                  ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred);

template <class ForwardIterator>
    ForwardIterator
    adjacent_find(ForwardIterator first, ForwardIterator last);

template <class ForwardIterator, class BinaryPredicate>
    ForwardIterator
    adjacent_find(ForwardIterator first, ForwardIterator last, BinaryPredicate pred);

template <class InputIterator, class T>
    typename iterator_traits<InputIterator>::difference_type
    count(InputIterator first, InputIterator last, const T& value);

template <class InputIterator, class Predicate>
    typename iterator_traits<InputIterator>::difference_type
    count_if(InputIterator first, InputIterator last, Predicate pred);

template <class InputIterator1, class InputIterator2>
    pair<InputIterator1, InputIterator2>
    mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);

template <class InputIterator1, class InputIterator2>
    pair<InputIterator1, InputIterator2>
    mismatch(InputIterator1 first1, InputIterator1 last1,
             InputIterator2 first2, InputIterator2 last2); // **C++14**

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    pair<InputIterator1, InputIterator2>
    mismatch(InputIterator1 first1, InputIterator1 last1,
             InputIterator2 first2, BinaryPredicate pred);

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    pair<InputIterator1, InputIterator2>
    mismatch(InputIterator1 first1, InputIterator1 last1,
             InputIterator2 first2, InputIterator2 last2,
             BinaryPredicate pred); // **C++14**

template <class InputIterator1, class InputIterator2>
    bool
    equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);

template <class InputIterator1, class InputIterator2>
    bool
    equal(InputIterator1 first1, InputIterator1 last1,
          InputIterator2 first2, InputIterator2 last2); // **C++14**

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool
    equal(InputIterator1 first1, InputIterator1 last1,
          InputIterator2 first2, BinaryPredicate pred);

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool
    equal(InputIterator1 first1, InputIterator1 last1,
          InputIterator2 first2, InputIterator2 last2,
          BinaryPredicate pred); // **C++14**

template<class ForwardIterator1, class ForwardIterator2>
    bool
    is_permutation(ForwardIterator1 first1, ForwardIterator1 last1,
                   ForwardIterator2 first2);

template<class ForwardIterator1, class ForwardIterator2>
    bool
    is_permutation(ForwardIterator1 first1, ForwardIterator1 last1,
                   ForwardIterator2 first2, ForwardIterator2 last2); // **C++14**

template<class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
    bool
    is_permutation(ForwardIterator1 first1, ForwardIterator1 last1,
                   ForwardIterator2 first2, BinaryPredicate pred);

template<class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
    bool
    is_permutation(ForwardIterator1 first1, ForwardIterator1 last1,
                   ForwardIterator2 first2, ForwardIterator2 last2,
                   BinaryPredicate pred);  // **C++14**

template <class ForwardIterator1, class ForwardIterator2>
    ForwardIterator1
    search(ForwardIterator1 first1, ForwardIterator1 last1,
           ForwardIterator2 first2, ForwardIterator2 last2);

template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
    ForwardIterator1
    search(ForwardIterator1 first1, ForwardIterator1 last1,
           ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred);

template <class ForwardIterator, class Size, class T>
    ForwardIterator
    search_n(ForwardIterator first, ForwardIterator last, Size count, const T& value);

template <class ForwardIterator, class Size, class T, class BinaryPredicate>
    ForwardIterator
    search_n(ForwardIterator first, ForwardIterator last,
             Size count, const T& value, BinaryPredicate pred);

template <class InputIterator, class OutputIterator>
    OutputIterator
    copy(InputIterator first, InputIterator last, OutputIterator result);

template<class InputIterator, class OutputIterator, class Predicate>
    OutputIterator
    copy_if(InputIterator first, InputIterator last,
            OutputIterator result, Predicate pred);

template<class InputIterator, class Size, class OutputIterator>
    OutputIterator
    copy_n(InputIterator first, Size n, OutputIterator result);

template <class BidirectionalIterator1, class BidirectionalIterator2>
    BidirectionalIterator2
    copy_backward(BidirectionalIterator1 first, BidirectionalIterator1 last,
                  BidirectionalIterator2 result);

template <class ForwardIterator1, class ForwardIterator2>
    ForwardIterator2
    swap_ranges(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2);

template <class ForwardIterator1, class ForwardIterator2>
    void
    iter_swap(ForwardIterator1 a, ForwardIterator2 b);

template <class InputIterator, class OutputIterator, class UnaryOperation>
    OutputIterator
    transform(InputIterator first, InputIterator last, OutputIterator result, UnaryOperation op);

template <class InputIterator1, class InputIterator2, class OutputIterator, class BinaryOperation>
    OutputIterator
    transform(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
              OutputIterator result, BinaryOperation binary_op);

template <class ForwardIterator, class T>
    void
    replace(ForwardIterator first, ForwardIterator last, const T& old_value, const T& new_value);

template <class ForwardIterator, class Predicate, class T>
    void
    replace_if(ForwardIterator first, ForwardIterator last, Predicate pred, const T& new_value);

template <class InputIterator, class OutputIterator, class T>
    OutputIterator
    replace_copy(InputIterator first, InputIterator last, OutputIterator result,
                 const T& old_value, const T& new_value);

template <class InputIterator, class OutputIterator, class Predicate, class T>
    OutputIterator
    replace_copy_if(InputIterator first, InputIterator last, OutputIterator result, Predicate pred, const T& new_value);

template <class ForwardIterator, class T>
    void
    fill(ForwardIterator first, ForwardIterator last, const T& value);

template <class OutputIterator, class Size, class T>
    OutputIterator
    fill_n(OutputIterator first, Size n, const T& value);

template <class ForwardIterator, class Generator>
    void
    generate(ForwardIterator first, ForwardIterator last, Generator gen);

template <class OutputIterator, class Size, class Generator>
    OutputIterator
    generate_n(OutputIterator first, Size n, Generator gen);

template <class ForwardIterator, class T>
    ForwardIterator
    remove(ForwardIterator first, ForwardIterator last, const T& value);

template <class ForwardIterator, class Predicate>
    ForwardIterator
    remove_if(ForwardIterator first, ForwardIterator last, Predicate pred);

template <class InputIterator, class OutputIterator, class T>
    OutputIterator
    remove_copy(InputIterator first, InputIterator last, OutputIterator result, const T& value);

template <class InputIterator, class OutputIterator, class Predicate>
    OutputIterator
    remove_copy_if(InputIterator first, InputIterator last, OutputIterator result, Predicate pred);

template <class ForwardIterator>
    ForwardIterator
    unique(ForwardIterator first, ForwardIterator last);

template <class ForwardIterator, class BinaryPredicate>
    ForwardIterator
    unique(ForwardIterator first, ForwardIterator last, BinaryPredicate pred);

template <class InputIterator, class OutputIterator>
    OutputIterator
    unique_copy(InputIterator first, InputIterator last, OutputIterator result);

template <class InputIterator, class OutputIterator, class BinaryPredicate>
    OutputIterator
    unique_copy(InputIterator first, InputIterator last, OutputIterator result, BinaryPredicate pred);

template <class BidirectionalIterator>
    void
    reverse(BidirectionalIterator first, BidirectionalIterator last);

template <class BidirectionalIterator, class OutputIterator>
    OutputIterator
    reverse_copy(BidirectionalIterator first, BidirectionalIterator last, OutputIterator result);

template <class ForwardIterator>
    ForwardIterator
    rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last);

template <class ForwardIterator, class OutputIterator>
    OutputIterator
    rotate_copy(ForwardIterator first, ForwardIterator middle, ForwardIterator last, OutputIterator result);

template <class RandomAccessIterator>
    void
    random_shuffle(RandomAccessIterator first, RandomAccessIterator last); // deprecated in C++14, removed in C++17

template <class RandomAccessIterator, class RandomNumberGenerator>
    void
    random_shuffle(RandomAccessIterator first, RandomAccessIterator last,
                   RandomNumberGenerator& rand);  // deprecated in C++14, removed in C++17

template<class PopulationIterator, class SampleIterator,
         class Distance, class UniformRandomBitGenerator>
    SampleIterator sample(PopulationIterator first, PopulationIterator last,
                          SampleIterator out, Distance n,
                          UniformRandomBitGenerator&& g); // C++17

template<class RandomAccessIterator, class UniformRandomNumberGenerator>
    void shuffle(RandomAccessIterator first, RandomAccessIterator last,
                 UniformRandomNumberGenerator&& g);

template <class InputIterator, class Predicate>
    bool
    is_partitioned(InputIterator first, InputIterator last, Predicate pred);

template <class ForwardIterator, class Predicate>
    ForwardIterator
    partition(ForwardIterator first, ForwardIterator last, Predicate pred);

template <class InputIterator, class OutputIterator1,
          class OutputIterator2, class Predicate>
    pair<OutputIterator1, OutputIterator2>
    partition_copy(InputIterator first, InputIterator last,
                   OutputIterator1 out_true, OutputIterator2 out_false,
                   Predicate pred);

template <class ForwardIterator, class Predicate>
    ForwardIterator
    stable_partition(ForwardIterator first, ForwardIterator last, Predicate pred);

template<class ForwardIterator, class Predicate>
    ForwardIterator
    partition_point(ForwardIterator first, ForwardIterator last, Predicate pred);

template <class ForwardIterator>
    bool
    is_sorted(ForwardIterator first, ForwardIterator last);

template <class ForwardIterator, class Compare>
    bool
    is_sorted(ForwardIterator first, ForwardIterator last, Compare comp);

template<class ForwardIterator>
    ForwardIterator
    is_sorted_until(ForwardIterator first, ForwardIterator last);

template <class ForwardIterator, class Compare>
    ForwardIterator
    is_sorted_until(ForwardIterator first, ForwardIterator last, Compare comp);

template <class RandomAccessIterator>
    void
    sort(RandomAccessIterator first, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
    void
    sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

template <class RandomAccessIterator>
    void
    stable_sort(RandomAccessIterator first, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
    void
    stable_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

template <class RandomAccessIterator>
    void
    partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
    void
    partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last, Compare comp);

template <class InputIterator, class RandomAccessIterator>
    RandomAccessIterator
    partial_sort_copy(InputIterator first, InputIterator last,
                      RandomAccessIterator result_first, RandomAccessIterator result_last);

template <class InputIterator, class RandomAccessIterator, class Compare>
    RandomAccessIterator
    partial_sort_copy(InputIterator first, InputIterator last,
                      RandomAccessIterator result_first, RandomAccessIterator result_last, Compare comp);

template <class RandomAccessIterator>
    void
    nth_element(RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
    void
    nth_element(RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last, Compare comp);

template <class ForwardIterator, class T>
    ForwardIterator
    lower_bound(ForwardIterator first, ForwardIterator last, const T& value);

template <class ForwardIterator, class T, class Compare>
    ForwardIterator
    lower_bound(ForwardIterator first, ForwardIterator last, const T& value, Compare comp);

template <class ForwardIterator, class T>
    ForwardIterator
    upper_bound(ForwardIterator first, ForwardIterator last, const T& value);

template <class ForwardIterator, class T, class Compare>
    ForwardIterator
    upper_bound(ForwardIterator first, ForwardIterator last, const T& value, Compare comp);

template <class ForwardIterator, class T>
    pair<ForwardIterator, ForwardIterator>
    equal_range(ForwardIterator first, ForwardIterator last, const T& value);

template <class ForwardIterator, class T, class Compare>
    pair<ForwardIterator, ForwardIterator>
    equal_range(ForwardIterator first, ForwardIterator last, const T& value, Compare comp);

template <class ForwardIterator, class T>
    bool
    binary_search(ForwardIterator first, ForwardIterator last, const T& value);

template <class ForwardIterator, class T, class Compare>
    bool
    binary_search(ForwardIterator first, ForwardIterator last, const T& value, Compare comp);

template <class InputIterator1, class InputIterator2, class OutputIterator>
    OutputIterator
    merge(InputIterator1 first1, InputIterator1 last1,
          InputIterator2 first2, InputIterator2 last2, OutputIterator result);

template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
    OutputIterator
    merge(InputIterator1 first1, InputIterator1 last1,
          InputIterator2 first2, InputIterator2 last2, OutputIterator result, Compare comp);

template <class BidirectionalIterator>
    void
    inplace_merge(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last);

template <class BidirectionalIterator, class Compare>
    void
    inplace_merge(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last, Compare comp);

template <class InputIterator1, class InputIterator2>
    bool
    includes(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2);

template <class InputIterator1, class InputIterator2, class Compare>
    bool
    includes(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp);

template <class InputIterator1, class InputIterator2, class OutputIterator>
    OutputIterator
    set_union(InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2, InputIterator2 last2, OutputIterator result);

template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
    OutputIterator
    set_union(InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2, InputIterator2 last2, OutputIterator result, Compare comp);

template <class InputIterator1, class InputIterator2, class OutputIterator>
    OutputIterator
    set_intersection(InputIterator1 first1, InputIterator1 last1,
                     InputIterator2 first2, InputIterator2 last2, OutputIterator result);

template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
    OutputIterator
    set_intersection(InputIterator1 first1, InputIterator1 last1,
                     InputIterator2 first2, InputIterator2 last2, OutputIterator result, Compare comp);

template <class InputIterator1, class InputIterator2, class OutputIterator>
    OutputIterator
    set_difference(InputIterator1 first1, InputIterator1 last1,
                   InputIterator2 first2, InputIterator2 last2, OutputIterator result);

template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
    OutputIterator
    set_difference(InputIterator1 first1, InputIterator1 last1,
                   InputIterator2 first2, InputIterator2 last2, OutputIterator result, Compare comp);

template <class InputIterator1, class InputIterator2, class OutputIterator>
    OutputIterator
    set_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, InputIterator2 last2, OutputIterator result);

template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
    OutputIterator
    set_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, InputIterator2 last2, OutputIterator result, Compare comp);

template <class RandomAccessIterator>
    void
    push_heap(RandomAccessIterator first, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
    void
    push_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

template <class RandomAccessIterator>
    void
    pop_heap(RandomAccessIterator first, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
    void
    pop_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

template <class RandomAccessIterator>
    void
    make_heap(RandomAccessIterator first, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
    void
    make_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

template <class RandomAccessIterator>
    void
    sort_heap(RandomAccessIterator first, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
    void
    sort_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

template <class RandomAccessIterator>
    bool
    is_heap(RandomAccessIterator first, RandomAccessiterator last);

template <class RandomAccessIterator, class Compare>
    bool
    is_heap(RandomAccessIterator first, RandomAccessiterator last, Compare comp);

template <class RandomAccessIterator>
    RandomAccessIterator
    is_heap_until(RandomAccessIterator first, RandomAccessiterator last);

template <class RandomAccessIterator, class Compare>
    RandomAccessIterator
    is_heap_until(RandomAccessIterator first, RandomAccessiterator last, Compare comp);

template <class ForwardIterator>
    ForwardIterator
    min_element(ForwardIterator first, ForwardIterator last);  // constexpr in C++14

template <class ForwardIterator, class Compare>
    ForwardIterator
    min_element(ForwardIterator first, ForwardIterator last, Compare comp);  // constexpr in C++14

template <class T>
    const T&
    min(const T& a, const T& b);  // constexpr in C++14

template <class T, class Compare>
    const T&
    min(const T& a, const T& b, Compare comp);  // constexpr in C++14

template<class T>
    T
    min(initializer_list<T> t);  // constexpr in C++14

template<class T, class Compare>
    T
    min(initializer_list<T> t, Compare comp);  // constexpr in C++14

template<class T>
    constexpr const T& clamp( const T& v, const T& lo, const T& hi );               // C++17

template<class T, class Compare>
    constexpr const T& clamp( const T& v, const T& lo, const T& hi, Compare comp ); // C++17

template <class ForwardIterator>
    ForwardIterator
    max_element(ForwardIterator first, ForwardIterator last);  // constexpr in C++14

template <class ForwardIterator, class Compare>
    ForwardIterator
    max_element(ForwardIterator first, ForwardIterator last, Compare comp);  // constexpr in C++14

template <class T>
    const T&
    max(const T& a, const T& b); // constexpr in C++14

template <class T, class Compare>
    const T&
    max(const T& a, const T& b, Compare comp);  // constexpr in C++14

template<class T>
    T
    max(initializer_list<T> t);  // constexpr in C++14

template<class T, class Compare>
    T
    max(initializer_list<T> t, Compare comp);  // constexpr in C++14

template<class ForwardIterator>
    pair<ForwardIterator, ForwardIterator>
    minmax_element(ForwardIterator first, ForwardIterator last);   // constexpr in C++14

template<class ForwardIterator, class Compare>
    pair<ForwardIterator, ForwardIterator>
    minmax_element(ForwardIterator first, ForwardIterator last, Compare comp);   // constexpr in C++14

template<class T>
    pair<const T&, const T&>
    minmax(const T& a, const T& b);  // constexpr in C++14

template<class T, class Compare>
    pair<const T&, const T&>
    minmax(const T& a, const T& b, Compare comp);  // constexpr in C++14

template<class T>
    pair<T, T>
    minmax(initializer_list<T> t);  // constexpr in C++14

template<class T, class Compare>
    pair<T, T>
    minmax(initializer_list<T> t, Compare comp);  // constexpr in C++14

template <class InputIterator1, class InputIterator2>
    bool
    lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2);

template <class InputIterator1, class InputIterator2, class Compare>
    bool
    lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                            InputIterator2 first2, InputIterator2 last2, Compare comp);

template <class BidirectionalIterator>
    bool
    next_permutation(BidirectionalIterator first, BidirectionalIterator last);

template <class BidirectionalIterator, class Compare>
    bool
    next_permutation(BidirectionalIterator first, BidirectionalIterator last, Compare comp);

template <class BidirectionalIterator>
    bool
    prev_permutation(BidirectionalIterator first, BidirectionalIterator last);

template <class BidirectionalIterator, class Compare>
    bool
    prev_permutation(BidirectionalIterator first, BidirectionalIterator last, Compare comp);

}  // std

*/

#include "__config.hpp"
#include "initializer_list.hpp"
#include "type_traits.hpp"
#include <string.h>
#include "utility.hpp" // needed to provide swap_ranges.
#include "memory.hpp"
#include "iterator.hpp"
#include <stddef.h>

#if defined(__IBMCPP__)
#include "support/ibm/support.h"
#endif
#if defined(_LIBCPP_COMPILER_MSVC)
#include <intrin.h>
#endif

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#pragma GCC system_header
#endif

_LIBCPP_PUSH_MACROS
#include "__undef_macros.hpp"


_LIBCPP_BEGIN_NAMESPACE_STD

// I'd like to replace these with _VSTD::equal_to<void>, but can't because:
//   * That only works with C++14 and later, and
//   * We haven't included <functional> here.
template <class _T1, class _T2 = _T1>
struct __equal_to
{
    _LIBCPP_INLINE_VISIBILITY bool operator()(const _T1& __x, const _T1& __y) const {return __x == __y;}
    _LIBCPP_INLINE_VISIBILITY bool operator()(const _T1& __x, const _T2& __y) const {return __x == __y;}
    _LIBCPP_INLINE_VISIBILITY bool operator()(const _T2& __x, const _T1& __y) const {return __x == __y;}
    _LIBCPP_INLINE_VISIBILITY bool operator()(const _T2& __x, const _T2& __y) const {return __x == __y;}
};

template <class _T1>
struct __equal_to<_T1, _T1>
{
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    bool operator()(const _T1& __x, const _T1& __y) const {return __x == __y;}
};

template <class _T1>
struct __equal_to<const _T1, _T1>
{
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    bool operator()(const _T1& __x, const _T1& __y) const {return __x == __y;}
};

template <class _T1>
struct __equal_to<_T1, const _T1>
{
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    bool operator()(const _T1& __x, const _T1& __y) const {return __x == __y;}
};

template <class _T1, class _T2 = _T1>
struct __less
{
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    bool operator()(const _T1& __x, const _T1& __y) const {return __x < __y;}

    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    bool operator()(const _T1& __x, const _T2& __y) const {return __x < __y;}

    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    bool operator()(const _T2& __x, const _T1& __y) const {return __x < __y;}

    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    bool operator()(const _T2& __x, const _T2& __y) const {return __x < __y;}
};

template <class _T1>
struct __less<_T1, _T1>
{
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    bool operator()(const _T1& __x, const _T1& __y) const {return __x < __y;}
};

template <class _T1>
struct __less<const _T1, _T1>
{
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    bool operator()(const _T1& __x, const _T1& __y) const {return __x < __y;}
};

template <class _T1>
struct __less<_T1, const _T1>
{
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    bool operator()(const _T1& __x, const _T1& __y) const {return __x < __y;}
};

template <class _Predicate>
class __invert // invert the sense of a comparison
{
private:
    _Predicate __p_;
public:
    _LIBCPP_INLINE_VISIBILITY __invert() {}

    _LIBCPP_INLINE_VISIBILITY
    explicit __invert(_Predicate __p) : __p_(__p) {}

    template <class _T1>
    _LIBCPP_INLINE_VISIBILITY
    bool operator()(const _T1& __x) {return !__p_(__x);}

    template <class _T1, class _T2>
    _LIBCPP_INLINE_VISIBILITY
    bool operator()(const _T1& __x, const _T2& __y) {return __p_(__y, __x);}
};

#ifdef _LIBCPP_DEBUG

template <class _Compare>
struct __debug_less
{
    _Compare __comp_;
    __debug_less(_Compare& __c) : __comp_(__c) {}

    template <class _Tp, class _Up>
    bool operator()(const _Tp& __x, const _Up& __y)
    {
        bool __r = __comp_(__x, __y);
        if (__r)
            __do_compare_assert(0, __y, __x);
        return __r;
    }

    template <class _LHS, class _RHS>
    inline _LIBCPP_INLINE_VISIBILITY
    decltype((void)_VSTD::declval<_Compare&>()(
        _VSTD::declval<_LHS const&>(), _VSTD::declval<_RHS const&>()))
    __do_compare_assert(int, _LHS const& __l, _RHS const& __r) {
        _LIBCPP_ASSERT(!__comp_(__l, __r),
            "Comparator does not induce a strict weak ordering");
    }

    template <class _LHS, class _RHS>
    inline _LIBCPP_INLINE_VISIBILITY
    void __do_compare_assert(long, _LHS const&, _RHS const&) {}
};

#endif  // _LIBCPP_DEBUG

// Precondition:  __x != 0
inline _LIBCPP_INLINE_VISIBILITY
unsigned __ctz(unsigned __x) {
#ifndef _LIBCPP_COMPILER_MSVC
    return static_cast<unsigned>(__builtin_ctz(__x));
#else
  static_assert(sizeof(unsigned) == sizeof(unsigned long), "");
  static_assert(sizeof(unsigned long) == 4, "");
  unsigned long where;
  // Search from LSB to MSB for first set bit.
  // Returns zero if no set bit is found.
  if (_BitScanForward(&where, mask))
    return where;
  return 32;
#endif
}

inline _LIBCPP_INLINE_VISIBILITY
unsigned long __ctz(unsigned long __x) {
#ifndef _LIBCPP_COMPILER_MSVC
    return static_cast<unsigned long>(__builtin_ctzl(__x));
#else
    static_assert(sizeof(unsigned long) == sizeof(unsigned), "");
    return __ctz(static_cast<unsigned>(__x));
#endif
}

inline _LIBCPP_INLINE_VISIBILITY
unsigned long long __ctz(unsigned long long __x) {
#ifndef _LIBCPP_COMPILER_MSVC
    return static_cast<unsigned long long>(__builtin_ctzll(__x));
#else
    unsigned long where;
// Search from LSB to MSB for first set bit.
// Returns zero if no set bit is found.
#if defined(_LIBCPP_HAS_BITSCAN64)
    (defined(_M_AMD64) || defined(__x86_64__))
  if (_BitScanForward64(&where, mask))
    return static_cast<int>(where);
#else
  // Win32 doesn't have _BitScanForward64 so emulate it with two 32 bit calls.
  // Scan the Low Word.
  if (_BitScanForward(&where, static_cast<unsigned long>(mask)))
    return where;
  // Scan the High Word.
  if (_BitScanForward(&where, static_cast<unsigned long>(mask >> 32)))
    return where + 32; // Create a bit offset from the LSB.
#endif
  return 64;
#endif // _LIBCPP_COMPILER_MSVC
}

// Precondition:  __x != 0
inline _LIBCPP_INLINE_VISIBILITY
unsigned __clz(unsigned __x) {
#ifndef _LIBCPP_COMPILER_MSVC
    return static_cast<unsigned>(__builtin_clz(__x));
#else
  static_assert(sizeof(unsigned) == sizeof(unsigned long), "");
  static_assert(sizeof(unsigned long) == 4, "");
  unsigned long where;
  // Search from LSB to MSB for first set bit.
  // Returns zero if no set bit is found.
  if (_BitScanReverse(&where, mask))
    return 31 - where;
  return 32; // Undefined Behavior.
#endif
}

inline _LIBCPP_INLINE_VISIBILITY
unsigned long __clz(unsigned long __x) {
#ifndef _LIBCPP_COMPILER_MSVC
    return static_cast<unsigned long>(__builtin_clzl (__x));
#else
    static_assert(sizeof(unsigned) == sizeof(unsigned long), "");
    return __clz(static_cast<unsigned>(__x));
#endif
}

inline _LIBCPP_INLINE_VISIBILITY
unsigned long long __clz(unsigned long long __x) {
#ifndef _LIBCPP_COMPILER_MSVC
    return static_cast<unsigned long long>(__builtin_clzll(__x));
#else
  unsigned long where;
// BitScanReverse scans from MSB to LSB for first set bit.
// Returns 0 if no set bit is found.
#if defined(_LIBCPP_HAS_BITSCAN64)
  if (_BitScanReverse64(&where, mask))
    return static_cast<int>(63 - where);
#else
  // Scan the high 32 bits.
  if (_BitScanReverse(&where, static_cast<unsigned long>(mask >> 32)))
    return 63 - (where + 32); // Create a bit offset from the MSB.
  // Scan the low 32 bits.
  if (_BitScanReverse(&where, static_cast<unsigned long>(mask)))
    return 63 - where;
#endif
  return 64; // Undefined Behavior.
#endif // _LIBCPP_COMPILER_MSVC
}

inline _LIBCPP_INLINE_VISIBILITY int __pop_count(unsigned __x) {
#ifndef _LIBCPP_COMPILER_MSVC
  return __builtin_popcount  (__x);
#else
  static_assert(sizeof(unsigned) == 4, "");
  return __popcnt(__x);
#endif
}

inline _LIBCPP_INLINE_VISIBILITY int __pop_count(unsigned long __x) {
#ifndef _LIBCPP_COMPILER_MSVC
  return __builtin_popcountl (__x);
#else
  static_assert(sizeof(unsigned long) == 4, "");
  return __popcnt(__x);
#endif
}

inline _LIBCPP_INLINE_VISIBILITY int __pop_count(unsigned long long __x) {
#ifndef _LIBCPP_COMPILER_MSVC
  return __builtin_popcountll(__x);
#else
  static_assert(sizeof(unsigned long long) == 8, "");
  return __popcnt64(__x);
#endif
}

// all_of

template <class _InputIterator, class _Predicate>
inline _LIBCPP_INLINE_VISIBILITY
bool
all_of(_InputIterator __first, _InputIterator __last, _Predicate __pred)
{
    for (; __first != __last; ++__first)
        if (!__pred(*__first))
            return false;
    return true;
}

// any_of

template <class _InputIterator, class _Predicate>
inline _LIBCPP_INLINE_VISIBILITY
bool
any_of(_InputIterator __first, _InputIterator __last, _Predicate __pred)
{
    for (; __first != __last; ++__first)
        if (__pred(*__first))
            return true;
    return false;
}

// none_of

template <class _InputIterator, class _Predicate>
inline _LIBCPP_INLINE_VISIBILITY
bool
none_of(_InputIterator __first, _InputIterator __last, _Predicate __pred)
{
    for (; __first != __last; ++__first)
        if (__pred(*__first))
            return false;
    return true;
}

// for_each

template <class _InputIterator, class _Function>
inline _LIBCPP_INLINE_VISIBILITY
_Function
for_each(_InputIterator __first, _InputIterator __last, _Function __f)
{
    for (; __first != __last; ++__first)
        __f(*__first);
    return __f;
}

#if _LIBCPP_STD_VER > 14
// for_each_n

template <class _InputIterator, class _Size, class _Function>
inline _LIBCPP_INLINE_VISIBILITY
_InputIterator
for_each_n(_InputIterator __first, _Size __orig_n, _Function __f)
{
    typedef decltype(__convert_to_integral(__orig_n)) _IntegralSize;
    _IntegralSize __n = __orig_n;
    while (__n > 0)
    {
         __f(*__first);
         ++__first;
         --__n;
    }
    return __first;
}
#endif

// find

template <class _InputIterator, class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
_InputIterator
find(_InputIterator __first, _InputIterator __last, const _Tp& __value_)
{
    for (; __first != __last; ++__first)
        if (*__first == __value_)
            break;
    return __first;
}

// find_if

template <class _InputIterator, class _Predicate>
inline _LIBCPP_INLINE_VISIBILITY
_InputIterator
find_if(_InputIterator __first, _InputIterator __last, _Predicate __pred)
{
    for (; __first != __last; ++__first)
        if (__pred(*__first))
            break;
    return __first;
}

// find_if_not

template<class _InputIterator, class _Predicate>
inline _LIBCPP_INLINE_VISIBILITY
_InputIterator
find_if_not(_InputIterator __first, _InputIterator __last, _Predicate __pred)
{
    for (; __first != __last; ++__first)
        if (!__pred(*__first))
            break;
    return __first;
}

// find_end

template <class _BinaryPredicate, class _ForwardIterator1, class _ForwardIterator2>
_ForwardIterator1
__find_end(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
           _ForwardIterator2 __first2, _ForwardIterator2 __last2, _BinaryPredicate __pred,
           forward_iterator_tag, forward_iterator_tag)
{
    // modeled after search algorithm
    _ForwardIterator1 __r = __last1;  // __last1 is the "default" answer
    if (__first2 == __last2)
        return __r;
    while (true)
    {
        while (true)
        {
            if (__first1 == __last1)         // if source exhausted return last correct answer
                return __r;                  //    (or __last1 if never found)
            if (__pred(*__first1, *__first2))
                break;
            ++__first1;
        }
        // *__first1 matches *__first2, now match elements after here
        _ForwardIterator1 __m1 = __first1;
        _ForwardIterator2 __m2 = __first2;
        while (true)
        {
            if (++__m2 == __last2)
            {                         // Pattern exhaused, record answer and search for another one
                __r = __first1;
                ++__first1;
                break;
            }
            if (++__m1 == __last1)     // Source exhausted, return last answer
                return __r;
            if (!__pred(*__m1, *__m2))  // mismatch, restart with a new __first
            {
                ++__first1;
                break;
            }  // else there is a match, check next elements
        }
    }
}

template <class _BinaryPredicate, class _BidirectionalIterator1, class _BidirectionalIterator2>
_BidirectionalIterator1
__find_end(_BidirectionalIterator1 __first1, _BidirectionalIterator1 __last1,
           _BidirectionalIterator2 __first2, _BidirectionalIterator2 __last2, _BinaryPredicate __pred,
           bidirectional_iterator_tag, bidirectional_iterator_tag)
{
    // modeled after search algorithm (in reverse)
    if (__first2 == __last2)
        return __last1;  // Everything matches an empty sequence
    _BidirectionalIterator1 __l1 = __last1;
    _BidirectionalIterator2 __l2 = __last2;
    --__l2;
    while (true)
    {
        // Find last element in sequence 1 that matchs *(__last2-1), with a mininum of loop checks
        while (true)
        {
            if (__first1 == __l1)  // return __last1 if no element matches *__first2
                return __last1;
            if (__pred(*--__l1, *__l2))
                break;
        }
        // *__l1 matches *__l2, now match elements before here
        _BidirectionalIterator1 __m1 = __l1;
        _BidirectionalIterator2 __m2 = __l2;
        while (true)
        {
            if (__m2 == __first2)  // If pattern exhausted, __m1 is the answer (works for 1 element pattern)
                return __m1;
            if (__m1 == __first1)  // Otherwise if source exhaused, pattern not found
                return __last1;
            if (!__pred(*--__m1, *--__m2))  // if there is a mismatch, restart with a new __l1
            {
                break;
            }  // else there is a match, check next elements
        }
    }
}

template <class _BinaryPredicate, class _RandomAccessIterator1, class _RandomAccessIterator2>
_LIBCPP_CONSTEXPR_AFTER_CXX11 _RandomAccessIterator1
__find_end(_RandomAccessIterator1 __first1, _RandomAccessIterator1 __last1,
           _RandomAccessIterator2 __first2, _RandomAccessIterator2 __last2, _BinaryPredicate __pred,
           random_access_iterator_tag, random_access_iterator_tag)
{
    // Take advantage of knowing source and pattern lengths.  Stop short when source is smaller than pattern
    typename iterator_traits<_RandomAccessIterator2>::difference_type __len2 = __last2 - __first2;
    if (__len2 == 0)
        return __last1;
    typename iterator_traits<_RandomAccessIterator1>::difference_type __len1 = __last1 - __first1;
    if (__len1 < __len2)
        return __last1;
    const _RandomAccessIterator1 __s = __first1 + (__len2 - 1);  // End of pattern match can't go before here
    _RandomAccessIterator1 __l1 = __last1;
    _RandomAccessIterator2 __l2 = __last2;
    --__l2;
    while (true)
    {
        while (true)
        {
            if (__s == __l1)
                return __last1;
            if (__pred(*--__l1, *__l2))
                break;
        }
        _RandomAccessIterator1 __m1 = __l1;
        _RandomAccessIterator2 __m2 = __l2;
        while (true)
        {
            if (__m2 == __first2)
                return __m1;
                                 // no need to check range on __m1 because __s guarantees we have enough source
            if (!__pred(*--__m1, *--__m2))
            {
                break;
            }
        }
    }
}

template <class _ForwardIterator1, class _ForwardIterator2, class _BinaryPredicate>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator1
find_end(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
         _ForwardIterator2 __first2, _ForwardIterator2 __last2, _BinaryPredicate __pred)
{
    return _VSTD::__find_end<typename add_lvalue_reference<_BinaryPredicate>::type>
                         (__first1, __last1, __first2, __last2, __pred,
                          typename iterator_traits<_ForwardIterator1>::iterator_category(),
                          typename iterator_traits<_ForwardIterator2>::iterator_category());
}

template <class _ForwardIterator1, class _ForwardIterator2>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator1
find_end(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
         _ForwardIterator2 __first2, _ForwardIterator2 __last2)
{
    typedef typename iterator_traits<_ForwardIterator1>::value_type __v1;
    typedef typename iterator_traits<_ForwardIterator2>::value_type __v2;
    return _VSTD::find_end(__first1, __last1, __first2, __last2, __equal_to<__v1, __v2>());
}

// find_first_of

template <class _ForwardIterator1, class _ForwardIterator2, class _BinaryPredicate>
_LIBCPP_CONSTEXPR_AFTER_CXX11 _ForwardIterator1
__find_first_of_ce(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
              _ForwardIterator2 __first2, _ForwardIterator2 __last2, _BinaryPredicate __pred)
{
    for (; __first1 != __last1; ++__first1)
        for (_ForwardIterator2 __j = __first2; __j != __last2; ++__j)
            if (__pred(*__first1, *__j))
                return __first1;
    return __last1;
}


template <class _ForwardIterator1, class _ForwardIterator2, class _BinaryPredicate>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator1
find_first_of(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
              _ForwardIterator2 __first2, _ForwardIterator2 __last2, _BinaryPredicate __pred)
{
    return _VSTD::__find_first_of_ce(__first1, __last1, __first2, __last2, __pred);
}

template <class _ForwardIterator1, class _ForwardIterator2>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator1
find_first_of(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
              _ForwardIterator2 __first2, _ForwardIterator2 __last2)
{
    typedef typename iterator_traits<_ForwardIterator1>::value_type __v1;
    typedef typename iterator_traits<_ForwardIterator2>::value_type __v2;
    return _VSTD::__find_first_of_ce(__first1, __last1, __first2, __last2, __equal_to<__v1, __v2>());
}

// adjacent_find

template <class _ForwardIterator, class _BinaryPredicate>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator
adjacent_find(_ForwardIterator __first, _ForwardIterator __last, _BinaryPredicate __pred)
{
    if (__first != __last)
    {
        _ForwardIterator __i = __first;
        while (++__i != __last)
        {
            if (__pred(*__first, *__i))
                return __first;
            __first = __i;
        }
    }
    return __last;
}

template <class _ForwardIterator>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator
adjacent_find(_ForwardIterator __first, _ForwardIterator __last)
{
    typedef typename iterator_traits<_ForwardIterator>::value_type __v;
    return _VSTD::adjacent_find(__first, __last, __equal_to<__v>());
}

// count

template <class _InputIterator, class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
typename iterator_traits<_InputIterator>::difference_type
count(_InputIterator __first, _InputIterator __last, const _Tp& __value_)
{
    typename iterator_traits<_InputIterator>::difference_type __r(0);
    for (; __first != __last; ++__first)
        if (*__first == __value_)
            ++__r;
    return __r;
}

// count_if

template <class _InputIterator, class _Predicate>
inline _LIBCPP_INLINE_VISIBILITY
typename iterator_traits<_InputIterator>::difference_type
count_if(_InputIterator __first, _InputIterator __last, _Predicate __pred)
{
    typename iterator_traits<_InputIterator>::difference_type __r(0);
    for (; __first != __last; ++__first)
        if (__pred(*__first))
            ++__r;
    return __r;
}

// mismatch

template <class _InputIterator1, class _InputIterator2, class _BinaryPredicate>
inline _LIBCPP_INLINE_VISIBILITY
pair<_InputIterator1, _InputIterator2>
mismatch(_InputIterator1 __first1, _InputIterator1 __last1,
         _InputIterator2 __first2, _BinaryPredicate __pred)
{
    for (; __first1 != __last1; ++__first1, (void) ++__first2)
        if (!__pred(*__first1, *__first2))
            break;
    return pair<_InputIterator1, _InputIterator2>(__first1, __first2);
}

template <class _InputIterator1, class _InputIterator2>
inline _LIBCPP_INLINE_VISIBILITY
pair<_InputIterator1, _InputIterator2>
mismatch(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2)
{
    typedef typename iterator_traits<_InputIterator1>::value_type __v1;
    typedef typename iterator_traits<_InputIterator2>::value_type __v2;
    return _VSTD::mismatch(__first1, __last1, __first2, __equal_to<__v1, __v2>());
}

#if _LIBCPP_STD_VER > 11
template <class _InputIterator1, class _InputIterator2, class _BinaryPredicate>
inline _LIBCPP_INLINE_VISIBILITY
pair<_InputIterator1, _InputIterator2>
mismatch(_InputIterator1 __first1, _InputIterator1 __last1,
         _InputIterator2 __first2, _InputIterator2 __last2,
         _BinaryPredicate __pred)
{
    for (; __first1 != __last1 && __first2 != __last2; ++__first1, (void) ++__first2)
        if (!__pred(*__first1, *__first2))
            break;
    return pair<_InputIterator1, _InputIterator2>(__first1, __first2);
}

template <class _InputIterator1, class _InputIterator2>
inline _LIBCPP_INLINE_VISIBILITY
pair<_InputIterator1, _InputIterator2>
mismatch(_InputIterator1 __first1, _InputIterator1 __last1,
         _InputIterator2 __first2, _InputIterator2 __last2)
{
    typedef typename iterator_traits<_InputIterator1>::value_type __v1;
    typedef typename iterator_traits<_InputIterator2>::value_type __v2;
    return _VSTD::mismatch(__first1, __last1, __first2, __last2, __equal_to<__v1, __v2>());
}
#endif

// equal

template <class _InputIterator1, class _InputIterator2, class _BinaryPredicate>
inline _LIBCPP_INLINE_VISIBILITY
bool
equal(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _BinaryPredicate __pred)
{
    for (; __first1 != __last1; ++__first1, (void) ++__first2)
        if (!__pred(*__first1, *__first2))
            return false;
    return true;
}

template <class _InputIterator1, class _InputIterator2>
inline _LIBCPP_INLINE_VISIBILITY
bool
equal(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2)
{
    typedef typename iterator_traits<_InputIterator1>::value_type __v1;
    typedef typename iterator_traits<_InputIterator2>::value_type __v2;
    return _VSTD::equal(__first1, __last1, __first2, __equal_to<__v1, __v2>());
}

#if _LIBCPP_STD_VER > 11
template <class _BinaryPredicate, class _InputIterator1, class _InputIterator2>
inline _LIBCPP_INLINE_VISIBILITY
bool
__equal(_InputIterator1 __first1, _InputIterator1 __last1,
        _InputIterator2 __first2, _InputIterator2 __last2, _BinaryPredicate __pred,
        input_iterator_tag, input_iterator_tag )
{
    for (; __first1 != __last1 && __first2 != __last2; ++__first1, (void) ++__first2)
        if (!__pred(*__first1, *__first2))
            return false;
    return __first1 == __last1 && __first2 == __last2;
}

template <class _BinaryPredicate, class _RandomAccessIterator1, class _RandomAccessIterator2>
inline _LIBCPP_INLINE_VISIBILITY
bool
__equal(_RandomAccessIterator1 __first1, _RandomAccessIterator1 __last1,
        _RandomAccessIterator2 __first2, _RandomAccessIterator2 __last2, _BinaryPredicate __pred,
      random_access_iterator_tag, random_access_iterator_tag )
{
    if ( _VSTD::distance(__first1, __last1) != _VSTD::distance(__first2, __last2))
        return false;
    return _VSTD::equal<_RandomAccessIterator1, _RandomAccessIterator2,
                        typename add_lvalue_reference<_BinaryPredicate>::type>
                       (__first1, __last1, __first2, __pred );
}

template <class _InputIterator1, class _InputIterator2, class _BinaryPredicate>
inline _LIBCPP_INLINE_VISIBILITY
bool
equal(_InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2, _BinaryPredicate __pred )
{
    return _VSTD::__equal<typename add_lvalue_reference<_BinaryPredicate>::type>
       (__first1, __last1, __first2, __last2, __pred,
        typename iterator_traits<_InputIterator1>::iterator_category(),
        typename iterator_traits<_InputIterator2>::iterator_category());
}

template <class _InputIterator1, class _InputIterator2>
inline _LIBCPP_INLINE_VISIBILITY
bool
equal(_InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2)
{
    typedef typename iterator_traits<_InputIterator1>::value_type __v1;
    typedef typename iterator_traits<_InputIterator2>::value_type __v2;
    return _VSTD::__equal(__first1, __last1, __first2, __last2, __equal_to<__v1, __v2>(),
        typename iterator_traits<_InputIterator1>::iterator_category(),
        typename iterator_traits<_InputIterator2>::iterator_category());
}
#endif

// is_permutation

template<class _ForwardIterator1, class _ForwardIterator2, class _BinaryPredicate>
bool
is_permutation(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
               _ForwardIterator2 __first2, _BinaryPredicate __pred)
{
    // shorten sequences as much as possible by lopping of any equal parts
    for (; __first1 != __last1; ++__first1, (void) ++__first2)
        if (!__pred(*__first1, *__first2))
            goto __not_done;
    return true;
__not_done:
    // __first1 != __last1 && *__first1 != *__first2
    typedef typename iterator_traits<_ForwardIterator1>::difference_type _D1;
    _D1 __l1 = _VSTD::distance(__first1, __last1);
    if (__l1 == _D1(1))
        return false;
    _ForwardIterator2 __last2 = _VSTD::next(__first2, __l1);
    // For each element in [f1, l1) see if there are the same number of
    //    equal elements in [f2, l2)
    for (_ForwardIterator1 __i = __first1; __i != __last1; ++__i)
    {
        // Have we already counted the number of *__i in [f1, l1)?
        for (_ForwardIterator1 __j = __first1; __j != __i; ++__j)
            if (__pred(*__j, *__i))
                goto __next_iter;
        {
            // Count number of *__i in [f2, l2)
            _D1 __c2 = 0;
            for (_ForwardIterator2 __j = __first2; __j != __last2; ++__j)
                if (__pred(*__i, *__j))
                    ++__c2;
            if (__c2 == 0)
                return false;
            // Count number of *__i in [__i, l1) (we can start with 1)
            _D1 __c1 = 1;
            for (_ForwardIterator1 __j = _VSTD::next(__i); __j != __last1; ++__j)
                if (__pred(*__i, *__j))
                    ++__c1;
            if (__c1 != __c2)
                return false;
        }
__next_iter:;
    }
    return true;
}

template<class _ForwardIterator1, class _ForwardIterator2>
inline _LIBCPP_INLINE_VISIBILITY
bool
is_permutation(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
               _ForwardIterator2 __first2)
{
    typedef typename iterator_traits<_ForwardIterator1>::value_type __v1;
    typedef typename iterator_traits<_ForwardIterator2>::value_type __v2;
    return _VSTD::is_permutation(__first1, __last1, __first2, __equal_to<__v1, __v2>());
}

#if _LIBCPP_STD_VER > 11
template<class _BinaryPredicate, class _ForwardIterator1, class _ForwardIterator2>
bool
__is_permutation(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
                 _ForwardIterator2 __first2, _ForwardIterator2 __last2,
                 _BinaryPredicate __pred,
                 forward_iterator_tag, forward_iterator_tag )
{
    // shorten sequences as much as possible by lopping of any equal parts
    for (; __first1 != __last1 && __first2 != __last2; ++__first1, (void) ++__first2)
        if (!__pred(*__first1, *__first2))
            goto __not_done;
    return __first1 == __last1 && __first2 == __last2;
__not_done:
    // __first1 != __last1 && __first2 != __last2 && *__first1 != *__first2
    typedef typename iterator_traits<_ForwardIterator1>::difference_type _D1;
    _D1 __l1 = _VSTD::distance(__first1, __last1);

    typedef typename iterator_traits<_ForwardIterator2>::difference_type _D2;
    _D2 __l2 = _VSTD::distance(__first2, __last2);
    if (__l1 != __l2)
        return false;

    // For each element in [f1, l1) see if there are the same number of
    //    equal elements in [f2, l2)
    for (_ForwardIterator1 __i = __first1; __i != __last1; ++__i)
    {
        // Have we already counted the number of *__i in [f1, l1)?
        for (_ForwardIterator1 __j = __first1; __j != __i; ++__j)
            if (__pred(*__j, *__i))
                goto __next_iter;
        {
            // Count number of *__i in [f2, l2)
            _D1 __c2 = 0;
            for (_ForwardIterator2 __j = __first2; __j != __last2; ++__j)
                if (__pred(*__i, *__j))
                    ++__c2;
            if (__c2 == 0)
                return false;
            // Count number of *__i in [__i, l1) (we can start with 1)
            _D1 __c1 = 1;
            for (_ForwardIterator1 __j = _VSTD::next(__i); __j != __last1; ++__j)
                if (__pred(*__i, *__j))
                    ++__c1;
            if (__c1 != __c2)
                return false;
        }
__next_iter:;
    }
    return true;
}

template<class _BinaryPredicate, class _RandomAccessIterator1, class _RandomAccessIterator2>
bool
__is_permutation(_RandomAccessIterator1 __first1, _RandomAccessIterator2 __last1,
               _RandomAccessIterator1 __first2, _RandomAccessIterator2 __last2,
               _BinaryPredicate __pred,
               random_access_iterator_tag, random_access_iterator_tag )
{
    if ( _VSTD::distance(__first1, __last1) != _VSTD::distance(__first2, __last2))
        return false;
    return _VSTD::is_permutation<_RandomAccessIterator1, _RandomAccessIterator2,
                                 typename add_lvalue_reference<_BinaryPredicate>::type>
                                (__first1, __last1, __first2, __pred );
}

template<class _ForwardIterator1, class _ForwardIterator2, class _BinaryPredicate>
inline _LIBCPP_INLINE_VISIBILITY
bool
is_permutation(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
               _ForwardIterator2 __first2, _ForwardIterator2 __last2,
               _BinaryPredicate __pred )
{
    return _VSTD::__is_permutation<typename add_lvalue_reference<_BinaryPredicate>::type>
       (__first1, __last1, __first2, __last2, __pred,
        typename iterator_traits<_ForwardIterator1>::iterator_category(),
        typename iterator_traits<_ForwardIterator2>::iterator_category());
}

template<class _ForwardIterator1, class _ForwardIterator2>
inline _LIBCPP_INLINE_VISIBILITY
bool
is_permutation(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
               _ForwardIterator2 __first2, _ForwardIterator2 __last2)
{
    typedef typename iterator_traits<_ForwardIterator1>::value_type __v1;
    typedef typename iterator_traits<_ForwardIterator2>::value_type __v2;
    return _VSTD::__is_permutation(__first1, __last1, __first2, __last2,
        __equal_to<__v1, __v2>(),
        typename iterator_traits<_ForwardIterator1>::iterator_category(),
        typename iterator_traits<_ForwardIterator2>::iterator_category());
}
#endif

// search

template <class _BinaryPredicate, class _ForwardIterator1, class _ForwardIterator2>
pair<_ForwardIterator1, _ForwardIterator1>
__search(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
         _ForwardIterator2 __first2, _ForwardIterator2 __last2, _BinaryPredicate __pred,
         forward_iterator_tag, forward_iterator_tag)
{
    if (__first2 == __last2)
        return make_pair(__first1, __first1);  // Everything matches an empty sequence
    while (true)
    {
        // Find first element in sequence 1 that matchs *__first2, with a mininum of loop checks
        while (true)
        {
            if (__first1 == __last1)  // return __last1 if no element matches *__first2
                return make_pair(__last1, __last1);
            if (__pred(*__first1, *__first2))
                break;
            ++__first1;
        }
        // *__first1 matches *__first2, now match elements after here
        _ForwardIterator1 __m1 = __first1;
        _ForwardIterator2 __m2 = __first2;
        while (true)
        {
            if (++__m2 == __last2)  // If pattern exhausted, __first1 is the answer (works for 1 element pattern)
                return make_pair(__first1, __m1);
            if (++__m1 == __last1)  // Otherwise if source exhaused, pattern not found
                return make_pair(__last1, __last1);
            if (!__pred(*__m1, *__m2))  // if there is a mismatch, restart with a new __first1
            {
                ++__first1;
                break;
            }  // else there is a match, check next elements
        }
    }
}

template <class _BinaryPredicate, class _RandomAccessIterator1, class _RandomAccessIterator2>
_LIBCPP_CONSTEXPR_AFTER_CXX11
pair<_RandomAccessIterator1, _RandomAccessIterator1>
__search(_RandomAccessIterator1 __first1, _RandomAccessIterator1 __last1,
         _RandomAccessIterator2 __first2, _RandomAccessIterator2 __last2, _BinaryPredicate __pred,
           random_access_iterator_tag, random_access_iterator_tag)
{
    typedef typename iterator_traits<_RandomAccessIterator1>::difference_type _D1;
    typedef typename iterator_traits<_RandomAccessIterator2>::difference_type _D2;
    // Take advantage of knowing source and pattern lengths.  Stop short when source is smaller than pattern
    const _D2 __len2 = __last2 - __first2;
    if (__len2 == 0)
        return make_pair(__first1, __first1);
    const _D1 __len1 = __last1 - __first1;
    if (__len1 < __len2)
        return make_pair(__last1, __last1);
    const _RandomAccessIterator1 __s = __last1 - (__len2 - 1);  // Start of pattern match can't go beyond here

    while (true)
    {
        while (true)
        {
            if (__first1 == __s)
                return make_pair(__last1, __last1);
            if (__pred(*__first1, *__first2))
                break;
            ++__first1;
        }

        _RandomAccessIterator1 __m1 = __first1;
        _RandomAccessIterator2 __m2 = __first2;
         while (true)
         {
             if (++__m2 == __last2)
                 return make_pair(__first1, __first1 + __len2);
             ++__m1;          // no need to check range on __m1 because __s guarantees we have enough source
             if (!__pred(*__m1, *__m2))
             {
                 ++__first1;
                 break;
             }
         }
    }
}

template <class _ForwardIterator1, class _ForwardIterator2, class _BinaryPredicate>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator1
search(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
       _ForwardIterator2 __first2, _ForwardIterator2 __last2, _BinaryPredicate __pred)
{
    return _VSTD::__search<typename add_lvalue_reference<_BinaryPredicate>::type>
                         (__first1, __last1, __first2, __last2, __pred,
                          typename iterator_traits<_ForwardIterator1>::iterator_category(),
                          typename iterator_traits<_ForwardIterator2>::iterator_category())
            .first;
}

template <class _ForwardIterator1, class _ForwardIterator2>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator1
search(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
       _ForwardIterator2 __first2, _ForwardIterator2 __last2)
{
    typedef typename iterator_traits<_ForwardIterator1>::value_type __v1;
    typedef typename iterator_traits<_ForwardIterator2>::value_type __v2;
    return _VSTD::search(__first1, __last1, __first2, __last2, __equal_to<__v1, __v2>());
}

// search_n

template <class _BinaryPredicate, class _ForwardIterator, class _Size, class _Tp>
_ForwardIterator
__search_n(_ForwardIterator __first, _ForwardIterator __last,
           _Size __count, const _Tp& __value_, _BinaryPredicate __pred, forward_iterator_tag)
{
    if (__count <= 0)
        return __first;
    while (true)
    {
        // Find first element in sequence that matchs __value_, with a mininum of loop checks
        while (true)
        {
            if (__first == __last)  // return __last if no element matches __value_
                return __last;
            if (__pred(*__first, __value_))
                break;
            ++__first;
        }
        // *__first matches __value_, now match elements after here
        _ForwardIterator __m = __first;
        _Size __c(0);
        while (true)
        {
            if (++__c == __count)  // If pattern exhausted, __first is the answer (works for 1 element pattern)
                return __first;
            if (++__m == __last)  // Otherwise if source exhaused, pattern not found
                return __last;
            if (!__pred(*__m, __value_))  // if there is a mismatch, restart with a new __first
            {
                __first = __m;
                ++__first;
                break;
            }  // else there is a match, check next elements
        }
    }
}

template <class _BinaryPredicate, class _RandomAccessIterator, class _Size, class _Tp>
_RandomAccessIterator
__search_n(_RandomAccessIterator __first, _RandomAccessIterator __last,
           _Size __count, const _Tp& __value_, _BinaryPredicate __pred, random_access_iterator_tag)
{
    if (__count <= 0)
        return __first;
    _Size __len = static_cast<_Size>(__last - __first);
    if (__len < __count)
        return __last;
    const _RandomAccessIterator __s = __last - (__count - 1);  // Start of pattern match can't go beyond here
    while (true)
    {
        // Find first element in sequence that matchs __value_, with a mininum of loop checks
        while (true)
        {
            if (__first >= __s)  // return __last if no element matches __value_
                return __last;
            if (__pred(*__first, __value_))
                break;
            ++__first;
        }
        // *__first matches __value_, now match elements after here
        _RandomAccessIterator __m = __first;
        _Size __c(0);
        while (true)
        {
            if (++__c == __count)  // If pattern exhausted, __first is the answer (works for 1 element pattern)
                return __first;
             ++__m;          // no need to check range on __m because __s guarantees we have enough source
            if (!__pred(*__m, __value_))  // if there is a mismatch, restart with a new __first
            {
                __first = __m;
                ++__first;
                break;
            }  // else there is a match, check next elements
        }
    }
}

template <class _ForwardIterator, class _Size, class _Tp, class _BinaryPredicate>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator
search_n(_ForwardIterator __first, _ForwardIterator __last,
         _Size __count, const _Tp& __value_, _BinaryPredicate __pred)
{
    return _VSTD::__search_n<typename add_lvalue_reference<_BinaryPredicate>::type>
           (__first, __last, __convert_to_integral(__count), __value_, __pred,
           typename iterator_traits<_ForwardIterator>::iterator_category());
}

template <class _ForwardIterator, class _Size, class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator
search_n(_ForwardIterator __first, _ForwardIterator __last, _Size __count, const _Tp& __value_)
{
    typedef typename iterator_traits<_ForwardIterator>::value_type __v;
    return _VSTD::search_n(__first, __last, __convert_to_integral(__count),
                           __value_, __equal_to<__v, _Tp>());
}

// copy
template <class _Iter>
inline _LIBCPP_INLINE_VISIBILITY
_Iter
__unwrap_iter(_Iter __i)
{
    return __i;
}

template <class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
typename enable_if
<
    is_trivially_copy_assignable<_Tp>::value,
    _Tp*
>::type
__unwrap_iter(move_iterator<_Tp*> __i)
{
    return __i.base();
}

#if _LIBCPP_DEBUG_LEVEL < 2

template <class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
typename enable_if
<
    is_trivially_copy_assignable<_Tp>::value,
    _Tp*
>::type
__unwrap_iter(__wrap_iter<_Tp*> __i)
{
    return __i.base();
}

#else

template <class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
typename enable_if
<
    is_trivially_copy_assignable<_Tp>::value,
    __wrap_iter<_Tp*>
>::type
__unwrap_iter(__wrap_iter<_Tp*> __i)
{
    return __i;
}

#endif  // _LIBCPP_DEBUG_LEVEL < 2

template <class _InputIterator, class _OutputIterator>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
__copy(_InputIterator __first, _InputIterator __last, _OutputIterator __result)
{
    for (; __first != __last; ++__first, (void) ++__result)
        *__result = *__first;
    return __result;
}

template <class _Tp, class _Up>
inline _LIBCPP_INLINE_VISIBILITY
typename enable_if
<
    is_same<typename remove_const<_Tp>::type, _Up>::value &&
    is_trivially_copy_assignable<_Up>::value,
    _Up*
>::type
__copy(_Tp* __first, _Tp* __last, _Up* __result)
{
    const size_t __n = static_cast<size_t>(__last - __first);
    if (__n > 0)
        memmove(__result, __first, __n * sizeof(_Up));
    return __result + __n;
}

template <class _InputIterator, class _OutputIterator>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
copy(_InputIterator __first, _InputIterator __last, _OutputIterator __result)
{
    return _VSTD::__copy(__unwrap_iter(__first), __unwrap_iter(__last), __unwrap_iter(__result));
}

// copy_backward

template <class _BidirectionalIterator, class _OutputIterator>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
__copy_backward(_BidirectionalIterator __first, _BidirectionalIterator __last, _OutputIterator __result)
{
    while (__first != __last)
        *--__result = *--__last;
    return __result;
}

template <class _Tp, class _Up>
inline _LIBCPP_INLINE_VISIBILITY
typename enable_if
<
    is_same<typename remove_const<_Tp>::type, _Up>::value &&
    is_trivially_copy_assignable<_Up>::value,
    _Up*
>::type
__copy_backward(_Tp* __first, _Tp* __last, _Up* __result)
{
    const size_t __n = static_cast<size_t>(__last - __first);
    if (__n > 0)
    {
        __result -= __n;
        memmove(__result, __first, __n * sizeof(_Up));
    }
    return __result;
}

template <class _BidirectionalIterator1, class _BidirectionalIterator2>
inline _LIBCPP_INLINE_VISIBILITY
_BidirectionalIterator2
copy_backward(_BidirectionalIterator1 __first, _BidirectionalIterator1 __last,
              _BidirectionalIterator2 __result)
{
    return _VSTD::__copy_backward(__unwrap_iter(__first),
                                  __unwrap_iter(__last),
                                  __unwrap_iter(__result));
}

// copy_if

template<class _InputIterator, class _OutputIterator, class _Predicate>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
copy_if(_InputIterator __first, _InputIterator __last,
        _OutputIterator __result, _Predicate __pred)
{
    for (; __first != __last; ++__first)
    {
        if (__pred(*__first))
        {
            *__result = *__first;
            ++__result;
        }
    }
    return __result;
}

// copy_n

template<class _InputIterator, class _Size, class _OutputIterator>
inline _LIBCPP_INLINE_VISIBILITY
typename enable_if
<
    __is_input_iterator<_InputIterator>::value &&
   !__is_random_access_iterator<_InputIterator>::value,
    _OutputIterator
>::type
copy_n(_InputIterator __first, _Size __orig_n, _OutputIterator __result)
{
    typedef decltype(__convert_to_integral(__orig_n)) _IntegralSize;
    _IntegralSize __n = __orig_n;
    if (__n > 0)
    {
        *__result = *__first;
        ++__result;
        for (--__n; __n > 0; --__n)
        {
            ++__first;
            *__result = *__first;
            ++__result;
        }
    }
    return __result;
}

template<class _InputIterator, class _Size, class _OutputIterator>
inline _LIBCPP_INLINE_VISIBILITY
typename enable_if
<
    __is_random_access_iterator<_InputIterator>::value,
    _OutputIterator
>::type
copy_n(_InputIterator __first, _Size __orig_n, _OutputIterator __result)
{
    typedef decltype(__convert_to_integral(__orig_n)) _IntegralSize;
    _IntegralSize __n = __orig_n;
    return _VSTD::copy(__first, __first + __n, __result);
}

// move

template <class _InputIterator, class _OutputIterator>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
__move(_InputIterator __first, _InputIterator __last, _OutputIterator __result)
{
    for (; __first != __last; ++__first, (void) ++__result)
        *__result = _VSTD::move(*__first);
    return __result;
}

template <class _Tp, class _Up>
inline _LIBCPP_INLINE_VISIBILITY
typename enable_if
<
    is_same<typename remove_const<_Tp>::type, _Up>::value &&
    is_trivially_copy_assignable<_Up>::value,
    _Up*
>::type
__move(_Tp* __first, _Tp* __last, _Up* __result)
{
    const size_t __n = static_cast<size_t>(__last - __first);
    if (__n > 0)
        memmove(__result, __first, __n * sizeof(_Up));
    return __result + __n;
}

template <class _InputIterator, class _OutputIterator>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
move(_InputIterator __first, _InputIterator __last, _OutputIterator __result)
{
    return _VSTD::__move(__unwrap_iter(__first), __unwrap_iter(__last), __unwrap_iter(__result));
}

// move_backward

template <class _InputIterator, class _OutputIterator>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
__move_backward(_InputIterator __first, _InputIterator __last, _OutputIterator __result)
{
    while (__first != __last)
        *--__result = _VSTD::move(*--__last);
    return __result;
}

template <class _Tp, class _Up>
inline _LIBCPP_INLINE_VISIBILITY
typename enable_if
<
    is_same<typename remove_const<_Tp>::type, _Up>::value &&
    is_trivially_copy_assignable<_Up>::value,
    _Up*
>::type
__move_backward(_Tp* __first, _Tp* __last, _Up* __result)
{
    const size_t __n = static_cast<size_t>(__last - __first);
    if (__n > 0)
    {
        __result -= __n;
        memmove(__result, __first, __n * sizeof(_Up));
    }
    return __result;
}

template <class _BidirectionalIterator1, class _BidirectionalIterator2>
inline _LIBCPP_INLINE_VISIBILITY
_BidirectionalIterator2
move_backward(_BidirectionalIterator1 __first, _BidirectionalIterator1 __last,
              _BidirectionalIterator2 __result)
{
    return _VSTD::__move_backward(__unwrap_iter(__first), __unwrap_iter(__last), __unwrap_iter(__result));
}

// iter_swap

// moved to <type_traits> for better swap / noexcept support

// transform

template <class _InputIterator, class _OutputIterator, class _UnaryOperation>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
transform(_InputIterator __first, _InputIterator __last, _OutputIterator __result, _UnaryOperation __op)
{
    for (; __first != __last; ++__first, (void) ++__result)
        *__result = __op(*__first);
    return __result;
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator, class _BinaryOperation>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
transform(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2,
          _OutputIterator __result, _BinaryOperation __binary_op)
{
    for (; __first1 != __last1; ++__first1, (void) ++__first2, ++__result)
        *__result = __binary_op(*__first1, *__first2);
    return __result;
}

// replace

template <class _ForwardIterator, class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
void
replace(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __old_value, const _Tp& __new_value)
{
    for (; __first != __last; ++__first)
        if (*__first == __old_value)
            *__first = __new_value;
}

// replace_if

template <class _ForwardIterator, class _Predicate, class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
void
replace_if(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred, const _Tp& __new_value)
{
    for (; __first != __last; ++__first)
        if (__pred(*__first))
            *__first = __new_value;
}

// replace_copy

template <class _InputIterator, class _OutputIterator, class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
replace_copy(_InputIterator __first, _InputIterator __last, _OutputIterator __result,
             const _Tp& __old_value, const _Tp& __new_value)
{
    for (; __first != __last; ++__first, (void) ++__result)
        if (*__first == __old_value)
            *__result = __new_value;
        else
            *__result = *__first;
    return __result;
}

// replace_copy_if

template <class _InputIterator, class _OutputIterator, class _Predicate, class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
replace_copy_if(_InputIterator __first, _InputIterator __last, _OutputIterator __result,
                _Predicate __pred, const _Tp& __new_value)
{
    for (; __first != __last; ++__first, (void) ++__result)
        if (__pred(*__first))
            *__result = __new_value;
        else
            *__result = *__first;
    return __result;
}

// fill_n

template <class _OutputIterator, class _Size, class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
__fill_n(_OutputIterator __first, _Size __n, const _Tp& __value_)
{
    for (; __n > 0; ++__first, (void) --__n)
        *__first = __value_;
    return __first;
}

template <class _Tp, class _Size, class _Up>
inline _LIBCPP_INLINE_VISIBILITY
typename enable_if
<
    is_integral<_Tp>::value && sizeof(_Tp) == 1 &&
    !is_same<_Tp, bool>::value &&
    is_integral<_Up>::value && sizeof(_Up) == 1,
    _Tp*
>::type
__fill_n(_Tp* __first, _Size __n,_Up __value_)
{
    if (__n > 0)
        memset(__first, (unsigned char)__value_, (size_t)(__n));
    return __first + __n;
}

template <class _OutputIterator, class _Size, class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
fill_n(_OutputIterator __first, _Size __n, const _Tp& __value_)
{
   return _VSTD::__fill_n(__first, __convert_to_integral(__n), __value_);
}

// fill

template <class _ForwardIterator, class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
void
__fill(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_, forward_iterator_tag)
{
    for (; __first != __last; ++__first)
        *__first = __value_;
}

template <class _RandomAccessIterator, class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
void
__fill(_RandomAccessIterator __first, _RandomAccessIterator __last, const _Tp& __value_, random_access_iterator_tag)
{
    _VSTD::fill_n(__first, __last - __first, __value_);
}

template <class _ForwardIterator, class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
void
fill(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_)
{
    _VSTD::__fill(__first, __last, __value_, typename iterator_traits<_ForwardIterator>::iterator_category());
}

// generate

template <class _ForwardIterator, class _Generator>
inline _LIBCPP_INLINE_VISIBILITY
void
generate(_ForwardIterator __first, _ForwardIterator __last, _Generator __gen)
{
    for (; __first != __last; ++__first)
        *__first = __gen();
}

// generate_n

template <class _OutputIterator, class _Size, class _Generator>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
generate_n(_OutputIterator __first, _Size __orig_n, _Generator __gen)
{
    typedef decltype(__convert_to_integral(__orig_n)) _IntegralSize;
    _IntegralSize __n = __orig_n;
    for (; __n > 0; ++__first, (void) --__n)
        *__first = __gen();
    return __first;
}

// remove

template <class _ForwardIterator, class _Tp>
_ForwardIterator
remove(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_)
{
    __first = _VSTD::find(__first, __last, __value_);
    if (__first != __last)
    {
        _ForwardIterator __i = __first;
        while (++__i != __last)
        {
            if (!(*__i == __value_))
            {
                *__first = _VSTD::move(*__i);
                ++__first;
            }
        }
    }
    return __first;
}

// remove_if

template <class _ForwardIterator, class _Predicate>
_ForwardIterator
remove_if(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred)
{
    __first = _VSTD::find_if<_ForwardIterator, typename add_lvalue_reference<_Predicate>::type>
                           (__first, __last, __pred);
    if (__first != __last)
    {
        _ForwardIterator __i = __first;
        while (++__i != __last)
        {
            if (!__pred(*__i))
            {
                *__first = _VSTD::move(*__i);
                ++__first;
            }
        }
    }
    return __first;
}

// remove_copy

template <class _InputIterator, class _OutputIterator, class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
remove_copy(_InputIterator __first, _InputIterator __last, _OutputIterator __result, const _Tp& __value_)
{
    for (; __first != __last; ++__first)
    {
        if (!(*__first == __value_))
        {
            *__result = *__first;
            ++__result;
        }
    }
    return __result;
}

// remove_copy_if

template <class _InputIterator, class _OutputIterator, class _Predicate>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
remove_copy_if(_InputIterator __first, _InputIterator __last, _OutputIterator __result, _Predicate __pred)
{
    for (; __first != __last; ++__first)
    {
        if (!__pred(*__first))
        {
            *__result = *__first;
            ++__result;
        }
    }
    return __result;
}

// unique

template <class _ForwardIterator, class _BinaryPredicate>
_ForwardIterator
unique(_ForwardIterator __first, _ForwardIterator __last, _BinaryPredicate __pred)
{
    __first = _VSTD::adjacent_find<_ForwardIterator, typename add_lvalue_reference<_BinaryPredicate>::type>
                                 (__first, __last, __pred);
    if (__first != __last)
    {
        // ...  a  a  ?  ...
        //      f     i
        _ForwardIterator __i = __first;
        for (++__i; ++__i != __last;)
            if (!__pred(*__first, *__i))
                *++__first = _VSTD::move(*__i);
        ++__first;
    }
    return __first;
}

template <class _ForwardIterator>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator
unique(_ForwardIterator __first, _ForwardIterator __last)
{
    typedef typename iterator_traits<_ForwardIterator>::value_type __v;
    return _VSTD::unique(__first, __last, __equal_to<__v>());
}

// unique_copy

template <class _BinaryPredicate, class _InputIterator, class _OutputIterator>
_OutputIterator
__unique_copy(_InputIterator __first, _InputIterator __last, _OutputIterator __result, _BinaryPredicate __pred,
              input_iterator_tag, output_iterator_tag)
{
    if (__first != __last)
    {
        typename iterator_traits<_InputIterator>::value_type __t(*__first);
        *__result = __t;
        ++__result;
        while (++__first != __last)
        {
            if (!__pred(__t, *__first))
            {
                __t = *__first;
                *__result = __t;
                ++__result;
            }
        }
    }
    return __result;
}

template <class _BinaryPredicate, class _ForwardIterator, class _OutputIterator>
_OutputIterator
__unique_copy(_ForwardIterator __first, _ForwardIterator __last, _OutputIterator __result, _BinaryPredicate __pred,
              forward_iterator_tag, output_iterator_tag)
{
    if (__first != __last)
    {
        _ForwardIterator __i = __first;
        *__result = *__i;
        ++__result;
        while (++__first != __last)
        {
            if (!__pred(*__i, *__first))
            {
                *__result = *__first;
                ++__result;
                __i = __first;
            }
        }
    }
    return __result;
}

template <class _BinaryPredicate, class _InputIterator, class _ForwardIterator>
_ForwardIterator
__unique_copy(_InputIterator __first, _InputIterator __last, _ForwardIterator __result, _BinaryPredicate __pred,
              input_iterator_tag, forward_iterator_tag)
{
    if (__first != __last)
    {
        *__result = *__first;
        while (++__first != __last)
            if (!__pred(*__result, *__first))
                *++__result = *__first;
        ++__result;
    }
    return __result;
}

template <class _InputIterator, class _OutputIterator, class _BinaryPredicate>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
unique_copy(_InputIterator __first, _InputIterator __last, _OutputIterator __result, _BinaryPredicate __pred)
{
    return _VSTD::__unique_copy<typename add_lvalue_reference<_BinaryPredicate>::type>
                              (__first, __last, __result, __pred,
                               typename iterator_traits<_InputIterator>::iterator_category(),
                               typename iterator_traits<_OutputIterator>::iterator_category());
}

template <class _InputIterator, class _OutputIterator>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
unique_copy(_InputIterator __first, _InputIterator __last, _OutputIterator __result)
{
    typedef typename iterator_traits<_InputIterator>::value_type __v;
    return _VSTD::unique_copy(__first, __last, __result, __equal_to<__v>());
}

// reverse

template <class _BidirectionalIterator>
inline _LIBCPP_INLINE_VISIBILITY
void
__reverse(_BidirectionalIterator __first, _BidirectionalIterator __last, bidirectional_iterator_tag)
{
    while (__first != __last)
    {
        if (__first == --__last)
            break;
        _VSTD::iter_swap(__first, __last);
        ++__first;
    }
}

template <class _RandomAccessIterator>
inline _LIBCPP_INLINE_VISIBILITY
void
__reverse(_RandomAccessIterator __first, _RandomAccessIterator __last, random_access_iterator_tag)
{
    if (__first != __last)
        for (; __first < --__last; ++__first)
            _VSTD::iter_swap(__first, __last);
}

template <class _BidirectionalIterator>
inline _LIBCPP_INLINE_VISIBILITY
void
reverse(_BidirectionalIterator __first, _BidirectionalIterator __last)
{
    _VSTD::__reverse(__first, __last, typename iterator_traits<_BidirectionalIterator>::iterator_category());
}

// reverse_copy

template <class _BidirectionalIterator, class _OutputIterator>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
reverse_copy(_BidirectionalIterator __first, _BidirectionalIterator __last, _OutputIterator __result)
{
    for (; __first != __last; ++__result)
        *__result = *--__last;
    return __result;
}

// rotate

template <class _ForwardIterator>
_ForwardIterator
__rotate_left(_ForwardIterator __first, _ForwardIterator __last)
{
    typedef typename iterator_traits<_ForwardIterator>::value_type value_type;
    value_type __tmp = _VSTD::move(*__first);
    _ForwardIterator __lm1 = _VSTD::move(_VSTD::next(__first), __last, __first);
    *__lm1 = _VSTD::move(__tmp);
    return __lm1;
}

template <class _BidirectionalIterator>
_BidirectionalIterator
__rotate_right(_BidirectionalIterator __first, _BidirectionalIterator __last)
{
    typedef typename iterator_traits<_BidirectionalIterator>::value_type value_type;
    _BidirectionalIterator __lm1 = _VSTD::prev(__last);
    value_type __tmp = _VSTD::move(*__lm1);
    _BidirectionalIterator __fp1 = _VSTD::move_backward(__first, __lm1, __last);
    *__first = _VSTD::move(__tmp);
    return __fp1;
}

template <class _ForwardIterator>
_ForwardIterator
__rotate_forward(_ForwardIterator __first, _ForwardIterator __middle, _ForwardIterator __last)
{
    _ForwardIterator __i = __middle;
    while (true)
    {
        swap(*__first, *__i);
        ++__first;
        if (++__i == __last)
            break;
        if (__first == __middle)
            __middle = __i;
    }
    _ForwardIterator __r = __first;
    if (__first != __middle)
    {
        __i = __middle;
        while (true)
        {
            swap(*__first, *__i);
            ++__first;
            if (++__i == __last)
            {
                if (__first == __middle)
                    break;
                __i = __middle;
            }
            else if (__first == __middle)
                __middle = __i;
        }
    }
    return __r;
}

template<typename _Integral>
inline _LIBCPP_INLINE_VISIBILITY
_Integral
__algo_gcd(_Integral __x, _Integral __y)
{
    do
    {
        _Integral __t = __x % __y;
        __x = __y;
        __y = __t;
    } while (__y);
    return __x;
}

template<typename _RandomAccessIterator>
_RandomAccessIterator
__rotate_gcd(_RandomAccessIterator __first, _RandomAccessIterator __middle, _RandomAccessIterator __last)
{
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;

    const difference_type __m1 = __middle - __first;
    const difference_type __m2 = __last - __middle;
    if (__m1 == __m2)
    {
        _VSTD::swap_ranges(__first, __middle, __middle);
        return __middle;
    }
    const difference_type __g = _VSTD::__algo_gcd(__m1, __m2);
    for (_RandomAccessIterator __p = __first + __g; __p != __first;)
    {
        value_type __t(_VSTD::move(*--__p));
        _RandomAccessIterator __p1 = __p;
        _RandomAccessIterator __p2 = __p1 + __m1;
        do
        {
            *__p1 = _VSTD::move(*__p2);
            __p1 = __p2;
            const difference_type __d = __last - __p2;
            if (__m1 < __d)
                __p2 += __m1;
            else
                __p2 = __first + (__m1 - __d);
        } while (__p2 != __p);
        *__p1 = _VSTD::move(__t);
    }
    return __first + __m2;
}

template <class _ForwardIterator>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator
__rotate(_ForwardIterator __first, _ForwardIterator __middle, _ForwardIterator __last,
         _VSTD::forward_iterator_tag)
{
    typedef typename _VSTD::iterator_traits<_ForwardIterator>::value_type value_type;
    if (_VSTD::is_trivially_move_assignable<value_type>::value)
    {
        if (_VSTD::next(__first) == __middle)
            return _VSTD::__rotate_left(__first, __last);
    }
    return _VSTD::__rotate_forward(__first, __middle, __last);
}

template <class _BidirectionalIterator>
inline _LIBCPP_INLINE_VISIBILITY
_BidirectionalIterator
__rotate(_BidirectionalIterator __first, _BidirectionalIterator __middle, _BidirectionalIterator __last,
         _VSTD::bidirectional_iterator_tag)
{
    typedef typename _VSTD::iterator_traits<_BidirectionalIterator>::value_type value_type;
    if (_VSTD::is_trivially_move_assignable<value_type>::value)
    {
        if (_VSTD::next(__first) == __middle)
            return _VSTD::__rotate_left(__first, __last);
        if (_VSTD::next(__middle) == __last)
            return _VSTD::__rotate_right(__first, __last);
    }
    return _VSTD::__rotate_forward(__first, __middle, __last);
}

template <class _RandomAccessIterator>
inline _LIBCPP_INLINE_VISIBILITY
_RandomAccessIterator
__rotate(_RandomAccessIterator __first, _RandomAccessIterator __middle, _RandomAccessIterator __last,
         _VSTD::random_access_iterator_tag)
{
    typedef typename _VSTD::iterator_traits<_RandomAccessIterator>::value_type value_type;
    if (_VSTD::is_trivially_move_assignable<value_type>::value)
    {
        if (_VSTD::next(__first) == __middle)
            return _VSTD::__rotate_left(__first, __last);
        if (_VSTD::next(__middle) == __last)
            return _VSTD::__rotate_right(__first, __last);
        return _VSTD::__rotate_gcd(__first, __middle, __last);
    }
    return _VSTD::__rotate_forward(__first, __middle, __last);
}

template <class _ForwardIterator>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator
rotate(_ForwardIterator __first, _ForwardIterator __middle, _ForwardIterator __last)
{
    if (__first == __middle)
        return __last;
    if (__middle == __last)
        return __first;
    return _VSTD::__rotate(__first, __middle, __last,
                           typename _VSTD::iterator_traits<_ForwardIterator>::iterator_category());
}

// rotate_copy

template <class _ForwardIterator, class _OutputIterator>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
rotate_copy(_ForwardIterator __first, _ForwardIterator __middle, _ForwardIterator __last, _OutputIterator __result)
{
    return _VSTD::copy(__first, __middle, _VSTD::copy(__middle, __last, __result));
}

// min_element

template <class _ForwardIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
_ForwardIterator
min_element(_ForwardIterator __first, _ForwardIterator __last, _Compare __comp)
{
    if (__first != __last)
    {
        _ForwardIterator __i = __first;
        while (++__i != __last)
            if (__comp(*__i, *__first))
                __first = __i;
    }
    return __first;
}

template <class _ForwardIterator>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
_ForwardIterator
min_element(_ForwardIterator __first, _ForwardIterator __last)
{
    return _VSTD::min_element(__first, __last,
              __less<typename iterator_traits<_ForwardIterator>::value_type>());
}

// min

template <class _Tp, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
const _Tp&
min(const _Tp& __a, const _Tp& __b, _Compare __comp)
{
    return __comp(__b, __a) ? __b : __a;
}

template <class _Tp>
inline _LIBCPP_CONSTEXPR_AFTER_CXX11
const _Tp&
min(const _Tp& __a, const _Tp& __b)
{
    return _VSTD::min(__a, __b, __less<_Tp>());
}

#ifndef _LIBCPP_CXX03_LANG

template<class _Tp, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
_Tp
min(initializer_list<_Tp> __t, _Compare __comp)
{
    return *_VSTD::min_element(__t.begin(), __t.end(), __comp);
}

template<class _Tp>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
_Tp
min(initializer_list<_Tp> __t)
{
    return *_VSTD::min_element(__t.begin(), __t.end(), __less<_Tp>());
}

#endif  // _LIBCPP_CXX03_LANG

// max_element

template <class _ForwardIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
_ForwardIterator
max_element(_ForwardIterator __first, _ForwardIterator __last, _Compare __comp)
{
    if (__first != __last)
    {
        _ForwardIterator __i = __first;
        while (++__i != __last)
            if (__comp(*__first, *__i))
                __first = __i;
    }
    return __first;
}


template <class _ForwardIterator>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
_ForwardIterator
max_element(_ForwardIterator __first, _ForwardIterator __last)
{
    return _VSTD::max_element(__first, __last,
              __less<typename iterator_traits<_ForwardIterator>::value_type>());
}

// max

template <class _Tp, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
const _Tp&
max(const _Tp& __a, const _Tp& __b, _Compare __comp)
{
    return __comp(__a, __b) ? __b : __a;
}

template <class _Tp>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
const _Tp&
max(const _Tp& __a, const _Tp& __b)
{
    return _VSTD::max(__a, __b, __less<_Tp>());
}

#ifndef _LIBCPP_CXX03_LANG

template<class _Tp, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
_Tp
max(initializer_list<_Tp> __t, _Compare __comp)
{
    return *_VSTD::max_element(__t.begin(), __t.end(), __comp);
}

template<class _Tp>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
_Tp
max(initializer_list<_Tp> __t)
{
    return *_VSTD::max_element(__t.begin(), __t.end(), __less<_Tp>());
}

#endif  // _LIBCPP_CXX03_LANG

#if _LIBCPP_STD_VER > 14
// clamp
template<class _Tp, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
const _Tp&
clamp(const _Tp& __v, const _Tp& __lo, const _Tp& __hi, _Compare __comp)
{
    _LIBCPP_ASSERT(!__comp(__hi, __lo), "Bad bounds passed to std::clamp");
    return __comp(__v, __lo) ? __lo : __comp(__hi, __v) ? __hi : __v;

}

template<class _Tp>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
const _Tp&
clamp(const _Tp& __v, const _Tp& __lo, const _Tp& __hi)
{
    return _VSTD::clamp(__v, __lo, __hi, __less<_Tp>());
}
#endif

// minmax_element

template <class _ForwardIterator, class _Compare>
_LIBCPP_CONSTEXPR_AFTER_CXX11
std::pair<_ForwardIterator, _ForwardIterator>
minmax_element(_ForwardIterator __first, _ForwardIterator __last, _Compare __comp)
{
  std::pair<_ForwardIterator, _ForwardIterator> __result(__first, __first);
  if (__first != __last)
  {
      if (++__first != __last)
      {
          if (__comp(*__first, *__result.first))
              __result.first = __first;
          else
              __result.second = __first;
          while (++__first != __last)
          {
              _ForwardIterator __i = __first;
              if (++__first == __last)
              {
                  if (__comp(*__i, *__result.first))
                      __result.first = __i;
                  else if (!__comp(*__i, *__result.second))
                      __result.second = __i;
                  break;
              }
              else
              {
                  if (__comp(*__first, *__i))
                  {
                      if (__comp(*__first, *__result.first))
                          __result.first = __first;
                      if (!__comp(*__i, *__result.second))
                          __result.second = __i;
                  }
                  else
                  {
                      if (__comp(*__i, *__result.first))
                          __result.first = __i;
                      if (!__comp(*__first, *__result.second))
                          __result.second = __first;
                  }
              }
          }
      }
  }
  return __result;
}

template <class _ForwardIterator>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
std::pair<_ForwardIterator, _ForwardIterator>
minmax_element(_ForwardIterator __first, _ForwardIterator __last)
{
    return _VSTD::minmax_element(__first, __last,
              __less<typename iterator_traits<_ForwardIterator>::value_type>());
}

// minmax

template<class _Tp, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
pair<const _Tp&, const _Tp&>
minmax(const _Tp& __a, const _Tp& __b, _Compare __comp)
{
    return __comp(__b, __a) ? pair<const _Tp&, const _Tp&>(__b, __a) :
                              pair<const _Tp&, const _Tp&>(__a, __b);
}

template<class _Tp>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
pair<const _Tp&, const _Tp&>
minmax(const _Tp& __a, const _Tp& __b)
{
    return _VSTD::minmax(__a, __b, __less<_Tp>());
}

#ifndef _LIBCPP_CXX03_LANG

template<class _Tp, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
pair<_Tp, _Tp>
minmax(initializer_list<_Tp> __t, _Compare __comp)
{
    typedef typename initializer_list<_Tp>::const_iterator _Iter;
    _Iter __first = __t.begin();
    _Iter __last  = __t.end();
    std::pair<_Tp, _Tp> __result(*__first, *__first);

    ++__first;
    if (__t.size() % 2 == 0)
    {
        if (__comp(*__first,  __result.first))
            __result.first  = *__first;
        else
            __result.second = *__first;
        ++__first;
    }

    while (__first != __last)
    {
        _Tp __prev = *__first++;
        if (__comp(*__first, __prev)) {
            if ( __comp(*__first, __result.first)) __result.first  = *__first;
            if (!__comp(__prev, __result.second))  __result.second = __prev;
            }
        else {
            if ( __comp(__prev, __result.first))    __result.first  = __prev;
            if (!__comp(*__first, __result.second)) __result.second = *__first;
            }

        __first++;
    }
    return __result;
}

template<class _Tp>
inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
pair<_Tp, _Tp>
minmax(initializer_list<_Tp> __t)
{
    return _VSTD::minmax(__t, __less<_Tp>());
}

#endif  // _LIBCPP_CXX03_LANG

// random_shuffle

// __independent_bits_engine

template <unsigned long long _Xp, size_t _Rp>
struct __log2_imp
{
    static const size_t value = _Xp & ((unsigned long long)(1) << _Rp) ? _Rp
                                           : __log2_imp<_Xp, _Rp - 1>::value;
};

template <unsigned long long _Xp>
struct __log2_imp<_Xp, 0>
{
    static const size_t value = 0;
};

template <size_t _Rp>
struct __log2_imp<0, _Rp>
{
    static const size_t value = _Rp + 1;
};

template <class _UIntType, _UIntType _Xp>
struct __log2
{
    static const size_t value = __log2_imp<_Xp,
                                         sizeof(_UIntType) * __CHAR_BIT__ - 1>::value;
};

template<class _Engine, class _UIntType>
class __independent_bits_engine
{
public:
    // types
    typedef _UIntType result_type;

private:
    typedef typename _Engine::result_type _Engine_result_type;
    typedef typename conditional
        <
            sizeof(_Engine_result_type) <= sizeof(result_type),
                result_type,
                _Engine_result_type
        >::type _Working_result_type;

    _Engine& __e_;
    size_t __w_;
    size_t __w0_;
    size_t __n_;
    size_t __n0_;
    _Working_result_type __y0_;
    _Working_result_type __y1_;
    _Engine_result_type __mask0_;
    _Engine_result_type __mask1_;

#ifdef _LIBCPP_CXX03_LANG
    static const _Working_result_type _Rp = _Engine::_Max - _Engine::_Min
                                          + _Working_result_type(1);
#else
    static _LIBCPP_CONSTEXPR const _Working_result_type _Rp = _Engine::max() - _Engine::min()
                                                      + _Working_result_type(1);
#endif
    static _LIBCPP_CONSTEXPR const size_t __m = __log2<_Working_result_type, _Rp>::value;
    static _LIBCPP_CONSTEXPR const size_t _WDt = numeric_limits<_Working_result_type>::digits;
    static _LIBCPP_CONSTEXPR const size_t _EDt = numeric_limits<_Engine_result_type>::digits;

public:
    // constructors and seeding functions
    __independent_bits_engine(_Engine& __e, size_t __w);

    // generating functions
    result_type operator()() {return __eval(integral_constant<bool, _Rp != 0>());}

private:
    result_type __eval(false_type);
    result_type __eval(true_type);
};

template<class _Engine, class _UIntType>
__independent_bits_engine<_Engine, _UIntType>
    ::__independent_bits_engine(_Engine& __e, size_t __w)
        : __e_(__e),
          __w_(__w)
{
    __n_ = __w_ / __m + (__w_ % __m != 0);
    __w0_ = __w_ / __n_;
    if (_Rp == 0)
        __y0_ = _Rp;
    else if (__w0_ < _WDt)
        __y0_ = (_Rp >> __w0_) << __w0_;
    else
        __y0_ = 0;
    if (_Rp - __y0_ > __y0_ / __n_)
    {
        ++__n_;
        __w0_ = __w_ / __n_;
        if (__w0_ < _WDt)
            __y0_ = (_Rp >> __w0_) << __w0_;
        else
            __y0_ = 0;
    }
    __n0_ = __n_ - __w_ % __n_;
    if (__w0_ < _WDt - 1)
        __y1_ = (_Rp >> (__w0_ + 1)) << (__w0_ + 1);
    else
        __y1_ = 0;
    __mask0_ = __w0_ > 0 ? _Engine_result_type(~0) >> (_EDt - __w0_) :
                          _Engine_result_type(0);
    __mask1_ = __w0_ < _EDt - 1 ?
                               _Engine_result_type(~0) >> (_EDt - (__w0_ + 1)) :
                               _Engine_result_type(~0);
}

template<class _Engine, class _UIntType>
inline
_UIntType
__independent_bits_engine<_Engine, _UIntType>::__eval(false_type)
{
    return static_cast<result_type>(__e_() & __mask0_);
}

template<class _Engine, class _UIntType>
_UIntType
__independent_bits_engine<_Engine, _UIntType>::__eval(true_type)
{
    result_type _Sp = 0;
    for (size_t __k = 0; __k < __n0_; ++__k)
    {
        _Engine_result_type __u;
        do
        {
            __u = __e_() - _Engine::min();
        } while (__u >= __y0_);
        if (__w0_ < _WDt)
            _Sp <<= __w0_;
        else
            _Sp = 0;
        _Sp += __u & __mask0_;
    }
    for (size_t __k = __n0_; __k < __n_; ++__k)
    {
        _Engine_result_type __u;
        do
        {
            __u = __e_() - _Engine::min();
        } while (__u >= __y1_);
        if (__w0_ < _WDt - 1)
            _Sp <<= __w0_ + 1;
        else
            _Sp = 0;
        _Sp += __u & __mask1_;
    }
    return _Sp;
}

// uniform_int_distribution

template<class _IntType = int>
class uniform_int_distribution
{
public:
    // types
    typedef _IntType result_type;

    class param_type
    {
        result_type __a_;
        result_type __b_;
    public:
        typedef uniform_int_distribution distribution_type;

        explicit param_type(result_type __a = 0,
                            result_type __b = numeric_limits<result_type>::max())
            : __a_(__a), __b_(__b) {}

        result_type a() const {return __a_;}
        result_type b() const {return __b_;}

        friend bool operator==(const param_type& __x, const param_type& __y)
            {return __x.__a_ == __y.__a_ && __x.__b_ == __y.__b_;}
        friend bool operator!=(const param_type& __x, const param_type& __y)
            {return !(__x == __y);}
    };

private:
    param_type __p_;

public:
    // constructors and reset functions
    explicit uniform_int_distribution(result_type __a = 0,
                                      result_type __b = numeric_limits<result_type>::max())
        : __p_(param_type(__a, __b)) {}
    explicit uniform_int_distribution(const param_type& __p) : __p_(__p) {}
    void reset() {}

    // generating functions
    template<class _URNG> result_type operator()(_URNG& __g)
        {return (*this)(__g, __p_);}
    template<class _URNG> result_type operator()(_URNG& __g, const param_type& __p);

    // property functions
    result_type a() const {return __p_.a();}
    result_type b() const {return __p_.b();}

    param_type param() const {return __p_;}
    void param(const param_type& __p) {__p_ = __p;}

    result_type min() const {return a();}
    result_type max() const {return b();}

    friend bool operator==(const uniform_int_distribution& __x,
                           const uniform_int_distribution& __y)
        {return __x.__p_ == __y.__p_;}
    friend bool operator!=(const uniform_int_distribution& __x,
                           const uniform_int_distribution& __y)
            {return !(__x == __y);}
};

template<class _IntType>
template<class _URNG>
typename uniform_int_distribution<_IntType>::result_type
uniform_int_distribution<_IntType>::operator()(_URNG& __g, const param_type& __p)
{
    typedef typename conditional<sizeof(result_type) <= sizeof(uint32_t),
                                            uint32_t, uint64_t>::type _UIntType;
    const _UIntType _Rp = __p.b() - __p.a() + _UIntType(1);
    if (_Rp == 1)
        return __p.a();
    const size_t _Dt = numeric_limits<_UIntType>::digits;
    typedef __independent_bits_engine<_URNG, _UIntType> _Eng;
    if (_Rp == 0)
        return static_cast<result_type>(_Eng(__g, _Dt)());
    size_t __w = _Dt - __clz(_Rp) - 1;
    if ((_Rp & (std::numeric_limits<_UIntType>::max() >> (_Dt - __w))) != 0)
        ++__w;
    _Eng __e(__g, __w);
    _UIntType __u;
    do
    {
        __u = __e();
    } while (__u >= _Rp);
    return static_cast<result_type>(__u + __p.a());
}

#if _LIBCPP_STD_VER <= 14 || defined(_LIBCPP_ENABLE_CXX17_REMOVED_RANDOM_SHUFFLE) \
  || defined(_LIBCPP_BUILDING_LIBRARY)
class _LIBCPP_TYPE_VIS __rs_default;

_LIBCPP_FUNC_VIS __rs_default __rs_get();

class _LIBCPP_TYPE_VIS __rs_default
{
    static unsigned __c_;

    __rs_default();
public:
    typedef uint_fast32_t result_type;

    static const result_type _Min = 0;
    static const result_type _Max = 0xFFFFFFFF;

    __rs_default(const __rs_default&);
    ~__rs_default();

    result_type operator()();

    static _LIBCPP_CONSTEXPR result_type min() {return _Min;}
    static _LIBCPP_CONSTEXPR result_type max() {return _Max;}

    friend _LIBCPP_FUNC_VIS __rs_default __rs_get();
};

_LIBCPP_FUNC_VIS __rs_default __rs_get();

template <class _RandomAccessIterator>
void
random_shuffle(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    typedef uniform_int_distribution<ptrdiff_t> _Dp;
    typedef typename _Dp::param_type _Pp;
    difference_type __d = __last - __first;
    if (__d > 1)
    {
        _Dp __uid;
        __rs_default __g = __rs_get();
        for (--__last, --__d; __first < __last; ++__first, --__d)
        {
            difference_type __i = __uid(__g, _Pp(0, __d));
            if (__i != difference_type(0))
                swap(*__first, *(__first + __i));
        }
    }
}

template <class _RandomAccessIterator, class _RandomNumberGenerator>
void
random_shuffle(_RandomAccessIterator __first, _RandomAccessIterator __last,
#ifndef _LIBCPP_CXX03_LANG
               _RandomNumberGenerator&& __rand)
#else
               _RandomNumberGenerator& __rand)
#endif
{
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    difference_type __d = __last - __first;
    if (__d > 1)
    {
        for (--__last; __first < __last; ++__first, --__d)
        {
            difference_type __i = __rand(__d);
            swap(*__first, *(__first + __i));
        }
    }
}
#endif

template <class _PopulationIterator, class _SampleIterator, class _Distance,
          class _UniformRandomNumberGenerator>
_LIBCPP_INLINE_VISIBILITY
_SampleIterator __sample(_PopulationIterator __first,
                         _PopulationIterator __last, _SampleIterator __output,
                         _Distance __n,
                         _UniformRandomNumberGenerator & __g,
                         input_iterator_tag) {

  _Distance __k = 0;
  for (; __first != __last && __k < __n; ++__first, (void)++__k)
    __output[__k] = *__first;
  _Distance __sz = __k;
  for (; __first != __last; ++__first, (void)++__k) {
    _Distance __r = _VSTD::uniform_int_distribution<_Distance>(0, __k)(__g);
    if (__r < __sz)
      __output[__r] = *__first;
  }
  return __output + _VSTD::min(__n, __k);
}

template <class _PopulationIterator, class _SampleIterator, class _Distance,
          class _UniformRandomNumberGenerator>
_LIBCPP_INLINE_VISIBILITY
_SampleIterator __sample(_PopulationIterator __first,
                         _PopulationIterator __last, _SampleIterator __output,
                         _Distance __n,
                         _UniformRandomNumberGenerator& __g,
                         forward_iterator_tag) {
  _Distance __unsampled_sz = _VSTD::distance(__first, __last);
  for (__n = _VSTD::min(__n, __unsampled_sz); __n != 0; ++__first) {
    _Distance __r =
        _VSTD::uniform_int_distribution<_Distance>(0, --__unsampled_sz)(__g);
    if (__r < __n) {
      *__output++ = *__first;
      --__n;
    }
  }
  return __output;
}

template <class _PopulationIterator, class _SampleIterator, class _Distance,
          class _UniformRandomNumberGenerator>
_LIBCPP_INLINE_VISIBILITY
_SampleIterator __sample(_PopulationIterator __first,
                         _PopulationIterator __last, _SampleIterator __output,
                         _Distance __n, _UniformRandomNumberGenerator& __g) {
  typedef typename iterator_traits<_PopulationIterator>::iterator_category
        _PopCategory;
  typedef typename iterator_traits<_PopulationIterator>::difference_type
        _Difference;
  static_assert(__is_forward_iterator<_PopulationIterator>::value ||
                __is_random_access_iterator<_SampleIterator>::value,
                "SampleIterator must meet the requirements of RandomAccessIterator");
  typedef typename common_type<_Distance, _Difference>::type _CommonType;
  _LIBCPP_ASSERT(__n >= 0, "N must be a positive number.");
  return _VSTD::__sample(
      __first, __last, __output, _CommonType(__n),
      __g, _PopCategory());
}

#if _LIBCPP_STD_VER > 14
template <class _PopulationIterator, class _SampleIterator, class _Distance,
          class _UniformRandomNumberGenerator>
inline _LIBCPP_INLINE_VISIBILITY
_SampleIterator sample(_PopulationIterator __first,
                       _PopulationIterator __last, _SampleIterator __output,
                       _Distance __n, _UniformRandomNumberGenerator&& __g) {
    return _VSTD::__sample(__first, __last, __output, __n, __g);
}
#endif // _LIBCPP_STD_VER > 14

template<class _RandomAccessIterator, class _UniformRandomNumberGenerator>
    void shuffle(_RandomAccessIterator __first, _RandomAccessIterator __last,
#ifndef _LIBCPP_CXX03_LANG
                 _UniformRandomNumberGenerator&& __g)
#else
                 _UniformRandomNumberGenerator& __g)
#endif
{
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    typedef uniform_int_distribution<ptrdiff_t> _Dp;
    typedef typename _Dp::param_type _Pp;
    difference_type __d = __last - __first;
    if (__d > 1)
    {
        _Dp __uid;
        for (--__last, --__d; __first < __last; ++__first, --__d)
        {
            difference_type __i = __uid(__g, _Pp(0, __d));
            if (__i != difference_type(0))
                swap(*__first, *(__first + __i));
        }
    }
}

template <class _InputIterator, class _Predicate>
bool
is_partitioned(_InputIterator __first, _InputIterator __last, _Predicate __pred)
{
    for (; __first != __last; ++__first)
        if (!__pred(*__first))
            break;
    if ( __first == __last )
        return true;
    ++__first;
    for (; __first != __last; ++__first)
        if (__pred(*__first))
            return false;
    return true;
}

// partition

template <class _Predicate, class _ForwardIterator>
_ForwardIterator
__partition(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred, forward_iterator_tag)
{
    while (true)
    {
        if (__first == __last)
            return __first;
        if (!__pred(*__first))
            break;
        ++__first;
    }
    for (_ForwardIterator __p = __first; ++__p != __last;)
    {
        if (__pred(*__p))
        {
            swap(*__first, *__p);
            ++__first;
        }
    }
    return __first;
}

template <class _Predicate, class _BidirectionalIterator>
_BidirectionalIterator
__partition(_BidirectionalIterator __first, _BidirectionalIterator __last, _Predicate __pred,
            bidirectional_iterator_tag)
{
    while (true)
    {
        while (true)
        {
            if (__first == __last)
                return __first;
            if (!__pred(*__first))
                break;
            ++__first;
        }
        do
        {
            if (__first == --__last)
                return __first;
        } while (!__pred(*__last));
        swap(*__first, *__last);
        ++__first;
    }
}

template <class _ForwardIterator, class _Predicate>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator
partition(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred)
{
    return _VSTD::__partition<typename add_lvalue_reference<_Predicate>::type>
                            (__first, __last, __pred, typename iterator_traits<_ForwardIterator>::iterator_category());
}

// partition_copy

template <class _InputIterator, class _OutputIterator1,
          class _OutputIterator2, class _Predicate>
pair<_OutputIterator1, _OutputIterator2>
partition_copy(_InputIterator __first, _InputIterator __last,
               _OutputIterator1 __out_true, _OutputIterator2 __out_false,
               _Predicate __pred)
{
    for (; __first != __last; ++__first)
    {
        if (__pred(*__first))
        {
            *__out_true = *__first;
            ++__out_true;
        }
        else
        {
            *__out_false = *__first;
            ++__out_false;
        }
    }
    return pair<_OutputIterator1, _OutputIterator2>(__out_true, __out_false);
}

// partition_point

template<class _ForwardIterator, class _Predicate>
_ForwardIterator
partition_point(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred)
{
    typedef typename iterator_traits<_ForwardIterator>::difference_type difference_type;
    difference_type __len = _VSTD::distance(__first, __last);
    while (__len != 0)
    {
        difference_type __l2 = __len / 2;
        _ForwardIterator __m = __first;
        _VSTD::advance(__m, __l2);
        if (__pred(*__m))
        {
            __first = ++__m;
            __len -= __l2 + 1;
        }
        else
            __len = __l2;
    }
    return __first;
}

// stable_partition

template <class _Predicate, class _ForwardIterator, class _Distance, class _Pair>
_ForwardIterator
__stable_partition(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred,
                   _Distance __len, _Pair __p, forward_iterator_tag __fit)
{
    // *__first is known to be false
    // __len >= 1
    if (__len == 1)
        return __first;
    if (__len == 2)
    {
        _ForwardIterator __m = __first;
        if (__pred(*++__m))
        {
            swap(*__first, *__m);
            return __m;
        }
        return __first;
    }
    if (__len <= __p.second)
    {   // The buffer is big enough to use
        typedef typename iterator_traits<_ForwardIterator>::value_type value_type;
        __destruct_n __d(0);
        unique_ptr<value_type, __destruct_n&> __h(__p.first, __d);
        // Move the falses into the temporary buffer, and the trues to the front of the line
        // Update __first to always point to the end of the trues
        value_type* __t = __p.first;
        ::new(__t) value_type(_VSTD::move(*__first));
        __d.__incr((value_type*)0);
        ++__t;
        _ForwardIterator __i = __first;
        while (++__i != __last)
        {
            if (__pred(*__i))
            {
                *__first = _VSTD::move(*__i);
                ++__first;
            }
            else
            {
                ::new(__t) value_type(_VSTD::move(*__i));
                __d.__incr((value_type*)0);
                ++__t;
            }
        }
        // All trues now at start of range, all falses in buffer
        // Move falses back into range, but don't mess up __first which points to first false
        __i = __first;
        for (value_type* __t2 = __p.first; __t2 < __t; ++__t2, ++__i)
            *__i = _VSTD::move(*__t2);
        // __h destructs moved-from values out of the temp buffer, but doesn't deallocate buffer
        return __first;
    }
    // Else not enough buffer, do in place
    // __len >= 3
    _ForwardIterator __m = __first;
    _Distance __len2 = __len / 2;  // __len2 >= 2
    _VSTD::advance(__m, __len2);
    // recurse on [__first, __m), *__first know to be false
    // F?????????????????
    // f       m         l
    typedef typename add_lvalue_reference<_Predicate>::type _PredRef;
    _ForwardIterator __first_false = __stable_partition<_PredRef>(__first, __m, __pred, __len2, __p, __fit);
    // TTTFFFFF??????????
    // f  ff   m         l
    // recurse on [__m, __last], except increase __m until *(__m) is false, *__last know to be true
    _ForwardIterator __m1 = __m;
    _ForwardIterator __second_false = __last;
    _Distance __len_half = __len - __len2;
    while (__pred(*__m1))
    {
        if (++__m1 == __last)
            goto __second_half_done;
        --__len_half;
    }
    // TTTFFFFFTTTF??????
    // f  ff   m  m1     l
    __second_false = __stable_partition<_PredRef>(__m1, __last, __pred, __len_half, __p, __fit);
__second_half_done:
    // TTTFFFFFTTTTTFFFFF
    // f  ff   m    sf   l
    return _VSTD::rotate(__first_false, __m, __second_false);
    // TTTTTTTTFFFFFFFFFF
    //         |
}

struct __return_temporary_buffer
{
    template <class _Tp>
    _LIBCPP_INLINE_VISIBILITY void operator()(_Tp* __p) const {_VSTD::return_temporary_buffer(__p);}
};

template <class _Predicate, class _ForwardIterator>
_ForwardIterator
__stable_partition(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred,
                   forward_iterator_tag)
{
    const unsigned __alloc_limit = 3;  // might want to make this a function of trivial assignment
    // Either prove all true and return __first or point to first false
    while (true)
    {
        if (__first == __last)
            return __first;
        if (!__pred(*__first))
            break;
        ++__first;
    }
    // We now have a reduced range [__first, __last)
    // *__first is known to be false
    typedef typename iterator_traits<_ForwardIterator>::difference_type difference_type;
    typedef typename iterator_traits<_ForwardIterator>::value_type value_type;
    difference_type __len = _VSTD::distance(__first, __last);
    pair<value_type*, ptrdiff_t> __p(0, 0);
    unique_ptr<value_type, __return_temporary_buffer> __h;
    if (__len >= __alloc_limit)
    {
        __p = _VSTD::get_temporary_buffer<value_type>(__len);
        __h.reset(__p.first);
    }
    return __stable_partition<typename add_lvalue_reference<_Predicate>::type>
                             (__first, __last, __pred, __len, __p, forward_iterator_tag());
}

template <class _Predicate, class _BidirectionalIterator, class _Distance, class _Pair>
_BidirectionalIterator
__stable_partition(_BidirectionalIterator __first, _BidirectionalIterator __last, _Predicate __pred,
                   _Distance __len, _Pair __p, bidirectional_iterator_tag __bit)
{
    // *__first is known to be false
    // *__last is known to be true
    // __len >= 2
    if (__len == 2)
    {
        swap(*__first, *__last);
        return __last;
    }
    if (__len == 3)
    {
        _BidirectionalIterator __m = __first;
        if (__pred(*++__m))
        {
            swap(*__first, *__m);
            swap(*__m, *__last);
            return __last;
        }
        swap(*__m, *__last);
        swap(*__first, *__m);
        return __m;
    }
    if (__len <= __p.second)
    {   // The buffer is big enough to use
        typedef typename iterator_traits<_BidirectionalIterator>::value_type value_type;
        __destruct_n __d(0);
        unique_ptr<value_type, __destruct_n&> __h(__p.first, __d);
        // Move the falses into the temporary buffer, and the trues to the front of the line
        // Update __first to always point to the end of the trues
        value_type* __t = __p.first;
        ::new(__t) value_type(_VSTD::move(*__first));
        __d.__incr((value_type*)0);
        ++__t;
        _BidirectionalIterator __i = __first;
        while (++__i != __last)
        {
            if (__pred(*__i))
            {
                *__first = _VSTD::move(*__i);
                ++__first;
            }
            else
            {
                ::new(__t) value_type(_VSTD::move(*__i));
                __d.__incr((value_type*)0);
                ++__t;
            }
        }
        // move *__last, known to be true
        *__first = _VSTD::move(*__i);
        __i = ++__first;
        // All trues now at start of range, all falses in buffer
        // Move falses back into range, but don't mess up __first which points to first false
        for (value_type* __t2 = __p.first; __t2 < __t; ++__t2, ++__i)
            *__i = _VSTD::move(*__t2);
        // __h destructs moved-from values out of the temp buffer, but doesn't deallocate buffer
        return __first;
    }
    // Else not enough buffer, do in place
    // __len >= 4
    _BidirectionalIterator __m = __first;
    _Distance __len2 = __len / 2;  // __len2 >= 2
    _VSTD::advance(__m, __len2);
    // recurse on [__first, __m-1], except reduce __m-1 until *(__m-1) is true, *__first know to be false
    // F????????????????T
    // f       m        l
    _BidirectionalIterator __m1 = __m;
    _BidirectionalIterator __first_false = __first;
    _Distance __len_half = __len2;
    while (!__pred(*--__m1))
    {
        if (__m1 == __first)
            goto __first_half_done;
        --__len_half;
    }
    // F???TFFF?????????T
    // f   m1  m        l
    typedef typename add_lvalue_reference<_Predicate>::type _PredRef;
    __first_false = __stable_partition<_PredRef>(__first, __m1, __pred, __len_half, __p, __bit);
__first_half_done:
    // TTTFFFFF?????????T
    // f  ff   m        l
    // recurse on [__m, __last], except increase __m until *(__m) is false, *__last know to be true
    __m1 = __m;
    _BidirectionalIterator __second_false = __last;
    ++__second_false;
    __len_half = __len - __len2;
    while (__pred(*__m1))
    {
        if (++__m1 == __last)
            goto __second_half_done;
        --__len_half;
    }
    // TTTFFFFFTTTF?????T
    // f  ff   m  m1    l
    __second_false = __stable_partition<_PredRef>(__m1, __last, __pred, __len_half, __p, __bit);
__second_half_done:
    // TTTFFFFFTTTTTFFFFF
    // f  ff   m    sf  l
    return _VSTD::rotate(__first_false, __m, __second_false);
    // TTTTTTTTFFFFFFFFFF
    //         |
}

template <class _Predicate, class _BidirectionalIterator>
_BidirectionalIterator
__stable_partition(_BidirectionalIterator __first, _BidirectionalIterator __last, _Predicate __pred,
                   bidirectional_iterator_tag)
{
    typedef typename iterator_traits<_BidirectionalIterator>::difference_type difference_type;
    typedef typename iterator_traits<_BidirectionalIterator>::value_type value_type;
    const difference_type __alloc_limit = 4;  // might want to make this a function of trivial assignment
    // Either prove all true and return __first or point to first false
    while (true)
    {
        if (__first == __last)
            return __first;
        if (!__pred(*__first))
            break;
        ++__first;
    }
    // __first points to first false, everything prior to __first is already set.
    // Either prove [__first, __last) is all false and return __first, or point __last to last true
    do
    {
        if (__first == --__last)
            return __first;
    } while (!__pred(*__last));
    // We now have a reduced range [__first, __last]
    // *__first is known to be false
    // *__last is known to be true
    // __len >= 2
    difference_type __len = _VSTD::distance(__first, __last) + 1;
    pair<value_type*, ptrdiff_t> __p(0, 0);
    unique_ptr<value_type, __return_temporary_buffer> __h;
    if (__len >= __alloc_limit)
    {
        __p = _VSTD::get_temporary_buffer<value_type>(__len);
        __h.reset(__p.first);
    }
    return __stable_partition<typename add_lvalue_reference<_Predicate>::type>
                             (__first, __last, __pred, __len, __p, bidirectional_iterator_tag());
}

template <class _ForwardIterator, class _Predicate>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator
stable_partition(_ForwardIterator __first, _ForwardIterator __last, _Predicate __pred)
{
    return __stable_partition<typename add_lvalue_reference<_Predicate>::type>
                             (__first, __last, __pred, typename iterator_traits<_ForwardIterator>::iterator_category());
}

// is_sorted_until

template <class _ForwardIterator, class _Compare>
_ForwardIterator
is_sorted_until(_ForwardIterator __first, _ForwardIterator __last, _Compare __comp)
{
    if (__first != __last)
    {
        _ForwardIterator __i = __first;
        while (++__i != __last)
        {
            if (__comp(*__i, *__first))
                return __i;
            __first = __i;
        }
    }
    return __last;
}

template<class _ForwardIterator>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator
is_sorted_until(_ForwardIterator __first, _ForwardIterator __last)
{
    return _VSTD::is_sorted_until(__first, __last, __less<typename iterator_traits<_ForwardIterator>::value_type>());
}

// is_sorted

template <class _ForwardIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
bool
is_sorted(_ForwardIterator __first, _ForwardIterator __last, _Compare __comp)
{
    return _VSTD::is_sorted_until(__first, __last, __comp) == __last;
}

template<class _ForwardIterator>
inline _LIBCPP_INLINE_VISIBILITY
bool
is_sorted(_ForwardIterator __first, _ForwardIterator __last)
{
    return _VSTD::is_sorted(__first, __last, __less<typename iterator_traits<_ForwardIterator>::value_type>());
}

// sort

// stable, 2-3 compares, 0-2 swaps

template <class _Compare, class _ForwardIterator>
unsigned
__sort3(_ForwardIterator __x, _ForwardIterator __y, _ForwardIterator __z, _Compare __c)
{
    unsigned __r = 0;
    if (!__c(*__y, *__x))          // if x <= y
    {
        if (!__c(*__z, *__y))      // if y <= z
            return __r;            // x <= y && y <= z
                                   // x <= y && y > z
        swap(*__y, *__z);          // x <= z && y < z
        __r = 1;
        if (__c(*__y, *__x))       // if x > y
        {
            swap(*__x, *__y);      // x < y && y <= z
            __r = 2;
        }
        return __r;                // x <= y && y < z
    }
    if (__c(*__z, *__y))           // x > y, if y > z
    {
        swap(*__x, *__z);          // x < y && y < z
        __r = 1;
        return __r;
    }
    swap(*__x, *__y);              // x > y && y <= z
    __r = 1;                       // x < y && x <= z
    if (__c(*__z, *__y))           // if y > z
    {
        swap(*__y, *__z);          // x <= y && y < z
        __r = 2;
    }
    return __r;
}                                  // x <= y && y <= z

// stable, 3-6 compares, 0-5 swaps

template <class _Compare, class _ForwardIterator>
unsigned
__sort4(_ForwardIterator __x1, _ForwardIterator __x2, _ForwardIterator __x3,
            _ForwardIterator __x4, _Compare __c)
{
    unsigned __r = __sort3<_Compare>(__x1, __x2, __x3, __c);
    if (__c(*__x4, *__x3))
    {
        swap(*__x3, *__x4);
        ++__r;
        if (__c(*__x3, *__x2))
        {
            swap(*__x2, *__x3);
            ++__r;
            if (__c(*__x2, *__x1))
            {
                swap(*__x1, *__x2);
                ++__r;
            }
        }
    }
    return __r;
}

// stable, 4-10 compares, 0-9 swaps

template <class _Compare, class _ForwardIterator>
unsigned
__sort5(_ForwardIterator __x1, _ForwardIterator __x2, _ForwardIterator __x3,
            _ForwardIterator __x4, _ForwardIterator __x5, _Compare __c)
{
    unsigned __r = __sort4<_Compare>(__x1, __x2, __x3, __x4, __c);
    if (__c(*__x5, *__x4))
    {
        swap(*__x4, *__x5);
        ++__r;
        if (__c(*__x4, *__x3))
        {
            swap(*__x3, *__x4);
            ++__r;
            if (__c(*__x3, *__x2))
            {
                swap(*__x2, *__x3);
                ++__r;
                if (__c(*__x2, *__x1))
                {
                    swap(*__x1, *__x2);
                    ++__r;
                }
            }
        }
    }
    return __r;
}

// Assumes size > 0
template <class _Compare, class _BirdirectionalIterator>
void
__selection_sort(_BirdirectionalIterator __first, _BirdirectionalIterator __last, _Compare __comp)
{
    _BirdirectionalIterator __lm1 = __last;
    for (--__lm1; __first != __lm1; ++__first)
    {
        _BirdirectionalIterator __i = _VSTD::min_element<_BirdirectionalIterator,
                                                        typename add_lvalue_reference<_Compare>::type>
                                                       (__first, __last, __comp);
        if (__i != __first)
            swap(*__first, *__i);
    }
}

template <class _Compare, class _BirdirectionalIterator>
void
__insertion_sort(_BirdirectionalIterator __first, _BirdirectionalIterator __last, _Compare __comp)
{
    typedef typename iterator_traits<_BirdirectionalIterator>::value_type value_type;
    if (__first != __last)
    {
        _BirdirectionalIterator __i = __first;
        for (++__i; __i != __last; ++__i)
        {
            _BirdirectionalIterator __j = __i;
            value_type __t(_VSTD::move(*__j));
            for (_BirdirectionalIterator __k = __i; __k != __first && __comp(__t,  *--__k); --__j)
                *__j = _VSTD::move(*__k);
            *__j = _VSTD::move(__t);
        }
    }
}

template <class _Compare, class _RandomAccessIterator>
void
__insertion_sort_3(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;
    _RandomAccessIterator __j = __first+2;
    __sort3<_Compare>(__first, __first+1, __j, __comp);
    for (_RandomAccessIterator __i = __j+1; __i != __last; ++__i)
    {
        if (__comp(*__i, *__j))
        {
            value_type __t(_VSTD::move(*__i));
            _RandomAccessIterator __k = __j;
            __j = __i;
            do
            {
                *__j = _VSTD::move(*__k);
                __j = __k;
            } while (__j != __first && __comp(__t, *--__k));
            *__j = _VSTD::move(__t);
        }
        __j = __i;
    }
}

template <class _Compare, class _RandomAccessIterator>
bool
__insertion_sort_incomplete(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    switch (__last - __first)
    {
    case 0:
    case 1:
        return true;
    case 2:
        if (__comp(*--__last, *__first))
            swap(*__first, *__last);
        return true;
    case 3:
        _VSTD::__sort3<_Compare>(__first, __first+1, --__last, __comp);
        return true;
    case 4:
        _VSTD::__sort4<_Compare>(__first, __first+1, __first+2, --__last, __comp);
        return true;
    case 5:
        _VSTD::__sort5<_Compare>(__first, __first+1, __first+2, __first+3, --__last, __comp);
        return true;
    }
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;
    _RandomAccessIterator __j = __first+2;
    __sort3<_Compare>(__first, __first+1, __j, __comp);
    const unsigned __limit = 8;
    unsigned __count = 0;
    for (_RandomAccessIterator __i = __j+1; __i != __last; ++__i)
    {
        if (__comp(*__i, *__j))
        {
            value_type __t(_VSTD::move(*__i));
            _RandomAccessIterator __k = __j;
            __j = __i;
            do
            {
                *__j = _VSTD::move(*__k);
                __j = __k;
            } while (__j != __first && __comp(__t, *--__k));
            *__j = _VSTD::move(__t);
            if (++__count == __limit)
                return ++__i == __last;
        }
        __j = __i;
    }
    return true;
}

template <class _Compare, class _BirdirectionalIterator>
void
__insertion_sort_move(_BirdirectionalIterator __first1, _BirdirectionalIterator __last1,
                      typename iterator_traits<_BirdirectionalIterator>::value_type* __first2, _Compare __comp)
{
    typedef typename iterator_traits<_BirdirectionalIterator>::value_type value_type;
    if (__first1 != __last1)
    {
        __destruct_n __d(0);
        unique_ptr<value_type, __destruct_n&> __h(__first2, __d);
        value_type* __last2 = __first2;
        ::new(__last2) value_type(_VSTD::move(*__first1));
        __d.__incr((value_type*)0);
        for (++__last2; ++__first1 != __last1; ++__last2)
        {
            value_type* __j2 = __last2;
            value_type* __i2 = __j2;
            if (__comp(*__first1, *--__i2))
            {
                ::new(__j2) value_type(_VSTD::move(*__i2));
                __d.__incr((value_type*)0);
                for (--__j2; __i2 != __first2 && __comp(*__first1,  *--__i2); --__j2)
                    *__j2 = _VSTD::move(*__i2);
                *__j2 = _VSTD::move(*__first1);
            }
            else
            {
                ::new(__j2) value_type(_VSTD::move(*__first1));
                __d.__incr((value_type*)0);
            }
        }
        __h.release();
    }
}

template <class _Compare, class _RandomAccessIterator>
void
__sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    // _Compare is known to be a reference type
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;
    const difference_type __limit = is_trivially_copy_constructible<value_type>::value &&
                                    is_trivially_copy_assignable<value_type>::value ? 30 : 6;
    while (true)
    {
    __restart:
        difference_type __len = __last - __first;
        switch (__len)
        {
        case 0:
        case 1:
            return;
        case 2:
            if (__comp(*--__last, *__first))
                swap(*__first, *__last);
            return;
        case 3:
            _VSTD::__sort3<_Compare>(__first, __first+1, --__last, __comp);
            return;
        case 4:
            _VSTD::__sort4<_Compare>(__first, __first+1, __first+2, --__last, __comp);
            return;
        case 5:
            _VSTD::__sort5<_Compare>(__first, __first+1, __first+2, __first+3, --__last, __comp);
            return;
        }
        if (__len <= __limit)
        {
            _VSTD::__insertion_sort_3<_Compare>(__first, __last, __comp);
            return;
        }
        // __len > 5
        _RandomAccessIterator __m = __first;
        _RandomAccessIterator __lm1 = __last;
        --__lm1;
        unsigned __n_swaps;
        {
        difference_type __delta;
        if (__len >= 1000)
        {
            __delta = __len/2;
            __m += __delta;
            __delta /= 2;
            __n_swaps = _VSTD::__sort5<_Compare>(__first, __first + __delta, __m, __m+__delta, __lm1, __comp);
        }
        else
        {
            __delta = __len/2;
            __m += __delta;
            __n_swaps = _VSTD::__sort3<_Compare>(__first, __m, __lm1, __comp);
        }
        }
        // *__m is median
        // partition [__first, __m) < *__m and *__m <= [__m, __last)
        // (this inhibits tossing elements equivalent to __m around unnecessarily)
        _RandomAccessIterator __i = __first;
        _RandomAccessIterator __j = __lm1;
        // j points beyond range to be tested, *__m is known to be <= *__lm1
        // The search going up is known to be guarded but the search coming down isn't.
        // Prime the downward search with a guard.
        if (!__comp(*__i, *__m))  // if *__first == *__m
        {
            // *__first == *__m, *__first doesn't go in first part
            // manually guard downward moving __j against __i
            while (true)
            {
                if (__i == --__j)
                {
                    // *__first == *__m, *__m <= all other elements
                    // Parition instead into [__first, __i) == *__first and *__first < [__i, __last)
                    ++__i;  // __first + 1
                    __j = __last;
                    if (!__comp(*__first, *--__j))  // we need a guard if *__first == *(__last-1)
                    {
                        while (true)
                        {
                            if (__i == __j)
                                return;  // [__first, __last) all equivalent elements
                            if (__comp(*__first, *__i))
                            {
                                swap(*__i, *__j);
                                ++__n_swaps;
                                ++__i;
                                break;
                            }
                            ++__i;
                        }
                    }
                    // [__first, __i) == *__first and *__first < [__j, __last) and __j == __last - 1
                    if (__i == __j)
                        return;
                    while (true)
                    {
                        while (!__comp(*__first, *__i))
                            ++__i;
                        while (__comp(*__first, *--__j))
                            ;
                        if (__i >= __j)
                            break;
                        swap(*__i, *__j);
                        ++__n_swaps;
                        ++__i;
                    }
                    // [__first, __i) == *__first and *__first < [__i, __last)
                    // The first part is sorted, sort the secod part
                    // _VSTD::__sort<_Compare>(__i, __last, __comp);
                    __first = __i;
                    goto __restart;
                }
                if (__comp(*__j, *__m))
                {
                    swap(*__i, *__j);
                    ++__n_swaps;
                    break;  // found guard for downward moving __j, now use unguarded partition
                }
            }
        }
        // It is known that *__i < *__m
        ++__i;
        // j points beyond range to be tested, *__m is known to be <= *__lm1
        // if not yet partitioned...
        if (__i < __j)
        {
            // known that *(__i - 1) < *__m
            // known that __i <= __m
            while (true)
            {
                // __m still guards upward moving __i
                while (__comp(*__i, *__m))
                    ++__i;
                // It is now known that a guard exists for downward moving __j
                while (!__comp(*--__j, *__m))
                    ;
                if (__i > __j)
                    break;
                swap(*__i, *__j);
                ++__n_swaps;
                // It is known that __m != __j
                // If __m just moved, follow it
                if (__m == __i)
                    __m = __j;
                ++__i;
            }
        }
        // [__first, __i) < *__m and *__m <= [__i, __last)
        if (__i != __m && __comp(*__m, *__i))
        {
            swap(*__i, *__m);
            ++__n_swaps;
        }
        // [__first, __i) < *__i and *__i <= [__i+1, __last)
        // If we were given a perfect partition, see if insertion sort is quick...
        if (__n_swaps == 0)
        {
            bool __fs = _VSTD::__insertion_sort_incomplete<_Compare>(__first, __i, __comp);
            if (_VSTD::__insertion_sort_incomplete<_Compare>(__i+1, __last, __comp))
            {
                if (__fs)
                    return;
                __last = __i;
                continue;
            }
            else
            {
                if (__fs)
                {
                    __first = ++__i;
                    continue;
                }
            }
        }
        // sort smaller range with recursive call and larger with tail recursion elimination
        if (__i - __first < __last - __i)
        {
            _VSTD::__sort<_Compare>(__first, __i, __comp);
            // _VSTD::__sort<_Compare>(__i+1, __last, __comp);
            __first = ++__i;
        }
        else
        {
            _VSTD::__sort<_Compare>(__i+1, __last, __comp);
            // _VSTD::__sort<_Compare>(__first, __i, __comp);
            __last = __i;
        }
    }
}

// This forwarder keeps the top call and the recursive calls using the same instantiation, forcing a reference _Compare
template <class _RandomAccessIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
void
sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    __sort<_Comp_ref>(__first, __last, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    __sort<_Comp_ref>(__first, __last, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _RandomAccessIterator>
inline _LIBCPP_INLINE_VISIBILITY
void
sort(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    _VSTD::sort(__first, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}

template <class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
void
sort(_Tp** __first, _Tp** __last)
{
    _VSTD::sort((size_t*)__first, (size_t*)__last, __less<size_t>());
}

template <class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
void
sort(__wrap_iter<_Tp*> __first, __wrap_iter<_Tp*> __last)
{
    _VSTD::sort(__first.base(), __last.base());
}

template <class _Tp, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
void
sort(__wrap_iter<_Tp*> __first, __wrap_iter<_Tp*> __last, _Compare __comp)
{
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    _VSTD::sort<_Tp*, _Comp_ref>(__first.base(), __last.base(), __comp);
}

_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS void __sort<__less<char>&, char*>(char*, char*, __less<char>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS void __sort<__less<wchar_t>&, wchar_t*>(wchar_t*, wchar_t*, __less<wchar_t>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS void __sort<__less<signed char>&, signed char*>(signed char*, signed char*, __less<signed char>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS void __sort<__less<unsigned char>&, unsigned char*>(unsigned char*, unsigned char*, __less<unsigned char>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS void __sort<__less<short>&, short*>(short*, short*, __less<short>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS void __sort<__less<unsigned short>&, unsigned short*>(unsigned short*, unsigned short*, __less<unsigned short>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS void __sort<__less<int>&, int*>(int*, int*, __less<int>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS void __sort<__less<unsigned>&, unsigned*>(unsigned*, unsigned*, __less<unsigned>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS void __sort<__less<long>&, long*>(long*, long*, __less<long>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS void __sort<__less<unsigned long>&, unsigned long*>(unsigned long*, unsigned long*, __less<unsigned long>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS void __sort<__less<long long>&, long long*>(long long*, long long*, __less<long long>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS void __sort<__less<unsigned long long>&, unsigned long long*>(unsigned long long*, unsigned long long*, __less<unsigned long long>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS void __sort<__less<float>&, float*>(float*, float*, __less<float>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS void __sort<__less<double>&, double*>(double*, double*, __less<double>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS void __sort<__less<long double>&, long double*>(long double*, long double*, __less<long double>&))

_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS bool __insertion_sort_incomplete<__less<char>&, char*>(char*, char*, __less<char>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS bool __insertion_sort_incomplete<__less<wchar_t>&, wchar_t*>(wchar_t*, wchar_t*, __less<wchar_t>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS bool __insertion_sort_incomplete<__less<signed char>&, signed char*>(signed char*, signed char*, __less<signed char>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS bool __insertion_sort_incomplete<__less<unsigned char>&, unsigned char*>(unsigned char*, unsigned char*, __less<unsigned char>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS bool __insertion_sort_incomplete<__less<short>&, short*>(short*, short*, __less<short>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS bool __insertion_sort_incomplete<__less<unsigned short>&, unsigned short*>(unsigned short*, unsigned short*, __less<unsigned short>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS bool __insertion_sort_incomplete<__less<int>&, int*>(int*, int*, __less<int>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS bool __insertion_sort_incomplete<__less<unsigned>&, unsigned*>(unsigned*, unsigned*, __less<unsigned>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS bool __insertion_sort_incomplete<__less<long>&, long*>(long*, long*, __less<long>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS bool __insertion_sort_incomplete<__less<unsigned long>&, unsigned long*>(unsigned long*, unsigned long*, __less<unsigned long>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS bool __insertion_sort_incomplete<__less<long long>&, long long*>(long long*, long long*, __less<long long>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS bool __insertion_sort_incomplete<__less<unsigned long long>&, unsigned long long*>(unsigned long long*, unsigned long long*, __less<unsigned long long>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS bool __insertion_sort_incomplete<__less<float>&, float*>(float*, float*, __less<float>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS bool __insertion_sort_incomplete<__less<double>&, double*>(double*, double*, __less<double>&))
_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS bool __insertion_sort_incomplete<__less<long double>&, long double*>(long double*, long double*, __less<long double>&))

_LIBCPP_EXTERN_TEMPLATE(_LIBCPP_FUNC_VIS unsigned __sort5<__less<long double>&, long double*>(long double*, long double*, long double*, long double*, long double*, __less<long double>&))

// lower_bound

template <class _Compare, class _ForwardIterator, class _Tp>
_ForwardIterator
__lower_bound(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_, _Compare __comp)
{
    typedef typename iterator_traits<_ForwardIterator>::difference_type difference_type;
    difference_type __len = _VSTD::distance(__first, __last);
    while (__len != 0)
    {
        difference_type __l2 = __len / 2;
        _ForwardIterator __m = __first;
        _VSTD::advance(__m, __l2);
        if (__comp(*__m, __value_))
        {
            __first = ++__m;
            __len -= __l2 + 1;
        }
        else
            __len = __l2;
    }
    return __first;
}

template <class _ForwardIterator, class _Tp, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator
lower_bound(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    return __lower_bound<_Comp_ref>(__first, __last, __value_, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    return __lower_bound<_Comp_ref>(__first, __last, __value_, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _ForwardIterator, class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator
lower_bound(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_)
{
    return _VSTD::lower_bound(__first, __last, __value_,
                             __less<typename iterator_traits<_ForwardIterator>::value_type, _Tp>());
}

// upper_bound

template <class _Compare, class _ForwardIterator, class _Tp>
_ForwardIterator
__upper_bound(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_, _Compare __comp)
{
    typedef typename iterator_traits<_ForwardIterator>::difference_type difference_type;
    difference_type __len = _VSTD::distance(__first, __last);
    while (__len != 0)
    {
        difference_type __l2 = __len / 2;
        _ForwardIterator __m = __first;
        _VSTD::advance(__m, __l2);
        if (__comp(__value_, *__m))
            __len = __l2;
        else
        {
            __first = ++__m;
            __len -= __l2 + 1;
        }
    }
    return __first;
}

template <class _ForwardIterator, class _Tp, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator
upper_bound(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    return __upper_bound<_Comp_ref>(__first, __last, __value_, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    return __upper_bound<_Comp_ref>(__first, __last, __value_, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _ForwardIterator, class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
_ForwardIterator
upper_bound(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_)
{
    return _VSTD::upper_bound(__first, __last, __value_,
                             __less<_Tp, typename iterator_traits<_ForwardIterator>::value_type>());
}

// equal_range

template <class _Compare, class _ForwardIterator, class _Tp>
pair<_ForwardIterator, _ForwardIterator>
__equal_range(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_, _Compare __comp)
{
    typedef typename iterator_traits<_ForwardIterator>::difference_type difference_type;
    difference_type __len = _VSTD::distance(__first, __last);
    while (__len != 0)
    {
        difference_type __l2 = __len / 2;
        _ForwardIterator __m = __first;
        _VSTD::advance(__m, __l2);
        if (__comp(*__m, __value_))
        {
            __first = ++__m;
            __len -= __l2 + 1;
        }
        else if (__comp(__value_, *__m))
        {
            __last = __m;
            __len = __l2;
        }
        else
        {
            _ForwardIterator __mp1 = __m;
            return pair<_ForwardIterator, _ForwardIterator>
                   (
                      __lower_bound<_Compare>(__first, __m, __value_, __comp),
                      __upper_bound<_Compare>(++__mp1, __last, __value_, __comp)
                   );
        }
    }
    return pair<_ForwardIterator, _ForwardIterator>(__first, __first);
}

template <class _ForwardIterator, class _Tp, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
pair<_ForwardIterator, _ForwardIterator>
equal_range(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    return __equal_range<_Comp_ref>(__first, __last, __value_, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    return __equal_range<_Comp_ref>(__first, __last, __value_, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _ForwardIterator, class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
pair<_ForwardIterator, _ForwardIterator>
equal_range(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_)
{
    return _VSTD::equal_range(__first, __last, __value_,
                             __less<typename iterator_traits<_ForwardIterator>::value_type, _Tp>());
}

// binary_search

template <class _Compare, class _ForwardIterator, class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
bool
__binary_search(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_, _Compare __comp)
{
    __first = __lower_bound<_Compare>(__first, __last, __value_, __comp);
    return __first != __last && !__comp(__value_, *__first);
}

template <class _ForwardIterator, class _Tp, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
bool
binary_search(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    return __binary_search<_Comp_ref>(__first, __last, __value_, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    return __binary_search<_Comp_ref>(__first, __last, __value_, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _ForwardIterator, class _Tp>
inline _LIBCPP_INLINE_VISIBILITY
bool
binary_search(_ForwardIterator __first, _ForwardIterator __last, const _Tp& __value_)
{
    return _VSTD::binary_search(__first, __last, __value_,
                             __less<typename iterator_traits<_ForwardIterator>::value_type, _Tp>());
}

// merge

template <class _Compare, class _InputIterator1, class _InputIterator2, class _OutputIterator>
_OutputIterator
__merge(_InputIterator1 __first1, _InputIterator1 __last1,
        _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
    for (; __first1 != __last1; ++__result)
    {
        if (__first2 == __last2)
            return _VSTD::copy(__first1, __last1, __result);
        if (__comp(*__first2, *__first1))
        {
            *__result = *__first2;
            ++__first2;
        }
        else
        {
            *__result = *__first1;
            ++__first1;
        }
    }
    return _VSTD::copy(__first2, __last2, __result);
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
merge(_InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    return _VSTD::__merge<_Comp_ref>(__first1, __last1, __first2, __last2, __result, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    return _VSTD::__merge<_Comp_ref>(__first1, __last1, __first2, __last2, __result, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
merge(_InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result)
{
    typedef typename iterator_traits<_InputIterator1>::value_type __v1;
    typedef typename iterator_traits<_InputIterator2>::value_type __v2;
    return merge(__first1, __last1, __first2, __last2, __result, __less<__v1, __v2>());
}

// inplace_merge

template <class _Compare, class _InputIterator1, class _InputIterator2,
          class _OutputIterator>
void __half_inplace_merge(_InputIterator1 __first1, _InputIterator1 __last1,
                          _InputIterator2 __first2, _InputIterator2 __last2,
                          _OutputIterator __result, _Compare __comp)
{
    for (; __first1 != __last1; ++__result)
    {
        if (__first2 == __last2)
        {
            _VSTD::move(__first1, __last1, __result);
            return;
        }

        if (__comp(*__first2, *__first1))
        {
            *__result = _VSTD::move(*__first2);
            ++__first2;
        }
        else
        {
            *__result = _VSTD::move(*__first1);
            ++__first1;
        }
    }
    // __first2 through __last2 are already in the right spot.
}

template <class _Compare, class _BidirectionalIterator>
void
__buffered_inplace_merge(_BidirectionalIterator __first, _BidirectionalIterator __middle, _BidirectionalIterator __last,
                _Compare __comp, typename iterator_traits<_BidirectionalIterator>::difference_type __len1,
                                 typename iterator_traits<_BidirectionalIterator>::difference_type __len2,
                typename iterator_traits<_BidirectionalIterator>::value_type* __buff)
{
    typedef typename iterator_traits<_BidirectionalIterator>::value_type value_type;
    __destruct_n __d(0);
    unique_ptr<value_type, __destruct_n&> __h2(__buff, __d);
    if (__len1 <= __len2)
    {
        value_type* __p = __buff;
        for (_BidirectionalIterator __i = __first; __i != __middle; __d.__incr((value_type*)0), (void) ++__i, ++__p)
            ::new(__p) value_type(_VSTD::move(*__i));
        __half_inplace_merge(__buff, __p, __middle, __last, __first, __comp);
    }
    else
    {
        value_type* __p = __buff;
        for (_BidirectionalIterator __i = __middle; __i != __last; __d.__incr((value_type*)0), (void) ++__i, ++__p)
            ::new(__p) value_type(_VSTD::move(*__i));
        typedef reverse_iterator<_BidirectionalIterator> _RBi;
        typedef reverse_iterator<value_type*> _Rv;
        __half_inplace_merge(_Rv(__p), _Rv(__buff),
                             _RBi(__middle), _RBi(__first),
                             _RBi(__last), __invert<_Compare>(__comp));
    }
}

template <class _Compare, class _BidirectionalIterator>
void
__inplace_merge(_BidirectionalIterator __first, _BidirectionalIterator __middle, _BidirectionalIterator __last,
                _Compare __comp, typename iterator_traits<_BidirectionalIterator>::difference_type __len1,
                                 typename iterator_traits<_BidirectionalIterator>::difference_type __len2,
                typename iterator_traits<_BidirectionalIterator>::value_type* __buff, ptrdiff_t __buff_size)
{
    typedef typename iterator_traits<_BidirectionalIterator>::difference_type difference_type;
    while (true)
    {
        // if __middle == __last, we're done
        if (__len2 == 0)
            return;
        if (__len1 <= __buff_size || __len2 <= __buff_size)
            return __buffered_inplace_merge<_Compare>
                   (__first, __middle, __last, __comp, __len1, __len2, __buff);
        // shrink [__first, __middle) as much as possible (with no moves), returning if it shrinks to 0
        for (; true; ++__first, (void) --__len1)
        {
            if (__len1 == 0)
                return;
            if (__comp(*__middle, *__first))
                break;
        }
        // __first < __middle < __last
        // *__first > *__middle
        // partition [__first, __m1) [__m1, __middle) [__middle, __m2) [__m2, __last) such that
        //     all elements in:
        //         [__first, __m1)  <= [__middle, __m2)
        //         [__middle, __m2) <  [__m1, __middle)
        //         [__m1, __middle) <= [__m2, __last)
        //     and __m1 or __m2 is in the middle of its range
        _BidirectionalIterator __m1;  // "median" of [__first, __middle)
        _BidirectionalIterator __m2;  // "median" of [__middle, __last)
        difference_type __len11;      // distance(__first, __m1)
        difference_type __len21;      // distance(__middle, __m2)
        // binary search smaller range
        if (__len1 < __len2)
        {   // __len >= 1, __len2 >= 2
            __len21 = __len2 / 2;
            __m2 = __middle;
            _VSTD::advance(__m2, __len21);
            __m1 = __upper_bound<_Compare>(__first, __middle, *__m2, __comp);
            __len11 = _VSTD::distance(__first, __m1);
        }
        else
        {
            if (__len1 == 1)
            {   // __len1 >= __len2 && __len2 > 0, therefore __len2 == 1
                // It is known *__first > *__middle
                swap(*__first, *__middle);
                return;
            }
            // __len1 >= 2, __len2 >= 1
            __len11 = __len1 / 2;
            __m1 = __first;
            _VSTD::advance(__m1, __len11);
            __m2 = __lower_bound<_Compare>(__middle, __last, *__m1, __comp);
            __len21 = _VSTD::distance(__middle, __m2);
        }
        difference_type __len12 = __len1 - __len11;  // distance(__m1, __middle)
        difference_type __len22 = __len2 - __len21;  // distance(__m2, __last)
        // [__first, __m1) [__m1, __middle) [__middle, __m2) [__m2, __last)
        // swap middle two partitions
        __middle = _VSTD::rotate(__m1, __middle, __m2);
        // __len12 and __len21 now have swapped meanings
        // merge smaller range with recurisve call and larger with tail recursion elimination
        if (__len11 + __len21 < __len12 + __len22)
        {
            __inplace_merge<_Compare>(__first, __m1, __middle, __comp, __len11, __len21, __buff, __buff_size);
//          __inplace_merge<_Compare>(__middle, __m2, __last, __comp, __len12, __len22, __buff, __buff_size);
            __first = __middle;
            __middle = __m2;
            __len1 = __len12;
            __len2 = __len22;
        }
        else
        {
            __inplace_merge<_Compare>(__middle, __m2, __last, __comp, __len12, __len22, __buff, __buff_size);
//          __inplace_merge<_Compare>(__first, __m1, __middle, __comp, __len11, __len21, __buff, __buff_size);
            __last = __middle;
            __middle = __m1;
            __len1 = __len11;
            __len2 = __len21;
        }
    }
}

template <class _BidirectionalIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
void
inplace_merge(_BidirectionalIterator __first, _BidirectionalIterator __middle, _BidirectionalIterator __last,
              _Compare __comp)
{
    typedef typename iterator_traits<_BidirectionalIterator>::value_type value_type;
    typedef typename iterator_traits<_BidirectionalIterator>::difference_type difference_type;
    difference_type __len1 = _VSTD::distance(__first, __middle);
    difference_type __len2 = _VSTD::distance(__middle, __last);
    difference_type __buf_size = _VSTD::min(__len1, __len2);
    pair<value_type*, ptrdiff_t> __buf = _VSTD::get_temporary_buffer<value_type>(__buf_size);
    unique_ptr<value_type, __return_temporary_buffer> __h(__buf.first);

#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    return _VSTD::__inplace_merge<_Comp_ref>(__first, __middle, __last, __c, __len1, __len2,
                                            __buf.first, __buf.second);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    return _VSTD::__inplace_merge<_Comp_ref>(__first, __middle, __last, __comp, __len1, __len2,
                                            __buf.first, __buf.second);
#endif  // _LIBCPP_DEBUG
}

template <class _BidirectionalIterator>
inline _LIBCPP_INLINE_VISIBILITY
void
inplace_merge(_BidirectionalIterator __first, _BidirectionalIterator __middle, _BidirectionalIterator __last)
{
    _VSTD::inplace_merge(__first, __middle, __last,
                        __less<typename iterator_traits<_BidirectionalIterator>::value_type>());
}

// stable_sort

template <class _Compare, class _InputIterator1, class _InputIterator2>
void
__merge_move_construct(_InputIterator1 __first1, _InputIterator1 __last1,
        _InputIterator2 __first2, _InputIterator2 __last2,
        typename iterator_traits<_InputIterator1>::value_type* __result, _Compare __comp)
{
    typedef typename iterator_traits<_InputIterator1>::value_type value_type;
    __destruct_n __d(0);
    unique_ptr<value_type, __destruct_n&> __h(__result, __d);
    for (; true; ++__result)
    {
        if (__first1 == __last1)
        {
            for (; __first2 != __last2; ++__first2, ++__result, __d.__incr((value_type*)0))
                ::new (__result) value_type(_VSTD::move(*__first2));
            __h.release();
            return;
        }
        if (__first2 == __last2)
        {
            for (; __first1 != __last1; ++__first1, ++__result, __d.__incr((value_type*)0))
                ::new (__result) value_type(_VSTD::move(*__first1));
            __h.release();
            return;
        }
        if (__comp(*__first2, *__first1))
        {
            ::new (__result) value_type(_VSTD::move(*__first2));
            __d.__incr((value_type*)0);
            ++__first2;
        }
        else
        {
            ::new (__result) value_type(_VSTD::move(*__first1));
            __d.__incr((value_type*)0);
            ++__first1;
        }
    }
}

template <class _Compare, class _InputIterator1, class _InputIterator2, class _OutputIterator>
void
__merge_move_assign(_InputIterator1 __first1, _InputIterator1 __last1,
        _InputIterator2 __first2, _InputIterator2 __last2,
        _OutputIterator __result, _Compare __comp)
{
    for (; __first1 != __last1; ++__result)
    {
        if (__first2 == __last2)
        {
            for (; __first1 != __last1; ++__first1, ++__result)
                *__result = _VSTD::move(*__first1);
            return;
        }
        if (__comp(*__first2, *__first1))
        {
            *__result = _VSTD::move(*__first2);
            ++__first2;
        }
        else
        {
            *__result = _VSTD::move(*__first1);
            ++__first1;
        }
    }
    for (; __first2 != __last2; ++__first2, ++__result)
        *__result = _VSTD::move(*__first2);
}

template <class _Compare, class _RandomAccessIterator>
void
__stable_sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp,
              typename iterator_traits<_RandomAccessIterator>::difference_type __len,
              typename iterator_traits<_RandomAccessIterator>::value_type* __buff, ptrdiff_t __buff_size);

template <class _Compare, class _RandomAccessIterator>
void
__stable_sort_move(_RandomAccessIterator __first1, _RandomAccessIterator __last1, _Compare __comp,
                   typename iterator_traits<_RandomAccessIterator>::difference_type __len,
                   typename iterator_traits<_RandomAccessIterator>::value_type* __first2)
{
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;
    switch (__len)
    {
    case 0:
        return;
    case 1:
        ::new(__first2) value_type(_VSTD::move(*__first1));
        return;
    case 2:
       __destruct_n __d(0);
        unique_ptr<value_type, __destruct_n&> __h2(__first2, __d);
         if (__comp(*--__last1, *__first1))
        {
            ::new(__first2) value_type(_VSTD::move(*__last1));
            __d.__incr((value_type*)0);
            ++__first2;
            ::new(__first2) value_type(_VSTD::move(*__first1));
        }
        else
        {
            ::new(__first2) value_type(_VSTD::move(*__first1));
            __d.__incr((value_type*)0);
            ++__first2;
            ::new(__first2) value_type(_VSTD::move(*__last1));
        }
        __h2.release();
        return;
    }
    if (__len <= 8)
    {
        __insertion_sort_move<_Compare>(__first1, __last1, __first2, __comp);
        return;
    }
    typename iterator_traits<_RandomAccessIterator>::difference_type __l2 = __len / 2;
    _RandomAccessIterator __m = __first1 + __l2;
    __stable_sort<_Compare>(__first1, __m, __comp, __l2, __first2, __l2);
    __stable_sort<_Compare>(__m, __last1, __comp, __len - __l2, __first2 + __l2, __len - __l2);
    __merge_move_construct<_Compare>(__first1, __m, __m, __last1, __first2, __comp);
}

template <class _Tp>
struct __stable_sort_switch
{
    static const unsigned value = 128*is_trivially_copy_assignable<_Tp>::value;
};

template <class _Compare, class _RandomAccessIterator>
void
__stable_sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp,
              typename iterator_traits<_RandomAccessIterator>::difference_type __len,
              typename iterator_traits<_RandomAccessIterator>::value_type* __buff, ptrdiff_t __buff_size)
{
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    switch (__len)
    {
    case 0:
    case 1:
        return;
    case 2:
        if (__comp(*--__last, *__first))
            swap(*__first, *__last);
        return;
    }
    if (__len <= static_cast<difference_type>(__stable_sort_switch<value_type>::value))
    {
        __insertion_sort<_Compare>(__first, __last, __comp);
        return;
    }
    typename iterator_traits<_RandomAccessIterator>::difference_type __l2 = __len / 2;
    _RandomAccessIterator __m = __first + __l2;
    if (__len <= __buff_size)
    {
        __destruct_n __d(0);
        unique_ptr<value_type, __destruct_n&> __h2(__buff, __d);
        __stable_sort_move<_Compare>(__first, __m, __comp, __l2, __buff);
        __d.__set(__l2, (value_type*)0);
        __stable_sort_move<_Compare>(__m, __last, __comp, __len - __l2, __buff + __l2);
        __d.__set(__len, (value_type*)0);
        __merge_move_assign<_Compare>(__buff, __buff + __l2, __buff + __l2, __buff + __len, __first, __comp);
//         __merge<_Compare>(move_iterator<value_type*>(__buff),
//                           move_iterator<value_type*>(__buff + __l2),
//                           move_iterator<_RandomAccessIterator>(__buff + __l2),
//                           move_iterator<_RandomAccessIterator>(__buff + __len),
//                           __first, __comp);
        return;
    }
    __stable_sort<_Compare>(__first, __m, __comp, __l2, __buff, __buff_size);
    __stable_sort<_Compare>(__m, __last, __comp, __len - __l2, __buff, __buff_size);
    __inplace_merge<_Compare>(__first, __m, __last, __comp, __l2, __len - __l2, __buff, __buff_size);
}

template <class _RandomAccessIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
void
stable_sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    difference_type __len = __last - __first;
    pair<value_type*, ptrdiff_t> __buf(0, 0);
    unique_ptr<value_type, __return_temporary_buffer> __h;
    if (__len > static_cast<difference_type>(__stable_sort_switch<value_type>::value))
    {
        __buf = _VSTD::get_temporary_buffer<value_type>(__len);
        __h.reset(__buf.first);
    }
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    __stable_sort<_Comp_ref>(__first, __last, __c, __len, __buf.first, __buf.second);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    __stable_sort<_Comp_ref>(__first, __last, __comp, __len, __buf.first, __buf.second);
#endif  // _LIBCPP_DEBUG
}

template <class _RandomAccessIterator>
inline _LIBCPP_INLINE_VISIBILITY
void
stable_sort(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    _VSTD::stable_sort(__first, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}

// is_heap_until

template <class _RandomAccessIterator, class _Compare>
_RandomAccessIterator
is_heap_until(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    typedef typename _VSTD::iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    difference_type __len = __last - __first;
    difference_type __p = 0;
    difference_type __c = 1;
    _RandomAccessIterator __pp = __first;
    while (__c < __len)
    {
        _RandomAccessIterator __cp = __first + __c;
        if (__comp(*__pp, *__cp))
            return __cp;
        ++__c;
        ++__cp;
        if (__c == __len)
            return __last;
        if (__comp(*__pp, *__cp))
            return __cp;
        ++__p;
        ++__pp;
        __c = 2 * __p + 1;
    }
    return __last;
}

template<class _RandomAccessIterator>
inline _LIBCPP_INLINE_VISIBILITY
_RandomAccessIterator
is_heap_until(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    return _VSTD::is_heap_until(__first, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}

// is_heap

template <class _RandomAccessIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
bool
is_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    return _VSTD::is_heap_until(__first, __last, __comp) == __last;
}

template<class _RandomAccessIterator>
inline _LIBCPP_INLINE_VISIBILITY
bool
is_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    return _VSTD::is_heap(__first, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}

// push_heap

template <class _Compare, class _RandomAccessIterator>
void
__sift_up(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp,
          typename iterator_traits<_RandomAccessIterator>::difference_type __len)
{
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;
    if (__len > 1)
    {
        __len = (__len - 2) / 2;
        _RandomAccessIterator __ptr = __first + __len;
        if (__comp(*__ptr, *--__last))
        {
            value_type __t(_VSTD::move(*__last));
            do
            {
                *__last = _VSTD::move(*__ptr);
                __last = __ptr;
                if (__len == 0)
                    break;
                __len = (__len - 1) / 2;
                __ptr = __first + __len;
            } while (__comp(*__ptr, __t));
            *__last = _VSTD::move(__t);
        }
    }
}

template <class _RandomAccessIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
void
push_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    __sift_up<_Comp_ref>(__first, __last, __c, __last - __first);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    __sift_up<_Comp_ref>(__first, __last, __comp, __last - __first);
#endif  // _LIBCPP_DEBUG
}

template <class _RandomAccessIterator>
inline _LIBCPP_INLINE_VISIBILITY
void
push_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    _VSTD::push_heap(__first, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}

// pop_heap

template <class _Compare, class _RandomAccessIterator>
void
__sift_down(_RandomAccessIterator __first, _RandomAccessIterator /*__last*/,
            _Compare __comp,
            typename iterator_traits<_RandomAccessIterator>::difference_type __len,
            _RandomAccessIterator __start)
{
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;
    // left-child of __start is at 2 * __start + 1
    // right-child of __start is at 2 * __start + 2
    difference_type __child = __start - __first;

    if (__len < 2 || (__len - 2) / 2 < __child)
        return;

    __child = 2 * __child + 1;
    _RandomAccessIterator __child_i = __first + __child;

    if ((__child + 1) < __len && __comp(*__child_i, *(__child_i + 1))) {
        // right-child exists and is greater than left-child
        ++__child_i;
        ++__child;
    }

    // check if we are in heap-order
    if (__comp(*__child_i, *__start))
        // we are, __start is larger than it's largest child
        return;

    value_type __top(_VSTD::move(*__start));
    do
    {
        // we are not in heap-order, swap the parent with it's largest child
        *__start = _VSTD::move(*__child_i);
        __start = __child_i;

        if ((__len - 2) / 2 < __child)
            break;

        // recompute the child based off of the updated parent
        __child = 2 * __child + 1;
        __child_i = __first + __child;

        if ((__child + 1) < __len && __comp(*__child_i, *(__child_i + 1))) {
            // right-child exists and is greater than left-child
            ++__child_i;
            ++__child;
        }

        // check if we are in heap-order
    } while (!__comp(*__child_i, __top));
    *__start = _VSTD::move(__top);
}

template <class _Compare, class _RandomAccessIterator>
inline _LIBCPP_INLINE_VISIBILITY
void
__pop_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp,
           typename iterator_traits<_RandomAccessIterator>::difference_type __len)
{
    if (__len > 1)
    {
        swap(*__first, *--__last);
        __sift_down<_Compare>(__first, __last, __comp, __len - 1, __first);
    }
}

template <class _RandomAccessIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
void
pop_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    __pop_heap<_Comp_ref>(__first, __last, __c, __last - __first);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    __pop_heap<_Comp_ref>(__first, __last, __comp, __last - __first);
#endif  // _LIBCPP_DEBUG
}

template <class _RandomAccessIterator>
inline _LIBCPP_INLINE_VISIBILITY
void
pop_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    _VSTD::pop_heap(__first, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}

// make_heap

template <class _Compare, class _RandomAccessIterator>
void
__make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    difference_type __n = __last - __first;
    if (__n > 1)
    {
        // start from the first parent, there is no need to consider children
        for (difference_type __start = (__n - 2) / 2; __start >= 0; --__start)
        {
            __sift_down<_Compare>(__first, __last, __comp, __n, __first + __start);
        }
    }
}

template <class _RandomAccessIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
void
make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    __make_heap<_Comp_ref>(__first, __last, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    __make_heap<_Comp_ref>(__first, __last, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _RandomAccessIterator>
inline _LIBCPP_INLINE_VISIBILITY
void
make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    _VSTD::make_heap(__first, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}

// sort_heap

template <class _Compare, class _RandomAccessIterator>
void
__sort_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    for (difference_type __n = __last - __first; __n > 1; --__last, --__n)
        __pop_heap<_Compare>(__first, __last, __comp, __n);
}

template <class _RandomAccessIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
void
sort_heap(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    __sort_heap<_Comp_ref>(__first, __last, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    __sort_heap<_Comp_ref>(__first, __last, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _RandomAccessIterator>
inline _LIBCPP_INLINE_VISIBILITY
void
sort_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
    _VSTD::sort_heap(__first, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}

// partial_sort

template <class _Compare, class _RandomAccessIterator>
void
__partial_sort(_RandomAccessIterator __first, _RandomAccessIterator __middle, _RandomAccessIterator __last,
             _Compare __comp)
{
    __make_heap<_Compare>(__first, __middle, __comp);
    typename iterator_traits<_RandomAccessIterator>::difference_type __len = __middle - __first;
    for (_RandomAccessIterator __i = __middle; __i != __last; ++__i)
    {
        if (__comp(*__i, *__first))
        {
            swap(*__i, *__first);
            __sift_down<_Compare>(__first, __middle, __comp, __len, __first);
        }
    }
    __sort_heap<_Compare>(__first, __middle, __comp);
}

template <class _RandomAccessIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
void
partial_sort(_RandomAccessIterator __first, _RandomAccessIterator __middle, _RandomAccessIterator __last,
             _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    __partial_sort<_Comp_ref>(__first, __middle, __last, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    __partial_sort<_Comp_ref>(__first, __middle, __last, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _RandomAccessIterator>
inline _LIBCPP_INLINE_VISIBILITY
void
partial_sort(_RandomAccessIterator __first, _RandomAccessIterator __middle, _RandomAccessIterator __last)
{
    _VSTD::partial_sort(__first, __middle, __last,
                       __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}

// partial_sort_copy

template <class _Compare, class _InputIterator, class _RandomAccessIterator>
_RandomAccessIterator
__partial_sort_copy(_InputIterator __first, _InputIterator __last,
                    _RandomAccessIterator __result_first, _RandomAccessIterator __result_last, _Compare __comp)
{
    _RandomAccessIterator __r = __result_first;
    if (__r != __result_last)
    {
        for (; __first != __last && __r != __result_last; (void) ++__first, ++__r)
            *__r = *__first;
        __make_heap<_Compare>(__result_first, __r, __comp);
        typename iterator_traits<_RandomAccessIterator>::difference_type __len = __r - __result_first;
        for (; __first != __last; ++__first)
            if (__comp(*__first, *__result_first))
            {
                *__result_first = *__first;
                __sift_down<_Compare>(__result_first, __r, __comp, __len, __result_first);
            }
        __sort_heap<_Compare>(__result_first, __r, __comp);
    }
    return __r;
}

template <class _InputIterator, class _RandomAccessIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
_RandomAccessIterator
partial_sort_copy(_InputIterator __first, _InputIterator __last,
                  _RandomAccessIterator __result_first, _RandomAccessIterator __result_last, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    return __partial_sort_copy<_Comp_ref>(__first, __last, __result_first, __result_last, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    return __partial_sort_copy<_Comp_ref>(__first, __last, __result_first, __result_last, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _InputIterator, class _RandomAccessIterator>
inline _LIBCPP_INLINE_VISIBILITY
_RandomAccessIterator
partial_sort_copy(_InputIterator __first, _InputIterator __last,
                  _RandomAccessIterator __result_first, _RandomAccessIterator __result_last)
{
    return _VSTD::partial_sort_copy(__first, __last, __result_first, __result_last,
                                   __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}

// nth_element

template <class _Compare, class _RandomAccessIterator>
void
__nth_element(_RandomAccessIterator __first, _RandomAccessIterator __nth, _RandomAccessIterator __last, _Compare __comp)
{
    // _Compare is known to be a reference type
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    const difference_type __limit = 7;
    while (true)
    {
    __restart:
        if (__nth == __last)
            return;
        difference_type __len = __last - __first;
        switch (__len)
        {
        case 0:
        case 1:
            return;
        case 2:
            if (__comp(*--__last, *__first))
                swap(*__first, *__last);
            return;
        case 3:
            {
            _RandomAccessIterator __m = __first;
            _VSTD::__sort3<_Compare>(__first, ++__m, --__last, __comp);
            return;
            }
        }
        if (__len <= __limit)
        {
            __selection_sort<_Compare>(__first, __last, __comp);
            return;
        }
        // __len > __limit >= 3
        _RandomAccessIterator __m = __first + __len/2;
        _RandomAccessIterator __lm1 = __last;
        unsigned __n_swaps = _VSTD::__sort3<_Compare>(__first, __m, --__lm1, __comp);
        // *__m is median
        // partition [__first, __m) < *__m and *__m <= [__m, __last)
        // (this inhibits tossing elements equivalent to __m around unnecessarily)
        _RandomAccessIterator __i = __first;
        _RandomAccessIterator __j = __lm1;
        // j points beyond range to be tested, *__lm1 is known to be <= *__m
        // The search going up is known to be guarded but the search coming down isn't.
        // Prime the downward search with a guard.
        if (!__comp(*__i, *__m))  // if *__first == *__m
        {
            // *__first == *__m, *__first doesn't go in first part
            // manually guard downward moving __j against __i
            while (true)
            {
                if (__i == --__j)
                {
                    // *__first == *__m, *__m <= all other elements
                    // Parition instead into [__first, __i) == *__first and *__first < [__i, __last)
                    ++__i;  // __first + 1
                    __j = __last;
                    if (!__comp(*__first, *--__j))  // we need a guard if *__first == *(__last-1)
                    {
                        while (true)
                        {
                            if (__i == __j)
                                return;  // [__first, __last) all equivalent elements
                            if (__comp(*__first, *__i))
                            {
                                swap(*__i, *__j);
                                ++__n_swaps;
                                ++__i;
                                break;
                            }
                            ++__i;
                        }
                    }
                    // [__first, __i) == *__first and *__first < [__j, __last) and __j == __last - 1
                    if (__i == __j)
                        return;
                    while (true)
                    {
                        while (!__comp(*__first, *__i))
                            ++__i;
                        while (__comp(*__first, *--__j))
                            ;
                        if (__i >= __j)
                            break;
                        swap(*__i, *__j);
                        ++__n_swaps;
                        ++__i;
                    }
                    // [__first, __i) == *__first and *__first < [__i, __last)
                    // The first part is sorted,
                    if (__nth < __i)
                        return;
                    // __nth_element the secod part
                    // __nth_element<_Compare>(__i, __nth, __last, __comp);
                    __first = __i;
                    goto __restart;
                }
                if (__comp(*__j, *__m))
                {
                    swap(*__i, *__j);
                    ++__n_swaps;
                    break;  // found guard for downward moving __j, now use unguarded partition
                }
            }
        }
        ++__i;
        // j points beyond range to be tested, *__lm1 is known to be <= *__m
        // if not yet partitioned...
        if (__i < __j)
        {
            // known that *(__i - 1) < *__m
            while (true)
            {
                // __m still guards upward moving __i
                while (__comp(*__i, *__m))
                    ++__i;
                // It is now known that a guard exists for downward moving __j
                while (!__comp(*--__j, *__m))
                    ;
                if (__i >= __j)
                    break;
                swap(*__i, *__j);
                ++__n_swaps;
                // It is known that __m != __j
                // If __m just moved, follow it
                if (__m == __i)
                    __m = __j;
                ++__i;
            }
        }
        // [__first, __i) < *__m and *__m <= [__i, __last)
        if (__i != __m && __comp(*__m, *__i))
        {
            swap(*__i, *__m);
            ++__n_swaps;
        }
        // [__first, __i) < *__i and *__i <= [__i+1, __last)
        if (__nth == __i)
            return;
        if (__n_swaps == 0)
        {
            // We were given a perfectly partitioned sequence.  Coincidence?
            if (__nth < __i)
            {
                // Check for [__first, __i) already sorted
                __j = __m = __first;
                while (++__j != __i)
                {
                    if (__comp(*__j, *__m))
                        // not yet sorted, so sort
                        goto not_sorted;
                    __m = __j;
                }
                // [__first, __i) sorted
                return;
            }
            else
            {
                // Check for [__i, __last) already sorted
                __j = __m = __i;
                while (++__j != __last)
                {
                    if (__comp(*__j, *__m))
                        // not yet sorted, so sort
                        goto not_sorted;
                    __m = __j;
                }
                // [__i, __last) sorted
                return;
            }
        }
not_sorted:
        // __nth_element on range containing __nth
        if (__nth < __i)
        {
            // __nth_element<_Compare>(__first, __nth, __i, __comp);
            __last = __i;
        }
        else
        {
            // __nth_element<_Compare>(__i+1, __nth, __last, __comp);
            __first = ++__i;
        }
    }
}

template <class _RandomAccessIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
void
nth_element(_RandomAccessIterator __first, _RandomAccessIterator __nth, _RandomAccessIterator __last, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    __nth_element<_Comp_ref>(__first, __nth, __last, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    __nth_element<_Comp_ref>(__first, __nth, __last, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _RandomAccessIterator>
inline _LIBCPP_INLINE_VISIBILITY
void
nth_element(_RandomAccessIterator __first, _RandomAccessIterator __nth, _RandomAccessIterator __last)
{
    _VSTD::nth_element(__first, __nth, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}

// includes

template <class _Compare, class _InputIterator1, class _InputIterator2>
bool
__includes(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _InputIterator2 __last2,
           _Compare __comp)
{
    for (; __first2 != __last2; ++__first1)
    {
        if (__first1 == __last1 || __comp(*__first2, *__first1))
            return false;
        if (!__comp(*__first1, *__first2))
            ++__first2;
    }
    return true;
}

template <class _InputIterator1, class _InputIterator2, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
bool
includes(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _InputIterator2 __last2,
         _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    return __includes<_Comp_ref>(__first1, __last1, __first2, __last2, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    return __includes<_Comp_ref>(__first1, __last1, __first2, __last2, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _InputIterator1, class _InputIterator2>
inline _LIBCPP_INLINE_VISIBILITY
bool
includes(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _InputIterator2 __last2)
{
    return _VSTD::includes(__first1, __last1, __first2, __last2,
                          __less<typename iterator_traits<_InputIterator1>::value_type,
                                 typename iterator_traits<_InputIterator2>::value_type>());
}

// set_union

template <class _Compare, class _InputIterator1, class _InputIterator2, class _OutputIterator>
_OutputIterator
__set_union(_InputIterator1 __first1, _InputIterator1 __last1,
            _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
    for (; __first1 != __last1; ++__result)
    {
        if (__first2 == __last2)
            return _VSTD::copy(__first1, __last1, __result);
        if (__comp(*__first2, *__first1))
        {
            *__result = *__first2;
            ++__first2;
        }
        else
        {
            *__result = *__first1;
            if (!__comp(*__first1, *__first2))
                ++__first2;
            ++__first1;
        }
    }
    return _VSTD::copy(__first2, __last2, __result);
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
set_union(_InputIterator1 __first1, _InputIterator1 __last1,
          _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    return __set_union<_Comp_ref>(__first1, __last1, __first2, __last2, __result, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    return __set_union<_Comp_ref>(__first1, __last1, __first2, __last2, __result, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
set_union(_InputIterator1 __first1, _InputIterator1 __last1,
          _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result)
{
    return _VSTD::set_union(__first1, __last1, __first2, __last2, __result,
                          __less<typename iterator_traits<_InputIterator1>::value_type,
                                 typename iterator_traits<_InputIterator2>::value_type>());
}

// set_intersection

template <class _Compare, class _InputIterator1, class _InputIterator2, class _OutputIterator>
_OutputIterator
__set_intersection(_InputIterator1 __first1, _InputIterator1 __last1,
                   _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
    while (__first1 != __last1 && __first2 != __last2)
    {
        if (__comp(*__first1, *__first2))
            ++__first1;
        else
        {
            if (!__comp(*__first2, *__first1))
            {
                *__result = *__first1;
                ++__result;
                ++__first1;
            }
            ++__first2;
        }
    }
    return __result;
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
set_intersection(_InputIterator1 __first1, _InputIterator1 __last1,
                 _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    return __set_intersection<_Comp_ref>(__first1, __last1, __first2, __last2, __result, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    return __set_intersection<_Comp_ref>(__first1, __last1, __first2, __last2, __result, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
set_intersection(_InputIterator1 __first1, _InputIterator1 __last1,
                 _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result)
{
    return _VSTD::set_intersection(__first1, __last1, __first2, __last2, __result,
                                  __less<typename iterator_traits<_InputIterator1>::value_type,
                                         typename iterator_traits<_InputIterator2>::value_type>());
}

// set_difference

template <class _Compare, class _InputIterator1, class _InputIterator2, class _OutputIterator>
_OutputIterator
__set_difference(_InputIterator1 __first1, _InputIterator1 __last1,
                 _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
    while (__first1 != __last1)
    {
        if (__first2 == __last2)
            return _VSTD::copy(__first1, __last1, __result);
        if (__comp(*__first1, *__first2))
        {
            *__result = *__first1;
            ++__result;
            ++__first1;
        }
        else
        {
            if (!__comp(*__first2, *__first1))
                ++__first1;
            ++__first2;
        }
    }
    return __result;
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
set_difference(_InputIterator1 __first1, _InputIterator1 __last1,
               _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    return __set_difference<_Comp_ref>(__first1, __last1, __first2, __last2, __result, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    return __set_difference<_Comp_ref>(__first1, __last1, __first2, __last2, __result, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
set_difference(_InputIterator1 __first1, _InputIterator1 __last1,
               _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result)
{
    return _VSTD::set_difference(__first1, __last1, __first2, __last2, __result,
                                __less<typename iterator_traits<_InputIterator1>::value_type,
                                       typename iterator_traits<_InputIterator2>::value_type>());
}

// set_symmetric_difference

template <class _Compare, class _InputIterator1, class _InputIterator2, class _OutputIterator>
_OutputIterator
__set_symmetric_difference(_InputIterator1 __first1, _InputIterator1 __last1,
                           _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
    while (__first1 != __last1)
    {
        if (__first2 == __last2)
            return _VSTD::copy(__first1, __last1, __result);
        if (__comp(*__first1, *__first2))
        {
            *__result = *__first1;
            ++__result;
            ++__first1;
        }
        else
        {
            if (__comp(*__first2, *__first1))
            {
                *__result = *__first2;
                ++__result;
            }
            else
                ++__first1;
            ++__first2;
        }
    }
    return _VSTD::copy(__first2, __last2, __result);
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
set_symmetric_difference(_InputIterator1 __first1, _InputIterator1 __last1,
                         _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    return __set_symmetric_difference<_Comp_ref>(__first1, __last1, __first2, __last2, __result, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    return __set_symmetric_difference<_Comp_ref>(__first1, __last1, __first2, __last2, __result, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _InputIterator1, class _InputIterator2, class _OutputIterator>
inline _LIBCPP_INLINE_VISIBILITY
_OutputIterator
set_symmetric_difference(_InputIterator1 __first1, _InputIterator1 __last1,
                         _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result)
{
    return _VSTD::set_symmetric_difference(__first1, __last1, __first2, __last2, __result,
                                          __less<typename iterator_traits<_InputIterator1>::value_type,
                                                 typename iterator_traits<_InputIterator2>::value_type>());
}

// lexicographical_compare

template <class _Compare, class _InputIterator1, class _InputIterator2>
bool
__lexicographical_compare(_InputIterator1 __first1, _InputIterator1 __last1,
                          _InputIterator2 __first2, _InputIterator2 __last2, _Compare __comp)
{
    for (; __first2 != __last2; ++__first1, (void) ++__first2)
    {
        if (__first1 == __last1 || __comp(*__first1, *__first2))
            return true;
        if (__comp(*__first2, *__first1))
            return false;
    }
    return false;
}

template <class _InputIterator1, class _InputIterator2, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
bool
lexicographical_compare(_InputIterator1 __first1, _InputIterator1 __last1,
                        _InputIterator2 __first2, _InputIterator2 __last2, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    return __lexicographical_compare<_Comp_ref>(__first1, __last1, __first2, __last2, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    return __lexicographical_compare<_Comp_ref>(__first1, __last1, __first2, __last2, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _InputIterator1, class _InputIterator2>
inline _LIBCPP_INLINE_VISIBILITY
bool
lexicographical_compare(_InputIterator1 __first1, _InputIterator1 __last1,
                        _InputIterator2 __first2, _InputIterator2 __last2)
{
    return _VSTD::lexicographical_compare(__first1, __last1, __first2, __last2,
                                         __less<typename iterator_traits<_InputIterator1>::value_type,
                                                typename iterator_traits<_InputIterator2>::value_type>());
}

// next_permutation

template <class _Compare, class _BidirectionalIterator>
bool
__next_permutation(_BidirectionalIterator __first, _BidirectionalIterator __last, _Compare __comp)
{
    _BidirectionalIterator __i = __last;
    if (__first == __last || __first == --__i)
        return false;
    while (true)
    {
        _BidirectionalIterator __ip1 = __i;
        if (__comp(*--__i, *__ip1))
        {
            _BidirectionalIterator __j = __last;
            while (!__comp(*__i, *--__j))
                ;
            swap(*__i, *__j);
            _VSTD::reverse(__ip1, __last);
            return true;
        }
        if (__i == __first)
        {
            _VSTD::reverse(__first, __last);
            return false;
        }
    }
}

template <class _BidirectionalIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
bool
next_permutation(_BidirectionalIterator __first, _BidirectionalIterator __last, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    return __next_permutation<_Comp_ref>(__first, __last, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    return __next_permutation<_Comp_ref>(__first, __last, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _BidirectionalIterator>
inline _LIBCPP_INLINE_VISIBILITY
bool
next_permutation(_BidirectionalIterator __first, _BidirectionalIterator __last)
{
    return _VSTD::next_permutation(__first, __last,
                                  __less<typename iterator_traits<_BidirectionalIterator>::value_type>());
}

// prev_permutation

template <class _Compare, class _BidirectionalIterator>
bool
__prev_permutation(_BidirectionalIterator __first, _BidirectionalIterator __last, _Compare __comp)
{
    _BidirectionalIterator __i = __last;
    if (__first == __last || __first == --__i)
        return false;
    while (true)
    {
        _BidirectionalIterator __ip1 = __i;
        if (__comp(*__ip1, *--__i))
        {
            _BidirectionalIterator __j = __last;
            while (!__comp(*--__j, *__i))
                ;
            swap(*__i, *__j);
            _VSTD::reverse(__ip1, __last);
            return true;
        }
        if (__i == __first)
        {
            _VSTD::reverse(__first, __last);
            return false;
        }
    }
}

template <class _BidirectionalIterator, class _Compare>
inline _LIBCPP_INLINE_VISIBILITY
bool
prev_permutation(_BidirectionalIterator __first, _BidirectionalIterator __last, _Compare __comp)
{
#ifdef _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<__debug_less<_Compare> >::type _Comp_ref;
    __debug_less<_Compare> __c(__comp);
    return __prev_permutation<_Comp_ref>(__first, __last, __c);
#else  // _LIBCPP_DEBUG
    typedef typename add_lvalue_reference<_Compare>::type _Comp_ref;
    return __prev_permutation<_Comp_ref>(__first, __last, __comp);
#endif  // _LIBCPP_DEBUG
}

template <class _BidirectionalIterator>
inline _LIBCPP_INLINE_VISIBILITY
bool
prev_permutation(_BidirectionalIterator __first, _BidirectionalIterator __last)
{
    return _VSTD::prev_permutation(__first, __last,
                                  __less<typename iterator_traits<_BidirectionalIterator>::value_type>());
}

_LIBCPP_END_NAMESPACE_STD

_LIBCPP_POP_MACROS

#endif  // _LIBCPP_ALGORITHM
