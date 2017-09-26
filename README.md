# A C++ Properties class

[![Build Status](https://travis-ci.org/andremaravilha/cxxproperties.svg?branch=master)](https://travis-ci.org/andremaravilha/cxxproperties)

Properties are key/value pairs usually used to manage configuration values. In each pair, the key and value are both string values. The key identifies, and is used to retrieve, the value. Despite being stored as string, the values can be retrieved as the type specified by the user.

The **cxxproperties** is a header only C++ library that offers an easy-to-use Properties class. You just need to include the header file `cxxproperties.hpp` and that's it. You can already instantiate `cxxproperties::Properties` objects in your C++ code.

## Quick Start

The code below shows how to use **cxxproperties** library. For a more detailed example that shows all methods offered by `cxxproperties::Properties` class, see the `example/example.cpp` file in this repository.

```cpp
#include <cxxproperties.hpp>
#include <iostream>
#include <string>

int main(int argc, char** argv) {

    // Create an instance of cxxproperties::Properties class
    cxxproperties::Properties properties;
    
    // Add some properties (pairs key/value)
    properties.add("key_1", "A string value...");
    properties.add("key_2", 10);
    properties.add("key_3", 3.1415);
    properties.add("key_4", true);

    // Print the number of entries
    std::cout << "Number of entries: " << properties.size() 
              << std::endl << std::endl;

    // Print all pairs key/value (values are returned as std::string by default)
    std::cout << "Entries (returned as string): " << std::endl;
    for (const auto& key : properties.get_keys()) {
        std::cout << "  * " << key << " = " << properties.get(key) << std::endl;
    }
    std::cout << std::endl;

    // Get the values with the specified type
    std::string value_1 = properties.get<std::string>("key_1");
    int value_2         = properties.get<int>("key_2");
    double value_3      = properties.get<double>("key_3");
    bool value_4        = properties.get<bool>("key_4");

    // Print all pairs key/value (using the values )
    std::cout << "Entries: " << std::endl;
    std::cout << "  * " << "key_1" << " = " << value_1 << std::endl;
    std::cout << "  * " << "key_2" << " = " << value_2 << std::endl;
    std::cout << "  * " << "key_3" << " = " << value_3 << std::endl;
    std::cout << "  * " << "key_4" << " = " << value_4 << std::endl;
    std::cout << std::endl;
    
    return 0;
}
```


## Linking

This is a header only library.


## Requirements

The only build requirement is a C++ compiler that supports C++11. For example GCC >= 5.0 or clang >= 3.4.
