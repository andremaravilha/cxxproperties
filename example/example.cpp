/*

MIT License

Copyright (c) 2017 André L. Maravilha

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/


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

    // Check whether a property exist
    std::cout << "It contains the property \"key_1\"? " 
              << (properties.contains("key_1") ? "Yes" : "No")
              << std::endl;

    std::cout << "It contains the property \"key_0\"? " 
              << (properties.contains("key_0") ? "Yes" : "No")
              << std::endl;

    std::cout << std::endl;

    // Get default values for non-existent properties
    std::cout << "Get default value \"not found\" for non-existent keys:" << std::endl;
    std::cout << "Key: \"key_0\", Value: " << properties.get("key_0", "not found") << std::endl;
    std::cout << "Key: \"key_1\", Value: " << properties.get("key_1", "not found") << std::endl;
    std::cout << std::endl;

    std::cout << "Get default value 1.618 for non-existent keys:" << std::endl;
    std::cout << "Key: \"key_0\", Value: " << properties.get("key_0", 1.618) << std::endl;
    std::cout << "Key: \"key_3\", Value: " << properties.get("key_3", 1.618) << std::endl;
    std::cout << std::endl;

    // Remove a property
    std::cout << "Removing properties with key \"key_2\" and \"key_4\"..." << std::endl;
    properties.remove("key_2");
    properties.remove("key_4");

    // Print the keys remaining in the properties object
    std::cout << "Remaining keys: " << std::endl;
    for (const auto& key : properties.get_keys()) {
        std::cout << "  * " << key << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
