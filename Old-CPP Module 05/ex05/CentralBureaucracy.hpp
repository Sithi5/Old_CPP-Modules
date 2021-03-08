
#ifndef TEST_CENTRALBUREAUCRACY_HPP
#define TEST_CENTRALBUREAUCRACY_HPP

#include "OfficeBlock.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

class CentralBureaucracy {

private:
    OfficeBlock *_blocks;

    typedef struct s_list {
        std::string task;
        std::string target;
        struct s_list *next;
    } t_list;

    t_list *_tasks;

public:
    CentralBureaucracy();
    virtual ~CentralBureaucracy();

    OfficeBlock *getBlocks() const;

    OfficeBlock getBlockNb(int n) const;

    class OfficeDoesntExist : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    void setBlocks(OfficeBlock *blocks);

    void queueUp(std::string const &task, std::string const &target);

    void executeTask(t_list *task, OfficeBlock block);
    void executeAllTask();

    void hiring(Bureaucrat *jobless);


};


#endif //TEST_CENTRALBUREAUCRACY_HPP
