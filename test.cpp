#include "god_interface.hpp"
int main() {
    god_interface_impl impl;
    impl.read("hello");
    impl.read("hello", 5);
    impl.write("world");
    
    return 0;
}