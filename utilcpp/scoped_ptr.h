#ifndef UTILCPP_SCOPED_POINTER_H__
#define UTILCPP_SCOPED_POINTER_H__

//  This file is a simplified, in-tree copy of scoped_pointer.hpp from the Boost
//  libraries.
//
//  (C) Copyright Greg Colvin and Beman Dawes 1998, 1999.
//  Copyright (c) 2001, 2002 Peter Dimov
//  Copyright (c) 2011, 2012 Mart Somermaa
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//  http://www.boost.org/libs/smart_ptr/scoped_ptr.htm
//

//  scoped_pointer mimics a built-in pointer except that it guarantees deletion
//  of the object pointed to, either on destruction of the scoped_pointer or via
//  an explicit reset(). scoped_pointer is a simple solution for simple needs;
//  use shared_ptr or std::auto_ptr if your needs are more complex.

#include <utilcpp/release_assert.h>
#include <utilcpp/disable_copy.h>

#include <memory>

namespace utilcpp
{

template<typename T>
void scoped_ptr_default_delete(T* p)
{
    delete p;
}

template<class T, void (*Deleter)(T*) = scoped_ptr_default_delete<T> >
class scoped_ptr
{
    UTILCPP_DISABLE_COPY(scoped_ptr)

private:

    typedef scoped_ptr<T, Deleter> this_type;

public:

    explicit scoped_ptr(T* p = 0) :
        deleter(Deleter),
        px(p)
    {
    }

    explicit scoped_ptr(std::auto_ptr<T> p) :
        deleter(Deleter),
        px(p.release())
    {
    }

    this_type& operator=(std::auto_ptr<T> p)
    {
        this->reset(p.release());
        return *this;
    }

    ~scoped_ptr()
    {
        deleter(px);
    }

    void reset(T* p = 0)
    {
        UTILCPP_RELEASE_ASSERT(p == 0 || p != px,
                "Self-reset in scoped_ptr");
        this_type(p).swap(*this);
    }

    T& operator*() const
    {
        UTILCPP_RELEASE_ASSERT(px != 0,
                "Dereferencing null pointer in scoped_ptr");
        return *px;
    }

    T* operator->() const
    {
        UTILCPP_RELEASE_ASSERT(px != 0,
                "Dereferencing null pointer in scoped_ptr");
        return px;
    }

    T* get() const
    {
        return px;
    }

    operator bool() const
    {
        return px != 0;
    }

    void swap(scoped_ptr& b)
    {
        T* tmp = b.px;
        b.px = px;
        px = tmp;
    }

private:

    void (*deleter)(T*);
    T* px;

    void operator==(const scoped_ptr&) const;
    void operator!=(const scoped_ptr&) const;
};

}

#endif /* UTILCPP_SCOPED_POINTER_H */
