#pragma once
#include <iostream>
#include <string>
template <typename Op, typename Buffer, typename... Args>
void god_interface(Op op, Buffer buffer, Args... args) {
    op(buffer, args...);
}
struct god_interface_impl {
    struct read_some {
        void operator() (std::string buf) {
            std::cout << "god read string:" << buf << std::endl;
        }
        void operator() (std::string buf, size_t size) {
            std::cout << "god read string:" << buf << " size:" << size << std::endl;
        }
    };
    struct write_some {
        void operator() (std::string buf) {
            std::cout << "god write string:" << buf << std::endl;
        }
    };
    void read(std::string buf) {
        god_interface(read_some{}, buf);
    }
    void read(std::string buf, size_t size) {
        god_interface(read_some{}, buf, size);
    }
    void write(const std::string buf) {
        god_interface(write_some{}, buf);
    }
};