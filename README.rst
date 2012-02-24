utilcpp: general C++ utilities
==============================

``utilcpp`` contains the following general utilities that have proven useful in
C++ development throughout the years:

* Macro ``UTILCPP_RELEASE_ASSERT(cond, msg)`` in `release_assert.h`_ that
  throws ``std::logic_error`` with location information and the given message
  if ``cond`` is ``false``::

    UTILCPP_RELEASE_ASSERT(ptr != NULL, "Pointer should not be NULL");

* Macro ``UTILCPP_DISABLE_COPY(Cls)`` in `disable_copy.h`_ that disables the
  copy constructor for the class/struct ``Cls``::

    class Widget
    {
        UTILCPP_DISABLE_COPY(Widget)

     public:
         ...

* Lightweight scoped pointer based on `Boost scoped_ptr`_ in `scoped_ptr.h`_
  that does not depend on Boost and supports a deleter function as template
  argument::

    // calls delete in destructor by default
    utilcpp::scoped_ptr<Widget> widget(new Widget);

    Widget* widget_create();
    void widget_destroy(Widget *w);

    // calls widget_destroy() in destructor
    utilcpp::scoped_ptr<Widget, widget_destroy> widget(widget_create());

* Macros ``UTILCPP_DECLARE_INTERFACE(Cls)`` and
  ``UTILCPP_DECLARE_SINGLETON(Cls)`` in `declarations.h`_ that provide suitable
  constructor/destructor declarations for interfaces (pure virtual base
  classes) and `singletons`_ respectively::

    class Widget
    {
        UTILCPP_DECLARE_INTERFACE(Widget)

     public:
         ...

``utilcpp`` is `licenced under the Boost licence`_.

**Status**: production/stable.

See `main test`_ for further details.

.. _`release_assert.h`: https://github.com/mrts/utilcpp/blob/master/utilcpp/release_assert.h
.. _`disable_copy.h`: https://github.com/mrts/utilcpp/blob/master/utilcpp/disable_copy.h
.. _`Boost scoped_ptr`: http://www.boost.org/libs/smart_ptr/scoped_ptr.htm
.. _`scoped_ptr.h`: https://github.com/mrts/utilcpp/blob/master/utilcpp/scoped_ptr.h
.. _`declarations.h`: https://github.com/mrts/utilcpp/blob/master/utilcpp/declarations.h
.. _`singletons`: http://en.wikipedia.org/wiki/Singleton_pattern
.. _`licenced under the Boost licence`: https://github.com/mrts/utilcpp/blob/master/LICENCE.rst
.. _main test: https://github.com/mrts/utilcpp/blob/master/test/src/main.cpp
