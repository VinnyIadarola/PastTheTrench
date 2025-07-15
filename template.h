#pragma once
// or, if you prefer traditional guards:
// #ifndef PROJECT_FILENAME_H
// #define PROJECT_FILENAME_H

/**
 * @file    ProjectFilename.h
 * @brief   [Short description of what this header provides.]
 * @author  Your Name
 * @date    2025-07-15
 */

#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <exception>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// forward declarations
namespace ExternalLib {
    class ExternalClass;
}

namespace MyProject {

/** 
 * @brief    Global constants
 */
constexpr int    DEFAULT_TIMEOUT   = 30;                   ///< default timeout in seconds
extern const std::string DEFAULT_NAME;                    ///< default instance name

/**
 * @brief    Macro utilities
 */
#define UNUSED(x)     (void)(x)
#define VERSION_MAJOR 1
#define VERSION_MINOR 0

/**
 * @brief    Compile‐time checks
 */
static_assert(sizeof(void*) == 8, "This code requires a 64-bit platform");

/**
 * @enum   Status
 * @brief  Common return/status codes
 */
enum class Status : std::uint8_t {
    OK       = 0,
    Error    = 1,
    Unknown  = 255
};

/**
 * @typedef StringList
 * @brief   A list of strings
 */
using StringList = std::vector<std::string>;

/**
 * @brief   A utility exception for project‐specific errors
 */
class ProjectException : public std::exception {
public:
    explicit ProjectException(const std::string& msg) noexcept;
    ~ProjectException() noexcept override = default;
    const char* what() const noexcept override;
private:
    std::string message_;
};

/**
 * @brief   A sample class showing all special member functions
 */
class MyClass {
public:
    /** @name Constructors & Destructor */ /// @{
    MyClass();                                              ///< default ctor
    explicit MyClass(const std::string& name);              ///< converting ctor
    MyClass(const MyClass& other)            = default;    ///< copy ctor
    MyClass(MyClass&& other) noexcept        = default;    ///< move ctor
    ~MyClass();                                             ///< destructor
    /// @}

    /** @name Assignment */ /// @{
    MyClass& operator=(const MyClass& other) = default;    ///< copy assignment
    MyClass& operator=(MyClass&& other) noexcept = default;///< move assignment
    /// @}

    /** @name Public API */ /// @{
    /**
     * @brief   Perform the main action
     * @param   param  an integer parameter
     * @return  Status code
     */
    Status doSomething(int param);

    /**
     * @brief   Retrieve the name
     * @return  internal name string
     */
    const std::string& getName() const noexcept;

    /**
     * @brief   Set a new name
     * @param   name  the new name
     */
    void setName(const std::string& name);
    
    /**
     * @brief   Compare two MyClass instances
     */
    bool operator==(const MyClass& other) const noexcept;
    bool operator!=(const MyClass& other) const noexcept { return !(*this == other); }
    /// @}

protected:
    /** @brief  Helper available to derived classes */
    void helperFunction() noexcept;

private:
    /** @brief  Common initialization code */
    void init();

    std::string name_;    ///< instance name
    int         id_    {0}; ///< unique ID
};

/**
 * @brief   A free function utility
 * @param   x  first value
 * @param   y  second value
 * @return  sum of x and y
 */
inline int add(int x, int y) noexcept {
    return x + y;
}

/**
 * @brief   A templated utility to get the max of two values
 */
template<typename T>
T maxValue(const T& a, const T& b) {
    return (a < b) ? b : a;
}

// explicit specialization (if desired)
template<>
inline int maxValue<int>(const int& a, const int& b) {
    return (a < b) ? b : a;
}

/**
 * @brief   Another free function declared here
 */
void utilityFunction(int code, double factor) noexcept;

} // namespace MyProject

// #endif // PROJECT_FILENAME_H
