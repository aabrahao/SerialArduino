#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <iostream>
#include <functional>
#include <boost/asio.hpp>

class Echo {
public:
    void operator()(const std::string &message) const {
        std::cout << "arduino>" << message << std::endl;
    }
};

class Serial {
public:
    using Interpreter = std::function<void(const std::string)>; 
    explicit Serial(const std::string &port, Interpreter interpreter = Echo());
    ~Serial();
    void write(const std::string &message);
    std::string read();
protected:
    void reading(void);
private:
    boost::asio::io_service m_ioservice;
    boost::asio::serial_port m_serial;
    std::thread m_thread;
    Interpreter m_interpreter;
};

#endif
