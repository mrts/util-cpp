#ifndef UTILCPP_RELEASE_ASSERT_H__
#define UTILCPP_RELEASE_ASSERT_H__

#include <stdexcept>
#include <string>

#define UTILCPP_RELEASE_ASSERT(cond, msg) \
    if (!(cond)) { \
        std::string fn(__FUNCTION__); \
        std::string m(msg);\
        std::string c(#cond); \
        throw std::logic_error(fn + ": " + c + ": " + m); \
    } else (void) 0

#endif /* UTILCPP_RELEASE_ASSERT_H */
