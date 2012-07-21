#ifndef UTILCPP_DECLARATIONS_H__
#define UTILCPP_DECLARATIONS_H__

// interface has virtual destructor and no public constructors
#define UTILCPP_DECLARE_INTERFACE(Cls) \
    public: \
        virtual ~Cls() {} \
    protected: \
        Cls() {} \
    private: \
        Cls(const Cls&); \
        Cls& operator=(const Cls&);

#define UTILCPP_DECLARE_INTERFACE_ALLOW_CONSTRUCTORS(Cls) \
    public: \
        virtual ~Cls() {} \
    private: \
        Cls(const Cls&); \
        Cls& operator=(const Cls&);

// singleton has no public constructors and provides access to the instance via
// the static instance() method
#define UTILCPP_DECLARE_SINGLETON(Cls) \
    public: \
        static Cls& instance(); \
    private: \
        Cls(); \
        ~Cls() {} \
        Cls(const Cls&); \
        Cls& operator=(const Cls&);

#endif /* UTILCPP_DECLARATIONS_H__ */
