#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <boost/asio.hpp>

class Serial {
public:
    explicit Serial(const std::string &port);
    ~Serial();
    void write(const std::string &message);
    std::string read();
private:
    boost::asio::io_service m_ioservice;
    boost::asio::serial_port m_serial;
};

#endif
