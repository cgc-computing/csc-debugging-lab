/*
 * ticket_block.cpp
 * Reserves a block of seats for a group, prints the tickets, and returns
 * the block when the group is done. Each Ticket announces when it is
 * returned so the box office can confirm that every seat came back.
 */
#include <iostream>
#include <string>

class Ticket {
public:
    Ticket() : holder_("(unassigned)"), seat_(0) {}

    void assign(const std::string& holder, int seat)
    {
        holder_ = holder;
        seat_ = seat;
    }

    void print() const
    {
        std::cout << "  seat " << seat_ << " -> " << holder_ << std::endl;
    }

    ~Ticket()
    {
        std::cout << "[returned] seat " << seat_ << " (" << holder_ << ")" << std::endl;
    }

private:
    std::string holder_;
    int seat_;
};

Ticket* reserve_block(int count, int first_seat, const std::string names[])
{
    Ticket* block = new Ticket[count];
    for (int i = 0; i < count; i++) {
        block[i].assign(names[i], first_seat + i);
    }
    return block;
}

void release_block(Ticket* block)
{
    std::cout << "Returning the block..." << std::endl;
    delete[] block;
}

int main()
{
    const std::string group[3] = { "Omar", "Lena", "Chris" };

    Ticket* block = reserve_block(3, 14, group);

    std::cout << "Tickets issued:" << std::endl;
    for (int i = 0; i < 3; i++) {
        block[i].print();
    }

    release_block(block);
    std::cout << "All seats returned." << std::endl;
    return 0;
}
