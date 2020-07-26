#pragma once

#include <memory>
#include <string>

namespace ICSE {

class _013A
{
public:
  _013A(std::string const& portPath = "/dev/cu.usbserial-14610", uint32_t baudrate = 9600);
  ~_013A();
  _013A(_013A&&) noexcept;
  _013A& operator=(_013A&&) noexcept;

  void Set(bool first, bool second);

private:
  class Impl;
  std::unique_ptr<Impl> pImpl;
};

} /// end namespace ICSE