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

/**
 * @brief Set abstract data type
 * 
 * @tparam T Data type
 */
template <class T>
class ISet {
public:
    virtual ~ISet<T>();

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
         * @brief Inserts \p element into the set if it is not already a member
         * 
         * @param element 
         * @return true \p element was added to the set
         * @return false \p element was already a member of the set
         */
    virtual bool insert(const T& element) noexcept = 0;

    /**
         * @brief Removes \p element from the set if it is a member
         * 
         * @param element 
         * @return true \p element was removed from the set
         * @return false \p element was not a member of the set
         */
    virtual bool remove(const T& element) noexcept = 0;

    /**
         * @brief Removes all elements from the set
         * 
         */
    virtual void clear() noexcept = 0;
};

template <class T>
ISet<T>::~ISet()
{
}

#endif
