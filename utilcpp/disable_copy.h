#ifndef UTILCPP_DISABLE_COPY_H__
#define UTILCPP_DISABLE_COPY_H__

#define UTILCPP_DISABLE_COPY(Cls) \
    private: \
        Cls(const Cls&); \
        Cls& operator=(const Cls&);

#endif /* UTILCPP_DISABLE_COPY_H */
