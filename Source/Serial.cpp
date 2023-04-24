#include "Serial.h"

Serial::Serial(const std::string &port, Serial::Interpreter interpreter )
    : m_ioservice(),
      m_serial(m_ioservice, "/dev/ttyACM0"),
      m_thread(&Serial::reading, this),
      m_interpreter(interpreter) {
    m_serial.set_option(boost::asio::serial_port_base::baud_rate(115200));
    m_serial.set_option(boost::asio::serial_port::flow_control(boost::asio::serial_port::flow_control::none));
    m_serial.set_option(boost::asio::serial_port::parity(boost::asio::serial_port::parity::none));
    m_serial.set_option(boost::asio::serial_port::stop_bits(boost::asio::serial_port::stop_bits::one));
    m_serial.set_option(boost::asio::serial_port::character_size(boost::asio::serial_port::character_size(8)));
}

Serial::~Serial() {
    if (m_serial.is_open())
        m_serial.close();
}

void Serial::write(const std::string &message) {
    boost::asio::write(m_serial, boost::asio::buffer(message + '\n'));
}

std::string Serial::read() {
    boost::asio::streambuf buffer;
    boost::asio::read_until(m_serial, buffer, '\n');
    std::string message(boost::asio::buffer_cast<const char *>(buffer.data()), buffer.size());
    return message;
}

void Serial::reading(void) {
    for (;;)
        m_interpreter( read() );
}

