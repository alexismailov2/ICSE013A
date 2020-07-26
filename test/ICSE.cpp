#include <ICSE/_013A.hpp>

auto main(int argc, char** argv) -> int32_t
{
   auto _013A = ICSE::_013A{};
   for (int i = 0; i < 10; ++i)
   {
     _013A.Set(i & 0x01, i & 0x02);
   }
   return 0;
}
