/**
 * @file ISet.h
 * @author Taylor Curran
 * @brief Minimal set interface
 * @version 0.1
 * @date 2020-06-12
 * 
 * @copyright Copyright (c) 2020
 *
 */

#ifndef I_SET_H
#define I_SET_H

#include <functional>   // std::equal_to    

/**
 * @brief Interface representing the set abstract data type
 * 
 * @tparam T data type of set elements
 * @tparam Equal_To equality comparison object (see std::equal_to)
 * 
 * @details Sets cannot contain duplicate items. Equality is determined by the
 * Equal_To object; the default behaviour uses std::equal_to<T>, which simply
 * uses the equaliy operator. To implement custom equality behaviour, either 
 * provide an equality comparison object or override the equality operator. 
 */
template<class T, class Equal_To = std::equal_to<T>>
class ISet
{
    public:
        virtual ~ISet<T, Equal_To>();

        /**
         * @brief Returns the number of elements in the set
         * @return size_t Number of elements in the set
         */
        virtual size_t size() const noexcept = 0;

        /**
         * @brief Returns true if the set contains \p element
         *
         * @param element 
         * @return true The set contains \p element
         * @return false The set does not contain \p element
         */
        virtual bool contains(const T& element) const noexcept = 0;

        /**
         * @brief Inserts \p element into the set, if it is not already a member
         * 
         * @param element 
         */
        virtual void insert(const T& element) noexcept = 0;

        /**
         * @brief Removes \p element from the set if it is a member
         * 
         * @param element 
         */
        virtual void remove(const T& element) noexcept = 0;

        /**
         * @brief Removes all elements from the set
         * 
         */
        virtual void clear() noexcept = 0;
};

template<class T, class Equal_To>
ISet<T, Equal_To>::~ISet()
{

}

#endif


