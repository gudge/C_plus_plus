// http://preshing.com/20160726/using-quiescent-states-to-reclaim-memory


#include <vector>
#include <shared_mutex>

using namespace std;

class Server
{
    private:
        std::shared_mutex m_rwLock;
        std::vector<int> m_clients;
};

int
main()
{
    return 0;
}
