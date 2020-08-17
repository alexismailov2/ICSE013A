#include <ICSE/_013A.hpp>

#include <boost/asio/serial_port.hpp>
#include <boost/asio.hpp>

#include <thread>

namespace ICSE {

class _013A::Impl
{
public:
  Impl(std::string const& portPath, uint32_t baudrate)
    : _io{}
    , _port{_io}
  {
    _port.open(portPath);
    _port.set_option(boost::asio::serial_port_base::baud_rate(baudrate));

    uint8_t getVersion = 0x50;
    boost::asio::write(_port, boost::asio::buffer(&getVersion, 1));
    //uint8_t gottenVersion{};
    //boost::asio::read(_port, boost::asio::buffer(&gottenVersion, 1));

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    uint8_t w = 0x51;
    boost::asio::write(_port, boost::asio::buffer(&w, 1));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  void Set(bool first, bool second)
  {
    uint8_t control = first | (second << 1);
    boost::asio::write(_port, boost::asio::buffer(&control, 1));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  ~Impl()
  {
    _port.close();
  }

private:
  boost::asio::io_service _io;
  boost::asio::serial_port _port;
};

_013A::_013A(std::string const& portPath, uint32_t baudrate)
  : pImpl{std::make_unique<Impl>(portPath, baudrate)}
{
}

_013A::~_013A() = default;

_013A::_013A(_013A&&) noexcept = default;

_013A& _013A::operator=(_013A&&) noexcept = default;

void ICSE::_013A::Set(bool first, bool second)
{
   pImpl->Set(first, second);
}

} /// end namespace ICSE
