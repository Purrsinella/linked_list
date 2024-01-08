#include <iostream>
#include "linked_list.h"

int main() {

    linked_list<int> ll;
    ll.display(std::cout);


    if (ll.isEmpty())
        std::cout << "no inf in list\n";

    try {
        ll.del_front();
    }

    catch (std::range_error &re) {
        std::cout << re.what();
    }

    try
    {
        std::cout << ll.front() << std::endl;
    }

    catch(std::range_error &re)
    {
        std::cout << re.what();
    }

    ll.push_back(144);
    ll.display(std::cout);
    std::cout << ll.size() << std::endl;

    ll.push_back(143);
    ll.display(std::cout);
    std::cout << ll.size() << std::endl;

    ll.push_back(142);
    ll.display(std::cout);
    std::cout << ll.size() << std::endl;

    ll.push_back(141);
    ll.display(std::cout);
    std::cout << ll.size() << std::endl;

    ll.push_back(140);
    ll.display(std::cout);
    std::cout << ll.size() << std::endl;

    ll.push_back(139);
    ll.display(std::cout);
    std::cout << ll.size() << std::endl;

    ll.del_idx(1);
    ll.display(std::cout);
    std::cout << ll.size() << std::endl;

    ll.push_front(145);
    ll.display(std::cout);
    std::cout << ll.size() << std::endl;

    ll.del_front();
    ll.display(std::cout);
    std::cout << ll.size() << std::endl;
    ll.del_idx(1);
    ll.display(std::cout);
    if(!ll.isEmpty())
        std::cout << "inf in list\n";

    std::cout << ll.front() << std::endl;
    try {
        std::cout << ll[1] << std::endl;
    }
    catch(std::range_error &re)
    {
        std::cout << re.what();
    }

    try {
        std::cout << ll[31] << std::endl;
    }
    catch(std::range_error &re)
    {
        std::cout << re.what();
    }

    try {
        ll.del_idx(10);
    }
    catch(std::range_error &re)
    {
        std::cout << re.what();
    }
    return 0;
}