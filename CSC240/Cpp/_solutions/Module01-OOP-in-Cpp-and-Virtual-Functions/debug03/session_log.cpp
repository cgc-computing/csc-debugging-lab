/*
 * session_log.cpp
 * Models login sessions. A FileSession additionally owns a heap buffer
 * that must be released when the session ends. Sessions are managed
 * through base-class pointers.
 */
#include <iostream>
#include <string>

class Session {
public:
    explicit Session(const std::string& user) : user_(user)
    {
        std::cout << "[open]  session for " << user_ << std::endl;
    }
    virtual ~Session()
    {
        std::cout << "[close] session for " << user_ << std::endl;
    }

    virtual void describe() const
    {
        std::cout << "  plain session (" << user_ << ")" << std::endl;
    }

    const std::string& user() const { return user_; }

private:
    std::string user_;
};

class FileSession : public Session {
public:
    FileSession(const std::string& user, int buffer_size)
        : Session(user), buffer_size_(buffer_size), buffer_(new char[buffer_size])
    {
        std::cout << "[alloc] " << buffer_size_ << "-byte buffer for "
                  << user << std::endl;
    }

    ~FileSession()
    {
        delete[] buffer_;
        std::cout << "[free]  buffer for " << user() << std::endl;
    }

    void describe() const override
    {
        std::cout << "  file session (" << user() << ", "
                  << buffer_size_ << " bytes)" << std::endl;
    }

private:
    int buffer_size_;
    char* buffer_;
};

int main()
{
    Session* sessions[3] = {
        new Session("guest"),
        new FileSession("maria", 4096),
        new FileSession("devin", 1024)
    };

    std::cout << "Active sessions:" << std::endl;
    for (Session* s : sessions) {
        s->describe();
    }

    std::cout << "Logging everyone out..." << std::endl;
    for (Session* s : sessions) {
        delete s;
    }
    return 0;
}
