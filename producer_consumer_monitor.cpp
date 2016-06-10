// http://codereview.stackexchange.com/questions/84109/a-multi-threaded-producer-consumer-with-c11
// https://www.cs.mtu.edu/~shene/NSF-3/e-Book/MONITOR/basics.html

    #include <iostream>
    #include <deque>
    #include <condition_variable>
    #include <mutex>
    #include <thread>
    #include <memory>
    #include <functional>
    #include <cstdlib>
    #include <atomic>
    using namespace std::placeholders;
    
    using namespace std;
    
    class W
    {
    public:
      	explicit W();
        void p();
        void c();
    private:
        //std::shared_ptr<std::deque<std::uint64_t> > q;
        std::deque<std::uint64_t> q;
    	std::shared_ptr<std::mutex> m;
    	std::shared_ptr<std::condition_variable> cvQEmpty;
    	std::shared_ptr<std::condition_variable> cvQFull;
    	const std::size_t queue_size;
    };
    
    W::W()
    : //q(std::make_shared<std::deque<std::uint64_t> >()),
    m(std::make_shared<std::mutex>()),
    cvQEmpty(std::make_shared<std::condition_variable>()),
    cvQFull(std::make_shared<std::condition_variable>()),
    queue_size(3)
    {
    }
    
    void
    W::p()
    {
    	while(1)  	
    	{
    		std::unique_lock<std::mutex> lk(*m.get());
    		if (q.size() >= queue_size)
    		{
            	cvQFull->wait(lk, [this] { return q.size() < queue_size; });
    		}
    		if (q.size() >= queue_size)
    		{
            	std::abort();
    		}
    		q.push_back(q.size());
    		std::cout << "Pushed " << q[q.size() - 1] << std::endl;
            std::this_thread::sleep_for(2s);
            lk.unlock();
            cvQEmpty->notify_one();
    	}
    }
    
    void
    W::c()
    {
      while (1)
      {
    	std::unique_lock<std::mutex> lk(*m.get());
    	if (q.empty())
    	{
            cvQEmpty->wait(lk, [this] { return !q.empty(); });
    	}
    	if (q.empty())
    	{
    	  std::abort();
    	}
    	std::cout << __func__ << __LINE__ << std::endl;
    	while(!q.empty())
    	{
    	  const std::uint64_t val = q[0];
    	  std::cout << "Output : " << val << std::endl;
    	  q.pop_back();
    	}
        std::this_thread::sleep_for(1s);
    	lk.unlock();
    	cvQFull->notify_one();
      }
    }
    
    void 
    foo()
    {
        W w;
        std::thread p(&W::p, std::ref(w));
        std::thread c(&W::c, std::ref(w));
        c.join();
        p.join();
    }
    
    int
    main()
    {
        foo();    
        return 0;
    }
