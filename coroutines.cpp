#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void foo();
void bar(const boost::system::error_code& e); 

void 
bar(const boost::system::error_code& e) 
{
    std::cout << "Hello World" << '\n';
}

void foo()
{
    boost::asio::io_service io;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
    t.wait();
    std::cout << "Hello World" << std::endl;

    boost::asio::deadline_timer t2(io, boost::posix_time::seconds(5));
    t2.async_wait(&bar);
    io.run();
}

int
main()
{
    foo();
}
