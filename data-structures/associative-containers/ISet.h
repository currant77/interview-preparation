/**
 * @file ISet.h
 * @author Taylor Curran
 * @brief Set interface
 * @version 0.1
 * @date 2020-06-12
 */

#ifndef I_SET_H
#define I_SET_H

#include <functional>

template<class T>
class ISet
{
    public:
        virtual ~ISet<T>();

        virtual int size() const = 0;
        virtual bool contains(const T& t) const = 0;
        virtual bool insert(const T& t) = 0;
        virtual bool remove(const T& t) = 0;
        virtual void clear() = 0;
};

template<class T>
ISet<T>::~ISet()
{

}

#endif


